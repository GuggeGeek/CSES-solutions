#include <iostream>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	long long sum = 0, ans = 0;
	cin >> n;
	map<long long, int> list;
	list[0] = 1;
	for (int l = 0; l < n; l++) {
		long long current = 0;
		cin >> current;
		sum += current;
		long long r = (sum % n + n) % n;
		if(list.find(r) != list.end()) ans += list[(sum % n + n) % n];
		list[r]++;
	}
	cout << ans;
	return 0;
}