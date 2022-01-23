#include "../lib/Bouton.h"
#include <QtGui>
#include "../lib/Jeu.h"

/* constructeur de la classe bouton */
Bouton::Bouton(QString text)
{
    // configuration du rectangle
    setRect(0,0,200,50);

    QBrush brush; //permets d'ajouter de la couleur au bouton
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkGray);
    setBrush(brush);

    // assignation du texte sur le bouton
    texte= new QGraphicsTextItem(text,this); // avec this on a le bouton parent du texte donc bouton suppr = texte suppr
    int xPos = rect().width()/2 - texte->boundingRect().width()/2;
    int yPos = rect().height()/2 - texte->boundingRect().height()/2;
    texte->setPos(xPos,yPos);

    // permets au bouton de répondre aux différents évènements
    setAcceptHoverEvents(true);
}

void Bouton::mousePressEvent(QGraphicsSceneMouseEvent *event){
    Q_UNUSED(event);
    emit clicked(); // si on clique sur le bouton un signal est envoyé va permettre d'activer le slots dans Jeu.cpp
}

void Bouton::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    Q_UNUSED(event);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    setBrush(brush);
}

void Bouton::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    Q_UNUSED(event);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkRed);
    setBrush(brush);
}
