#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n = 0;
int st[19][200005]; // если я пишу vector . то компилятор на cses даёт такой ответ 
int d[200005];      // g++: fatal error: Killed signal terminated program cc1plus compilation terminated.

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int q = 0;
	cin >> n >> q;
	st[0][1] = 1;
	for (int l = 0; l < n - 1; l++) {
		cin >> st[0][l + 2];
		d[l + 2] = d[st[0][l + 2]] + 1;
	}

	for (int l = 1; l < 19; l++) {
		for (int j = 1; j <= n; j++) {
			st[l][j] = st[l - 1][st[l - 1][j]];
		}
	}

	for (int l = 0; l < q; l++) {
		int a = 0, b = 0;
		cin >> a >> b;
		if (d[a] < d[b]) swap(a, b);
		int put = d[a] - d[b];
		for (int j = 18; j >= 0; j--) {
			if (put & (1 << j)) a = st[j][a];
		}
		if (a == b) {
			cout << a << "\n";
			continue;
		}
		for (int j = 18; j >= 0; j--) {
			if (st[j][a] != st[j][b]) {
				a = st[j][a];
				b = st[j][b];
			}
		}
		cout << st[0][a] << "\n";
	}

	return 0;
}