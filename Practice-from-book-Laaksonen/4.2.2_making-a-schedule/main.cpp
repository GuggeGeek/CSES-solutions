#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Time {
	int start;
	int end;

	bool operator<(const Time& other)const { // наш оператор сравнения , нам нужно в данном случае сортировать по end
		return end < other.end;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// Нам дан 1 кабинет информатики , так же n уроков и время их начала и окончания . Выведите сколько максимум занятий можно провести 

	int n = 0; // n событий
	cin >> n;

	if (n == 0) {
		cout << 0;
		return 0;
	}

	vector <Time> jour; // вектор структур Time
	for (int l = 0; l < n; l++) { // заполнение вектора всеми занятиями
		int start= 0 , end = 0;
		cin >> start >> end;

		jour.push_back(Time{ start, end });
	}
	sort(jour.begin(), jour.end()); // сортируем наш вектор из Time

	int current = 0, num = 1; // номер занятия которое идет и счетчик занятий

	for (int l = 1; l < n; l++) { // начинаем с 1 на l , так как l это номер занятия , а занятие 0 УЖЕ идёт в любом случае
		if (jour[l].start >= jour[current].end) { // если следующее занятие не мешает актуальному , то мы его проводим
			current = l;
			num++;
		} // если занятие l провести не удалось , то просто идем дальше
	}

	cout << num; // суть задачи в том , что наилучший результат даёт способ , где мы выбираем занятия которые закончаться быстрее всего , так мы освобождаем кабинет раньше под будующие занятия
	return 0;
}