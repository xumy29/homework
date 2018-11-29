//2017年5月19日 21:06:33
//2017年5月22日 20:42:40
# include <stdio.h>
# include <string.h>
# include <windows.h>
# include <stdlib.h>
# include <conio.h>
# include <time.h>
# include <math.h>

# define de_lenth 5//蛇初始长度
# define ROW_MAX 20//地图行
# define LINE_MAX 30//地图列

int ROW = ROW_MAX;
int LINE = LINE_MAX;
int Head_x = ROW_MAX/2, Head_y = LINE_MAX/2;//蛇的初始坐标
int Head_v = 5;//判断是否为头
int Tail_x = 0, Tail_y = 0;//蛇尾坐标
int count = 0;//计数
char direct = 'a';//蛇移动的方向
int times = 1;

void SetUp(void);
void CreateMap(char map[ROW_MAX][LINE_MAX]);//创建地图
void CreateSnake(int snkae[ROW_MAX][LINE_MAX]);//构造蛇的初始位置
void CreateFood(char map[ROW_MAX][LINE_MAX], int snake[ROW_MAX][LINE_MAX]);//产生随机食物
void TraverseMap(char map[ROW_MAX][LINE_MAX], int snake[ROW_MAX][LINE_MAX]);//输出地图以及蛇的全部
int JudgeWall(void);//判断蛇是否撞墙
void MoveTail(int snake[ROW_MAX][LINE_MAX]);//蛇尾部的移动
int EatFood(char map[ROW_MAX][LINE_MAX]);//蛇吃到食物的操作
void run(char map[ROW_MAX][LINE_MAX], int snake[ROW_MAX][LINE_MAX]);//蛇的移动
void gotoxy(int x, int y);//将光标定位到某一位置, 用于显示结果, 以及暂停是使用
void Result(void);//显示结果
void dely(void);

int main()
{
    char map[ROW_MAX][LINE_MAX];
    int snake[ROW_MAX][LINE_MAX];
    char ch;
    srand(time(NULL));
/************设置*********************/   
    system("cls");
    printf("\tPress T/t to set up\n");
    printf("Press any other key to start!\n");
    ch = getch();

    if(ch == 'T' || ch == 't')
        SetUp();
/*************************************/

/**************初始画面**************/
    memset(map, 0, sizeof(map));
    memset(snake, 0, sizeof(snake));
    system("cls");
    CreateMap(map); 
//  gotoxy(1, 1);
    CreateSnake(snake);
    CreateFood(map, snake);
    TraverseMap(map, snake);
/**************初始画面**************/

/**********运动*****************/
    run(map, snake);
/*******************************/

/*************结果***************/
    Result();
/********************************/
    return 0;
}

void SetUp(void){

    char ch;
    int row;
    int line;
    int speed;
    system("cls");
    printf("\tSET UP\n");
    printf("1. speed\n");
    printf("2. area\n");
    printf("0. return\n");

    ch = getch();
    while(1){
        switch (ch){

        case '1':
            printf("The less the figure the faster speed level(1~8)\n");
            printf("Speed level: ");
            scanf("%d", &speed);
            times = speed>8? 8: speed<1? 1: speed;
            printf("The speed leve: %ld", times);
            break;
        case '2':
            printf("Update length and width(the max size is 80 x 80 and input 0 default)\n");
            printf("length: ");
            scanf("%d", &row);
            printf("width: ");
            scanf("%d", &line);

            if(line != 0 && row != 0){

                ROW = row+2;
                LINE = line+2;
                Head_x = ROW/2;
                Head_y = LINE/2;
            }
            printf("After updating length: %d\twidth: %d\n", row, line);

            break;

            default:
                return;
        }
        for(long i = 0; i < 400000000; ++i);
        //fflush(stdin);
        system("cls");
        printf("\tSET UP\n");
        printf("1. speed\n");
        printf("2. area\n");
        printf("0. return\n");

        ch = getch();
    }

}

void CreateMap(char map[ROW_MAX][LINE_MAX]){
//将行为0和ROW_MAX的位置赋值为'#', 以及列为0和LINE_MAX赋值为'#', 表示墙;
    int i, j;


    for(i = 0; i < ROW; ++i)
        map[i][0] = '#';
    for(j = 1; j < LINE; ++j)
        map[0][j] = '#';
    for(i = ROW-1, j = 1; j < LINE; ++j)
        map[i][j] = '#';
    for(j = LINE-1, i = 1; i < ROW; ++i)
        map[i][j] = '#';
}

void CreateSnake(int snake[ROW_MAX][LINE_MAX]){

    int i, j;
    int value = Head_v;
    snake[Head_x][Head_y] = value;

    for(i = Head_x, j = Head_y+1; j < Head_y + de_lenth; ++j)
        snake[i][j] = --value;
    Tail_x = i;
    Tail_y = --j;
}

void CreateFood(char map[ROW_MAX][LINE_MAX], int snake[ROW_MAX][LINE_MAX]){

    int food_x = 0;
    int food_y = 0;

    while (map[food_x][food_y] == '#' || snake[food_x][food_y] != 0){

        food_x = rand()%(ROW-3) + 1;
        food_y = rand()%(LINE-3) + 1;
    }

    map[food_x][food_y] = 'O';
}

void TraverseMap(char map[ROW_MAX][LINE_MAX], int snake[ROW_MAX][LINE_MAX]){

    int i, j;

    for (i = 0; i < ROW; ++i){
        for (j = 0; j < LINE; ++j){
            if(snake[i][j] == 0)
                printf("%c", map[i][j]);
            else{
                if(snake[i][j] == Head_v)
                    putchar('Q');
                else
                    putchar('a');               
            }
        }
        putchar('\n');
    }
}

int JudgeWall(void){

    if((Head_x == 0 || Head_x == ROW-1) || (Head_y == 0 || Head_y == LINE-1))
        return 0;
    else 
        return 1;
}



void MoveTail(int snake[ROW_MAX][LINE_MAX]){

    if (snake[Tail_x][Tail_y]+1 == snake[Tail_x-1][Tail_y]){

        snake[Tail_x][Tail_y] = 0;
        Tail_x--;
    }
    else if (snake[Tail_x][Tail_y]+1 == snake[Tail_x+1][Tail_y]){

        snake[Tail_x][Tail_y] = 0;
        Tail_x++;
    }
    else if (snake[Tail_x][Tail_y]+1 == snake[Tail_x][Tail_y-1]){

        snake[Tail_x][Tail_y] = 0;
        Tail_y--;
    }
    else{

        snake[Tail_x][Tail_y] = 0;
        Tail_y++;
    }
}

int EatFood(char map[ROW_MAX][LINE_MAX]){

    if(map[Head_x][Head_y] == 'O'){

        map[Head_x][Head_y] = 0;
        count++;
        return 0;
    }
    else
        return 1;
}

void run(char map[ROW_MAX][LINE_MAX], int snake[ROW_MAX][LINE_MAX]){
/*
上   -32 0xffffffe0 72 H
下   -32 0xffffffe0 80 P
左   -32 0xffffffe0 75 K
右   -32 0xffffffe0 77 M
*/
    char sh, ch;
    while(1){

        if(JudgeWall()){
        /**********判断键盘是否敲击***********/
            if (kbhit()){

                ch = getch();
                if (ch == -32){

                    sh = getch();
                    if(direct == 'w'){

                        if(sh == 'P')
                            continue;
                    }
                    else if (direct == 's'){

                        if(sh == 'H')
                            continue;
                    }
                    else if (direct == 'a'){

                        if(sh == 'M')
                            continue;
                    }
                    else{

                        if(sh == 'K')
                            continue;
                    }

                    switch (sh){

                        case 'H': direct = 'w'; break;
                        case 'P': direct = 's'; break;
                        case 'K': direct = 'a'; break;
                        case 'M': direct = 'd'; break;              
                    }
                }
                else{

                    if(direct == 'w'){

                        if(ch == 's' || ch == 'S')
                            continue;
                    }
                    else if (direct == 's'){

                        if(ch == 'w' || ch == 'W')
                            continue;
                    }
                    else if (direct == 'a'){

                        if(ch == 'd' || ch == 'D')
                            continue;
                    }
                    else if (direct == 'd'){

                        if(ch == 'a' || ch == 'A')
                            continue;
                    }

                    switch (ch){

                    case 'w':case 'W': direct = 'w'; break;
                    case 's':case 'S': direct = 's'; break;
                    case 'a':case 'A': direct = 'a'; break;
                    case 'd':case 'D': direct = 'd'; break;
                    case 27:
                        int i, j;
                        for(i = ROW/2-1; i <= ROW/2+1; ++i){
                                gotoxy(0, i);
                                for(j = 0; j <= LINE; ++j)
                                    putchar(' ');
                        }

                        gotoxy(LINE/2-8<0?0:LINE/2-8, ROW/2);
                        system("pause");

                        break;

                    }
                }               
            }
        /************************************/

        /**************蛇的运动******************/
            switch (direct){

                case 'w':
                    if(snake[Head_x-1][Head_y] != 0)
                        return;

                    snake[Head_x-1][Head_y] = ++Head_v;
                    Head_x--;
                    if(EatFood(map))
                        MoveTail(snake);
                    else
                        CreateFood(map, snake);
                    break;
                case 'a':
                    if(snake[Head_x][Head_y-1] != 0)
                        return;

                    snake[Head_x][Head_y-1] = ++Head_v;
                    Head_y--;
                    if(EatFood(map))
                        MoveTail(snake);
                    else
                        CreateFood(map, snake);
                    break;
                case 's':
                    if(snake[Head_x+1][Head_y] != 0)
                        return;

                    snake[Head_x+1][Head_y] = ++Head_v;
                    Head_x++;
                    if(EatFood(map))
                        MoveTail(snake);
                    else
                        CreateFood(map, snake);
                    break;                  
                case 'd': 
                    if(snake[Head_x][Head_y+1] != 0)
                        return;

                    snake[Head_x][Head_y+1] = ++Head_v;
                    Head_y++;
                    if(EatFood(map))
                        MoveTail(snake);
                    else
                        CreateFood(map, snake);
                    break;          
            }
            system("cls");
            TraverseMap(map, snake);
        /****************************************/
        }
        else
            return;
        dely();
    }
}



void gotoxy(int x, int y)
{
    CONSOLE_SCREEN_BUFFER_INFO    csbiInfo;                            
    HANDLE    hConsoleOut;
    hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsoleOut,&csbiInfo);
    csbiInfo.dwCursorPosition.X = x;                                    
    csbiInfo.dwCursorPosition.Y = y;                                    
    SetConsoleCursorPosition(hConsoleOut,csbiInfo.dwCursorPosition); 
}

void Result(void){
    int i, j;
    for(i = ROW/2-2; i <= ROW/2+1; ++i){
        gotoxy(0, i);
        for(j = 0; j <= LINE; ++j)
            putchar(' ');
    }
    gotoxy(LINE/2-4<0?0:LINE/2-4, ROW/2-1);
    printf("The end!\n");
    gotoxy(LINE/2-8<0?0:LINE/2-8, ROW/2);
    printf("Your score is %d\n", count);
    gotoxy(0,ROW);
    printf("Press any key to quit\n");
    printf("Thank you!\n");
    getch();
}

void dely (void){

    for(long i = 0; i <= pow(16, times); ++i)
        ;
}

