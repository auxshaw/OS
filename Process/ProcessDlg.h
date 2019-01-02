
// ProcessDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
struct pcb
{
	CString name;
	int right;
	int ntime;
	int rtime;
	int ftime;
	CString state;
};

// CProcessDlg 对话框
class CProcessDlg : public CDialogEx
{
// 构造
public:
	CProcessDlg(CWnd* pParent = NULL);	// 标准构造函数
	struct pcb m_pcb[50];
	int m_position;
// 对话框数据
	enum { IDD = IDD_PROCESS_DIALOG };
	
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);

	
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
private:
	CListCtrl m_list;
public:
	CString m_name;
	int m_right;
	int m_ntime;
//	int m_input;
	afx_msg void OnBnClickedRadio1();
	int m_input;
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio4();
};
