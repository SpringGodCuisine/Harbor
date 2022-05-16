#pragma once

#ifdef HB_PLATFROM_WINDOWS

extern Harbor::Application* Harbor::CreateApplication();

int main(int argc, char** argv)
{
	Harbor::Log::Init();

	std::string engineName = "Harbor Game Engine";

	HB_CORE_TRACE("Hi! This is a Log from {0}", engineName);

	auto app = Harbor::CreateApplication();
	app->Run();
	delete app;
}
#endif // HB_PLATFROM_WINDOWS
