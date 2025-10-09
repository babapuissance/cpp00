#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private:
	int					_value;
	static const int	_fractionalBits = 8;

public:
	Fixed();
	Fixed(const int n);
	Fixed(const float f);
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	
	float	toFloat(void) const;
	int		toInt(void) const;

	// Opérateurs de comparaison
	bool	operator>(const Fixed& other) const;
	bool	operator<(const Fixed& other) const;
	bool	operator>=(const Fixed& other) const;
	bool	operator<=(const Fixed& other) const;
	bool	operator==(const Fixed& other) const;
	bool	operator!=(const Fixed& other) const;

	// Opérateurs arithmétiques
	Fixed	operator+(const Fixed& other) const;
	Fixed	operator-(const Fixed& other) const;
	Fixed	operator*(const Fixed& other) const;
	Fixed	operator/(const Fixed& other) const;

	// Opérateurs d'incrémentation/décrémentation
	Fixed&	operator++(void);		// Pré-incrémentation (++a)
	Fixed	operator++(int);		// Post-incrémentation (a++)
	Fixed&	operator--(void);		// Pré-décrémentation (--a)
	Fixed	operator--(int);		// Post-décrémentation (a--)

	// Fonctions statiques min/max
	static Fixed&		min(Fixed& a, Fixed& b);
	static const Fixed&	min(const Fixed& a, const Fixed& b);
	static Fixed&		max(Fixed& a, Fixed& b);
	static const Fixed&	max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
