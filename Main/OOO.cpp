#include "OOO.h"

void Read(People& people) {
    fstream f;
    f.open("Employee.dat", ios::in);
    if (!f.is_open())
        cout << "Файл не відкрився!\n";
    else
    {
        f.seekg(0);
        cout << setw(15) << left << "Номер" << setw(15) << "Прізвище" << setw(15) << "Ім'я" << left << setw(15) << "Висота" << setw(15) << "Вага" << setw(15) << "Номер одягу" << setw(15) << "Номер взуття" << endl;
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
    int filteredCount = 0;
    int count = 0;
    People filtered[100];

    double avgHeight = calculateAvHeight(people, count);
    double avgWeight = calculateAvWeight(people, count);
    for (int i = 0; i < count; ++i) {
        if (abs(people.Heigth - avgHeight) <= 0.10 * avgHeight && abs(people.Weight - avgWeight) <= 0.05 * avgWeight)
        {
            filtered[filteredCount] = people;
            filteredCount++;
        }
    }
    cout << "Середнiй рiст: " << avgHeight << endl;
    cout << "Середня вага: " << avgWeight << endl;
    cout << "Люди, якi вiдповiдають критерiям:" << endl;
    for (int i = 0; i < filteredCount; ++i) {
        cout << "Рiст: " << filtered[i].Heigth << ", Вага: " << filtered[i].Weight << endl;
    }
}