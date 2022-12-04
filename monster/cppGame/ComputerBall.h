#ifndef __COMPUTER_BALL_H__
#define __COMPUTER_BALL_H__

#include <iostream>
using namespace std;

class ComputerBall {
private:
  int computerBall[3]; 
public:
  ComputerBall() {
    srand(static_cast<unsigned int>(time(NULL)));
    for (int i = 0; i < 3; i++) { 
      computerBall[i] = (rand() % 9) + 1; 
      for (int j = 0; j < i; j++) 
        if (computerBall[i] == computerBall[j] && i != j) 
          i--; 
    } 
  }
  int* getComputerBall() {
    return computerBall;
  }
};

#endif