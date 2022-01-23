#ifndef EOLIENNE_H
#define EOLIENNE_H

#include "EnergieRenouvelable.h"
#include "Jeu.h"
#include <QGraphicsPixmapItem>
#include <QObject>
#include "Joueur.h"

/* classe dérivant de la classe Energie renouvelable
points de soin = 20*/
class Eolienne : public QObject, public QGraphicsPixmapItem, public EnergieRenouvelable{
    Q_OBJECT
public:
    Eolienne(QGraphicsItem* parent,int pS);
    int soins(Joueur* j,Eolienne* jo);
public slots:
      void move();
      void soigner();
};

#endif
