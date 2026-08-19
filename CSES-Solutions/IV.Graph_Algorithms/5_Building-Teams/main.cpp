#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxi = 100001;
vector<int> list[maxi];
vector<int> act(100001, -1);
bool flag = false;

void dfs(int x, int color) {
	act[x] = color;
	for (auto now : list[x]) {
		if (act[now] == color) { // дроп
			flag = true;
			return;
		}
		else if (act[now] == -1) { // обработка
			dfs(now , 3 - color);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0, m = 0;
	cin >> n >> m;
	for (int l = 0; l < m; l++) {
		int from = 0, to = 0;
		cin >> from >> to;
		list[from].push_back(to);
		list[to].push_back(from);
	}

	for (int l = 1; l <= n; l++) {
		if(act[l] == -1)dfs(l, 1);
	}

	if (flag) {
		cout << "IMPOSSIBLE";
	}
	else {
		for (int l = 1; l <= n; l++) {
			cout << act[l] << " ";
		}
	}
	return 0;
}