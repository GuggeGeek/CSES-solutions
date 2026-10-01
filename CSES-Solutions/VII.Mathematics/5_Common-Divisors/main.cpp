#include <iostream>
#include <algorithm>

using namespace std;
int n = 0;
int st[1000001];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	int maxi = 0;
	for (int l = 0; l < n; l++) {
		int a = 0;
		cin >> a;
		maxi = max(maxi, a);
		st[a]++;
	}

	for (int l = maxi; l > 0; l--) {
		if (st[l] > 1) {
			cout << l;
			return 0;
		}
		int count = 0;
		for (int j = 1; l * j <= maxi; j++) {
			if (st[l * j] > 0) {
				count++;
				if (count > 1) {
					cout << l;
					return 0;
				}
			}
		}
	}

	return 0;
}