#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int const INF = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0, x = 0;
	cin >> n >> x;
	vector<int>coins(n);
	for (int l = 0; l < n; l++) cin >> coins[l];

	vector<int> value(x + 1, INF);
	value[0] = 0;
	for (int l = 1; l <= x; l++) {
		for (auto now : coins) {
			if (l - now >= 0) value[l] = min(value[l], (value[l - now] + 1));
		}
	}
	if (value[x] == INF) cout << -1;
	else cout << value[x];
	return 0;
}