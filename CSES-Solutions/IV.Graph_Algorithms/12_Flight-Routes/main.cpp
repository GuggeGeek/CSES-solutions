#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector <pair<long long, int>> list[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	for (int l = 0; l < m; l++) {
		int from = 0, to = 0;
		long long w = 0;
		cin >> from >> to >> w;
		list[from].push_back({ w , to });
	}
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
	vector <priority_queue <long long>> distance(n+1);
	distance[1].push(0);
	pq.push({ 0 , 1 });
	while (!pq.empty()) {
		auto [w, from] = pq.top(); pq.pop();
		if (distance[from].size() == k && w > distance[from].top()) continue;
		for (auto now : list[from]) {
			auto [road, to] = now;
			if (distance[to].size() < k || road + w < distance[to].top()) {
				if (distance[to].size() == k) {
					distance[to].pop();
				}
				distance[to].push(w + road);
				pq.push({ w + road, to });
			}
		}
	}
	vector<long long> ans(distance[n].size());
	int r = 0;
	while (!distance[n].empty()) {
		ans[r] = distance[n].top();  distance[n].pop();
		r++;
	}
	for (int l = ans.size() - 1; l >= 0; l--) cout << ans[l] << " ";
	return 0;
}