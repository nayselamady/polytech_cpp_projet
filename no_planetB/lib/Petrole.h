#ifndef PETROLE_H
#define PETROLE_H

#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QObject>
#include "EnergiePolluante.h"
#include "Joueur.h"
#include "Jeu.h"

/* classe dérivant de la classe Energie polluante
points d'attaque = 10*/
class Petrole: public QObject, public QGraphicsPixmapItem,public EnergiePolluante{
    Q_OBJECT
public:
    Petrole(QGraphicsItem * parent,int pA);
    int degats(Joueur* j,Petrole* m);
public slots:
      void move();
      void attaquer();
};

#endif
