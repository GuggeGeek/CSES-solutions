#include <iostream>
#include <vector>

using namespace std;

int const maxi = 100005;
vector<int> list[maxi];
vector<bool> visited(maxi, false);
vector<int> ch;

void dfs(int x) {
	visited[x] = true;
	for (auto s : list[x]) {
		if(!visited[s]) dfs(s);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0, m = 0; // города , дороги
	cin >> n >> m;
	for (int l = 0; l < m; l++) {
		int from = 0, to = 0;
		cin >> from >> to;
		list[from].push_back(to);
		list[to].push_back(from);
	}

	for (int l = 1; l <= n; l++) {
		if (!visited[l]) {
			dfs(l);
			ch.push_back(l);
		}
	}

	cout << int(ch.size()) - 1 << "\n";
	if (!ch.empty()) {
		for (int l = 1; l < ch.size(); l++) {
			cout << 1 << " " << ch[l] << "\n";
		}
	}
	return 0;
}