#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); // оптимизация

	vector <int> bubble = { 1 , 5 , 2 , 8 , 8 , 5 , 9 , 4 }; //  я дал конкретный массив чисел
	for (int l = 0; l < bubble.size(); l++) {   //  следовательно после l раундов массив будет отсортирован
		for (int j = 0; j < bubble.size() - 1; j++ ) {// после этого цикла гарантировано , что наибольший элемент окажется в последнецй позиции
			if (bubble[j] > bubble[j + 1]) {  // если число j < j + 1 (последующего числа) , то
				swap(bubble[j] , bubble[j + 1]); // команда swap меняет их местами
			}
		}
	}
	for (auto& const now : bubble) { // обыкновенный вывод массива
		cout << now << " ";
	}
	return 0; // данный способ сортировки работает за O(n²) времени , ведь в худшем случае ему придется провести O(n²) перестановок;
}