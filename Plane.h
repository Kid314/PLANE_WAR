#pragma once
#include<vector>
#include<easyx.h>
#include "bullet.h"
#include "view.h"
using namespace std;
class Plane
{
private:
	//�ɻ�ͼƬ�ĵ����Ͻ�����
	int x, y;

	//�ɻ��ĳ��Ϳ�
	int width, height;

	//��ʣ��Ѫ��
	int hp;

	//�ɻ����ƶ��ٶ�
	int  speed;

	//�ж��Ƿ���
	bool alive;
public:

	/*
	*	�ƶ�ģ��   void move(int);
		����ˣ�����
		
			��Ҫ���ݼ���������������ҷɻ������꣺

			���ռ�������
			-���ݷɻ����ٶ����޸ķɻ���x��yֵ

		������int
		�����void

	*/
	void move(int speed);

	/*
		�ж��Ƿ񱻻���ģ��   void ishit()

		����ˣ�����

		���ж�ÿ���ӵ��ӵ����������ķ�������
		�ٸ����ӵ�������ͳ���
		�Լ��ɻ�������ͳ���
		�ж��Ƿ񱻻���
		����Ӧ��Ѫ���Լ��ı�  �ӵ��ͷɻ�  ��alive

		���� vector<bullet>& bullets
		���� void

	*/
	void ishit(vector<bullet>& bullets);


	Plane(int x_, int y_, int width_, int height_, int speed_, int hp_, bool alive_) :
		x(x_), y(y_), width(width_), height(height_), speed(speed_), hp(hp_), alive(alive_) {}


	//Ҫ�õ������ݽӿ�
	int get_x() const { return x; }
	int get_y() const { return y; }
	int get_width() const { return width; }
	int get_height() const { return height; }
	int get_hp() const { return hp; }
	int get_speed() const { return speed; }
	bool get_alive() const { return alive; }
};

