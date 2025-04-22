/* 영상처리 */

#include <iostream>
#include <string>

int N, M;

std::string map[152];
int visited[152][152];

int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

int count, size, maxSize;

void dfs(int row, int col) {
	for (int i = 0; i < 4; ++i) {
		int nr = row + dr[i];
		int nc = col + dc[i];

		if (nr < 0 || nr >= M || nc < 0 || nc >= N) continue;
		if (visited[nr][nc] || map[nr][nc] == '.') continue;

		++size;
		visited[nr][nc] = true;
		dfs(nr, nc);
	}
}

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::cin >> N >> M;
	for (int i = 0; i < M; ++i)
		std::cin >> map[i];

	for (int row = 0; row < M; ++row) {
		for (int col = 0; col < N; ++col) {
			if (!visited[row][col] && map[row][col] == '#') {
				// 덩어리의 개수 count
				count++;
				// 인접 영역의 size 계산
				size = 1;
				visited[row][col] = true;
				dfs(row, col);
				if (size > maxSize) maxSize = size;
			}
		}
	}

	std::cout << count << "\n" << maxSize << "\n";

	return 0;
}