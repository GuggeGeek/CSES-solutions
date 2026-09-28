#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n = 0;
long long ans[200001];
vector<int> tree(200001, 1);
vector<int> st[200001];

void dfs(int from, int act, int d) {
	ans[1] += d;
	for (auto to : st[act]) {
		if (to == from) continue;
		dfs(act, to, d + 1);
		tree[act] += tree[to];
	}
}

void dfs2(int from, int act){
	if (act != 1) ans[act] = ans[from] - tree[act] + (n - tree[act]);
	for (auto to : st[act]) {
		if (to == from) continue;
		dfs2(act, to);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int l = 0; l < n - 1; l++) {
		int a = 0, b = 0;
		cin >> a >> b;
		st[a].push_back(b);
		st[b].push_back(a);
	}

	dfs(0, 1, 0);
	dfs2(0, 1);

	for (int l = 1; l <= n; l++) {
		cout << ans[l] << " ";
	}

	return 0;
}