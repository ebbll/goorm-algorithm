/* 피보나치 수열 */

#include <iostream>

int N;
int DP[1000001];

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	// DP 초기화
	DP[1] = 0;
	DP[2] = 1;

	std::cin >> N;

	// DP 점화식
	for (int i = 3; i <= 1000000; ++i)
		DP[i] = (DP[i - 1] + DP[i - 2]) % 1000000007;

	std::cout << DP[N];

	return 0;
}