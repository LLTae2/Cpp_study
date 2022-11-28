#ifndef __MAZE_H__
#define __MAZE_H__
#include "Matrix.h"

class Maze {
private:
  Matrix<int> map;
  int xMax, yMax;
public:
  Maze(int width, int height):map(height, width), xMax(width), yMax(height){
    for(int y = 0 ; y < yMax ; y++){
      for(int x = 0 ; x < xMax ; x++){
        map.elem(y, x) = 1;
      }
    }
  };

};
#endif
