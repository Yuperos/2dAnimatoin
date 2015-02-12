#ifndef FRAME_H
#define FRAME_H

#include <QList>
#include <QImage>
#include <QPainter>
#include <typeinfo>

#include "shape.h"
#include "myline.h"
#include "mypoint.h"
#include "quadtree.h"


class Frame
   {
   QuadTree quadTree;
   QList<Shape> SceneElements;

   QList<MyPoint> *selPoints;
   QList<MyLine> *selLines;

public:
   Frame(QRect qrect);

   Frame add(MyLine line){ SceneElements.append(line); return *this; }
   Frame add(MyPoint point){ SceneElements.append(point); return *this; }

   void select(MyPoint p){ selPoints->append(p); }
   void select(MyLine l) { selLines->append(l); }
   void clearSelection(){ selPoints->clear(); selLines->clear(); }

   void drawScene(QImage *image);

//   QList<QPoint>* getNodes(){ return points; }
//   QList<QLine>* getLines() { return lines; }

   };

#endif // FRAME_H
