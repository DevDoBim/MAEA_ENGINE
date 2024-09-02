#include "MEGA_SceneManager.h"

namespace MEGA
{
	std::map<std::wstring, Scene*> SceneManager::_scene = {};
	Scene* SceneManager::_activeScene = nullptr;

	// ��� Scene �ʱ�ȭ
	void SceneManager::Initialize()
	{
	}
	// ���� ���� ���� Scene ������Ʈ
	void SceneManager::Update()
	{
		_activeScene->Update();
	}
	void SceneManager::LateUpdate()
	{
		_activeScene->LateUpdate();
	}
	void SceneManager::Render(HDC hdc)
	{
		_activeScene->Render(hdc);
	}
}
