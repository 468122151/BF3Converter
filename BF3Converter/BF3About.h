#pragma once


// BF3About �Ի���

class BF3About : public CDialogEx
{
	DECLARE_DYNAMIC(BF3About)

public:
	BF3About(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~BF3About();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
