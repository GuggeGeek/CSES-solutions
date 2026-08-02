#include <iostream>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	long long x = 0, sum = 0, ans = 0;
	cin >> n >> x;
	map<long long, int> list;
	list[0] = 1;
	for (int l = 0; l < n; l++) {
		long long current = 0;
		cin >> current;
		sum += current;
		if (list.find(sum - x) != list.end()) ans += list[sum - x];
		list[sum]++;
	}
	cout << ans;
	return 0;
}