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

void calHighest() {
	int high = 0;
	for (size_t i = 0; i < data.size(); ++i)
		if (data[i] > high) high = data[i];
	highest = high;
}

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::cin >> N >> K;
	for (int loop = 0; loop < N; ++loop) {
		std::cin >> in;

		// F: 맨 앞에 데이터 추가
		if (in == 'F') {
			// data의 맨 앞에 highest보다 1만큼 큰 값을 넣음
			data.insert(data.begin(), ++highest);
			// 실행한 commands에 추가
			commands.push_back(in);
		}

		// B: 맨 뒤에 데이터 추가
		else if (in == 'B') {
			// data의 맨 뒤에 highest보다 1만큼 큰 값을 넣음
			data.push_back(++highest);
			// 실행한 commands에 추가
			commands.push_back(in);
		}

		// P: 맨 앞 data를 제거
		else if (in == 'P') {
			// data가 비어있는 경우 실행하지 않음
			if (data.empty()) continue;

			// 제거할 data를 rollback 스택에 저장
			rollback.push(data[0]);
			// 실제 data에서 삭제 수행
			data.erase(data.begin());
			// 실행한 command에 추가
			commands.push_back(in);
			// highest 재계산
			calHighest();
		}

		// Z: 가장 마지막으로 저장된 command를 취소
		else { // in == 'Z'
			// commands가 비어있는 경우 실행하지 않음
			if (commands.empty()) continue;

			// 가장 마지막으로 저장된 command 조회
			char lastCommand = commands.back();
			// 동일한 커맨드들의 수행을 취소
			while (!commands.empty() && commands.back() == lastCommand) {
				if (lastCommand == 'F') {
					// front에서 빼낸 값들을 맨 앞에 되돌림
					data.erase(data.begin());
					commands.pop_back();
					--highest;
				} else if (lastCommand == 'B') {
					// back에서 빼낸 값들을 맨 뒤에 되돌림
					data.pop_back();
					commands.pop_back();
					--highest;
				} else if (lastCommand == 'P') {
					// rollback에 넣어둔 데이터를 되돌림
					auto value = rollback.top();
					rollback.pop();
					data.insert(data.begin(), value);
					commands.pop_back();
				}
			}
			// rollback 후 highest 재계산
			calHighest();
		}

	}

	std::cout << data[0];

	return 0;
}