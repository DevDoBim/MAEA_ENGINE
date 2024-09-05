#pragma once
#include "MEGA_Component.h"

namespace MEGA
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

	public:
		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

	template<typename T>
	T* AddComponent()
	{
		T* component = new T();
		component->Initialize();
		component->SetOwner(this);
		_components.push_back(component);

		return component;
	}

	template<typename T>
	T* GetComponent()
	{
		T* returnComponent = nullptr;

		for (Component* component : _components)
		{
			// �⺻ Ŭ������ �����͸� �Ļ� Ŭ������ �����ͷ� ��ȯ
			// ��ü�� ������ ��ȯ�Ϸ��� �Ļ� Ŭ������ �ν��Ͻ����� �Ǻ�, ��ȿ���� ������ nullptr ��ȯ
			returnComponent = dynamic_cast<T*>(component);
			if (returnComponent)
			{
				break;
			}
		}
		return returnComponent;
	}

	private:
		void InitializTransform();

	private:
		std::vector<Component*> _components;
	};
}

