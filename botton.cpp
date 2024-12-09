#include "botton.h"


bool botton::isarea(ExMessage msg)
{
    if (msg.lbutton) {
        int mouseX = msg.x, mouseY = msg.y;
        if (mouseX >= x && mouseX <= x + width && mouseY >= y && mouseY <= y + height)
        {
            isactive = true;
            return true;
        }
    }
    isactive = false;
    return false;
}


void botton::printBotton()
{
    setlinecolor(RGB(173, 173, 173)); // 按钮边框颜色
    setfillcolor(RGB(225, 225, 225)); // 按钮填充颜色
    fillrectangle(x, y, x + width, y + height); // 绘制按钮
    settextcolor(BLACK); // 设置文本颜色为黑色
    setbkmode(TRANSPARENT); // 设置文本背景透明
    settextstyle(20, 0, "微软雅黑"); // 设置文本大小和字体
    //居中显示按钮文本
    int textX = x + (width - textwidth(text.c_str())) / 2; // 计算文本在按钮中央的x坐标
    int textY = y + (height - textheight("微软雅黑")) / 2; // 计算文本在按钮中央的y坐标
    outtextxy(textX, textY, text.c_str()); // 在按钮上绘制文本

}