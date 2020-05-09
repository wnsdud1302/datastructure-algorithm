#include <iostream>
#include <conio.h> //getch()�� kbhit() �Լ� ���
#include <ctime> //clock() �Լ� ���

using namespace std;

#define ESC 27 //���� ����
#define LEFT 75 //���� ȭ��ǥ Ű ASCII��
#define RIGHT 77 // ������ ȭ��ǥ Ű ASCII��
#define DOWN 80 //�Ʒ� ȭ��ǥ Ű ASCII��
#define UP 72 //���� ȭ��ǥ Ű ASCII��

#define MDIM 4 //4x4 ������� ũ��
#define PDIM 7 //7x7 ������ ũ��


//���� Map �׸��� ���� ��ġ: �ʿ��ϴٸ� ��� ��ġ�� ������ �� ���� 
#define MAP_STARTX 20 
#define MAP_STARTY 2

//�̵� ȸ�� �� �ҿ�ð� ��� ��ġ: �ʿ��ϴٸ� ��� ��ġ�� ������ �� ���� 
#define SCORE_STARTX 20
#define SCORE_STARTY 30

static int numPat[16][7][7]=
{
{2,2,2,2,2,2,2,
 2,0,0,0,0,0,2,
 2,0,0,0,0,0,2,
 2,0,0,0,0,0,2,
 2,0,0,0,0,0,2,
 2,0,0,0,0,0,2,
 2,2,2,2,2,2,2},
{2,2,2,2,2,2,2,
 2,0,0,1,0,0,2,
 2,0,0,1,0,0,2,
 2,0,0,1,0,0,2,
 2,0,0,1,0,0,2,
 2,0,0,1,0,0,2,
 2,2,2,2,2,2,2},
{2,2,2,2,2,2,2,
 2,0,1,1,1,0,2,
 2,0,0,0,1,0,2,
 2,0,1,1,1,0,2,
 2,0,1,0,0,0,2,
 2,0,1,1,1,0,2,
 2,2,2,2,2,2,2},
{2,2,2,2,2,2,2,
 2,0,1,1,1,0,2,
 2,0,0,0,1,0,2,
 2,0,1,1,1,0,2,
 2,0,0,0,1,0,2,
 2,0,1,1,1,0,2,
 2,2,2,2,2,2,2},
{2,2,2,2,2,2,2,
 2,0,1,0,1,0,2,
 2,0,1,0,1,0,2,
 2,0,1,1,1,0,2,
 2,0,0,0,1,0,2,
 2,0,0,0,1,0,2,
 2,2,2,2,2,2,2},
{2,2,2,2,2,2,2,
 2,0,1,1,1,0,2,
 2,0,1,0,0,0,2,
 2,0,1,1,1,0,2,
 2,0,0,0,1,0,2,
 2,0,1,1,1,0,2,
 2,2,2,2,2,2,2},
{2,2,2,2,2,2,2,
 2,0,1,0,0,0,2,
 2,0,1,0,0,0,2,
 2,0,1,1,1,0,2,
 2,0,1,0,1,0,2,
 2,0,1,1,1,0,2,
 2,2,2,2,2,2,2},
{2,2,2,2,2,2,2,
 2,0,1,1,1,0,2,
 2,0,0,0,1,0,2,
 2,0,0,0,1,0,2,
 2,0,0,0,1,0,2,
 2,0,0,0,1,0,2,
 2,2,2,2,2,2,2},
{2,2,2,2,2,2,2,
 2,0,1,1,1,0,2,
 2,0,1,0,1,0,2,
 2,0,1,1,1,0,2,
 2,0,1,0,1,0,2,
 2,0,1,1,1,0,2,
 2,2,2,2,2,2,2},
{2,2,2,2,2,2,2,
 2,0,1,1,1,0,2,
 2,0,1,0,1,0,2,
 2,0,1,1,1,0,2,
 2,0,0,0,1,0,2,
 2,0,0,0,1,0,2,
 2,2,2,2,2,2,2},
{2,2,2,2,2,2,2,
 2,1,0,1,1,1,2,
 2,1,0,1,0,1,2,
 2,1,0,1,0,1,2,
 2,1,0,1,0,1,2,
 2,1,0,1,1,1,2,
 2,2,2,2,2,2,2},
{2,2,2,2,2,2,2,
 2,1,0,0,1,0,2,
 2,1,0,0,1,0,2,
 2,1,0,0,1,0,2,
 2,1,0,0,1,0,2,
 2,1,0,0,1,0,2,
 2,2,2,2,2,2,2},
{2,2,2,2,2,2,2,
 2,1,0,1,1,1,2,
 2,1,0,0,0,1,2,
 2,1,0,1,1,1,2,
 2,1,0,1,0,0,2,
 2,1,0,1,1,1,2,
 2,2,2,2,2,2,2},
{2,2,2,2,2,2,2,
 2,1,0,1,1,1,2,
 2,1,0,0,0,1,2,
 2,1,0,1,1,1,2,
 2,1,0,0,0,1,2,
 2,1,0,1,1,1,2,
 2,2,2,2,2,2,2},
{2,2,2,2,2,2,2,
 2,1,0,1,0,1,2,
 2,1,0,1,0,1,2,
 2,1,0,1,1,1,2,
 2,1,0,0,0,1,2,
 2,1,0,0,0,1,2,
 2,2,2,2,2,2,2},
{2,2,2,2,2,2,2,
 2,1,0,1,1,1,2,
 2,1,0,1,0,0,2,
 2,1,0,1,1,1,2,
 2,1,0,0,0,1,2,
 2,1,0,1,1,1,2,
 2,2,2,2,2,2,2}
};

enum COMMAND {Stop=0, Left, Right, Down, Up, Non};

class puzzleGame
{
public:
	    
		puzzleGame(void); //�ʱ�ȭ �Լ�; �ʿ�ÿ� �Ű������� �߰���
		void gameDraw(void); // ���� �ʰ� �ݺ�ȸ��, �ð� ����Լ�; MAP_STARTX, MAP_STARTY ����� �����ؼ� �׻� ���� ��ġ(gotoXY�Լ� ��뿡 ����ʿ�ÿ� �Ű������� �߰���
		void puzzleDraw(int (*puzzle)[PDIM], int x, int y);//
		void puzzleMove(int moveKey); //���� �̵� �Լ�; �ʿ�ÿ� �Ű����� �߰���
		void shuffle(int num);//���� �� �ʱ�ȭ; 50ȸ ������ �̵�, �ʿ�ÿ� ���� �߰� �� �� ����
		void getCommand(void);//��� ������ �� ��ġ�� �ְų� ESCŰ�� ���������� ���� 0�� ��ȯ
                             // ����Ű�� ������ ���� �ش� Ű���� ��ȯ(LEFT, RIGHT, DOWN, UP)
                             //�ʿ�ÿ� �Ű����� ���ڸ� �߰��� �� ����
		int getAction(void)	{ return action;};
private:
	   int map[MDIM][MDIM];
       int action;
	   int x,y; //��ĭ�� ��ġ
	   int moveNum; //�̵�ȸ��
	   clock_t sTime; //���� �ð�
	   clock_t cTime; //���� �ð�
};

void gotoXY(int x, int y); //�ܼ� ȭ�鿡�� Ŀ���� Ư�� ��ġ�� �̵�
int getDirectKey();

int main(void)
{
	puzzleGame gameBot;
	gameBot.shuffle(50);
	gameBot.gameDraw();
	gameBot.getCommand();
    while(gameBot.getAction())
	{
	  gameBot.puzzleMove(gameBot.getAction());
	  gameBot.gameDraw(); 
	  gameBot.getCommand();
	}

	cout << "The game is over!!" << endl;
	return 0;
}

puzzleGame::puzzleGame()
{

	//���� �ʱ�ȭ �ڵ� �ۼ�
	
}


void puzzleGame::puzzleDraw(int (*puzzle)[PDIM], int x, int y)
{
	for(int i=0;i< PDIM ; i++)
	{
	  gotoXY(x,y+i);
	  for(int j=0; j< PDIM; j++)
		{
			if(puzzle[i][j] == 0)
				cout << "  ";
			else if(puzzle[i][j] == 1)
				cout << "��";
			else
				cout << "��";
		
		}
	}
}

void puzzleGame::gameDraw(void)
{
	gotoXY(MAP_STARTX, MAP_STARTY);
	cout << "   Fifteen Puzzle" << endl;
	
	for(int i=0; i< MDIM; i++)
	{   
		for(int j=0; j< MDIM; j++)
		{

			//���⼭ puzzleDraw �Լ� ȣ����

		}
	}

	cout << endl;
	gotoXY(  SCORE_STARTX, SCORE_STARTY);
	cout << "  �̵� ȸ��: " << moveNum << endl;
	gotoXY(  SCORE_STARTX, SCORE_STARTY+1);
	cTime = clock();
	cout << "  �ҿ� �ð�: " << (cTime-sTime)/1000.0 << "��" << endl;
}



void puzzleGame::puzzleMove(int moveKey)
{
	~
    ~
	~
}

void puzzleGame::getCommand(void)
{
	~
	~
	~
}

//�ܼ� ȭ�鿡�� Ŀ���� Ư�� ��ġ�� �̵�
void gotoXY(int x, int y) 
{
 COORD Pos = {x, y};
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}


int getDirectKey()
{
	char key=Non;
    if(_kbhit()!= 0) //Ű���带 �������� Ȯ����
	{
	  //Ư�� Ű�� ������ �� ���ۿ� 2Byte�� �߻���, ù��° ���� 224���� �߻��ϰ� �ι�° ���� Ư��Ű�� ���� �ٸ�
	  //Ư�� Ű�� Ȯ���ϱ� ���� 2���� getch()�Լ��� ȣ���ؾ� ��
		key = getch();
		if(key==224) key=_getch();
	}
	return key;
} 
