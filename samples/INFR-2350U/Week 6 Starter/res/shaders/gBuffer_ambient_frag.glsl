#version 420

layout(location = 0) in vec2 inUV;

struct DirectionalLight
{
	//Light direction (defaults to down, to the left, and a little forward)
	vec4 _lightDirection;

	//Generic Light controls
	vec4 _lightCol;

	//Ambience controls
	vec4 _ambientCol;
	float _ambientPow;
	
	//Power controls
	float _lightAmbientPow;
	float _lightSpecularPow;
	
	float _shadowBias;
};

<<<<<<< HEAD
layout (std140, binding = 0) uniform u_Lights
{
    DirectionalLight ambience;
};


layout (binding = 0) uniform sampler2D s_albedoTex;
layout (binding = 4) uniform sampler2D s_lightAccumTex;
layout (binding = 5) uniform sampler2D s_skyBox;

out vec4 frag_color;


void main(){

    //albedo 
    vec4 textureColor = texture(s_albedoTex, inUV); 

    //lights 
    vec4 lightAccum = texture(s_lightAccumTex, inUV);

    //skybox
    vec4 skybox = texture(s_skyBox,inUV);

    //ambient calculation
    vec3 ambient = ambience._lightAmbientPow * ambience._ambientCol.rgb;

    //the result of all lighting
    vec3 result = (ambient + lightAccum.rgb) * textureColor.rgb;

    //add the skybox
    result = result* skybox.rgb;

    //the light accumulation
    frag_color = vec4 (result,1.0);



}









=======
layout (std140, binding = 0) uniform u_Light
{
	DirectionalLight light;
};

layout (binding = 0) uniform sampler2D s_albedoTex;
layout (binding = 4) uniform sampler2D s_lightAccumTex;
layout (binding = 5) uniform sampler2D s_skybox;

out vec4 frag_color;

void main() 
{
	//Albedo
	vec4 textureColor = texture(s_albedoTex, inUV);
	//Lights
	vec4 lightAccum = texture(s_lightAccumTex, inUV);
	//Skybox
	vec4 skybox = texture(s_skybox, inUV);

	// Lecture 5
	vec3 ambient = light._lightAmbientPow * light._ambientCol.rgb;

	//The result of all the lighting
	vec3 result = (ambient + lightAccum.rgb) * textureColor.rgb;

	result = result * skybox.rgb;

	//The light accumulation
	frag_color = vec4(result, 1.0);
}
>>>>>>> master
