#include "fepch.h"
#include <FutureEngine.h>

class ExampleLayer :public FutureEngine::Layer
{
public:
	ExampleLayer() :Layer("Example") {}

	void OnUpdate() override
	{
		FE_INFO("ExampleLayer::OnUpdate");
	}

	void OnEvent(FutureEngine::Event& event) override
	{
		FE_INFO("ExampleLayer::OnUpdate");
	}
};

class Sandbox : public FutureEngine::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{
	
	}
};

FutureEngine::Application* FutureEngine::CreateApplication()
{
	return new Sandbox();
}

