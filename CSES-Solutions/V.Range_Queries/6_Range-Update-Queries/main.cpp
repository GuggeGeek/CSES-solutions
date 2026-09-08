#include <iostream>
#include <vector>

using namespace std;

int n = 0;
vector<long long> list;

void add(int k, long long x) {
	list[k] += x;
	while (k > 1) {
		if (k % 2 == 1)list[k / 2] = list[k] + list[k - 1]; // k справа
		else list[k / 2] = list[k] + list[k + 1]; // k слева
		k /= 2;
	}
}

long long sum(int k) { // 
	long long s = 0;
	int a = n;
	int b = n + k - 1;
	while (a <= b) {
		if (a % 2 == 1) s += list[a++];
		if (b % 2 == 0) s += list[b--];
		a /= 2;
		b /= 2;
	}
	return s;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int q = 0;
	cin >> n >> q;
	list.assign(n * 2, 0);
	long long last = 0;
	for (int l = 1; l <= n; l++) {
		long long x = 0;
		cin >> x;
		add(l + n - 1, x - last);
		last = x;
	}

	for (int l = 1; l <= q; l++) {
		int type = 0;
		cin >> type;

		if (type == 1) { // добавить числа в диапазон
			int a = 0, b = 0;
			long long u = 0;
			cin >> a >> b >> u;
			add(a + n - 1, u);
			if (b != n) {
				add(b + n, -u);
			}
		}
		else { // вывести значение для индекса k
			int k = 0;
			cin >> k;
			cout << sum(k) << "\n";
		}
	}
	return 0;
}