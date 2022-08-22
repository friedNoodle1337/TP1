#include "square.hpp"

#include <stdexcept>

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

  void Square::move(double newX, double newY)
  {
    rect_.pos_.x_ += newX;
    rect_.pos_.y_ += newY;
  }

  void Square::doScale(double scale)
  {
    rect_.width_ *= scale;
    rect_.height_ *= scale;
  }
}
