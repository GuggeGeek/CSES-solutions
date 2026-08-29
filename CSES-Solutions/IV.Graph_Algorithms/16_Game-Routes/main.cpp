#include <iostream>
#include <vector>

using namespace std;

vector<int> list[100001];
vector<bool> visit(100001, false);
vector<int> topo;
vector<long long> dp(100001, 0);

void dfs(int x) {
	for (auto now : list[x]) {
		if (!visit[now]) {
			dfs(now);
		}
	}
	visit[x] = true;
	topo.push_back(x);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0, m = 0;
	cin >> n >> m;
	for (int l = 0; l < m; l++) {
		int from = 0, to = 0;
		cin >> from >> to;
		list[from].push_back(to);
	}

	for (int l = 1; l <= n; l++) {
		if (!visit[l]) dfs(l);
	}
	dp[1] = 1;

	for (int l = topo.size() - 1; l >= 0; l--) {
		for (auto now : list[topo[l]]) {
			dp[now] = (dp[now] + dp[topo[l]]) % 1000000007;
		}
	}

	cout << dp[n];
	return 0;
}