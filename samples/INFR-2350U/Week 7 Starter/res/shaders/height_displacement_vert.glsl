#version 410

layout(location = 0) in vec3 inPosition;
layout(location = 1) in vec3 inColor;
layout(location = 2) in vec3 inNormal;
layout(location = 3) in vec2 inUV;

layout(location = 0) out vec3 outPos;
layout(location = 1) out vec3 outColor;
layout(location = 2) out vec3 outNormal;
layout(location = 3) out vec2 outUV;
layout(location = 4) out vec4 outFragPosLightSpace;

uniform mat4 u_ModelViewProjection;
uniform mat4 u_View;
uniform mat4 u_Model;
uniform mat3 u_NormalMatrix;
uniform vec3 u_LightPos;
uniform mat4 u_LightSpaceMatrix;

uniform sampler2D s_Height;
uniform float u_HeightIntensity;

<<<<<<< Updated upstream
void main() 
{
	float displacementVal = (2.0 * texture(s_Height, inUV).x) - 1.0;

	vec4 displacedVert = (vec4(inPosition, 1.0)) + (vec4(0.0, 0.0, u_HeightIntensity, 0.0) * displacementVal);

	gl_Position = u_ModelViewProjection * displacedVert;

	// Lecture 5
	// Pass vertex pos in world space to frag shader
	outPos = ((u_Model * displacedVert)).xyz;
=======
void main() {

	float displacementVal = (2.0 * texture(s_Height,inUV).x) -1.0;

	vec4 displacementVert = (vec4(inPosition,1.0)) + (vec4(0.0,0.0,u_HeightIntensity,0.0) * displacementVal);

	gl_Position = u_ModelViewProjection * displacementVert;

	// Lecture 5
	// Pass vertex pos in world space to frag shader
	outPos = (u_Model *displacementVert).xyz;
>>>>>>> Stashed changes

	// Normals
	outNormal = u_NormalMatrix * inNormal;

	// Pass our UV coords to the fragment shader
	outUV = inUV;

	//Pass out the light space fragment pos
	outFragPosLightSpace = u_LightSpaceMatrix * vec4(outPos, 1.0);

	///////////
	outColor = inColor;

<<<<<<< Updated upstream
}
=======
	}
>>>>>>> Stashed changes
