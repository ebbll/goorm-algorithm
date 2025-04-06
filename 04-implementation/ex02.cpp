/* 합리적 소비 */

#include <iostream>
#include <string>

int T;
int min = 100000, max = 0;
int price;

std::string name;
std::string minName, maxName;

int main() {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	// 입력
	std::cin >> T;

	// 가장 비싼 물건과 저렴한 물건 저장
	while (T--) {
		std::cin >> name >> price;
		if (price > max) { maxName = name; max = price; }
		if (price < min) { minName = name; min = price; }
	}

	// 출력
	std::cout << maxName << " " << max << "\n";
	std::cout << minName << " " << min << "\n";
	
	return 0;
}
