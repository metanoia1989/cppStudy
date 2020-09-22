#include <iostream>
#include <cstdio>

int addNumbers(int number1, int number2) 
{
    std::cout << "Entering function " << __func__ << std::endl;
    return number1 + number2;
}

int main() {
    enum PieceType { PieceTypeKing = 1, PieceTypeQueen, PieceTypeRook = 10, PieceTypePawn };
    PieceType myPiece;
    myPiece = PieceTypeKing;
    bool a = myPiece == 1;
    std::cout << a; // 输出 true 因为myPiece被隐式转换了

    enum class Piece2 { King, Queen, Book, Pawn };
    Piece2 myPiece2;
    myPiece2 = Piece2::King;
    // bool b = myPiece2 == myPiece; // 两种类型不一致，无法比较
    // std::cout << b;
    std::cout << addNumbers(1, 2);
}