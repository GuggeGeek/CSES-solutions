#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
	int n = 0;
	cin >> n;
	set <int> a;
	for (int l = n - 1; l > 0; l--) {
		int temp = 0;
		cin >> temp;
		a.insert(temp);
	}
	int num = 1;
	while ( num <= n ) {
		if (a.find(num) == a.end()) {
			cout << num;
			return 0;
		}
		else num++;
	}
	return 0;
}