#pragma once

#ifdef FE_PLATFORM_WINDOWS

extern FutureEngine::Application* FutureEngine::CreateApplication();

int main(int argc, char** argv)
{
	printf("Welcome to FutureEngine!\n");
	auto app = FutureEngine::CreateApplication();
	app->Run();
	delete app;
}
#endif
