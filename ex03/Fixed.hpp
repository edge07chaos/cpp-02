#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int rawBits;
	static const int fractionalBits = 8;

public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &src);
	Fixed &operator=(const Fixed &other);

	Fixed(const int value);
	Fixed(const float value);

	bool operator>(const Fixed &obj) const;
	bool operator<(const Fixed &obj) const;
	bool operator>=(const Fixed &obj) const;
	bool operator<=(const Fixed &obj) const;
	bool operator==(const Fixed &obj) const;
	bool operator!=(const Fixed &obj) const;

	Fixed operator+(const Fixed& obj) const; 
	Fixed operator-(const Fixed& obj) const; 
	Fixed operator*(const Fixed& obj) const; 
	Fixed operator/(const Fixed& obj) const;

	Fixed& operator++();
	Fixed& operator--();
	Fixed operator++(int);
	Fixed operator--(int);

	static Fixed& min(Fixed& obj1, Fixed& obj2);
	static Fixed& max(Fixed& obj1, Fixed& obj2);
	static const Fixed& min(const Fixed& obj1, const Fixed& obj2);
	static const Fixed& max(const Fixed& obj1, const Fixed& obj2);

	int toInt(void) const;
	float toFloat(void) const;
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &out, const Fixed &obj);

#endif
