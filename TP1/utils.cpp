#include "utils.hpp"

#include <iostream>
#include <string>

namespace savranenko
{
  void addDouble(std::shared_ptr< double[] >& doubles, double element, std::size_t count)
  {
    std::shared_ptr< double[] > newArr = std::shared_ptr< double[] >(new double[count + 1]);

    for (std::size_t i = 0; i < count; i++)
    {
      newArr[i] = doubles[i];
    }
    newArr[count] = element;

    doubles = newArr;
  }

  void addShape(shapeArr_t& shapes, shapePtr_t shape, std::size_t count)
  {
    shapeArr_t newArr = shapeArr_t(new shapePtr_t[count + 1]);

    for (std::size_t i = 0; i < count; i++)
    {
      newArr[i] = shapes[i];
    }
    newArr[count] = shape;

    shapes= newArr;
  }

  std::shared_ptr< double[] > enterPoints(std::size_t nDoubles)
  {
    std::string stringOfDoubles;
    std::getline(std::cin, stringOfDoubles, '\n');

    int start = 1;
    int end = 0;
    std::shared_ptr< double[] > doubles;
    for (std::size_t i = 0; i < nDoubles; i++)
    {
      end = stringOfDoubles.find(' ', start);
      if (start != 0 && end != 0)
      {
        double temp = std::strtod(stringOfDoubles.substr(start, end).c_str(), nullptr);
        addDouble(doubles, temp, i);
        start = end + 1;
      }
      else
      {
        throw std::range_error("NOT ENOUGH POINTS");
      }
    }

    return doubles;
  }

  void printShapes(const shapeArr_t& shapes, std::size_t count)
  {
    double sumArea = 0;
    for (std::size_t i = 0; i < count; i++)
    {
      sumArea += shapes[i]->getArea();
    }
    std::cout << sumArea;

    rectangle_t frame;
    point_t leftCorner, rightCorner;
    for (std::size_t i = 0; i < count; i++)
    {
      frame = shapes[i]->getFrameRect();
      leftCorner = { frame.pos_.x_ - frame.width_ / 2, frame.pos_.y_ - frame.height_ / 2 };
      rightCorner = { frame.pos_.x_ + frame.width_ / 2, frame.pos_.y_ + frame.height_ / 2 };
      std::cout << ' ' << leftCorner.x_ << ' ' << leftCorner.y_;
      std::cout << ' ' << rightCorner.x_ << ' ' << rightCorner.y_;
      if (i == count - 1)
      {
        std::cout << "\n";
      }
    }
  }

  void scaleShapes(const shapePtr_t& shape, double coef, double pointX, double pointY)
  {
    shape->scale(coef);
    rectangle_t frame = shape->getFrameRect();
    shape->move({ pointX - (pointX - frame.pos_.x_) * coef, pointY - (pointY - frame.pos_.y_) * coef });
  }
}
