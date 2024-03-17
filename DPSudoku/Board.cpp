#include "Board.h"

Board::Board() : value(0), fixed(false) {}

int Board::getValue() const
{
    return value;
}

void Board::setValue(int val)
{
    value = val;
}

bool Board::isFixed() const
{
    return fixed;
}

void Board::setFixed(bool fix)
{
    fixed = fix;
}
