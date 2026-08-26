#include <iostream>
#include <vector>

using namespace std;

vector<int> list[100001];
vector<int> act(100001);
vector<int> parents(100001);

void dfs(int x) {
	act[x] = 1;
	for (auto now : list[x]) {
		if (act[now] == 0) {
			parents[now] = x;
			dfs(now);
		}
		else if (act[now] == 1) { // обработка
			vector <int> ans{ x };
			int last = parents[x];
			while (last != now) {
				ans.push_back(last);
				last = parents[last];
			}
			cout << ans.size() + 2 << "\n" << now << " ";
			for (int l = ans.size() - 1; l >= 0; l--) {
				cout << ans[l] << " ";
			}
			cout << now;
			exit(0);
		}
	}
	act[x] = 2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0, m = 0;
	cin >> n >> m;
	for (int l = 0; l < m; l++) {
		int x, y;
		cin >> x >> y;
		list[x].push_back(y);
	}

	for (int l = 1; l <= n; l++) if(act[l] == 0) dfs(l);

	cout << "IMPOSSIBLE";

	return 0;
}