/* 과연 승자는? */

#include <iostream>

int N;
int A[100001];
int B[100001];
int alice, bob;

int main() {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	// 입력
	std::cin >> N;
	for (int i = 0; i < N; ++i) std::cin >> A[i];
	for (int i = 0; i < N; ++i) std::cin >> B[i];

	// 카드 게임 시뮬레이션
	for (int i = 0; i < N; ++i) {
		// 동점인 경우
		if (A[i] == B[i]) { ++alice; ++bob; }

		// 공격력이 다른 경우
		else if (A[i] > B[i]) {
			if (A[i] - B[i] == 7) { bob += 3; alice -= 1; }
			else alice += 2;
		} else {
			if (B[i] - A[i] == 7) { alice += 3; bob -= 1; }
			else bob += 2;
		}
	}

	// 출력
	std::cout << alice << " " << bob;

	return 0;
}