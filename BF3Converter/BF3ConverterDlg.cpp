
// BF3ConverterDlg.cpp : ʵ���ļ�
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


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CBF3ConverterDlg �Ի���




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


// CBF3ConverterDlg ��Ϣ�������

BOOL CBF3ConverterDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CBF3ConverterDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
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
		MessageBox("������Ϸȱ��dinput8.dll����dinput8A.dll�ļ�","����",MB_ICONSTOP);
	
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CBF3ConverterDlg::OnBnClickedButton2()  //doub
{
	if(_access("dinput8A.dll", 0)==0 || _access("dinput8.dll", 0)==0 )
	{
		if(_access("dinput8A.dll", 0) == 0)
			ShellExecute(NULL, "open", "http://bf3.321ol.com/bf3/", NULL, NULL, SW_SHOWNORMAL);
		else{
			rename("dinput8.dll","dinput8A.dll"); //����ok
			ShellExecute(NULL, "open", "http://bf3.321ol.com/bf3/", NULL, NULL, SW_SHOWNORMAL);} 
	}
	else
		MessageBox("������Ϸȱ��dinput8.dll����dinput8A.dll�ļ�","����",MB_ICONSTOP);
	
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
		MessageBox("������Ϸȱ��dinput8.dll����dinput8A.dll�ļ�","����",MB_ICONSTOP);

	display_result.Format("%d", call_result); 
	if(call_result<=32)
		switch(call_result)
	{
		case 0:MessageBox("�ڴ治��","�򿪳������",MB_ICONWARNING);break;
		case 2:MessageBox("��ȷ������������ΪAmgstart.exe","�ļ�������",MB_ICONWARNING);break;
		case 3:MessageBox("�뽫������ŵ���ϷĿ¼��","·��������",MB_ICONWARNING);break;
		case 11:MessageBox("����������AmgStart","exe�ļ���Ч",MB_ICONWARNING);break;
		default:MessageBox("��ȷ��AmgStart��Ч","δ֪����",MB_ICONWARNING);break;
	}
	
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
		MessageBox("������Ϸȱ��dinput8.dll����dinput8A.dll�ļ�","����",MB_ICONSTOP);

	display_result.Format("%d", call_result); 
	if(call_result<=32)
		switch(call_result)
	{
		case 0:MessageBox("�ڴ治��","�򿪳������",MB_ICONWARNING);break;
		case 2:MessageBox("��ȷ������������ΪzloLauncher.exe","�ļ�������",MB_ICONWARNING);break;
		case 3:MessageBox("�뽫������ŵ���ϷĿ¼��","·��������",MB_ICONWARNING);break;
		case 11:MessageBox("����������zloLauncher","exe�ļ���Ч",MB_ICONWARNING);break;
		default:MessageBox("��ȷ��zloLauncher��Ч","δ֪����",MB_ICONWARNING);break;
	}

	
	
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CBF3ConverterDlg::OnBnClickedButton5()     //ping
{
	ShellExecute(NULL, "open", "ping", "zloemu.org", NULL, SW_SHOW);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
		MessageBox("������Ϸȱ��dinput8.dll����dinput8A.dll�ļ�","����",MB_ICONSTOP);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CBF3ConverterDlg::OnBnClickedButton7()   //about
{
	BF3About aboutme;
	aboutme.DoModal();
	
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CAboutDlg::OnBnClickedButton1()
{
	
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
