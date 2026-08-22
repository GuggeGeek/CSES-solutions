#include <iostream>
#include <vector>
#include <algorithm>;

using namespace std;

const long long INF = 1e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0, m = 0, q = 0;
	cin >> n >> m >> q;
	vector<vector<long long>> matrix(n + 1, vector<long long>(n + 1, INF));
	for (int l = 0; l < m; l++) {
		int a = 0, b = 0;
		long long c = 0;
		cin >> a >> b >> c;
		matrix[a][b] = min(c, matrix[a][b]);
		matrix[b][a] = matrix[a][b];
	}
	for (int l = 1; l < n + 1; l++) matrix[l][l] = 0;

	for (int k = 1; k <= n; k++) {
		for (int l = 1; l <= n; l++) {
			for (int j = 1; j <= n; j++) {
				matrix[l][j] = min(matrix[l][j], (matrix[l][k] + matrix[k][j]));
				matrix[j][l] = matrix[l][j];
			}
		}
	}

	for (int l = 0; l < q; l++) {
		int a, b;
		cin >> a >> b;
		if (matrix[a][b] == INF) cout << -1 << "\n";
		else cout << matrix[a][b] << "\n";
	}
	return 0;
}