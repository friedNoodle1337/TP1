#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace savranenko
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(point_t leftCorner, point_t rightCorner);

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
