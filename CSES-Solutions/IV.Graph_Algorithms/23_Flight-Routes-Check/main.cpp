#include <iostream>
#include <vector>

using namespace std;

vector<int> list[100001];
vector<int> listrev[100001];
vector<bool> visit;

void dfs1(int a) {
	for (auto now : list[a]) {
		if (!visit[now]) {
			visit[now] = true;
			dfs1(now);
		}
	}
}
void dfs2(int a) {
	for (auto now : listrev[a]) {
		if (!visit[now]) {
			visit[now] = true;
			dfs2(now);
		}
	}
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
		listrev[b].push_back(a);
	}
	visit.assign(n + 1, false);
	visit[1] = true;
	dfs1(1);
	for (int l = 2; l <= n; l++) {
		if (!visit[l]) {
			cout << "NO" << "\n" << "1 " << l;
			return 0;
		}
	}
	visit.assign(n + 1, false);
	visit[1] = true;
	dfs2(1);
	for (int l = 2; l <= n; l++) {
		if (!visit[l]) {
			cout << "NO" << "\n" << l << " 1";
			return 0;
		}
	}

	cout << "YES";

	return 0;
}