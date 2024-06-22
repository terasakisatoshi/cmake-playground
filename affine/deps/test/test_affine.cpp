#include <gtest/gtest.h>

#include <Eigen/Dense>
#include "affine.hpp"

TEST(AffineTest, constructor) {
    double w11=1.0;
    double w12=0.0;
    double w21=0.0;
    double w22=1.0;
    Eigen::Matrix2d W {      // construct a 2x2 matrix
      {w11, w12},     // first row
      {w21, w22}      // second row
    };

    double b1=2.0;
    double b2=-1.0;
    Eigen::Vector2d b {b1, b2};

    Affine aff = Affine(W, b);
}

TEST(AffineTest, transform) {
    double w11=1.0;
    double w12=0.0;
    double w21=0.0;
    double w22=1.0;
    Eigen::Matrix2d W {      // construct a 2x2 matrix
      {w11, w12},     // first row
      {w21, w22}      // second row
    };

    double b1=2.0;
    double b2=-1.0;
    Eigen::Vector2d b {b1, b2};

    Affine aff = Affine(W, b);

    Eigen::Vector2d x {0.0,0.0};
    auto y = aff.transform(x);
    EXPECT_EQ(y[0], b1);
    EXPECT_EQ(y[1], b2);

    x[0] = 1.0;
    x[1] = 1.0;
    y = aff.transform(x);
    EXPECT_EQ(y[0], 3.0);
    EXPECT_EQ(y[1], 0.0);
}
