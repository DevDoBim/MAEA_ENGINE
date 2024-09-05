#pragma once
#include "MEGA_Scene.h"

namespace MEGA
{
	class SceneManager
	{
	public:
		SceneManager() = default;
		~SceneManager() = default;

	public:
		template<typename T>
		static Scene* CreateScene(const std::wstring& sceneName)
		{
			T* scene = new T();
			scene->SetName(sceneName);
			scene->Initialize();

			_scene.insert(std::make_pair(sceneName, scene));

			return scene;
		}

		static Scene* LoadScene(const std::wstring& sceneName)
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

	public:
		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);

	private:
		// SceneManager�� Ư�� Scene�� �ҷ���, �ش� Scene�� Update�Ѵ�.
		static std::map<std::wstring, Scene*> _scene;
		static Scene* _activeScene;
	};
	
}


