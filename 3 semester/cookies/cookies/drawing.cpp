#include "drawing.h"

drawing::drawing()
{

}

void drawing::pic(Pics pic)
{
    switch(pic)
    {
    case(P_UP):
        this->setPixmap(QPixmap(":/images/images/uparrow.png"));
        break;
    case(P_DOWN):
        this->setPixmap(QPixmap(":/images/images/downarr2.png"));
        break;
    case(P_LEFT):
        this->setPixmap(QPixmap(":/images/images/leftarrow.png"));
        break;
    case(P_RIGHT):
        this->setPixmap(QPixmap(":/images/images/rightarrow.png"));
        break;
    case(P_JUMP):
        this->setPixmap(QPixmap(":/images/images/jump32.png"));
        break;
    }
}
