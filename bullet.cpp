#include "bullet.h"

/*
	move������ʵ��
*/
void bullet::move(int speed)
{
	//�������ҵ��ӵ����ӵ�������
	if (mode)
	{
		//����ӵ�ͼƬ�ײ������ϱ߽磬���˳�������
		if (this->get_y() + this->get_height() <= 0)
		{
			this->alive = false;
			return;
		}
		//�ӵ������ߣ�ͼƬ���Ͻ�y���꣬��С3��
		this->y -= speed;
	}
	else//����ǵ��˵��ӵ����ӵ�������
	{
		//this->get_y() + this->get_height() >= GAME_WINDOW_HEIGHT
		if (this->get_y() + this->get_height() >= HEIGHT)//�߿��420
		{
			this->alive = false;
			return;
		}
		//����ӵ�δ�����߿��ӵ������ƶ�
		this->y += speed;
	}
}