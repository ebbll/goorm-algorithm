/* 재고 정리 */

#include <iostream>
#include <string>
#include <map>

int N, A;
std::string S;

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::map<std::string, int> foods;
	std::cin >> N;
	for (int i = 0; i < N; ++i) {
		std::cin >> S >> A;
		if (foods.find(S) == foods.end()) {
			foods[S] = A;
		} else {
			foods[S] += A;
		}
	}
	

	for (auto it : foods) {
		std::cout << it.first << " " << it.second << "\n";
	}

	return 0;
}