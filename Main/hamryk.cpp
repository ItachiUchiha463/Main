#include "Directives.h"

void priz() {
    ifstream f("People.dat", ios::in);
    if (!f.is_open()) {
        cout << "Ne vdalosia vidkryty fail dlia chytannia." << endl;
        return;
    }
    People people;
    bool found = false;
    cout << "Prizvyshcha liudei z nomerom odiahu > 46 ta nomerom vzuttia < 41:" << endl;
    while (f.read((char*)&people, sizeof(people))) {
        if (people.ClothesNumber > 46 && people.ShoesNumber < 41) {
            cout << people.Surname << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Nemae liudei, yaki vidpovidaiut umovam." << endl;
    }
    f.close();
}
void minRist() {
    ifstream f("People.dat", ios::in);
    if (!f.is_open()) {
        cout << "Ne vdalosia vidkryty fail dlia chytannia." << endl;
        return;
    }
    People minPerson;
    bool isFirst = true;
    bool found = false;
    while (f.read((char*)&minPerson, sizeof(minPerson))) {
        if (isFirst) {
            isFirst = false;
            found = true;
            continue;
        }
        People current;
        f.read((char*)&current, sizeof(current));

        if (current.Heigth < minPerson.Heigth ||
            (current.Heigth == minPerson.Heigth && current.ClothesNumber < minPerson.ClothesNumber)) {
            minPerson = current;
        }
    }
    if (found) {
        cout << "Liudyna z naimenshym zristom ta naimenshym nomerom odiahu: " << minPerson.Surname << endl;
    }
    else {
        cout << "Nemae liudei dlia porivniannia." << endl;
    }
    f.close();
}
void MaxVzMaxVaga() {
    ifstream f("People.dat", ios::in);
    if (!f.is_open()) {
        cout << "Ne vdalosia vidkryty fail dlia chytannia." << endl;
        return;
    }
    People maxPerson;
    bool isFirst = true;
    bool found = false;
    while (f.read((char*)&maxPerson, sizeof(maxPerson))) {
        if (isFirst) {
            isFirst = false;
            found = true;
            continue ;
        }
        People current;
        f.read((char*)&current, sizeof(current));

        if (current.ShoesNumber > maxPerson.ShoesNumber ||
            (current.ShoesNumber == maxPerson.ShoesNumber && current.Weight > maxPerson.Weight)) {
            maxPerson = current;
        }
    }
    if (found) {
        cout << "Liudyna z naibilshym nomerom vzuttia ta naibilshoiu vagoiu: " << maxPerson.Surname << endl;
    }
    else {
        cout << "Nema ludei dlia porivniannia." << endl;
    }
    f.close();
}