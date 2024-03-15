#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Gemi {
public:
    int saglik = 100;
    int yakit = 100;
    int para = 0;
    virtual float kacmaOlasiligi() = 0;
    virtual float hasarKatsayisi() = 0;
};

class HizliGemi : public Gemi {
public:
    float kacmaOlasiligi() override {
        return 1.5;
    }

    float hasarKatsayisi() override {
        return 1.5;
    }
};

class GucluGemi : public Gemi {
public:
    float kacmaOlasiligi() override {
        return 0.5;
    }

    float hasarKatsayisi() override {
        return 0.5;
    }
};

class NormalGemi : public Gemi {
public:
    float kacmaOlasiligi() override {
        return 1.0;
    }

    float hasarKatsayisi() override {
        return 1.0;
    }
};
void AsteroidKusagi(Gemi& Gemi) {
    cout << "Asteroid kusagina yakalandiniz, Dikkatli Olunuz !" << endl;
    Gemi.saglik -= 10 * Gemi.hasarKatsayisi();// alinan hasar
    cout << "Geminiz hasar aldı. Guncel gemi sagligi: " << Gemi.saglik << endl;
}

void TerkedilmisGezegen(Gemi& Gemi) {
    cout << "Tebrikler kesfedilmemis gezegene ulastiniz " << endl;
    if (rand() % 2) {
        cout << "TEBRIKLER!! 10 altin kazandiniz!" << endl;
        Gemi.para += 10;
    } else {
        cout << " DIKKAT!!! Uzay korsanlari pususuna dusuruldunuz!!! " << endl;
        Gemi.saglik -= 20 * Gemi.hasarKatsayisi(); // alinan hasar
        cout << "EYVAHH!!! Geminiz hasar aldi. Guncel gemi sagligi: " << Gemi.saglik << endl;
    }
}
