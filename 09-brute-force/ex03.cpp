/* 구름 찾기 깃발 */

#include <iostream>
#include <vector>

int map[1001][1001];
int N, K;
int in;
int count;

int dr[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dc[8] = {1, 0, -1, 1, -1, 1, 0, -1};

int main() {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	// 입력
	std::cin >> N >> K;
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < N; ++c) {
			std::cin >> in;
			// 깃발이 있는 위치를 1에서 -1로 바꾸어 저장
			map[r][c] = in * -1;
		}
	}

	// 완전 탐색 수행
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < N; ++c) {
			// 깃발이 있는 자리를 만나면
			if (map[r][c] == -1) {
				// 주변 빈 영역에 1씩 더함
				for (int dir = 0; dir < 8; ++dir) {
					int nr = r + dr[dir];
					int nc = c + dc[dir];
					if (nr < 0 || nr >= N || nc < 0 || nc >= N)
						continue ;
					if (map[nr][nc] == -1)
						continue;
					++map[nr][nc];
				}
			}
		}
 	}

	// 값이 K인 지점을 count
	for (int r = 0; r < N; ++r) {
		for (int c = 0; c < N; ++c) {
			if (map[r][c] == K) ++count;
		}
	}

	// 출력
	std::cout << count << "\n";

	return 0;
}