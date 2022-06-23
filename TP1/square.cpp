#include <stdexcept>

#include "square.hpp"

namespace savranenko
{
  Square::Square(const point_t& leftCorner, const double& side)
  {
    if (side <= 0.0)
    {
      throw std::range_error("INVALID SIDE");
    }

    rect_.width_ = side;
    rect_.height_ = side;
    rect_.pos_.x_ = leftCorner.x_ + (side / 2);
    rect_.pos_.y_ = leftCorner.y_ + (side / 2);
  }

  double Square::getArea() const
  {
    return rect_.width_ * rect_.height_;
  }

  rectangle_t Square::getFrameRect() const
  {
    return rect_;
  }

  void Square::move(const point_t& newCentre)
  {
    rect_.pos_ = newCentre;
  }

  void Square::move(const double& newX, const double& newY)
  {
    rect_.pos_.x_ += newX;
    rect_.pos_.y_ += newY;
  }

  void Square::scale(const double& scale)
  {
    rect_.width_ *= scale;
    rect_.height_ *= scale;
  }
}
