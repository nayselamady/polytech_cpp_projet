#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <QGraphicsTextItem>

/* classe Affichage s'occupant d'afficher des informations supplémentaires sur le joueur*/

class Affichage: public QGraphicsTextItem{
    Q_OBJECT
public:
    Affichage(QGraphicsItem * parent = 0);
signals:
    void dead();
public slots:
    void maj();
};

#endif // AFFICHAGE_H
