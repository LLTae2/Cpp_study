#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__

#include <iostream>
#include <algorithm>
using namespace std;

class Calculator {
private:
  int userBall[3];
  int computerBall[3];
  int strike = 0; 
  int ball = 0; 
  int count = 0;
public:
  Calculator(int userBall[], int computerBall[]) {
    for(int i = 0; i < 3; i++){
      this->userBall[i] = userBall[i];
      this->computerBall[i] = computerBall[i];
    } 
  }
  void Calculate() {

    for (int i = 0; i < 3; i++) {
      cout << userBall[i];
      for (int j = 0; j < 3; j++) {
        if (computerBall[i] == userBall[j]) {
          if (i == j) strike++; 
          else ball++; 
        }
      }
    }
  }
  void Check() {
    if (strike || ball) cout << "[결과]스트라이크 : " << strike << ", 볼 : " << ball << endl << endl; 
    else cout << "[결과] 아웃!!!" << endl << endl; 
    if (strike == 3) { 
      cout << "***** 승리했습니다. *****" << endl << endl; 
      exit(1);
    } 
    else if (count == 9) { 
      cout << "***** 패배했습니다.. 정답 : "; 
      cout << computerBall[0] << computerBall[1] << computerBall[2] << " *****" << endl << endl;
    } 
    count++;
  }
  void Init() {
    this->strike = 0;
    this->ball = 0;
  }
};

#endif