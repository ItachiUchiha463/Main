/**#include "Directives.h"
void priz(const People people[], int rozmir) {
    cout << "Prizvischa liudei z nomerom odezhi > 46 ta nomerom vzuttya < 41:" << endl;
    for (int i = 0; i < rozmir; i++) {
        if (people[i].ClothesNumber > 46 && people[i].ShoesNumber < 41) {
            cout << people[i].Surname << endl;
        }
    }
}
void minRist(const People people[], int rozmir) {
    if (rozmir == 0) {
        cout << "Nemaye ludei dlia porivnyannia." << endl;
        return;
    }
    People minPerson = people[0];
    for (int i = 1; i < rozmir; i++) {
        if (people[i].Heigth < minPerson.Heigth ||
            (people[i].Heigth == minPerson.Heigth && people[i].ClothesNumber < minPerson.ClothesNumber)) {
            minPerson = people[i];
        }
    }
    cout << "Liudyna z naimenshym zristom ta naimenshym nomerom odezhi: " << minPerson.Surname << endl;
}
void MaxVzMaxVaga(const People people[], int rozmir) {
    if (rozmir == 0) {
        cout << "Nemaye liudei dlia porivnyannia." << endl;
        return;
    }
    People maxPerson = people[0];
    for (int i = 1; i < rozmir; i++) {
        if (people[i].ShoesNumber > maxPerson.ShoesNumber ||
            (people[i].ShoesNumber == maxPerson.ShoesNumber && people[i].Weight > maxPerson.Weight)) {
            maxPerson = people[i];
        }
    }
    cout << "Liudyna z naibilshym nomerom vzuttya ta naibilshoyu vagoyu: " << maxPerson.Surname << endl;
}
int main() {
    const int rozmir = 3;
    People people[rozmir];
    priz(people, rozmir);
    minRist(people, rozmir);
    MaxVzMaxVaga(people, rozmir);

    return 0;
}