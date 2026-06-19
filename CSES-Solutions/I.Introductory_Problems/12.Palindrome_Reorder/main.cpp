#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector <int> number(26);
	string early;
	cin >> early;

	for ( auto now : early ) {
		int s = now - 'A';
		number[s]++;
	}
	int triger = 0;
	int triger_possicion = 0;
	for (int l = 0; l < 26; l++) {
		if ( number[l] % 2 != 0) {
			triger++;
			triger_possicion = l;
			if (triger > 1) {
				cout << "NO SOLUTION";
				return 0;
			}
		}
	}

	for (int l = 0; l < 26; l++ ) {
		if (number[l] % 2 == 0 && number[l] > 0) {
			for (int j = 0; j < (number[l] / 2); j++) {
				cout << char('A' + l );
			}
		}
	}
	if (triger == 1) {
		for (int l = 0; l < number[triger_possicion]; l++) {
			cout << char(triger_possicion + 'A');
		}
	}

	for (int l = 25; l >= 0; l--) {
		if (number[l] % 2 == 0 && number[l] > 0) {
			for (int j = 0; j < (number[l] / 2); j++) {
				cout << char('A' + l);
			}
		}
	}
	return 0;
}