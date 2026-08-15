#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct dpr {
	long long ans;
	long long sum;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	cin >> n;
	vector<long long> number(n, 0);
	for (int l = 0; l < n; l++) cin >> number[l];

	vector<vector<dpr>> dp(n, vector<dpr>(n, { 0,0 }));
	for (int l = 0; l < n; l++) dp[l][l] = { number[l],number[l] }; // баз.случай

	for (int start = 1; start < n; start++) {
		for (int R = start, L = 0; R < n; R++, L++) {
			dp[L][R] = { max(dp[L][L].ans + (dp[L + 1][R].sum - dp[L + 1][R].ans), dp[R][R].ans + (dp[L][R - 1].sum - dp[L][R - 1].ans)), dp[L][R - 1].sum + dp[R][R].sum };
		}
	}
	cout << dp[0][n - 1].ans;
	return 0;
}