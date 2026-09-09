#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0, q = 0;
	cin >> n >> q;
	vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
	for (int l = 1; l <= n; l++) {
		for (int j = 1; j <= n; j++) {
			char x;
			cin >> x;
			if (x == '*') x = int(1);
			else x = int(0);
			dp[l][j] = dp[l - 1][j] + dp[l][j - 1] + x - dp[l - 1][j - 1]; // y,x
		}
	}

	for (int l = 1; l <= q; l++) {
		int y1, y2, x1, x2;
		cin >> y1 >> x1 >> y2 >> x2;
		int maxy = max(y1, y2), maxx = max(x1, x2), minx = min(x1, x2), miny = min(y1, y2);
		cout << dp[maxy][maxx] - dp[miny - 1][maxx] - dp[maxy][minx - 1] + dp[miny - 1][minx - 1] << "\n";
	}

	return 0;
}