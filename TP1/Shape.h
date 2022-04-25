#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

class Shape
{
public:
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t centre) = 0;
    virtual void move(double x, double y) = 0;
    virtual void scale(const point_t centre, double scale) = 0;
};

#endif
