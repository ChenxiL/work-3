#pragma once


// cmin �Ի���

class cmin : public CDialogEx
{
	DECLARE_DYNAMIC(cmin)

public:
	cmin(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~cmin();
	void get(CString,CString);
// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	CString cc1,cc2;
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
