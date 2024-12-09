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
    setlinecolor(RGB(173, 173, 173)); // ��ť�߿���ɫ
    setfillcolor(RGB(225, 225, 225)); // ��ť�����ɫ
    fillrectangle(x, y, x + width, y + height); // ���ư�ť
    settextcolor(BLACK); // �����ı���ɫΪ��ɫ
    setbkmode(TRANSPARENT); // �����ı�����͸��
    settextstyle(20, 0, "΢���ź�"); // �����ı���С������
    //������ʾ��ť�ı�
    int textX = x + (width - textwidth(text.c_str())) / 2; // �����ı��ڰ�ť�����x����
    int textY = y + (height - textheight("΢���ź�")) / 2; // �����ı��ڰ�ť�����y����
    outtextxy(textX, textY, text.c_str()); // �ڰ�ť�ϻ����ı�

}