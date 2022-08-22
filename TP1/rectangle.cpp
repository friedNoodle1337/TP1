#include "rectangle.hpp"

#include <stdexcept>

namespace savranenko
{
  Rectangle::Rectangle(const point_t& leftCorner, const point_t& rightCorner)
  {
    if (leftCorner.x_ > rightCorner.x_)
    {
      throw std::logic_error("BAD POINTS");
    }
    if (leftCorner.y_ > rightCorner.y_)
    {
      throw std::logic_error("BAD POINTS");
    }

    rect_.width_ = rightCorner.x_ - leftCorner.x_;
    rect_.height_ = rightCorner.y_ - leftCorner.y_;
    rect_.pos_.x_ = leftCorner.x_ + rect_.width_ / 2;
    rect_.pos_.y_ = leftCorner.y_ + rect_.height_ / 2;
  }

  double Rectangle::getArea() const
  {
    return rect_.width_ * rect_.height_;
  }

  rectangle_t Rectangle::getFrameRect() const
  {
    return rect_;
  }

  void Rectangle::move(const point_t& newCentre)
  {
    rect_.pos_ = newCentre;
  }

  void Rectangle::move(double newX, double newY)
  {
    rect_.pos_.x_ += newX;
    rect_.pos_.y_ += newY;
  }

  void Rectangle::doScale(double scale)
  {
    rect_.width_ *= scale;
    rect_.height_ *= scale;
  }
}
