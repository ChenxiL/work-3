// cmin.cpp : 实现文件
//

#include "stdafx.h"
#include "demo.h"
#include "cmin.h"
#include "afxdialogex.h"


// cmin 对话框

IMPLEMENT_DYNAMIC(cmin, CDialogEx)

cmin::cmin(CWnd* pParent /*=NULL*/)
	: CDialogEx(cmin::IDD, pParent)
{

}

cmin::~cmin()
{
}

void cmin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(cmin, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &cmin::OnBnClickedButton1)
END_MESSAGE_MAP()


// cmin 消息处理程序
void cmin::get(CString a, CString b)
{
	cc1 = a;
	cc2 = b;
}

void cmin::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	MessageBox(cc1 +"*" +cc2);
}
