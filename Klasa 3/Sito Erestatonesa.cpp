#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void sitoEratostenesa() {
    // Zakres szukania
    const int number = 50;
    // Limit zakresu sprawdzania
    // +1 dla bezpieczeństwa w razie zanirzenia przez funkcje sqrt()
    int limiter = sqrt(number)+1;
    // Tablica TRUE/FALSE czy pierwsza
    // Od razu ustawiony pierwsze 2 elementy na false (0,1)
    bool primeTable[number+1] = { false };
    primeTable[1] = false;
    for (int i = 2; i <= number; i++) {
        primeTable[i] = true;
    }
    for (int i = 2; i < limiter; i++) {
        if (primeTable[i]){
            for (int j = i * i; j <= number; j += i) {
                primeTable[j] = false;
            }
        }
    }
    // Wypisanie liczb na podstawie tablicy true/false
    // Dopisuje wartości do vectora, który nie ma sprecyzowanej wielkości
    vector<int> primeNumberInSection{};
    for (int i = 0; i <= number; i++) {
        // Jeśli wartość jest true znaczy, że jest pierwsza
        if (primeTable[i]) {
            primeNumberInSection.push_back(i);
        }
    }
    for (int i = 0; i < primeNumberInSection.size(); i++){
        cout << primeNumberInSection[i] << "\n";
    }
}

int main()
{
    sitoEratostenesa();
}
