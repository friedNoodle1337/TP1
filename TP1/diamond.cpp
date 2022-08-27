#include "diamond.hpp"

#include <cmath>
#include <stdexcept>

namespace savranenko
{
  Diamond::Diamond(const point_t& pointA, const point_t& pointB, const point_t& pointC)
  {
    if ((pointA.x_ == pointB.x_ && pointA.y_ == pointC.y_) || (pointA.x_ == pointC.x_ && pointA.y_ == pointB.y_))
    {
      rect_.pos_ = pointA;
      rect_.width_ = std::fmax(std::abs(pointB.x_ - pointA.x_) * 2, std::abs(pointC.x_ - pointA.x_) * 2);
      rect_.height_ = std::fmax(std::abs(pointB.y_ - pointA.y_) * 2, std::abs(pointC.y_ - pointA.y_) * 2);
    }
    else if ((pointA.x_ == pointB.x_ && pointB.y_ == pointC.y_) || (pointB.x_ == pointC.x_ && pointA.y_ == pointB.y_))
    {
      rect_.pos_ = pointB;
      rect_.width_ = std::fmax(std::abs(pointA.x_ - pointB.x_) * 2, std::abs(pointC.x_ - pointB.x_) * 2);
      rect_.height_ = std::fmax(std::abs(pointA.y_ - pointB.y_) * 2, std::abs(pointC.y_ - pointB.y_) * 2);
    }
    else if ((pointA.x_ == pointC.x_ && pointB.y_ == pointC.y_) || (pointB.x_ == pointC.x_ && pointA.y_ == pointC.y_))
    {
      rect_.pos_ = pointC;
      rect_.width_ = std::fmax(std::abs(pointA.x_ - pointC.x_) * 2, std::abs(pointB.x_ - pointC.x_) * 2);
      rect_.height_ = std::fmax(std::abs(pointA.y_ - pointC.y_) * 2, std::abs(pointB.y_ - pointC.y_) * 2);
    }
    else
    {
      throw std::logic_error("BAD POINTS");
    }
  }

  double Diamond::getArea() const
  {
    return rect_.width_ * rect_.height_ / 2;
  }

  rectangle_t Diamond::getFrameRect() const
  {
    return rect_;
  }

  void Diamond::move(const point_t& newCentre)
  {
    rect_.pos_ = newCentre;
  }

  void Diamond::move(double newX, double newY)
  {
    rect_.pos_.x_ += newX;
    rect_.pos_.y_ += newY;
  }

  void Diamond::doScale(double scale)
  {
    rect_.width_ *= scale;
    rect_.height_ *= scale;
  }
}
