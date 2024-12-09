#include "Plane.h"
#include<Windows.h>
using namespace std;

/*
	move函数的实现
*/
void Plane::move(int speed)
{
#if 1
	if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W'))
	{
		if (this->y > 0)//边界处理//注意！！！一切的x，y都是图片的左上角的来
		{
			//能移动
			this->y -= speed;
		}

	}
	if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S'))
	{
		if (this->y  < HEIGHT-this->height)
		{
			this->y += speed;
		}
	}
	if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A'))
	{
		if (this->x > 0)
		{
			this->x -= speed;
		}
	}
	if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D'))
	{
		if (this->x < WIDTH-this->width)
		{
			this->x += speed;
		}
	}
#elif 0 // DEBUG

	ExMessage yingjue_msg;
	int yingjue_vx = 0;
	int yingjue_vy = 0;
	peekmessage(&yingjue_msg, EX_KEY);
	if (yingjue_msg.message == WM_KEYDOWN)
	{
		switch (yingjue_msg.vkcode)
		{
		case 'W':
		case VK_UP:
			yingjue_vy = -1;
			break;
		case 'A':
		case VK_LEFT:
			yingjue_vx = -1;
			break;
		case 'S':
		case VK_DOWN:
			yingjue_vy = 1;
			break;
		case 'D':
		case VK_RIGHT:
			yingjue_vx = 1;
			break;
		}
	}
	else if (yingjue_msg.message == WM_KEYUP)
	{
		switch (yingjue_msg.vkcode)
		{
		case 'W':
		case VK_UP:
			yingjue_vy = 0;
			break;
		case 'A':
		case VK_LEFT:
			yingjue_vx = 0;
			break;
		case 'S':
		case VK_DOWN:
			yingjue_vy = 0;
			break;
		case 'D':
		case VK_RIGHT:
			yingjue_vx = 0;
			break;
		}
	}
	this->x += speed * yingjue_vx;
	this->y += speed * yingjue_vy;
#endif

}

/*
	ishit函数的实现
*/
void Plane::ishit(vector<bullet>& bullets)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		//如果子弹属性为敌方，则判断是否击中
		if (bullets[i].get_mode() == false)
		{
			//子弹左边x坐标
			int x1 = bullets[i].get_x();

			//子弹顶部y坐标
			int y1 = bullets[i].get_y();

			//子弹右边x坐标
			int x2 = bullets[i].get_x() + bullets[i].get_width();

			//子弹底部y坐标
			int y2 = bullets[i].get_y() + bullets[i].get_height();

			//飞机左边x坐标
			int plane_x1 = this->x;

			//飞机顶部x坐标
			int plane_y1 = this->y;

			//飞机右边x坐标
			int plane_x2 = this->x + this->width;

			//飞机底部y坐标
			int plane_y2 = this->y + this->height;

			//飞机左上角与子弹重叠
			if (x2 > plane_x1 && x2<plane_x2 && y2>plane_y1 && y2 < plane_y2)
			{
				this->hp -= 10;
				bullets[i].alive = FALSE;
			}
			//飞机右上角与子弹重叠
			else if (x1 > plane_x1 && x1<plane_x2 && y2>plane_y1 && y2 < plane_y2)
			{
				this->hp -= 10;
				bullets[i].alive = FALSE;
			}
			//飞机左下角与子弹重叠
			else if (x2 > plane_x1 && x2<plane_x2 && y1>plane_y1 && y1 < plane_y2)
			{
				this->hp -= 10;
				bullets[i].alive = FALSE;
			}
			//飞机右下角与子弹重叠
			else if (x1 > plane_x1 && x1<plane_x2 && y1>plane_y1 && y1 < plane_y2)
			{
				this->hp -= 10;
				bullets[i].alive = FALSE;
			}
			//子弹高度大于飞机且飞机左侧与子弹重叠
			else if (x2 > plane_x1 && x2 < plane_x2 && y1<plane_y1 && y2>plane_y2)
			{
				this->hp -= 10;
				bullets[i].alive = FALSE;
			}
			//子弹高度大于飞机且飞机右侧与子弹重叠
			else if (x1 > plane_x1 && x1 < plane_x2 && y1<plane_y1 && y2>plane_y2)
			{
				this->hp -= 10;
				bullets[i].alive = FALSE;
			}

			if (this->hp <= 0)
			{
				this->alive = false;
				return;
			}
		}

	}
}
