#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include "shape.hpp"

namespace savranenko
{
  class Diamond : public Shape
  {
  public:
    Diamond(point_t centrePoint, point_t upperPoint, point_t sidePoint);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t newCentre) override;
    void move(double newX, double newY) override;
    void scale(const point_t centre, double scale) override;

  private:
    rectangle_t rect_;
  };
}

#endif
