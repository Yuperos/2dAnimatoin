#include "quadnode.h"

QuadNode::QuadNode(QRect rect)
   {
   field=rect;
   initialize();
   }

QuadNode::QuadNode(int x, int y, int Width, int Height)
   {
   field.setRect(x,y,Width,Height);
   initialize();
   }

void QuadNode::initialize()
   {
   for(int i=0; i<4; i++)
      Quadrants[i]=NULL;
   }

void QuadNode::add(Shape &shape)
   {
   int quadNumber;
   QPoint mid=field.center();
   if (shapeList.isEmpty())
      shapeList.append(&shape);
   else{
      if (shape.isCrossAxisY(mid.x()) ||
          shape.isCrossAxisX(mid.y())) {
         shapeList.append(&shape);
         }
      else{
         quadNumber=quad(shape);
         if (Quadrants[quadNumber]==NULL)
            switch(quadNumber){
               case 0: Quadrants[0] = new QuadNode(0,0,mid.x(),mid.y());                 break;
               case 1: Quadrants[1] = new QuadNode(mid.x(),0,mid.x()*2,mid.y());         break;
               case 2: Quadrants[2] = new QuadNode(mid.x(),mid.y(),mid.x()*2,mid.y()*2); break;
               case 3: Quadrants[3] = new QuadNode(0,mid.y(),mid.x(),mid.y()*2);         break;
               default: break;
               }
         Quadrants[quadNumber]->add(shape);
         }
      }
   }

//void QuadNode::delShape(Shape &shape)
//   {
//   QuadNode *qNode = find(shape);
//   if
//         //
//   }


QuadNode *QuadNode::find(Shape &shape)
   {
   if (shapeList.contains(&shape))
      return this;
   int currentQuad = quad(shape);
   if (Quadrants[currentQuad]!=NULL)
      return Quadrants[currentQuad]->find(shape);
   else
      return NULL;
   }

int QuadNode::quad(Shape shape)
   {
   int binQuad = shape.binQuad(field);
   switch(binQuad){
      case 1: return 0;
      case 2: return 1;
      case 4: return 2;
      case 8: return 3;
      default: break;
      }
   return -1;
}

int QuadNode::quad(QPoint p)
   {
   int binQuad;
      binQuad  = (p.x() > field.center().x())?6:9;   //()? 0110b : 1001b
      binQuad &= (p.y() > field.center().y())?12:3;  //()? 1100b : 0011b
   switch(binQuad){
      case 1: return 0;
      case 2: return 1;
      case 4: return 2;
      case 8: return 3;
      default: break;
      }
   return -1;
}

QuadNode *QuadNode::setSelectionInPointTo(QPoint p, bool isSelect)
   {
   foreach( Shape* shape, shapeList){
      if (shape->isHit(p) && shape->isSelected() != isSelect)
          shape->setSelectionTo(isSelect);
      return this;
      }
   int qurrentQuad;
   if (Quadrants!=NULL)
      {
      qurrentQuad=quad(p);
      if (Quadrants[qurrentQuad]!=NULL)
         return Quadrants[qurrentQuad]->setSelectionInPointTo(p,isSelect);
      }
   return NULL;
   }

void QuadNode::prune()
   {
   for(int i=0; i<4; i++) {
      if (Quadrants[i]!=NULL) Quadrants[i]->prune();
      }
   delete this;
   }



QuadNode::~QuadNode()
   {
   delete this;
   }

