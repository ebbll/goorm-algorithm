#include <iostream>
#include <queue>
#include <memory.h>

int N, M;
int charge, add, minus;

int start[2];
int end[2];
int pos[2];

int map[202][202];
int visited[202][202];
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

int cost;
int totalMove;

int calDist(int startRow, int startCol, int endRow, int endCol) {
	std::queue<std::pair<int, int>> Q;
	memset(visited, 0, sizeof(visited));

	visited[startRow][startCol] = 1;
	Q.push({startRow, startCol});

	while (!Q.empty()) {
		int r = Q.front().first;
		int c = Q.front().second;
		if (r == endRow && c == endCol) break;
		Q.pop();

		for (int dir = 0; dir < 4; ++dir) {
			int nr = r + dr[dir];
			int nc = c + dc[dir];

			if (nr < 1 || nr > N || nc < 1 || nc > N) continue;
			if (visited[nr][nc] || map[nr][nc]) continue;

			visited[nr][nc] = visited[r][c] + 1;
			Q.push({nr, nc});
		}
	}

	return visited[endRow][endCol] - 1;
}

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::cin >> N >> M;
	std::cin >> charge >> add >> minus;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			std::cin >> map[i][j];

	for (int loop = 0; loop < M; ++loop) {
		std::cin >> start[1] >> start[0] >> end[1] >> end[0];

		int dist1 = 0, dist2 = 0;

		// 1. 태우러 가기 -> pos에서 start까지 이동
		if (loop != 0)
			dist1 = calDist(pos[0], pos[1], start[0], start[1]);

		// 2. 주행 시작 -> start에서 end까지 이동
		dist2 = calDist(start[0], start[1], end[0], end[1]);
		
		// 3. 주행 종료 -> pos를 end로 업데이트
		pos[0] = end[0];
		pos[1] = end[1];

		// 운임 계산
		int tempCost = (dist2 <= 5 ? charge : charge + add * (dist2 - 5));
		cost += tempCost;
		
		// 전체 주행 거리 업데이트
		totalMove += dist1 + dist2;
	}

	// 통행료 차감
	std::cout << cost - totalMove * minus;

	return 0;
}