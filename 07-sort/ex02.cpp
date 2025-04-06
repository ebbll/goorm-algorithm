/* 이진수 정렬 */

#include <iostream>
#include <vector>
#include <algorithm>

int N, K, in;
std::vector<int> nums;

bool compare(int A, int B) {
	int copyA = A, copyB = B;
	int ac = 0, bc = 0;

	// 이진수로 변환했을 때 1의 개수 계산
	while (copyA > 0) {
		ac += copyA % 2;
		copyA /= 2;
	}
	while (copyB > 0) {
		bc += copyB % 2;
		copyB /= 2;
	}

	// 이진수로 변환했을 때 1의 개수가 더 많은 경우
	if (ac > bc) return true;
	// 1의 개수가 같다면, 십진수 기준으로 A가 B보다 큰 경우
	if (ac == bc && A > B) return true;
	return false;
}

int main() {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	// 입력
	std::cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		std::cin >> in;
		nums.push_back(in);
	}

	// 정렬
	std::sort(nums.begin(), nums.end(), compare);

	// 정렬 후 K번째에 위치한 수 출력
	std::cout << nums[K - 1];

	return 0;
}