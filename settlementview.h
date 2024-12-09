#pragma once
#include "Plane.h"
#include "botton.h"
//窗口宽度和高度以及积分
#include "view.h"
#include<sstream>
using namespace std;
//------------------------------------暂停页面---------------------
extern vector<botton> settlement_bottons;
//存放背景图片
extern vector<IMAGE> img_settlement_background;

class settlementview
{
public:
	int my_score;
	/*
	* * 完成人：张三
	* 参数：void
	* 输出：void
	* 功能：
	*			结合上述函数和easyx自带函数完成通关界面
	*			添加到存放页面的数组中去
	*/
	void winview();

	/*
	* * 完成人：张三
	* 参数：void
	* 输出：void
	* 功能：
	*			结合上述函数和easyx自带函数完成失败界面
	*			添加到存放页面的数组中去
	*/
	void loseview();

	settlementview(int score):my_score(score){}
};

