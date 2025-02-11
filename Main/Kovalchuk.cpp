#include "Kovalchuk.h"
void EnterOnePeople(People& people) {
	cout << "¬ведiть номер="; cin >> people.Number; cin.get();
	cout << "¬ведiть прiзвище="; cin.getline(people.Surname, 40);
	cout << "¬ведiть iм'€="; cin.getline(people.Name, 30);
	cout << "¬ведiть рiст="; cin >> people.Heigth; cin.get();
	cout << "¬ведiть вагу="; cin >> people.Weight; cin.get();
	cout << "¬ведiть номер одежi="; cin >> people.ClothesNumber; cin.get();
	cout << "¬ведiть номер взутт€="; cin >> people.ShoesNumber; cin.get();
	
}
void CreateFile(People& people) {
	fstream f;
	f.open("People.dat", ios::out);
	int kilk;
	cout << "¬ведiть кiлькiсть людей котру хочете добавити="; cin >> kilk; cin.get();
	for (int i = 0; i < kilk; i++) {
		cout << "Ћюдина " << i + 1 << endl;
		EnterOnePeople(people);
		f.write((char*)&people, sizeof(people));
	}
	f.close();
}

void AppendToFile(People& people) {
	fstream f, f1;
	f.open("People.dat", ios::in);
	if (!f.is_open())
		cout << "Ќе вдалос€ в≥дкрити файл дл€ запису." << endl;
	else {
		int kilk;
		f1.open("Buffer.dat", ios::out);
		while (f.read((char*)&people, sizeof people))
			f1.write((char*)&people, sizeof people);
		cout << "¬ведiть кiлькiсть людей котру хочете дозаписати="; cin >> kilk; cin.get();
		cout << "¬ведiть людей" << endl;
		for (int i = 0; i < kilk; i++) {
			cout << "Ћюдина " << i + 1 << endl;
			EnterOnePeople(people);
			f1.write((char*)&people, sizeof(people));
		}
		f.close();
		f1.close();
		remove("People.dat");
		rename("Buffer.dat", "People.dat");
	}
}
