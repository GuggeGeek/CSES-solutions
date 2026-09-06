#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n = 0;
vector <long long> tree;

void add(int k, long long x) {
	tree[k] = x;
	while (k > 1) {
		if (k % 2 == 1) tree[k / 2] = min(tree[k - 1], tree[k]);   // стоит справа
		else tree[k / 2] = min(tree[k + 1], tree[k]); // стоит слева
		k /= 2;
	}
}

long long range_min(int a, int b) {
	long long mins = 1e18;
	while (a <= b) {
		if (a % 2 == 1) mins = min(mins, tree[a++]);  // стоит справа
		if (b % 2 == 0) mins = min(mins, tree[b--]);  // стоит слева
		a /= 2;
		b /= 2; 
	}
	return mins;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int q = 0;
	cin >> n >> q;
	tree.assign(2 * n, 0);
	for (int l = 1; l <= n; l++) {
		long long x = 0;
		cin >> x;
		add(l + n - 1, x);
	}

	for (int j = 1; j <= q; j++) {
		int type = 0;
		cin >> type;
		if (type == 1) { // обновить значение
			int k = 0;
			long long u = 0;
			cin >> k >> u;
			add(k + n - 1, u);
		}
		else { // вывести минимум по отрезку
			int a = 0, b = 0;
			cin >> a >> b;
			cout << range_min(a + n - 1, b + n - 1) << "\n";
		}
	}

	return 0;
}