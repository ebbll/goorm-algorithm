/* 복제 로봇 */

#include <iostream>

int N, Q;
int xpos, ypos;
int curx, cury;
char move;
bool map[4002][4002];

void reverse() {
	if (move == 'L') ++curx;
	else if (move == 'R') --curx;
	else if (move == 'U') --cury;
	else ++cury;
}

void go() {
	if (move == 'L') --curx;
	else if (move == 'R') ++curx;
	else if (move == 'U') ++cury;
	else --cury;
}

int main() {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	// 입력
	std::cin >> curx >> cury >> N;

	// 좌표의 축 범위를 [-2000, 2000]에서 [0, 4000] 양수 구간으로 보정
	curx += 2000; cury += 2000;

	// 웅덩이의 좌표 입력
	for (int i = 0; i < N; ++i) {
		std::cin >> xpos >> ypos;
		map[xpos + 2000][ypos + 2000] = true;
	}

	std::cin >> Q;
	for (int i = 0; i < Q; ++i) {
		// 움직일 방향 입력받기
		std::cin >> move;

		// 이동하기
		go();

		// 웅덩이를 만난 경우 되돌아가기
		if (map[curx][cury]) reverse();
	}

	// 좌표 재보정 후 출력
	std::cout << curx - 2000 << " " << cury - 2000;

	return 0;
}
