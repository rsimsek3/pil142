#include "Gemi.h"
#include "constlar.h"
#include "Oyun.h"
#include <iostream>
#include <cstdlib>
#include <memory>



void Oyun::basla() {
    secGemi();
    for (int i = 0; i < 5; ++i) {
        if (yakit <= 0 || saglik <= 0) break;
        int olay = rand() % 3 + 1;
        switch (olay) {
            case 1:
                asteroidKusagi();
                break;
            case 2:
                terkedilmisGezegen();
                break;
            case 3:
                uzayKorsanlari();
                break;
        }
    }
    puanHesapla();
}


void Oyun::secGemi() {
    int secim;
    std::cout << " Uzay Yolculuguna Hazirlanin!!!\n" "Zorlu Uzay Macerasinda Kisginizi Yansitan Gemiyi Secmeniz Onerilir!!\n" " Gemi secin (1: Hizli Gemi, 2: Guclu Gemi, 3: Normal Gemi): ";
    std::cin >> secim;
    switch (secim) {
        case 1:
            gemi = std::make_unique<HizliGemi>();
            break;
        case 2:
            gemi = std::make_unique<GucluGemi>();
            break;
        default:
            gemi = std::make_unique<NormalGemi>();
            break;
    }
}

void Oyun::asteroidKusagi() {
    std::cout <<"HAY AKSI!!!\n" "Asteroid Kusagina Girdin! Hasar aliyorsun.\n";
    saglik -= HasarMiktari;
}

void Oyun::pazarlik() {
    int ucret = PazarlikSecenekleri[rand() % 3];
    std::cout << "Vicdansiz Korsanlar Senden " << ucret << " Altin Istiyor.\n";
    if (para >= ucret) {
        para -= ucret;
        std::cout <<"Memleket Kayseri mi???\n" "Pazarlik basarili. Korsanlar sizi biraktilar.\n";
    } else {
        std::cout << "Paran yok pazarliga tutusuyon :DDD Korsanlar Sinirlendi Isin Kilicini Kusan.\n";
        savas();
    }
}

void Oyun::uzayKorsanlari() {
    std::cout << "1 Dakika Guzergahta Davetsiz Misafirler Var\n ""Uzay korsanlariyla karsilastin!\n""YOK ARTIK UZAYDA KORSAN MI OLUR DEME:) KARSILASTIN ISTE:D\n""Secimini Yap (1: Kac, 2: Savas, 3: Pazarlik): ";
    int secim;
    std::cin >> secim;
    switch (secim) {
        case 1: // Kaç
            if (yakit < HarcananYakit) {
                std::cout << "Depoda Mazot Yok!!  Savasa hazirlan.\n";
                savas();
            } else {
                yakit -= HarcananYakit;
                if (rand() % 2 < gemi->getKacmaCarpani()) {
                    std::cout << "Dogru Soyle Ehliyeti Tekte Aldin Degil mi??! Korsanlara Tozunu Yutturdun!!!\n";
                } else {
                    std::cout << "Maalesef ki kacamadin Isin Kilicini Kusan!!! Savas Basliyor!!!.\n";
                    savas();
                }
            }
            break;
        case 2: // Savaş
            savas();
            break;
        case 3: // Pazarlık
            pazarlik();
            break;
        default:
            std::cout << "Uyaniklik Yapma Korkaklik Etme Isin Kilicini Kusan Ve Savas!!!.\n";
            savas();
            break;
    }
}

void Oyun::terkedilmisGezegen() {
    std::cout << "Terkedilmis Bir Gezegene Ulastiniz. ";
    if (rand() % 2) {
        std::cout << "Sansli Gunundesin! Cumhuriyet Altini buldun!\n";
        para += AltinMiktari;
    } else {
        std::cout << "1 Dakika Guzergahta Davetsiz Misafirler Var. Uzay korsanlariyla karsilastin. YOK ARTIK UZAYDA KORSAN MI OLUR DEME:) KARSILASTIN ISTE:D\n";
        uzayKorsanlari(); // Doğrudan uzay korsanlarıyla karşılaşma
    }
}

void Oyun::savas() {
    std::cout << "Uzay Korsanlariyla savasiyorsun. Her Sey Inanmakta Biter Mentalini Saglam TUT!\n";
    if (rand() % 2) {
        std::cout << "100 Isik Yili Yasamis Korsanlar Boyle Maglubiyet Tatmadilar!!! Savasi Kazandin!\n";
    } else {
        std::cout << "Dunyanin Yuzunu Kara Cıkarttın!! Uzay Korsanları Gemiye Vuruyor!!! . Hasar Aliyorsun.\n";
        saglik -= AlinanHasar * gemi->getHasarCarpani();
    }
}

void Oyun::puanHesapla() const {
    int puan = yakit * 5 + saglik * 10 + para * 10;
    std::cout << "Uzay Yolculugunun Sonuna Geldin!!! Oyun bitti. Toplam Puan: " << puan << std::endl;
}
