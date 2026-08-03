#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0, a = 0, b = 0;
	cin >> n >> a >> b;
	vector<long long> pref(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		long long x;
		cin >> x;
		pref[i] = pref[i - 1] + x; // Строим массив префиксных сумм
	}
	multiset<long long> window;
	long long max_sum = -1e18;
	for (int i = a; i <= n; i++) {
		window.insert(pref[i - a]);
		if (i > b) {
			window.erase(window.find(pref[i - b - 1]));
		}
		long long current_min_pref = *window.begin();
		max_sum = max(max_sum, pref[i] - current_min_pref);
	}
	cout << max_sum;
	return 0;
}