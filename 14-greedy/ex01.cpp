/* 보조 배터리 */

#include <iostream>
#include <vector>
#include <algorithm>

int battery[3];
int N;

std::vector<std::pair<long long, int> > charger;
long long price;
int type;

int count;
long long total;

bool compare(std::pair<int, int> a, std::pair<int, int> b) {
	return a.first < b.first;
}

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::cin >> battery[0] >> battery[1] >> battery[2];
	std::cin >> N;
	for (int i = 0; i < N; ++i) {
		std::cin >> price >> type;
		charger.push_back({price, type});
	}

	std::sort(charger.begin(), charger.end(), compare);
	for (size_t i = 0; i < charger.size(); ++i) {
		if (charger[i].second == 0) {
			if (battery[0] > 0) {
				count++;
				total += charger[i].first;
				battery[0]--;
			} else if (battery[2] > 0) {
				count++;
				total += charger[i].first;
				battery[2]--;
			}
		} else { // charger[i].second == 1
			if (battery[1] > 0) {
				count++;
				total += charger[i].first;
				battery[1]--;
			} else if (battery[2] > 0) {
				count++;
				total += charger[i].first;
				battery[2]--;
			}
		}
	}

	std::cout << count << " " << total;

	return 0;
}