#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int maxes = 1000005;
vector<int> obx[maxes];
int rooms = 0;
vector<bool>list(1000005, false);

void dfs(int s) {
	if (list[s]) return;
	list[s] = true;
	for (auto now : obx[s]) {
		dfs(now);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0, m = 0, ver = 1;
	cin >> n >> m;
	vector<vector<int>> matrix(n + 2, vector<int>(m + 2));
	for (int l = 1; l <= n; l++) {
		for (int j = 1; j <= m; j++) {
			char b;
			cin >> b;
			if (b == '.') {
				matrix[l][j] = ver;
				list[ver] = false;
				ver++;
			}
		}
	}

	if (ver == 1) {
		cout << 0;
		return 0;
	}
	for (int l = 1; l <= n; l++) {
		for (int j = 1; j <= m; j++) {
			if (matrix[l][j - 1] > 0) obx[matrix[l][j]].push_back(matrix[l][j - 1]);
			if (matrix[l][j + 1] > 0) obx[matrix[l][j]].push_back(matrix[l][j + 1]);
			if (matrix[l - 1][j] > 0) obx[matrix[l][j]].push_back(matrix[l - 1][j]);
			if (matrix[l + 1][j] > 0) obx[matrix[l][j]].push_back(matrix[l + 1][j]);
		}
	}

	for (int l = 1; l < ver; l++) {
		if (!list[l]){
			dfs(l);
			rooms++;
		}
	}

	cout << rooms;

	return 0;
}