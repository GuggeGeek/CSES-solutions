#include <iostream>

using namespace std;
int n = 0;
const long long MOD = 1e9 + 7;

long long func(long long x, long long y) {
	if (y == 0) return 1;

	if (y % 2 == 1) return (func(x, y - 1) * x) % MOD;
	x = func(x, y / 2);
	return (x * x) % MOD;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int l = 0; l < n; l++) {
		long long x = 0, y = 0;
		cin >> x >> y;
		cout << func(x, y) << "\n";
	}

	return 0;
}