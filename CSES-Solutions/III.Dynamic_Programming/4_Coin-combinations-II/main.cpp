#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long const INF = 1e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0, x = 0;
	cin >> n >> x;
	vector<int> coins(n);
	for (int l = 0; l < n; l++) cin >> coins[l];

	vector<long long> value(x + 1, 0); value[0] = 1;
	for (auto now : coins) {
		for (int l = 1; l <= x; l++) {
			if (l - now >= 0) value[l] = (value[l] + value[l - now]) % 1000000007;
		}
	}
	
	cout << value[x];

	return 0;
}