#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> list[100001];
vector<int> dp(100001, -1);
vector<int> parents(100001);
vector<bool> visit(100001, false);
vector<int> topo;

void dfs(int x) {
	for (auto now : list[x]) {
		if (!visit[now]) {
			dfs(now);
		}
	}
	topo.push_back(x);
	visit[x] = true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0, m = 0;
	cin >> n >> m;
	for(int l = 0; l < m; l++){
		int from = 0, to = 0;
		cin >> from >> to;
		list[from].push_back(to);
	}

	for (int l = 1; l <= n; l++) if (!visit[l]) dfs(l);

	dp[1] = 1;
	for (int l = topo.size() - 1; l >= 0; l--) {
		for (auto now : list[topo[l]]) {
			if (dp[topo[l]] + 1 > dp[now] && dp[topo[l]] != -1) {
				dp[now] = dp[topo[l]] + 1;
				parents[now] = topo[l];
			}
		}
	}

	if (dp[n] == -1) {
		cout << "IMPOSSIBLE";
		return 0;
	}

	int last = parents[n];
	vector<int> ans;
	while (last != 1) {
		ans.push_back(last);
		last = parents[last];
	}

	cout << dp[n] << "\n" << 1 << " ";
	for (int l = ans.size() - 1; l >= 0; l--) {
		cout << ans[l] << " ";
	}
	cout << n;

	return 0;
}