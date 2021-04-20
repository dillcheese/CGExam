#include "GBuffer.h"

void GBuffer::Init(unsigned width, unsigned height)
{
<<<<<<< HEAD
	//store height and width of window
	_windowWidth = width;
	_windowHeight = height;

	//adds color targets to g buffer
	_gBuffer.AddColorTarget(GL_RGBA8); //albedo buffer, needs all channels
	_gBuffer.AddColorTarget(GL_RGB8); //normals buffer, does not need alpha
	_gBuffer.AddColorTarget(GL_RGB8); //specular buffer, technivcally only needs 1 channel

	//obtain positional data using depth buffer.
	//here we use position buffer
	_gBuffer.AddColorTarget(GL_RGB32F);

	//add a depth buffer
	_gBuffer.AddDepthTarget();

	//init framebufer
	_gBuffer.Init(width, height);
	
	//init passthrough shader
=======
	//Stores window width and height
	_windowWidth = width;
	_windowHeight = height;

	//Adds color targets to our gbuffer
	_gBuffer.AddColorTarget(GL_RGBA8);		//Albedo Buffer, needs GL_RGBA8
	_gBuffer.AddColorTarget(GL_RGB8);		//Normals Buffer, doesn't need Alpha channel
	_gBuffer.AddColorTarget(GL_RGB8);			//specular buffer, only needs 1 channel

	//Important note, technically you can obtain the positional data using the depth buffer (there are calculations you can do), but in this case we're
	//going to use a POSITION buffer
	_gBuffer.AddColorTarget(GL_RGB32F);		//Stores the positional data of the scene, actually NEEDS more data storage, so we use GL_RGB32F

	//Adds our depth buffer
	_gBuffer.AddDepthTarget();

	//Inits our framebuffer
	_gBuffer.Init(width, height);

	//Initializes pass through shader;
>>>>>>> master
	_passThrough = Shader::Create();
	_passThrough->LoadShaderPartFromFile("shaders/passthrough_vert.glsl", GL_VERTEX_SHADER);
	_passThrough->LoadShaderPartFromFile("shaders/passthrough_frag.glsl", GL_FRAGMENT_SHADER);
	_passThrough->Link();
}

void GBuffer::Bind()
{
	_gBuffer.Bind();
}

void GBuffer::BindLighting()
{
	_gBuffer.BindColorAsTexture(Target::ALBEDO, 0);
	_gBuffer.BindColorAsTexture(Target::NORMAL, 1);
	_gBuffer.BindColorAsTexture(Target::SPECULAR, 2);
	_gBuffer.BindColorAsTexture(Target::POSITION, 3);
}

void GBuffer::Clear()
{
	_gBuffer.Clear();
}

void GBuffer::Unbind()
{
	_gBuffer.Unbind();
}

void GBuffer::UnbindLighting()
{
	_gBuffer.UnbindTexture(0);
	_gBuffer.UnbindTexture(1);
	_gBuffer.UnbindTexture(2);
	_gBuffer.UnbindTexture(3);
}

void GBuffer::DrawBuffersToScreen()
{
<<<<<<< HEAD
	//bind passthroguh shader
	_passThrough->Bind();

	//set viewport to top left
=======
	//Binds our Passthrough shader
	_passThrough->Bind();

	//Set viewport to top left corner
>>>>>>> master
	glViewport(0, _windowHeight / 2.f, _windowWidth / 2.f, _windowHeight / 2.f);
	_gBuffer.BindColorAsTexture(Target::ALBEDO, 0);
	_gBuffer.DrawFullscreenQuad();
	_gBuffer.UnbindTexture(0);

<<<<<<< HEAD
	//set viewport to top right
=======
	
	//Set viewport to the top right
>>>>>>> master
	glViewport(_windowWidth / 2.f, _windowHeight / 2.f, _windowWidth / 2.f, _windowHeight / 2.f);
	_gBuffer.BindColorAsTexture(Target::NORMAL, 0);
	_gBuffer.DrawFullscreenQuad();
	_gBuffer.UnbindTexture(0);

<<<<<<< HEAD
	//set viewport to bottom left
=======
	
	//Set viewport to the bottom left
>>>>>>> master
	glViewport(0, 0, _windowWidth / 2.f, _windowHeight / 2.f);
	_gBuffer.BindColorAsTexture(Target::SPECULAR, 0);
	_gBuffer.DrawFullscreenQuad();
	_gBuffer.UnbindTexture(0);

<<<<<<< HEAD
	//set viewport to bottom right
=======
	//Set viewport to the bottom right
>>>>>>> master
	glViewport(_windowWidth / 2.f, 0, _windowWidth / 2.f, _windowHeight / 2.f);
	_gBuffer.BindColorAsTexture(Target::POSITION, 0);
	_gBuffer.DrawFullscreenQuad();
	_gBuffer.UnbindTexture(0);

<<<<<<< HEAD
	//unbind passthorugh shader
=======
	//Unbinds our Passthrough shader
>>>>>>> master
	_passThrough->UnBind();
}

void GBuffer::Reshape(unsigned width, unsigned height)
{
<<<<<<< HEAD
	//store new width and height
	_windowWidth = width;
	_windowHeight = height;

	//reshape framebuffer
	_gBuffer.Reshape(width, height);
}
=======
	//Updates the saved width and height values
	_windowWidth = width;
	_windowHeight = height;

	//Reshapes the framebuffer with the new width and height
	_gBuffer.Reshape(width, height);
}
>>>>>>> master
