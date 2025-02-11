#include "Rudyi.h"

void SortingByHeight(People& people) {
    People sort[100];
    ifstream File("People.dat");
    if (!File) {
        cout << "Файл не відкрився";
    }
    int n = 0;
    while (File.read((char*)&people, sizeof people))
    {
        sort[n] = people;
        n++;
    }
    File.close();

    People temp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (sort[j].Heigth > sort[j + 1].Heigth) {
                swap(sort[j], sort[j + 1]);
            }
        }
    }
    cout << "Список людей після сортування за зростом:";
    for (int i = 0; i < n; i++) {
        cout << sort[i].Name << " " << sort[i].Surname
            << " - Зріст: " << sort[i].Heigth << " см, Вага: " << sort[i].Weight
            << " кг, Взуття: " << sort[i].ShoesNumber
            << ", Одяг: " << sort[i].ClothesNumber
            << ", Номер: " << sort[i].Number << endl;
    }
}