#include <easyx.h>
#include <conio.h>

int main()
{
	initgraph(640, 480);	// �������ƴ���
	circle(200, 200, 100);	// ��ͼ Բ�ģ�200��200���뾶100
	_getch();	// �����������
	closegraph();	// �رջ��ƴ���
}