#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<tuple<int, int, long long>> list;
	for (int l = 0; l < m; l++) {
		int from, to;
		long long w;
		cin >> from >> to >> w;
		list.push_back(tuple(from, to, w) );
	}
	vector<long long> distance(n + 1, 0);
	vector<int> parents(n + 1, 0);
	for (int l = 0; l <= n - 1; l++) {
		for (auto const &now : list) {
			auto [from, to, w] = now;
			if (distance[to] > distance[from] + w) {
				distance[to] = distance[from] + w;
				parents[to] = from;
			}
		}
	}
	for (auto const &now : list) {
		auto [from, to, w] = now;
		if (distance[to] > distance[from] + w) {
			parents[to] = from;
			cout << "YES" << "\n";
			int x = to;
			for (int l = 0; l < n; l++) x = parents[x];
			int v = x;
			vector<int> ans;
			while (true) {
				ans.push_back(v);
				v = parents[v];
				if (v == x) break;
			}
			ans.push_back(x);
			for (int l = ans.size() - 1; l >= 0; l--) {
				cout << ans[l] << " ";
			}
			
			return 0;
		}
	}
	cout << "NO";
	return 0;
}