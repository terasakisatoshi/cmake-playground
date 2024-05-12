#ifndef AFFINE_HPP
#define AFFINE_HPP

class Affine {
public:
  Affine(double w11, double w12, double w21, double w22, double b1, double b2);

  void transform(double &x, double &y);

private:
  double w11, w12, w21, w22, b1, b2;
};

#endif // AFFINE_HPP