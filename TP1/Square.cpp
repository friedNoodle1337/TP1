#include <limits>
#include <stdexcept>
#include "Square.h"

namespace bavykin
{
    Square::Square(point_t leftCorner, double sideLength)
    {
        double length = sideLength;

        m_Rect.m_Width = length;
        m_Rect.m_Height = length;
        m_Rect.m_Pos.m_X = leftCorner.m_X + length / 2;
        m_Rect.m_Pos.m_Y = leftCorner.m_Y + length / 2;
    }

    double Square::getArea() const
    {
        return m_Rect.m_Width * 2;
    }

    rectangle_t Square::getFrameRect() const
    {
        return m_Rect;
    }

    void Square::move(point_t centre)
    {
        m_Rect.m_Pos = centre;
    }

    void Square::move(double x, double y)
    {
        m_Rect.m_Pos.m_X += x;
        m_Rect.m_Pos.m_Y += y;
    }

    void Square::scale(point_t centre, double scale)
    {
        m_Rect.m_Width *= scale;
        m_Rect.m_Height *= scale;
    }
}
