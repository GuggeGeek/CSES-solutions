#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0, q = 0;
	cin >> n >> q;
	vector<vector<long long>> st(20, vector<long long>(n + 1, 0));
	for (int l = 1; l <= n; l++) cin >> st[0][l];

	for (int l = 1; (1 << l) <= n; l++) { // 2 в степени l
		for (int j = 1; j + (1 << l - 1) <= n; j++) {
			st[l][j] = min(st[l - 1][j], st[l - 1][j + (1 << (l - 1))]);
		}
	}

	for (int l = 0; l < q; l++) {
		int a = 0, b = 0;
		cin >> a >> b;
		int k = b - a + 1, step = __lg(k); // расстояние промежутка
		cout << min(st[step][b - (1 << step) + 1], st[step][a]) << "\n";
	}

	return 0;
}