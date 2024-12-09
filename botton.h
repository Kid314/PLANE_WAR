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
	* * 完成人：张三
		* 参数：ExMessage msg
		* 输出：void
		* 功能：
		判断是否触发按钮
		依据botton的  x,y,width, height  以及msg的x和y
		false代表未触发
		true代表触发
		并修改botton的isactive值
	*/
	bool isarea(ExMessage msg);

	/*
	* 完成人：张三
	* 参数：void
	* 输出：void
	* 功能：
		根据按钮自身属性在窗口中绘制
	*/
	void printBotton();

	botton(int x_,int y_,int width_,int height_,std::string text_):x(x_),y(y_),width(width_),height(height_),text(text_), isactive(false) {}

	//数据接口
	int get_x() const { return x; }
	int get_y() const { return y; }
	int get_width() const { return width; }
	int get_height() const { return height; }
	std::string get_text() const { return text; }
	bool get_isactive() const { return isactive; }
};

