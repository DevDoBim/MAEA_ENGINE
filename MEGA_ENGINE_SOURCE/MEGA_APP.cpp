#include "MEGA_APP.h"
#include "MEGA_Input.h"
#include "MEGA_Time.h"


namespace MEGA
{
	APP::APP() : 
		_hWnd(nullptr), _hdc(nullptr),
		_width(0), _height(0), _rect{},
		_backHdc(NULL), _backBuffer(NULL)
	{
	}

	APP::~APP()
	{
	}

	void APP::Initialize(HWND hWnd, UINT width, UINT height)
	{
		_hWnd = hWnd;
		_hdc = GetDC(hWnd);

		RECT rect = { 0, 0, width, height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);	

		_rect = rect;
		
		//_width = width;
		//_height = height;
		_width = rect.right - rect.left;
		_height = rect.bottom - rect.top;

		// ������ â ������ ���Ӱ� ����������, �ٽ� �����ش�.
		SetWindowPos(_hWnd, nullptr, 0, 0, _width, _height, 0);
		ShowWindow(_hWnd, true);

		// Bitmap ����, �޸� �� ������ Bitmap�� ������ �ʱ�ȭ�� ���� �ʱ� ������ ������(0)�̴�.
		_backBuffer = CreateCompatibleBitmap(_hdc, width, height);

		// backBuffer�� ����Ű�� DC ����
		_backHdc = CreateCompatibleDC(_hdc);

		// DC����, ������ _backHdc�� ���� ����� �����ϰ� _backBuffer�� ����ϰڴ�.
		// ������ _backHdc�� �ִ� bitmap�� ���� bitmap�� ����, _backBuffer bitmap�� ��ȯ
		HBITMAP bitmap = (HBITMAP)SelectObject(_backHdc, _backBuffer); 
		DeleteObject(bitmap);

		Input::Initailize();
		Time::Initailize();

	}

	void APP::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void APP::Update()
	{
		Input::Update();
		Time::Update();

		_player.Update();
	}

	void APP::LateUpdate()
	{
	}

	void APP::Render()
	{
		FillRect(_backHdc, &_rect, (HBRUSH)GetStockObject(WHITE_BRUSH));

		// ������ ���� �׷����°� backHdc�� �׸��ڴ�.
		Time::Render(_backHdc);
		_player.Render(_backHdc);

		// _backHdc�� �ִ� ������ ������ ������.
		BitBlt(_hdc, 0, 0, _width, _height, _backHdc, 0, 0, SRCCOPY);
	}
}