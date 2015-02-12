#ifndef MYPOINT_H
#define MYPOINT_H

#include <QPoint>
#include <math.h>
#include "shape.h"

class MyPoint : public Shape, public QPoint
   {
   static const int Thickness=5;
public:
   MyPoint():QPoint(){}
   MyPoint(QPoint p):QPoint( p.x(), p.y() ){}
   MyPoint(int xpos, int ypos):QPoint(xpos,ypos){}

   virtual bool isInRange(QPoint p);
   virtual bool isInRange(int x, int y);
   virtual bool isHit(QPoint p);
   virtual bool isHit(int x, int y);
   virtual bool isCrossAxisX(int y);
   virtual bool isCrossAxisY(int x);
   virtual int x() { return dynamic_cast<QPoint&>(*this).x(); }
   virtual int y() { return dynamic_cast<QPoint&>(*this).y(); }
   virtual void draw(QPainter &painter);
   virtual int binQuad(QRect &field);

   };

#endif // MYPOINT_H
