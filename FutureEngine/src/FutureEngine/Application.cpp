#include "fepch.h"
#include "Application.h"

#include "FutureEngine/Event/ApplicationEvent.h"
#include "FutureEngine/Log.h"

namespace FutureEngine {

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1200, 720);
		FE_INFO(e.ToString());
		while (true);
	}
}
