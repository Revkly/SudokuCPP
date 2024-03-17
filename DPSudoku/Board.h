#ifndef BOARD_H
#define BOARD_H

class Board
{
private:
    int value;
    bool fixed;

public:
    Board();
    int getValue() const;
    void setValue(int val);
    bool isFixed() const;
    void setFixed(bool fix);
};

#endif
