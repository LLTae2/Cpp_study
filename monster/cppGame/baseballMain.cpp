#include <iostream>  
#include <ctime> 
#include "UserBall.h"
#include "ComputerBall.h"
#include "Calculator.h"
using namespace std; 

int main() {  
  int userBall[3];
  UserBall user;
  ComputerBall computer;
  cout << computer.getComputerBall()[0] <<computer.getComputerBall()[1] <<computer.getComputerBall()[2];
  for(int i = 0;i < 9;i++) { 

    cout << "[" << i+1 << "회차 숫자야구]" << endl; 
    cout << "1부터 9까지의 숫자를 입력하세요 : "; 
    cin >> userBall[0] >> userBall[1] >> userBall[2];
     
    if (userBall[0] < 1 || userBall[0] > 9 || userBall[1] < 1 || userBall[1] > 9 || userBall[2] < 1 || userBall[2] > 9) { 
      cout << "범위 외의 숫자를 입력하시면 안됩니다." << endl; 
      continue; 
    } 
    else if (userBall[0] == userBall[1] || userBall[0] == userBall[2] || userBall[1] == userBall[2]) { 
      cout << "중복된 숫자를 입력하시면 안됩니다." << endl; 
      continue; 
    }
    else {
      user.setBall(userBall);
      Calculator calculator(user.getBall(), computer.getComputerBall());
      calculator.Init();
      calculator.Calculate();
      calculator.Check();
    }
  } 
  return 0; 
}