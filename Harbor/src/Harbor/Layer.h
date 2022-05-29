#pragma once

#include "Harbor/Core.h"
#include "Harbor/Events/Event.h"

namespace Harbor {
	
	class HARBOR_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_DebugName; }

	protected:
		std::string m_DebugName; 
	};

}
