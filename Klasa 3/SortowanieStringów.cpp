#include <iostream>
#include <vector>
using namespace std;

void sort_pr_wstaw_pr_wart(vector<string>& t, int n)// z wartownikiem
{
    t.push_back(""); // miejsce na wartownika
    /*
        przesun el. o 1 w prawo, by zrobić miejsce dla wartownika
    */
    for (int i = n; i > 0; i--)
        t[i] = t[i - 1];
    /*
        sortowanie wlasciwe
    */
    for (int k = 1; k < n; k++)
    {
        t[0] = t[k + 1];// ustaw wstawiany element jako wartownika
        int i = k;
        for (; t[i] > t[0]; i--)
            t[i + 1] = t[i];
        t[i + 1] = t[0];
    }
    /*
        przesun el. o 1 w lewo do formy pierwotnej (likwidujac wartownika)
    */
    for (int i = 0; i < n; i++)
        t[i] = t[i + 1];

    t.pop_back();
}

int main()
{
    const int roz = 20;
    vector<string> tab;
    int il;
    cout << "Podaj dlugosc tablicy" << '\n';
    cin >> il;
    if (il > roz) {
        cout << "Podaj ponownie" << '\n';
        cin >> il;
    }
    for (int i = 0; i < il; i++) {
        cout << "Podaj liczbe" << '\n';
        string input;
        cin >> input;
        tab.push_back(input);
    }
    for (int i = 0; i < il; i++)
        cout << tab[i] << '\t';
    cout << '\n';
    sort_pr_wstaw_pr_wart(tab, il);
    for (int i = 0; i < il; i++)
        cout << tab[i] << '\t';
    cout << '\n';
    return 0;
}