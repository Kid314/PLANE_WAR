#pragma once
#include "view.h"
class bullet
{
private:
	//�ӵ�ͼƬ�ĵ����Ͻ�����
	int x, y;

	//�ӵ��ĳ��Ϳ�
	int width, height;

	//�ӵ����ٶ�
	int speed;

	//�ӵ����ķ�������
	//tureΪ���
	//falseΪ����
	bool mode;

	//�ӵ���ɵ��˺�
	int hp;

public:

	//�ж��ӵ��Ƿ���Ҫ����
	bool alive;

	/*
	* * ����ˣ�����
		* ������int
		* �����void
		* ���ܣ�
			�ӵ��ƶ���

			�ӵ�����������ӵ��ٶȸı䣻
	
	*/
	void move(int speed);

	bullet(int x_,int y_,int width_,int height_,int speed_,bool mode_,int hp_,bool alive_): 
		x(x_),y(y_),width(width_), height(height_), speed(speed_),mode(mode_),hp(hp_),alive(alive_){ }

	//Ҫ�õ������ݽӿ�
	int get_x() const { return x; }
	int get_y() const { return y; }
	int get_width() const { return width; }
	int get_height() const { return height; }
	int get_hp() const { return hp; }
	int get_speed() const { return speed; }
	bool get_alive() const { return alive; }
	bool get_mode() const { return mode; }
};

