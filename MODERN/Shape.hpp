#pragma once

enum Color: unsigned char
{
    RED,
    GREEN,
    BLUE
};

class Shape
{
public:
    explicit Shape(Color given_color): color(given_color) {};
    virtual ~Shape() {};

    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void print() const;

    Color color= Color::RED;
};
