#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = n << this->_fractionalBits;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(f * (1 << this->_fractionalBits));
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_value = other.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	return this->_value;
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float Fixed::toFloat(void) const
{
	return (float)this->_value / (1 << this->_fractionalBits);
}

int Fixed::toInt(void) const
{
	return this->_value >> this->_fractionalBits;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return out;
}
