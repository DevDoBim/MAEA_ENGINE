#include "MEGA_SceneManager.h"

namespace MEGA
{
	std::map<std::wstring, Scene*> SceneManager::_scene = {};
	Scene* SceneManager::_activeScene = nullptr;

	Scene* SceneManager::LoadScene(const std::wstring& sceneName)
	{
		if (_activeScene)
		{
			_activeScene->OnExit();
		}

		std::map<std::wstring, Scene*>::iterator iter = _scene.find(sceneName);

		assert(iter != _scene.end());
		_activeScene = iter->second;
		_activeScene->OnEnter();

		return iter->second;
	}
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
