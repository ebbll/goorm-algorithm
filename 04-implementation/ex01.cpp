/* 합 계산기 */
#include <iostream>

int T;
int A, B;
char oper;

int res;

int main() {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	// 입력
	std::cin >> T;

	// operator에 맞게 연산
	while (T--) {
		std::cin >> A >> oper >> B;

		if (oper == '+')
			res += A + B;
		else if (oper == '-')
			res += A - B;
		else if (oper == '*')
			res += A * B;
		else // oper == '/'
			res += A / B;
	}

	// 출력
	std::cout << res;
	
	return 0;
}
