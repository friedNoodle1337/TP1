#ifndef UTILS_HPP
#define UTILS_HPP

#include <memory>
#include <cmath>
#include <stdexcept>

namespace savranenko
{
  template < class T >
  class Array
  {
  public:
    Array();

    const T& operator[](std::size_t index) const;
    T& operator[](std::size_t index);
    void add(const T& item);
    std::size_t getSize() const noexcept;

  private:
    std::size_t size_;
    std::size_t capacity_;
    std::shared_ptr< T[] > arr_;
  };

  template < class T >
  Array< T >::Array() :
    size_(0),
    capacity_(1),
    arr_(new T[1])
  {}

  template < class T >
  const T& Array< T >::operator[](std::size_t index) const
  {
    if (index >= size_)
    {
      throw std::range_error("ShapeArray: BAD INDEX");
    }

    return arr_[index];
  }

  template < class T >
  T& Array< T >::operator[](std::size_t index)
  {
    if (index >= size_)
    {
      throw std::range_error("ShapeArray: BAD INDEX");
    }

    return arr_[index];
  }

  template < class T >
  void Array< T >::add(const T& item)
  {
    if (size_ == capacity_)
    {
      capacity_ = static_cast<std::size_t>(std::round(capacity_ * 1.5));
      std::shared_ptr< T[] > temp(new T[capacity_]);
      for (std::size_t i = 0; i < size_; i++)
      {
        temp[i] = arr_[i];
      }
      temp[size_] = item;
      arr_ = temp;
      size_++;
      return;
    }

    arr_[size_] = item;
    size_++;
  }

  template < class T >
  std::size_t Array< T >::getSize() const noexcept
  {
    return size_;
  }
}

#endif
