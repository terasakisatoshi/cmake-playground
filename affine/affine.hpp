#include <Eigen/Dense>

class Affine{
public:
    Affine(const Eigen::Matrix2d W, const Eigen::Vector2d b);
    Eigen::Vector2d transform(const Eigen::Vector2d x);
    Eigen::Matrix2d W;
    Eigen::Vector2d b;
};
