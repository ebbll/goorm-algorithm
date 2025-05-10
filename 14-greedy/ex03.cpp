/* 초코 쿠키 */

#include <iostream>
#include <vector>
#include <algorithm>

int N;
int value;
std::vector<std::pair<int, int>> P;

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::cin >> N;
	for (int i = 1; i <= N; ++i) {
		std::cin >> value;
		P.push_back({value, i});
	}

	std::sort(P.begin(), P.end());

	for (int i = 0; i < N; ++i) {
		if (P[i].first - i <= 0) {
			for (int idx = 1; idx <= N; ++idx) {
				std::cout << idx << " ";
			}
			return 0;
		}
	}

	for (auto p : P)
		std::cout << p.second << " ";

	return 0;
}