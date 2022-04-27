#ifndef REGULAR_HPP
#define REGULAR_HPP
#include "Shape.h"

namespace bavykin
{
    class Regular : public Shape
    {
    public:
        Regular(point_t firstPoint, point_t secondPoint, point_t thirdPoint);

        double getArea() const override;
        rectangle_t getFrameRect() const override;
        void move(const point_t centre) override;
        void move(double x, double y) override;
        void scale(const point_t centre, double scale) override;

    private:
        double m_CathetOppositeTheCenter;
        double m_BigRadius;
        double m_SmallRadius;
        rectangle_t m_Rect;

        void calculateFrameRect();
        int getTheNumberOfCorners() const;
    };
}

#endif
