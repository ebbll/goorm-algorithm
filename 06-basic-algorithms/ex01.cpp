/* 시간복잡도 */

#include <iostream>

int N;
int count;

int main() {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	// 입력
	std::cin >> N;

	// N!의 맨 뒤에 붙는 연속된 0의 개수 계산
	// 0이 붙으려면 2 * 5가 곱해져야 하므로, N!을 구성하는 수 중에서 5가 몇 개 들어갔는지 count
	while (N > 0) {
		N /= 5;
		count += N;
	}

	// 출력
	std::cout << count;

	return 0;
}
