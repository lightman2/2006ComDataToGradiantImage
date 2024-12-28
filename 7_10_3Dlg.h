// 7_10_3Dlg.h : header file
//
//{{AFX_INCLUDES()
#include "mscomm.h"
#include "afxhtml.h"


//}}AFX_INCLUDES

#if !defined(AFX_7_10_3DLG_H__3BDBDBFF_94DD_4DEC_9C64_9990C3C5AD9D__INCLUDED_)
#define AFX_7_10_3DLG_H__3BDBDBFF_94DD_4DEC_9C64_9990C3C5AD9D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMy7_10_3Dlg dialog

class CMy7_10_3Dlg : public CDialog
{
// Construction
public:
	CString	InitTimeStr,EndTimeStr;
	int	Highest[15][10],Usual[15][10];
	void DrawDefaultFrame_Text();
	int	LenDecide;
	void DrawDefaultFrameRE(int m_GetSpan);
	void DrawDefaultFrame(int Combo_Span);
	int CurrentTime;
	int TimerFlag;
	void DrawDetailForRe(int board,int	point,int time,int	span);
	void DrawDetailRe(int	board,int	point,int	containerflag);
	int convertchar(char	a);
	CString ReadSpan;
	CString ReadTime;
	int	ReadYear,ReadMonth,ReadDay,ReadHour,ReadMinite;
	int count;
	CFile	PFile;
	int	ReadSpanValue;



	UINT		m_nTimer;
	int Default_Time;
	void SaveData();
	void DrawDefaultFrame();
	int moveflag;
	CDC *savedc;
	int m_nPort;
	int loc[15];
	int adr[15];
	int comnum;
	int com[15];
	long	int time;
	int	Combo_Board,Combo_Point,Combo_Span;
	COLORREF ColorList[10];
	COLORREF	ColorList2[15];
	void DrawDetail(int board,int	point,int time,int	span);
	int Temp[15][10][1000];
	int	handleddata[15][10];
	int	Temp_2[15][10][601];
	int	InitTimePos,TopTimePos;
	CString	InitTempValue[15][10],TopTempValue[15][10];
	CString	InitTempTime[15][10],TopTempTime[15][10];
	void DrawLine(int x1, int y1, int	x2, int y2,COLORREF	color,CDC *pDC);
	CMy7_10_3Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMy7_10_3Dlg)
	enum { IDD = IDD_MY7_10_3_DIALOG };
	CStatic	m_PicColorList;
	CEdit	m_GetSpan;
	CEdit	m_GetTime;
	CComboBox	m_Span;
	CComboBox	m_Board;
	CComboBox	m_Point;
	CStatic	m_Pic;
	CMSComm	m_Com1;
	CMSComm	m_Com10;
	CMSComm	m_Com11;
	CMSComm	m_Com12;
	CMSComm	m_Com13;
	CMSComm	m_Com14;
	CMSComm	m_Com2;
	CMSComm	m_Com3;
	CMSComm	m_Com4;
	CMSComm	m_Com5;
	CMSComm	m_Com6;
	CMSComm	m_Com7;
	CMSComm	m_Com8;
	CMSComm	m_Com9;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy7_10_3Dlg)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMy7_10_3Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnSelchangeCombo1();
	afx_msg void OnSelchangeCombo2();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnOnCommMscomm1();
	afx_msg void OnOnCommMscomm14();
	afx_msg void OnOnCommMscomm2();
	afx_msg void OnOnCommMscomm3();
	afx_msg void OnOnCommMscomm4();
	afx_msg void OnOnCommMscomm5();
	afx_msg void OnOnCommMscomm6();
	afx_msg void OnOnCommMscomm7();
	afx_msg void OnOnCommMscomm8();
	afx_msg void OnOnCommMscomm9();
	afx_msg void OnOnCommMscomm10();
	afx_msg void OnOnCommMscomm11();
	afx_msg void OnOnCommMscomm12();
	afx_msg void OnOnCommMscomm13();
	afx_msg void OnButton2();
	afx_msg void OnMove(int x, int y);
	afx_msg void OnSelchangeCombo3();
	afx_msg void OnButton4();
	afx_msg void OnChangeEdit2();
	afx_msg void OnButtonFileDialog();
	afx_msg void OnButton5();
	afx_msg void OnButton6();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_7_10_3DLG_H__3BDBDBFF_94DD_4DEC_9C64_9990C3C5AD9D__INCLUDED_)
