#include "gameview.h"
#include<random>
#include<Windows.h>

//------------------------游戏页面的实现---------------------------------

/*
	定时器的实现
*/
bool gameview::Timer(int ms, int id)
{
	static DWORD t[10];
	if (clock() - t[id] > ms)
	{
		t[id] = clock();
		return TRUE;
	}
	return FALSE;
}

void gameview::game_loadimg()
{
	img_game_background.resize(1);
	img_plane.resize(1);
	img_enemy.resize(5);
	img_bullet.resize(1);
	loadimage(&img_game_background[0], "../suorce/game.jpeg", WIDTH, HEIGHT);
	loadimage(&img_plane[0], "../suorce/plane.png", 39, 39);
	loadimage(&img_enemy[0], "../suorce/enemy1.jpeg", 52, 50);
	loadimage(&img_enemy[1], "../suorce/enemy2.jpeg", 52, 50);
	loadimage(&img_enemy[2], "../suorce/enemy3.jpeg", 52, 50);
	loadimage(&img_enemy[3], "../suorce/enemy4.jpeg", 52, 50);
	loadimage(&img_enemy[4], "../suorce/boss.jpg", 150, 160);
	loadimage(&img_bullet[0], "../suorce/bullet.png", 29, 32);
}

void gameview::init_gamedata()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, WIDTH - 52);


	int randomNum1 = dis(gen);
	int randomNum2 = dis(gen);
	int randomNum3 = dis(gen);

	Plane playerplane(WIDTH / 2 - 20, HEIGHT - 39, 39, 39,5, 1000, TRUE);
	players.push_back(playerplane);

	Enemy enemy1(randomNum1, 0, 52, 50, 2, 10, TRUE);
	Enemy enemy2(randomNum2, 0, 52, 50, 2, 10, TRUE);
	Enemy enemy3(randomNum3, 0, 52, 50, 2, 10, TRUE);
	enemys.push_back(enemy1);
	enemys.push_back(enemy2);
	enemys.push_back(enemy3);
}

void gameview::createbullet()
{
	for (const Enemy& kv : enemys)
	{
		if (kv.get_speed() == 0)
		{
			bullet  bullet2(kv.get_x(), kv.get_y() + 160, 29, 32,2, FALSE, 5, TRUE);
			bullet  bullet3(kv.get_x()+150-32, kv.get_y() +160, 29, 32,2,FALSE, 5, TRUE);
			bullets.push_back(bullet2);
			bullets.push_back(bullet3);
		}
	}
	Plane player = players[players.size()-1];
	bullet  bullet1(player.get_x(), player.get_y() - 32, 29, 32, 15, TRUE, 5, TRUE);
	bullets.push_back(bullet1);
}

void gameview::createnemy(int count)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, WIDTH - 52);

	int randomNum1 = dis(gen);
	
	if (count == 30)
	{
		Enemy enemy1(WIDTH / 2 - 75, 0, 320, 43, 0, 2000, TRUE);
		enemys.push_back(enemy1);
	}
	
	if (count > 30)
	{
		if (randomNum1 > WIDTH / 2 - 75 && randomNum1 < WIDTH / 2 + 75)
		{
			Enemy enemy3(randomNum1, 43, 52, 50, 2, 10, TRUE);
			enemys.push_back(enemy3);
		}
		else
		{
			Enemy enemy2(randomNum1, 0, 52, 50, 2, 10, TRUE);
			enemys.push_back(enemy2);
		}
	}
	else
	{
		Enemy enemy2(randomNum1, 0, 52, 50, 2, 10, TRUE);
		enemys.push_back(enemy2);
	}
}

void gameview::gameviewprint()
{
	putimage(0, 0, &img_game_background[0]);

	
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, 3);

	for (Enemy& kv : enemys)
	{
		int randomNum1 = dis(gen);
		if (kv.get_alive() != FALSE)
		{
			if (kv.get_speed() == 0)
			{
				putimage(kv.get_x(), kv.get_y(), &img_enemy[4]);
			}
			else
			putimage(kv.get_x(), kv.get_y(), &img_enemy[0]);
		}
	}
	putimage(players[players.size() - 1].get_x(), players[players.size() - 1].get_y(), &img_plane[0]);

	for (bullet& kv : bullets)
	{
		if (kv.get_alive() != FALSE)
		{
			putimage(kv.get_x(), kv.get_y(), &img_bullet[0]);
		}
	}
}

void gameview::cleandata()
{
	enemys.clear();
	bullets.clear();

	Plane playerplane(WIDTH / 2 - 64, HEIGHT - 104, 128, 104, 10, 100, TRUE);
	players.push_back(playerplane);

	Enemy enemy1(rand() % (WIDTH - 132), 0, 132, 89, 5, 1, TRUE);
	Enemy enemy2(rand() % (WIDTH - 132), 0, 132, 89, 5, 1, TRUE);
	Enemy enemy3(rand() % (WIDTH - 132), 0, 132, 89, 5, 1, TRUE);
	enemys.push_back(enemy1);
	enemys.push_back(enemy2);
	enemys.push_back(enemy3);
}

void gameview::addNewBotton(const botton& my_botton)
{
	game_bottons.push_back(my_botton);
}

int gameview::iswin(Plane& player)
{
	if (player.get_hp() <= 0)
	{
		return 2;
	}
	for (const Enemy& kv : enemys)
	{
		if (kv.get_speed() == 0)
		{
			if (kv.get_hp() <= 0)
			{
				return 1;
			}
		}
	}
	return 0;
}
