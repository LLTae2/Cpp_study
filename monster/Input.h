#ifndef __INPUT_H__
#define __INPUT_H__

#include <unistd.h> // read 함수
#include <termios.h>

int getch(void) {
	char buf = 0;
	struct termios terminal_setting = {0};
	tcgetattr(0, &terminal_setting); // 현재 터미널 설정 읽기
	terminal_setting.c_lflag &= ~ICANON;
	terminal_setting.c_lflag &= ~ECHO;
	terminal_setting.c_cc[VMIN] = 0; // 최소 입력 문자 수 설정
	terminal_setting.c_cc[VTIME] = 0; // 최소 읽기 대기 시간 설정
	tcsetattr(0, TCSANOW, &terminal_setting); // 터미널에 설정 입력
	read(0, &buf, 1);
	return buf;
}
#endif