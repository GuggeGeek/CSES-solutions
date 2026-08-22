#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

const long long INFo = -1e18;
const long long INF = 1e18;
const int maxi = 2501;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<tuple<int, int, long long>> list;
	for (int l = 0; l < m; l++) {
		int a, b;
		long long w;
		cin >> a >> b >> w;
		list.push_back(tuple(a, b, w));
	}
	vector<long long> visited(maxi, INFo);
	visited[1] = 0;
	for (int l = 1; l <= n - 1; l++) {
		bool flag = false;
		for (auto now : list) {
			auto [a, b, w] = now;
			if (visited[a] != INFo && visited[a] + w > visited[b]) {
				flag = true;
				visited[b] = visited[a] + w;
			}
		}
		if (!flag) break;
	}

	for (int l = 1; l <= n; l++) {
		bool flag = false;
		for (auto now : list) {
			auto [a, b, w] = now;
			if (visited[a] != INFo && visited[a] + w > visited[b]) {
				flag = true;
				visited[b] = 1e18;
			}
		}
		if (!flag) break;
	}

	if (visited[n] >= 1e17)cout << -1;
	else cout << visited[n];

	return 0;
}