#include <iostream>
#include <numeric>

int N;
int A, B;
int count;

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::cin >> N;
	for (int i = 1; i <= N / 2; ++i) {
		// A + B = N이고, A <= B <= N
		A = i;
		B = N - i;
		// A와 B는 서로소 관계, 즉 공약수가 1
		if (std::gcd(A, B) == 1) count++;
	}

	std::cout << count;

	return 0;
}