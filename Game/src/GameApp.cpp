#include <AceEngine.h>

class GameApp : public AceEngine::Application
{
public:
	GameApp()
	{
	}
	~GameApp()
	{

	}

};

AceEngine::Application* AceEngine::CreateApplication()
{
	return new GameApp();
}