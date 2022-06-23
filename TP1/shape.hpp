#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

namespace savranenko
{
  class Shape
  {
  public:
    virtual ~Shape() = default;

    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t& newCentre) = 0;
    virtual void move(const double& newX, const double& newY) = 0;
    virtual void scale(const double& scale) = 0;
  };
}

#endif
