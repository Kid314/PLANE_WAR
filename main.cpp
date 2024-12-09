#include<easyx.h>
#include "gameview.h"
#include "loginview.h"
#include "menuview.h"
#include "pauseview.h"
#include "settlementview.h"
#include "view.h"
using namespace std;



//---------------------ȫ�ֱ���---------------------------------

vector<int> gamescores;



map<string, string>accounts;

vector<botton> settlement_bottons;

//��ű���ͼƬ
vector<IMAGE> img_settlement_background;

vector<botton> pause_bottons;

//��ű���ͼƬ
vector<IMAGE> img_pause_background;

vector<botton> menu_bottons;

//��ű���ͼƬ
vector<IMAGE> img_menu_background;

//������
vector<Plane> players;

//������ел�
vector<Enemy> enemys;

//��������ӵ�
vector<bullet> bullets;

//���ҳ��İ�ť
vector<botton> game_bottons;

//�����Ϸ����ͼƬ
vector<IMAGE> img_game_background;

//������ͼƬ
vector<IMAGE> img_plane;

//��ŵ���ͼƬ
vector<IMAGE> img_enemy;

//����ӵ�ͼƬ
vector<IMAGE> img_bullet;

vector<vector<botton>> login_bottons;

//��ű���ͼƬ
vector<IMAGE> img_login_background;


//flag ������Ϸ״̬
// flag=0 ��������
// =1 ��ͣ
// =2ʧ�ܻ���ͨ�أ�����˵�
// =3������ս
//=4 ��֮ͣ��ز˵�
int flag = 0;
//����
int score = 0;


//---------------�˵�����-------------------------------------

//-----------��¼��ҳ��---------------------------------------
/*
* * ����ˣ�����
		* ������void
		* �����bool
		* ���ܣ�
	����loginviewҳ��ĺ������ҽ��easyx���ı��Լ����������Ϣ
	���������ĵ�¼����
	������
	-��¼����
	-�ο͵�¼����
	�ȣ��Լ����ǵ���ת��ϵ
	��½�ɹ������true
*/
bool login();

//----------------���˵�����----------------------------

/*
* * ����ˣ�����
		* ������void
		* �����void
		* ���ܣ�
		* ����menuviewҳ��ĺ������ҽ��easyx���ı��Լ����������Ϣ
	�������������˵�����
	������
		-��ʼ��Ϸ
		-�˳���Ϸ
		-������Ϸ
			����û�����Ϸ������ʾδ�ҵ��浵��
		-����
*/
int menu();



/*
* * ����ˣ�����
		* ������void
		* �����int 
		* ���ܣ�
		* ����gameview�Լ�pauseviewҳ��ĺ������ҽ��easyx���ı��Լ����������Ϣ
		* ����flag
		* ���flag==3��Ҫ���������ٿ�ʼ��Ϊ��������ս
		* ��������ͣ����Ϸ����
		* �������ͣ���������������������1
		* û������������
		* ͨ��Ϊ0
		* ʧ��Ϊ2

*/
int game();

//--------------------------�������--------------------

/*
* * ����ˣ�����
		* ������void
		* �����int
		* ���ܣ�
		*			��ͨ��ʱ��ӡͨ�ؽ������
		*			δͨ��ʱ��ӡδͨ�ؽ������
		* ����ת�����˵��򷵻�2
		* ��������ս�򷵻�3
		*			
*/
int settlement(int game_logic,int score);
//-------------------������---------------------------
/*
* ����ˣ�����
		* ������void
		* �����int 
		* ���ܣ�
		* ���������
*/

int main()
{
	int game_logic;
	if (login())
	{
		initgraph(WIDTH, HEIGHT);
		//���ز˵�
		while (1)
		{
			if (flag == 0||flag==4)
			{
				switch (menu())
				{
				case 0:
					flag = 0;
					break;
				case 1:
					flag = 1;
					break;
				case 2:
					return 0;
				}
			}
			game_logic = game();
			if (game_logic == 1)
			{
				ExMessage msg = { 0 };
				pauseview* pause = new pauseview();
				pause->pauseview_loadimg();
				pause->pauseviewprint();
				FlushBatchDraw();
				while (1)
				{
					if (peekmessage(&msg, EX_MOUSE))
					{
						if (msg.x <= 420 + 166 && msg.x >= 420 && msg.y <= 350+ 200 && msg.y >= 350 && msg.message == WM_LBUTTONDOWN)
						{
							flag = 1;
							break;
						}
						if (msg.x <= 420 + 166 && msg.x >= 420 && msg.y <= 551 + 200 && msg.y >= 551 && msg.message == WM_LBUTTONDOWN)
						{
							flag = 4;
							break;
						}
						if (msg.x <= 420 + 166 && msg.x >= 420 && msg.y <= 752 + 200 && msg.y >= 752 && msg.message == WM_LBUTTONDOWN)
						{
							flag = 4;
							break;
						}
					}
				}
			}
			if (flag == 1||flag==4)
			{
				cleardevice();
				continue;
			}
			cleardevice();
			switch (settlement(game_logic,score))
			{
			case 1:
				flag = 3;
				break;
			case 2:
				flag = 0;
				game_logic = 0;
				break;
			}
		}
	}
	getchar();

	return 0;
}




/*
	������Ϸ����
	������gameview.h��easyx�ĺ���
*/

int game()
{
		ExMessage  msg = { 0 };
		gamescores.push_back(score);
		int nowscore = gamescores[gamescores.size() - 1];

		gameview* gameview1 = new gameview();

		gameview1->game_loadimg();
		
		if (flag == 1)//��ͣ����
			;
		else if (flag == 3)
			gameview1->cleandata();
		else 
			gameview1->init_gamedata();

		//��������ģ��

	int count = 0;
	int die_count = 0;
	int die_count2=0;
	//˫�����ͼ
	BeginBatchDraw();

	while (1)
	{

		gameview1->gameviewprint();
		botton pause_botton2(10, 10, 20, 20, "II");

		pause_botton2.printBotton();

		botton pause_botton1(WIDTH-20, 10, 20, 20, std::to_string(nowscore));

		pause_botton1.printBotton();

		//˫�����ͼ
		FlushBatchDraw();

		players[players.size() - 1].move(players[players.size() - 1].get_speed());
		Sleep(8);


		for (bullet& kv : bullets)
		{
			kv.move(kv.get_speed());
		}

		static DWORD t2;
		if (gameview1->Timer(500, 0))
		{
			gameview1->createnemy(count);
			count++;
			gameview1->createbullet();
		}
		t2 = clock();

		for (Enemy& kv : enemys)
		{
			kv.move(kv.get_speed());

		}

		for (Enemy& kv : enemys)
		{
			kv.ishit(bullets);
		}
		for (Enemy& kv : enemys)
		{
			if (kv.get_alive() == false)
			{
				die_count++;
			}
		}
		nowscore += 10 * (die_count - die_count2);
		die_count2 = die_count;
		die_count = 0;
		players[players.size() - 1].ishit(bullets);
		if (peekmessage(&msg,EX_MOUSE))
		{
			if (msg.x <= 30 && msg.x >= 10 && msg.y <= 30 && msg.y >= 10 && msg.message == WM_LBUTTONDOWN)
			{
				score = nowscore;
				return 1;
			}
		}

		if (gameview1->iswin(players[players.size() - 1])==0) {}

		if (gameview1->iswin(players[players.size() - 1]) == 1)
		{
			score = nowscore;
			return 0;//ͨ��
		}
			
		if(gameview1->iswin(players[players.size() - 1]) == 2)
		{
			score = nowscore;
			return 2;
		}
	}
	//˫�����ͼ
	EndBatchDraw();
}

//------------------------��¼��ҳ���ʵ��---------------------------------


bool login()
{
	loginview* login = new loginview();
	login->login_loadimg();
	while (1)
	{
		login->loginviewprint();
		if (login->isaccount(login->fpr))
		{
			return TRUE;
		}
	}
}


//------------------------���˵�ҳ���ʵ��---------------------------------
int menu()
{
	ExMessage msg = { 0 };
	menuview* menu = new menuview();
	menu->menu_loadimg();
	while (1)
	{
		menu->menuviewprint();
		if (peekmessage(&msg, EX_MOUSE))
		{
			if (msg.x <= WIDTH / 4+ WIDTH / 2&& msg.x>= WIDTH / 4 && msg.y<= HEIGHT / 7+ HEIGHT / 7&& msg.y >= HEIGHT / 7 && msg.message == WM_LBUTTONDOWN)
			{
				return 1;
			}
			if (msg.x <= WIDTH / 4 + WIDTH / 2 && msg.x >= WIDTH / 4 && msg.y <= HEIGHT * 3 / 7 + HEIGHT / 7 && msg.y >= HEIGHT * 3 / 7 && msg.message == WM_LBUTTONDOWN)
			{
				return 0;
			}
			if (msg.x <= WIDTH / 4 + WIDTH / 2 && msg.x >= WIDTH / 4 && msg.y <= HEIGHT*5 / 7 + HEIGHT / 7 && msg.y >= HEIGHT * 5 / 7 && msg.message == WM_LBUTTONDOWN)
			{
				return 2;
			}
		}
	}
}
//-----------------------����ҳ���ʵ��-------------------------------------
int settlement(int game_logic,int score)
{
	ExMessage msg = { 0 };
	settlementview* settlement=new settlementview(score);
		if (game_logic == 0)
		{
			settlement->winview();
			
		}
		else if (game_logic == 2)
		{
			settlement->loseview();
		}
		FlushBatchDraw();
		while (1)
		{
			if (peekmessage(&msg, EX_MOUSE))
			{
				if (msg.x <= WIDTH * 7 / 16 + WIDTH / 6 && msg.x >= WIDTH * 7 / 16 && msg.y <= (HEIGHT / 8 + HEIGHT / 4 + HEIGHT / 8 + HEIGHT / 16) + 20 * 3+ HEIGHT / 16 && msg.y >= (HEIGHT / 8 + HEIGHT / 4 + HEIGHT / 8 + HEIGHT / 16) + 20 * 3 && msg.message == WM_LBUTTONDOWN)
				{
					return 1;//������ս
				}
				if (msg.x <= WIDTH * 7 / 16 + WIDTH / 6 && msg.x >= WIDTH * 7 / 16 && msg.y <= (HEIGHT / 8 + HEIGHT / 4 + HEIGHT / 8 + HEIGHT / 16 * 2) + 20 * 4 + HEIGHT / 16 && msg.y >= (HEIGHT / 8 + HEIGHT / 4 + HEIGHT / 8 + HEIGHT / 16 * 2) + 20 * 4 && msg.message == WM_LBUTTONDOWN)
				{
					return 2;//���ز˵�
				}
			}
		}
}
