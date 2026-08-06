#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	cin >> n;
	vector<int> value(n + 1, 0);
	value[0] = 0;
	for (int l = 1; l <= n; l++) {
		int temp = l;
		int top = 0;
		while (temp > 0) {
			int actual = temp % 10;
			top = max(actual, top);
			temp /= 10;
		}
		value[l] = value[l - top] + 1;
	}
	cout << value[n];
	return 0;
}