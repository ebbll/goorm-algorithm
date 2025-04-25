/* 불이야!! */

#include <iostream>
#include <string>
#include <queue>

#define EMPTY '.'
#define WALL '#'
#define POS '&'
#define FIRE '@'

int R, C;
char map[1002][1002];
int visited[1002][1002];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int pos[2];

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::queue<std::pair<int, int> > queue;

	std::cin >> R >> C;
	for (int row = 0; row < R; ++row) {
		for (int col = 0; col < C; ++col) {
			std::cin >> map[row][col];
			if (map[row][col] == FIRE) {
				queue.push({row, col});
				visited[row][col] = 1;
			} else if (map[row][col] == POS) {
				pos[0] = row;
				pos[1] = col;
			}
		}
	}

	while (!queue.empty()) {
		auto [row, col] = queue.front();
		queue.pop();

		for (int i = 0; i < 4; ++i) {
			int nr = row + dx[i];
			int nc = col + dy[i];

			if (nr < 0  || nr >= R || nc < 0 || nc >= C) continue;
			if (visited[nr][nc] > 0) continue;
			if (map[nr][nc] == WALL || map[nr][nc] == FIRE) continue;
			visited[nr][nc] = visited[row][col] + 1;
			queue.push({nr, nc});
		}
	}

	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			std::cout << visited[i][j] << " ";
		}
		std::cout << "\n";
	}

	if (visited[pos[0]][pos[1]] == 0) {
		std::cout << "-1";
	} else {
		std::cout << visited[pos[0]][pos[1]] - 2;
	}

	return 0;
}