//Kirill Vengerov 9"V"

#ifndef __MAP_H__
#define __MAP_H__

typedef class maP maP_t;
class maP
{
    int room;
    HDC background;
public:
    int Map[10][10];
    maP();
    ~maP();
    maP(const maP& maP);
    maP& operator = (maP);
    void draw_fon();
    void bank_fon();
    void load_fon();
    void in_pier();
    void restart();
    void reward();
    //void get_sell();
    //void set_sell();
};

maP::maP() : room(1),background(txLoadImage ("fon_kirillv.bmp"))
{
    int i = 0;
    int j = 0;
    int card[10][10] =
    {{  1, 1, 1, 1,  1,  3,  1, 1, 1, 1 },
     {  1, 1, 1, 1, 22, 22, 22, 1, 1, 1 },
     {  1, 1, 1, 1, 22, 22, 22, 1, 1, 1 },
     {  1, 1, 1, 1, 22, 22, 22, 1, 1, 1 },
     {  1, 1, 1, 1, 22, 22, 22, 1, 1, 1 },
     {  1, 1, 1, 1, 22, 22, 22, 1, 1, 1 },
     {  1, 1, 1, 1, 22, 22, 22, 1, 1, 1 },
     {  1, 1, 1, 1, 22, 22, 22, 1, 1, 1 },
     {  1, 1, 1, 1, 22, 22, 22, 1, 1, 1 },
     {  1, 1, 1, 1,  1,  1,  1, 1, 1, 1 }};
    for(i = 0;i < 10;i++)
    {
        for(j = 0;j < 10;j++)
        {
            Map[i][j] = card[i][j];
        }
    }
}

maP::~maP()
{
    txDeleteDC (background);
}

maP::maP(const maP& mAp) : room(mAp.room),background(mAp.background)
{
    this->background = txLoadImage ("fon_kirillv.bmp");
}

maP& maP::operator = (maP)
{
    background = nullptr;
    return *this;
}

void maP::draw_fon()
{
    int xm = 0;
    int ym = 0;
    int xp = 0;
    int yp = 0;
    for(xm = 0;xm < 10;xm++)
    {
        for(ym = 0;ym < 10;ym++)
        {
            if(Map[ym][xm] == 1)
            {
                xp = 311;
                yp = 190;
            }
            else if(Map[ym][xm] == 22)
            {
                xp = 422;
                yp = 305;
            }
            else if(Map[ym][xm] == 3)
            {
                xp = 35;
                yp = 36;
            }
            else if(Map[ym][xm] == 5)
            {
                xp = 457;
                yp = 605;
            }
            else if(Map[ym][xm] == 66)
            {
                xp = 120;
                yp = 233;
            }
            else if(Map[ym][xm] == 7)
            {
                xp = 554;
                yp = 545;
            }
            else if(Map[ym][xm] == 8)
            {
                xp = 12;
                yp = 35;
            }
            Win32::TransparentBlt (txDC(), 48*xm, 48*ym, 48, 48, background, xp, yp, 24, 24,RGB(32,32,64));
        }
    }
    if(room == 1)
    {
        xp = 36;
        yp = 11;
        Win32::TransparentBlt (txDC(), 48*6, 0, 48, 48, background, xp, yp, 24, 24,RGB(32,32,64));
        xp = 11;
        yp = 11;
        Win32::TransparentBlt (txDC(), 48*4, 0, 48, 48, background, xp, yp, 24, 24,RGB(32,32,64));
    }
}

void maP::bank_fon()
{
    room = 2;
    int i = 0;
    int j = 0;
    int card[10][10] =
    {{  5, 5,  5,   5,  5,  5,  5, 5, 5, 5 },
     {  5, 5,  5,   5, 22, 22, 22, 5, 5, 5 },
     {  5, 5, 22,  66, 22, 22, 22, 5, 5, 5 },
     {  5, 5, 22,  66, 22, 22, 22, 5, 5, 5 },
     {  5, 5,  5,   5, 22, 22, 22, 5, 5, 5 },
     {  5, 5, 22,  22, 22, 22, 22, 5, 5, 5 },
     {  5, 5, 22,  22, 22, 22, 22, 5, 5, 5 },
     {  5, 5, 22,  22, 22, 22, 22, 5, 5, 5 },
     {  5, 5, 22,  22, 22, 22, 22, 5, 5, 5 },
     {  5, 5,  5,   5,  5,  3,  5, 5, 5, 5 }};
    for(i = 0;i < 10;i++)
    {
        for(j = 0;j < 10;j++)
        {
            Map[i][j] = card[i][j];
        }
    }
}

void maP::load_fon()
{
    int x = 100;
    int xo = 100;
    while(x < 350)
    {
        txSetFillColor(RGB(0,0,0));
        txClear();
        txTextOut(200,200,"Loading...");
        txLine(xo,400,x,400);
        x+=10;
        txSleep(1);
    }
}

void maP::in_pier()
{
    int i = 0;
    int j = 0;
    int card[10][10] =
    {{  7, 7,  7,   7,  7,  7,  7, 7, 7, 7 },
     {  7, 7, 22,  22, 22, 22, 22, 7, 7, 7 },
     {  7, 7, 22,  22, 22, 22, 22, 7, 7, 7 },
     {  7, 7,  8,  22, 22, 22, 22, 7, 7, 7 },
     {  7, 7, 22,  22, 22, 22, 22, 7, 7, 7 },
     {  7, 7, 22,  22, 22, 22, 22, 7, 7, 7 },
     {  7, 7,  7,   7, 22, 22, 22, 7, 7, 7 },
     {  7, 7,  7,   7, 22, 22, 22, 7, 7, 7 },
     {  7, 7,  7,   7, 22, 22, 22, 7, 7, 7 },
     {  7, 7,  7,   7, 22, 22, 22, 7, 7, 7 }};
    for(i = 0;i < 10;i++)
    {
        for(j = 0;j < 10;j++)
        {
            Map[i][j] = card[i][j];
        }
    }
}

void maP::restart()
{
    room = 1;
    int i = 0;
    int j = 0;
    int card[10][10] =
    {{  1, 1, 1, 1,  1,  3,  1, 1, 1, 1 },
     {  1, 1, 1, 1, 22, 22, 22, 1, 1, 1 },
     {  1, 1, 1, 1, 22, 22, 22, 1, 1, 1 },
     {  1, 1, 1, 1, 22, 22, 22, 1, 1, 1 },
     {  1, 1, 1, 1, 22, 22, 22, 1, 1, 1 },
     {  1, 1, 1, 1, 22, 22, 22, 1, 1, 1 },
     {  1, 1, 1, 1, 22, 22, 22, 1, 1, 1 },
     {  1, 1, 1, 1, 22, 22, 22, 1, 1, 1 },
     {  1, 1, 1, 1, 22, 22, 22, 1, 1, 1 },
     {  1, 1, 1, 1,  1,  1,  1, 1, 1, 1 }};
    for(i = 0;i < 10;i++)
    {
        for(j = 0;j < 10;j++)
        {
            Map[i][j] = card[i][j];
        }
    }
}

void maP::reward()
{
    Win32::TransparentBlt (txDC(), 160, 160, 160, 160, background, 85, 10, 24, 24,RGB(32,32,64));
}

#endif //__MAP_H__


