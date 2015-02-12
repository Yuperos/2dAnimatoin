#ifndef MYLINE_H
#define MYLINE_H

#include <QLine>
#include "shape.h"

class MyLine : public Shape, public QLine
   {
   static const int Thickness=3;
public:
   MyLine():QLine(){}
   MyLine(QLine l):QLine(l.p1(),l.p2()){}
   MyLine(QPoint &p1, QPoint &p2):QLine(p1,p2){}
   MyLine(int x1, int y1, int x2, int y2):QLine(x1,y1,x2,y2){}

   virtual bool isHit(QPoint p);
   virtual bool isHit(int x, int y);
   virtual bool isInRange(QPoint p);
   virtual bool isInRange(int x, int y);
   virtual bool inAllowedRange(QPoint p);
   virtual bool inAllowedRange(int x, int y);
   virtual bool isCrossAxisX(int y);
   virtual bool isCrossAxisY(int x);
   virtual QPoint p1() { return dynamic_cast<QLine&>(*this).p1(); }
   virtual QPoint p2() { return dynamic_cast<QLine&>(*this).p1(); }
   virtual void draw(QPainter &painter);
   virtual int binQuad(QRect &field);

   };

#endif // MYLINE_H
