#pragma once

#include "Core.h"

namespace FutureEngine 
{
	class FE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}