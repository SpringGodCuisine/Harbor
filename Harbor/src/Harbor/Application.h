#pragma once
#include "Core.h"

namespace Harbor {
	class HARBOR_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//To be define in CLIENT
	Application* CreateApplication();
}



