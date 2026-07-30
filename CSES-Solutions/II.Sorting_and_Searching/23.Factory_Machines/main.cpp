#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n = 0;
long long t = 0, ans = 0;
vector <long long> arr;

bool chek(long long times) {
	long long tow = 0;
	for (auto now : arr) {
		tow += times / now;
		if (tow >= t) return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> t;
	for (int l = 0; l < n; l++) {
		long long x = 0;
		cin >> x;
		arr.push_back(x);
	}
	long long mini = *min_element(arr.begin(), arr.end());
	long long limit = t * mini;
	for (long long b = limit; b > 0; b /= 2) {
		while (!(chek(ans + b))) ans += b;
	}

	cout << ans + 1;
	return 0;
}