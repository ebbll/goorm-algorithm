#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>

int N, K;
char in;

std::vector<int> data;
std::vector<char> commands;
std::stack<int> rollback;
int highest;

void calHigh() {
	int high = 0;
	for (size_t i = 0; i < data.size(); ++i) {
		if (data[i] > high) high = data[i];
	}
	highest = high;
}

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::cin >> N >> K;
	for (int loop = 0; loop < N; ++loop) {
		std::cin >> in;
		if (in == 'F') {
			// data의 맨 앞에 highest보다 1만큼 큰 값을 넣음
			data.insert(data.begin(), ++highest);

			// 실행한 commands에 추가
			commands.push_back(in);
		} else if (in == 'B') {
			// data의 맨 뒤에 highest보다 1만큼 큰 값을 넣음
			data.push_back(++highest);

			// 실행한 commands에 추가
			commands.push_back(in);
		} else if (in == 'P') {
			// data가 비어있는 경우 실행하지 않음
			if (data.empty()) continue;

			// 제거할 data의 pos와 value를 rollback 스택에 저장
			rollback.push(data[0]);
			// 실제 data에서 삭제 수행
			data.erase(data.begin());
			// 실행한 command에 추가
			commands.push_back(in);
			// highest 재계산
			calHigh();
		} else if (in == 'Z') {
			// commands가 비어있는 경우 실행하지 않음
			if (commands.empty()) continue;

			// 가장 마지막으로 저장된 command 조회
			char lastCommand = commands.back();
			// 동일한 커맨드들의 수행을 취소
			while (!commands.empty() && commands.back() == lastCommand) {
				if (lastCommand == 'F') {
					data.erase(data.begin());
					commands.pop_back();
					--highest;
				} else if (lastCommand == 'B') {
					data.pop_back();
					commands.pop_back();
					--highest;
				} else if (lastCommand == 'P') {
					// rollback 데이터의 pos와 value를 통해 되돌림
					auto value = rollback.top();
					rollback.pop();
					data.insert(data.begin(), value);
					commands.pop_back();
				}
			}
			// highest 재계산
			calHigh();
		}

		// std::cout << "=======\n";
		// for (size_t i = 0; i < data.size(); ++i)
		// 	std::cout << data[i] << " ";
		// std::cout << "\n";
		// for (size_t i = 0; i < commands.size(); ++i)
		// 	std::cout << commands[i] << " ";
		// std::cout << "\n";
		// std::cout << "=======\n";
	}

	std::cout << data[0];

	return 0;
}