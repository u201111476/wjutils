#ifndef _WJ_FILE_MGR_H_
#define _WJ_FILE_MGR_H_

#pragma once

#ifdef WJ_EXPORT
#define WJAPI __declspec(dllexport)
#else
#define WJAPI __declspec(dllimport)
#endif

#include <string>

class WJAPI FileMgr
{
public:
	/// @brief ��ȡ��ִ���ļ���·��
	/// @return ��ִ���ļ�·���ַ���
	static std::string GetExecutableFilePath();
	/// @brief �ж��ļ��Ƿ����
	/// @param filePath �ļ�·��
	/// @return ����ļ����ڷ���true
	static bool IsFileExist(const char* filePath);
	/// @brief �ж��ļ��Ƿ����
	/// @param filePath �ļ�·��
	/// @return ����ļ����ڷ���true
	static bool IsFileExist(const std::string& filePath);
};

#endif
