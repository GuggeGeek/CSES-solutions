#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0, q = 0;
	cin >> n >> q;
	vector<long long> pref(n + 1, 0);
	for (int l = 1; l <= n; l++) {
		int x = 0;
		cin >> x;
		pref[l] = pref[l - 1] + x;
	}

	for (int l = 1; l <= q; l++) {
		int a = 0, b = 0;
		cin >> a >> b;
		cout << pref[b] - pref[a - 1] << "\n";
	}

	return 0;
}