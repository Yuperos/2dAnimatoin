#ifndef SHAPE_H
#define SHAPE_H

#include <QPoint>
#include <QDebug>
#include <QColor>
#include <QPainter>
class Shape
   {
   bool isSelect;
   QColor color;
public:
   Shape(){ isSelect=false; }

   Shape *setSelectionTo(bool isSelect){ this->isSelect=isSelect; return this; }
   bool isSelected(){ return isSelect; }
   QColor getColor(){ return color; }
   void setColor(QColor col){ color=col; }

   virtual bool isHit(QPoint p)        {qDebug() << "wrong implementation isHit(QPoint)"; return false; }
   virtual bool isHit(int x, int y)    {qDebug() << "wrong implementation isHit(int,int)"; return false; }
   virtual bool isInRange(QPoint p)    {qDebug() << "wrong implementation isInRange(QPoint)"; return false; }
   virtual bool isInRange(int x, int y){qDebug() << "wrong implementation isInRange(int,int)"; return false; }
   virtual bool isCrossAxisX(int y)    {qDebug() << "wrong implementation isCrossAxisX(int)"; return false; }
   virtual bool isCrossAxisY(int x)    {qDebug() << "wrong implementation isCrossAxisY(int)"; return false; }
   virtual QPoint p1() const           {qDebug() << "wrong implementation p1()"; return QPoint(0,0); }
   virtual QPoint p2() const           {qDebug() << "wrong implementation p2()"; return QPoint(0,0); }
   virtual int x() const               {qDebug() << "wrong implementation x()"; return 0;}
   virtual int y() const               {qDebug() << "wrong implementation y()"; return 0;}
   virtual void draw(QPainter &painter){qDebug() << "wrong implementation draw(QPainter)"; }
   virtual int binQuad(QRect &field)   {qDebug() << "wrong implementation draw(QPainter)"; return 0; }

// TODO: зачем сравнение ?
// virtual inline bool operator==(const X& sh1, const X& sh2){ qDebug() << "wrong implementation op=="; return false; }
   };

#endif // SHAPE_H
