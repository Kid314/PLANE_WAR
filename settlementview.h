#pragma once
#include "Plane.h"
#include "botton.h"
//���ڿ�Ⱥ͸߶��Լ�����
#include "view.h"
#include<sstream>
using namespace std;
//------------------------------------��ͣҳ��---------------------
extern vector<botton> settlement_bottons;
//��ű���ͼƬ
extern vector<IMAGE> img_settlement_background;

class settlementview
{
public:
	int my_score;
	/*
	* * ����ˣ�����
	* ������void
	* �����void
	* ���ܣ�
	*			�������������easyx�Դ��������ͨ�ؽ���
	*			��ӵ����ҳ���������ȥ
	*/
	void winview();

	/*
	* * ����ˣ�����
	* ������void
	* �����void
	* ���ܣ�
	*			�������������easyx�Դ��������ʧ�ܽ���
	*			��ӵ����ҳ���������ȥ
	*/
	void loseview();

	settlementview(int score):my_score(score){}
};

