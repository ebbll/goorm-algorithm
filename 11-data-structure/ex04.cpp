/* 묶음 상품 */

#include <iostream>
#include <vector>

int N, M;
int a, b;
int count;

std::vector<int> graph[100002];
bool visited[100002];

void dfs(int node) {
	for (size_t i = 0; i < graph[node].size(); ++i) {
		if (visited[graph[node][i]]) continue;
		visited[graph[node][i]] = true;
		dfs(graph[node][i]);
	}
}

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::cin >> N >> M;

	// 아이템 a와 b의 연결 관계를 저장함
	for (int loop = 0; loop < M; ++loop) {
		std::cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	// 서로 연결된 덩어리가 몇 개나 있는지 계산
	for (int item = 1; item <= N; ++item) {
		if (visited[item]) continue;
		visited[item] = true;
		// 조회하지 않은 노드를 발견하면 새 덩어리로 간주
		++count;
		// 이 노드와 연결된 모든 정점을 방문
		dfs(item);
	}

	std::cout << count;

	return 0;
}