
// BF3ConverterDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "BF3Converter.h"
#include "BF3ConverterDlg.h"
#include "afxdialogex.h"
#include "io.h"
#include "BF3About.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CAboutDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CBF3ConverterDlg 对话框




CBF3ConverterDlg::CBF3ConverterDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBF3ConverterDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBF3ConverterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CBF3ConverterDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CBF3ConverterDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CBF3ConverterDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CBF3ConverterDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CBF3ConverterDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CBF3ConverterDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CBF3ConverterDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CBF3ConverterDlg::OnBnClickedButton7)
END_MESSAGE_MAP()


// CBF3ConverterDlg 消息处理程序

BOOL CBF3ConverterDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CBF3ConverterDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CBF3ConverterDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CBF3ConverterDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CBF3ConverterDlg::OnBnClickedButton1()    //zaft
{
	
	if(_access("dinput8A.dll", 0)==0 || _access("dinput8.dll", 0)==0 )
	{
		if(_access("dinput8A.dll", 0) == 0)
			ShellExecute(NULL, "open", "http://bf3.skyts.net/", NULL, NULL, SW_SHOWNORMAL);
		else{
			rename("dinput8.dll","dinput8A.dll"); 
			ShellExecute(NULL, "open", "http://bf3.skyts.net/", NULL, NULL, SW_SHOWNORMAL);} 
	}
	else
		MessageBox("您的游戏缺少dinput8.dll或者dinput8A.dll文件","警告",MB_ICONSTOP);
	
	// TODO: 在此添加控件通知处理程序代码
}


void CBF3ConverterDlg::OnBnClickedButton2()  //doub
{
	if(_access("dinput8A.dll", 0)==0 || _access("dinput8.dll", 0)==0 )
	{
		if(_access("dinput8A.dll", 0) == 0)
			ShellExecute(NULL, "open", "http://bf3.321ol.com/bf3/", NULL, NULL, SW_SHOWNORMAL);
		else{
			rename("dinput8.dll","dinput8A.dll"); //此行ok
			ShellExecute(NULL, "open", "http://bf3.321ol.com/bf3/", NULL, NULL, SW_SHOWNORMAL);} 
	}
	else
		MessageBox("您的游戏缺少dinput8.dll或者dinput8A.dll文件","警告",MB_ICONSTOP);
	
	// TODO: 在此添加控件通知处理程序代码
}


void CBF3ConverterDlg::OnBnClickedButton3()  //amg
{
	
	CString display_result;
	int call_result=33;
	if(_access("dinput8A.dll", 0)==0 || _access("dinput8.dll", 0)==0 )
	{
		if(_access("dinput8.dll", 0) == 0)
			call_result=int(ShellExecute(NULL,"open","AmgStart.exe",NULL,NULL,SW_SHOWNORMAL));
		else{
			rename("dinput8A.dll","dinput8.dll"); 
			int call_result=int(ShellExecute(NULL,"open","AmgStart.exe",NULL,NULL,SW_SHOWNORMAL));} 
	}
	else
		MessageBox("您的游戏缺少dinput8.dll或者dinput8A.dll文件","警告",MB_ICONSTOP);

	display_result.Format("%d", call_result); 
	if(call_result<=32)
		switch(call_result)
	{
		case 0:MessageBox("内存不足","打开程序错误",MB_ICONWARNING);break;
		case 2:MessageBox("请确保启动器名字为Amgstart.exe","文件名错误",MB_ICONWARNING);break;
		case 3:MessageBox("请将本程序放到游戏目录下","路径名错误",MB_ICONWARNING);break;
		case 11:MessageBox("请重新下载AmgStart","exe文件无效",MB_ICONWARNING);break;
		default:MessageBox("请确保AmgStart有效","未知错误",MB_ICONWARNING);break;
	}
	
	// TODO: 在此添加控件通知处理程序代码
}


void CBF3ConverterDlg::OnBnClickedButton4()  //zlo
{
	CString display_result;
	int call_result=33;
	if(_access("dinput8A.dll", 0)==0 || _access("dinput8.dll", 0)==0 )
	{
		if(_access("dinput8.dll", 0) == 0)
			call_result=int(ShellExecute(NULL,"open","zlolauncher.exe",NULL,NULL,SW_SHOWNORMAL));
		else{
			rename("dinput8A.dll","dinput8.dll"); 
			int call_result=int(ShellExecute(NULL,"open","zlolauncher.exe",NULL,NULL,SW_SHOWNORMAL));} 
	}
	else
		MessageBox("您的游戏缺少dinput8.dll或者dinput8A.dll文件","警告",MB_ICONSTOP);

	display_result.Format("%d", call_result); 
	if(call_result<=32)
		switch(call_result)
	{
		case 0:MessageBox("内存不足","打开程序错误",MB_ICONWARNING);break;
		case 2:MessageBox("请确保启动器名字为zloLauncher.exe","文件名错误",MB_ICONWARNING);break;
		case 3:MessageBox("请将本程序放到游戏目录下","路径名错误",MB_ICONWARNING);break;
		case 11:MessageBox("请重新下载zloLauncher","exe文件无效",MB_ICONWARNING);break;
		default:MessageBox("请确保zloLauncher有效","未知错误",MB_ICONWARNING);break;
	}

	
	
	// TODO: 在此添加控件通知处理程序代码
}


void CBF3ConverterDlg::OnBnClickedButton5()     //ping
{
	ShellExecute(NULL, "open", "ping", "zloemu.org", NULL, SW_SHOW);
	// TODO: 在此添加控件通知处理程序代码
}


void CBF3ConverterDlg::OnBnClickedButton6()     //single player
{
	

	if(_access("dinput8A.dll", 0)==0 || _access("dinput8.dll", 0)==0 )
	{
		if(_access("dinput8A.dll", 0) == 0)
			ShellExecute(NULL,"open","lanbf3.exe",NULL,NULL,SW_SHOWNORMAL);
		else{
			rename("dinput8.dll","dinput8A.dll"); 
			ShellExecute(NULL,"open","lanbf3.exe",NULL,NULL,SW_SHOWNORMAL);} 
	}
	else
		MessageBox("您的游戏缺少dinput8.dll或者dinput8A.dll文件","警告",MB_ICONSTOP);
	// TODO: 在此添加控件通知处理程序代码
}


void CBF3ConverterDlg::OnBnClickedButton7()   //about
{
	BF3About aboutme;
	aboutme.DoModal();
	
	// TODO: 在此添加控件通知处理程序代码
}


void CAboutDlg::OnBnClickedButton1()
{
	
	// TODO: 在此添加控件通知处理程序代码
}
