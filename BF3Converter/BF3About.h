#pragma once


// BF3About 对话框

class BF3About : public CDialogEx
{
	DECLARE_DYNAMIC(BF3About)

public:
	BF3About(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~BF3About();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
