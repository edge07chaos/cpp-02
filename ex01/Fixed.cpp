#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(): rawBits(0) {
	std::cout<<"Default constructor called"<<std::endl;
}

Fixed::Fixed(const Fixed& src) {
	std::cout<<"Copy constructor called"<<std::endl;
	*this = src;
}

Fixed::Fixed(const int value) {
	std::cout<<"Int constructor called"<<std::endl;
	this->rawBits = (value << this->fractionalBits);
}

Fixed::Fixed(const float value) {
	std::cout<<"Float constructor called"<<std::endl;
	this->rawBits = roundf(value * (1<<this->fractionalBits));
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout<<"Copy assignment operator called"<<std::endl;
	if (this != &other)
		this->rawBits = other.rawBits;
	return *this;
}

Fixed::~Fixed() {
	std::cout<<"Destructor called"<<std::endl;
}

int Fixed::getRawBits(void) const {
	std::cout<<"getRawBits member function called"<<std::endl;
	return this->rawBits;
}

void Fixed::setRawBits(int const raw) {
	this->rawBits = raw;
}

int Fixed::toInt(void) const {
	return (this->rawBits >> 8);
}

float Fixed::toFloat(void) const {
	return (float)(this->rawBits) / (1<<this->fractionalBits);
}

std::ostream& operator<<(std::ostream& out,const Fixed& obj) {
	out << obj.toFloat();
	return out;
}