#include "affine.hpp"

Affine::Affine(double w11, double w12, double w21, double w22, double b1, double b2)
      : w11(w11), w12(w12), w21(w21), w22(w22), b1(b1), b2(b2) {}

void Affine::transform(double &x, double &y) {
    double newX = w11 * x + w12 * y + b1;
    double newY = w21 * x + w22 * y + b2;
    x = newX;
    y = newY;
}
