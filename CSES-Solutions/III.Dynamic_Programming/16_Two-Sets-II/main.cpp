#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	cin >> n;
	long long total_sum = n * (n + 1) / 2;
	if (total_sum % 2 == 1) {
		cout << 0;
		return 0;
	}
	vector<long long> dp(total_sum + 1, 0);
	dp[0] = 1;
	for (int l = 1; l < n; l++) {
		long long local_sum = l * (l + 1) / 2;
		for (int j = local_sum; j >= l; j--) {
			dp[j] = (dp[j] + dp[j - l]) % 1000000007;
		}
	}
	long long pol = (total_sum + 1) / 2;
	cout << dp[pol];

	return 0;
}