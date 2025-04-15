/* 섭외하기 대작전 */

#include <iostream>
#include <algorithm>

int N;
long long S[3002];
long long in;
long long count;

bool cal(int i, int j, int k) {
	if (S[i] > S[j] + S[k]) return false;

	return true;
}

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	// 입력
	std::cin >> N;
	for (int i = 0; i < N; ++i) {
		std::cin >> S[i];
	}
	std::sort(S, S + N);

	// 이분 탐색
	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			int k = std::upper_bound(S, S + N, S[i] + S[j]) - S - 1;
			count += k - j;
		}
	}

	// 출력
	std::cout << count;

	return 0;
}
