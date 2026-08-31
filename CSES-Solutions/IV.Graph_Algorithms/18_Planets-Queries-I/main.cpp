#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0, q = 0;
	cin >> n >> q;
	vector<vector<int>> dp(31, vector<int>(n + 1, 0));
	for (int l = 1; l <= n; l++) cin >> dp[0][l]; // если сделаем 1 шагов(2 в степени 0),то окажемся в точке l 
	for (int l = 1; l <= 30; l++) {
		for (int j = 1; j <= n; j++) {
			dp[l][j] = (dp[l - 1][dp[l - 1][j]]);
		}
	}

	for (int l = 1; l <= q; l++) {
		int x = 0;
		long long k = 0;
		cin >> x >> k;
		for (int j = 0; j <= 30; j++) {
			if(k & (1LL << j)) x = dp[j][x];
		}
		cout << x << "\n";
	}

	return 0;
}