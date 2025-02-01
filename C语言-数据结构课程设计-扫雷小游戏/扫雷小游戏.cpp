#include <easyx.h>
#include <stdio.h>

int ROW;
int  COL;
int  IMG_SIZE= 40;
int  MINE_NUM;

IMAGE img[16];
int mine[100][100]={0};
int num = 0;
int nums = 0;
int mx;
int my;
int level = 1; // Ĭ���Ѷ�Ϊ��

int startTime;
int endTime;
int gameTime;

int gameLevel()
{
	// ��ȡ��Ļ��Ⱥ͸߶�
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);
	
	HWND hWnd = initgraph(258 * 1, 72 * 3);
	if (hWnd == NULL) 
	{
	    printf("ͼ�γ�ʼ��ʧ�ܣ�\n");
	    return -1; 
	}
	
	// ���㴰�����Ͻǵ�λ�ã�ȷ����������Ļ����
	int windowX = (screenWidth - 258 ) / 2;
	int windowY = (screenHeight - 72 * 3) / 2;
	
	// �ƶ����ڵ��������λ��
	MoveWindow(GetHWnd(), windowX, windowY, 258 * 1, 72 * 3+25, TRUE);
	
	putimage(0, 0, &img[12]);
	putimage(0, 72*1, &img[13]);
	putimage(0, 72*2, &img[14]);
	ExMessage em;
	
	while (true) 
	{
	    if (peekmessage(&em, EX_MOUSE)) 
		{
	        int y = em.y / 72;
	        if (em.lbutton)
			{
	        	if (y >= 0 && y < 3) 
				{
	            level = y + 1;
	            printf("%d",level);
	            break;	
				}
	        }
	    }
	}
	closegraph();
	return level;
}


void gameInita()
{
	int row, col;
	
	// ��ȡ��Ļ��Ⱥ͸߶�
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);
	
	// ������Ϸ����
	initgraph(IMG_SIZE * ROW, IMG_SIZE * (COL+2));
	
	// ���㴰�����Ͻǵ�λ�ã�ȷ����������Ļ����
	int windowX = (screenWidth - IMG_SIZE * ROW) / 2;
	int windowY = (screenHeight - IMG_SIZE * COL) / 2;
	
	// �ƶ����ڵ��������λ��
	MoveWindow(GetHWnd(), windowX, windowY, IMG_SIZE * ROW, IMG_SIZE * COL+25+IMG_SIZE*2, TRUE);
	
	// ����
	for (int i = 0; i < MINE_NUM;) 
	{
		row = rand() % ROW + 1;
		col = rand() % COL + 1;
		if (mine[row][col] == 0) 
		{
		  mine[row][col] = 9;
		  i++;
		}
	}
	// �Ź���������
	for (int i = 1; i <= ROW; i++) 
	{
		for (int j = 1; j <= COL; j++) 
		{
		  if (mine[i][j] == 9) 
		  {
		  	// ��������Χ�ľŹ���
		    for (int a = i - 1; a <= i + 1; a++) 
			{
		      for (int b = j - 1; b <= j + 1; b++) 
			  {
			  	// ���׵ĸ��ӣ���һ
		        if (mine[a][b] != 9) 
				{
		          mine[a][b]++;
		        }
		      }
		    }
		  }
		}
	}
	
	// ���ڵ�ͼ
	for (int i = 1; i < ROW + 1; i++) 
	{
		for (int j = 1; j < COL + 1; j++) 
		{
		  mine[i][j] += 20;
		}
	}
	
	// ��¼��Ϸ��ʼʱ��
	startTime = GetTickCount();
}


void gameInit() 
{
	for(int a =0;a<100;a++)
	{
		for(int b =0;b<100;b++)
		{
			mine[a][b]=0;
		}
	}
	char buf[260] = "";
	
	// ������Ϸ��Դ
	for (int i = 0; i < 16; i++) 
	{
		memset(buf, 0, sizeof(buf));
		sprintf(buf, "./img/%d.jpg", i);
		
		// ����ͼƬ
		if(i<12)
		{
			loadimage(&img[i], buf, IMG_SIZE, IMG_SIZE);
		}
		else if(i < 15 && i > 11)
		{
			loadimage(&img[i], buf, 258, 72);
		}
		else if(i == 15)
		{
			loadimage(&img[i], buf, 120, 40);
		}
	}
	
	//��Ϸ�Ѷ� 
	int a=gameLevel();
	level = a;
	
	if(a==1)
	{
		ROW= 9;
		COL= 9;
		MINE_NUM= 18;
		gameInita();
	}
	else if(a==2)
	{
		ROW= 15;
		COL= 10;
		MINE_NUM= 50;
		gameInita();
	}
	else if(a==3)
	{
		ROW= 30;
		COL= 20;
		MINE_NUM= 100;
		gameInita();
	}
}


void gameDraw() 
{
	num=0;
	nums=0;
	for (int i = 1; i < ROW + 1; i++) 
	{
		for (int j = 1; j < COL + 1; j++) 
		{
			
		  int x = (i - 1) * IMG_SIZE;
		  int y = (j - 1) * IMG_SIZE;
		  
		  if (mine[i][j] >= 0 && mine[i][j] <= 9) 
		  {
		    putimage(x, y, &img[mine[i][j]]);
		    num++;
		  } 
		  else if (mine[i][j] >= 20 && mine[i][j] < 30) 
		  {
		    putimage(x, y, &img[10]);//�ո� 
		    num++;
		  } 
		  else if (mine[i][j] > 29) 
		  {
		    putimage(x, y, &img[11]);//���� 
		    nums++;
		  }
		}
	}
	putimage(0, COL * IMG_SIZE, &img[15]);
	// ������Ϸ����ʱ��
	gameTime = GetTickCount() - startTime;
	
	// ������ʱ��ת��Ϊ���Ӻ���
	int minutes = gameTime / 60000;
	int seconds = (gameTime % 60000) / 1000;
	
	// ����ʱ��
	setbkcolor(RGB(173, 216, 230));
	settextcolor(RGB(255, 0, 0));
	char timeStr[20];
	sprintf(timeStr, "%02d:%02d", minutes, seconds);
	settextstyle(40, 23, _T("Consolas")); // ����������ʽ�ʹ�С
	
	// �ڴ��ڵ����½���ʾʱ��
	outtextxy(IMG_SIZE * ROW - 120, IMG_SIZE*COL, timeStr); 
	
	// �����ַ���
	setbkcolor(RGB(0, 0, 0));
	settextcolor(RGB(255, 0, 0));
	char displayStr[100]; 
	
	if(level == 1)
	{
		strcpy(displayStr, "ɨ��");
	}
	else if(level == 2)
	{
		strcpy(displayStr, "ɨ����Ϸ");
	}
	else if(level == 3)
	{
		strcpy(displayStr, "ɨ����Ϸ����ģʽ");
	}
	
	settextstyle(40, 20, _T("Consolas")); 
	
	// ������Ϸ���·����м�λ��
	int textX = (IMG_SIZE * ROW - textwidth(displayStr)) / 2; 
	int textY = IMG_SIZE * COL; 
	
	outtextxy(textX, textY, displayStr); 
	
	setbkcolor(RGB(173, 216, 230));
	settextcolor(RGB(255, 0, 0));
	char disStr[100]; 
	int a;
	a=MINE_NUM - nums;
	sprintf(disStr, "��ʣ%d����",a);
	settextstyle(40, 20, _T("Consolas")); 
	
	outtextxy(0, IMG_SIZE*(COL+1), disStr); 
}


void openNUll(int r, int c) 
{
	// �հ�����
	if (mine[r][c] == 0) 
	{
		for (int i = r - 1; i <= r + 1; ++i) 
		{
		  for (int j = c - 1; j <= c + 1; ++j) 
		  {
		    if ((mine[i][j] == 20 || mine[i][j] != 29) && mine[i][j] > 9)
			{
		      mine[i][j] -= 20;
		      openNUll(i, j);
		    }
		  }
		}
	}
}


void mouseClick() 
{
	ExMessage em;
	if (peekmessage(&em, EX_MOUSE)) 
	{
		mx = em.x / IMG_SIZE + 1;
		my = em.y / IMG_SIZE + 1;
		
		if (em.lbutton) 
		{		
			
			if((mx==1&&my==COL+1)||(mx==2&&my==COL+1)||(mx==3&&my==COL+1))
			{
				// ��Ϸ��ʼ��
				gameInit();
			}
			  if (mine[mx][my] > 9) 
			  {
			    mine[mx][my] -= 20;
			    openNUll(mx, my);
			  }
		} 
		else if (em.rbutton) 
		{
		  if (mine[mx][my] > 9 && mine[mx][my] <= 29) 
		  {
			mine[mx][my] += 20;
		  } 
		  else 
		  {
		    mine[mx][my] -= 20;
		  }
		}
	}
}


void isOver() {
	if (mine[mx][my] == 9) 
	{
		int ok = MessageBox(GetHWnd(), "�Ƿ����", "������", MB_OKCANCEL);
		if (ok == IDOK) 
		{
			closegraph();
			gameInit(); 
		} 
		else 
		{
			closegraph();
			exit(-1);
		}
	}
	
	if (num == ROW * COL - MINE_NUM&&nums==MINE_NUM) 
	{
		int ok = MessageBox(GetHWnd(), "��ϲ��ɹ������Ƿ����", "��ʾ", MB_OKCANCEL);
		if (ok == IDOK) 
		{
			closegraph();
			gameInit();
		} else 
		{
			closegraph();
			exit(0);
		}
	}
}

int main() 
{
	// ��Ϸ��ʼ��
	gameInit();
	
	while (true) 
	{
		// �û��������
		mouseClick();
		// ��Ϸ����
		gameDraw();
		// �ж���Ϸ�Ƿ����
		isOver();
	}
	return 0;
}
