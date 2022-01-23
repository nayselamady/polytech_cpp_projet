#include "../lib/Affichage.h"
#include "../lib/Jeu.h"
#include <QFont>
#include <QDebug>
#include <QTimer>

extern Jeu* grille;

/*constructeur Affichage*/
Affichage::Affichage(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
    /* afficher point de vie et score périodiquement */
    QTimer * timer_pv = new QTimer();
    connect(timer_pv, SIGNAL(timeout()), this, SLOT(maj()));
    timer_pv->start(50); // timer time to 50 ms

}

/*Fonction s'occupant de la mise à jour de l'affichage du score et des points de vie du joueur
Selon le niveau de vie du joueur la couleur change */
void Affichage::maj(){
    if (grille->player->getpV()<=VIE_JOUEUR && grille->player->getpV()>=(VIE_JOUEUR/3)){
        setPlainText("Pv: " + QString::number(grille->player->getpV())+"\nScore : "+QString::number(grille->player->getScore()));
        setDefaultTextColor(Qt::green);
        setFont(QFont("times",16));
    }
    else if (grille->player->getpV()<(VIE_JOUEUR/3) && grille->player->getpV()>=(VIE_JOUEUR/2)){
        setPlainText("Pv: " + QString::number(grille->player->getpV())+"\nScore : "+QString::number(grille->player->getScore()));
        setDefaultTextColor(Qt::yellow);
        setFont(QFont("times",16));
    }
    else if (grille->player->getpV()<(VIE_JOUEUR/2) && grille->player->getpV()>=(VIE_JOUEUR/4)){
        setPlainText("Pv: " + QString::number(grille->player->getpV())+"\nScore : "+QString::number(grille->player->getScore()));
        setDefaultTextColor(QColor("#ffb000"));
        setFont(QFont("times",16));
    }
    else if (grille->player->getpV()<(VIE_JOUEUR/4) && grille->player->getpV()>=0){
        setPlainText("Pv: " + QString::number(grille->player->getpV())+"\nScore : "+QString::number(grille->player->getScore()));
        setDefaultTextColor(Qt::red);
        setFont(QFont("times",16));
        if(grille->player->getpV()<=0){
            grille->player->setPv(0);
            emit dead();
        }
    }
    else{
        setPlainText("Pv: " + QString::number(grille->player->getpV())+"\nScore : "+QString::number(grille->player->getScore()));
        setDefaultTextColor(Qt::gray);
        setFont(QFont("times",16));
    }
}



