#pragma once
#ifndef KHAMRYK_H
#define KHAMRYK_H
#include <string>
#include <iostream>
using namespace std;

struct Person {
    string prizvishe;
    int zrist;
    int vaga;
    int odezhiNum;
    int vzuttyaNum;
};

void vvid(Person people[], int rozmir) {
    for (int i = 0; i < rozmir; i++) {
        cout << "Vvedit dani dlia osoby " << i + 1 << ":" << endl;
        cout << "Prizvishe: ";
        cin >> people[i].prizvishe;
        cout << "Zrist: ";
        cin >> people[i].zrist;
        cout << "Vaga: ";
        cin >> people[i].vaga;
        cout << "# odezhi: ";
        cin >> people[i].odezhiNum;
        cout << "# vzuttya: ";
        cin >> people[i].vzuttyaNum;
        cout << endl;
    }
}
void priz(const Person people[], int rozmir) {
    cout << "Prizvishe z num odeksi > 46 i num vzuttya < 41:" << endl;
    for (int i = 0; i < rozmir; i++) {
        if (people[i].odezhiNum > 46 && people[i].vzuttyaNum < 41) {
            cout << people[i].prizvishe << endl;
        }
    }
}
void minRist(const Person people[], int rozmir) {
    if (rozmir == 0) {
        cout << "Nemaye ludey dla vikonanya." << endl;
        return;
    }
    Person minPerson = people[0];
    for (int i = 1; i < rozmir; i++) {
        if (people[i].zrist < minPerson.zrist || (people[i].zrist == minPerson.zrist && people[i].odezhiNum < minPerson.odezhiNum)) {
            minPerson = people[i];
        }
    }
    cout << "Ludyna z najmenshym zristom i najmenshym # odezhi: " << minPerson.prizvishe << endl;
}
void MaxVzMaxVaga(const Person people[], int rozmir) {
    if (rozmir == 0) {
        cout << "No people to compare." << endl;
        return;
    }
    Person maxPerson = people[0];
    for (int i = 1; i < rozmir; i++) {
        if (people[i].vzuttyaNum > maxPerson.vzuttyaNum ||
            (people[i].vzuttyaNum == maxPerson.vzuttyaNum && people[i].vaga > maxPerson.vaga)) {
            maxPerson = people[i];
        }
    }
    cout << "Liudyna z naibilshym # vzuttya i naibilshoyu vagoyu: " << maxPerson.prizvishe << endl;
}
#endif