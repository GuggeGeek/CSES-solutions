#include <iostream>
#include <vector>
using namespace std;

const long long mod = 1e9 + 7;
vector<long long> ans(1000001, 0);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	cin >> n;

	ans[2] = 1;
	for (int l = 3; l <= n; l++) {
		ans[l] = ((l - 1) * (ans[l - 1] + ans[l - 2])) % mod;
	}

	cout << ans[n];

	return 0;
}