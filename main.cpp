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
