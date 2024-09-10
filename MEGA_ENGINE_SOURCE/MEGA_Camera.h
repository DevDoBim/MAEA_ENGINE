#pragma once
#include "MEGA_Component.h"
#include "MEGA_GameObject.h"

namespace MEGA
{
	class Camera : public Component
	{
	public:
		math::Vector2 CalculatePosition(math::Vector2 position) { return position - _distance; }

	public:
		Camera();
		~Camera();

	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		//std::vector<GameObject*> _gameObjects;

		math::Vector2 _distance; // �Ÿ�
		math::Vector2 _resolution; // �ػ�
		math::Vector2 _lookPosition; // ī�޶� �ٶ󺸴� ��ġ

		GameObject* _target;
		

	};
}


