#include "shape.hpp"

#include <stdexcept>

namespace savranenko
{
  void Shape::scale(double scale)
  {
    if (scale <= 0.0)
    {
      throw std::range_error("INVALID SCALE");
    }
    doScale(scale);
  }
}
