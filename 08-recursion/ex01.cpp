/* Bigger than you! */

#include <iostream>
#include <vector>
#include <string>
#include <climits>

int N;
long long K;
int len;
bool found;
std::vector<char> nums;

long long max = LLONG_MAX;
char done[12];

std::string newSolution() {
	char min = '9' + 1;
	std::string result = "";
	
	// 첫 자리에 0을 제외하고 가장 작은 숫자가 오도록
	for (size_t i = 0; i < nums.size(); ++i) {
		if (nums[i] != '0') { min = nums[i]; break; }
	}
	result += min;

	// 나머지 자리는 가장 작은 숫자로 채움
	for (int i = 0; i < len; ++i) result += nums[0];

	return result;
}

void calLength(long long N) {
	while (N > 0) {
		N /= 10;
		++len;
	}
}

long long calValue() {
	std::string val	= "";

	for (int i = 0; i < len; ++i) val += done[i];
	return (std::stoll(val));
}

void dfs(int count) {
	// 조기 종료
	if (found) return;

	// 백트래킹 중단
	if (count == len) {
		// generate 해낸 숫자 계산 후, K와 비교
		if (calValue() > K) {
			max = std::min(max, calValue());
			found = true;
		}
		return ;
	}

	for (int i = 0; i < N; ++i) {
		// 맨 첫 자리에 0이 오지 않도록 조정
		if (count == 0 && nums[i] == '0') continue ;
		done[count] = nums[i];
		dfs(count + 1);
	}
}

int main() {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	// 입력
	std::cin >> N;
	// 숫자들 입력 - 순서 보장됨
	for (int i = 0; i < N; ++i) {
		char in;
		std::cin >> in;
		nums.push_back(in);
	}
	std::cin >> K;

	// K의 길이 len 계산
	calLength(K);
	// 내가 가진 num로 len 길이의 숫자를 만드는 재귀 함수 호출
	dfs(0);

	// len의 길이로 구할 수 없었던 경우, len + 1 길이의 새로운 숫자 생성
	if (!found) std::cout << newSolution();
	else std::cout << max;

	return 0;
}
