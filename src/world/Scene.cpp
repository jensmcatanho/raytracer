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
#include "Scene.h"
#include "Ambient.h"
#include "Object.h"
#include "Ray.h"
#include "Sampler.h"
#include "Surface.h"
#include "Tracer.h"

Scene::Scene() :
	m_BackgroundColor(RGBColor::Black),
	m_AmbientPtr(new Ambient),
	m_CameraPtr(nullptr),
	m_TracerPtr(nullptr) {

	m_Pixels = new RGBColor[m_ProjectionPlane.m_Width * m_ProjectionPlane.m_Height];
}

void Scene::DisplayPixel(const int row, const int column, const RGBColor &raw_color) const {
	RGBColor mapped_color;

	if (m_ProjectionPlane.m_ClampOutOfGamut)
		mapped_color = RGBColor::ClampToColor(raw_color, m_ProjectionPlane.m_ClampColor);
	else
		mapped_color = RGBColor::MaxToOne(raw_color);
	
	if (m_ProjectionPlane.m_Gamma != 1.0)
		mapped_color = RGBColor(glm::pow(mapped_color.r, m_ProjectionPlane.m_InvGamma),
								glm::pow(mapped_color.g, m_ProjectionPlane.m_InvGamma),
								glm::pow(mapped_color.b, m_ProjectionPlane.m_InvGamma));

	m_Pixels[row * m_ProjectionPlane.m_Width + column].r = mapped_color.r;
	m_Pixels[row * m_ProjectionPlane.m_Width + column].g = mapped_color.g;
	m_Pixels[row * m_ProjectionPlane.m_Width + column].b = mapped_color.b;
}

Surface Scene::HitObjects(const Ray &ray) {
	Surface sr(*this);
	double t; 			
	double tmin = kHugeValue;
	glm::vec3 normal;
	glm::vec3 local_hit_point;
	int num_objects = m_Objects.size();
	
	for (int i = 0; i < num_objects; i++)
		if (m_Objects[i]->Hit(ray, t, sr) && (t < tmin)) {
			sr.m_Hit = true;
			tmin = t;

			sr.m_MaterialPtr = m_Objects[i]->GetMaterial();
			sr.m_HitPoint = ray.m_Origin + static_cast<float>(t) * ray.m_Direction;

			normal = sr.m_Normal;
			local_hit_point = sr.m_LocalHitPoint;
		}

	if (sr.m_Hit) {
		sr.m_T = tmin;
		sr.m_Normal = normal;
		sr.m_LocalHitPoint = local_hit_point;
	}

	return sr;
}
