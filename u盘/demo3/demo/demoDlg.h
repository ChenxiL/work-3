
// demoDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CdemoDlg �Ի���
class CdemoDlg : public CDialogEx
{
// ����ss
public:
	CdemoDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_DEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CEdit m_sUser;
	afx_msg void OnBnClickedButton2Login();
	afx_msg void OnBnClickedButton1Registre();
	CEdit m_spassword;
	CListCtrl m_list;
	afx_msg void OnBnClickedButton3Del();
};
