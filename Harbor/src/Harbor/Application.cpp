#include "hbpch.h"
#include "Application.h"


#include "Harbor/Events/ApplicationEvent.h"
#include "Harbor/Log.h"

namespace Harbor {
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1920, 1080);
		if (e.IsInCategory(EventCategoryApplication))
		{
			HB_INFO(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			HB_INFO(e);
		}

		while (true);
	}
}

