// BF3About.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "BF3Converter.h"
#include "BF3About.h"
#include "afxdialogex.h"


// BF3About �Ի���

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


// BF3About ��Ϣ�������


void BF3About::OnBnClickedButton1()
{
	
	ShellExecute(NULL, "open", "https://github.com/BennyThink/BF3Converter", NULL, NULL, SW_SHOWNORMAL);
	
	EndDialog(0);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
