#include "../lib/Nucleaire.h"
#include <stdlib.h>
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include "../lib/Jeu.h"

extern Jeu* grille;

Nucleaire::Nucleaire(QGraphicsItem * parent,int pA): QObject(), QGraphicsPixmapItem(parent),EnergiePolluante(pA,"Nucleaire"){
    // on met une position aléatoire
    int random_number = rand() % 700;
    setPos(random_number,0);
    // on "dessine" l'élément
    setPixmap(QPixmap(":/images/nucleaire_redim.png"));

    //création des timer puis on connect
    QTimer * timer = new QTimer();
    QTimer * timer_move = new QTimer();
    connect(timer_move, SIGNAL(timeout()), this, SLOT(move()));
    connect(timer, SIGNAL(timeout()), this, SLOT(attaquer()));
    timer->start(50); // durée du timer jusqu'à 50 ms
    timer_move->start(75);

}

/*Méthode qui calcul les dégats causé par un Nucléaire sur un joueur */
int Nucleaire::degats(Joueur *j, Nucleaire *m)
{
        int attaque = j->getpV()- m->getpA();
        if(attaque<0){ // si les dégats sont <0 alors on mets les points de vies à 0
            j->setPv(0);
            return 1;
        }
        else{
            j->setPv(attaque);// si les dégats sont >0 alors on fixe pV = attaque
            return 0;
       }
}

/* Méthode contrôlant le déplacement des Nucléaires*/
void Nucleaire::move()
{
    //move Nucleaire
     setPos(x(), y()+5);
     if(pos().y() > 600){ // s'il quitte la fenêtre graphique alors on le supprime et on l'enlève de la scène
         scene()->removeItem(this);
         delete this;
         //qDebug() << "méchant supprimé";
     }
}

/* Méthode permettant à un Nucléaire d'attaquer le joueur lorsqu'ils entrent en collision
 Si un Nucléaire touche un autre Nucléaire alors on la change de place */
void Nucleaire::attaquer(){
    QList<QGraphicsItem*> list = collidingItems();
    int n = list.size();
    for (int i = 0; i< n; i++){
        if(typeid(*(list[i])) == typeid(Joueur)){
            int ret=degats(grille->player,this);
            if(ret){
                scene()->removeItem(this); // supprime le méchant
                delete list[i]; // game over
                delete this;
                return;
            }
            else{
                scene()->removeItem(this);
                delete this;
                return;
            }
        }
        else if(typeid(*(list[i])) == typeid(Nucleaire)){
            setPos(rand()%700,0);
        }
    }
}
