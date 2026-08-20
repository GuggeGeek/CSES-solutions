#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0, m = 0, herx = 0,hery = 0;
	cin >> n >> m;

	queue <tuple<int, int, int>>bfs;
	vector<vector<int>> matrix(1005, vector <int>(1005, 1e9)); // проход
	vector<vector<char>> hist(1005, vector<char>(1005));
	queue <tuple<int, int, int>> monsters;
	for (int l = 1; l <= n; l++) {
		for (int j = 1; j <= m; j++) {
			char r;
			cin >> r;
			if (r == '#') matrix[j][l] = -1; // стена
			else if (r == 'M') {
				monsters.push(tuple(j, l, 0));
				matrix[j][l] = 0;
			}
			else if (r == 'A') {
				bfs.push(tuple(j, l, 0));
				herx = j; hery = l;
			}
		}
		
	}
	while (!monsters.empty()) {
		auto r = monsters.front(); monsters.pop();
		int x = get<0>(r), y = get<1>(r), num = get<2>(r);
		if (x + 1 <= m && matrix[x + 1][y] == 1e9) {
			monsters.push(tuple(x + 1, y, num + 1));
			matrix[x + 1][y] = num + 1;
		}
		if (x - 1 >= 1 && matrix[x - 1][y] == 1e9) {
			monsters.push(tuple(x - 1, y, num + 1));
			matrix[x - 1][y] = num + 1;
		}
		if (y + 1 <= n && matrix[x][y + 1] == 1e9) {
			monsters.push(tuple(x, y + 1, num + 1));
			matrix[x][y + 1] = num + 1;
		}
		if (y - 1 >= 1 && matrix[x][y - 1] == 1e9) {
			monsters.push(tuple(x, y - 1, num + 1));
			matrix[x][y - 1] = num + 1;
		}
	}
	hist[herx][hery] = 'S';
	while (!bfs.empty()) {
		auto r = bfs.front(); bfs.pop();
		int x = get<0>(r), y = get<1>(r), num = get<2>(r);
		if (x == 1 || x == m || y == 1 || y == n) { //выход
			cout << "YES" << "\n";
			vector<char>ans;
			while (x != herx || y != hery) {
				ans.push_back(hist[x][y]);
				if (hist[x][y] == 'R') { x--; continue; }
				if (hist[x][y] == 'L') { x++; continue; }
				if (hist[x][y] == 'D') { y--; continue; }
				if (hist[x][y] == 'U') { y++; continue; }
			}
			cout << ans.size() << "\n";
			for (int l = ans.size() - 1; l >= 0; l--) {
				cout << ans[l];
			}
			exit(0);
		}
		if (x + 1 <= m && matrix[x + 1][y] > num + 1 && hist[x + 1][y] == 0) {
			hist[x + 1][y] = 'R';
			bfs.push(tuple(x + 1, y, num + 1));
		}
		if (x - 1 >= 1 && matrix[x - 1][y] > num + 1 && hist[x - 1][y] == 0) {
			hist[x - 1][y] = 'L';
			bfs.push(tuple(x - 1, y, num + 1));
		}
		if (y + 1 <= n && matrix[x][y + 1] > num + 1 && hist[x][y + 1] == 0) {
			hist[x][y + 1] = 'D';
			bfs.push(tuple(x, y + 1, num + 1));
		}
		if (y - 1 >= 1 && matrix[x][y - 1] > num + 1 && hist[x][y - 1] == 0) {
			hist[x][y - 1] = 'U';
			bfs.push(tuple(x, y - 1, num + 1));
		}
	}
	cout << "NO";
	return 0;
}