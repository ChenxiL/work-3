
// demoDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CdemoDlg 对话框
class CdemoDlg : public CDialogEx
{
// 构造ss
public:
	CdemoDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_DEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
