#include <iostream>

using namespace std;

const long long MOD = 1e9 + 7;

long long func(long long a, long long b, long long mod) {
	if (b == 0) return 1;
	if (b % 2 == 1) return func(a, b - 1, mod) * a % mod;
	a = func(a, b / 2, mod) % mod;
	return a = a * a % mod;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0; 
	cin >> n;
	for (int l = 0; l < n; l++) {
		long long a, b, c;
		cin >> a >> b >> c;
		long long times = func(b, c, MOD - 1);
		cout << func(a, times, MOD) << "\n";
	}

	return 0;
}