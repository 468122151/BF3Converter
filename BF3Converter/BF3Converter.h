
// BF3Converter.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CBF3ConverterApp:
// �йش����ʵ�֣������ BF3Converter.cpp
//

class CBF3ConverterApp : public CWinApp
{
public:
	CBF3ConverterApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CBF3ConverterApp theApp;