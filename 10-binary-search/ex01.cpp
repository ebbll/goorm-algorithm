/* 방 탈출하기 */

#include <iostream>
#include <vector>

int N, M;
std::vector<int> A;
int B;
int in;

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	// 입력
	std::cin >> N;
	for (int i = 0; i < N; ++i) {
		std::cin >> in;
		A.push_back(in);
	}
	std::sort(A.begin(), A.end());
	std::cin >> M;

	// 이분 탐색 수행
	while (M--) {
		int start = 0, end = N - 1;
		bool check = false;
		std::cin >> B;

		while (start < end) {
			std::cout << "[" << start << ", " << end << "]\n";
			int mid = (start + end) / 2;
			if (A[mid] < B) start = mid + 1;
			else if (A[mid] > B) end = mid - 1;
			else {
				check = true;
				break;
			}
		}

		// 출력
		std::cout << (check ? 1 : 0) << "\n";
	}

	return 0;
}