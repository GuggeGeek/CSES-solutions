#include <iostream>
#include <vector>

using namespace std;

int n = 0;

int ans(int a) {
	int ch = 1;
	for (int l = 2; l * l <= a; l++) { // выражение l*l <= n можно сказать как l <= корень n
		int act = 0;
		while (a % l == 0) {
			act++;
			a /= l;
		}
		if (act != 0) {
			act++;
			ch *= act;
		}
	}
	if (a > 1) ch *= 2;
	if (ch == 1) return 2;
	return ch;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int l = 0; l < n; l++) {
		int a = 0;
		cin >> a;
		if (a == 1) cout << 1 << "\n";
		else cout << ans(a) << "\n";
	}

	return 0;
}