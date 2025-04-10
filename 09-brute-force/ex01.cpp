/* 판다는 귀여워 */

#include <iostream>
#include <climits>
#include <vector>

int N, M, K;
int R[100];
int C[100];
bool map[101][101];
int rpos, cpos;
long long min = LLONG_MAX;

long long distance(int row, int column) {
	long long dist = 0;
	for (int i = 0; i < K; ++i) {
		dist += (R[i] - row) * (R[i] - row) + (C[i] - column) * (C[i] - column);
	}
	return dist;
}

int main() {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::cin >> N >> M >> K;

	// 입력
	for (int i = 0; i < K; ++i) {
		std::cin >> R[i] >> C[i];
		map[R[i]][C[i]] = true;
	}

	// 완전 탐색 수행
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			if (map[i][j]) continue;
			// 현재 포인트에서 다른 포인트까지의 거리 계산
			min = std::min(min, distance(i, j));
		}
	}

	// 출력
	std::cout << min;

	return 0;
}