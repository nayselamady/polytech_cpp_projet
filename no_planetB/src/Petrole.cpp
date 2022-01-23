#include "../lib/Petrole.h"
#include <QTimer>

extern Jeu* grille;

Petrole::Petrole(QGraphicsItem * parent,int pA): QObject(),QGraphicsPixmapItem(parent),EnergiePolluante(pA,"Petrole"){
    // on met une position aléatoires
    int random_number = rand()%700;
    setPos(random_number,0);
    // on "dessine" l'élément
    setPixmap(QPixmap(":/images/petrole_redim.png"));

    //création des timer puis on connect
    QTimer * timer = new QTimer();
    QTimer * timer_move = new QTimer();
    connect(timer_move, SIGNAL(timeout()), this, SLOT(move()));
    connect(timer, SIGNAL(timeout()), this, SLOT(attaquer()));
    timer->start(50); // timer time to 50 ms
    timer_move->start(100);

}

/*Méthode qui calcul les dégats causé par un Nucléaire sur un joueur
si valeur retournée 1 alors on doit delete le joueur
si valeur retournée 0 alors on doit pas delete le joueur*/
int Petrole::degats(Joueur* j, Petrole* m)
{
    int attaque = j->getpV()- m->getpA();
    if(attaque<0){
        j->setPv(0);
        return 1;
    }
    else{
        j->setPv(attaque);
        return 0;
    }
}

void Petrole::move()
{
   //move survivalistes up
    setPos(x(), y()+5);
    //on veut suppr les Petrole une fois sortie de la scene
    if(pos().y() > 600){
        scene()->removeItem(this);
        delete this;
        //qDebug() << "mechant supprime";
    }
}

/* Méthode permettant à un Petrole d'attaquer le joueur lorsqu'ils entrent en collision
 Si un Nucléaire touche un autre Petrole alors on la change de place */
void Petrole::attaquer(){
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
        else if(typeid(*(list[i])) == typeid(Petrole)){
            setPos(rand()%700,0);
        }
        }
    }
