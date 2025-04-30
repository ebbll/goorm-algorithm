/* 세계 여행 */

#include <iostream>
#include <vector>

int N, M;
int start, end;

std::vector<int> graph[1002];
int language[1002];
bool visited[11][1002];

int maxCount;
int count;

void dfs(int curr, int lang) {
	for (size_t i = 0; i < graph[curr].size(); ++i) {
		int next = graph[curr][i];
		if (visited[lang][next]) continue;
		if (language[next] != lang && language[next] != language[1]) continue;

		visited[lang][next] = true;
		count++;
		dfs(next, lang);
	}
}

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::cin >> N >> M;
	for (int i = 1; i <= N; ++i) std::cin >> language[i];
	for (int i = 0; i < M; ++i) {
		std::cin >> start >> end;
		graph[start].push_back(end);
		graph[end].push_back(start);
	}

	for (int lang = 1; lang <= 10; ++lang) {
		if (language[1] == lang) continue;

		count = 1;
		visited[lang][1] = true;
		dfs(1, lang);
		if (count > maxCount) maxCount = count;
	}

	std::cout << maxCount;

	return 0;
}