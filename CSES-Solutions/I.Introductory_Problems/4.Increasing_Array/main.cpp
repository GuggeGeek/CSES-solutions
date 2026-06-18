#include <iostream>
#include <vector>

using namespace std;
int main() {
	int n = 0;
	cin >> n;
	vector <long long> a(n);
	for (int l = 0; l < n; l++) {
		cin >> a[l];
	}
	int last = a[0];
	long long max = 0;
	for (auto &now : a) {
		if ( last > now ) {
			max = last - now + max;
			now = last;
		}
		last = now;
	}
	cout << max;
	return 0;
}