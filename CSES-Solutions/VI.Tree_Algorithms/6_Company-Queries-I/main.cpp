#include <iostream>
#include <vector>

using namespace std;
int n = 0;
vector<vector<int>> jump(19, vector<int>(200005, -1));



int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int q = 0;
	cin >> n >> q;
	for (int l = 0; l < n - 1; l++) cin >> jump[0][l + 2];

	for (int l = 1; l < 19; l++) {
		for (int j = 1; j <= n; j++) {
			if(jump[l - 1][j] != -1) jump[l][j] = jump[l - 1][jump[l - 1][j]];
		}
	}

	for (int l = 0; l < q; l++) {
		int a = 0, k = 0;
		vector<int> step;
		cin >> a >> k;
		for (int l = 31; l >= 0; l--) {
			if (k & (1 << l)) step.push_back(l);
		}
		for (auto now : step) {
			if (a == -1) break;
			a = jump[now][a];
		}
		cout << a << "\n";
	}

	return 0;
}