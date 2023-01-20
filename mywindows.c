#include "mywindows.h"
//1.获取句柄 初始化
HANDLE handle;  //全局变量
void initHandle()
{
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
}
//2.获取光标位置
void setPos(int x, int y)
{
    COORD pos = {x*2,y};
    SetConsoleCursorPosition(handle, pos);
}
//3.设置文字颜色（前景色，背景色）
void setColor(int color)
{
    SetConsoleTextAttribute(handle, color);
}
//4.设置光标是否可见
void setCursorVisible(int flag)
{
    CONSOLE_CURSOR_INFO info; //光标信息结构体
    info.bVisible = flag; //光标是否可见
    info.dwSize = 100; //光标宽度1-100
    SetConsoleCursorInfo(handle,&info);
}
//5.设置窗口标题
void setTitle(char title[40])
{
    SetConsoleTitle(title);
}
//6.关闭句柄
void closeHandle()
{
    CloseHandle(handle);
}

