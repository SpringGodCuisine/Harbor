#include <Harbor.h>

class Sandbox : public Harbor::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Harbor::Application* Harbor::CreateApplication()
{
	return new Sandbox();
}