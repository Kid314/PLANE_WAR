#pragma once
#include<vector>
#include "view.h"
#include "botton.h"
#include<iostream>
#include<easyx.h>
#include <conio.h>
using namespace std;

//存放页面的按钮
extern vector<botton> pause_bottons;

//存放背景图片
extern vector<IMAGE> img_pause_background;

//存放页面的按钮图片
extern vector<IMAGE> img_pause_bottons;

//-------------------------暂停界面------------------------

class pauseview
{
public:
	/*
	* * 完成人：张三
	* 参数：void
	* 输出：void
	* 功能：
		加载图片
		使用loadimage函数将所有需要的图片加载到各自的存放处
		-img_pause_background
		-img_pause_bottons
	*/
	void pauseview_loadimg();

	/*
	* * 完成人：张三
	* 参数：void
	* 输出：void
	* 功能：
		制作所有需要的页面
		加到pause_views数组中去
	*/
	void pauseviewprint();

	/*
	参数：void
	功能：点击后，进入游戏设置
	*/
	//void 
};

