#pragma once
#include<vector>
#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>
#include "botton.h"
#include<map>
//窗口宽度和高度以及积分
#include "view.h"
using namespace std;
//-----------------------------登录页面----------------------------
//存放界面按钮
//每个页面都有自己的vector<botton>
extern vector<vector<botton>> login_bottons;

extern map<string, string>accounts;

//存放背景图片
extern vector<IMAGE> img_login_background;

class loginview
{
public:
	vector<vector<botton>> login_bottons;

	map<string, string>accounts;

	//存放背景图片
	vector<IMAGE> img_login_background;
	ExMessage msg = {0};
	string input_account;
	string input_password;
	char ch;
	fstream fpr;

	loginview():ch('\0')
	{
		fpr.open("account.txt", ios::out);
	}

	~loginview()
	{
		fpr.close();
	}

	/*
	* * 完成人：张三
	* 参数：void
	* 输出：void
	* 功能：
		加载图片
		使用loadimage函数将所有需要的图片加载到各自的存放处
		botton可以选择加不加图片都无所谓
		-img_login_background
		-img_login_bottons(非必要）
	*/
	void login_loadimg();

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
	* 完成人：张三
	* 参数：void
	* 输出：void
	* 功能：
	*			获取用户输入并输入到input_account和input_password中
	*/
	void receive();

	/*
	* 完成人：张三
	* 参数：fstream& fpr
	* 输出：bool
	* 功能：
	*			判断是否符合文件中的账号密码
	*			并反馈账号错误或者密码错误
	*			或者不存在此账号
	*/
	bool isaccount(fstream& fpr);

	/*
	* * 完成人：张三
	* 参数：void
	* 输出：void
	* 功能：
		制作所有登录页面，包括页面间的跳转逻辑
	*/
	void loginviewprint();
};


