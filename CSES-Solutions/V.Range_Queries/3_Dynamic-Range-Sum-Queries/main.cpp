#include <iostream>
#include <vector>

using namespace std;
int n = 0;
vector<long long> list;

void add(int k, long long x) {
	while (k <= n) {
		list[k] += x;
		k += k & -k; // побитовая магия
	}
}

long long sum(int k) { // сумма от 1 до k
	long long s = 0;
	while (k >= 1) {
		s += list[k];
		k -= k & -k;
	}
	return s;
}

long long range_sum(int a, int b) {
	return sum(b) - sum(a - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int q = 0;
	cin >> n >> q;
	list.assign(n + 1, 0);
	for (int l = 1; l <= n; l++) {
		long long x = 0;
		cin >> x;
		add(l, x);
	}

	for (int l = 1; l <= q;l++) {
		int type = 0;
		cin >> type;

		if (type == 1) { // меняем
			int k = 0;
			long long u = 0;
			cin >> k >> u;
			long long act = range_sum(k, k);
			add(k, u - act);
		}
		else if (type == 2) { // выводим
			int a = 0, b = 0;
			cin >> a >> b;
			cout << range_sum(a, b) << "\n";
		}
	}

	return 0;
}