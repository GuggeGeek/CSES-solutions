#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0, m = 0;
	int Ax = 0, Ay = 0, Bx = 0, By = 0;
	cin >> n >> m;
	vector<vector<int>> matrix(n + 2, vector<int>(m + 2, 0));
	for (int l = 1; l <= n; l++) {
		for (int j = 1; j <= m; j++) {
			char actual;
			cin >> actual;
			if (actual != '#') {
				if (actual == '.') matrix[l][j] = 1;
				else if (actual == 'A') {
					matrix[l][j] = 2;
					Ax = l; Ay = j;
				}
				else {
					matrix[l][j] = 3;
					Bx = l; By = j;
				}
			}
		}
	}

	vector<vector<bool>> visited(n + 2, vector<bool>(m + 2, 0));
	vector<vector<int>> distances(n + 2, vector<int>(m + 2, 0));
	vector<vector<char>> buk(n + 2, vector<char>(m + 2, 0));
	queue <pair<int, int>> q;

	visited[Ax][Ay] = true;
	distances[Ax][Ay] = 0;
	q.push({ Ax, Ay });
	while (!q.empty()) {
		auto r = q.front(); q.pop();
		int x = r.first, y = r.second;
		if (x == Bx && y == By) {
			cout << "YES" << "\n" << distances[x][y] << "\n";
			string ans = "";
			while (x != Ax || y != Ay) {
				ans += buk[x][y];

				if (buk[x][y] == 'U') x++;
				else if (buk[x][y] == 'D') x--;
				else if (buk[x][y] == 'L') y++;
				else if (buk[x][y] == 'R') y--;
			}
			for (int it = ans.length() - 1; it >= 0; it--) {
				cout << ans[it];
			}
			return 0;
		}
		if (matrix[x - 1][y] > 0 && !visited[x - 1][y]) {
			q.push({ x - 1, y });
			distances[x - 1][y] = distances[x][y] + 1;
			visited[x - 1][y] = true;
			buk[x - 1][y] = 'U';
		}
		if ( matrix[x + 1][y] > 0 && !visited[x + 1][y]) {
			q.push({ x + 1, y });
			distances[x + 1][y] = distances[x][y] + 1;
			visited[x + 1][y] = true;
			buk[x + 1][y] = 'D';
		}
		if (matrix[x][y - 1] > 0 && !visited[x][y - 1]) {
			q.push({ x, y - 1 });
			distances[x][y - 1] = distances[x][y] + 1;
			visited[x][y - 1] = true;
			buk[x][y - 1] = 'L';
		}
		if (matrix[x][y + 1] > 0 && !visited[x][y + 1]) {
			q.push({ x , y + 1 });
			distances[x][y + 1] = distances[x][y] + 1;
			visited[x][y + 1] = true;
			buk[x][y + 1] = 'R';
		}
	}
	cout << "NO";

	return 0;
}