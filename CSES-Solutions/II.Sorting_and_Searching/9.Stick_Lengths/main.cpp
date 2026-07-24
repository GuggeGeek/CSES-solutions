#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	cin >> n;
	vector <long long> array(n);
	for (int l = 0; l < n; l++) {
		cin >> array[l];
	}
	sort(array.begin(), array.end());
	long long mediana = array[n / 2], all = 0;
	for (auto now : array) all += abs(now - mediana);
	cout << all;

	return 0;
}