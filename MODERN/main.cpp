#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <memory>
#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include "Circle.hpp"
#include <functional>
using namespace std;

using Collection = vector<shared_ptr<Shape>> ;


void printCollectionElements(const Collection& collection)
{
    for(const auto& it : collection)
        if(it)
            (it)->print();
}

void printAreas(const Collection& collection)
{
    for(const auto& it : collection)
        if(it)
            cout << it->getArea() << std::endl;
}

void findFirstShapeMatchingPredicate(const Collection& collection,
                                     std::function<bool(shared_ptr<Shape>)> predicate,
                                     std::string info)
{
    Collection::const_iterator iter = std::find_if(collection.begin(), collection.end(), predicate);
    if(*iter != nullptr)
    {
        cout << "First shape matching predicate: " << info << endl;
        (*iter)->print();
    }
    else
    {
        cout << "There is no shape matching predicate " << info << endl;
    }
}


constexpr unsigned int fibonacci(int target){

    unsigned int fib = 0, current = 1, prev = 0;

    for (auto i = 1; i < target; i++) {
        fib = current + prev;
        prev = current;
        current = fib;
    }

    return fib;
} 


int main()
{

    constexpr auto result = fibonacci(45);
    std::cout << "Fibonacci: " << result << std::endl;

    Collection shapes{make_shared<Circle>(2.0), make_shared<Circle>(3.0), nullptr, 
                      make_shared<Circle>(4.0), make_shared<Rectangle>(10.0, 5.0), 
                      make_shared<Square>(3.0), make_shared<Circle>(4.0), 
                      make_shared<Circle>(Color::RED)};
    

    printCollectionElements(shapes);

    std::cout << "Areas before sort: " << std::endl;
    printAreas(shapes);

    auto sortByArea = [](shared_ptr<Shape> first, shared_ptr<Shape> second) -> auto {
        if (first == nullptr || second == nullptr)
            return false;
        return (first->getArea() < second->getArea());
    };

    std::sort(shapes.begin(), shapes.end(), sortByArea);

    std::cout << "Areas after sort: " << std::endl;
    printAreas(shapes);

    auto square = make_shared<Square>(4.0);
    shapes.push_back(std::move(square));
    printCollectionElements(shapes);
    auto perimeterBiggerThan20 = [](shared_ptr<Shape> s) -> auto 
    { 
        if(s)
            return (s->getPerimeter() > 20);
        return false;
    };


    findFirstShapeMatchingPredicate(shapes, perimeterBiggerThan20, "perimeter bigger than 20");


    auto areaLessThanX = [x = 10](shared_ptr<Shape> s) -> auto 
    {
        if (s)
            return (s->getArea() < x);
        return false;
    };

    findFirstShapeMatchingPredicate(shapes, areaLessThanX, "area less than 10");



    return 0;
}

