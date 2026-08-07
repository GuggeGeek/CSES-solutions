#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	cin >> n;
	vector<vector<long long>> matrix(n + 1, vector<long long>(n + 1, 0));
	for (int l = 1; l <= n; l++) {
		for (int j = 1; j <= n; j++) {
			char s;
			cin >> s;
			if (s == '*') matrix[l][j] = -1;
		}
	}

	if (matrix[1][1] == -1) {
		cout << 0;
		return 0;
	}
	matrix[1][0] = 1;

	for (int l = 1; l <= n; l++) {
		for (int j = 1; j <= n; j++) {
			if (matrix[l][j] == -1) matrix[l][j] = 0;
			else matrix[l][j] = (matrix[l - 1][j] + matrix[l][j - 1]) % 1000000007;
		}
	}

	cout << matrix[n][n];
	return 0;
}