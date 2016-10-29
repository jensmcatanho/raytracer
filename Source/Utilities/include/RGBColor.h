#ifndef RGBCOLOR_H
#define RGBCOLOR_H

#include "Prerequisites.h"

class RGBColor {
	public:
		double r, g, b;

		RGBColor();
		RGBColor(const double, const double, const double);
		RGBColor(const double);
		RGBColor(const RGBColor &);
		
		RGBColor &operator=(const RGBColor &);
		bool operator==(const RGBColor &) const;

		RGBColor operator+(const RGBColor &) const;
		RGBColor operator-(const RGBColor &) const;
		RGBColor operator*(const RGBColor &) const;
		RGBColor operator*(const float) const;
		RGBColor operator/(const float) const;

		RGBColor operator+=(const RGBColor &);
		RGBColor operator-=(const RGBColor &);
		RGBColor operator*=(const float);
		RGBColor operator/=(const float);

		RGBColor pow(const float) const;
		float average() const;

		// Color constants
		static const RGBColor Black;
		static const RGBColor White;
		static const RGBColor Red;
		static const RGBColor Green;
		static const RGBColor Blue;
};

inline bool RGBColor::operator==(const RGBColor &c) const {
	return (r == c.r) && (g == c.g) && (b == c.b);

}

inline RGBColor RGBColor::operator+(const RGBColor &c) const {
	return RGBColor(r + c.r, g + c.g, b + c.b);

}

inline RGBColor RGBColor::operator-(const RGBColor &c) const {
	return RGBColor(r - c.r, g - c.g, b - c.b);

}

inline RGBColor RGBColor::operator*(const RGBColor &c) const {
	return RGBColor(r * c.r, g * c.g, b * c.b);

}

inline RGBColor RGBColor::operator*(const float f) const {
	return RGBColor(r * f, g * f, b * f);

}

inline RGBColor RGBColor::operator/(const float f) const {
	return RGBColor(r/f, g/f, b/f);

}

inline RGBColor RGBColor::operator+=(const RGBColor &c) {
	r += c.r;
	g += c.g;
	b += c.b;

	return (*this);
}

inline RGBColor RGBColor::operator-=(const RGBColor &c) {
	r -= c.r;
	g -= c.g;
	b -= c.b;

	return (*this);
}

inline RGBColor RGBColor::operator*=(const float f) {
	r *= f;
	g *= f;
	b *= f;

	return (*this);
}

inline RGBColor RGBColor::operator/=(const float f) {
	r /= f;
	g /= f;
	b /= f;

	return (*this);
}

inline float RGBColor::average() const {
	return (float)(0.333333333333f * (r + g + b));

}

#endif
