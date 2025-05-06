/* 가장 가까운 점 찾기 */

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int N, Q;
long long in, query;
std::vector<long long> point;
int left, right, mid;
int closest;

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::cin >> N >> Q;
	for (int i = 0; i < N; ++i) {
		std::cin >> in;
		point.push_back(in);
	}
	std::sort(point.begin(), point.end());

	for (int loop = 0; loop < Q; ++loop) {
		std::cin >> query;
		left = 0; right = N - 1;

		while (left < right) {
			mid = (left + right) / 2;
			if (point[mid] < query) left = mid + 1;
			else right = mid;
		}

		if (left == 0) std::cout << point[left] << "\n";
		else {
			if (std::abs(query - point[left - 1]) <= std::abs(query - point[left]))
				std::cout << point[left - 1] << "\n";
			else
				std::cout << point[left] << "\n";
		}
	}

	return 0;
}