#include "Enemy.h"
#include <Windows.h>

/*
	move������ʵ��
*/
void Enemy::move(int speed)
{
	this->y += speed;
}

/*
	ishit������ʵ��
*/
void Enemy::ishit(vector<bullet>& bullets)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		//����ӵ�����Ϊ��ң����ж��Ƿ����
		
			//�ӵ����x����
			int x1 = bullets[i].get_x();

			//�ӵ�����y����
			int y1 = bullets[i].get_y();

			//�ӵ��ұ�x����
			int x2 = bullets[i].get_x() + bullets[i].get_width();

			//�ӵ��ײ�y����
			int y2 = bullets[i].get_y() + bullets[i].get_height();

			//DiFang���x����
			int DiFang_x1 = this->x;

			//DiFang����x����
			int DiFang_y1 = this->y;

			//DiFang�ұ�x����
			int DiFang_x2 = this->x + this->width;

			//DiFang�ײ�y����
			int DiFang_y2 = this->y + this->height;
			if (bullets[i].get_mode() == TRUE)
			{
				//DiFang���Ͻ����ӵ��ص�
				if (x2 > DiFang_x1 && x2<DiFang_x2 && y2>DiFang_y1 && y2 < DiFang_y2)
				{
					this->hp -= 10;
					bullets[i].alive = FALSE;
				}
				//DiFang���Ͻ����ӵ��ص�
				else if (x1 > DiFang_x1 && x1<DiFang_x2 && y2>DiFang_y1 && y2 < DiFang_y2)
				{
					this->hp -= 10;
					bullets[i].alive = FALSE;
				}
				//DiFang���½����ӵ��ص�
				else if (x2 > DiFang_x1 && x2<DiFang_x2 && y1>DiFang_y1 && y1 < DiFang_y2)
				{
					this->hp -= 10;
					bullets[i].alive = FALSE;
				}
				//DiFang���½����ӵ��ص�
				else if (x1 > DiFang_x1 && x1<DiFang_x2 && y1>DiFang_y1 && y1 < DiFang_y2)
				{
					this->hp -= 10;
					bullets[i].alive = FALSE;
				}
				//�ӵ��߶ȴ���DiFang��DiFang������ӵ��ص�
				else if (x2 > DiFang_x1 && x2 < DiFang_x2 && y1<DiFang_y1 && y2>DiFang_y2)
				{
					this->hp -= 10;
					bullets[i].alive = FALSE;
				}
				//�ӵ��߶ȴ���DiFang��DiFang�Ҳ����ӵ��ص�
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
				//DiFang���Ͻ����ӵ��ص�
				else if (x1 > DiFang_x1 && x1<DiFang_x2 && y2>DiFang_y1 && y2 < DiFang_y2)
				{
					bullets[i].alive = FALSE;
				}
				//DiFang���½����ӵ��ص�
				else if (x2 > DiFang_x1 && x2<DiFang_x2 && y1>DiFang_y1 && y1 < DiFang_y2)
				{
					bullets[i].alive = FALSE;
				}
				//DiFang���½����ӵ��ص�
				else if (x1 > DiFang_x1 && x1<DiFang_x2 && y1>DiFang_y1 && y1 < DiFang_y2)
				{
					bullets[i].alive = FALSE;
				}
				//�ӵ��߶ȴ���DiFang��DiFang������ӵ��ص�
				else if (x2 > DiFang_x1 && x2 < DiFang_x2 && y1<DiFang_y1 && y2>DiFang_y2)
				{
					bullets[i].alive = FALSE;
				}
				//�ӵ��߶ȴ���DiFang��DiFang�Ҳ����ӵ��ص�
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