/* 동전 줍기 대회 */

#include <iostream>

int N;
int COIN[100001];
long long DP[100001];
long long max;

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::cin >> N;
	for (int i = 1; i <= N; ++i) {
		std::cin >> COIN[i];
		DP[i] = COIN[i] + DP[i - 1];
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = i + 1; j <= N; ++j) {
			max = std::max(max, DP[j] - DP[i - 1]);
		}
	}

	std::cout << max;

	return 0;
}