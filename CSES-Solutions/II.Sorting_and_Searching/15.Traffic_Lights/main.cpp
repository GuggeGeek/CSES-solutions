#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long x = 0;
	int n = 0;
	cin >> x >> n;
	set <long long> array = { 0 , x };
	multiset <long long> length = { x };
	for (int l = 0; l < n; l++) {
		long long a = 0;
		cin >> a;

		auto itu = array.upper_bound(a); // иттератор на следующее максимальное
		auto itl = itu; itl--; // иттератор на следующее меньшее или равное

		array.insert(a);

		long long old_length = *itu - *itl;

		length.erase(length.find(old_length));
		length.insert(*itu - a);
		length.insert(a - *itl);

		auto itmax = length.end(); itmax--;
		cout << *itmax << " ";
	}
	return 0;
}