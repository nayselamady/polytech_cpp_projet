#ifndef NUCLEAIRE_H
#define NUCLEAIRE_H

#include "EnergiePolluante.h"
#include "Joueur.h"


/* classe dérivant de la classe Energie polluante
points d'attaque = 20*/
class Nucleaire :public QObject, public QGraphicsPixmapItem,public EnergiePolluante{
    Q_OBJECT
public:
    Nucleaire(QGraphicsItem * parent,int pA);
    int degats(Joueur* j,Nucleaire* m);
public slots:
      void move();
      void attaquer();
};

#endif
