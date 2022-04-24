#include <limits>
#include <stdexcept>
#include <cmath>

#include "rectangle.hpp"

namespace savranenko
{
  Rectangle::Rectangle(point_t leftCorner, point_t rightCorner)
  {
    if (rect_.width_ <= std::numeric_limits< double >::epsilon())
    {
      throw std::range_error("INVALID WIDTH");
    }

    if (rect_.height_ <= std::numeric_limits< double >::epsilon())
    {
      throw std::range_error("INVALID HEIGHT");
    }

    double width = rightCorner.x_ - leftCorner.x_;
    double height = rightCorner.y_ - leftCorner.y_;
    double posX = (rightCorner.x_ - leftCorner.x_) / 2;
    double posY = (rightCorner.y_ - leftCorner.y_) / 2;

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

  void Rectangle::move(double newX, double newY)
  {
    rect_.pos_.x_ += newX;
    rect_.pos_.y_ += newY;
  }

  void Rectangle::scale(const point_t centre, double scale)
  {
    if (scale <= std::numeric_limits< double >::epsilon())
    {
      throw std::range_error("INVALID SCALE");
    }

    rect_.width_ *= std::abs(scale);
    rect_.height_ *= std::abs(scale);
  }
}
