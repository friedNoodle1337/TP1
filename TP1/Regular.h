#ifndef REGULAR_HPP
#define REGULAR_HPP
#include "Shape.h"

namespace bavykin
{
    class Regular : public Shape
    {
    public:
        Regular(point_t leftCorner, point_t rightCorner);

        double getArea() const override;
        rectangle_t getFrameRect() const override;
        void move(const point_t centre) override;
        void move(double x, double y) override;
        void scale(const point_t centre, double scale) override;

    private:
        rectangle_t m_Rect;
    };
}

#endif
