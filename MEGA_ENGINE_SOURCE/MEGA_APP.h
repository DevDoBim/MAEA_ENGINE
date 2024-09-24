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
		HWND GetHWND() const { return _hWnd; }
		HDC GetHDC() const { return _hdc; }
		UINT GetWidth() const { return _width; }
		UINT GetHeight() const { return _height; }

	//Initialize
	private:
		void adjustWindowRect(HWND hWnd, UINT width, UINT height);
		void createBuffer();
		void InitializeEtc();

	//Render
	private:
		void resetRender();
		void copyRender();


	private:
		HWND _hWnd;
		HDC _hdc;

		// DC���� ��ȭ���� �����ϴµ�, ��ȭ���� �ڷ����� BITMAP�̴�.
		HDC _backHdc;
		HBITMAP _backBuffer;

		UINT _width;
		UINT _height;

		RECT _rect;

		std::vector<GameObject*> _gameObjects;
	};
}

