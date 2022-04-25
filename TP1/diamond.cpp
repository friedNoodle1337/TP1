#include <stdexcept>

#include "diamond.hpp"

namespace savranenko
{
  Diamond::Diamond(const point_t centrePoint, const point_t upperPoint, const point_t sidePoint)
  {
    double width = 0.0;
    double height = 0.0;

    if (sidePoint.x_ >= centrePoint.x_)
    {
      width = (sidePoint.x_ - centrePoint.x_) * 2;
    }
    else
    {
      width = (centrePoint.x_ - sidePoint.x_) * 2;
    }
    if (upperPoint.y_ >= centrePoint.y_)
    {
      height = (upperPoint.y_ - centrePoint.y_) * 2;
    }
    else
    {
      height = (centrePoint.y_ - upperPoint.y_) * 2;
    }
    double posX = centrePoint.x_;
    double posY = centrePoint.y_;

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

  double Diamond::getArea() const
  {
    return rect_.width_ * rect_.height_ / 2;
  }

  rectangle_t Diamond::getFrameRect() const
  {
    return rect_;
  }

  void Diamond::move(const point_t newCentre)
  {
    rect_.pos_ = newCentre;
  }

  void Diamond::move(const double newX, const double newY)
  {
    rect_.pos_.x_ += newX;
    rect_.pos_.y_ += newY;
  }

  void Diamond::scale(const point_t centre, const double scale)
  {
    if (scale <= 0.0)
    {
      throw std::range_error("INVALID SCALE");
    }

    rect_.width_ *= scale;
    rect_.height_ *= scale;
  }
}
