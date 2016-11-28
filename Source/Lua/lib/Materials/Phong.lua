Phong = {}

function Phong.new()
	local self = {}

	-- Private member variables
	self.name = "Phong"

	-- Public member variables
	self.diffuse_color = {r = 0.0, g = 0.0, b = 0.0}
	self.diffuse_reflection = 1.0
	self.ambient_color = {r = 0.0, g = 0.0, b = 0.0}
	self.ambient_reflection = 1.0
	self.specular_color = {r = 0.0, g = 0.0, b = 0.0}
	self.specular_reflection = 1.0
	self.specular_exp = 1.0

	-- Public methods
	function self.SetDiffuseRGB(r, g, b)
		diffuse_color.r, diffuse_color.g, diffuse_color.b = r, g, b
	end

	function self.SetAmbientRGB(r, g, b)
		ambient_color.r, ambient_color.g, ambient_color.b = r, g, b
	end

	function self.SetSpecularRGB(r, g, b)
		specular_color.r, specular_color.g, specular_color.b = r, g, b
	end

	function self.SetRGB(r, g, b)
		SetDiffuseRGB(r, g, b)
		SetAmbientRGB(r, g, b)
	end

	return self
end

return Phong