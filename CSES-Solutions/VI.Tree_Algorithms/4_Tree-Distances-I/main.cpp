#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n = 0, maxprice = 0, maxa = 0;
vector<int> st[200001];
vector<int> dista, distb;
bool second = false;

void dfs(int a, int b, int price) {
	if (price > maxprice) {
		maxprice = price;
		maxa = b;
	}
	for (auto now : st[b]) {
		if (a == now) continue;
		dfs(b, now, price + 1);
	}
}

void dfsin(int a, int b, int price) {
	if (price > maxprice) {
		maxprice = price;
		maxa = b;
	}
	for (auto now : st[b]) {
		if (a == now) continue;
		if (!second) dista[now] = price + 1;
		else distb[now] = price + 1;
		dfsin(b, now, price + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	dista.assign(n + 1, 0);
	distb.assign(n + 1, 0);
	for (int l = 0; l < n - 1; l++) {
		int a = 0, b = 0;
		cin >> a >> b;
		st[a].push_back(b);
		st[b].push_back(a);
	}

	dfs(0, 1, 0);
	maxprice = 0;
	dfsin(0, maxa, 0);
	maxprice = 0;
	second = true;
	dfsin(0, maxa, 0);

	for (int l = 1; l <= n; l++) {
		cout << max(dista[l], distb[l]) << " ";
	}
	return 0;
}