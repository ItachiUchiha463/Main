#include "Kovalchuk.h"
#include"OOO.h"
int main() {
	setlocale(0, "UKR");
	int choice=1;
	People people;
	while (choice != 9) {
		cout << "Виберiть операцію" << endl;
		cout << "1-записати у файл" << endl;
		cout << "2-дозаписати у файл" << endl;
		cout << "3-прочитати файл" << endl;
		cout << "4-сортування за ростом" << endl;
		cout << "5-однакова вага i однаковий номер взуття  " << endl;
		cout << "6-номер одежi>46 i номер взуття<41" << endl;
		cout << "7-люди ріст яких в межах 10% та вага в межах 5%" << endl;
		cout << "8-людина з найменшим ростом i найменшим номером одежi та людина з найбiльшим номером взуття i найбільшою вагою" << endl;
		cout << "9-завершення роботи" << endl;
		cin >> choice; cin.get();
		switch (choice) {
		case 1: { CreateFile(people); break; }
		case 2: { AppendToFile(people); break; }
		case 3: { Read(people); break; }
		case 4: { break; }
		case 5: { break; }
		case 6: { break; }
		case 7: { break; }
		case 8: { break; }

		}
	}
}