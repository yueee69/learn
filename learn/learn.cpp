#include <iostream>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <cstdlib>

using namespace std;

double start;
int score = 0, dechp = 10, incsc = 1, constime = 2;

struct combat
{
	string weap[6] = { "" };//背包格子
	int atk = 20, def = 5, matk = 20, mdef = 5, hp = 500;
} enemy, player;

void delay(short times)
{
	clock_t now = clock();

	while (clock() - now < times);
}

void setcolor(short color = 7)
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

void restart() {
	system("cls");
	for (short sec = 3; sec >= 1; sec--) {
		cout << sec;
		delay(1000);
		system("cls");
	}
	start = GetTickCount64();
}

class kb
{
public:
	void start() {
		cout << "輸入start開始(請記得切換小寫及英文輸入)\n局內輸入/help可查看教學與指令！\n";
		while (1)
		{
			string test;
			cin >> test;
			if (test == "start") {
				break;
			}
			else {
				system("cls");
				cout << "輸入start開始(請記得切換小寫及英文輸入)\n局內輸入/help可查看教學與指令！" << endl;
				setcolor(3);
				cout << "調整好了就輸入start哦！" << endl;
				setcolor();
			}
		}
	}
	void esc() {
		while (1) {
			if (_kbhit()) {
				if (_getch() == 27)
					break;
			}
		}
	}
	void tab() {
		while (1) {
			if (_kbhit()) {
				if (_getch() == 9)
					break;
			}
		}
	}
};

void gamemode() {
	string cheat;
	int setmode = 0;
	system("cls");
	cout << "1.設定血量:" << player.hp << endl;
	cout << "2.設定分數:" << score << endl;
	cout << "3.設定加分:" << incsc << endl;
	cout << "4.設定扣血:" << dechp << endl;
	cout << "5.打字時間:" << constime << endl;
	cout << "請輸入欲修改的數值項:";
	while (1) {
		cin >> cheat;
		if (cheat == "end") restart();
		else if (cheat == "1") {
			system("cls");
			cout << "設定血量(目前血量" << player.hp << "):";
			cin >> setmode;
			if (setmode == 0) {
				gamemode();
			}
			else if (setmode <= 0) {
				player.hp = 1;
				gamemode();
			}
			else if (setmode > 99999) {
				player.hp = 99999;
				gamemode();
			}
			else {
				player.hp = setmode;
				gamemode();
			}
		}
		else if (cheat == "2") {
			system("cls");
			cout << "設定分數(目前分數" << score << "):";
			cin >> setmode;
			if (setmode == 0) {
				gamemode();
			}
			else if (setmode <= 0) {
				score = 1;
				gamemode();
			}
			else if (setmode > 99999) {
				score = 99999;
				gamemode();
			}
			else {
				score = setmode;
				gamemode();
			}
		}
		else if (cheat == "3") {
			system("cls");
			cout << "設定加分(答對一題加" << incsc << "分):";
			cin >> setmode;
			if (setmode == 0) {
				gamemode();
			}
			else if (setmode <= 0) {
				incsc = 1;
				gamemode();
			}
			else if (setmode > 100) {
				incsc = 100;
				gamemode();
			}
			else {
				incsc = setmode;
				gamemode();
			}
		}
		else if (cheat == "4") {
			system("cls");
			cout << "設定扣血(一次扣" << dechp << "):";
			cin >> setmode;
			if (setmode == 0) {
				gamemode();
			}
			else if (setmode <= 0) {
				dechp = 1;
				gamemode();
			}
			else if (setmode > 99999) {
				dechp = 99999;
				gamemode();
			}
			else {
				dechp = setmode;
				gamemode();
			}
		}
		else if (cheat == "5") {
			system("cls");
			cout << "設定打字時間(" << constime << "秒內回答正確就加分):";
			cin >> setmode;
			if (setmode == 0) {
				gamemode();
			}
			else if (setmode <= 0) {
				constime = 1;
				gamemode();
			}
			else if (setmode > 99999) {
				constime = 99999;
				gamemode();
			}
			else {
				constime = setmode;
				gamemode();
			}
		}
		else {
			setcolor(3);
			cout << "請輸入正確的值！";
			setcolor();
			delay(3000);
			gamemode();
		}
		break;
	}
}

class bag {
public:
	kb kb;
	void slot() {
		system("cls");
		for (short n = 0; n <= 5; n++)
			cout << "slot" << n + 1 << ":" << player.weap[n] << endl;
		cout << "按esc返回";
		kb.esc();
	}
};


void Help() {
	kb kb;
	system("cls");
	string help;
	cout << "/bag \t\t查看背包裡的道具" << endl;
	cout << "/gamemode \t使用作弊調整各項數據" << endl;
	cout << "/weaponinfo \t裝備圖鑑" << endl;
	cout << "/task \t\t查看突發任務" << endl;
	setcolor(12);
	cout << "/gameinfo \t查看遊戲介紹(超級重要 一定要看！！！！！)" << endl;
	setcolor();
	cout << "輸入以上任一指令可查看詳細介紹！\n輸入/end返回遊戲。" << endl;
	cout << "/";
	while (1) {
		cin >> help;
		if (help == "bag") {
			system("cls");
			cout << "這是一個背包存放頁面!" << endl;
			cout << "獲取的裝備將儲存於此" << endl;
			cout << "並可讀取裝備的能力" << endl;
			cout << "部分裝備擁有「主動技能」與「被動技能」" << endl;
			cout << "「主動技能」可在背包內使用" << endl;
			cout << "詳細能力可使用/weaponinfo進行查詢。\n" << endl;
			cout << "按esc返回上一頁";
			kb.esc();
			Help();
		}
		else if (help == "gamemode") {
			system("cls");
			cout << "這個指令可以設定大部分的遊戲參數!" << endl;
			setcolor(3);
			cout << "不過每個參數都有各自的上下限喔!" << endl;
			setcolor();
			cout << "目前能調整的參數有:" << endl;
			cout << "血量 分數 扣血 加分 打字時間。\n" << endl;
			cout << "按esc返回上一頁";
			kb.esc();
			Help();
		}
		else if (help == "gameinfo") {
			system("cls");
			cout << "這是一個打字的遊戲！" << endl;
			cout << "遊戲的玩法如下：" << endl;
			cout << "在" << constime << "秒內打出題目的內容，即可加" << incsc << "分" << endl;
			cout << "反之，若打字時間大於" << constime << "秒，則扣" << dechp << "點血量" << endl;
			cout << "但是只有這樣實在是太無聊了！" << endl;
			cout << "於是我們增加了";
			setcolor(3);
			cout << "任務系統";
			setcolor();
			setcolor(3);
			cout << "製作這個遊戲的動機：" << endl;
			setcolor();
			cout << "在二上接觸資訊課時學習了c++" << endl;
			cout << "對我來說，其實產生了極大的興趣" << endl;
			cout << "在課餘時間我也會自己學習一些程式" << endl;
			cout << "同時買了一本叫「c++全方位學習(";
			setcolor(3);
			cout << "ISBN:9789865028022";
			setcolor();
			cout << ")的書" << endl;
			cout << "在閱讀完後，雖然不能說是爐火純青，但也能應付大部分的東西了！" << endl;
			cout << "於是想要挑戰自己，做出一款小遊戲" << endl;
			cout << "雖然這個遊戲用到的數學很少" << endl;
			cout << "很多都是硬做出來的" << endl;
			cout << "這就是我覺得目前我最大的缺失。\n" << endl;
			cout << "參考資料:" << endl;
			cout << "控制台字體顏色  https://blog.csdn.net/wangxun20081008/article/details/115046817" << endl;
			cout << "delay(延遲)函數  https://blog.csdn.net/tangweide/article/details/7063747\n" << endl;
			cout << "按esc返回上一頁";
			kb.esc();
			Help();
		}
		else if (help == "weaponinfo") {
			cout << "白色=一般品質  ";
			setcolor(13);
			cout << "紫色";
			setcolor();
			cout << "=稀有品質  ";
			setcolor(14);
			cout << "黃色";
			setcolor();
			cout << "=傳說品質" << endl;
			cout << "";

			cout << "按esc返回上一頁";
			kb.esc();
			Help();
		}
		else if (help == "end") {
			break;
		}
		else {
			setcolor(3);
			cout << "請輸入正確的指令!";
			setcolor();
			delay(3000);
			Help();
		}
		break;
	}
}



void type() {
	short n = 0, round = 0, r = 0;
	double usetime = 0;
	kb kb;
	bag bag;
	kb.start();
	restart();
	const string s[] = { "123","456","789","012" };
	string question = {};
	string typein = {};
	while (player.hp > 0 && enemy.hp > 0) {
		start = GetTickCount64();
		srand(time(NULL));
		n = rand() % 4;
		question.clear();
		typein.clear();
		question = s[n];
		system("cls");
		round++;
		cout << question << "\tscore:" << score << "\thp:" << player.hp << "\tround:" << round << "\t敵人血量:" << enemy.hp << endl;
		while (1) {
			cin >> typein;
			cin.ignore();
			if (typein == "/help") {
				Help();
				restart();
				cout << question << "\tscore:" << score << "\thp:" << player.hp << "\tround:" << round << "\t敵人血量:" << enemy.hp << endl;
			}
			else if (typein == "/bag") {//呼叫背包
				bag.slot();
				restart();
				cout << question << "\tscore:" << score << "\thp:" << player.hp << "\tround:" << round << "\t敵人血量:" << enemy.hp << endl;
			}
			else if (typein == "/gamemode") {//作弊清單
				gamemode();
				cout << question << "\tscore:" << score << "\thp:" << player.hp << "\tround:" << round << "\t敵人血量:" << enemy.hp << endl;
			}
			else if (typein == question)
				break;
		}
		double end = GetTickCount64();
		if (end < start)
			usetime = (end / 1000 + 86000) - (start / 1000);
		else usetime = (end - start) / 1000;
		if (usetime < constime) {
			score += incsc;
			if (player.matk > player.atk)
				enemy.hp -= player.matk - enemy.mdef;
			else enemy.hp -= player.atk - enemy.def;
		}
		else
			player.hp -= 100;
	}
		system("cls");
		cout << (player.hp >= 0 ? "你贏了！\n遊戲結束！" : "您死了！\n遊戲結束！") << endl;
		setcolor();
		system("pause");
	
}

int main() {
	system("title 這是一個打字小遊戲!!");
	for (short n = 0; n < 6; n++) {
		player.weap[n].append("空");
		enemy.weap[n].append("空");
	}
	type();
}
