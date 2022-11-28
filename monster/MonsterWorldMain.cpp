#include "MonsterWorld.h"
#include "VariousMonster.h"
#include <time.h>
#include "Human.h"
#include "RankingBoard.h"

#define RANK_FILENAME "MonsterWorldRanking.txt"

int main(void) {
	RankingBoard rank;
	rank.print("[게임 랭킹] : 시작");
	srand((unsigned int)time(NULL));
	int width = 16, height = 8;
	rank.load(RANK_FILENAME);

	MonsterWorld game(width, height);
	game.add(new Zombie("허접한좀비", '!', rand() % width, rand() % height));
	game.add(new Vampire("난뱀파이어", '@', rand() % width, rand() % height));
	game.add(new Jiangshi("강강시", '%', rand() % width, rand() % height));
	Human* human = new Human("휴먼입니다", '(', rand() % width, rand() % height);
	game.add(human);
	game.play(30, 1);	
	rank.add(human -> getnItem());
	rank.print("[게임 랭킹] : 종료");
	rank.save(RANK_FILENAME);
	return 0;
}