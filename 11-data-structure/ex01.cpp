/* 뒤통수가 따가워 */

#include <iostream>
#include <stack>

int N;
int heights[100002];

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	// 입력
	std::cin >> N;
	for (int i = 0; i < N; ++i) {
		std::cin >> heights[i];
	}

	std::stack<int> s;
	for (int curr = 0; curr < N; ++curr) {
		// curr position에서 올려다 볼 수 있는 봉우리의 수 출력
		std::cout << s.size() << " ";
		// 현재 높이보다 낮은 것들은 가려지므로, pop
		while (!s.empty() && heights[s.top()] <= heights[curr])
			s.pop();
		s.push(curr);
	}

	return 0;
}
