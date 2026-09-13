#include <iostream>
#include <vector>

using namespace std;

int n = 0;
vector<int> list[200001];
vector<int> sizes;

void dfs(int b) { // откуда , где сейчас
	sizes[b] = 1;
	for (auto now : list[b]) {
		dfs(now);
		sizes[b] += sizes[now];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	sizes.assign(n + 1, 0);
	for (int l = 2; l <= n; l++) {
		int k = 0;
		cin >> k; // k - начальник для l
		list[k].push_back(l);
	}

	dfs(1);

	for (int l = 1; l <= n; l++) {
		cout << sizes[l] - 1 << " ";
	}

	return 0;
}