/* 문자열 나누기 */

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

int N;
int answer;
std::string S;
std::vector<std::string> P;

int main() {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::cin >> N >> S;
	for (int i = 0; i < N; ++i) {
		std::string cur;
		for (int j = i; j < N; ++j) {
			cur.push_back(S[j]);
			if ((int)cur.size() > N - 2) break;
			P.push_back(cur);
		}
	}

	std::sort(P.begin(), P.end());
	P.erase(std::unique(P.begin(), P.end()), P.end());

	std::map<std::string, int> score;
	for (size_t i = 0; i < P.size(); ++i) score[P[i]] = i + 1;

	for (int L = 1; L < N; ++L) {
		int i = score[S.substr(0, L)];
		for (int R = L + 1; R < N; ++R) {
			int j = score[S.substr(L, R - L)];
			int k = score[S.substr(R, N - R)];
			answer = std::max(answer, i + j + k);
		}
	}

	std::cout << answer;
	return 0;
}