#include <stdexcept>
#include "Rectangle.h"

namespace bavykin
{
    Rectangle::Rectangle(point_t leftCorner, point_t rightCorner)
    {
        double width = std::abs(rightCorner.m_X - leftCorner.m_X);
        double height = std::abs(leftCorner.m_Y - rightCorner.m_Y);
        double posX = std::abs(rightCorner.m_X - leftCorner.m_X) / 2;
        double posY = std::abs(leftCorner.m_Y - rightCorner.m_Y) / 2;

        m_Rect.m_Width = width;
        m_Rect.m_Height = height;
        m_Rect.m_Pos.m_X = posX;
        m_Rect.m_Pos.m_Y = posY;
    }

    double Rectangle::getArea() const
    {
        return m_Rect.m_Width * m_Rect.m_Height;
    }

    rectangle_t Rectangle::getFrameRect() const
    {
        return m_Rect;
    }

    void Rectangle::move(point_t centre)
    {
        m_Rect.m_Pos = centre;
    }

    void Rectangle::move(double x, double y)
    {
        m_Rect.m_Pos.m_X += x;
        m_Rect.m_Pos.m_Y += y;
    }

    void Rectangle::scale(point_t centre, double scale)
    {
        m_Rect.m_Width *= scale;
        m_Rect.m_Height *= scale;
    }
}
