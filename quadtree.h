#ifndef QUADTREE_H
#define QUADTREE_H

#include "quadnode.h"

class QuadTree : public QuadNode
   {
public:
   QuadTree():QuadNode(){}
   QuadTree(QRect qrect):QuadNode(qrect){}
   QuadTree(int windowWidth, int windowHeight):QuadNode(0,0,windowWidth,windowHeight){}

   QuadNode *fromShapeList(QList<Shape *> ShapeList);
   QuadNode *Select(QPoint p);
   QuadNode *unSelect(QPoint p);

   ~QuadTree();
   };

#endif // QUADTREE_H
