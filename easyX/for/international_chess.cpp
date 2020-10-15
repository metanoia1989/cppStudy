#include <graphics.h>
#include "Resource.h"
#include <stdlib.h>
#include <iostream>

//******************************************************************
// 绘制国际象棋
// 8x8 然后每个相邻的单元格颜色都不同
//******************************************************************


class ChessBoard
{
public:
    /**
     * 绘制象棋棋盘
     */ 
    void draw()
    {
        initgraph(400, 400);

        drawCell();    
        drawChessMan();

        system("pause");
        closegraph();
    }

    /**
     * 绘制单元格
     */ 
    void drawCell()
    {
        for (int x = 0; x < 400; x += 50) {
            for (int y = 0; y < 400; y += 50) {
                int stepX = x / 50  % 2; 
                int stepY = y / 50 % 2; 
                // 浅色的单元格：stepX 为奇数，stepY 为奇数； stepX 为偶数，stepY 为偶数；
                // 深色的单元格：stepX 为奇数，stepY 为偶数； stepX 为偶数，stepY 为奇数；
                if (stepX == 1 && stepY == 1 || stepX == 0 && stepY == 0) { // 浅色
                    setfillcolor(0xEBECD0); 
                } else { // 深色
                    setfillcolor(0x779556); 
                }
                fillrectangle(x, y, x+50, y+50);
            } 
        } 
    }
    
    /**
     * 绘制棋子
     */ 
    void drawChessMan()
    {
        IMAGE img;

        // 绘制兵棋
        loadimage(&img, _T("IMAGE"), MAKEINTRESOURCE(CHESS_PAWN1), 50, 50); 
        for (int x = 0; x < 400; x+=50) {
            putimage(x, 50, &img);
        }
    }
};




int main(int argc, char const *argv[])
{
    auto chess = ChessBoard();
    chess.draw();

    return 0;
}


