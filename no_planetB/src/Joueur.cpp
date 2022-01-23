#include "../lib/Joueur.h"
#include "../lib/Jeu.h"
#include "../lib/Panpan.h"
#include <iostream>
#include <string>
#include <QFont>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QKeyEvent>
#include <QFont>
#include <QTimer>

using namespace std;

Joueur::Joueur(QGraphicsItem* parent,int pA,int pV,int score):QGraphicsPixmapItem(parent),Personnage("Hero",0),_pA(pA),_pV(pV),_score(score)
{
    soncanon = new QMediaPlayer();
    soncanon->setMedia(QUrl("qrc:/sons/sf_laser_explosion.mp3"));
    setPixmap(QPixmap(":/images/hero_redim.png"));


    QTimer * timer_w= new QTimer();
    connect(timer_w, SIGNAL(timeout()), this, SLOT(winner()));
    timer_w->start(50); // timer time to 50 ms

}

void Joueur::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left){
        if(pos().x() > 0){ //condition pour que le joueur ne sorte pas de la fenêtre
            setPos(x()-10,y());
        }
    }
    else if(event->key() == Qt::Key_Right){
        if(pos().x()+100 < LENGHT_SCREEN){//condition pour que le joueur ne sorte pas de la fenêtre
            setPos(x()+10,y());
        }
    }
    else if(event->key() == Qt::Key_Space){
        //crée une arme
        Panpan * panpan = new Panpan();
        panpan->setPos(x(), y());
        scene()->addItem(panpan);
        //son de canon
        if(soncanon->state() == QMediaPlayer::PlayingState){
            soncanon->setPosition(0);
        }
        else if(soncanon->state() == QMediaPlayer::StoppedState){
            soncanon->play();
        }
    }

}

void Joueur::winner()
{
    if(this->_score>= 80){ // si on atteint le score objectif alors on a gagné
        emit win();// émission du signal win()
    }

}
