#pragma once

#include "Shape.hpp"

class Circle final : public Shape 
{
public:
    explicit Circle(double r);
    Circle(const Circle & other) = default;
    Circle(Circle && circle) noexcept;

    Circle& operator=(Circle&& circle ) noexcept;
    
    double getArea() const noexcept override;
    double getPerimeter() const  noexcept override;
    double getRadius() const;
    [[deprecated]]  double getPi() const;
    void print() const override;

private:
    Circle() = delete; // doesn't allow to call default constructor

    double r_;
};
