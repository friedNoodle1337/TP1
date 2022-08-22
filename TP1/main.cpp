﻿#include <iostream>
#include <iomanip>

#include "utils.hpp"
#include "rectangle.hpp"
#include "diamond.hpp"
#include "square.hpp"

using namespace savranenko;

int main()
{
  std::cout << std::fixed << std::setprecision(1);

  std::string str;
  std::shared_ptr< double[] > doubles;
  shapeArr_t shapes;
  std::size_t shapesCount = 0;
  bool scaleCheck = false;
  bool correctnessCheck = true;
  while (std::cin >> str)
  {
    try
    {
      if (str == "RECTANGLE")
      {
        doubles = enterPoints(4);
        point_t leftCorner = { doubles[0], doubles[1] };
        point_t rightCorner = { doubles[2], doubles[3] };
        addShape(shapes, shapePtr_t(new Rectangle(leftCorner, rightCorner)), shapesCount++);
      }
      else if (str == "SQUARE")
      {
        doubles = enterPoints(3);
        point_t leftCorner = { doubles[0], doubles[1] };
        addShape(shapes, shapePtr_t(new Square(leftCorner, doubles[2])), shapesCount++);
      }
      else if (str == "DIAMOND")
      {
        doubles = enterPoints(6);
        point_t firstPoint = { doubles[0], doubles[1] };
        point_t secondPoint = { doubles[2], doubles[3] };
        point_t thirdPoint = { doubles[4], doubles[5] };
        addShape(shapes, shapePtr_t(new Diamond(firstPoint, secondPoint, thirdPoint)), shapesCount++);
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
          return 1;
        }
        if (!std::cin || shapesCount == 0)
        {
          std::cerr << "SCALE ERROR" << "\n";
          return 1;
        }
        else
        {
          printShapes(shapes, shapesCount);
          for (std::size_t i = 0; i < shapesCount; i++)
          {
            scaleShapes(shapes[i], coef, pointX, pointY);
          }
          printShapes(shapes, shapesCount);
        }
        break;
      }
    }
    catch (const std::exception& exception)
    {
      std::string temp = exception.what();
      std::cerr << temp << "\n";
      if (temp == "INVALID SIDE")
      {
        correctnessCheck = false;
      }
    }
  }
  if (scaleCheck == false)
  {
    std::cerr << "THERE IS NOT SCALE" << "\n";
    return 1;
  }
  if (correctnessCheck == false)
  {
    return 1;
  }

  return 0;
}
