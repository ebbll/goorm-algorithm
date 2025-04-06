/* 나무꾼 구름이 */

#include <iostream>
#include <vector>

int N, M;
int pos;
int H, Q;
long long res;
char D;
int growth;
std::vector<int> heights;

void takeWood(int pos) {
	if (heights[pos] + growth >= M) {
		res += heights[pos] + growth;
		heights[pos] -= heights[pos] + growth;
	}
}

int main() {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	// 입력
	std::cin >> N >> M >> pos;
	--pos;
	for (int i = 0; i < N; ++i) {
		std::cin >> H;
		heights.push_back(H);
	}
	std::cin >> Q;

	// 시뮬레이션
	for (int loop = 0; loop < Q; ++loop) {
		// 벌목
		takeWood(pos);

		// 나무 성장
		++growth;

		// 포지션 이동
		std::cin >> D;
		if (D == 'L') { pos = (pos - 1 + N) % N; }
		else if (D == 'R') { pos = (pos + 1) % N; }
	}

	// 출력
	std::cout << res;
	return 0;
}