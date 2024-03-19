#ifndef COSMICVOYAGER_GEMI_H
#define COSMICVOYAGER_GEMI_H

class Gemi {
public:
    virtual ~Gemi();
    virtual double getKacmaCarpani() const = 0;
    virtual double getHasarCarpani() const = 0;
};

class HizliGemi : public Gemi {
public:
    double getKacmaCarpani() const override;
    double getHasarCarpani() const override;
};

class GucluGemi : public Gemi {
public:
    double getKacmaCarpani() const override;
    double getHasarCarpani() const override;
};

class NormalGemi : public Gemi {
public:
    double getKacmaCarpani() const override;
    double getHasarCarpani() const override;
};

#endif //COSMICVOYAGER_GEMI_H
