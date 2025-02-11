#include "Kovalchuk.h"
void EnterOnePeople(People& people) {
	cout << "Введiть номер="; cin >> people.Number; cin.get();
	cout << "Введiть прiзвище="; cin.getline(people.Surname, 40);
	cout << "Введiть iм'я="; cin.getline(people.Name, 30);
	cout << "Введiть рiст="; cin >> people.Heigth; cin.get();
	cout << "Введiть вагу="; cin >> people.Weight; cin.get();
	cout << "Введiть номер одежi="; cin >> people.ClothesNumber; cin.get();
	cout << "Введiть номер взуття="; cin >> people.ShoesNumber; cin.get();
	
}
void CreateFile(People& people) {
	fstream f;
	f.open("People.dat", ios::out);
	int kilk;
	cout << "Введiть кiлькiсть людей котру хочете добавити="; cin >> kilk; cin.get();
	for (int i = 0; i < kilk; i++) {
		cout << "Людина " << i + 1 << endl;
		EnterOnePeople(people);
		f.write((char*)&people, sizeof(people));
	}
	f.close();
}

void AppendToFile(People& people) {
	fstream f, f1;
	f.open("People.dat", ios::in);
	if (!f.is_open())
		cout << "Не вдалося відкрити файл для запису." << endl;
	else {
		int kilk;
		f1.open("Buffer.dat", ios::out);
		while (f.read((char*)&people, sizeof people))
			f1.write((char*)&people, sizeof people);
		cout << "Введiть кiлькiсть людей котру хочете дозаписати="; cin >> kilk; cin.get();
		cout << "Введiть людей" << endl;
		for (int i = 0; i < kilk; i++) {
			cout << "Людина " << i + 1 << endl;
			EnterOnePeople(people);
			f1.write((char*)&people, sizeof(people));
		}
		f.close();
		f1.close();
		remove("People.dat");
		rename("Buffer.dat", "People.dat");
	}
}
