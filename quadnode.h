#ifndef QUADNODE_H
#define QUADNODE_H

#include <QRect>
#include <QList>
#include <typeinfo>

#include <myline.h>
#include <mypoint.h>

class QuadNode{
   QList<Shape*> shapeList;
   QuadNode* Quadrants[4];
   QRect field;
public:
   QuadNode(){}
   QuadNode(int x, int y,int Width,int Height);
   QuadNode(QRect rect);
   void initialize();

   void add(Shape &shape);
   //void move(); ??
   void delShape(Shape &shape);
   QuadNode *find(Shape &shape);
   int quad(Shape shape);
   int quad(QPoint p);
   QuadNode *setSelectionInPointTo(QPoint p, bool isSelect);
   void prune();

   ~QuadNode();
   };

#endif // QUADNODE_H
