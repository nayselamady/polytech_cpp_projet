#ifndef BOUTON_H
#define BOUTON_H


#include <QGraphicsRectItem> //pour les boutons rectangles
#include <QGraphicsSceneMouseEvent>

/* Classe bouton permettant de générer les différents boutond de la fenêtre graphique (Rejouer , Quitter ...) */
class Bouton:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Bouton(QString text);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

signals:
    void clicked();
private:
    QGraphicsTextItem* texte;
};

#endif // Bouton_HH
