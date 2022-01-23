#include "../lib/Panpan.h"
#include "../lib/Petrole.h"
#include "../lib/Nucleaire.h"
#include "../lib/Eolienne.h"
#include "../lib/Solaire.h"
#include "../lib/Jeu.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <QList>

extern Jeu* grille;
Panpan::Panpan(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    // dessin du graphique
    setPixmap(QPixmap(":/images/arme_redim.png"));
    //Création du timer + connection avec la méthode move
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50); // timer time to 50 ms
}

//fonction liée au timer donc appelée périodiquement
void Panpan::move()
{
    // si collision avec EnergiePolluante on detruit la balle et l'énergie
    QList<QGraphicsItem *> colliding_items = collidingItems();
    int n = colliding_items.size();
    for (int i = 0; i< n; i++){
        if(typeid(*(colliding_items[i])) == typeid(Nucleaire)||typeid(*(colliding_items[i])) == typeid(Petrole)){
            grille->player->setScore((grille->player->getScore()+5));
            scene()->removeItem((colliding_items[i]));
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
        if(typeid(*(colliding_items[i])) == typeid(Eolienne)){ // si tu touches une Eolienne tu perds 5pts de vie
            int dommage = grille->player->getpV()-5;
            grille->player->setPv(dommage);
            scene()->removeItem((colliding_items[i]));
            delete colliding_items[i];
            return;
        }
        if (typeid(*(colliding_items[i])) == typeid(Solaire)){ // si tu touches un Solaire tu perds 25pts de vie
            int dommage = grille->player->getpV()-25;
            grille->player->setPv(dommage);
            scene()->removeItem((colliding_items[i]));
            delete colliding_items[i];
            return;
        }
    }

   //move panpan up
    setPos(x(), y()-10);
    //on supprime les balles une fois sortie de la scene
    if(pos().y()<0){
        scene()->removeItem(this);
        delete this;
    }
}

