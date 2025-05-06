/* 게임 마스터 */

#include <iostream>

long long N, M;
long long start, end, mid;
int rate, goal;
long long result;

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::cin >> N >> M;

	goal = M * 100 / N + 1;

	start = 1;
	end = 999999999999;
	result = 1000000000000;

	while (start <= end) {
		mid = (start + end) / 2;

		rate = (M + mid) * 100 / (N + mid);
		if (rate >= goal) {
			result = mid;
			end = mid - 1;
		} else {
			start = mid + 1;
		}
	}

	if (result == 1000000000000) std::cout << "X";
	else std::cout << result;

	return 0;
}