#ifndef UTILS_HPP
#define UTILS_HPP

#include <memory>

#include "shape.hpp"

namespace savranenko
{
  using shapePtr_t = std::shared_ptr< Shape >;
  using shapeArr_t = std::shared_ptr< shapePtr_t[] >;

  void addDouble(std::shared_ptr< double[] >& arr, double element, std::size_t count);
  void addShape(shapeArr_t& arr, shapePtr_t shape, std::size_t count);
  std::shared_ptr< double[] > enterPoints(std::size_t nDoubles);
  void printShapes(const shapeArr_t& shapes, std::size_t count);
  void scaleShapes(const shapePtr_t& shape, double coef, double pointX, double pointY);
}

#endif
