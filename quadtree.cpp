#include "quadtree.h"

QuadNode *QuadTree::fromShapeList(QList<Shape *> ShapeList)
   {
   foreach(Shape *shape, ShapeList){
      add(*shape);
      }
   return this;
}

QuadNode *QuadTree::Select(QPoint p)
   {
   return this->setSelectionInPointTo(p, true);
   }

QuadNode *QuadTree::unSelect(QPoint p)
   {
   return this->setSelectionInPointTo(p, false);
   }

QuadTree::~QuadTree()
   {
   prune();
   }






