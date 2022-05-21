#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"
#include "Harbor/Events/ApplicationEvent.h"

namespace Harbor {

	class HARBOR_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};
	
	//To be define in CLIENT
	Application* CreateApplication();
}



