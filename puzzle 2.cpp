#include <iostream>
#include <windows.h> //GetStdHandle(), Sleep(), SetConsoleCursorPosition() �Լ� ���
#include <conio.h> //getch()�� kbhit() �Լ� ���
#include <ctime> //clock() �Լ� ���

using namespace std;

#define ESC 27 //���� ����
#define LEFT 75 //���� ȭ��ǥ Ű ASCII��
#define RIGHT 77 // ������ ȭ��ǥ Ű ASCII��
#define DOWN 80 //�Ʒ� ȭ��ǥ Ű ASCII��
#define UP 72 //���� ȭ��ǥ Ű ASCII��

#define DIM 4 //4x4 ������� ũ��

static int x,y; //��ĭ�� ��ġ
static int moveNum; //�̵�ȸ��
static clock_t sTime; //���� �ð�
static clock_t cTime; //���� �ð�

//���� Map �׸��� ���� ��ġ: �ʿ��ϴٸ� ��� ��ġ�� ������ �� ���� 
#define MAP_STARTX 20 
#define MAP_STARTY 2

//�̵� ȸ�� �� �ҿ�ð� ��� ��ġ: �ʿ��ϴٸ� ��� ��ġ�� ������ �� ���� 
#define SCORE_STARTX 20
#define SCORE_STARTY 12



enum COMMAND {Stop=0, Left, Right, Down, Up, Non};

void gotoXY(int x, int y); //�ܼ� ȭ�鿡�� Ŀ���� Ư�� ��ġ�� �̵�
void init(int (*map)[DIM]); //�ʱ�ȭ �Լ�; �ʿ�ÿ� �Ű������� �߰���
void gameDraw(int (*map)[DIM]); // ���� �ʰ� �ݺ�ȸ��, �ð� ����Լ�; MAP_STARTX, MAP_STARTY ����� �����ؼ� �׻� ���� ��ġ(gotoXY�Լ� ��뿡 ����ʿ�ÿ� �Ű������� �߰���
//                ȭ�� ��� ����
//                Fifteen Puzzle
//                  1  2  9  3
//                  6  8  7  4
//                  10    5  15
//                  13 14 12 11
//
//                  �̵� ȸ��: 10ȸ
//                  �ҿ� �ð�: 15.2��

void puzzleMove(int (*map)[DIM], int action); //���� �̵� �Լ�; �ʿ�ÿ� �Ű����� �߰���
void shuffle(int num,int (*map)[DIM]);//���� �� �ʱ�ȭ; 50ȸ ������ �̵�, �ʿ�ÿ� ���� �߰� �� �� ����
int getAction(int (*map)[DIM]);//��� ������ �� ��ġ�� �ְų� ESCŰ�� ���������� ���� 0�� ��ȯ
                   // ����Ű�� ������ ���� �ش� Ű���� ��ȯ(LEFT, RIGHT, DOWN, UP)
                   //�ʿ�ÿ� �Ű����� ���ڸ� �߰��� �� ����

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


int main(void)
{
	int map[DIM][DIM];
	int action = Non;

	init(map);
	shuffle(50,map);
	gameDraw(map);
	action = getAction(map);
    while(action)
	{
      puzzleMove(map, action);
	  gameDraw(map); 
	  action = getAction(map);
	}

	cout << "The game is stopped" << endl;
	return 0;
}

void init(int (*map)[DIM])
{
	int num=1;

	//map �ʱ�ȭ
	for(int i=0;i < DIM ; i++)
		for(int j=0; j < DIM; j++)
			map[i][j] = num++;
	map[DIM-1][DIM-1]= 0;

	//����ð� ȹ��
	sTime = cTime = clock();
	x = y = 3; //0�� ��ǥ�� 
	srand(time(NULL));
}

void shuffle(int num, int (*map)[DIM])
{
	int temp;
	
	for(int i=0; i< num;i++)
	{
		temp = rand()%4 +1;
        puzzleMove(map,temp);
		gameDraw(map);
		Sleep(100);
	}
}

void gameDraw(int (*map)[DIM])
{
	gotoXY(MAP_STARTX, MAP_STARTY);
	cout << "   Fifteen Puzzle" << endl;
	
	for(int i=0; i< DIM; i++)
	{   
		gotoXY(MAP_STARTX, MAP_STARTY + i*2 + 2); 
		for(int j=0; j< DIM; j++)
		{
			if(map[i][j] != 0)
			{
				cout.width(4);
				cout << map[i][j];
			}
			else
			{
				cout.width(4);
				cout << '*';
			}
		}
		cout << endl;
	}

	cout << endl;
	gotoXY(  SCORE_STARTX, SCORE_STARTY);
	cout << "  �̵� ȸ��: " << moveNum << endl;
	gotoXY(  SCORE_STARTX, SCORE_STARTY+1);
	cTime = clock();
	cout << "  �ҿ� �ð�: " << (cTime-sTime)/1000.0 << "��" << endl;
}



void puzzleMove(int (*map)[DIM], int action)
{

	switch(action)
	{
		case Left:
   				  if(x > 0)  // ���� ��迡 �����ߴ��� üũ, ��迡 �����ϸ� ������ ��ġ�� �ٲ��� ����
				  {
					x--;
				    int temp = map[y][x];
				 	map[y][x] = map[y][x+1] ;
					map[y][x+1] = temp;
					moveNum++;
				  }
				  break;
		case Right:
   				  if(x < DIM-1) //���� ��迡 �����ߴ��� üũ, ��迡 �����ϸ� ������ ��ġ�� �ٲ��� ����
				  {
					x++;
				    int temp = map[y][x];
				 	map[y][x] = map[y][x-1] ;
					map[y][x-1] = temp;
					moveNum++;
				  }
				  break;
		case Up:
   				  if(y > 0) //��� ��迡 �����޴��� üũ, ��迡 �����ϸ� ������ ��ġ�� �ٲ��� ����
				  {
					 y--;
				     int temp = map[y][x];
				 	 map[y][x] = map[y+1][x] ;
					 map[y+1][x] = temp;
					 moveNum++;
				  }
				  break;
		case Down:
   				  if(y < DIM-1) // �ϴ� ��迡 �����ߴ��� üũ, ��迡 �����ϸ� ������ ��ġ�� �ٲ��� ���� 
				  {
					y++;
				    int temp = map[y][x];
				 	map[y][x] = map[y-1][x] ;
					map[y-1][x] = temp;
					moveNum++;
				  }
	}
}

int getAction(int (*map)[DIM])
{
    int num=1,command;

	// ������ �ϼ��Ǿ����� Ȯ��
	for(int i=0;i<DIM;i++)
	   for(int j=0;j< DIM; j++)
		   if(map[i][j] != num++)
			   break;
	if(num > DIM*DIM)  //���������� Ȯ�εǸ� ������ �ϼ���
	   return Stop;
	

    //����Ű�� ���� ��ɾ ����
	switch(getDirectKey())
	{
		case LEFT:
			      command = Left; 
				  break;
		case RIGHT:
   				  command = Right;
				  break;
		case UP:
			      command = Up;
				  break;
		case DOWN:
				  command = Down;
				  break;
		case ESC:
			      command = Stop;
				  break;
		default:
			      command = Non; // ����Ű�� ESCŰ �ܿ� �ٸ� Ű�� �������� �ƹ� ��ɾ �������� ����
	}

	return command;
}


//�ܼ� ȭ�鿡�� Ŀ���� Ư�� ��ġ�� �̵�
void gotoXY(int x, int y) 
{
 COORD Pos = {x, y};
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

// �׿� �Լ����� ������
