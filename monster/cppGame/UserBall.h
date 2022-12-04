#ifndef __USER_BALL_H__
#define __USER_BALL_H__

#include <iostream>
using namespace std;

class UserBall {
private:
  int userBall[3];
public:
  void setBall(int userBall[]) {
    for(int i = 0; i < 3; i++){
      this->userBall[i] = userBall[i];
    }
  }
  int* getBall() {
    return userBall;
  }
};

#endif