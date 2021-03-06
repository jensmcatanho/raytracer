/*
-----------------------------------------------------------------------------
The MIT License (MIT)

Copyright (c) 2016-2017 Jean Michel Catanho

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
#ifndef RAY_H
#define RAY_H

#include "Prerequisites.h"

/**
 * @addtogroup Utilities
 * @{
 */

/**
 * Object used to trace scenes.
 * @remarks TODO
 */
class Ray {
	public:
		/**
		 * Standard constructor.
		 */
		Ray();

		/**
		 * Constructs a ray with the target origin and direction.
		 * @param origin    Target origin.
		 * @param direction Target direction.
		 */
		Ray(glm::vec3 &origin, glm::vec3 &direction);

		/**
		 * Origin of the ray in world coordinates.
		 */
		glm::vec3 m_Origin;

		/**
		 * Direction of the ray.
		 */
		glm::vec3 m_Direction;
};

/**
 * @}
 */

#endif
