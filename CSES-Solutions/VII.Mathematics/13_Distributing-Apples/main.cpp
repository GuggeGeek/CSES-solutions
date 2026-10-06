#include <iostream>

using namespace std;

const long long mod = 1e9 + 7;
long long factorio[2000001];

long long st(long long a, long long b) {
	if (b == 0) return 1;
	if (b % 2 == 1) return st(a, b - 1) * a % mod;
	long long h = st(a, b / 2);
	return h * h % mod;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	factorio[0] = 1, factorio[1] = 1;
	for (int l = 2; l < 2000001; l++) factorio[l] = factorio[l - 1] * l % mod;

	int n = 0, m = 0;
	cin >> n >> m; // child apple
	n = n + m - 1;

	cout << factorio[n] * st(factorio[m] * (factorio[n - m] % mod) % mod, mod - 2) % mod;

	return 0;
}