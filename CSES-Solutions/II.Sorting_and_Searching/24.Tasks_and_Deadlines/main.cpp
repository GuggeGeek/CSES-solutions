#include <iostream>
#include <set>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	cin >> n;
	long long sum = 0;
	multiset<int> array;
	for (int l = 0; l < n; l++) {
		int a = 0, d = 0;
		cin >> a >> d;
		sum += d;
		array.insert(a);
	}
	long long all = 0;
	for (auto now : array) {
		all += now;
		sum -= all;
	}
	cout << sum;
	return 0;
}