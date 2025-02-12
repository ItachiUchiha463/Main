#include "Rudyi.h"

void SortingByHeight(People& people) {
    People sort[100];// масив жля збереження даних про людей (ну максимум 100)
    ifstream File("People.dat");// відкриття файлу для читання
    int n = 0;
    if (!File) {// перевірка чи він відкрився
        cout << "Файл не відкрився";
    }
    else {
        int n = 0;// кількість прорахованих людей
        while (File.read((char*)&people, sizeof people))// читання з файлу
        {
            sort[n] = people;// збереження прочитаних файлів в масив
            n++;// лічильник
        }
        File.close();

        for (int i = 0; i < n - 1; i++) {// гарантує що кожен елемент потрапить на совє місце без зайвих перевірок, буде залишатися 1 невідсортований елемент але він буде на своєму місці тому немає смислу його провіряти
            for (int j = 0; j < n - i - 1; j++) {// запобігає зайвим порівнянням уже відсортованих елементів у кінці
                if (sort[j].Heigth > sort[j + 1].Heigth) {
                    swap(sort[j], sort[j + 1]);
                }
            }
        }
        cout << setw(30) << "Список людей після сортування за зростом";
        for (int i = 0; i < n; i++) {
            cout << sort[i].Name << setw(10) << sort[i].Surname << setw(15)
                << "Зріст: " << sort[i].Heigth << " см" << setw(15) << "Вага:"
                << sort[i].Weight << " кг" << setw(15) << "Взуття: " << sort[i].ShoesNumber
                << setw(15) << "Одяг: " << sort[i].ClothesNumber << setw(15) << "Номер: " <<
                sort[i].Number << endl;
        }
    }
    ofstream OutFile("SortedPeople.dat", ios::binary);// відкриває файл для запису
    if (!OutFile) {
        cout << "Помилка відкриття файлу для запису";
        return;
    }
    for (int i = 0; i < n; i++) {
        OutFile.write((char*)&sort[i], sizeof(People));// запис у файл(бінарний)
    }
    OutFile.close();
}

void SurnameOutputBySize(People& people) {
    People sortu[100];
    ifstream File("People.dat");
    int n = 0;
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

        People buffer[30];// тимчасовий масив для зберігання людей які мають однакову вагу і номер
        int count = 0;// лічильник скільки людей знайшло
        bool found = false;// чи були знайдені люди

        for (int i = 0; i < n; i++) {// перебирає кожен елемент sortu
            for (int j = i + 1; j < n; j++) {// починається з j = i + 1 щоб уникнути повторного порівняння пробігає також n - 1, але починається завжди на 1 крок попереду і
                if (sortu[i].Weight == sortu[j].Weight && sortu[i].ShoesNumber == sortu[j].ShoesNumber) {// порівняння
                    buffer[count++] = sortu[i];// інформація 1 людини
                    buffer[count++] = sortu[j];// інформація 2 людини
                    found = true;
                }
            }
        }

        if (!found) {
            cout << "Немає людей з однаковою вагою та розміром взуття." << endl;
        }
        else {
            cout << "Люди з однаковою вагою та номером взуття:" << endl;
            for (int i = 0; i < count; i++) {
                cout << buffer[i].Surname << endl;
            }
        }
    }
    ofstream OutFile("SortedPeople.dat", ios::binary);
    if (!OutFile) {
        cout << "Помилка відкриття файлу для запису";
        return;
    }
    for (int i = 0; i < n; i++) {
        OutFile.write((char*)&sortu[i], sizeof(People));
    }
    OutFile.close();
}