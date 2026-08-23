#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;

const long long INF = 1e18;
vector<pair<long long, int>> list[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0, m = 0;
	cin >> n >> m;
	for (int l = 0; l < m; l++) {
		int from, to;
		long long w;
		cin >> from >> to >> w;
		list[from].push_back(pair(w, to));
	}

	vector<vector<long long>> visit(n + 1, vector<long long>(2, INF));
	priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> pq;
	visit[1][0] = 0;
	pq.push(tuple(0, 1, 0));
	while (!pq.empty()) {
		auto [w, a, act] = pq.top(); pq.pop();
		if (w > visit[a][act]) continue;
		for (auto now : list[a]) {
			auto [wn, aw] = now;
			if (act == 0) {
				if (visit[aw][0] > w + wn) {
					visit[aw][0] = w + wn;
					pq.push(tuple(visit[aw][0], aw, 0));
				}
				if (visit[aw][1] > w + wn / 2) {
					visit[aw][1] = w + wn / 2;
					pq.push(tuple(visit[aw][1], aw, 1));
				}
			}
			else if (act == 1) {
				if (visit[aw][1] > w + wn) {
					visit[aw][1] = w + wn;
					pq.push(tuple(visit[aw][1], aw, 1));
				}
			}
		}
	}

	cout << visit[n][1];
	return 0;
}