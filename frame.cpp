#include "frame.h"

Frame::Frame(QRect qrect)
   {
   quadTree = QuadTree(qrect);
   }


void Frame::drawScene(QImage *image)
   {
   QPainter p;
   image->fill(Qt::white);
   p.begin(image);
   p.setBrush(Qt::yellow);
   p.setPen(Qt::red);
   foreach(Shape shape, SceneElements)
      {
      shape.draw(p);
      }
   }
