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
void uzayKorsanlari(Gemi& gemi) {
    cout << "Uzay korsanlari saldiriyor! Arkani kolla " << endl;
    int secim, istenenAltin;
    bool gecerliSecim = false;

    while (!gecerliSecim) {
        cout << "1. Kac (33 yakit harcar)\n2. Savas\n3. Pazarlik";
        cout << "\nSeciminizi girin: ";
        cin >> secim;

        switch (secim) {
            case 1: // Kaçma seçimi
                gecerliSecim = true;
                if (gemi.yakit < 33) {
                    cout << "Kacmak icin yeterli yakitiniz yok!" << endl;
                    gecerliSecim = false; //  yeniden seçim yaptırmak için
                } else {
                    gemi.yakit -= 33;
                    if (rand() % 100 < 50 * gemi.kacmaOlasiligi()) {
                        cout << "Basariyla kactiniz!" << endl;
                    } else {
                        cout << "Kacamadiniz ve naneyi yediniz. Korsanlar hala pesinizde!" << endl;
                    }
                }
                break;
            case 2: // Savaş seçimi
                gecerliSecim = true;
                if (rand() % 2) {
                    cout << "Korsanlarin icinden gectiniz!!!" << endl;
                } else {
                    gemi.saglik -= 30 * gemi.hasarKatsayisi();
                    cout << "Savasi ve baska bir seyi  kaybettiniz; ayrica hasar aldiniz. Guncel saglik: " << gemi.saglik << endl;
                }
                break;
            case 3: // Pazarlık
                istenenAltin = (rand() % 3 + 1) * 10; // Korsanların istediği altın miktarı
                cout << "Korsanlar sizden " << istenenAltin << " altin istiyor." << endl;
                cout << "Korsanlar Beyi: Ya parani ya da ...'nu alirim yegenim " << endl;
                if (istenenAltin <= gemi.para) {
                    gemi.para -= istenenAltin;
                    gecerliSecim = true;
                    cout << "Korsanlar Beyi: Guzel boyle adam ol, gelecekte vermeye devam " << endl;

                } else {
                    cout << "Korsanlara odeyecek kadar altininiz yok." << endl;
                    cout << "Ya savasmali ya da kacmalisiniz." << endl;
                    // yeniden seçime zorlar ve tekrar pazarlık seçse de yeniden seçime zorlar.
                }
                break;
            default:
                cout << "Gecersiz secim. Tekrar deneyin." << endl;
                // bu yazıyı görmek isteyen  1 2 3 dışında bir sayı yazsın sürekli
        }
    }
}

