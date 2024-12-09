#pragma once
#include<vector>
#include "botton.h"
//窗口宽度和高度以及积分
#include "view.h"
using namespace std;
//---------------------------------------------主菜单页面-----------------------------------------
//存放页面的按钮
//每个页面都有自己的vector<botton>
extern vector<botton> menu_bottons;

//存放背景图片
extern vector<IMAGE> img_menu_background;

class menuview
{
public:
	/*
	* 完成人：张三
	* 参数：void
	* 输出：void
	* 功能：
		加载图片
		使用loadimage函数将所有需要的图片加载到各自的存放处
		-img_menu_background
		-img_menu_bottons
	*/
	void menu_loadimg();

	/*
	* 完成人：张三
	* 参数：const botton& my_botton
	* 输出：void
	* 功能：
		创建按钮
		并将新按钮加入到各自的botton的数组中方便调用
	*/
	void addNewBotton(const botton& my_botton);

	/*
	* * 完成人：张三
	* 参数：void
	* 输出：void
	* 功能：
		制作所有主菜单页面，包括页面间的跳转逻辑
	*/
	void menuviewprint();
};



