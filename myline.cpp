#include "myline.h"
#include <math.h>

bool MyLine::isHit(QPoint p)
   {
   return isInRange(p) && inAllowedRange(p);
}

bool MyLine::isInRange(QPoint p)
   {
   return p.x() >= (p1().x() < p2().x())? p1().x() : p2().x() &&
          p.x() <= (p1().x() > p2().x())? p1().x() : p2().x() &&
          p.y() >= (p1().y() < p2().y())? p1().y() : p2().y() &&
          p.y() <= (p1().y() > p2().y())? p1().y() : p2().y();
   }

bool MyLine::inAllowedRange(QPoint p)
   {
   double xVec = (double(p1().x()-p2().x()));
   double yVec = (double(p1().y()-p2().y()));
   return fabs(p.x()*(yVec/xVec)-p.y()) < cos(yVec/xVec)*Thickness &&
          fabs(p.y()*(xVec/yVec)-p.x()) < cos(xVec/yVec)*Thickness;

   }


bool MyLine::isHit(int x, int y)
   {
   return isInRange(x,y) && inAllowedRange(x,y);
   }


bool MyLine::isInRange(int x, int y)
   {
   return x >= (p1().x() < p2().x())? p1().x() : p2().x() &&
          x <= (p1().x() > p2().x())? p1().x() : p2().x() &&
          y >= (p1().y() < p2().y())? p1().y() : p2().y() &&
          y <= (p1().y() > p2().y())? p1().y() : p2().y();
   }

bool MyLine::inAllowedRange(int x, int y)
   {
   double xVec = (double(p1().x()-p2().x()));
   double yVec = (double(p1().y()-p2().y()));
   return fabs(x*(yVec/xVec)-y) < cos(yVec/xVec)*Thickness &&
          fabs(y*(xVec/yVec)-x) < cos(xVec/yVec)*Thickness;

   }

bool MyLine::isCrossAxisX(int y)
   {
   return (p1().y() > y && p2().y() < y) ||
          (p2().y() > y && p1().y() < y);
   }

bool MyLine::isCrossAxisY(int x)
   {
   return (p1().x() > x && p2().x() < x) ||
          (p2().x() > x && p1().x() < x);
   }

void MyLine::draw(QPainter &painter)
   {
   painter.drawLine(dynamic_cast<QLine&>(*this));
   }

int MyLine::binQuad(QRect &field)
   {
      int binQuad  = (p1().x() > field.center().x() && p2().x() > field.center().x())?6:9;   //()? 0110b : 1001b
   return binQuad &= (p1().y() > field.center().y() && p2().y() > field.center().y())?12:3;  //()? 1100b : 0011b
   }


