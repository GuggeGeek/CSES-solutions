#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	long long x = 0;
	cin >> n >> x;
	vector<pair<int, long long>> best(1 << n);
	vector<long long> weight(n);
	for (int l = 0; l < n; l++) cin >> weight[l];

	best[0] = { 1 , 0 };
	for (int l = 1; l < (1 << n); l++) { // 1
		best[l] = { n + 1 , 0 };
		for (int p = 0; p < n; p++) {
			if (l & (1 << p)) {
				int first = best[l ^ (1 << p)].first;
				long long second = best[l ^ (1 << p)].second;
				if (weight[p] + second > x) { // превышает грузоподьёмность
					first++;
					second = weight[p];
				}
				else second += weight[p];
				best[l] = min(best[l], { first , second });
			}
		}
	}
	cout << best[(1 << n) - 1].first;
	return 0;
}