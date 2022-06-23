#include <stdexcept>
#include <cmath>

#include "diamond.hpp"

namespace savranenko
{
  Diamond::Diamond(const point_t& firstPoint, const point_t& secondPoint, const point_t& thirdPoint)
  {
    point_t centrePoint;
    point_t upperPoint;
    point_t sidePoint;
    bool FirstAndSecondLinedUpX = firstPoint.x_ == secondPoint.x_;
    bool FirstAndThirdLinedUpX = firstPoint.x_ == thirdPoint.x_;
    bool SecondAndThirdLinedUpX = secondPoint.x_ == thirdPoint.x_;
    bool FirstAndSecondLinedUpY = firstPoint.y_ == secondPoint.y_;
    bool FirstAndThirdLinedUpY = firstPoint.y_ == thirdPoint.y_;
    bool SecondAndThirdLinedUpY = secondPoint.y_ == thirdPoint.y_;

    if (FirstAndSecondLinedUpX)
    {
      if (FirstAndThirdLinedUpY)
      {
        centrePoint = firstPoint;
        upperPoint = secondPoint;
        sidePoint = thirdPoint;
      }
      else if (SecondAndThirdLinedUpY)
      {
        centrePoint = secondPoint;
        upperPoint = firstPoint;
        sidePoint = thirdPoint;
      }
      else
      {
        throw std::logic_error("BAD POINTS");
      }
    }
    else if (FirstAndThirdLinedUpX)
    {
      if (FirstAndSecondLinedUpY)
      {
        centrePoint = firstPoint;
        upperPoint = thirdPoint;
        sidePoint = secondPoint;
      }
      else if (SecondAndThirdLinedUpY)
      {
        centrePoint = thirdPoint;
        upperPoint = firstPoint;
        sidePoint = secondPoint;
      }
      else
      {
        throw std::logic_error("BAD POINTS");
      }
    }
    else if (SecondAndThirdLinedUpX)
    {
      if (FirstAndSecondLinedUpY)
      {
        centrePoint = secondPoint;
        upperPoint = thirdPoint;
        sidePoint = firstPoint;
      }
      else if (FirstAndThirdLinedUpY)
      {
        centrePoint = thirdPoint;
        upperPoint = secondPoint;
        sidePoint = firstPoint;
      }
      else
      {
        throw std::logic_error("BAD POINTS");
      }
    }
    else
    {
      throw std::logic_error("BAD POINTS");
    }

    rect_.width_ = std::abs(sidePoint.x_ - centrePoint.x_) * 2;
    rect_.height_ = std::abs(upperPoint.y_ - centrePoint.y_) * 2;
    rect_.pos_.x_ = centrePoint.x_;
    rect_.pos_.y_ = centrePoint.y_;
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

  void Diamond::move(const double& newX, const double& newY)
  {
    rect_.pos_.x_ += newX;
    rect_.pos_.y_ += newY;
  }

  void Diamond::scale(const double& scale)
  {
    rect_.width_ *= scale;
    rect_.height_ *= scale;
  }
}
