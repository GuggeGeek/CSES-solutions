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
	for (int j = 1; j <= n; j++) {
		cin >> st[0][j];
	}

	for (int l = 1; (1 << l) <= n; l++) { // степень
		for (int j = 1; j + (1 << l) -1 <= n; j++) { // наше место
			st[l][j] = min(st[l - 1][j], st[l - 1][j + (1 << (l - 1))]); // заполняем таблицу
		}
	}

	for (int l = 1; l <= q; l++) {
		int a = 0, b = 0;
		cin >> a >> b;
		int k = __lg(b - a + 1);
		cout << min(st[k][a], st[k][b - (1 << k) + 1]) << "\n";
	}

	return 0;
}