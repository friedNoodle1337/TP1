#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace savranenko
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(const point_t& leftCorner, const point_t& rightCorner);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& newCentre) override;
    void move(double newX, double newY) override;

  private:
    void doScale(double scale) override;
    rectangle_t rect_;
  };
}

#endif
