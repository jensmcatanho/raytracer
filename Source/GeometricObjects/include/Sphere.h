/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2016 Jean Michel Catanho

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
-----------------------------------------------------------------------------
*/
#ifndef SPHERE_H
#define SPHERE_H

#include "Object.h"

class Sphere : public Object {
	public:
		// Default constructor.
		Sphere();

		// Return true and shading information if a ray intersects with this Object.
		virtual bool Hit(const Ray &, double &, ShadeRecord &) const;

		// Return true and shading information if a ray intersects with this Object.
		virtual bool ShadowHit(const Ray &, float &) const;

		void SetCenter(const glm::vec3 &);
		void SetRadius(const float);

	private:
		// Center of the Sphere in world coordinates.
		glm::vec3 m_Center;

		// Radius of the Sphere.
		float m_Radius;

		// Epsilon factor.
		static const double kEpsilon;

};

inline void Sphere::SetCenter(const glm::vec3 &center) {
	m_Center = center;
}
		
inline void Sphere::SetRadius(const float radius) {
	m_Radius = radius;
}

#endif
