
// ProcessDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Process.h"
#include "ProcessDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CProcessDlg 对话框



CProcessDlg::CProcessDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CProcessDlg::IDD, pParent)
	, m_name(_T(""))
	, m_right(0)
	, m_ntime(0)
	, m_input(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CProcessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Text(pDX, IDC_EDIT2, m_name);
	DDV_MaxChars(pDX, m_name, 50);
	DDX_Text(pDX, IDC_EDIT3, m_right);
	DDX_Text(pDX, IDC_EDIT4, m_ntime);
	DDV_MinMaxInt(pDX, m_right, 1, INT_MAX);
	DDV_MinMaxInt(pDX, m_ntime, 1, INT_MAX);
	DDX_Text(pDX, IDC_EDIT5, m_input);
}

BEGIN_MESSAGE_MAP(CProcessDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CProcessDlg::OnLvnItemchangedList1)
	ON_BN_CLICKED(IDC_BUTTON1, &CProcessDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CProcessDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &CProcessDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CProcessDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_RADIO1, &CProcessDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CProcessDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CProcessDlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &CProcessDlg::OnBnClickedRadio4)
END_MESSAGE_MAP()


// CProcessDlg 消息处理程序

BOOL CProcessDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码
	m_list.InsertColumn(0, TEXT("进程名"), LVCFMT_CENTER, 50);
	m_list.InsertColumn(1, TEXT("优先权"), LVCFMT_CENTER, 50);
	m_list.InsertColumn(2, TEXT("服务时间"), LVCFMT_CENTER, 60);
	m_list.InsertColumn(3, TEXT("已运行的时间"), LVCFMT_CENTER, 90);
	m_list.InsertColumn(4, TEXT("状态"), LVCFMT_CENTER, 50);
	m_list.InsertColumn(5, TEXT("完成时间"), LVCFMT_CENTER, 60);
	m_right = 1;
	m_ntime = 1;
	m_input = 1;
	m_position = 0;
	UpdateData(FALSE);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CProcessDlg::OnPaint()
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
HCURSOR CProcessDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CProcessDlg::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO:  在此添加控件通知处理程序代码
	*pResult = 0;
}
int s;
int i = 0;
int j;
int k = 0;
void CProcessDlg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	m_list.DeleteAllItems();
	i = 0;
	k = 0;
	m_position = 0;
	((CButton *)GetDlgItem(IDC_RADIO1))->SetCheck(FALSE);
	((CButton *)GetDlgItem(IDC_RADIO2))->SetCheck(FALSE);
	((CButton *)GetDlgItem(IDC_RADIO3))->SetCheck(FALSE);
	((CButton *)GetDlgItem(IDC_RADIO4))->SetCheck(FALSE);
}

//执行
void CProcessDlg::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码
	CString tmp_str;
	switch (s)
	{
	case  1:
		if (i<m_position)
		{
			
			if (m_pcb[i].rtime<m_pcb[i].ntime)
			{
				k++;
				m_list.SetItemText(i, 4, TEXT("运行中"));
				m_pcb[i].state = 'r';
				m_pcb[i].rtime++;
				tmp_str.Format(_T("%d"), m_pcb[i].rtime);
				m_list.SetItemText(i, 3, tmp_str);
				if (m_pcb[i].rtime == m_pcb[i].ntime)
				{
					m_pcb[i].ftime = k;
					tmp_str.Format(_T("%d"), m_pcb[i].ftime);
					m_list.SetItemText(i, 4, TEXT("完成"));
					m_list.SetItemText(i, 5, tmp_str);
					m_pcb[i].state = 'f'; i++;
				}
			}
		}
		break;

	case 2:
			if (i<m_position)
			{
				if (m_pcb[i].rtime < m_pcb[i].ntime)
				{
					k++;
					m_list.SetItemText(i, 4, TEXT("运行中"));
					m_pcb[i].state = 'r';
					m_pcb[i].rtime++;
					tmp_str.Format(_T("%d"), m_pcb[i].rtime);
					m_list.SetItemText(i, 3, tmp_str);
					if (m_pcb[i].rtime == m_pcb[i].ntime)
					{
						m_pcb[i].ftime = k;
						tmp_str.Format(_T("%d"), m_pcb[i].ftime);
						m_list.SetItemText(i, 4, TEXT("完成"));
						m_list.SetItemText(i, 5, tmp_str);
						m_pcb[i].state = 'f';
						i++;
						return;
					}
				}
			    m_pcb[i].right = m_pcb[i].right + 1;
			    tmp_str.Format(_T("%d"), m_pcb[i].right);
				m_list.SetItemText(i, 1, tmp_str);
				if (i != m_position-1){
					if (m_pcb[i].right > m_pcb[i + 1].right)
					{
						m_pcb[i].state = 'w';
						OnBnClickedRadio1();
						s = 2;
					}
				}
				
			}
			break;

	case 3:
		if (i<m_position)
		{

		Loop:	
			
			if (m_pcb[i].rtime < m_pcb[i].ntime)
			{
				k++;
				m_list.SetItemText(i, 4, TEXT("运行中"));
				m_pcb[i].state = 'r';
				m_pcb[i].rtime++;
				if (i != 0 && m_pcb[i-1].state == 'r'){
					m_list.SetItemText(i - 1, 4, TEXT("等待中"));
					m_pcb[i - 1].state = 'w';
				}
				tmp_str.Format(_T("%d"), m_pcb[i].rtime);
				m_list.SetItemText(i, 3, tmp_str);
				if (m_pcb[i].rtime == m_pcb[i].ntime)
				{
					m_pcb[i].ftime = k;
					tmp_str.Format(_T("%d"), m_pcb[i].ftime);
					m_list.SetItemText(i, 4, TEXT("完成"));
					m_list.SetItemText(i, 5, tmp_str);
					m_pcb[i].state = 'f'; 
				}
				
			}
			i++; 
			
		}
		else
		{
			if (m_pcb[i-1].state == 'r'){
				m_list.SetItemText(i - 1, 4, TEXT("等待中"));
				m_pcb[i - 1].state = 'w';
			}
			i = 0; goto Loop;

		}
		break;
	case 4:
		UpdateData(TRUE);

		if (i < m_position)
		{

		Loop1:
			
			if (m_pcb[i].rtime < m_pcb[i].ntime)
			{
				k = k + m_input;
				m_list.SetItemText(i, 4, TEXT("运行中"));
				m_pcb[i].state = 'r';
				m_pcb[i].rtime = m_pcb[i].rtime + m_input;
				if (m_pcb[i].rtime>m_pcb[i].ntime)
				{
					int k1 = m_pcb[i].rtime - m_pcb[i].ntime;
					m_pcb[i].rtime = m_pcb[i].ntime;
					k = k - k1;
				}
				if (i != 0 && m_pcb[i - 1].state == 'r'){
					m_list.SetItemText(i - 1, 4, TEXT("等待中"));
					m_pcb[i - 1].state = 'w';
				}
				tmp_str.Format(_T("%d"), m_pcb[i].rtime);
				m_list.SetItemText(i, 3, tmp_str);
				if (m_pcb[i].rtime == m_pcb[i].ntime)
				{
					m_pcb[i].ftime = k;
					tmp_str.Format(_T("%d"), m_pcb[i].ftime);
					m_list.SetItemText(i, 4, TEXT("完成"));
					m_list.SetItemText(i, 5, tmp_str);
					m_pcb[i].state = 'f';
				}
			}
			
			i++;
		}
		else
		{
			if (m_pcb[i - 1].state == 'r'){
				m_list.SetItemText(i - 1, 4, TEXT("等待中"));
				m_pcb[i - 1].state = 'w';
			}
			i = 0; goto Loop1;

		}
		UpdateData(FALSE);
		break;
	default:
		break;
	}

}


void CProcessDlg::OnBnClickedButton4()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
}

//加入
void CProcessDlg::OnBnClickedButton5()
{
	// TODO:  在此添加控件通知处理程序代码
	if (!UpdateData(TRUE))return;
	CString tmp_str;


	m_pcb[m_position].name = m_name;
	m_pcb[m_position].right = m_right;
	m_pcb[m_position].ntime = m_ntime;
	m_pcb[m_position].rtime = 0;
	m_pcb[m_position].state = 'w';

	m_list.InsertItem(m_position, m_name);
	tmp_str.Format(_T("%d"), m_right);
	m_list.SetItemText(m_position, 1, tmp_str);
	tmp_str.Format(_T("%d"), m_ntime);
	m_list.SetItemText(m_position, 2, tmp_str);

	m_position++;
	m_pcb[m_position].name = "";
	UpdateData(FALSE);
}


//静态优先级
void CProcessDlg::OnBnClickedRadio1()
{
	int i, j;
	UpdateData(TRUE);
	// TODO:  在此添加控件通知处理程序代码
	struct pcb tmp_rec;
	for (i = 0; i<m_position - 1; i++)
	{
		for (j = i + 1; j<m_position; j++)
		if (m_pcb[i].right>m_pcb[j].right)
		{
			tmp_rec = m_pcb[j];
			m_pcb[j] = m_pcb[i];
			m_pcb[i] = tmp_rec;
		}
	}
	m_list.DeleteAllItems();
	for (i = 0; i<m_position; i++)
	{
		CString tmp_str, a;
		m_list.InsertItem(i, m_pcb[i].name);
		tmp_str.Format(_T("%d"), m_pcb[i].right);
		m_list.SetItemText(i, 1, tmp_str);
		tmp_str.Format(_T("%d"), m_pcb[i].ntime);
		m_list.SetItemText(i, 2, tmp_str);

		tmp_str.Format(_T("%d"), m_pcb[i].rtime);
		m_list.SetItemText(i, 3, tmp_str);
		if (m_pcb[i].state == 'f')
		{
			a = "完成";
			tmp_str.Format(_T("%d"), m_pcb[i].ftime);
			m_list.SetItemText(i, 5, tmp_str);
		}
		else if (m_pcb[i].state == 'w')a = "等待中";
		else if (m_pcb[i].state == 'r')a = "运行中";
		m_list.SetItemText(i, 4, a);

	}

	s = 1;
}

//动态优先级
void CProcessDlg::OnBnClickedRadio2()
{
	// TODO:  在此添加控件通知处理程序代码
	OnBnClickedRadio1();
	s = 2;
}

//简单轮转法
void CProcessDlg::OnBnClickedRadio3()
{
	// TODO:  在此添加控件通知处理程序代码
	int i;
	CString tmp_str;
	tmp_str = "等待中";
	for (i = 0; i <= m_position; i++)
	{
		m_list.SetItemText(i, 1, NULL);
		m_list.SetItemText(i, 4, tmp_str);
	}
	s = 3;
}

//可变时间片
void CProcessDlg::OnBnClickedRadio4()
{
	// TODO:  在此添加控件通知处理程序代码
	int i;
	CString tmp_str;
	tmp_str = "等待中";
	for (i = 0; i <= m_position; i++)
	{
		m_list.SetItemText(i, 1, NULL);
		m_list.SetItemText(i, 4, tmp_str);
	}
	s = 4;
	
}
