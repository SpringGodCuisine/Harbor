#pragma once

#include "Core.h"
#include "Harbor/Events/Event.h"
#include "Harbor/LayerStack.h"
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
		
		void PushLayer(Layer* layer);
		
		void PushOverlay(Layer* overlay);

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};
	
	//To be define in CLIENT
	Application* CreateApplication();
}



