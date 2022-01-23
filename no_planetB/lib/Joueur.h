#ifndef JOUEUR_H
#define JOUEUR_H

#include "Personnage.h"
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>


class Joueur: public QObject,public QGraphicsPixmapItem,public Personnage{
    Q_OBJECT
public:
    Joueur(QGraphicsItem* parent,int pA,int pV,int score);
    int getpV() const{return _pV;}
    void setPv(int a){_pV = a;}
    void setpA(int a ){_pA=a;}
    int getpA()const {return _pA;}
    int getScore() const{return _score;}
    void setScore(int a){_score= a;}
    // déplacement à gérer avec Qt
    void keyPressEvent(QKeyEvent * event);

signals:
    void win();
public slots:
    void winner();

private:
    int _pA;
    int _pV;
    int _score;
    QMediaPlayer * soncanon;
};

#endif
