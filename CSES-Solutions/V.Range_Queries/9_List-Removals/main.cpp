#include <iostream>
#include <vector>

using namespace std;

int n = 0;
vector<int> st(1 << 19);
vector<long long> table;

void add(int k, int type) {
	st[k] = type;
	while (k > 1) {
		if (k % 2 == 0) st[k / 2] = st[k] + st[k + 1];
		else st[k / 2] = st[k] + st[k - 1];
		k /= 2;
	}
}

long long search(int p) {
	int k = 1;
	while (k < (1 << 18)) {
		if (st[k * 2] >= p) { 
			k *= 2;
		}
		else {
			p -= st[k * 2];
			k = k * 2 + 1;
		}
	}
	add(k, 0);
	return table[k - (1 << 18) + 1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	table.assign(n + 1, 0);
	for (int l = 1; l <= n; l++) {
		cin >> table[l];
		add(l + (1 << 18) - 1, 1);
	}

	for (int l = 0; l < n; l++) {
		int p = 0;
		cin >> p;
		cout << search(p) << " ";
	}


	return 0;
}