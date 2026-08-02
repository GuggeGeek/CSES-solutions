#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0, k = 0, unique = 0, left = 1;
	long long ans = 0;
	cin >> n >> k;
	map<long long, int> list;
	vector<long long> array(n + 1);
	for (int right = 1; right <= n; right++) {
		long long current = 0;
		cin >> current;
		array[right] = current;
		if (list[current] == 0) unique++;
		list[current]++;
		while (unique > k) { 
			list[array[left]]--;
			if (list[array[left]] == 0) {
				unique--;
			}
			left++;
		}
		ans += (right - left + 1);
	}
	cout << ans;
	return 0;
}