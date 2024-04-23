#include "FileMgr.h"

#ifdef _PLATFORM_WIN_
#include <Windows.h>
#include <psapi.h>		//GetModuleFileName等函数需要
#include <io.h>			//_access等函数需要
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
	return _access(filePath, 0) == 0;      //调用access函数，参数0表示仅测试文件是否存在
#endif
	return false;
}

bool FileMgr::IsFileExist(const std::string& filePath)
{
	return IsFileExist(filePath.c_str());
}
