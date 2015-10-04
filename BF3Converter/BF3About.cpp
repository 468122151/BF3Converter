// BF3About.cpp : 实现文件
//

#include "stdafx.h"
#include "BF3Converter.h"
#include "BF3About.h"
#include "afxdialogex.h"


// BF3About 对话框

IMPLEMENT_DYNAMIC(BF3About, CDialogEx)

BF3About::BF3About(CWnd* pParent /*=NULL*/)
	: CDialogEx(BF3About::IDD, pParent)
{

}

BF3About::~BF3About()
{
}

void BF3About::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(BF3About, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &BF3About::OnBnClickedButton1)
END_MESSAGE_MAP()


// BF3About 消息处理程序


void BF3About::OnBnClickedButton1()
{
	
	ShellExecute(NULL, "open", "https://github.com/BennyThink/BF3Converter", NULL, NULL, SW_SHOWNORMAL);
	
	EndDialog(0);
	// TODO: 在此添加控件通知处理程序代码
}
