#include <Crab.h>

class Warrior : public Crab::Application
{
public:
	Warrior() {

	}
	~Warrior() {

	}
};

Crab::Application* Crab::CreateApplication() {
	return new Warrior();
}
