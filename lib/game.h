#ifndef GAME_H
#define GAME_H
#include "board.h"
#include "consts.h"

class BaseGame {
protected:
  Board * board;
  virtual int solve() = 0;
public:
  BaseGame();
  ~BaseGame();
  int run();
};


class ControlGame : public BaseGame {
protected:
    int solve() override {
        int hits = 0;
        for(int i = 0; i < HEIGHT; i++)
        {
            for(int j = 0; j < WIDTH; j++)
            {
                if(this->board->guess(i, j) == ResponseType::HIT)
                {
                    hits += 1;
                }
            }
        }
        return hits;
    }
};

class AssignmentGame : public BaseGame 
{
protected:
    //edited the solve() as asked
    int solve() override
    {
        //ships intialized to zero, while board size is initalized to the values of height and width above
        int ships = 0;
        int boardsize = HEIGHT + WIDTH;

        //for loop start
        for (int i = 0; i < boardsize; i++)
        {
            //checks if guess function from the board has a hit response type
            if (this->board->guess(i) == ResponseType::HIT)
            {
                //if hit incriment by 1
                ships++;
                //checks if ship count id the same as SHIP_COUNT
                //if it comesback equal it returns to shipcount and loops until all spaces are checked
                if (ships == SHIP_COUNT)
                {
                    //returns if hit
                    return SHIP_COUNT;
                }
            }
        }
        //returns the final count once iterated loop goes through
        return ships;
    }
};


#endif /* GAME_H */
