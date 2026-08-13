#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a = 0, b = 0;
	cin >> a >> b;
	vector<vector<int>> matrix(max(a, b) + 1, vector<int>(max(a, b) + 1, 1e9));
	for (int l = 0; l <= max(a, b); l++) matrix[l][l] = 0;
	
	for (int l = 1; l <= max(a, b); l++) {
		for (int j = l; j <= max(a, b); j++) {
			for (int cheka = 1; cheka <= j / 2; cheka++) {
				matrix[l][j] = min(matrix[l][cheka] + matrix[l][j - cheka] + 1, matrix[l][j]);
			}
			for (int chekb = 1; chekb <= l / 2; chekb++) {
				matrix[l][j] = min(matrix[chekb][j] + matrix[l - chekb][j] + 1, matrix[l][j]);
			}
			matrix[j][l] = matrix[l][j];
		}
	}
	cout << matrix[b][a];
	return 0;
}