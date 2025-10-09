#include "Fixed.hpp"
#include <cmath>

/* ************************************************************************** */
/*                          Constructeurs & Destructeur                       */
/* ************************************************************************** */

Fixed::Fixed() : _value(0)
{
}

Fixed::Fixed(const int n)
{
	this->_value = n << this->_fractionalBits;
}

Fixed::Fixed(const float f)
{
	this->_value = roundf(f * (1 << this->_fractionalBits));
}

Fixed::Fixed(const Fixed& other)
{
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		this->_value = other.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
}

/* ************************************************************************** */
/*                       Getters, Setters & Conversions                       */
/* ************************************************************************** */

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

/* ************************************************************************** */
/*                    Opérateurs de comparaison (>, <, >=, etc.)             */
/* ************************************************************************** */

bool Fixed::operator>(const Fixed& other) const
{
	return this->_value > other._value;
}

bool Fixed::operator<(const Fixed& other) const
{
	return this->_value < other._value;
}

bool Fixed::operator>=(const Fixed& other) const
{
	return this->_value >= other._value;
}

bool Fixed::operator<=(const Fixed& other) const
{
	return this->_value <= other._value;
}

bool Fixed::operator==(const Fixed& other) const
{
	return this->_value == other._value;
}

bool Fixed::operator!=(const Fixed& other) const
{
	return this->_value != other._value;
}

/* ************************************************************************** */
/*                  Opérateurs arithmétiques (+, -, *, /)                    */
/* ************************************************************************** */

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed result;
	result.setRawBits(this->_value + other._value);
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed result;
	result.setRawBits(this->_value - other._value);
	return result;
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed result;
	result.setRawBits((this->_value * other._value) >> this->_fractionalBits);
	return result;
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed result;
	result.setRawBits((this->_value << this->_fractionalBits) / other._value);
	return result;
}

/* ************************************************************************** */
/*                 Incrémentation & Décrémentation (++, --)                   */
/* ************************************************************************** */

Fixed& Fixed::operator++(void)
{
	this->_value++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	this->_value++;
	return temp;
}

Fixed& Fixed::operator--(void)
{
	this->_value--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	this->_value--;
	return temp;
}

/* ************************************************************************** */
/*                      Fonctions statiques (min & max)                       */
/* ************************************************************************** */

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b) ? a : b;
}

/* ************************************************************************** */
/*                    Surcharge de l'opérateur d'insertion                    */
/* ************************************************************************** */

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return out;
}
