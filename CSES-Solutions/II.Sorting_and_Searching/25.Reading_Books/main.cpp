#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	cin >> n;
	long long sum = 0, maxi = 0;
	for (int l = 0; l < n; l++) {
		long long x = 0;
		cin >> x;
		sum += x;
		maxi = max(x, maxi);
	}
	if (maxi * 2 > sum) cout << maxi * 2;
	else cout << sum;

	return 0;
}