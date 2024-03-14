#include <iostream>


class Gemi {
public:
    int yakit;
    int saglik;
    int para;
};

class HizliGemi : public Gemi {
public:
    double hasar_carpici;
    double kacma_olasiligi;
    HizliGemi() {
        yakit = 100;
        saglik = 100;
        para = 0;
        hasar_carpici = 1.5;
        kacma_olasiligi = 1.5;
    }


};
class GucluGemi : public Gemi {
public:
    double hasar_carpici;
    double kacma_olasiligi;
    GucluGemi() {
        yakit = 100;
        saglik = 100;
        para = 0;
        hasar_carpici = 0.5;
        kacma_olasiligi = 0.5;
    }


};

class NormalGemi : public Gemi {
public:
    double hasar_carpici;
    double kacma_olasiligi;
    NormalGemi() {
        yakit = 100;
        saglik = 100;
        para = 0;
        hasar_carpici = 1.0;
        kacma_olasiligi = 1.0;
    }

};