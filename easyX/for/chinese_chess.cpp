#include <graphics.h>
#include <string>
#include <stdlib.h>

//***********************************************************
// 绘制中国象棋的棋盘
// 绘制比较简单，横线+竖线、帅周围格子的交叉线、以及卒和炮的小折线  
// 棋子绘制，可以有两种形式，形式1是边框和文字，形式2是填充和镂空   
// 但是游戏机制就比较复杂的，没有规则的棋子移动很简单，各个棋子都有
// 其移动的规则，=_= 也就是整个棋盘的坐标都要记忆住
// 棋子跟棋子的规则编写单独的类，可以自动组合   
// 先进行绘制处理，后期再进行规则的编写 
// 
// 将棋盘的点存到一个二维数组里，那个点有棋子就为1，
// 然后棋子本身保存坐标，以马来说，能走的坐标为以日字规则进行迭代   
// 加上蹩脚机制，判断能走的点，哈哈，有点感觉了 
//***********************************************************

/**
 * 象棋棋子，传入棋子文字以及颜色
 */ 
class Chessman
{
public:
    Chessman(std::string chessName) 
        : m_chessName(chessName) {}
                                    
    /**
     * 绘制棋子，边框+文字，但是这个图形库的绘制都是以整个棋盘的左上角为坐标的
     * 单个棋子要怎么处理呢？先设置中心坐标，然后再这个坐标上进行绘制吗？
     * 感觉有点难，算了，先弄简单的好了，只是绘制棋盘。 
     */ 
    void draw() 
    {
        
    }
        
private:
    std::string m_chessName;
};

/**
 * 棋盘
 * 每个单元格 50x50
 * 宽高 400x450 
 * 外边距 10 
 */ 
class ChessBoard
{
public:
    /**
     * 绘制象棋棋盘
     */ 
    void draw()
    {
        initgraph(440, 490);
        fillrectangle(10, 10, 430, 480);
        drawCell();
        drawCrossLine();
        
        system("pause");
        closegraph();
    }
    
    /**
     * 绘制单元格
     */ 
    void drawCell()
    {
        setlinecolor(BLACK);
        rectangle(20, 20, 420, 470);
        // 画竖线
        for (int x = 20; x <= 420; x += 50) {
            line(x, 20, x, 220); 
            line(x, 270, x, 470); 
        } 
        // 画横线
        for (int y = 20; y <= 470; y += 50) {
            line(20, y, 420, y); 
        } 
    }
    
    /**
     * 绘制帅所在田字框的交叉线
     */ 
    void drawCrossLine()
    {
        line(170, 20, 270, 120);
        line(170, 120, 270, 20);

        line(170, 370, 270, 470);
        line(170, 470, 270, 370);
    }

};

int main(int argc, char const *argv[])
{
    auto chess = ChessBoard();
    chess.draw();

    return 0;
}
