/* 운동 중독 플레이어 */

#include <iostream>

int weight, repeat;
int cal;

int main() {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	// 입력
	std::cin >> weight >> repeat;

	// 계산 후 소수점 이하 버림
	cal = (int)(weight * (1 + (double)repeat / 30));

	// 출력
	std::cout << cal;

	return 0;
}
