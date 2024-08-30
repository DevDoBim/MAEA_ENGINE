#include "MEGA_Time.h"

#define CAST_FLOAT(a) (static_cast<float>(a))

namespace MEGA
{
	LARGE_INTEGER Time::cpuFrequency = {};
	LARGE_INTEGER Time::startFrequency = {};
	LARGE_INTEGER Time::endFrequency = {};

	float Time::deltaTime = 0.0f;

	void Time::Initailize()
	{
		// ���ػ� ���� ī������ �󵵸� ��ȯ, �ý����� ������ Ÿ�̸��� ���ļ�
		QueryPerformanceFrequency(&cpuFrequency);

		// ���α׷� ����, ����� ī��Ʈ ����
		QueryPerformanceCounter(&startFrequency);
	}
	void Time::Update()
	{
		QueryPerformanceCounter(&endFrequency);

		// �ൿ�ϱ��� ī��Ʈ ����, �ൿ ���� ī��Ʈ ���� ���� -> �ൿ�� ī��Ʈ
		// ī��Ʈ / 1�ʴ� ī��Ʈ, 1�ʿ� �� �� �ൿ�ϴ��� ���� �� �ִ�.
		float calculationFrequency = CAST_FLOAT(endFrequency.QuadPart - startFrequency.QuadPart);
		deltaTime = calculationFrequency / CAST_FLOAT(cpuFrequency.QuadPart);

		// �ൿ ī��Ʈ �ʱ�ȭ
		startFrequency.QuadPart = endFrequency.QuadPart;
	}
	void Time::Render(HDC hdc)
	{
		static float time = 0.0f;
		time += deltaTime;
		float fps = 1.0f / deltaTime;

		// �����ڵ� ���ڿ� ���� ����
		// float Ÿ���� ���ڿ��� ��ȯ
		wchar_t str[256] = L"";
		swprintf_s(str, 256, L"fps : %d", static_cast<int>(fps));

		// ���ڿ��� ����, null ���ڸ� ������ �ش� ��ġ�� �������� ��ȯ�Ѵ�.
		int len = wcsnlen_s(str, 256);
		TextOut(hdc, 50, 50, str, len);

		
	}
}