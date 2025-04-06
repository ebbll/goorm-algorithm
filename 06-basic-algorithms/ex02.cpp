/* 구름 RPG */

#include <iostream>

int N, A[5000];

bool isPrime(int n) {
	for (int i = 2; i * i <= n; i++) if (n % i == 0) return false;
	return true;
}

int main() {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	// 입력
	std::cin >> N;
	for (int i = 0; i < N; i++) std::cin >> A[i];

	// A의 소수 여부 판별
	for (int i = 0; i < N; i++) {
		if (isPrime(A[i])) std::cout << "Yes\n";
		else std::cout << "No\n";
	}
}
