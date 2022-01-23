#ifndef SOLAIRE_H
#define SOLAIRE_H

#include "EnergieRenouvelable.h"
#include "Jeu.h"
#include "Joueur.h"
#include <QGraphicsPixmapItem>
#include <QObject>

/* classe dérivant de la classe Energie renouvelable
points de soin = 10*/
class Solaire : public QObject,public QGraphicsPixmapItem,public EnergieRenouvelable{
    Q_OBJECT
public:
    Solaire(QGraphicsItem * parent,int pS); // il n'y a qu'un seul Solaire par partie
    int soins(Joueur* j,Solaire* sj);

public slots:
      void move();
      void soigner();
};

#endif
