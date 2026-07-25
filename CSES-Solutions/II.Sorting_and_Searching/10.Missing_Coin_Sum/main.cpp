#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	cin >> n;
	vector<long long> array(n);
	for (int l = 0; l < n;l++) {
		cin >> array[l];
	}
	sort(array.begin(), array.end());
	long long sum = 0;
	for (auto now : array) {
		if (now > sum && (now - sum) > 1) {
			cout << sum + 1;
			return 0;
		}
		else sum += now;
	}
	cout << sum + 1;

	return 0;
}