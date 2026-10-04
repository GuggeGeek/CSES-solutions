#include <iostream>

using namespace std;
long long st[1000001]; // считаем факториал от 1 до 100000
const long long mod = 1e9 + 7;

long long modpov(long long a, long long b, long long m) {
	if (b == 0) return 1;
	if (b % 2 == 1) return modpov(a, b - 1, m) * a % m;
	long long h = modpov(a, b / 2, m);
	return h * h % mod;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	st[1] = 1; st[0] = 1;
	for (int l = 2; l < 1000001; l++) {
		st[l] = st[l - 1] * l % mod;
	}

	int n = 0;
	cin >> n;
	for (int l = 0; l < n; l++) {
		int a = 0, b = 0;
		cin >> a >> b;
		cout << st[a] * modpov((st[b] * st[a - b] % mod), mod - 2, mod) % mod << "\n";
	}

	return 0;
}