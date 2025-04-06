/* 여유 황금비 */

#include <iostream>
#include <cmath>

int T;
long long smaller, larger;
int count;

int main() {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	// 입력
	std::cin >> T;

	// A와 B의 관계가 황금비인 케이스를 카운트
	while (T--) {
		std::cin >> smaller >> larger;
		if (smaller > larger) std::swap(smaller, larger);

		// 큰 수가 작은 수에 1.6을 곱한 이상, 1.63을 곱한 값 이하인 경우 황금비
		// 소수점 보정을 위해 100 곱하여 계산
		if ((larger * 100 >= smaller * 160) && (larger * 100 <= smaller * 163))
			++count;
	}

	// 출력
	std::cout << count;
	
	return 0;
}
