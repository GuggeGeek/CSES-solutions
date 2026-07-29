#include <iostream>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0, m = 0; // билетов / покупателей
	cin >> n >> m;
	multiset<long long> array;
	for (int l = 0; l < n; l++) {
		long long x = 0;
		cin >> x;
		array.insert(x);
	}
	for (int l = 0; l < m; l++) {
		long long x = 0;
		cin >> x;
		auto it = array.upper_bound(x);
		if (it == array.begin()) {
			cout << -1 << "\n";
			continue;
		}
		it--;
		cout << *it << "\n";
		array.erase(it);
	}
	return 0;
}