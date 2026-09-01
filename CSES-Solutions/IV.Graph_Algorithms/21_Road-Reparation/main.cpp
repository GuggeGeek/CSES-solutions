#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

vector<int> sz;
vector<int> parent;

int n = 0;

void init(int n) {
	sz.assign(n + 1, 1);
	parent.assign(n + 1, 0);
	for (int l = 1; l <= n;l++) {
		parent[l] = l;
	}
}

int road(int x) {
	if (x == parent[x]) {
		return x;  // нашли батю
	}
	parent[x] = road(parent[x]);
	return parent[x];
}

bool chek(int a, int b) {
	if (road(a) == road(b)) {
		return false;
	}
	else return true;
}

void unite(int a, int b) {
	a = road(a);
	b = road(b);
	if (sz[a] < sz[b]) swap(a, b);
	parent[b] = a;
	sz[a] += sz[b];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int m = 0;
	cin >> n >> m;
	vector<tuple<long long, int, int>> list(m);
	for (int l = 0; l < m; l++) {
		long long c = 0;
		int a = 0, b = 0;
		cin >> a >> b >> c;
		list[l] = tuple(c, a, b);
	}
	sort(list.begin(), list.end());
	init(n);

	long long total = 0;
	int rebr = 0;
	
	for (auto now : list) {
		auto [c, a, b] = now;
		if (chek(a, b)) {
			unite(a, b);
			total += c;
			rebr++;
		}
	}
	if (rebr == n - 1) {
		cout << total;
	}
	else cout << "IMPOSSIBLE";
	return 0;
}