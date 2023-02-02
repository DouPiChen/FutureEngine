#pragma once

#ifdef FE_PLATFORM_WINDOWS

extern FutureEngine::Application* FutureEngine::CreateApplication();

int main(int argc, char** argv)
{

	FutureEngine::Log::Init();
	FE_CORE_ERROR("Engine initialized");
	FE_INFO("APP initialized");

	auto app = FutureEngine::CreateApplication();
	app->Run();
	delete app;
}
#endif
