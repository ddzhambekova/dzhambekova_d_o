#ifndef DRAWING_H
#define DRAWING_H

#include<QLabel>

enum Pics
{
    P_UP = 0,
    P_DOWN,
    P_LEFT,
    P_RIGHT,
    P_JUMP
};

class drawing : public QLabel
{
public:
    drawing();
    void pic(Pics pic);
};

#endif // DRAWING_H
