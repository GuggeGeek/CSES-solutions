#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0, m = 0; 
	cin >> n >> m;
	vector<vector<long long>> matrix(n + 1, vector<long long>(m + 2, 0));
	vector<int> array(n + 1, 0);
	for (int l = 1; l <= n; l++) cin >> array[l];
	
	if (array[1] == 0) for (int l = 1; l <= m; l++) matrix[1][l] = 1;
	else matrix[1][array[1]] = 1;

	for(int l = 2; l <= n; l++){
		long long v = array[l];
		if (array[l] == 0) for (int j = 1; j <= m; j++) {
				matrix[l][j] = (matrix[l - 1][j - 1] + matrix[l - 1][j] + matrix[l - 1][j + 1]) % 1000000007;
			}
		else matrix[l][v] = (matrix[l - 1][v - 1] + matrix[l - 1][v] + matrix[l - 1][v + 1]) % 1000000007;
	}

	long long ans = 0;
	for (int l = 1; l <= m; l++) ans = (ans + matrix[n][l]) % 1000000007;

	cout << ans;

	return 0;
}