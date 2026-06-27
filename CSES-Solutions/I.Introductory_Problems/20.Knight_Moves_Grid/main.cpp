#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n = 0;
	cin >> n;
	vector <vector<int>> matrix( n , vector<int>( n , -1));
	queue<pair<int, int>> q;

	matrix[0][0] = 0;
	q.push({ 0 , 0 });

	int dx[8] = { 2 , 2 ,-2 ,-2, 1 , 1 ,-1 ,-1 };
	int dy[8] = { 1 , -1, 1 , -1 ,2 , -2, 2 ,-2 };

	while (!(q.empty())) {
		auto cur = q.front();
		q.pop();

		int x = cur.first;
		int y = cur.second;

		for (int l = 0; l < 8; l++) {
			int nx = dx[l] + x;
			int ny = dy[l] + y;

			if (nx >= 0 && ny >= 0 && nx < n && ny < n && matrix[nx][ny] == -1) {
				matrix[nx][ny] = matrix[x][y] + 1;
				q.push({nx, ny});
			}
		}
	}

	for (int y = 0; y < n; y++ ) {
		for (int x = 0; x < n;x++) {
			cout << matrix[x][y] << " ";
		}
		cout << "\n";
	}

	return 0;
}