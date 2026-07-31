#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0, ans = 0;
	long long x = 0;
	cin >> n >> x;
	vector <long long> array(n);

	for (int l = 0; l < n; l++) cin >> array[l];

	auto left = array.begin();
	long long sum = 0;
	for (auto right = array.begin(); right < array.end(); right++) {
		sum += *right;
		while (x < sum) {
			sum -= *left;
			left++;
		}
		if (x == sum) ans++;
	}
	cout << ans;
	return 0;
}