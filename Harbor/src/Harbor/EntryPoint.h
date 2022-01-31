#pragma once

#ifdef HB_PLATFROM_WINDOWS

extern Harbor::Application* Harbor::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Harbor::CreateApplication();
	app->Run();
	delete app;
}
#endif // HB_PLATFROM_WINDOWS
