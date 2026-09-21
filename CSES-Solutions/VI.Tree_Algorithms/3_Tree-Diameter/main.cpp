#include <iostream>
#include <vector>

using namespace std;

vector<int> st[200001];
int maxline = 0, maxvert = 1, n = 0;

void dfs(int from, int to, int price) {
	if (price > maxline) {
		maxline = price;
		maxvert = to;
	}
	for (auto now : st[to]) {
		if (now == from) continue;
		dfs(to, now, price + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int l = 0; l < n - 1; l++) {
		int a = 0, b = 0;
		cin >> a >> b;
		st[a].push_back(b);
		st[b].push_back(a);
	}

	dfs(0, 1, 0);
	dfs(0, maxvert, 0);
	cout << maxline;

	return 0;
}