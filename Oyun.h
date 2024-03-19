#ifndef OYUN_H
#define OYUN_H

#ifndef COSMICVOYAGER_OYUN_H
#define COSMICVOYAGER_OYUN_H

#include "Gemi.h"
#include "constlar.h"
#include <memory>
#include <ctime>
#include <cstdlib>

class Oyun {
public:
    Oyun() : yakit(BaslangicYakiti), saglik(BaslangicSagligi), para(BaslangicPara) {
        srand(time(nullptr));
    }
    void basla();

private:
    std::unique_ptr<Gemi> gemi;
    int yakit, saglik, para;

    void secGemi();
    void asteroidKusagi();
    void terkedilmisGezegen();
    void uzayKorsanlari();
    void savas();
    void pazarlik();
    void puanHesapla() const;
};

#endif //COSMICVOYAGER_OYUN_H
#endif OYUN_H
