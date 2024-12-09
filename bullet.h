#pragma once
#include "view.h"
class bullet
{
private:
	//子弹图片的的左上角坐标
	int x, y;

	//子弹的长和宽
	int width, height;

	//子弹的速度
	int speed;

	//子弹是哪方发出的
	//ture为玩家
	//false为敌人
	bool mode;

	//子弹造成的伤害
	int hp;

public:

	//判断子弹是否还需要绘制
	bool alive;

	/*
	* * 完成人：张三
		* 参数：int
		* 输出：void
		* 功能：
			子弹移动：

			子弹的坐标根据子弹速度改变；
	
	*/
	void move(int speed);

	bullet(int x_,int y_,int width_,int height_,int speed_,bool mode_,int hp_,bool alive_): 
		x(x_),y(y_),width(width_), height(height_), speed(speed_),mode(mode_),hp(hp_),alive(alive_){ }

	//要用到的数据接口
	int get_x() const { return x; }
	int get_y() const { return y; }
	int get_width() const { return width; }
	int get_height() const { return height; }
	int get_hp() const { return hp; }
	int get_speed() const { return speed; }
	bool get_alive() const { return alive; }
	bool get_mode() const { return mode; }
};

