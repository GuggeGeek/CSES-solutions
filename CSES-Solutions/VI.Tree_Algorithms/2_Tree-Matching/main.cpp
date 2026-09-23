#include <iostream>
#include <vector>

using namespace std;
int n = 0;
vector<int> st[200001];
vector<bool> used(200001, false);
int ans = 0;


void dfs(int a, int b) {
	for (auto now : st[b]) {
		if (now == a) continue;
		dfs(b, now);
		if (!used[b]) {
			if (!used[now]) {
				ans++;
				used[b] = true; used[now] = true;
			}
		}
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

	dfs(0, 1);
	cout << ans;
	return 0;
}