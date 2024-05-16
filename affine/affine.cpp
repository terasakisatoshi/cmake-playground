#include "affine.hpp"
#include <Eigen/Dense>

//constructor function
Affine::Affine(const Eigen::Matrix2d W, const Eigen::Vector2d b) : W(W), b(b) {};
Eigen::Vector2d Affine::transform(const Eigen::Vector2d x){
    return W * x + b;
}
