/* 빵야 */

#include <iostream>

int N;
int enemies[100001];
int pointer;
long long count;

int main() {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	// 입력
	std::cin >> N;
	for (int i = 0; i < N; ++i) std::cin >> enemies[i];

	// 적 하나씩 상대
	for (int i = 0; i < N; ++i) {
		// 권총의 대미지는 1, 2, 3, 4, 1, 2, 3, 4, ... 를 반복
		// 4번의 발사 1, 2, 3, 4가 한 세트

		// ememy의 체력을 권총 4회(한 바퀴)를 발사한 결과인 10으로 나누기
		count += enemies[i] / 10 * 4;

		// 나머지를 취하기
		enemies[i] %= 10;

		// 나머지 체력에 대해 발사 반복, modulo로 현재 pointer 저장
		while (enemies[i] > 0) {
			enemies[i] -= (pointer++ + 1); // pointer 값의 구간은 1, 2, 3, 4를 순환
			pointer %= 4;
			++count;
		}
	}

	// 출력
	std::cout << count;
	
	return 0;
}