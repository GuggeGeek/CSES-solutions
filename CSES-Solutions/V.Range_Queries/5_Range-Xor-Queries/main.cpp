#include <iostream>
#include <vector>

using namespace std;

int n = 0;
vector<long long> list;

void add(int k, long long x) {
	list[k] = x;
	while (k > 1) {
		if (k % 2 == 0)list[k / 2] = list[k] ^ list[k + 1]; // к слева
		if (k % 2 == 1)list[k / 2] = list[k] ^ list[k - 1]; // к справа
		k /= 2;
	}
}

long long range_xor(int a, int b) {
	long long s = 0;
	while (a <= b) {
		if (a % 2 == 1) s^= list[a++];
		if (b % 2 == 0) s^= list[b--];
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
	list.assign(2 * n, 0);
	for (int l = 1; l <= n; l++) {
		long long x;
		cin >> x;
		add(l + n - 1, x);
	}

	for (int l = 1; l <= q; l++) {
		int a = 0, b = 0;
		cin >> a >> b;
		cout << range_xor(a + n - 1, b + n - 1) << "\n";
	}

	return 0;
}