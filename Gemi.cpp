#include "Gemi.h"

Gemi::~Gemi() {}

double HizliGemi::getKacmaCarpani() const { return 1.5; }
double HizliGemi::getHasarCarpani() const { return 1.5; }

double GucluGemi::getKacmaCarpani() const { return 0.5; }
double GucluGemi::getHasarCarpani() const { return 0.5; }

double NormalGemi::getKacmaCarpani() const { return 1.0; }
double NormalGemi::getHasarCarpani() const { return 1.0; }
