#pragma once
#include<vector>
#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>
#include "botton.h"
#include<map>
//���ڿ�Ⱥ͸߶��Լ�����
#include "view.h"
using namespace std;
//-----------------------------��¼ҳ��----------------------------
//��Ž��水ť
//ÿ��ҳ�涼���Լ���vector<botton>
extern vector<vector<botton>> login_bottons;

extern map<string, string>accounts;

//��ű���ͼƬ
extern vector<IMAGE> img_login_background;

class loginview
{
public:
	vector<vector<botton>> login_bottons;

	map<string, string>accounts;

	//��ű���ͼƬ
	vector<IMAGE> img_login_background;
	ExMessage msg = {0};
	string input_account;
	string input_password;
	char ch;
	fstream fpr;

	loginview():ch('\0')
	{
		fpr.open("account.txt", ios::out);
	}

	~loginview()
	{
		fpr.close();
	}

	/*
	* * ����ˣ�����
	* ������void
	* �����void
	* ���ܣ�
		����ͼƬ
		ʹ��loadimage������������Ҫ��ͼƬ���ص����ԵĴ�Ŵ�
		botton����ѡ��Ӳ���ͼƬ������ν
		-img_login_background
		-img_login_bottons(�Ǳ�Ҫ��
	*/
	void login_loadimg();

	/*
	* ����ˣ�����
	* ������const botton& my_botton
	* �����void
	* ���ܣ�
		������ť
		�����°�ť���뵽���Ե�botton�������з������
	*/
	void addNewBotton(const botton& my_botton);

	/*
	* ����ˣ�����
	* ������void
	* �����void
	* ���ܣ�
	*			��ȡ�û����벢���뵽input_account��input_password��
	*/
	void receive();

	/*
	* ����ˣ�����
	* ������fstream& fpr
	* �����bool
	* ���ܣ�
	*			�ж��Ƿ�����ļ��е��˺�����
	*			�������˺Ŵ�������������
	*			���߲����ڴ��˺�
	*/
	bool isaccount(fstream& fpr);

	/*
	* * ����ˣ�����
	* ������void
	* �����void
	* ���ܣ�
		�������е�¼ҳ�棬����ҳ������ת�߼�
	*/
	void loginviewprint();
};


