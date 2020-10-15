#include <graphics.h>
#include "Resource.h"
#include <stdlib.h>
#include <iostream>

//******************************************************************
// 绘制国际象棋
// 8x8 然后每个相邻的单元格颜色都不同
//******************************************************************

void transparentimage(IMAGE *dstimg, int x, int y, IMAGE *srcimg);

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
        IMAGE img1, img2;

        // 绘制兵棋
        loadimage(&img1, _T("IMAGE"), MAKEINTRESOURCE(CHESS_PAWN1), 50, 50); 
        loadimage(&img2, _T("IMAGE"), MAKEINTRESOURCE(CHESS_PAWN2), 40, 37); 
        for (int x = 0; x < 400; x+=50) {
            transparentimage(nullptr, x - 5, 50, &img1);
            transparentimage(nullptr, x + 5 , 305, &img2);
        }
        // 绘制车棋
        loadimage(&img1, _T("IMAGE"), MAKEINTRESOURCE(CHESS_ROOK1), 50, 50); 
        loadimage(&img2, _T("IMAGE"), MAKEINTRESOURCE(CHESS_ROOK2), 40, 40); 
        transparentimage(nullptr, 0, 0, &img1);
        transparentimage(nullptr, 0, 355, &img2);
        transparentimage(nullptr, 250, 0, &img1);
        transparentimage(nullptr, 250, 355, &img2);

        // 绘制马棋
        loadimage(&img1, _T("IMAGE"), MAKEINTRESOURCE(CHESS_KNIGHT1), 50, 50); 
        loadimage(&img2, _T("IMAGE"), MAKEINTRESOURCE(CHESS_KNIGHT2), 40, 40); 
        transparentimage(nullptr, 50, 0, &img1);
        transparentimage(nullptr, 50, 355, &img2);
        transparentimage(nullptr, 300, 0, &img1);
        transparentimage(nullptr, 300, 355, &img2);
        
        // 绘制象棋
        loadimage(&img1, _T("IMAGE"), MAKEINTRESOURCE(CHESS_BISHOP1), 50, 50); 
        loadimage(&img2, _T("IMAGE"), MAKEINTRESOURCE(CHESS_BISHOP2), 40, 40); 
        transparentimage(nullptr, 100, 0, &img1);
        transparentimage(nullptr, 100, 355, &img2);
        transparentimage(nullptr, 350, 0, &img1);
        transparentimage(nullptr, 350, 355, &img2);
        
        // 绘制国王
        loadimage(&img1, _T("IMAGE"), MAKEINTRESOURCE(CHESS_KING1), 50, 50); 
        loadimage(&img2, _T("IMAGE"), MAKEINTRESOURCE(CHESS_KING2), 40, 40); 
        transparentimage(nullptr, 150, 0, &img1);
        transparentimage(nullptr, 150, 355, &img2);
       
        // 绘制皇后
        loadimage(&img1, _T("IMAGE"), MAKEINTRESOURCE(CHESS_QUEUE1), 50, 50); 
        loadimage(&img2, _T("IMAGE"), MAKEINTRESOURCE(CHESS_QUEUE2), 40, 40); 
        transparentimage(nullptr, 200, 0, &img1);
        transparentimage(nullptr, 200, 355, &img2);
    }
};

/**
 * 半透明贴图函数
 *
 * @param  {IMAGE*} dstimg 目标IMAGE对象指针，NULL表示默认窗体
 * @param  {int} x, y 目标贴图位置
 * @param  {IMAGE*} srcimg 源IMAGE对象指针，NULL表示默认窗体
 */
void transparentimage(IMAGE *dstimg, int x, int y, IMAGE *srcimg)
{
    HDC dstDC = GetImageHDC(dstimg);    
    HDC srcDC = GetImageHDC(srcimg);    
    int w = srcimg->getwidth();
    int h = srcimg->getheight();
    
    // 结构体的第三个成员表示额外的透明度，0表示全透明，255表示不透明
    BLENDFUNCTION bf = { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA };
    // 使用 Windows GDI 函数实现半透明位图
    AlphaBlend(dstDC, x, y, w, h, srcDC, 0, 0, w, h, bf);
}



int main(int argc, char const *argv[])
{
    auto chess = ChessBoard();
    chess.draw();

    return 0;
}


