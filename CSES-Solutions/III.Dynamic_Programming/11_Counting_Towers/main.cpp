#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	cin >> n;
	vector<int> test(n);
	for (int l = 0; l < n; l++) cin >> test[l];

	vector<vector<long long>> dp(1000000 + 1, vector<long long>(2, 0));
	dp[1][0] = 1;
	dp[1][1] = 1;
	for (int l = 2; l <= 1000000; l++) {
		dp[l][0] = (2 * dp[l - 1][0] + 1 * dp[l - 1][1]) % 1000000007;
		dp[l][1] = (1 * dp[l - 1][0] + 4 * dp[l - 1][1]) % 1000000007;
	}
	for (auto now : test) {
		cout << (dp[now][0] + dp[now][1]) % 1000000007 << "\n";
	}
	return 0;
}