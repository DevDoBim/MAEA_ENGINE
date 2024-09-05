#include "MEGA_APP.h"
#include "MEGA_Input.h"
#include "MEGA_Time.h"
#include "MEGA_SceneManager.h"


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
		adjustWindowRect(hWnd, width, height);
		createBuffer();
		InitializeEtc();

		SceneManager::Initialize();
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
		SceneManager::Update();
	}

	void APP::LateUpdate()
	{
		SceneManager::LateUpdate();
	}

	void APP::Render()
	{
		resetRender();

		// ������ ���� �׷����°� backHdc�� �׸��ڴ�.
		Time::Render(_backHdc);
		SceneManager::Render(_backHdc);
		copyRender();
		//SceneManager::Render(_backHdc);
	}

	void APP::adjustWindowRect(HWND hWnd, UINT width, UINT height)
	{
		_hWnd = hWnd;
		_hdc = GetDC(hWnd);

		RECT rect = { 0, 0, width, height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		_rect = rect;

		_width = width;
		_height = height;
		//_width = rect.right - rect.left;
		//_height = rect.bottom - rect.top;
	}

	void APP::createBuffer()
	{
		// Bitmap ����, �޸� �� ������ Bitmap�� ������ �ʱ�ȭ�� ���� �ʱ� ������ ������(0)�̴�.
		_backBuffer = CreateCompatibleBitmap(_hdc, _width, _height);

		// backBuffer�� ����Ű�� DC ����
		_backHdc = CreateCompatibleDC(_hdc);

		// DC����, ������ _backHdc�� ���� ����� �����ϰ� _backBuffer�� ����ϰڴ�.
		// ������ _backHdc�� �ִ� bitmap�� ���� bitmap�� ����, _backBuffer bitmap�� ��ȯ
		HBITMAP bitmap = (HBITMAP)SelectObject(_backHdc, _backBuffer);
		DeleteObject(bitmap);
	}

	void APP::InitializeEtc()
	{
		// ������ â ������ ���Ӱ� ����������, �ٽ� �����ش�.
		SetWindowPos(_hWnd, nullptr, 0, 0, _width, _height, 0);
		ShowWindow(_hWnd, true);

		Input::Initailize();
		Time::Initailize();
	}

	void APP::resetRender()
	{
		FillRect(_backHdc, &_rect, (HBRUSH)GetStockObject(WHITE_BRUSH));
	}
	
	void APP::copyRender()
	{
		// _backHdc�� �ִ� ������ ������ ������.
		BitBlt(_hdc, 0, 0, _width, _height, _backHdc, 0, 0, SRCCOPY);
	}
}