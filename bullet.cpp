#include "bullet.h"

/*
	move函数的实现
*/
void bullet::move(int speed)
{
	//如果是玩家的子弹，子弹向上走
	if (mode)
	{
		//如果子弹图片底部超过上边界，则退出函数。
		if (this->get_y() + this->get_height() <= 0)
		{
			this->alive = false;
			return;
		}
		//子弹向上走，图片左上角y坐标，减小3。
		this->y -= speed;
	}
	else//如果是敌人的子弹，子弹向下走
	{
		//this->get_y() + this->get_height() >= GAME_WINDOW_HEIGHT
		if (this->get_y() + this->get_height() >= HEIGHT)//边框高420
		{
			this->alive = false;
			return;
		}
		//如果子弹未超出边框，子弹向下移动
		this->y += speed;
	}
}