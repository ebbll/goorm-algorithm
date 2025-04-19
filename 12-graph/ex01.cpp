/* 폭탄 해제 */

#include <iostream>
#include <vector>

int N, M;
int v1, v2;
int count;
std::vector<int> graph[302];
std::vector<std::pair<int, int> > edges;
std::vector<int> res;

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::cin >> N >> M;

	for (int i = 0; i < M; ++i) {
		std::cin >> v1 >> v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
		edges.push_back({v1, v2});
	}

	for (int i = 0; i < M; ++i) {
		if (graph[edges[i].first].size() == 1 || graph[edges[i].second].size() == 1)
			continue;
		res.push_back(i + 1);
	}

	if (!res.size()) std::cout << "-1";
	else
		for (size_t i = 0; i < res.size(); ++i) std::cout << res[i] << " ";

	return 0;
}