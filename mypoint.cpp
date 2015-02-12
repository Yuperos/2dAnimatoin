#include "mypoint.h"

bool MyPoint::isInRange(QPoint p)
   {
   return sqrt( pow((double)p.x()-this->x(), 2) + pow((double)p.y()-this->y(), 2) ) <= Thickness;
   }

bool MyPoint::isInRange(int x, int y)
   {
   return sqrt( pow((double)x-this->x(), 2) + pow((double)y-this->y(), 2) ) <= Thickness;
   }

bool MyPoint::isHit(QPoint p)
   {
   return isInRange(p);
   }

bool MyPoint::isHit(int x, int y)
   {
   return isInRange(x,y);
   }

bool MyPoint::isCrossAxisX(int y)
   {
   return this->y() - Thickness < y &&
          this->y() + Thickness > y;
   }

bool MyPoint::isCrossAxisY(int x)
   {
   return this->x() - Thickness < x &&
          this->x() + Thickness > x;
   }

void MyPoint::draw(QPainter &painter)
   {
   painter.drawEllipse(dynamic_cast<QPoint&>(*this),5,5);
   }

int MyPoint::binQuad(QRect &field)
   {
      int binQuad  = (x() > field.center().x())?6:9;   //()? 0110b : 1001b
   return binQuad &= (y() > field.center().y())?12:3;  //()? 1100b : 0011b
   }
