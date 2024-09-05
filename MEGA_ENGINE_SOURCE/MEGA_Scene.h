#pragma once
#include "MEGA_SceneName.h"
#include "MEGA_GameObject.h"
#include "MEGA_Layer.h"

namespace MEGA
{
	class Scene : public SceneName
	{
	public:
		Scene();
		~Scene();

	public:
		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

	public:
		void AddGameObject(GameObject* gameObj, const e_LayerType type);

	public:
		virtual void OnEnter();
		virtual void OnExit();


	private:
		std::vector<Layer*> _layers;
	};
}


