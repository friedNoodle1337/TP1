#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include "shape.hpp"

namespace savranenko
{
  class Diamond : public Shape
  {
  public:
    Diamond(const point_t centrePoint, const point_t upperPoint, const point_t sidePoint);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t newCentre) override;
    void move(const double newX, const double newY) override;
    void scale(const point_t centre, const double scale) override;

  private:
    rectangle_t rect_;
  };
}

#endif
