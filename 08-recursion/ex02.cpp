/* 하노이의 탑 */

#include <iostream>
#include <vector>

int K;
std::vector<int> sticks[4];
std::vector<std::pair<int, int> > moves;

// n: 옮겨야 하는 disk의 수
// start: 출발지 end: 목적지 via: 경유지
void hanoi(int n, int start, int end, int via){
	// 원반이 하나인 경우, 옮기고 종료
	if (n == 1) {
		moves.push_back({start, end});
		return ;
	}

	// n-1개의 disk을 via로
	hanoi(n - 1, start, via, end);

	// 마지막 disk을 end로
	moves.push_back({start, end});

	// via로 옮긴 n-1개의 disk을 다시 end로
	hanoi(n - 1, via, end, start);
}

int main() {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	// 입력
	std::cin >> K;
	
	// 20개의 disk을 1번째 pillar에 push
	for (int i = 20; i > 0; --i)
		sticks[1].push_back(i);

	// 20개짜리 disk의 하노이의 탑을 해결하는 move를 순서대로 기록
	hanoi(20, 1, 3, 2);

	// 저장된 move대로 K번째 과정까지 시뮬레이션
	for (int step = 0; step < K; ++step) {
		// start의 맨 위에 있는 disk을 end로 옮김
		int start = moves[step].first;
		int end = moves[step].second;
		int disk = sticks[start].back();

		sticks[start].pop_back();
		sticks[end].push_back(disk);
	}

	// 각 pillar에 있는 disk 크기의 합을 출력
	for (int pillar = 1; pillar <= 3; ++pillar) {
		int total = 0;
		for (size_t i = 0; i < sticks[pillar].size(); ++i)
			total += sticks[pillar][i];
		std::cout << total << ' ';
	}
}
