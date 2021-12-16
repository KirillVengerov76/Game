//Kirill Vengerov 9"V"

#ifndef __PERS_H__
#define __PERS_H__

typedef class pers pers_t;
class pers
{
    int x;//положение на холсте по оси x
    int y;//положение на холсте по оси y
    int p;//анимация(шаги)
    int l;//поворот
    int loc;//поворот без движения
    int wr;//это нужно для колизии
    int n;
    int c;
    int mon;
    int yg;
    int res;
    int f;
    HDC picture;//персонаж
public:

    pers();
    ~pers();
    pers(const pers& pers);
    pers& operator = (pers p);
    void draw();
    int bot_maker();
    void move_up();
    void move_down();
    void move_right();
    void move_left();
    void move_uwall();
    void move_dwall();
    void move_rwall();
    void move_lwall();
    void update(maP &maP);
    void change(maP_t* maP);
    void in_bank(maP_t* maP);
    int debate(maP_t* maP);
    void chest(maP &maP);
    void restart(maP_t* maP);
    int finish(maP_t* maP);
};

pers::pers() : x(200),y(100),p(0),l(0),loc(1),wr(0),n(0),c(1),mon(0),yg(250),res(0),f(0),picture(txLoadImage ("knights_kv_pic.bmp"))
{
}

pers::~pers()
{
    txDeleteDC (picture);
}

pers::pers(const pers& peRs) : x(peRs.x),y(peRs.y),p(peRs.p),l(peRs.l),loc(peRs.loc),wr(peRs.wr),n(peRs.n),c(peRs.c),mon(peRs.mon),yg(peRs.yg),res(peRs.res),f(peRs.f),picture(peRs.picture)
{
    this->picture = txLoadImage ("knights_kv_pic.bmp");
}

pers& pers::operator = (pers pe)
{
    x = pe.x;
    y = pe.y;
    p = pe.p;
    l = pe.l;
    loc = pe.loc;
    wr = pe.wr;
    n = pe.n;
    c = pe.c;
    picture = nullptr;
    return *this;
}

void pers::draw()
{
    char chet [1];
    sprintf(chet,"%d",mon);
    Win32::TransparentBlt (txDC(), x, y, 48, 78, picture,0+p,l,57,90,RGB(0,0,0));
    txTextOut(0,0,chet);
}

int pers::bot_maker()
{
    return n;
}

void pers::move_up()
{
    l = 325;
    p += 160;
    if(loc == 3)
    {
        y-=16;
    }
    if(p > 160)
    {
        p = 0;
    }
    loc = 3;
}

void pers::move_down()
{
    l = 2;
    p += 160;
    if(loc == 1)
    {
        y+=16;
    }
    if(p > 160)
    {
        p = 0;
    }
    loc = 1;
}

void pers::move_right()
{
    l = 216;
    p += 160;
    if(loc == 2)
    {
        x+=16;
    }
    if(p > 160)
    {
        p = 0;
    }
    loc = 2;
}

void pers::move_left()
{
    l = 108;
    p += 160;
    if(loc == 4)
    {
        x-=16;
    }
    if(p > 160)
    {
        p = 0;
    }
    loc = 4;
}

void pers::move_uwall()
{
    l = 325;
    p = 76;
    y = y/48*48;
    wr = 1;
}

void pers::move_dwall()
{
    l = 2;
    p = 76;
    y = y/48*48+10;
    wr = 3;
}

void pers::move_rwall()
{
    l = 216;
    p = 76;
    x = (x/48 + 1)*48 - 7;
    wr = 4;
}

void pers::move_lwall()
{
    l = 108;
    p = 76;
    x = x/48*48;
    wr = 2;
}

void pers::update(maP &maP)
{
    if(GetAsyncKeyState('W'))
    {
        for(c = 1;c <= 8;c++)
        {
            if(maP.Map[(y-16)/48][x/48] == c || maP.Map[(y-16)/48][(x+48)/48] == c || maP.Map[(y-16)/48][(x+24)/48] == c)
            {
                if (wr!=1)
                {
                    if(l == 325)
                    {
                        move_uwall();
                        wr = 1;
                    }
                    l = 325;
                }
                return;
            }
        }
        move_up();
        wr = 0;
    }
    else if(GetAsyncKeyState('S'))
    {
        for(c = 1;c <= 8;c++)
        {
            if(maP.Map[(y+94)/48][x/48] == c || maP.Map[(y+94)/48][(x+48)/48] == c || maP.Map[(y+94)/48][(x+24)/48] == c)
            {
                if (wr!=3)
                {
                    if(l == 2)
                    {
                        move_dwall();
                        wr = 3;
                    }
                    l = 2;
                }
                return;
            }

        }
        move_down();
        wr = 0;
    }
    else if(GetAsyncKeyState('A'))
    {
        for(c = 1;c <= 8;c++)
        {
            if(maP.Map[y/48][(x-16)/48] == c || maP.Map[(y+78)/48][(x-16)/48] == c || maP.Map[(y+39)/48][(x-16)/48] == c)
            {
                if (wr!=4)
                {
                    if(l == 108)
                    {
                        move_lwall();
                            wr = 4;
                    }
                    l = 108;
                }
                return;
            }
        }
        move_left();
        wr = 0;
    }
    else if(GetAsyncKeyState('D'))
    {
        for(c = 1;c <= 8;c++)
        {
            if(maP.Map[y/48][(x+64)/48] == c || maP.Map[(y+78)/48][(x+64)/48] == c || maP.Map[(y+39)/48][(x+64)/48] == c)
            {
                if (wr!=2)
                {
                    if(l == 216)
                    {
                        move_rwall();
                        wr = 2;
                    }
                    l = 216;
                }
                return;
            }
        }
        move_right();
        wr = 0;
    }
}

void pers::change(maP_t* maP)
{
    if((*maP).Map[y/48 - 1][x/48] == 3)
    {
        txTextOut(50,400,"Press E to enter the gunstore.");
        if(GetAsyncKeyState('E'))
        {
            (*maP).load_fon();
            (*maP).bank_fon();
            y = 336;
            n = 1;
            c = 5;
        }
    }
}

void pers::in_bank(maP_t* maP)
{
    int k = 0;
    if((*maP).Map[y/48][((x-16)/48)] == 66)
    {
        txSetFillColor(RGB(0,0,0));
        txClear();
        (*maP).draw_fon();
        txSelectFont ("NN", 40, 10);
        while(!GetAsyncKeyState(VK_SPACE))
        {
            txClear();
            (*maP).draw_fon();
            txRectangle (40, 96, 410, 250);
            txTextOut(50,150,"Gunman:Friend,there was a case.");
            txSleep(1000);
        }
        txSleep(500);
        while(!GetAsyncKeyState(VK_SPACE))
        {
            txClear();
            (*maP).draw_fon();
            txRectangle (40, 96, 420, 250);
            txTextOut(50,150,"Gunman:The new armor was delivered.");
            txSleep(1000);
        }
        txSleep(500);
        while(!GetAsyncKeyState(VK_SPACE))
        {
            txClear();
            (*maP).draw_fon();
            txRectangle (40, 96, 410, 250);
            txTextOut(50,150,"Gunman:Please, pick it up from port.");
            txSleep(1000);
        }
        txSleep(500);
        while(!GetAsyncKeyState(VK_SPACE))
        {
            txClear();
            (*maP).draw_fon();
            txRectangle (40, 96, 400, 250);
            txTextOut(50,150,"Gunman:I will pay 50 orens.");//отсылочка
            txSleep(1000);
        }
        txSleep(500);
        (*maP).draw_fon();
        txRectangle (40, 96, 400, 250);
        txTextOut(50,150,"Press Y to agree");
        txTextOut(50,200,"Press N to bargain");
        txSleep(1000);
        while(k == 0)
        {
            if(GetAsyncKeyState('Y'))
            {
                txClear();
                (*maP).draw_fon();
                txRectangle (40, 130, 400, 250);
                txTextOut(50,130,"Knight:Fine,I'm going.");
                txSleep(1000);
                txClear();
                k++;
                mon+=50;
            }
            if(GetAsyncKeyState('N'))
            {
                txClear();
                (*maP).draw_fon();
                txRectangle (40, 130, 410, 250);
                txTextOut(50,150,"Gunman:Fine,75 orens, but no more.");
                txSleep(1000);
                txClear();
                k++;
                mon+=75;
            }
        }
        txSleep(1000);
        txClear();
        (*maP).load_fon();
        (*maP).in_pier();
        n = 2;
        x = 270;
        y = 402;
        txSelectFont ("Usually-font", 40);
    }
}

int pers::debate(maP_t* maP)
{
    int k = 0;
    if(n == 2)
    {
        if(y <= yg)
        {
            txSetFillColor(RGB(0,0,0));
            txSelectFont ("NN", 40, 10);
            while(!GetAsyncKeyState(VK_SPACE))
            {
                txClear();
                (*maP).draw_fon();
                txRectangle (48, 192, 456, 312);
                txTextOut(48,200,"Guard:Who are you?");
                txSleep(1000);
            }
            txSleep(500);
            while(!GetAsyncKeyState(VK_SPACE))
            {
                txClear();
                (*maP).draw_fon();
                txRectangle (48, 192, 456, 312);
                txTextOut(48,200,"Knight:I came from a gunsmith.");
                txSleep(1000);
            }
            txSleep(500);
            while(!GetAsyncKeyState(VK_SPACE))
            {
                txClear();
                (*maP).draw_fon();
                txRectangle (48, 192, 485, 312);
                txTextOut(48,200,"Guard:Only the owner can take this armor.");
                txSleep(1000);
            }
            txSleep(500);
            txClear();
            (*maP).draw_fon();
            txRectangle (96, 192, 456, 312);
            txTextOut(96,200,"Press P to pay 25 orens.");
            txTextOut(96,250,"Press C to conforont.");
            txSleep(1000);
            while(k == 0)
            {
                if(GetAsyncKeyState('P'))
                {
                    txClear();
                    (*maP).draw_fon();
                    txRectangle (96, 192, 456, 312);
                    txTextOut(96,200,"Guard:Fine,take it.");
                    txSleep(1000);
                    txClear();
                    mon-=25;
                    k++;
                    yg = -10;
                    n++;
                }
                if(GetAsyncKeyState('C'))
                {
                    txClear();
                    (*maP).draw_fon();
                    txRectangle (96, 192, 456, 312);
                    txTextOut(96,200,"Guard:Fine.");
                    txSleep(1000);
                    txClear();
                    (*maP).draw_fon();
                    txRectangle (96, 192, 456, 312);
                    txTextOut(96,200,"Guard:Arrest him!.");
                    txSleep(1000);
                    k+=2;
                }
            }
            if(k == 2)
            {
                txSelectFont ("NN", 110, 35);
                txClear();
                txPlaySound(NULL);
                txPlaySound("Busted.wav");
                txTextOut(85,200,"BUSTED");
                txSleep(2000);
                txClear();
                txSelectFont ("NN", 40, 10);
                txTextOut(20,200,"To restart-Y");
                txTextOut(20,250,"To terminate-Esc");
                txSleep(2000);
                k = 0;
                while(k == 0)
                {
                    if(GetAsyncKeyState('Y'))
                    {
                        txPlaySound("England Theme.wav",SND_LOOP);
                        x = 200;
                        y = 100;
                        p = 0;
                        l = 0;
                        loc = 1;
                        wr = 0;
                        n = 0;
                        c = 1;
                        (*maP).load_fon();
                        (*maP).restart();
                        k++;
                        mon = 0;
                        yg = 250;
                        txSelectFont ("Usually-font", 40);
                        return 0;
                    }
                    if(GetAsyncKeyState(VK_ESCAPE))
                    {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

void pers::chest(maP &maP)
{
    if(maP.Map[(y-8)/48][x/48] == 8 || maP.Map[(y-8)/48][(x+48)/48] == 8 || maP.Map[(y-8)/48][(x+24)/48] == 8||
    maP.Map[(y+78)/48][x/48] == 8 || maP.Map[(y+78)/48][(x+48)/48] == 8 || maP.Map[(y+78)/48][(x+24)/48] == 8||
    maP.Map[y/48][(x-8)/48] == 8 || maP.Map[(y+78)/48][(x-8)/48] == 8 || maP.Map[(y+39)/48][(x-8)/48] == 8)
    {
        txTextOut(100,400,"Press E to open chest.");
        if(GetAsyncKeyState('E'))
        {
            txClear();
            txSetFillColor(RGB(0,0,0));
            txRectangle (40, 130, 400, 250);
            txSelectFont ("NN", 40, 10);
            txTextOut(50,150,"Knight:Job done.");
            txSleep(1000);
            txClear();
            f++;
        }
    }
}

void pers::restart(maP_t* maP)
{
    if(res == 1)
    {
        (*maP).restart();
        res = 0;
    }
}

int pers::finish(maP_t* maP)
{
    int k = 0;
    if(f == 1)
    {
        (*maP).load_fon();
        (*maP).bank_fon();
        txSetFillColor(RGB(0,0,0));
        txSelectFont ("NN", 40, 10);
        while(!GetAsyncKeyState(VK_SPACE))
        {
            txClear();
            (*maP).draw_fon();
            txRectangle (40, 96, 410, 250);
            txTextOut(50,150,"Gunman:Thanks for the help.");
            txSleep(1000);
        }
        txSleep(500);
        while(!GetAsyncKeyState(VK_SPACE))
        {
            txClear();
            (*maP).draw_fon();
            txRectangle (40, 96, 410, 250);
            txTextOut(50,150,"Gunman:Take it for reward.");
            txSleep(1000);
        }
        txSleep(500);
        txClear();
        txPlaySound(NULL);
        txPlaySound("win.wav");
        (*maP).reward();
        txTextOut(50,150,"Press Y to restart.");
        txTextOut(50,200,"Press ESC to finish.");
        txSleep(1000);
        txClear();
        while(k == 0)
        {
            if(GetAsyncKeyState('Y'))
            {
                x = 200;
                y = 100;
                p = 0;
                l = 0;
                loc = 1;
                wr = 0;
                n = 0;
                c = 1;
                k++;
                res = 1;
                mon = 0;
                f = 0;
                yg = 250;
                txSelectFont ("Usually-font", 40);
                txPlaySound("England Theme.wav",SND_LOOP);
                return 0;
            }
            if(GetAsyncKeyState(VK_ESCAPE))
            {
                return 1;
            }
        }
    }
    return 0;
}
#endif //__PERS_H__

