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
		std::cout << s.size() << " ";
		while (!s.empty() && heights[s.top()] <= heights[curr])
			s.pop();
		s.push(curr);
	}

	return 0;
}

// SOLVE 완료!
