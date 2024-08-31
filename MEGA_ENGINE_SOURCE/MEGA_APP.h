#pragma once
#include "MEGA_GameObject.h"

namespace MEGA
{
	class APP
	{
	public:
		APP();
		~APP();

	public:
		void Initialize(HWND hWnd, UINT width, UINT height);
		void Run();

		void Update();
		void LateUpdate();
		void Render();

	public:

	private:
		HWND _hWnd;
		HDC _hdc;

		// DC���� ��ȭ���� �����ϴµ�, ��ȭ���� �ڷ����� BITMAP�̴�.
		HDC _backHdc;
		HBITMAP _backBuffer;

		UINT _width;
		UINT _height;

		RECT _rect;

		MEGA::GameObject _player;
	};
}

