#include "Plane.h"
#include<Windows.h>
using namespace std;

/*
	move������ʵ��
*/
void Plane::move(int speed)
{
#if 1
	if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W'))
	{
		if (this->y > 0)//�߽紦��//ע�⣡����һ�е�x��y����ͼƬ�����Ͻǵ���
		{
			//���ƶ�
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
	ishit������ʵ��
*/
void Plane::ishit(vector<bullet>& bullets)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		//����ӵ�����Ϊ�з������ж��Ƿ����
		if (bullets[i].get_mode() == false)
		{
			//�ӵ����x����
			int x1 = bullets[i].get_x();

			//�ӵ�����y����
			int y1 = bullets[i].get_y();

			//�ӵ��ұ�x����
			int x2 = bullets[i].get_x() + bullets[i].get_width();

			//�ӵ��ײ�y����
			int y2 = bullets[i].get_y() + bullets[i].get_height();

			//�ɻ����x����
			int plane_x1 = this->x;

			//�ɻ�����x����
			int plane_y1 = this->y;

			//�ɻ��ұ�x����
			int plane_x2 = this->x + this->width;

			//�ɻ��ײ�y����
			int plane_y2 = this->y + this->height;

			//�ɻ����Ͻ����ӵ��ص�
			if (x2 > plane_x1 && x2<plane_x2 && y2>plane_y1 && y2 < plane_y2)
			{
				this->hp -= 10;
				bullets[i].alive = FALSE;
			}
			//�ɻ����Ͻ����ӵ��ص�
			else if (x1 > plane_x1 && x1<plane_x2 && y2>plane_y1 && y2 < plane_y2)
			{
				this->hp -= 10;
				bullets[i].alive = FALSE;
			}
			//�ɻ����½����ӵ��ص�
			else if (x2 > plane_x1 && x2<plane_x2 && y1>plane_y1 && y1 < plane_y2)
			{
				this->hp -= 10;
				bullets[i].alive = FALSE;
			}
			//�ɻ����½����ӵ��ص�
			else if (x1 > plane_x1 && x1<plane_x2 && y1>plane_y1 && y1 < plane_y2)
			{
				this->hp -= 10;
				bullets[i].alive = FALSE;
			}
			//�ӵ��߶ȴ��ڷɻ��ҷɻ�������ӵ��ص�
			else if (x2 > plane_x1 && x2 < plane_x2 && y1<plane_y1 && y2>plane_y2)
			{
				this->hp -= 10;
				bullets[i].alive = FALSE;
			}
			//�ӵ��߶ȴ��ڷɻ��ҷɻ��Ҳ����ӵ��ص�
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
