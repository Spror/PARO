#pragma once

#include "Rectangle.hpp"

class Square : public Rectangle
{
public:
    Square() = delete;
    Square(double x);
    Square(const Square & other) = default;
    Square(Square && square) noexcept;

    /* Square& operator=(Square && square) noexcept; */

    double getArea() const override;
    double getPerimeter() const override;
    void print() const override;

    



private:
    double getY() = delete; // should not have Y dimension
    
};
