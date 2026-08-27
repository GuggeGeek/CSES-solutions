#include <iostream>
#include <vector>

using namespace std;

vector<int> list[100001];
vector<int> act(100001);
vector<int> ans;

void dfs(int x) {
	act[x] = 1;
	for (auto now : list[x]) {
		if (act[now] == 0) {
			dfs(now);
		}
		if (act[now] == 1) {
			cout << "IMPOSSIBLE";
			exit(0);
		}
	}
	act[x] = 2;
	ans.push_back(x);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0, m = 0;
	cin >> n >> m;
	for (int l = 0; l < m; l++) {
		int a = 0, b = 0;
		cin >> a >> b;
		list[a].push_back(b);
	}

	for (int l = 1; l <= n; l++) {
		if (act[l] == 0) dfs(l);
	}

	for (int l = ans.size() - 1; l >= 0; l--) {
		cout << ans[l] << " ";
	}

	return 0;
}