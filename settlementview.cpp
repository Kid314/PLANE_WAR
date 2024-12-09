#include "settlementview.h"

void settlementview::winview()
{
	//绘制按钮
	botton victory_botton(WIDTH / 4, HEIGHT / 8, WIDTH / 2, HEIGHT / 4, "胜利");
	string score_str = "";
	std::stringstream ss;
	ss << "得分为:" << my_score;
	score_str = ss.str();
	botton score_botton(WIDTH * 3 / 8, (HEIGHT / 8 + HEIGHT / 4) + 20, WIDTH / 4, HEIGHT / 8, score_str);
	//botton xiayiguan_botton(WIDTH * 7 / 16, (HEIGHT / 8 + HEIGHT / 4 + HEIGHT / 8) + 20 * 2, WIDTH / 6, HEIGHT / 16, "下一关");
	botton chongxintiaozhan_botton(WIDTH * 7 / 16, (HEIGHT / 8 + HEIGHT / 4 + HEIGHT / 8 + HEIGHT / 16) + 20 * 3, WIDTH / 6, HEIGHT / 16, "重新挑战");
	botton fanhui_botton(WIDTH * 7 / 16, (HEIGHT / 8 + HEIGHT / 4 + HEIGHT / 8 + HEIGHT / 16 * 2) + 20 * 4, WIDTH / 6, HEIGHT / 16, "返回主菜单");
	//打印按钮
	victory_botton.printBotton();
	score_botton.printBotton();
	//xiayiguan_botton.printBotton();
	chongxintiaozhan_botton.printBotton();
	fanhui_botton.printBotton();
	//把绘制的按钮添加到settlement_bottons中
	settlement_bottons.push_back(victory_botton);
	settlement_bottons.push_back(score_botton);
	settlement_bottons.push_back(chongxintiaozhan_botton);
	settlement_bottons.push_back(fanhui_botton);
}

void settlementview::loseview()
{
	botton defeat_botton(WIDTH / 4, HEIGHT / 8, WIDTH / 2, HEIGHT / 4, "失败");
	char score_str[50] = "";
	sprintf_s(score_str, "得分为:%d", my_score);
	botton score_botton(WIDTH * 3 / 8, (HEIGHT / 8 + HEIGHT / 4) + 20, WIDTH / 4, HEIGHT / 8, score_str);
	botton nanduxuanze_botton(WIDTH * 7 / 16, (HEIGHT / 8 + HEIGHT / 4 + HEIGHT / 8) + 20 * 2, WIDTH / 6, HEIGHT / 16, "难度选择");
	botton chongxintiaozhan_botton(WIDTH * 7 / 16, (HEIGHT / 8 + HEIGHT / 4 + HEIGHT / 8 + HEIGHT / 16) + 20 * 3, WIDTH / 6, HEIGHT / 16, "重新挑战");
	botton fanhui_botton(WIDTH * 7 / 16, (HEIGHT / 8 + HEIGHT / 4 + HEIGHT / 8 + HEIGHT / 16 * 2) + 20 * 4, WIDTH / 6, HEIGHT / 16, "返回主菜单");

	defeat_botton.printBotton();
	score_botton.printBotton();
	nanduxuanze_botton.printBotton();
	chongxintiaozhan_botton.printBotton();
	fanhui_botton.printBotton();

	settlement_bottons.push_back(defeat_botton);
	settlement_bottons.push_back(score_botton);
	settlement_bottons.push_back(nanduxuanze_botton);
	settlement_bottons.push_back(chongxintiaozhan_botton);
	settlement_bottons.push_back(fanhui_botton);
}
