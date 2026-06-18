#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n = 0;
	cin >> n;
	long long res = 2;
	for (int l = 1; l < n; l++) {
		res = res * 2 % 1000000007;
	}
	cout << res;
	return 0;
}