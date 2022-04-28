#include "Circle.hpp"
#include <math.h>
#include <iostream>

Circle::Circle(double r): Shape(Color::RED), r_(r)
{}


double Circle::getArea() const noexcept 
{
    return M_PI * r_ * r_;
}

double Circle::getPerimeter() const noexcept
{
    return 2 * M_PI * r_;
}

double Circle::getRadius() const
{
    return r_;
}

double Circle::getPi() const
{
    return M_PI;
}

void Circle::print() const
{
    std::cout << "Circle: radius: " << getRadius() << std::endl
              << "          area: " << getArea() << std::endl
              << "     perimeter: " << getPerimeter() << std::endl
              << "     Color: " << this->color << std::endl;
}

Circle::Circle(Circle &&circle)noexcept: Shape(Color::RED)  {
    r_ = circle.r_;
}

Circle &Circle::operator=(Circle &&circle) noexcept {
    r_ = circle.r_;
    return *this;
}