#ifndef __MONSTER_WORLD_H__
#define __MONSTER_WORLD_H__

#include "Canvas.h"
#include "Monster.h"
#include <unistd.h>
#include <stdlib.h>
#include "Matrix.h"
#define MAX_MONSTER 20

class MonsterWorld {
private:
    Matrix<int> map;
    int xMax, yMax, nMon, nMove;
    Monster* mon[MAX_MONSTER];
    Canvas canvas;
public:
    MonsterWorld(int width, int height): canvas(width, height), xMax(width), yMax(height), nMon(0), nMove(0), map(height, width){
        for(int y = 0 ; y < yMax ; y++){
            for(int x = 0 ; x < xMax ; x++){
                map.elem(y, x) = 1;
            }
        }
    }
    ~MonsterWorld(){
        for(int i = 0 ; i < nMon ; i++){
            delete mon[i];
        }
    }
    void add(Monster* m){
        if(nMon < MAX_MONSTER)
            mon[nMon++] = m;
    }
    int countItems(){
        int nItems = 0;
        for(int y = 0; y < yMax; y++)
            for(int x = 0; x < xMax ; x++)
                if(map.elem(y, x) == 1)
                    nItems++;
        return nItems;
    }

    void print(){
        cout << "\x1B[2J\x1B[H";

        canvas.clear();
        //1. canvas에 아이템
        for(int y = 0 ; y < yMax ; y++){
            for(int x = 0 ; x < xMax ; x++){
                if(map.elem(y, x) == 1)
                    canvas.draw(x,y,'.');
            }
        }
        //2. canvas에 monster
        for(int i = 0 ; i < nMon ; i++)
            mon[i]->draw(canvas);
        //3. canvas 출력
        canvas.print();
        //4. 전체 이동 횟수
        cout<<"전체 이동 횟수 = "<<nMove<<endl;
        //5. 남은 아이템 수
        cout<<"남은 아이템 수 = "<<countItems()<<endl;
        //6. 몬스터별 상태
        for(int i = 0 ; i < nMon ; i++)
            mon[i]->print();
    }
       
    void play(int maxWalk, int wait) {
        print();
        cout << " 엔터를 누르세요...";
        getchar();
        for(int i = 0 ; i < maxWalk ; i++){
            for(int k = 0 ; k < nMon ; k++)
                mon[k]->move(map.getMatrix(), xMax, yMax);
            nMove++;
            print();
            if(countItems() == 0) break;
            sleep(wait);
        }
    }
};

#endif
