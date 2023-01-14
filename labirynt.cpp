
#include <iostream>
#include <conio.h>

//Definiowanie klawiszy wedlug kodu ASCII
#define gora 103
#define dol 100
#define lewo 108
#define prawo 112

//Mapa labiryntu ze zdefiniowana wielkoscia 10x20
const char labirynt[10][20] = { 
{'#', '$', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
{'#', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', ' ', ' ', ' ', ' ', '#'},
{'#', ' ', ' ', ' ', '#', ' ', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', '#', '#'},
{'#', '#', '#', ' ', '#', ' ', ' ', '#', '#', '#', '#', '#', '#', ' ', '#', ' ', '#', ' ', ' ', '#'},
{'#', ' ', '#', ' ', '#', '#', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', '@'},
{'#', ' ', '#', ' ', '#', '#', ' ', '#', '#', '#', ' ', '#', ' ', '#', '#', '#', '#', '#', '#', '#'},
{'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', '#', ' ', ' ', '#', ' ', '#'},
{'#', '#', ' ', '#', '#', ' ', '#', '#', '#', '#', ' ', '#', '#', '#', '#', ' ', '#', '#', ' ', '#'},
{'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}, 
};
//Czyszczenie konsolii
void Wyczysc() {
    system("CLS");
}
//Poruszanie sie po nasicnieciu zdefiniowanego przycisku, oraz wykrywanie czy na torze znajduje sie sciana
void Ruch(int poruszanie, int& pX, int& pY) { //& odpowiada za referencje do infa
    switch (poruszanie = _getch()) { //_getch to odczyt z bufora klawiatury, który czeka na klawisz i zwraca wartosc, nie uzyty getchar poniewaz czekajac na znak z klawiatury pozwala wpisac dłuższy tekst który będzie ciągle wypisywał po wywołaniu funkcji
    case gora: //switch wybiera jedna z czterech mozliwosci ruchu
        if (pY - 1 >= 0) {
            if (labirynt[pY - 1][pX] != '#') { 
                pY--;
            }
        }
        break;

    case dol:
        if (pY + 1 <= 10) {
            if (labirynt[pY + 1][pX] != '#') {
                pY++;
            }
        }
        break;

    case lewo:
        if (pX - 1 >= 0) {
            if (labirynt[pY][pX - 1] != '#') {
                pX--;
            }
        }
        break;

    case prawo:
        if (pX + 1 <= 20) {
            if (labirynt[pY][pX + 1] != '#') {
                pX++;
            }
        }
    }
}
//Odpowiada za pokazanie nowej pozycji gracza na planszy oraz usuwaniu go ze starej pozycji
void Gracz(int pX, int pY) {
    for (int i = 0; i < 10; i++) { //Gracz nie moze wyjsc poza granice mapy
        for (int j = 0; j < 20; j++) { //Gracz nie moze wyjsc poza granice mapy
            if (j == pX && i == pY) { //Jeżeli wszystko sie zgadza to przesunac pozycje gracza
                std::cout << "* "; //"grafika" gracza
                continue;
            }
            std::cout << labirynt[i][j] << " "; //Jezeli sie zgadza usunac stara pozycje gracza
        }
        std::cout << "\n"; //Pozwala na utrzymanie mapy w zdefiniowanej wielkosci
    }
}
//Sprawdza czy gracz pojawil sie na kordynatach mety, jezeli tak to TRUE
bool CzyWygral(int pX, int pY) {
    if (pX == 19 && pY == 4) { //Kordynaty mety
        return true;
    }
    return false;
}
//Głowna sekcja odpowiadająca za działanie gry
int main() {

    int PozycjaX = 1; //Kordynat poczatkowy gracza x=1
    int PozycjaY = 0; //Kordynat poczatkowy gracza y=0
    int poruszanie{}; //Wartość ruchu gracza

    while (!CzyWygral(PozycjaX, PozycjaY)) { //Po pierwsze sprawdzenie czy gracz nie skończył gry
        Gracz(PozycjaX, PozycjaY); //Poruszenie gracza o pozycje która została podana na koniec pętli
        Ruch(poruszanie, PozycjaX, PozycjaY); //Wykonanie nastepnego ruchu gracza
        Wyczysc(); //Wyczyszczenie konsoli
    }
    //Komunikat pojawiający się po wygranej
    std::cout << std::endl;
    std::cout << "Wygrana!";
    std::cout << std::endl;

}
