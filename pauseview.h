#pragma once
#include<vector>
#include "view.h"
#include "botton.h"
#include<iostream>
#include<easyx.h>
#include <conio.h>
using namespace std;

//���ҳ��İ�ť
extern vector<botton> pause_bottons;

//��ű���ͼƬ
extern vector<IMAGE> img_pause_background;

//���ҳ��İ�ťͼƬ
extern vector<IMAGE> img_pause_bottons;

//-------------------------��ͣ����------------------------

class pauseview
{
public:
	/*
	* * ����ˣ�����
	* ������void
	* �����void
	* ���ܣ�
		����ͼƬ
		ʹ��loadimage������������Ҫ��ͼƬ���ص����ԵĴ�Ŵ�
		-img_pause_background
		-img_pause_bottons
	*/
	void pauseview_loadimg();

	/*
	* * ����ˣ�����
	* ������void
	* �����void
	* ���ܣ�
		����������Ҫ��ҳ��
		�ӵ�pause_views������ȥ
	*/
	void pauseviewprint();

	/*
	������void
	���ܣ�����󣬽�����Ϸ����
	*/
	//void 
};

