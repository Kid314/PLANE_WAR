#include "menuview.h"


// ���˵�ҳ�����
void menuview::menuviewprint()
{
    putimage(0, 0, &img_menu_background[0]); // ����ֻ������һ�ű���ͼ

    //������Ϸ
    botton botton1(WIDTH/4,HEIGHT/7, WIDTH / 2,HEIGHT/7,"������Ϸ");
    //������Ϸ
    botton botton2(WIDTH / 4, HEIGHT *3/ 7, WIDTH / 2, HEIGHT / 7, "������Ϸ");
    //�˳���Ϸ
    botton botton3(WIDTH / 4, HEIGHT*5 / 7, WIDTH / 2, HEIGHT / 7, "�˳���Ϸ");
    menu_bottons.push_back(botton1);
    menu_bottons.push_back(botton2);
    menu_bottons.push_back(botton3);
    for (botton& kv : menu_bottons)
    {
        kv.printBotton();
    }
    FlushBatchDraw();
}

// ����ͼƬ��Դ�Ͱ�ť
void menuview::menu_loadimg() {
    // ���ر���ͼƬ
    img_menu_background.resize(1);
    loadimage(&img_menu_background[0], "../suorce/menu.jpg");
}