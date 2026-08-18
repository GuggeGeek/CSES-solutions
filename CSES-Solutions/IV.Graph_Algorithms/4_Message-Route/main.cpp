#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

const int maxi = 100005;
vector<int> list[maxi];
queue<int> spi;
vector<bool> visited(maxi, false);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0, m = 0; // компьютеров, путей
	cin >> n >> m;
	for (int l = 0; l < m; l++) {
		int from = 0, to = 0;
		cin >> from >> to;
		list[from].push_back(to);
		list[to].push_back(from);
	}

	vector<int> last(maxi);
	spi.push(1);
	visited[1] = true;
	while (!spi.empty()) {
		int x = spi.front(); spi.pop();
		if (x == n) {
			vector<int> ans = { x };
			while (x != 1) {
				x = last[x];
				ans.push_back(x);
			}
			cout << ans.size() << "\n";

			for (int l = ans.size() - 1; l >= 0; l--) {
				cout << ans[l] << " ";
			}

			return 0;
		} 
		for (auto now : list[x]) {
			if (!visited[now]) {
				visited[now] = true;
				spi.push(now);
				last[now] = x;
			}
		}
	}

	cout << "IMPOSSIBLE";

	return 0;
}