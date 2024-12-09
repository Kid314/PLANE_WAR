#include<easyx.h>
#include "gameview.h"
#include "loginview.h"
#include "menuview.h"
#include "pauseview.h"
#include "settlementview.h"
#include "view.h"
using namespace std;



//---------------------全局变量---------------------------------

vector<int> gamescores;



map<string, string>accounts;

vector<botton> settlement_bottons;

//存放背景图片
vector<IMAGE> img_settlement_background;

vector<botton> pause_bottons;

//存放背景图片
vector<IMAGE> img_pause_background;

vector<botton> menu_bottons;

//存放背景图片
vector<IMAGE> img_menu_background;

//存放玩家
vector<Plane> players;

//存放所有敌机
vector<Enemy> enemys;

//存放所有子弹
vector<bullet> bullets;

//存放页面的按钮
vector<botton> game_bottons;

//存放游戏背景图片
vector<IMAGE> img_game_background;

//存放玩家图片
vector<IMAGE> img_plane;

//存放敌人图片
vector<IMAGE> img_enemy;

//存放子弹图片
vector<IMAGE> img_bullet;

vector<vector<botton>> login_bottons;

//存放背景图片
vector<IMAGE> img_login_background;


//flag 代表游戏状态
// flag=0 正常游玩
// =1 暂停
// =2失败或者通关，进入菜单
// =3重新挑战
//=4 暂停之后回菜单
int flag = 0;
//积分
int score = 0;


//---------------菜单界面-------------------------------------

//-----------登录的页面---------------------------------------
/*
* * 完成人：张三
		* 参数：void
		* 输出：bool
		* 功能：
	整合loginview页面的函数并且结合easyx的文本以及键盘鼠标消息
	做出完整的登录界面
	包括：
	-登录界面
	-游客登录界面
	等，以及他们的跳转关系
	登陆成功就输出true
*/
bool login();

//----------------主菜单界面----------------------------

/*
* * 完成人：张三
		* 参数：void
		* 输出：void
		* 功能：
		* 整合menuview页面的函数并且结合easyx的文本以及键盘鼠标消息
	做出完整的主菜单界面
	包括：
		-开始游戏
		-退出游戏
		-继续游戏
			（若没玩过游戏则能提示未找到存档）
		-设置
*/
int menu();



/*
* * 完成人：张三
		* 参数：void
		* 输出：int 
		* 功能：
		* 整合gameview以及pauseview页面的函数并且结合easyx的文本以及键盘鼠标消息
		* 根据flag
		* 如果flag==3则要清理数据再开始因为是重新挑战
		* 做出能暂停的游戏流程
		* 如果有暂停发生则立马结束，并返回1
		* 没有则正常结束
		* 通关为0
		* 失败为2

*/
int game();

//--------------------------结算界面--------------------

/*
* * 完成人：张三
		* 参数：void
		* 输出：int
		* 功能：
		*			当通关时打印通关结算界面
		*			未通关时打印未通关结算界面
		* 若跳转到主菜单则返回2
		* 若重新挑战则返回3
		*			
*/
int settlement(int game_logic,int score);
//-------------------主函数---------------------------
/*
* 完成人：张三
		* 参数：void
		* 输出：int 
		* 功能：
		* 整体的整合
*/

int main()
{
	int game_logic;
	if (login())
	{
		initgraph(WIDTH, HEIGHT);
		//加载菜单
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
	绘制游戏流程
	即整合gameview.h和easyx的函数
*/

int game()
{
		ExMessage  msg = { 0 };
		gamescores.push_back(score);
		int nowscore = gamescores[gamescores.size() - 1];

		gameview* gameview1 = new gameview();

		gameview1->game_loadimg();
		
		if (flag == 1)//暂停回来
			;
		else if (flag == 3)
			gameview1->cleandata();
		else 
			gameview1->init_gamedata();

		//绘制所有模型

	int count = 0;
	int die_count = 0;
	int die_count2=0;
	//双缓冲绘图
	BeginBatchDraw();

	while (1)
	{

		gameview1->gameviewprint();
		botton pause_botton2(10, 10, 20, 20, "II");

		pause_botton2.printBotton();

		botton pause_botton1(WIDTH-20, 10, 20, 20, std::to_string(nowscore));

		pause_botton1.printBotton();

		//双缓冲绘图
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
			return 0;//通关
		}
			
		if(gameview1->iswin(players[players.size() - 1]) == 2)
		{
			score = nowscore;
			return 2;
		}
	}
	//双缓冲绘图
	EndBatchDraw();
}

//------------------------登录的页面的实现---------------------------------


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


//------------------------主菜单页面的实现---------------------------------
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
//-----------------------结算页面的实现-------------------------------------
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
					return 1;//重新挑战
				}
				if (msg.x <= WIDTH * 7 / 16 + WIDTH / 6 && msg.x >= WIDTH * 7 / 16 && msg.y <= (HEIGHT / 8 + HEIGHT / 4 + HEIGHT / 8 + HEIGHT / 16 * 2) + 20 * 4 + HEIGHT / 16 && msg.y >= (HEIGHT / 8 + HEIGHT / 4 + HEIGHT / 8 + HEIGHT / 16 * 2) + 20 * 4 && msg.message == WM_LBUTTONDOWN)
				{
					return 2;//返回菜单
				}
			}
		}
}
