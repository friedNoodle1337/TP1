#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace savranenko
{
  struct point_t
  {
    double x_, y_;
  };

  struct rectangle_t
  {
    double width_, height_;
    point_t pos_;
  };
}

#endif
