/* 연합 */

#include <iostream>
#include <vector>

int N, M;
int start, end;
int count;

std::vector<int> graph[2001];
bool edge[2001][2001];
int visited[2001];

void dfs(int start) {
	for (size_t i = 0; i < graph[start].size(); ++i) {
		if (visited[graph[start][i]]) continue;
		visited[graph[start][i]] = true;
		dfs(graph[start][i]);
	}
}

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		std::cin >> start >> end;
		edge[start][end] = true;
	}

	// 단방향 연결 관계를 저장
	for (int i = 1; i < N; ++i) {
		for (int j = i + 1; j <= N; ++j) {
			if (edge[i][j] && edge[j][i]) {
				graph[i].push_back(j);
				graph[j].push_back(i);
			}
		}
	}

	// 양방향 connection이 존재하는 경우만 저장
	for (int i = 1; i <= N; ++i) {
		if (!visited[i]) {
			visited[i] = count;
			++count;
			dfs(i);
		}
	}

	std::cout << count;

	return 0;
}