#include <iostream>
#include <vector>
#include <memory.h>

int N, M, K;
int min = INT_MAX;
int max = 0;
int mid;

std::vector<std::pair<int, int> > graph[200002];
std::vector<int> power;
bool visited[200002];

bool checkVisited() {
	for (int i = 1; i <= N; ++i)
		if (!visited[i]) return false;
	return true;
}

void dfs(int start) {
	for (size_t i = 0; i < graph[start].size(); ++i) {
		if (visited[graph[start][i].first]) continue;
		if (graph[start][i].second > mid) continue;
		visited[graph[start][i].first] = true;
		dfs(graph[start][i].first);
	}
}

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::cin >> N >> M >> K;
	for (int i = 0; i < K; ++i) {
		int p;
		std::cin >> p;
		power.push_back(p);
	}

	for (int i = 0; i < M; ++i) {
		int start, end, weight;
		std::cin >> start >> end >> weight;
		graph[start].push_back({end, weight});
		graph[end].push_back({start, weight});
		if (min > weight) min = weight;
		if (max < weight) max = weight;
	}

	while (min < max) {
		mid = (min + max) / 2;
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < K; ++i) {
			if (visited[power[i]]) continue;
			visited[power[i]] = true;
			dfs(power[i]);
		}

		if (checkVisited()) {
			max = mid;
		} else {
			min = mid + 1;
		}
	}

	std::cout << min;

	return 0;
}