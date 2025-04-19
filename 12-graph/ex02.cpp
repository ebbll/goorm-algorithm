/* 가뭄 */

#include <iostream>

int T;
int N, M;
int v1, v2;

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::cin >> T;
	while (T--) {
		std::cin >> N >> M;
		for (int i = 0; i < M; ++i)
			std::cin >> v1 >> v2;
		std::cout << N - 1 << "\n";
	}

	return 0;
}