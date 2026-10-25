#include "Point.hpp"
#include <iostream>

Point::Point(): x(0), y(0) {
	// std::cout<<"Default constructor called"<<std::endl;

};
Point::Point(const Point& other): x(other.x), y(other.y) {
	// std::cout<<"Copy constructor called"<<std::endl;
}

Point::Point(const float x, const float y): x(x), y(y) {}


Point& Point::operator=(const Point& other) {
	// std::cout<<"Copy assignment operator called"<<std::endl;
	(void)other;
	return *this;
}

Point::~Point() {
	// std::cout<<"Destructor called"<<std::endl;
}

Fixed Point::getX(void) const {
	return this->x;
}

Fixed Point::getY(void) const {
	return this->y;
}