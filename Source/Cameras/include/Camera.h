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
#ifndef CAMERA_H
#define CAMERA_H

#include "Prerequisites.h"

class Camera {
	public:
		Camera();
		Camera(glm::vec3, glm::vec3);

		virtual void RenderScene(const World &w) = 0;

		// Setters.
		void SetEye(const glm::vec3 &);
		void LookAt(const glm::vec3 &);
		void SetUpVector(const glm::vec3 &);
		void SetYaw(const float);
		void SetPitch(const float);
		void SetRoll(const float);
		void SetExposureTime(const float);

	protected:
		// Computes the orthornormal basis given the eye point, the lookat point and the up vector.
		void ComputeUVW();
		
		// Location in world coordinates.
		glm::vec3 m_Eye;

		// Direction in which the camera is looking.
		glm::vec3 m_LookAt;

		// World's up vector.
		glm::vec3 m_UpVector;

		// Orthonormal basis vectors.
		glm::vec3 m_U, m_V, m_W;

		// Angles for rotation.
		float m_Yaw, m_Pitch, m_Roll;

		float m_ExposureTime;
};

inline void Camera::SetEye(const glm::vec3 &eye) {
	m_Eye = eye;
}

inline void Camera::LookAt(const glm::vec3 &lookat) {
	m_LookAt = lookat;
}

inline void Camera::SetUpVector(const glm::vec3 &up) {
	m_UpVector = up;
}

inline void Camera::SetYaw(const float yaw) {
	m_Yaw = yaw;
}

inline void Camera::SetPitch(const float pitch) {
	m_Pitch = pitch;
}

inline void Camera::SetRoll(const float roll) {
	m_Roll = roll;
}

inline void Camera::SetExposureTime(const float etime) {
	m_ExposureTime = etime;
}

#endif