//Kirill Vengerov 9"V"

#ifndef __BOT_H__
#define __BOT_H__

typedef class bot bot_t;
class bot
{
    HDC knight;
    HDC gunman;
public:
    bot();
    ~bot();
    bot(const bot& bOt);
    bot& operator = (bot);
    void draw_gunman(pers &pers);
    void draw_guard(pers &pers);
};

bot::bot() : knight(txLoadImage ("knights_kv_pic2.bmp")),gunman(txLoadImage ("secound_pers.bmp"))
{
}

bot::~bot()
{
    txDeleteDC (knight);
    txDeleteDC (gunman);
}

bot::bot(const bot& bOt) : knight(bOt.knight),gunman(bOt.gunman)
{
    this->knight = txLoadImage ("knights_kv_pic2.bmp");
    this->gunman = txLoadImage ("secound_pers.bmp");
}

bot& bot::operator = (bot)
{
    knight = nullptr;
    gunman = nullptr;
    return *this;
}

void bot::draw_gunman(pers &pers)
{
    int n = pers.bot_maker();
    if(n == 1)
    {
        Win32::TransparentBlt (txDC(), 96, 96, 48, 78, gunman,492,68,57,99,RGB(160,160,192));
    }
}

void bot::draw_guard(pers &pers)
{
    int n = pers.bot_maker();
    if(n == 2)
    {
        Win32::TransparentBlt (txDC(), 240, 192, 48, 78, knight,227,0,57,90,RGB(0,0,0));
    }
}
#endif //__BOT_H__
