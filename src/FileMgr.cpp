#include "FileMgr.h"

#ifdef _PLATFORM_WIN_
#include <Windows.h>
#include <psapi.h>		//GetModuleFileName�Ⱥ�����Ҫ
#include <io.h>			//_access�Ⱥ�����Ҫ
#endif

std::string FileMgr::GetExecutableFilePath()
{
	char buf[MAX_PATH] = {};
#ifdef _PLATFORM_WIN_
	GetModuleFileNameA(NULL, buf, MAX_PATH);
#endif
	return buf;
}

bool FileMgr::IsFileExist(const char* filePath)
{
#ifdef _PLATFORM_WIN_
	return _access(filePath, 0) == 0;      //����access����������0��ʾ�������ļ��Ƿ����
#endif
	return false;
}

bool FileMgr::IsFileExist(const std::string& filePath)
{
	return IsFileExist(filePath.c_str());
}
