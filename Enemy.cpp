#include "Enemy.h"
#include <Windows.h>

/*
	move函数的实现
*/
void Enemy::move(int speed)
{
	this->y += speed;
}

/*
	ishit函数的实现
*/
void Enemy::ishit(vector<bullet>& bullets)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		//如果子弹属性为玩家，则判断是否击中
		
			//子弹左边x坐标
			int x1 = bullets[i].get_x();

			//子弹顶部y坐标
			int y1 = bullets[i].get_y();

			//子弹右边x坐标
			int x2 = bullets[i].get_x() + bullets[i].get_width();

			//子弹底部y坐标
			int y2 = bullets[i].get_y() + bullets[i].get_height();

			//DiFang左边x坐标
			int DiFang_x1 = this->x;

			//DiFang顶部x坐标
			int DiFang_y1 = this->y;

			//DiFang右边x坐标
			int DiFang_x2 = this->x + this->width;

			//DiFang底部y坐标
			int DiFang_y2 = this->y + this->height;
			if (bullets[i].get_mode() == TRUE)
			{
				//DiFang左上角与子弹重叠
				if (x2 > DiFang_x1 && x2<DiFang_x2 && y2>DiFang_y1 && y2 < DiFang_y2)
				{
					this->hp -= 10;
					bullets[i].alive = FALSE;
				}
				//DiFang右上角与子弹重叠
				else if (x1 > DiFang_x1 && x1<DiFang_x2 && y2>DiFang_y1 && y2 < DiFang_y2)
				{
					this->hp -= 10;
					bullets[i].alive = FALSE;
				}
				//DiFang左下角与子弹重叠
				else if (x2 > DiFang_x1 && x2<DiFang_x2 && y1>DiFang_y1 && y1 < DiFang_y2)
				{
					this->hp -= 10;
					bullets[i].alive = FALSE;
				}
				//DiFang右下角与子弹重叠
				else if (x1 > DiFang_x1 && x1<DiFang_x2 && y1>DiFang_y1 && y1 < DiFang_y2)
				{
					this->hp -= 10;
					bullets[i].alive = FALSE;
				}
				//子弹高度大于DiFang且DiFang左侧与子弹重叠
				else if (x2 > DiFang_x1 && x2 < DiFang_x2 && y1<DiFang_y1 && y2>DiFang_y2)
				{
					this->hp -= 10;
					bullets[i].alive = FALSE;
				}
				//子弹高度大于DiFang且DiFang右侧与子弹重叠
				else if (x1 > DiFang_x1 && x1 < DiFang_x2 && y1<DiFang_y1 && y2>DiFang_y2)
				{
					this->hp -= 10;
					bullets[i].alive = FALSE;
				}
			}
			else
			{
				if (x2 > DiFang_x1 && x2<DiFang_x2 && y2>DiFang_y1 && y2 < DiFang_y2)
				{
					bullets[i].alive = FALSE;
				}
				//DiFang右上角与子弹重叠
				else if (x1 > DiFang_x1 && x1<DiFang_x2 && y2>DiFang_y1 && y2 < DiFang_y2)
				{
					bullets[i].alive = FALSE;
				}
				//DiFang左下角与子弹重叠
				else if (x2 > DiFang_x1 && x2<DiFang_x2 && y1>DiFang_y1 && y1 < DiFang_y2)
				{
					bullets[i].alive = FALSE;
				}
				//DiFang右下角与子弹重叠
				else if (x1 > DiFang_x1 && x1<DiFang_x2 && y1>DiFang_y1 && y1 < DiFang_y2)
				{
					bullets[i].alive = FALSE;
				}
				//子弹高度大于DiFang且DiFang左侧与子弹重叠
				else if (x2 > DiFang_x1 && x2 < DiFang_x2 && y1<DiFang_y1 && y2>DiFang_y2)
				{
					bullets[i].alive = FALSE;
				}
				//子弹高度大于DiFang且DiFang右侧与子弹重叠
				else if (x1 > DiFang_x1 && x1 < DiFang_x2 && y1<DiFang_y1 && y2>DiFang_y2)
				{
					bullets[i].alive = FALSE;
				}
			}
			if (this->hp <= 0)
			{
				this->alive = FALSE;
				return;
			}
	}
}