/* 울타리 치기 */

#include <iostream>
#include <cmath>

int N;
int prev, curr;
int res;

int main() {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	// 울타리의 개수 입력
	std::cin >> N;

	// 현재 울타리의 높이를 입력받고, 이전 울타리와의 높이차를 계산
	for (int i = 0; i < N; ++i) {
		std::cin >> curr;
		res += std::abs(prev - curr);
		prev = curr;
	}

	// 출력
	std::cout << res + 2 * N + curr;

	return 0;
}
