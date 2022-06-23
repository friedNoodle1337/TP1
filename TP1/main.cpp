#include <iostream>
#include <iomanip>
#include <string>

#include "utils.hpp"
#include "rectangle.hpp"
#include "diamond.hpp"
#include "square.hpp"

using namespace savranenko;

void enterPoints(Array< double >& doubles, int&& nDoubles)
{
  std::string stringOfDoubles;
  std::getline(std::cin, stringOfDoubles, '\n');
  int start = 1;
  int end = 0;
  for (int i = 0; i < nDoubles; i++)
  {
    end = stringOfDoubles.find(' ', start);
    if (start != 0 && end != 0)
    {
      doubles.add(std::strtod(stringOfDoubles.substr(start, end).c_str(), nullptr));
      start = end + 1;
    }
    else
    {
      throw std::range_error("NOT ENOUGH POINTS");
    }
  }
}

void printShapes(const Array< std::shared_ptr< Shape > >& shapes)
{
  double sumArea = 0;
  for (std::size_t i = 0; i < shapes.getSize(); i++)
  {
    sumArea += shapes[i]->getArea();
  }
  std::cout << sumArea;

  rectangle_t frame;
  point_t leftCorner;
  point_t rightCorner;
  for (std::size_t i = 0; i < shapes.getSize(); i++)
  {
    frame = shapes[i]->getFrameRect();
    leftCorner = {frame.pos_.x_ - frame.width_ / 2, frame.pos_.y_ - frame.height_ / 2};
    rightCorner = {frame.pos_.x_ + frame.width_ / 2, frame.pos_.y_ + frame.height_ / 2};
    std::cout << ' ' << leftCorner.x_ << ' ' << leftCorner.y_;
    std::cout << ' ' << rightCorner.x_ << ' ' << rightCorner.y_;
    if (i == shapes.getSize() - 1)
    {
      std::cout << "\n";
    }
  }
}

void scaleShapes(const std::shared_ptr< Shape >& shape, double coef, double pointX, double pointY)
{
  shape->scale(coef);
  rectangle_t frame = shape->getFrameRect();
  shape->move({pointX - (pointX - frame.pos_.x_) * coef, pointY - (pointY - frame.pos_.y_) * coef});
}

int main()
{
  std::cout << std::fixed << std::setprecision(1);

  std::string str;
  Array< std::shared_ptr < Shape > > shapes;
  bool scaleCheck = false;
  while (std::cin >> str)
  {
    try
    {
      if (str == "RECTANGLE")
      {
        Array< double > doubles;
        enterPoints(doubles, 4);
        shapes.add(std::shared_ptr< Shape >(
          new Rectangle({doubles[0], doubles[1]}, {doubles[2], doubles[3]})));
      }
      else if (str == "SQUARE")
      {
        Array< double > doubles;
        enterPoints(doubles, 3);
        shapes.add(std::shared_ptr< Shape >(
          new Square({doubles[0], doubles[1]}, doubles[2])));
      }
      else if (str == "DIAMOND")
      {
        Array< double > doubles;
        enterPoints(doubles, 6);
        shapes.add(std::shared_ptr< Shape >(
          new Diamond({doubles[0], doubles[1]}, {doubles[2], doubles[3]}, {doubles[4], doubles[5]})));
      }
      else if (str == "SCALE")
      {
        scaleCheck = true;
        double pointX = 0.0;
        double pointY = 0.0;
        double coef = 0.0;
        std::cin >> pointX >> pointY >> coef;
        if (coef <= 0.0)
        {
          std::cerr << "INVALID SCALE" << "\n";
          return -3;
        }
        if (!std::cin || !shapes.getSize())
        {
          std::cerr << "SCALE ERROR" << "\n";
          return -1;
        }
        else
        {
          printShapes(shapes);
          for (std::size_t i = 0; i < shapes.getSize(); i++)
          {
            scaleShapes(shapes[i], coef, pointX, pointY);
          }
          printShapes(shapes);
        }
        break;
      }
    }
    catch (const std::exception& exception)
    {
      std::cerr << exception.what() << "\n";
    }
  }
  if (scaleCheck == false)
  {
    std::cerr << "THERE IS NOT SCALE" << "\n";
    return -2;
  }

  return 0;
}
