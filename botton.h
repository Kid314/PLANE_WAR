#pragma once
#include<easyx.h>
#include<string>
class botton
{
private:
	int x, y;
	int width, height;
	std::string text;
	bool isactive;
public:
	/*
	* * ����ˣ�����
		* ������ExMessage msg
		* �����void
		* ���ܣ�
		�ж��Ƿ񴥷���ť
		����botton��  x,y,width, height  �Լ�msg��x��y
		false����δ����
		true������
		���޸�botton��isactiveֵ
	*/
	bool isarea(ExMessage msg);

	/*
	* ����ˣ�����
	* ������void
	* �����void
	* ���ܣ�
		���ݰ�ť���������ڴ����л���
	*/
	void printBotton();

	botton(int x_,int y_,int width_,int height_,std::string text_):x(x_),y(y_),width(width_),height(height_),text(text_), isactive(false) {}

	//���ݽӿ�
	int get_x() const { return x; }
	int get_y() const { return y; }
	int get_width() const { return width; }
	int get_height() const { return height; }
	std::string get_text() const { return text; }
	bool get_isactive() const { return isactive; }
};

