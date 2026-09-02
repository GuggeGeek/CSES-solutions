#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parent;
vector<int> sz;
int maxi = 0;

void init(int n) {
	sz.assign(n + 1, 1);
	parent.assign(n + 1, 0);
	for (int l = 1; l <= n; l++) {
		parent[l] = l;
	}
}

int road(int x) {
	if (x == parent[x]) return x;
	parent[x] = road(parent[x]);
	return parent[x];
}

bool chek(int a, int b) {
	if (road(a) != road(b)) return true;
	else return false;
}

void unite(int a, int b) {
	a = road(a);
	b = road(b);
	if (sz[a] < sz[b]) swap(a, b);
	sz[a] += sz[b];
	maxi = max(maxi, sz[a]);
	parent[b] = a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0, m = 0;
	cin >> n >> m;
	init(n);
	int komp = n;

	for (int l = 1; l <= m; l++) {
		int a = 0, b = 0;
		cin >> a >> b;
		if (chek(a, b)) {
			unite(a, b);
			komp--;
		}
		cout << komp << " " << maxi << "\n";
	}

	return 0;
}