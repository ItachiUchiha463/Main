#include "Rudyi.h"

void SortingByHeight(People& people) {
    People sort[100];
    ifstream File("People.dat");
    if (!File) {
        cout << "Файл не відкрився";
    }
    else {
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
        cout << setw(30) << "Список людей після сортування за зростом"<<endl;
        for (int i = 0; i < n; i++) {
            cout << sort[i].Name << setw(15) << sort[i].Surname << setw(15)
                << "Зріст: " << sort[i].Heigth << " см" << setw(15) << "Вага:"
                << sort[i].Weight << " кг" << setw(15) << "Взуття: " << sort[i].ShoesNumber
                << setw(15) << "Одяг: " << sort[i].ClothesNumber << setw(15) << "Номер: " <<
                sort[i].Number << endl;
        }
    }
}

void SurnameOutputBySize(People& people) {
    People sortu[100];
    ifstream File("People.dat");
    if (!File) {
        cout << "Файл не відкрився";
    }
    else {
        int n = 0;
        while (File.read((char*)&people, sizeof people))
        {
            sortu[n] = people;
            n++;
        }
        File.close();

        People buffer[15];
        int count = 0;
        bool found = false;
        for (int i = 0; i < n; i++) {
                if (sortu[i].Weight == sortu[i].ShoesNumber) {
                    buffer[count] = sortu[i];
                    count++;
                    found = true;
                }
        }

        if (!found) {
            cout << "Немає людей з однаковою вагою та розміром взуття." << endl;
        }
        else {
            cout << "Люди з однаковою вагою та номером взуття" << endl;
            for (int i = 0; i < count; i++) {
                cout << buffer[i].Surname << endl;
            }
        }
    }
}