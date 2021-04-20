#version 410

layout (location = 0) in vec3 inPosition;

<<<<<<< Updated upstream
//Out lightspace matrix
=======
//out lightspace matrix
>>>>>>> Stashed changes
uniform mat4 u_LightSpaceMatrix;
uniform mat4 u_Model;

void main()
{ 
<<<<<<< Updated upstream
	//Lightspace matrix is the viewProjection matrix from the light's perspective
	gl_Position = u_LightSpaceMatrix * u_Model * vec4(inPosition, 1.0);
=======
	//lightspace matrix form the light's perspective
	gl_Position= u_LightSpaceMatrix * u_Model * vec4(inPosition,1.0);

>>>>>>> Stashed changes
}