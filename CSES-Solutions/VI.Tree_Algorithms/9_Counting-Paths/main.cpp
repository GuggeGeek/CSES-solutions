#include <iostream>
#include <vector>

using namespace std;
int n = 0, q = 0;
vector<int> st[200001];
int parent[200001];
int depth[200001]; // высота >= 1
int step[19][200001];
int ans[200001];

void dfs(int from, int to, int d) {
	step[0][to] = from;
	depth[to] = d;
	for (auto now : st[to]) {
		if (now == from) continue;
		parent[now] = to;
		dfs(to, now, d + 1);
	}
}

void dfs2(int from, int to) {
	for (auto now : st[to]) {
		if (now == from) continue;
		dfs2(to, now);
		ans[to] += ans[now];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	step[0][1] = 1;
	cin >> n >> q;
	for (int l = 0; l < n - 1; l++) {
		int a = 0, b = 0;
		cin >> a >> b;
		st[a].push_back(b);
		st[b].push_back(a);
	}

	dfs(0, 1, 1);
	
	for (int l = 1; l < 19; l++) {
		for (int j = 1; j <= n; j++) {
			step[l][j] = step[l - 1][step[l - 1][j]];
		}
	}

	for (int l = 1; l <= q; l++) {
		int aori = 0, bori = 0;
		cin >> aori >> bori;

		int a = aori, b = bori;
		if (depth[a] > depth[b]) swap(a, b);
		for (int j = 18; j >= 0; j--) {
			if ((1 << j) & depth[b] - depth[a]) b = step[j][b];
		}

		int lca = a;
		if (a != b) {
			for (int j = 18; j >= 0; j--) {
				if (step[j][a] != step[j][b]) {
					a = step[j][a];
					b = step[j][b];
				}
			}
			lca = parent[a];;
		}
		
		
		ans[aori]++;
		ans[bori]++;
		ans[lca]--;
		if (parent[lca] != 0) ans[parent[lca]]--;
	}

	dfs2(0, 1);

	for (int l = 1; l <= n; l++) {
		cout << ans[l] << "\n";
	}

	return 0;
}