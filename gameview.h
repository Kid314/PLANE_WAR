#pragma once
#include<time.h>
#include<conio.h>
#include "Plane.h"
#include "Enemy.h"
#include "botton.h"
//���ڿ�Ⱥ͸߶��Լ�����
#include "view.h"
using namespace std;


//������
extern vector<Plane> players;

//������ел�
extern vector<Enemy> enemys;

//��������ӵ�
extern vector<bullet> bullets;

//���ҳ��İ�ť
extern vector<botton> game_bottons;

//�����Ϸ����ͼƬ
extern vector<IMAGE> img_game_background;

//������ͼƬ
extern vector<IMAGE> img_plane;

//��ŵ���ͼƬ
extern vector<IMAGE> img_enemy;

//����ӵ�ͼƬ
extern vector<IMAGE> img_bullet;

//---------------��Ϸ����----------------------------------------
class gameview
{
public:
	/*
	*  * ����ˣ�kid
		* ������void
		* �����void
		* ���ܣ�
		����ͼƬ
		ʹ��loadimage����������ͼƬ���ص����ԵĴ�Ŵ�
		-img_game_background
		-img_plane
		-img_enemy
		-img_bullet
	*/
	void game_loadimg();

	/*
	* ����ˣ�kid
	* ������const botton& my_botton
	* �����void
	* ���ܣ�
		������ť
		�����°�ť���뵽���Ե�botton�������з������
	*/
	void addNewBotton(const botton& my_botton);

	/*
	*  * ����ˣ�kid
		* ������void
		* �����void
		* ���ܣ�
		��ʼ����������:
		������ҷɻ��Ĵ���
		Ĭ��һ��ʼ�����л�����
	*/
	void init_gamedata();

	/*
	*  * ����ˣ�kid
		* ������int ms, int id
		* �����void
		* ���ܣ�
		������ʱ�������Զ������������ɵл�
		ms����ÿ����������һ���л�
	*/
	bool Timer(int ms, int id);

	/*
	*  * ����ˣ�kid
		* ������void
		* �����void
		* ���ܣ�
		�������ӵ�   ����ʵ����һ���ӵ���

		����Ҫ���л�����

		���ø���Ҵ���

		��ӵ�bullets��
	*/
	void createbullet();

	/*
	*  * ����ˣ�kid
		* ������void
		* �����void
		* ���ܣ�
		�����л�
		��ӵ�enemys��
	*/
	void createnemy(int count);

	/*
	*  * ����ˣ�kid
		* ������void
		* �����void
		* ���ܣ�
		������Ϸ����

		ͨ��putimage�������

		�ӵ��͵���ֻ��aliveΪ��Ż���

		��aliveΪ�ٵĽ���pop����
		�����л��ֵĸ��ģ�ȫ�ֱ���score)

		ͨ��putimage�������ӵ��͵��˻���

	*/
	void gameviewprint();

	/*
	* * ����ˣ�kid
	* ������void
	* �����void
	* ���ܣ�
	*	��������(������ͼƬ)���ҳ�ʼ��
	* Ĭ��һ��ʼ�����л�����
	*/
	void cleandata();

	/*
	*  * ����ˣ�kid
	* ������Plane& palyer
	* �����bool
	* ���ܣ�
	*	����Ѫ���ж��Ƿ�ɹ�ͨ��
	* 
	* ���ɹ��򷵻�1
	* �����ɹ��򷵻�2��
	* �������򷵻�0������Ϸ
	*/
	int iswin(Plane& palyer);
};

