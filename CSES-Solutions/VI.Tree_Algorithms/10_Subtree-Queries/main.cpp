#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long BASE = 1 << 19;
int n = 0, pos = 0;
vector<long long> Do(1 << 20);
vector<int> put[200005];
vector<int> tin(200001);
vector<int> sizes(200001, 1);
long long vrem[200001];

void izm(int a, long long x) {
	Do[a] = x;
	while (a > 1) {
		if (a % 2 == 0) Do[a / 2] = Do[a] + Do[a + 1]; // слева
		else Do[a / 2] = Do[a] + Do[a - 1];// справа
		a /= 2;
	}
}

long long ans(int a, int b) {
	long long total = 0;
	while (a <= b) {
		if (a % 2 == 1) total += Do[a++];
		if (b % 2 == 0) total += Do[b--];
		a /= 2;
		b /= 2;
	}
	return total;
}

void dfs(int a, int b) {
	tin[b] = pos++;
	for (auto now : put[b]) {
		if (now == a) continue;
		dfs(b, now);
		sizes[b] += sizes[now];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int q = 0;
	cin >> n >> q;
	for (int l = 0; l < n; l++) {
		cin >> vrem[l + 1];
	}

	for (int l = 0; l < n - 1; l++) {
		int a = 0, b = 0;
		cin >> a >> b;
		put[a].push_back(b);
		put[b].push_back(a);
	}

	dfs(0, 1);
	
	for (int l = 1; l <= n; l++) {
		izm(BASE + tin[l] - 1, vrem[l]);
	}

	for (int l = 0; l < q; l++) {
		int a = 0;
		cin >> a;
		if (a == 1) { // заменить вес узла s на x
			int s = 0;
			long long x = 0;
			cin >> s >> x;
			izm(tin[s] + BASE - 1, x);
		}
		else { // вывести количество подмассивов на позиции s
			int s = 0;
			cin >> s;
			int L = BASE + tin[s] - 1;
			int R = BASE + tin[s] + sizes[s] - 2;
			cout << ans(L,R) << "\n";
		}
	}

	return 0;
}