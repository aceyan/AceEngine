#pragma once

#ifdef ACE_ENGINE_PLATFORM_WINDOWS

extern AceEngine::Application* AceEngine::CreateApplication();

void main()
{
	AceEngine::Logger::Init();
	ACE_GAME_ERROR("xxxx");
	ACE_CORE_TRACE("YYYY");

	auto* game = AceEngine::CreateApplication();
	game->Run();
	delete game;
}


#endif