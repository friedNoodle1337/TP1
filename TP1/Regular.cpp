#include <stdexcept>
#include <cmath>
#include "Regular.h"

namespace bavykin
{
    Regular::Regular(point_t firstPoint, point_t secondPoint, point_t thirdPoint)
    {
        m_Rect.m_Pos = firstPoint;

        double firstSideWidth = std::abs(firstPoint.m_X - secondPoint.m_X);
        double firstSideHeight = std::abs(firstPoint.m_Y - secondPoint.m_Y);
        double firstSide = std::sqrt(std::pow(firstSideWidth, 2) + std::pow(firstSideHeight, 2));

        double secondSideWidth = std::abs(firstPoint.m_Y - thirdPoint.m_Y);
        double secondSideHeight = std::abs(firstPoint.m_Y - thirdPoint.m_Y);
        double secondSide = std::sqrt(std::pow(secondSideWidth, 2) + std::pow(secondSideHeight, 2));

        double thirdSideWidth = std::abs(secondPoint.m_Y - thirdPoint.m_Y);
        double thirdSideHeight = std::abs(secondPoint.m_Y - thirdPoint.m_Y);
        double thirdSide = std::sqrt(std::pow(thirdSideWidth, 2) + std::pow(thirdSideHeight, 2));

        m_CathetOppositeTheCenter = thirdSide;

        if (std::sqrt(std::pow(thirdSide, 2) + std::pow(secondSide, 2)) == firstSide)
        {
            m_BigRadius = firstSide;
            m_SmallRadius = secondSide;
        }
        else if (std::sqrt(std::pow(thirdSide, 2) + std::pow(firstSide, 2)) == secondSide)
        {
            m_BigRadius = secondSide;
            m_SmallRadius = firstSide;
        }
        else
        {
            throw std::logic_error("Invalid arguments, it is not a right triangle.");
        }

        calculateFrameRect();
    }

    double Regular::getArea() const
    {
        double PI = std::acos(-1);
        double R = m_BigRadius;
        int n = getTheNumberOfCorners();

        return n * std::pow(R, 2) / 2 * std::sin(2 * PI / n);
    }

    int Regular::getTheNumberOfCorners() const
    {
        double PI = std::acos(-1);
        double side = m_CathetOppositeTheCenter * 2;
        double R = m_BigRadius;

        return PI / std::asin(side / 2 * R);
    }

    rectangle_t Regular::getFrameRect() const
    {
        /// TO DO: ...

        return m_Rect;
    }

    void Regular::move(point_t centre)
    {
        m_Rect.m_Pos = centre;
    }

    void Regular::move(double x, double y)
    {
        m_Rect.m_Pos.m_X += x;
        m_Rect.m_Pos.m_Y += y;
    }

    void Regular::calculateFrameRect()
    {
        // TO DO: ...
    }

    void Regular::scale(point_t centre, double scale)
    {
        m_BigRadius *= scale;
        m_SmallRadius *= scale;

        move(centre);

        calculateFrameRect();
    }
}
