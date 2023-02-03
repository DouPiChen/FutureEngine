#include "fepch.h"
#include <FutureEngine.h>

class Sandbox : public FutureEngine::Application
{
public:
	Sandbox()
	{
	
	}

	~Sandbox()
	{
	
	}
};

FutureEngine::Application* FutureEngine::CreateApplication()
{
	return new Sandbox();
}

