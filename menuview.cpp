#include "menuview.h"


// 主菜单页面绘制
void menuview::menuviewprint()
{
    putimage(0, 0, &img_menu_background[0]); // 假设只加载了一张背景图

    //继续游戏
    botton botton1(WIDTH/4,HEIGHT/7, WIDTH / 2,HEIGHT/7,"继续游戏");
    //进行游戏
    botton botton2(WIDTH / 4, HEIGHT *3/ 7, WIDTH / 2, HEIGHT / 7, "进行游戏");
    //退出游戏
    botton botton3(WIDTH / 4, HEIGHT*5 / 7, WIDTH / 2, HEIGHT / 7, "退出游戏");
    menu_bottons.push_back(botton1);
    menu_bottons.push_back(botton2);
    menu_bottons.push_back(botton3);
    for (botton& kv : menu_bottons)
    {
        kv.printBotton();
    }
    FlushBatchDraw();
}

// 加载图片资源和按钮
void menuview::menu_loadimg() {
    // 加载背景图片
    img_menu_background.resize(1);
    loadimage(&img_menu_background[0], "../suorce/menu.jpg");
}