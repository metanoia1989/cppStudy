#include <easyx.h>
#include <conio.h>

int main()
{
	initgraph(640, 480);	// 创建绘制窗口
	circle(200, 200, 100);	// 画图 圆心（200，200）半径100
	_getch();	// 按任意键继续
	closegraph();	// 关闭绘制窗口
}