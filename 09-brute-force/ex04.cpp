/* 구름 RPG 2 */

#include <iostream>

int N, A;
int count;

bool isprime(int n) {
	if (n < 2) return false;
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) return false;
	}
	return true;
}

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::cin >> N;
	for (int i = 0; i < N; ++i) {
		std::cin >> A;
		count = 0;
		while (!isprime(A - count)) ++count;
		std::cout << count << "\n";
	}

	return 0;
}