#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
vector<pair<long long, int>> list[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0, m = 0;
	cin >> n >> m;
	vector<long long> minprice(n + 1, 1e18); minprice[1] = 0;
	vector<long long> minroad(n + 1, 0); minroad[1] = 1;
	vector<int> minfly(n + 1, 1e9); minfly[1] = 0;
	vector<int> maxfly(n + 1, 0);
	for (int l = 0; l < m; l++) {
		int from = 0, to = 0;
		long long price = 0;
		cin >> from >> to >> price;
		list[from].push_back(pair(price, to));
	}

	pq.push(pair(0, 1));
	while (!pq.empty()) {
		auto [price, from] = pq.top();pq.pop();
		if (price > minprice[from]) continue;
		for (auto now : list[from]) {
			auto [price2, to] = now;
			if (price + price2 < minprice[to]) {
				minprice[to] = price + price2;
				minfly[to] = minfly[from] + 1;
				minroad[to] = minroad[from];
				maxfly[to] = maxfly[from] + 1;
				pq.push(pair(minprice[to], to));
			}
			else if (price + price2 == minprice[to]) {
				minroad[to] = (minroad[from] + minroad[to]) % 1000000007;
				minfly[to] = min(minfly[to], minfly[from] + 1);
				maxfly[to] = max(maxfly[to], maxfly[from] + 1);
			}
		}
	}

	cout << minprice[n]<< " " << minroad[n] << " " << minfly[n] << " " << maxfly[n];

	return 0;
}