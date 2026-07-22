#include <iostream>
#include <set>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	cin >> n;
	set <int> a;
	for (int l = 0; l < n; l++) {
		int x = 0;
		cin >> x;
		a.insert(x);
	}
	cout << n - (n - a.size());

	return 0;
}