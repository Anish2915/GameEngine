#pragma once
#include "Core.h"

namespace Crab {

	class DLL_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};
	Application* CreateApplication();
}
