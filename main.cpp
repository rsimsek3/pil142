#include <iostream>
#include <cstdlib>
#include <ctime>
#include <memory>
#include <string>

using namespace std;

// const correctness yaptık ve magic number yok
const int baslangicSaglik = 100;
const int baslangicYakit = 100;
const int yeterliYakit = 33;
const int asteroidHasar = 10;
const int korsanHasar = 20;
const int savasHasar = 30;
const int altinKazanimi = 10;
const float hizliGemiKacmaOlasiligi = 1.5f;
const float hizliGemiHasarKatsayisi = 1.5f;
const float gucluGemiKacmaOlasiligi = 0.5f;
const float gucluGemiHasarKatsayisi = 0.5f;
const float normalGemiKacmaOlasiligi = 1.0f;
const float normalGemiHasarKatsayisi = 1.0f;
const int kacisSecimi = 1;
const int savasSecimi = 2;
const int pazarlikSecimi = 3;
const int yakitHarcamasiKacis = 33;
const int olaySayisi = 5;
const int olasilik100 = 100;
const int altinPazarlikMinimum = 10;
const int altinPazarlikMaximum = 30;
const int altinPazarlikCarpan = 10;

class Gemi {    //arayüzümüz
public:
    int saglik = baslangicSaglik;
    int yakit = baslangicYakit;
    int para = 0;

    virtual float kacmaOlasiligi() = 0;
    virtual float hasarKatsayisi() = 0;
};

class HizliGemi : public Gemi {
public:
    float kacmaOlasiligi() override {
        return hizliGemiKacmaOlasiligi;
    }

    float hasarKatsayisi() override {
        return hizliGemiHasarKatsayisi;
    }
};

class GucluGemi : public Gemi {
public:
    float kacmaOlasiligi() override {
        return gucluGemiKacmaOlasiligi;
    }

    float hasarKatsayisi() override {
        return gucluGemiHasarKatsayisi;
    }
};

class NormalGemi : public Gemi {
public:
    float kacmaOlasiligi() override {
        return normalGemiKacmaOlasiligi;
    }

    float hasarKatsayisi() override {
        return normalGemiHasarKatsayisi;
    }
};

void asteroidKusagi(shared_ptr<Gemi> gemi) { // shared pointer kullanma kararı aldık
    cout << "Asteroid kusagina yakalandiniz, Dikkatli Olunuz !" << endl;
    gemi->saglik -= asteroidHasar * gemi->hasarKatsayisi();
    cout << "Geminiz hasar aldi. Guncel gemi sagligi: " << gemi->saglik << endl;
}

void terkedilmisGezegen(shared_ptr<Gemi> gemi) {
    cout << "Tebrikler kesfedilmemis gezegene ulastiniz " << endl;
    if (rand() % 2) {
        cout << "TEBRIKLER!! 10 altin kazandiniz!" << endl;
        gemi->para += altinKazanimi;
    } else {
        cout << " DIKKAT!!! Uzay korsanlari pususuna dusuruldunuz!!!" << endl;
        gemi->saglik -= korsanHasar * gemi->hasarKatsayisi();
        cout << "EYVAHH!!! Geminiz hasar aldi. Guncel gemi sagligi: " << gemi->saglik << endl;
    }
}

void uzayKorsanlari(shared_ptr<Gemi> gemi) {
    cout << "Uzay korsanlari saldiriyor! Arkani kolla " << endl;
    int secim;
    bool gecerliSecim = false;
    int istenenAltin;

    while (!gecerliSecim) {
        cout << "1. Kac (33 yakit harcar)\n2. Savas\n3. Pazarlik";
        cout << "\nSeciminizi girin: ";
        cin >> secim;

        switch (secim) {
            case kacisSecimi:
                if (gemi->yakit < yakitHarcamasiKacis) {
                    cout << "Kacmak icin yeterli yakitiniz yok!" << endl;
                } else {
                    gemi->yakit -= yakitHarcamasiKacis;
                    if (rand() % olasilik100 < gemi->kacmaOlasiligi() * olasilik100) {
                        cout << "Basariyla kactiniz!" << endl;
                        gecerliSecim = true;
                    } else {
                        cout << "Kacamadiniz ve naneyi yediniz. Korsanlar hala pesinizde!" << endl;
                        gecerliSecim = false;// tekrar döngüye sokuyo, sanırım gereksiz ama
                    }
                }
                break;
            case savasSecimi:
                if (rand() % 2) {
                    cout << "Korsanlarin icinden gectiniz!!!" << endl;
                } else {
                    gemi->saglik -= savasHasar * gemi->hasarKatsayisi();
                    cout << "Savasi ve baska bir seyi kaybettiniz; ayrica hasar aldiniz. Guncel saglik: " << gemi->saglik << endl;
                }
                gecerliSecim = true;
                break;
            case pazarlikSecimi:
                istenenAltin = (rand() % 3 + 1) * altinPazarlikCarpan;
                cout << "Korsanlar sizden " << istenenAltin << " altin istiyor." << endl;
                cout << "Korsanlar Beyi: Ya parani ya da ...'nu alirim yegenim " << endl;
                if (istenenAltin <= gemi->para) {
                    gemi->para -= istenenAltin;
                    cout << "Korsanlar Beyi: Guzel boyle adam ol, gelecekte vermeye devam " << endl;
                    gecerliSecim = true;
                } else {
                    cout << "Korsanlara odeyecek kadar altininiz yok." << endl;
                    cout << "Ya savasmali ya da kacmalisiniz." << endl;
                }
                break;
            default:
                cout << "Gecersiz secim. Tekrar deneyin." << endl;
        }
    }
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    shared_ptr<Gemi> gemi;
    int gemiTipi;

    cout << "Gemi tipinizi secin:\n1. Hizli Gemi\n2. Guclu Gemi\n3. Normal Gemi\nSeciminizi girin: ";
    cin >> gemiTipi;

    switch (gemiTipi) {
        case 1:
            gemi = make_shared<HizliGemi>();
            break;
        case 2:
            gemi = make_shared<GucluGemi>();
            break;
        case 3:
            gemi = make_shared<NormalGemi>();
            break;
        default:
            cout << "Gecersiz secim. Normal Gemi olarak ayarlandı." << endl;
            gemi = make_shared<NormalGemi>();
    }

    for (int i = 0; i < olaySayisi; i++) {
        int olay = rand() % 3;
        switch (olay) {
            case 0:
                asteroidKusagi(gemi);
                break;
            case 1:
                terkedilmisGezegen(gemi);
                break;
            case 2:
                uzayKorsanlari(gemi);
                break;
        }

        if (gemi->yakit <= 1) {
            cout << "Yakitiniz tukendi. Oyun bitti." << endl;
            break;
        }
    }

    int skor = gemi->yakit * 5 + gemi->saglik * 10 + gemi->para * 10;
    cout << "Oyun bitti. Skorunuz: " << skor << endl;

    return 0;
}
