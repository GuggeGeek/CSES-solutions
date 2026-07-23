#include <iostream>

using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	cin >> n;
	long long current = 0, maxi = -1e18;
	for (int l = 0; l < n;l++) {
		long long x = 0;
		cin >> x;
		
		if (current < 0) current = 0;
		current += x;
		maxi = max(maxi, current);
	}
	cout << maxi;

	return 0;
}