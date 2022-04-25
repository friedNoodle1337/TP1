#include <stdexcept>

#include "rectangle.hpp"

namespace savranenko
{
  Rectangle::Rectangle(const point_t leftCorner, const point_t rightCorner)
  {
    double width = rightCorner.x_ - leftCorner.x_;
    double height = rightCorner.y_ - leftCorner.y_;
    double posX = (rightCorner.x_ - leftCorner.x_) / 2;
    double posY = (rightCorner.y_ - leftCorner.y_) / 2;

    if (width <= 0.0)
    {
      throw std::range_error("INVALID WIDTH");
    }

    if (height <= 0.0)
    {
      throw std::range_error("INVALID HEIGHT");
    }

    rect_.width_ = width;
    rect_.height_ = height;
    rect_.pos_.x_ = posX;
    rect_.pos_.y_ = posY;
  }

  double Rectangle::getArea() const
  {
    return rect_.width_ * rect_.height_;
  }

  rectangle_t Rectangle::getFrameRect() const
  {
    return rect_;
  }

  void Rectangle::move(const point_t newCentre)
  {
    rect_.pos_ = newCentre;
  }

  void Rectangle::move(const double newX, const double newY)
  {
    rect_.pos_.x_ += newX;
    rect_.pos_.y_ += newY;
  }

  void Rectangle::scale(const point_t centre, const double scale)
  {
    if (scale <= 0.0)
    {
      throw std::range_error("INVALID SCALE");
    }

    rect_.width_ *= scale;
    rect_.height_ *= scale;
    move(centre);
  }
}
