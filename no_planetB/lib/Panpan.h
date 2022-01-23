#ifndef PANPAN_H
#define PANPAN_H

#include <QGraphicsPixmapItem>
#include <QObject>

// Qobject = formalité lorsqu'on a des public slots, maintenant la classe panpan peut manipuler les signals et les slots

class Panpan: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
      Panpan(QGraphicsItem * parent = 0);
public slots:
      void move();
};


#endif // PANPAN_H
