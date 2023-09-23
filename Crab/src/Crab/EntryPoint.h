#pragma once

#ifdef PLATFORM_WINDOWS

extern Crab::Application* Crab::CreateApplication();

int main(int argc,char** argv) {
	Crab::Log::Init();
	CRAB_CORE_WARN("Initialised log");
	int a = 6;
	CRAB_INFO("Hello Var={0}", a);
	Crab::Application* app = Crab::CreateApplication();
	app->Run();
	delete app;
}

#endif