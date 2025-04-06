/* 해적왕 구름이 */

#include <iostream>
#include <vector>
#include <algorithm>

int N;
int x, y;
int res[100000];
std::vector<std::pair< int, std::pair<int, int> > > island;

bool compare(std::pair< int, std::pair<int, int> > A, std::pair< int, std::pair<int, int> > B) {
	std::pair<int, int> Apos = A.second;
	std::pair<int, int> Bpos = B.second;
	
	// 1. A의 x좌표가 B의 x좌표보다 작은 경우
	// 2. A와 B의 x좌표가 같고, A의 y좌표가 B의 y좌표보다 작은 경우
	if (Apos.first < Bpos.first || (Apos.first == Bpos.first && Apos.second < Bpos.second))
		return true;
	return false;
}

int main() {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	// 입력
	std::cin >> N;
	for (int i = 0; i < N; ++i) {
		std::cin >> x >> y;
		island.push_back({i + 1, {x, y}});
	}

	// 섬 정렬
	std::sort(island.begin(), island.end(), compare);

	// 섬 i를 뒤따르는 섬의 개수 계산
	for (int i = 0; i < N; ++i) 
		res[island[i].first - 1] = N - 1 - i;

	// 섬 번호에 맞게 출력
	for (int i = 0; i < N; ++i) 
		std::cout << res[i] << "\n";

	return 0;
}