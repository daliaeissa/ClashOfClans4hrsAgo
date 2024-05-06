#include "worker.h"
#include<QTimer>
#include "fence.h"

worker::worker() {
}


void worker::moveWorker1() {
    //if (x() >= 240 && y() <= 300) {
        // setPos(x() - 2,y());
    if (x() != -40)
      {
           setPos(x() - 1,y());
    }
    else
    {
        setPos(x(),y());
    }
}
    // QList<QGraphicsItem*> colliding_items1 = collidingItems();

    // for(int i = 0; i < colliding_items1.size(); i++)
    // {

    //     if(typeid(*(colliding_items1[i])) == typeid(Fence))
    //     {
    //         setPos(-40, y());
    //     }
    //  }
    //     else {
    //         setPos(x() - 2, y() - 3.75);
    //     }
    // //}
    // else if (x() == 260 && y() == 300) {
    //     setPos(x() + 2, y() - 3.75);
    //     if (x() == 350) {
    //         setPos(350, 225);
    //     }
    // }
    // else if (x() == 250 && y() == 290) {
    //     setPos(x() + 0.5, y() - 5);
    //     if (y() == 100) {
    //         setPos(275, 100);
    //     }
    // }
    // else if (x() == 250 && y() == 310) {
    //     setPos(x() + 1.25, y() + 2);
    //     if (y() == 350) {
    //         setPos(275, 350);
    //     }
    // }


void worker::moveWorker2() {
    // setPos(x() + 2, y());
   if (x() != 115)
    {
        setPos(x() + 1, y());
    }
   else
   {
       setPos(x(),y());
   }

}
//             setPos(350, 225);
//         }
// }
//     QList<QGraphicsItem*> colliding_items2 = collidingItems();

//     for(int i = 0; i < colliding_items2.size(); i++)
//     {

//         if(typeid(*(colliding_items2[i])) == typeid(Fence))
//         {
//             setPos(110, y());
//         }
//     }
// }

void worker::moveWorker3() {
    // setPos(x() + 0.5, y() - 5);
      if (y() != -190)
    {
     setPos(x() , y() - 5);
      }
      else
      {
          setPos(x(),y());
      }
}
//             setPos(275, 100);
//         }
// }
//     QList<QGraphicsItem*> colliding_items3 = collidingItems();

//     for(int i = 0; i < colliding_items3.size(); i++)
//     {

//         if(typeid(*(colliding_items3[i])) == typeid(Fence))
//         {
//             setPos(75, -190);
//         }
//     }
// }

void worker::moveWorker4()
      {
    // setPos(x() + 1.25, y() + 2);
  if (y() != 65)
    {
        setPos(x(), y() + 1);
 }
  else
  {
      setPos(x(),y());
  }
      }
// }
//     QList<QGraphicsItem*> colliding_items4 = collidingItems();

//     for(int i = 0; i < colliding_items4.size(); i++)
//     {

//         if(typeid(*(colliding_items4[i])) == typeid(Fence))
//         {
//             setPos(25, 40);
//         }
//     }
// }
