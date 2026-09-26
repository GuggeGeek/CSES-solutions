#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> road[200001];
int n = 0;
int table[19][200005];
int d[200001];

void dfs(int a, int b) {
	for (auto now : road[b]) {
		if (now == a) continue;
		table[0][now] = b;
		d[now] = d[b] + 1;
		dfs(b, now);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int q = 0;
	cin >> n >> q;
	for (int l = 0; l < n - 1; l++) {
		int a = 0, b = 0;
		cin >> a >> b;
		road[a].push_back(b);
		road[b].push_back(a);
	}

	table[0][1] = 1;
	dfs(0, 1);

	for (int l = 1; l < 19; l++) {
		for (int j = 1; j <= n; j++) {
			table[l][j] = table[l - 1][table[l - 1][j]];
		}
	}

	for (int l = 0; l < q; l++) {
		int a = 0, b = 0;
		cin >> a >> b;
		int u = a, v = b;

		if (d[a] < d[b]) swap(a, b);
		int diff = d[a] - d[b];
		for (int j = 18; j >= 0; j--) {
			if ((1 << j) & diff) {
				a = table[j][a];
			}
		}

		if (a != b) {
			for (int j = 18; j >= 0; j--) {
				if (table[j][a] != table[j][b]) {
					a = table[j][a];
					b = table[j][b];
				}
			}
			a = table[0][a];
		}
		cout << d[u] + d[v] - 2 * d[a] << "\n";
	}

	return 0;
}