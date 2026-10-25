#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : rawBits(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->rawBits = other.rawBits;
	return *this;
}

Fixed::Fixed(const int value)
{
	// std::cout << "Int constructor called" << std::endl;
	this->rawBits = (value << this->fractionalBits);
}

Fixed::Fixed(const float value)
{
	// std::cout << "Float constructor called" << std::endl;
	this->rawBits = roundf(value * (1 << this->fractionalBits));
}

bool Fixed::operator>(const Fixed& obj) const
{
	return (this->rawBits > obj.rawBits);
}
bool Fixed::operator<(const Fixed& obj) const
{
	return (this->rawBits < obj.rawBits);
}
bool Fixed::operator>=(const Fixed& obj) const
{
	return (this->rawBits >= obj.rawBits);
}
bool Fixed::operator<=(const Fixed& obj) const
{
	return (this->rawBits <= obj.rawBits);
}
bool Fixed::operator==(const Fixed& obj) const
{
	return (this->rawBits == obj.rawBits);
}
bool Fixed::operator!=(const Fixed& obj) const
{
	return (this->rawBits != obj.rawBits);
}

Fixed Fixed::operator+(const Fixed& obj) const
{
	Fixed res;

	res.setRawBits(this->rawBits + obj.rawBits);
	return res;
}
Fixed Fixed::operator-(const Fixed& obj) const
{
	Fixed res;
	res.setRawBits(this->rawBits - obj.rawBits);
	return res;
}
Fixed Fixed::operator*(const Fixed& obj) const
{
	return Fixed(this->toFloat() * obj.toFloat());
}
Fixed Fixed::operator/(const Fixed& obj) const
{
	return Fixed(this->toFloat() / obj.toFloat());
}

Fixed &Fixed::operator++()
{
	this->rawBits += 1;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed copy(*this);
	this->rawBits += 1;
	return copy;
}

Fixed &Fixed::operator--()
{
	this->rawBits -= 1;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed copy(*this);
	this->rawBits -= 1;
	return copy;
}

Fixed& Fixed::min(Fixed& obj1, Fixed& obj2)
{
	return obj1 < obj2 ? obj1 : obj2;
}
Fixed& Fixed::max(Fixed& obj1, Fixed& obj2)
{
	return obj1 > obj2 ? obj1 : obj2;
}
const Fixed& Fixed::min(const Fixed& obj1, const Fixed& obj2)
{
	return obj1 < obj2 ? obj1 : obj2;
}
const Fixed& Fixed::max(const Fixed& obj1, const Fixed& obj2)
{
	return obj1 > obj2 ? obj1 : obj2;
}

int Fixed::toInt(void) const
{
	return (this->rawBits >> this->fractionalBits);
}

float Fixed::toFloat(void) const
{
	return (float)(this->rawBits) / (1 << this->fractionalBits);
}

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return this->rawBits;
}

void Fixed::setRawBits(int const raw)
{
	this->rawBits = raw;
}

std::ostream &operator<<(std::ostream &out, const Fixed& obj)
{
	out << obj.toFloat();
	return out;
}