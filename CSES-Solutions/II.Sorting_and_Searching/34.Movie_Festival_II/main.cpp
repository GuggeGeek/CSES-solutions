#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct movie {
	long long in;
	long long out;
	
	bool operator<(const movie& other)const {
		return out < other.out;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0, k = 0;
	cin >> n >> k;
	vector<movie> arrayf;
	multiset<long long> outs;
	for (int l = 0; l < n; l++) {
		long long x, r;
		cin >> x >> r;
		arrayf.push_back(movie(x, r));
	}
	sort(arrayf.begin(), arrayf.end());
	for (int l = 0; l < k; l++) outs.insert(0);

	long long ans = 0;
	for (auto now : arrayf) {
		auto it = outs.upper_bound(now.in);
		if (it != outs.begin()) {
			it--;
			outs.erase(it);
			outs.insert(now.out);
			ans++;
		}
	}
	cout << ans;
	return 0;
}