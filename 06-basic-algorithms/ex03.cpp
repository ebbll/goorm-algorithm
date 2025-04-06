/* GameJam */

#include <iostream>
#include <memory.h>

int N;
int cnt[204][204];
bool visited[204][204];
int pos[2][2];
char command[204][204];

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

int play(int y, int x, int N) {
	int score = 0;
	bool flag = false;

	memset(visited, 0, sizeof(bool) * 204 * 204);
	visited[y][x] = true;

	while (true) {
		// 방향 설정
		int dir;
		switch (command[y][x]) {
			case 'R': { dir = 0; break; }
			case 'L': { dir = 1; break; }
			case 'D': { dir = 2; break; }
			case 'U': { dir = 3; break; }
		};

		// 이동
		int moveCnt = cnt[y][x];
		while (moveCnt--) {
			y += dy[dir], x += dx[dir];

			if (y > N) y -= N;
			if (x > N) x -= N;
			if (y == 0) y += N;
			if (x == 0) x += N;

			// 이미 방문한 칸에 재방문하면 게임 종료
			if (visited[y][x]) { flag = true; break ; }
			visited[y][x] = true;
		}

		// 게임 종료
		if (flag) break ;
	}

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			if (visited[i][j]) score++;
	return score;
}

int main() {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	// 입력
	std::cin >> N;
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			std::cin >> pos[i][j];
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			std::cin >> cnt[i][j] >> command[i][j];

	// goorm과 player의 점수 계산
	int goormScore = play(pos[0][0], pos[0][1], N);
	int playerScore = play(pos[1][0], pos[1][1], N);

	// 출력
	if (goormScore > playerScore)
		std::cout << "goorm " << goormScore << '\n';
	else
		std::cout << "player " << playerScore << '\n';

	return 0;
}