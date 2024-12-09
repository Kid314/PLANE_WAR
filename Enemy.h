#pragma once
#include "view.h"
#include<vector>
#include "bullet.h"
using namespace std;
class Enemy
{
private:
	//敌机图片的的左上角坐标
	int x, y;

	//敌机的长和宽
	int width, height;

	//所剩的血量
	int hp;

	//敌机的移动速度
	int  speed;

	//判断是否存活
	bool alive;

public:

	/*
	*	移动模块   void move(int);
		完成人：张三
		根据速度修改x，y值
		参数：int
		输出：void

	*/
	void move(int speed);

	/*
		判断是否被击中模块   void ishit()

		完成人：张三

		先判断每个子弹子弹的属性是哪方发出的
		再根据子弹的坐标和长宽，
		以及飞机的坐标和长宽
		判断是否被击中
		并相应扣血，以及改变  子弹和飞机  的alive

		参数 vector<bullet>& bullets
		返回 void

	*/
	void ishit(vector<bullet>& bullets);


	Enemy(int x_, int y_, int width_, int height_, int speed_, int hp_, bool alive_) :
		x(x_), y(y_), width(width_), height(height_), speed(speed_), hp(hp_), alive(alive_) {}

	//要用到的数据接口
	int get_x() const { return x; }
	int get_y() const { return y; }
	int get_width() const { return width; }
	int get_height() const { return height; }
	int get_hp() const { return hp; }
	int get_speed() const { return speed; }
	bool get_alive() const { return alive; }

};

