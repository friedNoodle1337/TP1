#ifndef UTILS_HPP
#define UTILS_HPP

#include <memory>

#include "shape.hpp"

namespace savranenko
{
  using shapePtr_t = std::shared_ptr< Shape >;
  using shapeArr_t = std::shared_ptr< shapePtr_t[] >;

  void addDouble(std::shared_ptr< double[] >& arr, double element, size_t count);
  void addShape(shapeArr_t& arr, shapePtr_t shape, size_t count);
  std::shared_ptr< double[] > enterPoints(size_t nDoubles);
  void printShapes(shapeArr_t& shapes, size_t count);
  void scaleShapes(shapePtr_t& shape, double coef, double pointX, double pointY);
}

#endif
