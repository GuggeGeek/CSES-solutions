#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0, sum = 0, ans = 0;
	cin >> n;
	vector<int> coins(n);
	for (int l = 0; l < n; l++) {
		cin >> coins[l];
		sum += coins[l];
	}

	vector<int> dp(sum + 1, 0);
	dp[0] = 1;
	for (auto now : coins) {
		for (int l = sum; l > 0; l--) {
			if (l - now >= 0 && dp[l - now] == 1) {
				if (dp[l] == 0) ans++;
				dp[l] = 1;
			}
		}
	}
	cout << ans << "\n";
	for (int l = 1; l <= sum; l++) if (dp[l] == 1) cout << l << " ";

	return 0;
}