#include "OOO.h"

void Read(People& people) {
    fstream f;
    f.open("People.dat", ios::in);
    if (!f.is_open())
        cout << "���� �� ��������!\n";
    else
    {
        f.seekg(0);
        cout << setw(15) << left << "�����" << setw(15) << "�������" << setw(15) << "��'�" << left << setw(15) << "������" << setw(15) << "����" << setw(15) << "����� �����" << setw(15) << "����� ������" << endl;
        while (f.read((char*)&people, sizeof people)) {
            cout << setw(15) << people.Number << setw(15) << people.Surname << setw(15) << people.Name << setw(15) << people.Heigth << left << setw(15) << people.Weight << setw(15) << people.ClothesNumber << setw(15) << people.ShoesNumber << endl;

        }
        f.close();

    }
}

double calculateAvHeight(People& people, int count) {
    double sum = 0;
    for (int i = 0; i < count; ++i) {
        sum += people.Heigth;
    }
    return sum / count;
}

double calculateAvWeight(People& people, int count) {
    double sum = 0;
    for (int i = 0; i < count; ++i) {
        sum += people.Weight;
    }
    return sum / count;
}

void filterPeople(People& people) {

    fstream f;
    f.open("People.dat", ios::in); 
    int filteredCount = 0;
    double sumH=0;
    double sumW=0;
    int count = 0;
    People filtered[100];
    if (!f.is_open())
        cout << "���� �� ��������!\n";
    else
    {
        f.seekg(0);
        while (f.read((char*)&people, sizeof people)) {
            sumH += people.Heigth;
            sumW += people.Weight;
            count++;
        }
        f.close();

    }
    double avgHeight = calculateAvHeight(people, count);
    double avgWeight = calculateAvWeight(people, count);
    while (f.read((char*)&people, sizeof people)) {
        if (abs(people.Heigth - avgHeight) <= 0.10 * avgHeight && abs(people.Weight - avgWeight) <= 0.05 * avgWeight)
        {

            filtered[filteredCount] = people;
            filteredCount++;
        }
    }
    cout << "������i� �i��: " << avgHeight << endl;
    cout << "������� ����: " << avgWeight << endl;
    cout << "����, ��i �i����i����� ������i��:" << endl;
    for (int i = 0; i < filteredCount; ++i) {
        cout << "�i��: " << filtered[i].Heigth << ", ����: " << filtered[i].Weight << endl;
    }
}