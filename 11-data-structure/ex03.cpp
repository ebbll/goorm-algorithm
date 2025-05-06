/* 아이템 교환 */

#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

int N, Q;
std::string item;
std::set<std::string> G, F;
std::string a, b;
std::vector<std::string> res;

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::cin >> N >> Q;

	for (int i = 0; i < N; ++i) {
		std::cin >> item;
		G.insert(item);
	}
	for (int i = 0; i < N; ++i) {
		std::cin >> item;
		F.insert(item);
	}

	while (Q--) {
		std::cin >> a >> b;
		if (G.find(a) != G.end() && F.find(b) != F.end()){

			G.erase(a);
			F.erase(b);

			G.insert(b);
			F.insert(a);
		}
	}

	for (auto it: G) res.push_back(it);
	std::sort(res.begin(), res.end());
	for (auto it: res) std::cout << it << ' ';

	return 0;
}
