#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include <math.h>
struct People {
	int Number, Heigth, ClothesNumber, ShoesNumber;
	double Weight;
	char Surname[40], Name[30];
};
using namespace std;
void EnterOnePeople(People& people);
void CreateFile(People& people);
void AppendToFile(People& people);

void EnterOnePeople(People &people) {
	cout << "����i�� �����="; cin >> people.Number; cin.get();
	cout << "����i�� ��i�����="; cin.getline(people.Surname, 40);
	cout << "����i�� i�'�="; cin.getline(people.Name, 30);
	cout << "����i�� �i��="; cin >> people.Heigth; cin.get();
	cout << "����i�� ����="; cin >> people.Weight; cin.get();
	cout << "����i�� ����� ����i="; cin >> people.ClothesNumber; cin.get();
	cout << "����i�� ����� ������="; cin >> people.ShoesNumber; cin.get();
}
void CreateFile(People &people) {
	fstream f;
	f.open("People.dat", ios::out);
	int kilk;
	cout << "����i�� �i���i��� ����� ����� ������ ��������="; cin >> kilk;
	for (int i = 0; i < kilk; i++) {
		EnterOnePeople(people);
		f.write((char*)&people, sizeof(people));
	}
	f.close();
}

void AppendToFile(People &people) {
	fstream f, f1;
	f.open("People.dat", ios::in);
	if (!f.is_open()) 
		cout << "�� ������� ������� ���� ��� ������." << endl;
	else {
		int kilk;
		f1.open("Buffer.dat", ios::out);
		while (f.read((char*)&people, sizeof people))
			f1.write((char*)&people, sizeof people);
		cout << "����i�� �i���i��� ����� ����� ������ ����������="; cin >> kilk; cin.get();
		cout << "����i�� �����" << endl;
		for (int i = 0; i < kilk; i++) {
			cout << "������ " << i + 1 << endl;
			EnterOnePeople(people);
			f1.write((char*)&people, sizeof(people));
		}
		f.close();
		f1.close();
		remove("People.dat");
		rename("Buffer.dat", "People.dat");
	}
}