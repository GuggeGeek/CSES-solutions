#include <iostream>

using namespace std;
long long ans = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0, q = 0;
	cin >> n;
	for (int l = 0; l < n; l++) {
		cin >> q;
		cin >> ans;
		for (int j = 1; j < q; j++) {
			long long x = 0;
			cin >> x;
			ans = ans ^ x;
		}
		if (ans == 0) cout << "second" << "\n";
		else cout << "first" << "\n";
	}


	return 0;
}