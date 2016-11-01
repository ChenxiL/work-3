#pragma once


// cmin 对话框

class cmin : public CDialogEx
{
	DECLARE_DYNAMIC(cmin)

public:
	cmin(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~cmin();
	void get(CString,CString);
// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	CString cc1,cc2;
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
