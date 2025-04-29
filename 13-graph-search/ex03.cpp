/* 작은 노드 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int N, M, K;
int start, end;
std::vector<int> graph[2002];
bool visited[2002];
std::vector<int> sequence;
std::queue<int> queue;

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	// 그래프 정보 저장
	std::cin >> N >> M >> K;
	for (int i = 0; i < M; ++i) {
		std::cin >> start >> end;
		graph[start].push_back(end);
		graph[end].push_back(start);
	}

	// 가장 작은 번호의 노드부터 방문해야 하므로, 데이터를 정렬
	for (int i = 1; i <= N; ++i)
		std::sort(graph[i].begin(), graph[i].end());

	// K부터 BFS 시작
	visited[K] = true;
	queue.push(K);
	sequence.push_back(K);

	// BFS
	while (!queue.empty()) {
		int flag = false;
		int curr = queue.front();	
		queue.pop();

		for (size_t i = 0; i < graph[curr].size(); ++i) {
			int next = graph[curr][i];
			if (visited[next]) continue;

			// 방문할 수 있는 노드 중 가장 작은 번호의 노드를 방문
			visited[next] = true;
			sequence.push_back(next);
			queue.push(next);
			flag = true;
			break;
		}

		// 방문할 수 있는 노드를 찾지 못한 경우, 탐색을 종료
		if (!flag) break;
	}

	std::cout << sequence.size() << " " << *(sequence.end() - 1);

	return 0;
}