#ifndef __HUMAN_H__
#define __HUMAN_H__

#include "Monster.h"
#include "Input.h"

class Human: public Monster {
  public:
    Human(string name="인간", char icon='&', int x=0, int y=0): Monster(name, icon, x, y) {}
    ~Human() {
      cout << " [ Human ]";
    }
    void move(int** map, int xMax, int yMax) {
      int arrow_check1 = getch();
      int arrow_check2 = getch();
      if(arrow_check1 == 27 && arrow_check2 == 91) {
        int ch = getch();
        if(ch==68) x--;
        if(ch==67) x++;
        if(ch==65) y--;
        if(ch==66) y++;
      }

      clip(xMax, yMax);
      eat(map);

    }
    int getnItem() {
      return nItem;
    }
};
#endif