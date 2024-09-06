#pragma once
#include "MEGA_Resource.h"

namespace MEGA
{
	class Resources
	{
	public:
		template<typename T>
		static Resource* Find(const std::wstring& key)
		{
			std::map<std::wstring, Resource*>::iterator iter;
			iter = _Resources.find(key);

			// iter�� �θ��� ������ ����, dynamic_cast�� ���� �ٿ� ĳ���� 
			// -> �ڽ��� ������, �� ��� Resource ������ �����Ͱ� �ȴ�.
			assert(iter != _Resources.end());
			return dynamic_cast<T*>(iter->second);
		}

		template<typename T>
		static Resource* Load(const std::wstring& key, const std::wstring& path)
		{
			T* resource = Resources::Find<T>(key);
			if (resource) { return resource; }
			
			resource = new T();
			assert(FAILED(resource->Load(path)) && "Image Load Fail");
			
			if (FAILED(resource->Load(path)))
			{
				MessageBox(nullptr, L"Image Load Fail", L"Error", MB_OK);
				return nullptr;
			}

		}

	private:
		static std::map<std::wstring, Resource*> _Resources;

	};
}


