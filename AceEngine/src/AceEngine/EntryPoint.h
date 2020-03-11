#pragma once

#ifdef ACE_ENGINE_PLATFORM_WINDOWS

extern AceEngine::Application* AceEngine::CreateApplication();

void main()
{

	printf("xxxxxxxxxxx");
	auto* game = AceEngine::CreateApplication();
	game->Run();
	delete game;
}


#endif