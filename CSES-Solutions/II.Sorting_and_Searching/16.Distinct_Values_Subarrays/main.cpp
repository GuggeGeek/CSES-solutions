#include <iostream>
#include <map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0, left = 0;
	long long ans = 0;
	map <long long, int> array;
	cin >> n;
	for (int right = 0; right < n; right++) {
		long long x = 0;
		cin >> x;
		if (array.find(x) != array.end()) left = max(left, array.at(x) + 1);
		array[x] = right;
		ans += (right - left + 1);
	}
	cout << ans;
	return 0;
}