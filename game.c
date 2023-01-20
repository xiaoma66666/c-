#include "game.h"
#include "mywindows.h"
#include "data.h"
#include <conio.h>
#include <time.h>

//定义当前方块和下一个方块
Block block_cur;
Block block_next;

// 碰撞检测 基于下一个位置的检测
int crash(int x, int y, int shape, int status)
{
    int i,j;
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            if(blockShape[shape][status][i][j] == 1)
            {
                if(windowShape[i+y][j+x-15] == 1)
                {
                    //发生碰撞
                    if(block_cur.x == 22 && block_cur.y == 1)
                    {
                        //方块一产生就发生了碰撞
                        return -2;
                    }
                    return -1;
                }
            }
        }
    }
    return 0;
}

// 产生第一个方块
void startBlock()
{
    srand((unsigned)time(NULL)); //设置随机数种子
    block_cur.x = 22;
    block_cur.y = 1;
    block_cur.shape = rand()%7;
    block_cur.status = rand()%4;
    block_cur.color = rand()%0x10; //16进制的16
    if(block_cur.color == 0x00)
    {
        block_cur.color = 0x0f;
    }
    printBlock(block_cur.x,block_cur.y,block_cur.shape,block_cur.status,block_cur.color);
}

// 随机产生下一个方块
void randBlock()
{
    deleteBlock(block_next.x, block_next.y, block_next.shape,block_next.status);
    block_next.x = 33;
    block_next.y = 2;
    block_next.shape = rand()%7;
    block_next.status = rand()%4;
    block_next.color = rand()%0x10;
    if(block_next.color == 0x00)
    {
        block_next.color = 0x0f;
    }
    printBlock(block_next.x,block_next.y,block_next.shape,block_next.status,block_next.color);
}

// 拷贝方块 -->当前方块=下一个方块，并产生新的下一个方块
void copyBlock()
{
    deleteBlock(block_next.x, block_next.y, block_next.shape,block_next.status);
    block_cur = block_next;
    block_cur.x = 22;
    block_cur.y = 1;
    printBlock(block_cur.x,block_cur.y,block_cur.shape,block_cur.status,block_cur.color);
    randBlock(); //随机产生下一个方块
}

//1.绘制界面提示信息等
void printInfo()
{
    //1.设置颜色
    setColor(0x0f); //0黑色 没颜色
    //2.设置位置
    setPos(31,9);
    //3.打印
    printf("操作规则：");
    setColor(0x0c);
    setPos(32,11);
    printf("按A或<-左移");
    setPos(32,12);
    printf("按D或->右移");
    setPos(32,13);
    printf("按s或S加速下落");
    setPos(32,14);
    printf("按W或w变形");
    setPos(32,15);
    printf("按空格暂停");
    setPos(32,16);
    printf("按回车落底");
}
//2.打印游戏池边框
void printGamePool(int x, int y)
{
    int i,j;
    for(i=0; i<25; i++)
    {
        for(j=0; j<26; j++)
        {
            if(windowShape[i][j] == 1)
            {
                setColor(0xc0);
                setPos(x+j,y+i);
                //打印两个空格
                printf("  ");
            }
        }
    }
}

//3.打印分数 消除一行加10分
int score = 0;
void printGL(int num)
{
    switch(num)
    {
    case 0:
        break;
    case 1:
        score += 10;
        break;
    case 2:
        score += 30;
        break;
    case 3:
        score += 50;
        break;
    case 4:
        score += 80;
        break;
    }
    setColor(0x0b);
    setPos(3,25);
    printf("分数:%d", score);
}

//4.打印方块
void printBlock(int x, int y, int shape, int status, int color)
{
    int i,j;
    setColor(color);
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            if(blockShape[shape][status][i][j] == 1)
            {
                setPos(x+j,y+i);
                printf("■");
            }
        }
    }
}
//5.清除方块
void deleteBlock(int x, int y, int shape, int status)
{
    int i,j;
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            if(blockShape[shape][status][i][j] == 1)
            {
                setPos(x+j,y+i);
                printf("  ");
            }
        }
    }
}
//6.游戏初始化函数
void initGame()
{
    initHandle();
    printAnimation();
    setCursorVisible(0);
    printInfo();
    printGamePool(15,0);
    printGL(0);
    startBlock();
    randBlock();
    clock_t startTime = clock();
    clock_t stopTime;

    while(1)
    {
        //检测是否有按键按下
        if(kbhit())
        {
            switch(getch())
            {
            case 'w':
            case 'W':
            case 72:
                blockChange();
                break;
            case 'a':
            case 'A':
            case 75:
                blockLeft();
                break;
            case 'd':
            case 'D':
            case 77:
                blockRight();
                break;
            case 's':
            case 'S':
            case 80:
                blockDown();
                break;
            case 32:
                pause();
                break;
            case 13:
                blockBottom();
                break;
            }
        }
        stopTime = clock();
        // 方块每0.45s下落一次 //两个时间做差值
        if(stopTime-startTime>0.45*CLOCKS_PER_SEC)
        {
            if(blockDown() == -2)
            {
                break;
            }
            startTime = stopTime;
        }
    }
    printOver();
    printFinish();
}

//7.方块左移
void blockLeft()
{
    if(crash(block_cur.x-1,block_cur.y,block_cur.shape,block_cur.status) == -1)
    {
        return;
    }
    //删除方块
    deleteBlock(block_cur.x,block_cur.y,block_cur.shape,block_cur.status);
    //改变坐标
    block_cur.x -= 1;
    //重新打印
    printBlock(block_cur.x,block_cur.y,block_cur.shape,block_cur.status,block_cur.color);
}

//8.方块右移
void blockRight()
{
    if(crash(block_cur.x+1,block_cur.y,block_cur.shape,block_cur.status) == -1)
    {
        return;
    }
    //删除方块
    deleteBlock(block_cur.x,block_cur.y,block_cur.shape,block_cur.status);
    //改变坐标
    block_cur.x += 1;
    //重新打印
    printBlock(block_cur.x,block_cur.y,block_cur.shape,block_cur.status,block_cur.color);
}

//9.方块加速下落
int blockDown()
{
    if(crash(block_cur.x,block_cur.y+1,block_cur.shape,block_cur.status) == -1)
    {
        //重新产生下一个方块
        saveBlock();
        lineClear();
        copyBlock();
        updateGame();
        return -1;
    }
    else if(crash(block_cur.x,block_cur.y+1,block_cur.shape,block_cur.status) == -2)
    {
        //游戏该结束了
        return -2;
    }
    //删除方块
    deleteBlock(block_cur.x,block_cur.y,block_cur.shape,block_cur.status);
    //改变坐标
    block_cur.y += 1;
    //重新打印
    printBlock(block_cur.x,block_cur.y,block_cur.shape,block_cur.status,block_cur.color);

}

//10.方块变形
void blockChange()
{
    if(crash(block_cur.x,block_cur.y,block_cur.shape,block_cur.status+1) == -1)
    {
        return;
    }
    else
    {
        //删除方块
        deleteBlock(block_cur.x,block_cur.y,block_cur.shape,block_cur.status);
        //改变形态
        block_cur.status = (block_cur.status+1)%4;
        //重新打印
        printBlock(block_cur.x,block_cur.y,block_cur.shape,block_cur.status,block_cur.color);
    }
}

//11.方块落底
void blockBottom()
{
    while(1)
    {
        //流程与方块下落一致
        if(crash(block_cur.x,block_cur.y+1,block_cur.shape,block_cur.status) == -1)
        {
            //重新产生下一个方块
            saveBlock();
            lineClear();
            copyBlock();
            updateGame();
            return;
        }
        else if(crash(block_cur.x,block_cur.y+1,block_cur.shape,block_cur.status) == -2)
        {
            //游戏结束 游戏结束动画 提示
            return;
        }
        else
        {
            ++block_cur.y;
        }
    }
}

//12.游戏暂停
void pause()
{
    while(1)
    {
        if(getch() == 32)
        {
            break;
        }
    }
}

// 保存方块
void saveBlock()
{
    int i,j;
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            if(blockShape[block_cur.shape][block_cur.status][i][j] == 1)
            {
                windowShape[i+block_cur.y][j+block_cur.x-15] = 1;
            }
        }
    }
}

//刷新游戏区域
void updateGame()
{
    int i,j;
    for(i=1; i<24; i++)
    {
        for(j=1; j<15; j++)
        {
            if(windowShape[i][j] == 1)
            {
                setColor(0x0e);
                setPos(j+15,i);
                printf("■");
            }
            else
            {
                setColor(0x00);
                setPos(j+15,i);
                printf("%2s","");
            }
        }
    }
}

//消行检测
void lineClear()
{
    int i,j;
    int number = 0;
    for(i=23; i>1; i--)
    {
        int total = 0;
        for(j=1; j<15; j++)
        {
            total += windowShape[i][j];
        }
        if(total == 14)
        {
            lineDown(i);
            i+=1;
            number += 1;
        }
    }
    printGL(number);
}

//消行下移
void lineDown(int line)
{
    int i,j;
    for(i=line; i>1; i--)
    {
        for(j=1; j<15; j++)
        {
            windowShape[i][j] = windowShape[i-1][j];
        }
    }
}

//游戏结束动画
void printOver()
{
    int i,j;
    for(i=23; i>0; i--)
    {
        for(j=14; j>0; j--)
        {
            setColor(0x76);
            setPos(j+15,i);
            printf("★");
            Sleep(5);
        }
    }
}

//重新开始提示
void printFinish()
{
    setColor(0x0d);
    setPos(21,8);
    printf("游戏结束！");
    setPos(17,9);
    printf("按Y重新开始！");
    setPos(24,9);
    printf("按N结束游戏！");
    switch(getch())
    {
    case 'Y':
    case 'y':
        againGame();
        break;
    case 'N':
    case 'n':
        break;
    case 13:
        printFinish();
        break;
    default:
        printFinish();
        break;
    }
}

//重新开始
void againGame()
{
    setColor(0x00);
    system("cls"); //清屏
    //初始化游戏池
    int i,j;
    for(i=1; i<24; i++)
    {
        for(j=1; j<15; j++)
        {
            windowShape[i][j] = 0;
        }
    }
    initGame();
}

//打印开始界面
void printStart(int x, int y)
{
    int color = rand()%0x10;
    if(color == 0x00)
    {
        color = 0x0f;
    }
    setColor(color);
    setPos(x,y);
    printf("■■■■■ ■■■■■ ■■■■■ ■■■■ ■■■ ■■■■");
    setPos(x,y+1);
    printf("■ ■ ■ ■ ■ ■ ■");
    setPos(x,y+2);
    printf("■ ■■■■ ■ ■■■■ ■ ■■■");
    setPos(x,y+3);
    printf("■ ■ ■ ■ ■ ■ ■");
    setPos(x,y+4);
    printf("■ ■■■■■ ■ ■ ■ ■■■ ■■■■");
    setPos(20,15);
    printf("按任意键开始游戏吧！！！！");
}

//清除开始动画
void clearStart(int x, int y)
{
    int i,j;
    for(i=y; i<=y+4; i++)
    {
        for(j=x; j<=x+33; j++)
        {
            setPos(j,i);
            printf(" ");
        }
    }
}

//动画
void printAnimation()
{
    clock_t time1,time2;
    time1 = clock();
    int x = 5;
    printStart(x,5);
    while(1)
    {
        time2 = clock();
        if(time2-time1 > 300)
        {
            time1 = time2;
            clearStart(x,5);
            printStart(++x,5);
            if(x==25)
            {
                clearStart(x,5);
                x=0;
            }
        }
        //检查当前是否有键盘输入，若有 则返回一个非0值，否则返回0
        if(kbhit())
        {
            break;
        }
    }
    system("cls");
}

