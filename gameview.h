#pragma once
#include<time.h>
#include<conio.h>
#include "Plane.h"
#include "Enemy.h"
#include "botton.h"
//窗口宽度和高度以及积分
#include "view.h"
using namespace std;


//存放玩家
extern vector<Plane> players;

//存放所有敌机
extern vector<Enemy> enemys;

//存放所有子弹
extern vector<bullet> bullets;

//存放页面的按钮
extern vector<botton> game_bottons;

//存放游戏背景图片
extern vector<IMAGE> img_game_background;

//存放玩家图片
extern vector<IMAGE> img_plane;

//存放敌人图片
extern vector<IMAGE> img_enemy;

//存放子弹图片
extern vector<IMAGE> img_bullet;

//---------------游戏界面----------------------------------------
class gameview
{
public:
	/*
	*  * 完成人：kid
		* 参数：void
		* 输出：void
		* 功能：
		加载图片
		使用loadimage函数将所有图片加载到各自的存放处
		-img_game_background
		-img_plane
		-img_enemy
		-img_bullet
	*/
	void game_loadimg();

	/*
	* 完成人：kid
	* 参数：const botton& my_botton
	* 输出：void
	* 功能：
		创建按钮
		并将新按钮加入到各自的botton的数组中方便调用
	*/
	void addNewBotton(const botton& my_botton);

	/*
	*  * 完成人：kid
		* 参数：void
		* 输出：void
		* 功能：
		初始化所有数据:
		包括玩家飞机的创建
		默认一开始三个敌机好了
	*/
	void init_gamedata();

	/*
	*  * 完成人：kid
		* 参数：int ms, int id
		* 输出：void
		* 功能：
		创建定时器用于自动攻击或者生成敌机
		ms代表每隔几秒生成一个敌机
	*/
	bool Timer(int ms, int id);

	/*
	*  * 完成人：kid
		* 参数：void
		* 输出：void
		* 功能：
		创建新子弹   即新实例化一个子弹类

		不仅要给敌机创建

		还得给玩家创建

		添加到bullets中
	*/
	void createbullet();

	/*
	*  * 完成人：kid
		* 参数：void
		* 输出：void
		* 功能：
		创建敌机
		添加到enemys中
	*/
	void createnemy(int count);

	/*
	*  * 完成人：kid
		* 参数：void
		* 输出：void
		* 功能：
		绘制游戏画面

		通过putimage绘制玩家

		子弹和敌人只有alive为真才绘制

		把alive为假的进行pop操作
		并进行积分的更改（全局变量score)

		通过putimage函数把子弹和敌人绘制

	*/
	void gameviewprint();

	/*
	* * 完成人：kid
	* 参数：void
	* 输出：void
	* 功能：
	*	数据清理(不清理图片)并且初始化
	* 默认一开始三个敌机好了
	*/
	void cleandata();

	/*
	*  * 完成人：kid
	* 参数：Plane& palyer
	* 输出：bool
	* 功能：
	*	根据血量判断是否成功通关
	* 
	* 若成功则返回1
	* 若不成功则返回2；
	* 都不是则返回0继续游戏
	*/
	int iswin(Plane& palyer);
};

