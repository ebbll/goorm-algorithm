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
	}

	DP[1] = COIN[1];
	for (int i = 2; i <= N; i++)
		DP[i] = std::max(DP[i - 1], (long long)0) + COIN[i];

	for (int i = 1; i <= N; i++)
		max = std::max(max, DP[i]);

	std::cout << max;

	return 0;
}