#pragma once
#include<vector>
#include "botton.h"
//���ڿ�Ⱥ͸߶��Լ�����
#include "view.h"
using namespace std;
//---------------------------------------------���˵�ҳ��-----------------------------------------
//���ҳ��İ�ť
//ÿ��ҳ�涼���Լ���vector<botton>
extern vector<botton> menu_bottons;

//��ű���ͼƬ
extern vector<IMAGE> img_menu_background;

class menuview
{
public:
	/*
	* ����ˣ�����
	* ������void
	* �����void
	* ���ܣ�
		����ͼƬ
		ʹ��loadimage������������Ҫ��ͼƬ���ص����ԵĴ�Ŵ�
		-img_menu_background
		-img_menu_bottons
	*/
	void menu_loadimg();

	/*
	* ����ˣ�����
	* ������const botton& my_botton
	* �����void
	* ���ܣ�
		������ť
		�����°�ť���뵽���Ե�botton�������з������
	*/
	void addNewBotton(const botton& my_botton);

	/*
	* * ����ˣ�����
	* ������void
	* �����void
	* ���ܣ�
		�����������˵�ҳ�棬����ҳ������ת�߼�
	*/
	void menuviewprint();
};



