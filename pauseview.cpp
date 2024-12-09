#include "pauseview.h"
//#include"Setting.h"
void pauseview::pauseviewprint()
{
	putimage(0, 0, &img_pause_background[0]);

	botton button1(420, 350, 166, 200, "继续游戏");
	botton button2(420, 551, 166, 200, "设置");
	botton button3(420, 752, 166, 200, "返回主菜单");

	pause_bottons.push_back(button1);
	pause_bottons.push_back(button2);
	pause_bottons.push_back(button3);
	for (int i = 0; i < pause_bottons.size(); i++) {
		pause_bottons[i].printBotton();
	}
}

void pauseview::pauseview_loadimg()
{
	img_pause_background.resize(1);
	loadimage(&img_pause_background[0], "../suorce/pause.jpg", WIDTH, HEIGHT);/*266*/
}
