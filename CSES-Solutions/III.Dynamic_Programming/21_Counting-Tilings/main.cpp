#include <iostream>
#include <vector>

using namespace std;

int n = 0, m = 0;
vector<vector<int>> matrix;

void generate(int pos, int prev_mask, int curr_mask, int current_row) { // pos - на какую клетку смотрим от 0 до n
	if (pos == n) {
		matrix[current_row][curr_mask] = (matrix[current_row][curr_mask] + matrix[current_row - 1][prev_mask]) % 1000000007;
		return;
	}
	if (prev_mask & (1 << pos)) {
		generate(pos + 1, prev_mask, curr_mask, current_row);
		return;
	}
	generate(pos + 1, prev_mask, curr_mask | (1 << pos), current_row);
	if (pos + 1 < n && !(prev_mask & (1 << (pos + 1)))) {
		generate(pos + 2, prev_mask, curr_mask, current_row);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	int limit = 1 << n; // 2 в степени n
	matrix.assign(m + 1, vector<int>(limit, 0));

	matrix[0][0] = 1;
	for (int l = 1; l <= m; l++) {
		for (int prev_mask = 0; prev_mask < limit; prev_mask++) { // маска прошлого ряда.
			if (matrix[l - 1][prev_mask] > 0) {
				generate(0, prev_mask, 0, l);
			}
		}
	}
	cout << matrix[m][0];
	return 0;
}