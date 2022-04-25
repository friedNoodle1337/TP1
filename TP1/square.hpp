#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "shape.hpp"

namespace savranenko
{
  class Square : public Shape
  {
  public:
    Square(const point_t leftCorner, const double side);

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