#include <iostream>
#include <vector>

using namespace std;

const int maxi = 100001;
vector<int> list[maxi];
vector<bool> visited(maxi, false);
vector<int> last(maxi);

void dfs(int x) {
	visited[x] = true;
	for (auto now : list[x]) {
		if (visited[now] && last[x] != now) { // ответ
			vector<int> ans = { now };
			int r = x;
			while (r != now) {
				ans.push_back(r);
				r = last[r];
			}
			ans.push_back(now);
			cout << ans.size() << "\n";
			for (auto act : ans) {
				cout << act << " ";
			}
			exit(0);
		}
		else if (!visited[now]) {
			last[now] = x;
			dfs(now);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0, m = 0;
	cin >> n >> m;
	for (int l = 0; l < m; l++) {
		int from, to;
		cin >> from >> to;
		list[from].push_back(to);
		list[to].push_back(from);
	}

	for (int l = 1; l <= n; l++) if (!visited[l]) dfs(l);

	cout << "IMPOSSIBLE";

	return 0;
}