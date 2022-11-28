#ifndef __VARIOUS_MONSTERS_H__
#define __VARIOUS_MONSTERS_H__
#include "Monster.h"

class Zombie : public Monster {
  public:
  Zombie(string name = "좀비", char icon = '!', int x = 0, int y = 0): Monster(name, icon, x, y){}
  ~Zombie() {
    cout << "[ Zombie ]";
  }
  void move(int** map, int xMax, int yMax){
    switch(rand()%8) {
			case 0: y--; break; // up
			case 1: x++; y--; break; // right up
			case 2: x++; break; // right
			case 3: x++; y++; break; // right down
			case 4: y++; break; // down
			case 5: x--; y++; break; // left down
			case 6: x--; break; // left
			case 7: x--; y--; break; // left up
		}
		clip(xMax, yMax);
		eat(map);
  }
};

class Vampire : public Monster {
  public:
  Vampire(string name = "뱀파이어", char icon = '@', int x = 0, int y = 0): Monster(name, icon, x, y){}
  ~Vampire() {
    cout << "[ Vampire ]";
  }
  void move(int** map, int xMax, int yMax){
    switch(rand()%4) {
      case 0: y--; break;
      case 1: x++; break;
      case 2: y++; break;
      case 3: x--; break;
    }
    clip(xMax, yMax);
    eat(map);
  }
};

class Jiangshi : public Monster {
  public:
  Jiangshi(string name = "강시", char icon = '%', int x = 0, int y = 0): Monster(name, icon, x, y){}
  ~Jiangshi() {
    cout << "[ Jiangshi ]";
  }
  void move(int** map, int xMax, int yMax){
    switch(rand()%4) {
      case 0: y--; break;
      case 1: x++; break;
      case 2: y++; break;
      case 3: x--; break;
    }
    clip(xMax, yMax);
    eat(map);
  }
};


#endif