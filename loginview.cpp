#include "loginview.h"
#include<algorithm>
// ������������
#ifndef CONSTANTS_H
#define CONSTANTS_H

// ��ťĬ�Ͽ�Ⱥ͸߶�
#define BUTTON_WIDTH (WIDTH / 2) // ʹ�� WIDTH ���㰴ť���
#define BUTTON_HEIGHT 40

// ����ͼƬ��Ⱥ͸߶�
#define BACKGROUND_WIDTH WIDTH
#define BACKGROUND_HEIGHT HEIGHT

#endif // CONSTANTS_H
void loginview::loginviewprint()
{
    for (auto d : accounts) {
        cout << d.first << d.second;
    }
    int flag_fx = 0, flag1_fx = 0, flag2_fx = 0;

    login_loadimg();
    initgraph(WIDTH, HEIGHT);
    cleardevice();
    BeginBatchDraw();
    putimage(0, 0, &img_login_background[0]);
    settextcolor(WHITE);
    setbkmode(TRANSPARENT); // �����ı�����͸��
    settextstyle(30, 25, "����");
    outtextxy(200, 300, flag1_fx == 0 ? "�˺�" : "���˺�");
    outtextxy(200, 350, "����");
    settextcolor(BLACK);
    outtextxy(89, 25, input_account.c_str());
    outtextxy(89, 55, input_password.c_str());
    BeginBatchDraw();
    if (!login_bottons.empty() && login_bottons[0].size() > 0) {
        for (int i = 0; i < login_bottons[0].size(); i++) {
            login_bottons[0][i].printBotton();
            cout << i << " " << login_bottons[0][i].get_text();
        }
    }
    FlushBatchDraw();
    while (1) {
        cleardevice();
        BeginBatchDraw();

        putimage(0, 0, &img_login_background[0]);

        if (!login_bottons.empty() && flag1_fx < login_bottons.size()) {
            for (int i = 0; i < login_bottons[flag1_fx].size(); i++) {
                login_bottons[flag1_fx][i].printBotton();
            }
        }
        settextcolor(WHITE);
        settextstyle(25, 20, "����");
        outtextxy(flag1_fx == 0 ? 200 : 170, 300, flag1_fx == 0 || flag1_fx == 3 ? "�˺�" : "���˺�");
        outtextxy(200, 350, "����");
        settextcolor(BLACK);
        settextstyle(20, 15, "����");
        outtextxy(300, 305, input_account.c_str());
        outtextxy(300, 355, input_password.c_str());
        FlushBatchDraw();
        while (1) {
            if (_kbhit() || (peekmessage(&msg) && msg.message == WM_LBUTTONDOWN))break;
        }if (1) {
            if (flag1_fx == 0) {

                int k = -1; // ��ʼֵ���жϼ�λ��������
                if (!login_bottons.empty() && login_bottons[0].size() > 0) {
                    for (int i = 0; i < login_bottons[0].size(); i++) {
                        if (login_bottons[0][i].isarea(msg)) {
                            k = i;

                            break;
                        }
                    }
                    if (k == -1 && msg.message == WM_LBUTTONDOWN)continue;
                }
                FlushBatchDraw();
                if (k == 0) {
                cc:
                    cout << 1222;
                    if (!input_account.empty() && input_account.back() == '|') input_account.pop_back();
                    if (!input_password.empty() && input_password.back() == '|') input_password.pop_back();

                    if (isaccount(fpr)) {
                        break;
                    }
                    else {
                        string linshi = "�˺Ż��������";
                        settextcolor(WHITE);
                        outtextxy((WIDTH / 2 - 15 * linshi.size() / 2), 200, linshi.c_str());
                        FlushBatchDraw();
                        Sleep(1000);

                    }
                    /* input_account.clear();
                     input_password.clear();*/
                    flag_fx = 0;
                    continue;
                }
                if (k == 2) {
                    flag1_fx = 1;
                    flag_fx = 0;
                    input_account.clear();
                    input_password.clear();
                }
                // ����������
                if (k == 3) {
                    if (!input_account.empty() && input_account.back() == '|') {
                        input_account.pop_back();
                    }
                    else if (!input_password.empty() && !flag_fx == 0) {
                        input_password.pop_back();
                    }
                    input_account.push_back('|');
                    flag_fx = 1;
                }
                if (k == 4) {
                bb:
                    cout << 100;
                    if (!input_password.empty() && input_password.back() == '|') {
                        input_password.pop_back();
                    }
                    else if (!input_account.empty() && !flag_fx == 0) {
                        input_account.pop_back();
                    }
                    input_password.push_back('|');
                    flag_fx = 2;
                    continue;
                }

                if (k == -1) {
                    unsigned char key = _getch();

                    if (key == 0 || key == 0xE0) { // ǰ���ֽ�Ϊ0��0xE0��ʾ����һ�������
                        key = _getch(); // ��ȡʵ�ʵ�ɨ����
                    }
                    cout << (int)key << " ";
                    if (key == 8) {

                        if (flag_fx == 1 && input_account.size() >= 2) {
                            input_account.erase(input_account.size() - 2, 1);


                        }
                        if (flag_fx == 2 && input_password.size() >= 2) {
                            input_password.erase(input_password.size() - 2, 1);
                        }
                    }
                    /*else if (key == 77 || key == 75) {
                        if (key == 75) {
                            if (flag_fx == 1) {
                                if (flag2_fx > 0) {
                                    swap(input_account[flag2_fx], input_account[flag2_fx - 1]);
                                }
                            }
                            else {
                                if (flag2_fx > 0) {
                                    swap(input_password[flag2_fx], input_password[flag2_fx - 1]);
                                }
                            }
                        }
                        else if (key == 77) {
                            if (flag_fx == 1) {
                                if (flag2_fx< input_account.size()-1) {
                                    swap(input_account[flag2_fx], input_account[flag2_fx+1]);
                                }
                            }
                            else {
                                if (flag2_fx<input_account.size()-1) {
                                    swap(input_password[flag2_fx], input_password[flag2_fx +1]);
                                }
                            }

                        }
                    }*/
                    else if (key == 13) {
                        if (flag_fx == 1)goto bb;
                        else if (flag_fx == 2)goto cc;
                    }
                    else if (key >= 32 && key <= 128) {

                        if (flag_fx == 1) {

                            input_account.insert(input_account.size() - 1, 1, key);
                        }
                        else if (flag_fx == 2) {
                            input_password.insert(input_password.size() - 1, 1, key);
                        }
                    }
                }
            }

            else if (flag1_fx == 1) {


                int k = -1; // ��ʼֵ���жϼ�λ��������

                if (!login_bottons.empty() && login_bottons[1].size() > 0) {
                    for (int i = 0; i < login_bottons[1].size(); i++) {
                        if (login_bottons[1][i].isarea(msg)) {
                            k = i;
                            break;
                        }
                    }
                    if (k == -1 && msg.message == WM_LBUTTONDOWN)continue;
                }

                if (k == 0) {
                dd:

                    if (input_account.empty() && input_account != "|") {
                        string linshi = "�˺Ų���Ϊ��";
                        settextcolor(WHITE);
                        outtextxy((WIDTH / 2 - 15 * linshi.size() / 2), 200, linshi.c_str());
                        FlushBatchDraw();
                        Sleep(1000);
                    }
                    else if (input_password.empty() && input_password != "|") {
                        string linshi = "���벻��Ϊ��";
                        settextcolor(WHITE);
                        outtextxy((WIDTH / 2 - 15 * linshi.size() / 2), 200, linshi.c_str());
                        FlushBatchDraw();
                        Sleep(1000);
                    }
                    else {
                        if (!input_account.empty() && input_account.back() == '|') input_account.pop_back();
                        if (!input_password.empty() && input_password.back() == '|') input_password.pop_back();
                        accounts[input_account] = input_password;
                        fpr << input_account << endl << input_password << endl;
                        input_account.clear();
                        input_password.clear();
                        flag_fx = 0;
                        flag1_fx = 0;
                    }
                    continue;
                }
                else if (k == 1) {

                    flag_fx = 0;
                    flag1_fx = 0; // ���ص�¼ҳ��
                    input_password.clear();
                    input_account.clear();
                }
                // ����������
                else if (k == 3) {
                    if (!input_account.empty() && input_account.back() == '|') {
                        input_account.pop_back();
                    }
                    else if (!input_password.empty()) {
                        input_password.pop_back();
                    }
                    input_account.push_back('|');
                    flag_fx = 1;
                }
                else if (k == 4) {
                aa:
                    if (!input_password.empty() && input_password.back() == '|') {
                        input_password.pop_back();
                    }
                    else if (!input_account.empty()) {
                        input_account.pop_back();
                    }
                    input_password.push_back('|');
                    flag_fx = 2;
                    continue;
                }

                if (k == -1) {
                    char key = _getch();
                    if (key == 0 || key == 0xE0) { // ǰ���ֽ�Ϊ0��0xE0��ʾ����һ�������
                        key = _getch(); // ��ȡʵ�ʵ�ɨ����
                    }
                    if (key == 8) {
                        if (flag_fx == 1 && input_account.size() >= 2) {
                            input_account.erase(input_account.size() - 2, 1);
                            flag2_fx--;
                        }
                        if (flag_fx == 2 && input_password.size() >= 2) {
                            input_password.erase(input_password.size() - 2, 1);
                            flag2_fx--;
                        }
                    }

                    else if (key == 13) {
                        if (flag_fx == 1) {
                            goto aa;
                        }if (flag_fx == 2) {
                            goto dd;
                        }

                    }
                    else if (key >= 32 && key < 128) {
                        if (flag_fx == 1) {
                            input_account.insert(input_account.size() - 1, 1, key);
                            flag2_fx++;
                        }
                        else if (flag_fx == 2) {
                            input_password.insert(input_password.size() - 1, 1, key);
                            flag2_fx++;
                        }
                    }
                }
            }

        }

    }
    fpr.close();
}
void loginview::login_loadimg()
{
    IMAGE img;
    vector<botton> logoin;

    // ������ֵ
    loadimage(&img, "./����3.jpg", BACKGROUND_WIDTH, BACKGROUND_HEIGHT);
    img_login_background.push_back(img);
    // ��¼��ť
    string bot = "��¼";
    botton cascal(WIDTH / 2 - BUTTON_WIDTH / 4, 400, BUTTON_WIDTH / 2, BUTTON_HEIGHT, bot);
    logoin.push_back(cascal);

    // �������밴ť
    bot = "";
    botton foget(0, 700, 0, 0, bot);
    logoin.push_back(foget);

    // ע�ᰴť
    bot = "û���˺ţ�����ע��";
    botton enroll(WIDTH - bot.size() * 9, 700, bot.size() * 9, 12, bot);
    logoin.push_back(enroll);

    // �����ռλ��
    botton eroll(300, 300, BUTTON_WIDTH, 30, "");
    logoin.push_back(eroll);
    botton eroll1(300, 350, BUTTON_WIDTH, 30, "");
    logoin.push_back(eroll1);

    login_bottons.push_back(logoin);

    // ע��ҳ�水ť
    vector<botton> logoin1;
    bot = "ע��";
    botton cascal1(WIDTH / 2 - BUTTON_WIDTH / 4, 400, BUTTON_WIDTH / 2, BUTTON_HEIGHT, bot);
    logoin1.push_back(cascal1);
    bot = "����";
    botton enroll2(WIDTH - bot.size() * 9, 700, bot.size() * 9, 12, bot); logoin1.push_back(enroll2);
    bot = "";
    botton enroll3(WIDTH - 3 * bot.size() * 9, 700, bot.size() * 9, 12, bot); logoin1.push_back(enroll3);
    // ռλ����ť
    botton eroll4(300, 300, BUTTON_WIDTH, 30, "");
    logoin1.push_back(eroll4);
    botton eroll15(300, 350, BUTTON_WIDTH, 30, "");
    logoin1.push_back(eroll15);

    login_bottons.push_back(logoin1);
}

bool loginview::isaccount(fstream& fpr) {
    string line, line1;
    int x = 0;

    // ���accountsΪ�գ�����ļ��м�������
    if (accounts.empty()) {
        fpr.clear(); // ����ļ�����״̬��־
        fpr.seekg(0, ios::beg); // ���ļ�ָ���Ƶ��ļ���ͷ

        while (getline(fpr, line)) {

            getline(fpr, line1);
            if (!line.empty() && !line1.empty()) {
                accounts.insert(make_pair(line, line1));

            }

            ++x; // ����x��ֵ
        }
    }

    // ���������˻��������Ƿ�ƥ��
    auto it = accounts.find(input_account);
    if (it != accounts.end() && it->second == input_password) {
        return true;
    }
    return false;
}

void loginview::addNewBotton(const botton& my_botton)
{

}