
// demoDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "demo.h"
#include "demoDlg.h"
#include "afxdialogex.h"
#include "cmin.h"

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
	afx_msg void OnBnClickedOk();
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAboutDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CdemoDlg �Ի���



CdemoDlg::CdemoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CdemoDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CdemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT2_USER, m_sUser);
	DDX_Control(pDX, IDC_EDIT1_PASSWORD, m_spassword);
	DDX_Control(pDX, IDC_LIST_ONE, m_list);
}

BEGIN_MESSAGE_MAP(CdemoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2_LOGIN, &CdemoDlg::OnBnClickedButton2Login)
	ON_BN_CLICKED(IDC_BUTTON1_REGISTRE, &CdemoDlg::OnBnClickedButton1Registre)
	ON_BN_CLICKED(IDC_BUTTON3_DEL, &CdemoDlg::OnBnClickedButton3Del)
END_MESSAGE_MAP()


// CdemoDlg ��Ϣ�������

BOOL CdemoDlg::OnInitDialog()
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	m_list.InsertColumn(0,"�û�����",LVCFMT_LEFT,147);
	m_list.InsertColumn(1, "���룺", LVCFMT_LEFT, 147);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CdemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CdemoDlg::OnPaint()
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
HCURSOR CdemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void CdemoDlg::OnBnClickedButton2Login()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString user,password;
	m_sUser.GetWindowText(user);
	m_spassword.GetWindowText(password);
	if (user == "" || password == "")
		MessageBox("wrong username or password!");
	else
		MessageBox("�û�����"+user +"\n"+ "���룺"+password);
	cmin d;
	this->OnOK();//�رյ�ǰҳ��
	d.get(user,password);
	d.DoModal();//��ʾ����ҳ��
}


void CdemoDlg::OnBnClickedButton1Registre()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString num, pass;
	m_sUser.GetWindowText(num);
	m_spassword.GetWindowText(pass);
	if (num.GetLength()<=0||pass.IsEmpty())
	{
		MessageBox("wrong name or password!!");
		return;
	}
	m_list.InsertItem(0, num);
	m_list.SetItemText(0,1, pass);
}


void CAboutDlg::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}


void CdemoDlg::OnBnClickedButton3Del()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	int i = -1;
	i= m_list.GetSelectionMark();
	if (i==-1)
		m_list.DeleteItem(0);
	else
		m_list.DeleteItem(i);
}
