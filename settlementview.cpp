#include "settlementview.h"

void settlementview::winview()
{
	//���ư�ť
	botton victory_botton(WIDTH / 4, HEIGHT / 8, WIDTH / 2, HEIGHT / 4, "ʤ��");
	string score_str = "";
	std::stringstream ss;
	ss << "�÷�Ϊ:" << my_score;
	score_str = ss.str();
	botton score_botton(WIDTH * 3 / 8, (HEIGHT / 8 + HEIGHT / 4) + 20, WIDTH / 4, HEIGHT / 8, score_str);
	//botton xiayiguan_botton(WIDTH * 7 / 16, (HEIGHT / 8 + HEIGHT / 4 + HEIGHT / 8) + 20 * 2, WIDTH / 6, HEIGHT / 16, "��һ��");
	botton chongxintiaozhan_botton(WIDTH * 7 / 16, (HEIGHT / 8 + HEIGHT / 4 + HEIGHT / 8 + HEIGHT / 16) + 20 * 3, WIDTH / 6, HEIGHT / 16, "������ս");
	botton fanhui_botton(WIDTH * 7 / 16, (HEIGHT / 8 + HEIGHT / 4 + HEIGHT / 8 + HEIGHT / 16 * 2) + 20 * 4, WIDTH / 6, HEIGHT / 16, "�������˵�");
	//��ӡ��ť
	victory_botton.printBotton();
	score_botton.printBotton();
	//xiayiguan_botton.printBotton();
	chongxintiaozhan_botton.printBotton();
	fanhui_botton.printBotton();
	//�ѻ��Ƶİ�ť��ӵ�settlement_bottons��
	settlement_bottons.push_back(victory_botton);
	settlement_bottons.push_back(score_botton);
	settlement_bottons.push_back(chongxintiaozhan_botton);
	settlement_bottons.push_back(fanhui_botton);
}

void settlementview::loseview()
{
	botton defeat_botton(WIDTH / 4, HEIGHT / 8, WIDTH / 2, HEIGHT / 4, "ʧ��");
	char score_str[50] = "";
	sprintf_s(score_str, "�÷�Ϊ:%d", my_score);
	botton score_botton(WIDTH * 3 / 8, (HEIGHT / 8 + HEIGHT / 4) + 20, WIDTH / 4, HEIGHT / 8, score_str);
	botton nanduxuanze_botton(WIDTH * 7 / 16, (HEIGHT / 8 + HEIGHT / 4 + HEIGHT / 8) + 20 * 2, WIDTH / 6, HEIGHT / 16, "�Ѷ�ѡ��");
	botton chongxintiaozhan_botton(WIDTH * 7 / 16, (HEIGHT / 8 + HEIGHT / 4 + HEIGHT / 8 + HEIGHT / 16) + 20 * 3, WIDTH / 6, HEIGHT / 16, "������ս");
	botton fanhui_botton(WIDTH * 7 / 16, (HEIGHT / 8 + HEIGHT / 4 + HEIGHT / 8 + HEIGHT / 16 * 2) + 20 * 4, WIDTH / 6, HEIGHT / 16, "�������˵�");

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
