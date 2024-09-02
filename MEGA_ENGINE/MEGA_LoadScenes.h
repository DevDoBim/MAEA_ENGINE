#pragma once
#include "..\MEGA_ENGINE_SOURCE\MEGA_SceneManager.h"
#include "MEGA_MainScene.h"

namespace MEGA
{
	void LoadScenes()
	{
		// Scene ����
		SceneManager::CreateScene<MainScene>(L"MainScene");
		
		// Scene ȣ��
		SceneManager::LoadScene(L"MainScene");
	}
}
