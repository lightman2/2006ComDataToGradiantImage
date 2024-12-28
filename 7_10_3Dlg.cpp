// 7_10_3Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "7_10_3.h"
#include "7_10_3Dlg.h"
#include	"math.h"
#include	"stdlib.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define	XREF	830
#define	YREF	400
#define File_Read_Number 7000 
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy7_10_3Dlg dialog

CMy7_10_3Dlg::CMy7_10_3Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMy7_10_3Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMy7_10_3Dlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy7_10_3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMy7_10_3Dlg)
	DDX_Control(pDX, IDC_STATIC_2, m_PicColorList);
	DDX_Control(pDX, IDC_EDIT3, m_GetSpan);
	DDX_Control(pDX, IDC_EDIT2, m_GetTime);
	DDX_Control(pDX, IDC_COMBO3, m_Span);
	DDX_Control(pDX, IDC_COMBO1, m_Board);
	DDX_Control(pDX, IDC_COMBO2, m_Point);
	DDX_Control(pDX, IDC_STATIC_1, m_Pic);
	DDX_Control(pDX, IDC_MSCOMM1, m_Com1);
	DDX_Control(pDX, IDC_MSCOMM10, m_Com10);
	DDX_Control(pDX, IDC_MSCOMM11, m_Com11);
	DDX_Control(pDX, IDC_MSCOMM12, m_Com12);
	DDX_Control(pDX, IDC_MSCOMM13, m_Com13);
	DDX_Control(pDX, IDC_MSCOMM14, m_Com14);
	DDX_Control(pDX, IDC_MSCOMM2, m_Com2);
	DDX_Control(pDX, IDC_MSCOMM3, m_Com3);
	DDX_Control(pDX, IDC_MSCOMM4, m_Com4);
	DDX_Control(pDX, IDC_MSCOMM5, m_Com5);
	DDX_Control(pDX, IDC_MSCOMM6, m_Com6);
	DDX_Control(pDX, IDC_MSCOMM7, m_Com7);
	DDX_Control(pDX, IDC_MSCOMM8, m_Com8);
	DDX_Control(pDX, IDC_MSCOMM9, m_Com9);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMy7_10_3Dlg, CDialog)
	//{{AFX_MSG_MAP(CMy7_10_3Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO2, OnSelchangeCombo2)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_WM_MOVE()
	ON_CBN_SELCHANGE(IDC_COMBO3, OnSelchangeCombo3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_EN_CHANGE(IDC_EDIT2, OnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON_FILE_DIALOG, OnButtonFileDialog)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy7_10_3Dlg message handlers

BOOL CMy7_10_3Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	for(int i=0;i<15;i++)
		for(int j=0;j<10;j++)
			for(int	k=0;k<1000;k++)
			{
				Temp[i][j][k]=18;//1;k;rand()%100;
			}
	for(i=0;i<15;i++)
		for(int	j=0;j<10;j++)
		{
			handleddata[i][j]=18;//rand()%100; 
		}

	ColorList[0]=RGB(255,255,255);
	ColorList[1]=RGB(29,5,141);
	ColorList[2]=RGB(0,122,249);
	ColorList[3]=RGB(0,211,121);
	ColorList[4]=RGB(108,255,37);
	ColorList[5]=RGB(255,227,14);
	ColorList[6]=RGB(255,168,44);
	ColorList[7]=RGB(241,92,196);
	ColorList[8]=RGB(228,0,117);
	ColorList[9]=RGB(148,0,1);


	ColorList2[0]=RGB(154,150,65);
	ColorList2[1]=RGB(214,3,30);
	ColorList2[2]=RGB(215,2,140);
	ColorList2[3]=RGB(200,1,216);
	ColorList2[4]=RGB(104,2,217);
	ColorList2[5]=RGB(2,13,217);
	ColorList2[6]=RGB(2,120,217);
	ColorList2[7]=RGB(3,216,194);
	ColorList2[8]=RGB(4,215,83);
	ColorList2[9]=RGB(62,216,3);
	ColorList2[10]=RGB(142,218,1);
	ColorList2[11]=RGB(216,216,3);
	ColorList2[12]=RGB(218,148,1);
	ColorList2[13]=RGB(216,56,3);
	ColorList2[14]=RGB(154,150,65);

	
	CTime	InitTime=CTime::GetCurrentTime();
	int	j;
	char	a[100];
	j=sprintf(a,"%d-",InitTime.GetYear());
	j+=sprintf(a+j,"%d-",InitTime.GetMonth());
	j+=sprintf(a+j,"%d%t",InitTime.GetDay());
	j+=sprintf(a+j,"%d:",InitTime.GetHour());
	j+=sprintf(a+j,"%d",InitTime.GetMinute());

	InitTimeStr=a;//____________________________________________________________________________________datacreation
//	InitTimeStr+=InitTime.Format("%H:%M:%S");
	
	time=0; 
	Combo_Board=15;
	Combo_Point=5;
	Combo_Span=10;

	CTime	time;
	time=CTime::GetCurrentTime();
	Default_Time=time.GetHour()*10000+time.GetMinute()*100+time.GetSecond();

	PFile.Open("data.txt",CFile::modeCreate|CFile::modeNoTruncate|CFile::modeReadWrite);
	TimerFlag=0;

	m_Board.SetCurSel (14);
	m_Point.SetCurSel(4);
	m_Span.SetCurSel(0);
//	((CButton *)this->GetDlgItem(IDC_COMBO1))->EnableWindow(FALSE);
//	((CButton *)this->GetDlgItem(IDC_COMBO2))->EnableWindow(FALSE);
	((CButton *)this->GetDlgItem(IDC_COMBO3))->EnableWindow(FALSE);
	((CButton *)this->GetDlgItem(IDC_BUTTON1))->EnableWindow(FALSE);
	((CButton *)this->GetDlgItem(IDC_BUTTON6))->EnableWindow(FALSE);
//	((CButton *)this->GetDlgItem(IDC_EDIT2))->EnableWindow(FALSE);
//	((CButton *)this->GetDlgItem(IDC_EDIT3))->EnableWindow(FALSE);
//	((CButton *)this->GetDlgItem(IDC_BUTTON4))->EnableWindow(FALSE);


	CDC	*dc=this->GetDC();
	dc->TextOut(0,0,"abc");
	dc->DeleteDC();

	return TRUE;  // return TRUE  unless you set the focus to a control

}

void CMy7_10_3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMy7_10_3Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting
		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
	if(TimerFlag==1)
	{
	DrawDefaultFrame(Combo_Span);

	if(Combo_Board!=15&&Combo_Point!=10)
		for(int	k=1;k<time+1;k++)
			DrawDetail(Combo_Board,Combo_Point,k,Combo_Span);
	else	if(Combo_Board!=15&&Combo_Point==10)
	{
		for(int	k=1;k<time+1;k++)
			for(int	i=1;i<10;i++)
			{
				DrawDetail(Combo_Board,i,k,Combo_Span);
			}
	}
	else	if(Combo_Board==15&&Combo_Point!=10)
	{
				for(int	k=1;k<time+1;k++)
					for(int	i=1;i<15;i++)
					{
						DrawDetail(i,Combo_Point,k,Combo_Span);
					}
	}
	else	if(Combo_Board==15&&Combo_Point==10)
	{
				for(int	k=1;k<time+1;k++)
					for(int	i=1;i<15;i++)
						for(int	j=1;j<10;j++)
						{
							DrawDetail(i,j,k,Combo_Span);
						}
	}
	}





		CDialog::OnPaint();

	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMy7_10_3Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

//DEL void CMy7_10_3Dlg::OnEditchangeCombo1() 
//DEL {
//DEL 	// TODO: Add your control notification handler code here
//DEL 	
//DEL }

//DEL void CMy7_10_3Dlg::OnEditchangeCombo2() 
//DEL {
//DEL 	// TODO: Add your control notification handler code here
//DEL 	
//DEL }

void	CMy7_10_3Dlg::DrawLine(int x1, int y1, int	x2, int y2,COLORREF	color,CDC *pDC)
{
	CPen	*oldPen,*pCPen;
	pCPen=new	CPen(0,2,color);
	 //pCPen->CreatePen(0,2,color);
	oldPen=pDC->SelectObject(pCPen);
	pDC->MoveTo(x1,y1);
	pDC->LineTo(x2,y2);
	pDC->SelectObject(oldPen);
	pCPen->DeleteObject();
	delete	pCPen;
	
}

void CMy7_10_3Dlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	CurrentTime=0;
	DrawDefaultFrame(Combo_Span);
	CTime	ctime;
	ctime=CTime::GetCurrentTime();
	Default_Time=ctime.GetHour()*10000+ctime.GetMinute()*100+ctime.GetSecond();
	count=0;
	time=0;
	m_nTimer=SetTimer(1,1000,0); 
	TimerFlag=1;


	//if(PFile.)


}

//DEL void CMy7_10_3Dlg::OnStatic1() 
//DEL {
//DEL 	// TODO: Add your control notification handler code here
//DEL 	
//DEL }

void CMy7_10_3Dlg::OnSelchangeCombo1() 
{
	// TODO: Add your control notification handler code here
	//AfxMessageBox("gdsf");
	//GetLBText( int nIndex, CString& rString );
//	CString strSelected;
//	int index=m_Board.GetCurSel();
//	if(index!=CB_ERR)
//	{
//		int	abc=m_Board.GetCurSel();
//		this->m_Board.GetLBText(index,strSelected);
	this->Combo_Board=m_Board.GetCurSel()+1;
	if(m_Board.GetCurSel()!=14)
	{
		m_Point.SetCurSel(9);
		Combo_Point=m_Point.GetCurSel()+1;
	}
	if(m_Board.GetCurSel()==14)
	{	
		m_Point.SetCurSel(4);
		Combo_Point=m_Point.GetCurSel()+1;
	}

//	}

//	m_Point.seh
}

void CMy7_10_3Dlg::OnSelchangeCombo2() 
{
	// TODO: Add your control notification handler code here
	//CString strSelected;
	//int index=m_Point.GetCurSel();
	//if(index!=CB_ERR)
	//{
		//this->m_Board.GetLBText(index,strSelected);
	int	abc=this->Combo_Point=m_Point.GetCurSel()+1;

	//}
}
void CMy7_10_3Dlg::OnSelchangeCombo3() 
{
	// TODO: Add your control notification handler code here
	CString strSelected;
	int	index=m_Span.GetCurSel();
	if(index!=CB_ERR)
	{
	this->m_Span.GetLBText(index,strSelected);
	this->Combo_Span=atoi(strSelected);
	}
}


void CMy7_10_3Dlg::DrawDetail(int board,int	point,int time,int	span)
{
 	float	span_2=(float)span;
	int timepix1,temppix1,timepix2,temppix2;
	timepix1=(int)((time-1)*60/span_2);
	temppix1=Temp[board][point][time-1]*4;
	
	timepix2=(int)(time*60/span_2);
	temppix2=Temp[board][point][time]*4;
	CDC	*dc;
	dc=m_Pic.GetDC();
	if(Combo_Board!=15&&time!=0)
		DrawLine(timepix1+30,YREF-temppix1,timepix2+30,YREF-temppix2,ColorList[point],dc);
	else	if(time!=0)
		DrawLine(timepix1+30,YREF-temppix1,timepix2+30,YREF-temppix2,ColorList2[board],dc);
	dc->DeleteDC();
}

void CMy7_10_3Dlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	int	i=1;
	time++;
	count++;
	CurrentTime++;
	if(count%60==0)
	{
		count=0;
		SaveData();
	}

	

	for(int	j=0;j<15;j++)
		for(int	k=0;k<10;k++)
		{
			Temp[j][k][time]=handleddata[j][k];//_____________________________________调试 最后 恢复
		}
	if(Combo_Board!=15&&Combo_Point!=10)
		DrawDetail(Combo_Board,Combo_Point,time,Combo_Span);
	else	if(Combo_Board!=15&&Combo_Point==10)
	{
		for(i=1;i<10;i++)
		{
			DrawDetail(Combo_Board,i,time,Combo_Span);
		}
	}
	else	if(Combo_Board==15&&Combo_Point!=10)
	{
		for(i=1;i<15;i++)
		{
			DrawDetail(i,Combo_Point,time,Combo_Span);
		}
	}
	else	if(Combo_Board==15&&Combo_Point==10)
	{
		for(i=1;i<15;i++)
			for(int	j=1;j<10;j++)
			{
				DrawDetail(i,j,time,Combo_Span);
			}
	}

	if(time==Combo_Span*10)
	{
		time=-1;
		DrawDefaultFrame(Combo_Span);
	}


	CDialog::OnTimer(nIDEvent);
}

BEGIN_EVENTSINK_MAP(CMy7_10_3Dlg, CDialog)
    //{{AFX_EVENTSINK_MAP(CMy7_10_3Dlg)
	ON_EVENT(CMy7_10_3Dlg, IDC_MSCOMM1, 1 /* OnComm */, OnOnCommMscomm1, VTS_NONE)
	ON_EVENT(CMy7_10_3Dlg, IDC_MSCOMM14, 1 /* OnComm */, OnOnCommMscomm14, VTS_NONE)
	ON_EVENT(CMy7_10_3Dlg, IDC_MSCOMM2, 1 /* OnComm */, OnOnCommMscomm2, VTS_NONE)
	ON_EVENT(CMy7_10_3Dlg, IDC_MSCOMM3, 1 /* OnComm */, OnOnCommMscomm3, VTS_NONE)
	ON_EVENT(CMy7_10_3Dlg, IDC_MSCOMM4, 1 /* OnComm */, OnOnCommMscomm4, VTS_NONE)
	ON_EVENT(CMy7_10_3Dlg, IDC_MSCOMM5, 1 /* OnComm */, OnOnCommMscomm5, VTS_NONE)
	ON_EVENT(CMy7_10_3Dlg, IDC_MSCOMM6, 1 /* OnComm */, OnOnCommMscomm6, VTS_NONE)
	ON_EVENT(CMy7_10_3Dlg, IDC_MSCOMM7, 1 /* OnComm */, OnOnCommMscomm7, VTS_NONE)
	ON_EVENT(CMy7_10_3Dlg, IDC_MSCOMM8, 1 /* OnComm */, OnOnCommMscomm8, VTS_NONE)
	ON_EVENT(CMy7_10_3Dlg, IDC_MSCOMM9, 1 /* OnComm */, OnOnCommMscomm9, VTS_NONE)
	ON_EVENT(CMy7_10_3Dlg, IDC_MSCOMM10, 1 /* OnComm */, OnOnCommMscomm10, VTS_NONE)
	ON_EVENT(CMy7_10_3Dlg, IDC_MSCOMM11, 1 /* OnComm */, OnOnCommMscomm11, VTS_NONE)
	ON_EVENT(CMy7_10_3Dlg, IDC_MSCOMM12, 1 /* OnComm */, OnOnCommMscomm12, VTS_NONE)
	ON_EVENT(CMy7_10_3Dlg, IDC_MSCOMM13, 1 /* OnComm */, OnOnCommMscomm13, VTS_NONE)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CMy7_10_3Dlg::OnOnCommMscomm1() 
{
	// TODO: Add your control notification handler code here
	VARIANT			variant_inp;
	COleSafeArray	safearray_inp;
	LONG			len,k;
	BYTE			rxdata[2048];
	char			actdata[2048];
	CString			strtemp,inter;//;
	int				n0,n1,n2;
	int				l,m,n;	
		
		if(m_Com1.GetCommEvent()==2)
		{
			variant_inp=m_Com1.GetInput();
			safearray_inp=variant_inp;
			len=safearray_inp.GetOneDimSize();
			for(k=0;k<len;k++)
			{
				safearray_inp.GetElement(&k,rxdata+k);
				BYTE bt=*(char*)(rxdata+k); //字符型 
				strtemp.Format("%c",bt); //将字符送入临时变量strtemp存放 
				inter+=strtemp; //______________________________变量
			}
			int n4=0,num;
			n2=0;
			n0=0;
			while(n0!=-1)
			{
				n1=n2;
				n0=n2=inter.Find('#',++n1);
				if(n0==-1)
					break;
				strtemp=inter.Mid(n1,n2-n1);//_______________________________________变量复
				num=strtemp.GetLength();
				if(num!=10)continue;
				lstrcpy(actdata,strtemp);

				l=convertchar(actdata[0])*10+convertchar(actdata[1]);
				m=convertchar(actdata[3]);
				n=convertchar(actdata[5]);
				if((47<actdata[6])&(actdata[6]<58))
				{
					n=convertchar(actdata[6])+n*10;
				}
				
				if((0<=l)&(l<=255)&(0<=m)&(m<=9)&(0<=n)&(n<=300))
				{
					int	o=handleddata[loc[1]][m];
					handleddata[loc[1]][m]=n;
				}
				
			}//_________________________________________________________________0的启示地址00110000;
		}
			this->UpdateData(false);	
}

void CMy7_10_3Dlg::OnOnCommMscomm14() 
{
	// TODO: Add your control notification handler code here
		VARIANT			variant_inp;
	COleSafeArray	safearray_inp;
	LONG			len,k;
	BYTE			rxdata[2048];
	char			actdata[2048];
	CString			strtemp,inter;//;
	int				n0,n1,n2;
	int				l,m,n;	
		
		if(m_Com14.GetCommEvent()==2)
		{
			
			variant_inp=m_Com14.GetInput();
			safearray_inp=variant_inp;
			len=safearray_inp.GetOneDimSize();
			for(k=0;k<len;k++)
			{
				safearray_inp.GetElement(&k,rxdata+k);
				BYTE bt=*(char*)(rxdata+k); //字符型 
				strtemp.Format("%c",bt); //将字符送入临时变量strtemp存放 
				inter+=strtemp; //______________________________变量
			}
			int n4=0,num;
			n2=0;
			n0=0;
			while(n0!=-1)
			{
				n1=n2;
				n0=n2=inter.Find('#',++n1);
				if(n0==-1)
					break;
				strtemp=inter.Mid(n1,n2-n1);//_______________________________________变量复
				num=strtemp.GetLength();
				if(num!=10)continue;
				lstrcpy(actdata,strtemp);

				l=convertchar(actdata[0])*10+convertchar(actdata[1]);
				m=convertchar(actdata[3]);
				n=convertchar(actdata[5]);
				if((47<actdata[6])&(actdata[6]<58))
				{
					n=convertchar(actdata[6])+n*10;
				}
				if((0<=l)&(l<=255)&(0<=m)&(m<=9)&(0<=n)&(n<=300))
				{
					int	o=handleddata[loc[14]][m];
					handleddata[loc[14]][m]=n;
				//	if(abs(o-n)>=1)
				//	Draw_Block(loc[14]);
				}
				
			}//_________________________________________________________________0的启示地址00110000;
		//	m_Edit=inter;
			this->UpdateData(false);
		}
				
}

void CMy7_10_3Dlg::OnOnCommMscomm2() 
{
	// TODO: Add your control notification handler code here
			VARIANT			variant_inp;
	COleSafeArray	safearray_inp;
	LONG			len,k;
	BYTE			rxdata[2048];
	char			actdata[2048];
	CString			strtemp,inter;//;
	int				n0,n1,n2;
	int				l,m,n;	
		
		if(m_Com2.GetCommEvent()==2)
		{
			
			variant_inp=m_Com2.GetInput();
			safearray_inp=variant_inp;
			len=safearray_inp.GetOneDimSize();
			for(k=0;k<len;k++)
			{
				safearray_inp.GetElement(&k,rxdata+k);
				BYTE bt=*(char*)(rxdata+k); //字符型 
				strtemp.Format("%c",bt); //将字符送入临时变量strtemp存放 
				inter+=strtemp; //______________________________变量
			}
			int n4=0,num;
			n2=0;
			n0=0;
			while(n0!=-1)
			{
				n1=n2;
				n0=n2=inter.Find('#',++n1);
				if(n0==-1)
					break;
				strtemp=inter.Mid(n1,n2-n1);//_______________________________________变量复
				num=strtemp.GetLength();
				if(num!=10)continue;
				lstrcpy(actdata,strtemp);

				l=convertchar(actdata[0])*10+convertchar(actdata[1]);
				m=convertchar(actdata[3]);
				n=convertchar(actdata[5]);
				if((47<actdata[6])&(actdata[6]<58))
				{
					n=convertchar(actdata[6])+n*10;
				}
				if((0<=l)&(l<=255)&(0<=m)&(m<=9)&(0<=n)&(n<=300))
				{
					int	o=handleddata[loc[2]][m];
					handleddata[loc[2]][m]=n;
				//	if(abs(o-n)>=1)
				//	Draw_Block(loc[2]);
				}
				
			}//_________________________________________________________________0的启示地址00110000;
		//	m_Edit=inter;
			this->UpdateData(false);
		}
}

void CMy7_10_3Dlg::OnOnCommMscomm3() 
{
	// TODO: Add your control notification handler code here
		VARIANT			variant_inp;
	COleSafeArray	safearray_inp;
	LONG			len,k;
	BYTE			rxdata[2048];
	char			actdata[2048];
	CString			strtemp,inter;//;
	int				n0,n1,n2;
	int				l,m,n;	
		
		if(m_Com1.GetCommEvent()==2)
		{
			
			variant_inp=m_Com1.GetInput();
			safearray_inp=variant_inp;
			len=safearray_inp.GetOneDimSize();
			for(k=0;k<len;k++)
			{
				safearray_inp.GetElement(&k,rxdata+k);
				BYTE bt=*(char*)(rxdata+k); //字符型 
				strtemp.Format("%c",bt); //将字符送入临时变量strtemp存放 
				inter+=strtemp; //______________________________变量
			}
			int n4=0,num;
			n2=0;
			n0=0;
			while(n0!=-1)
			{
				n1=n2;
				n0=n2=inter.Find('#',++n1);
				if(n0==-1)
					break;
				strtemp=inter.Mid(n1,n2-n1);//_______________________________________变量复
				num=strtemp.GetLength();
				if(num!=10)continue;
				lstrcpy(actdata,strtemp);

				/*n2 = inter.Find (',',n1);
				str1 = inter.Mid (n1,n2-n1);
				str2 = ;
				str3 = ;*/

				l=convertchar(actdata[0])*10+convertchar(actdata[1]);
				m=convertchar(actdata[3]);
				n=convertchar(actdata[5]);
				if((47<actdata[6])&(actdata[6]<58))
				{
					n=convertchar(actdata[6])+n*10;
				}
				if((0<=l)&(l<=255)&(0<=m)&(m<=9)&(0<=n)&(n<=300))
				{
					int	o=handleddata[loc[3]][m];
					handleddata[loc[3]][m]=n;
				//	if(abs(o-n)>=1)
				//	Draw_Block(loc[3]);
				}
				
			}//_________________________________________________________________0的启示地址00110000;
		//	m_Edit=inter;
			//CRect rc;

			//Draw1.GetClientRect(&rc);
			this->UpdateData(false);
		}
}

void CMy7_10_3Dlg::OnOnCommMscomm4() 
{
	// TODO: Add your control notification handler code here
			VARIANT			variant_inp;
	COleSafeArray	safearray_inp;
	LONG			len,k;
	BYTE			rxdata[2048];
	char			actdata[2048];
	CString			strtemp,inter;//;
	int				n0,n1,n2;
	int				l,m,n;	
		
		if(m_Com4.GetCommEvent()==2)
		{
			
			variant_inp=m_Com4.GetInput();
			safearray_inp=variant_inp;
			len=safearray_inp.GetOneDimSize();
			for(k=0;k<len;k++)
			{
				safearray_inp.GetElement(&k,rxdata+k);
				BYTE bt=*(char*)(rxdata+k); //字符型 
				strtemp.Format("%c",bt); //将字符送入临时变量strtemp存放 
				inter+=strtemp; //______________________________变量
			}
			int n4=0,num;
			n2=0;
			n0=0;
			while(n0!=-1)
			{
				n1=n2;
				n0=n2=inter.Find('#',++n1);
				if(n0==-1)
					break;
				strtemp=inter.Mid(n1,n2-n1);//_______________________________________变量复
				num=strtemp.GetLength();
				if(num!=10)continue;
				lstrcpy(actdata,strtemp);

				l=convertchar(actdata[0])*10+convertchar(actdata[1]);
				m=convertchar(actdata[3]);
				n=convertchar(actdata[5]);
				if((47<actdata[6])&(actdata[6]<58))
				{
					n=convertchar(actdata[6])+n*10;
				}
				if((0<=l)&(l<=255)&(0<=m)&(m<=9)&(0<=n)&(n<=300))
				{
					int	o=handleddata[loc[4]][m];
					handleddata[loc[4]][m]=n;
			//		if(abs(o-n)>=1)
			//		Draw_Block(loc[4]);
				}
				
			}//_________________________________________________________________0的启示地址00110000;
			//m_Edit=inter;
			this->UpdateData(false);
		}	
}

void CMy7_10_3Dlg::OnOnCommMscomm5() 
{
	// TODO: Add your control notification handler code here
		VARIANT			variant_inp;
	COleSafeArray	safearray_inp;
	LONG			len,k;
	BYTE			rxdata[2048];
	char			actdata[2048];
	CString			strtemp,inter;//;
	int				n0,n1,n2;
	int				l,m,n;	
		
		if(m_Com5.GetCommEvent()==2)
		{
			
			variant_inp=m_Com5.GetInput();
			safearray_inp=variant_inp;
			len=safearray_inp.GetOneDimSize();
			for(k=0;k<len;k++)
			{
				safearray_inp.GetElement(&k,rxdata+k);
				BYTE bt=*(char*)(rxdata+k); //字符型 
				strtemp.Format("%c",bt); //将字符送入临时变量strtemp存放 
				inter+=strtemp; //______________________________变量
			}
			int n4=0,num;
			n2=0;
			n0=0;
			while(n0!=-1)
			{
				n1=n2;
				n0=n2=inter.Find('#',++n1);
				if(n0==-1)
					break;
				strtemp=inter.Mid(n1,n2-n1);//_______________________________________变量复
				num=strtemp.GetLength();
				if(num!=10)continue;
				lstrcpy(actdata,strtemp);

				l=convertchar(actdata[0])*10+convertchar(actdata[1]);
				m=convertchar(actdata[3]);
				n=convertchar(actdata[5]);
				if((47<actdata[6])&(actdata[6]<58))
				{
					n=convertchar(actdata[6])+n*10;
				}
				if((0<=l)&(l<=255)&(0<=m)&(m<=9)&(0<=n)&(n<=300))
				{
					int	o=handleddata[loc[105]][m];
					handleddata[loc[5]][m]=n;
				}
				
			}//_________________________________________________________________0的启示地址00110000;
			this->UpdateData(false);
		}
}

void CMy7_10_3Dlg::OnOnCommMscomm6() 
{
	// TODO: Add your control notification handler code here
		VARIANT			variant_inp;
	COleSafeArray	safearray_inp;
	LONG			len,k;
	BYTE			rxdata[2048];
	char			actdata[2048];
	CString			strtemp,inter;//;
	int				n0,n1,n2;
	int				l,m,n;	
		
		if(m_Com6.GetCommEvent()==2)
		{
			
			variant_inp=m_Com6.GetInput();
			safearray_inp=variant_inp;
			len=safearray_inp.GetOneDimSize();
			for(k=0;k<len;k++)
			{
				safearray_inp.GetElement(&k,rxdata+k);
				BYTE bt=*(char*)(rxdata+k); //字符型 
				strtemp.Format("%c",bt); //将字符送入临时变量strtemp存放 
				inter+=strtemp; //______________________________变量
			}
			int n4=0,num;
			n2=0;
			n0=0;
			while(n0!=-1)
			{
				n1=n2;
				n0=n2=inter.Find('#',++n1);
				if(n0==-1)
					break;
				strtemp=inter.Mid(n1,n2-n1);//_______________________________________变量复
				num=strtemp.GetLength();
				if(num!=10)continue;
				lstrcpy(actdata,strtemp);

				l=convertchar(actdata[0])*10+convertchar(actdata[1]);
				m=convertchar(actdata[3]);
				n=convertchar(actdata[5]);
				if((47<actdata[6])&(actdata[6]<58))
				{
					n=convertchar(actdata[6])+n*10;
				}
				if((0<=l)&(l<=255)&(0<=m)&(m<=9)&(0<=n)&(n<=300))
				{
					int	o=handleddata[loc[6]][m];
					handleddata[loc[6]][m]=n;
				}
				
			}//_________________________________________________________________0的启示地址00110000;
			this->UpdateData(false);
		}
				
}

void CMy7_10_3Dlg::OnOnCommMscomm7() 
{
	// TODO: Add your control notification handler code here
		VARIANT			variant_inp;
	COleSafeArray	safearray_inp;
	LONG			len,k;
	BYTE			rxdata[2048];
	char			actdata[2048];
	CString			strtemp,inter;//;
	int				n0,n1,n2;
	int				l,m,n;	
		
		if(m_Com7.GetCommEvent()==2)
		{
			
			variant_inp=m_Com7.GetInput();
			safearray_inp=variant_inp;
			len=safearray_inp.GetOneDimSize();
			for(k=0;k<len;k++)
			{
				safearray_inp.GetElement(&k,rxdata+k);
				BYTE bt=*(char*)(rxdata+k); //字符型 
				strtemp.Format("%c",bt); //将字符送入临时变量strtemp存放 
				inter+=strtemp; //______________________________变量
			}
			int n4=0,num;
			n2=0;
			n0=0;
			while(n0!=-1)
			{
				n1=n2;
				n0=n2=inter.Find('#',++n1);
				if(n0==-1)
					break;
				strtemp=inter.Mid(n1,n2-n1);//_______________________________________变量复
				num=strtemp.GetLength();
				if(num!=10)continue;
				lstrcpy(actdata,strtemp);

				l=convertchar(actdata[0])*10+convertchar(actdata[1]);
				m=convertchar(actdata[3]);
				n=convertchar(actdata[5]);
				if((47<actdata[6])&(actdata[6]<58))
				{
					n=convertchar(actdata[6])+n*10;
				}
				if((0<=l)&(l<=255)&(0<=m)&(m<=9)&(0<=n)&(n<=300))
				{
					int	o=handleddata[loc[7]][m];
					handleddata[loc[7]][m]=n;
				}
				
			}//_________________________________________________________________0的启示地址00110000;
			this->UpdateData(false);
		}
				
}

void CMy7_10_3Dlg::OnOnCommMscomm8() 
{
	// TODO: Add your control notification handler code here
		VARIANT			variant_inp;
	COleSafeArray	safearray_inp;
	LONG			len,k;
	BYTE			rxdata[2048];
	char			actdata[2048];
	CString			strtemp,inter;//;
	int				n0,n1,n2;
	int				l,m,n;	
		
		if(m_Com8.GetCommEvent()==2)
		{
			
			variant_inp=m_Com8.GetInput();
			safearray_inp=variant_inp;
			len=safearray_inp.GetOneDimSize();
			for(k=0;k<len;k++)
			{
				safearray_inp.GetElement(&k,rxdata+k);
				BYTE bt=*(char*)(rxdata+k); //字符型 
				strtemp.Format("%c",bt); //将字符送入临时变量strtemp存放 
				inter+=strtemp; //______________________________变量
			}
			int n4=0,num;
			n2=0;
			n0=0;
			while(n0!=-1)
			{
				n1=n2;
				n0=n2=inter.Find('#',++n1);
				if(n0==-1)
					break;
				strtemp=inter.Mid(n1,n2-n1);//_______________________________________变量复
				num=strtemp.GetLength();
				if(num!=10)continue;
				lstrcpy(actdata,strtemp);

				l=convertchar(actdata[0])*10+convertchar(actdata[1]);
				m=convertchar(actdata[3]);
				n=convertchar(actdata[5]);
				if((47<actdata[6])&(actdata[6]<58))
				{
					n=convertchar(actdata[6])+n*10;
				}
				if((0<=l)&(l<=255)&(0<=m)&(m<=9)&(0<=n)&(n<=300))
				{
					int	o=handleddata[loc[8]][m];
					handleddata[loc[8]][m]=n;
				}
				
			}//_________________________________________________________________0的启示地址00110000;
			this->UpdateData(false);
		}	
}

void CMy7_10_3Dlg::OnOnCommMscomm9() 
{
	// TODO: Add your control notification handler code here
		VARIANT			variant_inp;
	COleSafeArray	safearray_inp;
	LONG			len,k;
	BYTE			rxdata[2048];
	char			actdata[2048];
	CString			strtemp,inter;//;
	int				n0,n1,n2;
	int				l,m,n;	
		
		if(m_Com9.GetCommEvent()==2)
		{
			
			variant_inp=m_Com9.GetInput();
			safearray_inp=variant_inp;
			len=safearray_inp.GetOneDimSize();
			for(k=0;k<len;k++)
			{
				safearray_inp.GetElement(&k,rxdata+k);
				BYTE bt=*(char*)(rxdata+k); //字符型 
				strtemp.Format("%c",bt); //将字符送入临时变量strtemp存放 
				inter+=strtemp; //______________________________变量
			}
			int n4=0,num;
			n2=0;
			n0=0;
			while(n0!=-1)
			{
				n1=n2;
				n0=n2=inter.Find('#',++n1);
				if(n0==-1)
					break;
				strtemp=inter.Mid(n1,n2-n1);//_______________________________________变量复
				num=strtemp.GetLength();
				if(num!=10)continue;
				lstrcpy(actdata,strtemp);

				l=convertchar(actdata[0])*10+convertchar(actdata[1]);
				m=convertchar(actdata[3]);
				n=convertchar(actdata[5]);
				if((47<actdata[6])&(actdata[6]<58))
				{
					n=convertchar(actdata[6])+n*10;
				}
				if((0<=l)&(l<=255)&(0<=m)&(m<=9)&(0<=n)&(n<=300))
				{
					int	o=handleddata[loc[9]][m];
					handleddata[loc[9]][m]=n;
				}
				
			}//_________________________________________________________________0的启示地址00110000;
			this->UpdateData(false);
		}
				
}

void CMy7_10_3Dlg::OnOnCommMscomm10() 
{
	// TODO: Add your control notification handler code here
		VARIANT			variant_inp;
	COleSafeArray	safearray_inp;
	LONG			len,k;
	BYTE			rxdata[2048];
	char			actdata[2048];
	CString			strtemp,inter;//;
	int				n0,n1,n2;
	int				l,m,n;	
		
		if(m_Com10.GetCommEvent()==2)
		{
			
			variant_inp=m_Com10.GetInput();
			safearray_inp=variant_inp;
			len=safearray_inp.GetOneDimSize();
			for(k=0;k<len;k++)
			{
				safearray_inp.GetElement(&k,rxdata+k);
				BYTE bt=*(char*)(rxdata+k); //字符型 
				strtemp.Format("%c",bt); //将字符送入临时变量strtemp存放 
				inter+=strtemp; //______________________________变量
			}
			int n4=0,num;
			n2=0;
			n0=0;
			while(n0!=-1)
			{
				n1=n2;
				n0=n2=inter.Find('#',++n1);
				if(n0==-1)
					break;
				strtemp=inter.Mid(n1,n2-n1);//_______________________________________变量复
				num=strtemp.GetLength();
				if(num!=10)continue;
				lstrcpy(actdata,strtemp);

				l=convertchar(actdata[0])*10+convertchar(actdata[1]);
				m=convertchar(actdata[3]);
				n=convertchar(actdata[5]);
				if((47<actdata[6])&(actdata[6]<58))
				{
					n=convertchar(actdata[6])+n*10;
				}
				if((0<=l)&(l<=255)&(0<=m)&(m<=9)&(0<=n)&(n<=300))
				{
					int	o=handleddata[loc[10]][m];
					handleddata[loc[10]][m]=n;
				}
				
			}//_________________________________________________________________0的启示地址00110000;
			this->UpdateData(false);
		}
			
}

void CMy7_10_3Dlg::OnOnCommMscomm11() 
{
	// TODO: Add your control notification handler code here
		VARIANT			variant_inp;
	COleSafeArray	safearray_inp;
	LONG			len,k;
	BYTE			rxdata[2048];
	char			actdata[2048];
	CString			strtemp,inter;//;
	int				n0,n1,n2;
	int				l,m,n;	
		
		if(m_Com11.GetCommEvent()==2)
		{
			
			variant_inp=m_Com11.GetInput();
			safearray_inp=variant_inp;
			len=safearray_inp.GetOneDimSize();
			for(k=0;k<len;k++)
			{
				safearray_inp.GetElement(&k,rxdata+k);
				BYTE bt=*(char*)(rxdata+k); //字符型 
				strtemp.Format("%c",bt); //将字符送入临时变量strtemp存放 
				inter+=strtemp; //______________________________变量
			}
			int n4=0,num;
			n2=0;
			n0=0;
			while(n0!=-1)
			{
				n1=n2;
				n0=n2=inter.Find('#',++n1);
				if(n0==-1)
					break;
				strtemp=inter.Mid(n1,n2-n1);//_______________________________________变量复
				num=strtemp.GetLength();
				if(num!=10)continue;
				lstrcpy(actdata,strtemp);

				l=convertchar(actdata[0])*10+convertchar(actdata[1]);
				m=convertchar(actdata[3]);
				n=convertchar(actdata[5]);
				if((47<actdata[6])&(actdata[6]<58))
				{
					n=convertchar(actdata[6])+n*10;
				}
				if((0<=l)&(l<=255)&(0<=m)&(m<=9)&(0<=n)&(n<=300))
				{
					int	o=handleddata[loc[11]][m];
					handleddata[loc[11]][m]=n;
				}
				
			}//_________________________________________________________________0的启示地址00110000;
			this->UpdateData(false);
		}	
}

void CMy7_10_3Dlg::OnOnCommMscomm12() 
{
	// TODO: Add your control notification handler code here
		VARIANT			variant_inp;
	COleSafeArray	safearray_inp;
	LONG			len,k;
	BYTE			rxdata[2048];
	char			actdata[2048];
	CString			strtemp,inter;//;
	int				n0,n1,n2;
	int				l,m,n;	
		
		if(m_Com12.GetCommEvent()==2)
		{
			
			variant_inp=m_Com12.GetInput();
			safearray_inp=variant_inp;
			len=safearray_inp.GetOneDimSize();
			for(k=0;k<len;k++)
			{
				safearray_inp.GetElement(&k,rxdata+k);
				BYTE bt=*(char*)(rxdata+k); //字符型 
				strtemp.Format("%c",bt); //将字符送入临时变量strtemp存放 
				inter+=strtemp; //______________________________变量
			}
			int n4=0,num;
			n2=0;
			n0=0;
			while(n0!=-1)
			{
				n1=n2;
				n0=n2=inter.Find('#',++n1);
				if(n0==-1)
					break;
				strtemp=inter.Mid(n1,n2-n1);//_______________________________________变量复
				num=strtemp.GetLength();
				if(num!=10)continue;
				lstrcpy(actdata,strtemp);

				l=convertchar(actdata[0])*10+convertchar(actdata[1]);
				m=convertchar(actdata[3]);
				n=convertchar(actdata[5]);
				if((47<actdata[6])&(actdata[6]<58))
				{
					n=convertchar(actdata[6])+n*10;
				}
				if((0<=l)&(l<=255)&(0<=m)&(m<=9)&(0<=n)&(n<=300))
				{
					int	o=handleddata[loc[12]][m];
					handleddata[loc[12]][m]=n;
				}
				
			}//_________________________________________________________________0的启示地址00110000;
			this->UpdateData(false);
		}	
}

void CMy7_10_3Dlg::OnOnCommMscomm13() 
{
	// TODO: Add your control notification handler code here
		VARIANT			variant_inp;
	COleSafeArray	safearray_inp;
	LONG			len,k;
	BYTE			rxdata[2048];
	char			actdata[2048];
	CString			strtemp,inter;//;
	int				n0,n1,n2;
	int				l,m,n;	
		
		if(m_Com13.GetCommEvent()==2)
		{
			
			variant_inp=m_Com13.GetInput();
			safearray_inp=variant_inp;
			len=safearray_inp.GetOneDimSize();
			for(k=0;k<len;k++)
			{
				safearray_inp.GetElement(&k,rxdata+k);
				BYTE bt=*(char*)(rxdata+k); //字符型 
				strtemp.Format("%c",bt); //将字符送入临时变量strtemp存放 
				inter+=strtemp; //______________________________变量
			}
			int n4=0,num;
			n2=0;
			n0=0;
			while(n0!=-1)
			{
				n1=n2;
				n0=n2=inter.Find('#',++n1);
				if(n0==-1)
					break;
				strtemp=inter.Mid(n1,n2-n1);//_______________________________________变量复
				num=strtemp.GetLength();
				if(num!=10)continue;
				lstrcpy(actdata,strtemp);

				l=convertchar(actdata[0])*10+convertchar(actdata[1]);
				m=convertchar(actdata[3]);
				n=convertchar(actdata[5]);
				if((47<actdata[6])&(actdata[6]<58))
				{
					n=convertchar(actdata[6])+n*10;
				}
				if((0<=l)&(l<=255)&(0<=m)&(m<=9)&(0<=n)&(n<=300))
				{
					int	o=handleddata[loc[13]][m];
					handleddata[loc[13]][m]=n;
				}
				
			}//_________________________________________________________________0的启示地址00110000;
			this->UpdateData(false);
		}	
}

void CMy7_10_3Dlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	CFile	file;
	CString comname="infolist.txt";
	if(!file.Open (comname,CFile::modeReadWrite))
	{AfxMessageBox("library error,please set infolist");}
	else
	{
		char	 buf[500];
		int		 num=file.Read(buf,500);
		int		 begin=1,end=1,flag=1,templen=0;
		int		j=0,interi=0;
		int		count=0;
		comnum=0;
		for(int i=0;i<num;i++)
		{
			if(buf[i]=='m')
			{
				comnum++;
				j++;
				count=0;
				interi=i+1;
				com[j]=convertchar(buf[interi]);
				if(buf[++interi]!=',')
					com[j]=convertchar(buf[interi])+com[j]*10;//______com	DEC
				
			}
			if(buf[i]==',')
			{
				count++;
				if(count==1)//________________________address		OCT
				{
				interi=i+3;
				int mid=convertchar(buf[interi]);
				adr[j]=convertchar(buf[interi])*16+convertchar(buf[interi+1]);
				}
				if(count==2)//_________________________location    DEC
				{
				interi=i+1;
				loc[j]=convertchar(buf[interi])*10+convertchar(buf[interi+1]);
				}
			}
	


		}
}
		((CButton *)this->GetDlgItem(IDC_COMBO1))->EnableWindow(TRUE);
			((CButton *)this->GetDlgItem(IDC_COMBO2))->EnableWindow(TRUE);
			((CButton *)this->GetDlgItem(IDC_COMBO3))->EnableWindow(TRUE);
			((CButton *)this->GetDlgItem(IDC_BUTTON1))->EnableWindow(TRUE);
	int i=1;
	if(i<=comnum)
	{	
		if(m_Com1.GetPortOpen())
			m_Com1.SetPortOpen(FALSE);

		m_Com1.SetCommPort(m_nPort=com[i]);//________________________________________________________端口设置
		if(!m_Com1.GetPortOpen())
			m_Com1.SetPortOpen(TRUE);
		else
			AfxMessageBox("cannot open serial port");//______________________________________first close the port thentest if open 

		m_Com1.SetSettings("19200,n,8,1");
		m_Com1.SetRThreshold(32);
		m_Com1.SetInputMode(1);
		m_Com1.SetInputLen(0);
		m_Com1.GetInput();
		i++;
	}
	if(i<=comnum)
	{	
		if(m_Com2.GetPortOpen())
			m_Com2.SetPortOpen(FALSE);

			m_Com2.SetCommPort(m_nPort=com[i]);//________________________________________________________端口设置
			if(!m_Com2.GetPortOpen())
			m_Com2.SetPortOpen(TRUE);
		else
			AfxMessageBox("cannot open serial port");//______________________________________first close the port thentest if open 

			m_Com2.SetSettings("19200,n,8,1");
			m_Com2.SetRThreshold(32);
			m_Com2.SetInputMode(1);
			m_Com2.SetInputLen(0);
			m_Com2.GetInput();
			i++;
	}

	if(i<=comnum)
	{	
		if(m_Com3.GetPortOpen())
			m_Com3.SetPortOpen(FALSE);

			m_Com3.SetCommPort(m_nPort=com[i]);//________________________________________________________端口设置
			if(!m_Com3.GetPortOpen())
			m_Com3.SetPortOpen(TRUE);
		else
			AfxMessageBox("cannot open serial port");//______________________________________first close the port thentest if open 

			m_Com3.SetSettings("19200,n,8,1");
			m_Com3.SetRThreshold(32);
			m_Com3.SetInputMode(1);
			m_Com3.SetInputLen(0);
			m_Com3.GetInput();
			i++;
		}

	if(i<=comnum)
	{	
		if(m_Com4.GetPortOpen())
			m_Com4.SetPortOpen(FALSE);

			m_Com4.SetCommPort(m_nPort=com[i]);//________________________________________________________端口设置
			if(!m_Com4.GetPortOpen())
			m_Com4.SetPortOpen(TRUE);
		else
			AfxMessageBox("cannot open serial port");//______________________________________first close the port thentest if open 

			m_Com4.SetSettings("19200,n,8,1");
			m_Com4.SetRThreshold(32);
			m_Com4.SetInputMode(1);
			m_Com4.SetInputLen(0);
			m_Com4.GetInput();
			i++;
	}

	if(i<=comnum)
	{	
		if(m_Com5.GetPortOpen())
			m_Com5.SetPortOpen(FALSE);

			m_Com5.SetCommPort(m_nPort=com[i]);//________________________________________________________端口设置
			if(!m_Com5.GetPortOpen())
			m_Com5.SetPortOpen(TRUE);
		else
			AfxMessageBox("cannot open serial port");//______________________________________first close the port thentest if open 

			m_Com5.SetSettings("19200,n,8,1");
			m_Com5.SetRThreshold(32);
			m_Com5.SetInputMode(1);
			m_Com5.SetInputLen(0);
			m_Com5.GetInput();
			i++;
	}

	if(i<=comnum)
	{	
		if(m_Com6.GetPortOpen())
			m_Com6.SetPortOpen(FALSE);

			m_Com6.SetCommPort(m_nPort=com[i]);//________________________________________________________端口设置
			if(!m_Com6.GetPortOpen())
			m_Com6.SetPortOpen(TRUE);
		else
			AfxMessageBox("cannot open serial port");//______________________________________first close the port thentest if open 

			m_Com6.SetSettings("19200,n,8,1");
			m_Com6.SetRThreshold(32);
			m_Com6.SetInputMode(1);
			m_Com6.SetInputLen(0);
			m_Com6.GetInput();
			i++;
	}

	if(i<=comnum)
	{	
		if(m_Com7.GetPortOpen())
			m_Com7.SetPortOpen(FALSE);

			m_Com7.SetCommPort(m_nPort=com[i]);//________________________________________________________端口设置
			if(!m_Com7.GetPortOpen())
			m_Com7.SetPortOpen(TRUE);
		else
			AfxMessageBox("cannot open serial port");//______________________________________first close the port thentest if open 

			m_Com7.SetSettings("19200,n,8,1");
			m_Com7.SetRThreshold(32);
			m_Com7.SetInputMode(1);
			m_Com7.SetInputLen(0);
			m_Com7.GetInput();
			i++;
	}

	if(i<=comnum)
	{	
		if(m_Com8.GetPortOpen())
			m_Com8.SetPortOpen(FALSE);

			m_Com8.SetCommPort(m_nPort=com[i]);//________________________________________________________端口设置
			if(!m_Com8.GetPortOpen())
			m_Com8.SetPortOpen(TRUE);
		else
			AfxMessageBox("cannot open serial port");//______________________________________first close the port thentest if open 

			m_Com8.SetSettings("19200,n,8,1");
			m_Com8.SetRThreshold(32);
			m_Com8.SetInputMode(1);
			m_Com8.SetInputLen(0);
			m_Com8.GetInput();
			i++;
	}

	if(i<=comnum)
	{	
		if(m_Com9.GetPortOpen())
			m_Com9.SetPortOpen(FALSE);

			m_Com9.SetCommPort(m_nPort=com[i]);//________________________________________________________端口设置
			if(!m_Com9.GetPortOpen())
			m_Com9.SetPortOpen(TRUE);
		else
			AfxMessageBox("cannot open serial port");//______________________________________first close the port thentest if open 

			m_Com9.SetSettings("19200,n,8,1");
			m_Com9.SetRThreshold(32);
			m_Com9.SetInputMode(1);
			m_Com9.SetInputLen(0);
			m_Com9.GetInput();
			i++;
	}

	if(i<=comnum)
	{	
		if(m_Com10.GetPortOpen())
			m_Com10.SetPortOpen(FALSE);

			m_Com10.SetCommPort(m_nPort=com[i]);//________________________________________________________端口设置
			if(!m_Com10.GetPortOpen())
			m_Com10.SetPortOpen(TRUE);
		else
			AfxMessageBox("cannot open serial port");//______________________________________first close the port thentest if open 

			m_Com10.SetSettings("19200,n,8,1");
			m_Com10.SetRThreshold(32);
			m_Com10.SetInputMode(1);
	 		m_Com10.SetInputLen(0);
			m_Com10.GetInput();
			i++;
	}

	if(i<=comnum)
	{	
		if(m_Com11.GetPortOpen())
			m_Com11.SetPortOpen(FALSE);

			m_Com11.SetCommPort(m_nPort=com[i]);//________________________________________________________端口设置
			if(!m_Com11.GetPortOpen())
			m_Com11.SetPortOpen(TRUE);
		else
			AfxMessageBox("cannot open serial port");//______________________________________first close the port thentest if open 

			m_Com11.SetSettings("19200,n,8,1");
			m_Com11.SetRThreshold(32);
			m_Com11.SetInputMode(1);
			m_Com11.SetInputLen(0);
			m_Com11.GetInput();
			i++;
	}

	if(i<=comnum)
	{	
		if(m_Com12.GetPortOpen())
			m_Com12.SetPortOpen(FALSE);

			m_Com12.SetCommPort(m_nPort=com[i]);//________________________________________________________端口设置
			if(!m_Com12.GetPortOpen())
			m_Com12.SetPortOpen(TRUE);
		else
			AfxMessageBox("cannot open serial port");//______________________________________first close the port thentest if open 

			m_Com12.SetSettings("19200,n,8,1");
			m_Com12.SetRThreshold(32);
			m_Com12.SetInputMode(1);
			m_Com12.SetInputLen(0);
			m_Com12.GetInput();
			i++;
	}

	if(i<=comnum)
	{	
		if(m_Com13.GetPortOpen())
			m_Com13.SetPortOpen(FALSE);

			m_Com13.SetCommPort(m_nPort=com[i]);//________________________________________________________端口设置
			if(!m_Com13.GetPortOpen())
			m_Com13.SetPortOpen(TRUE);
		else
			AfxMessageBox("cannot open serial port");//______________________________________first close the port thentest if open 

			m_Com13.SetSettings("19200,n,8,1");
			m_Com13.SetRThreshold(32);
			m_Com13.SetInputMode(1);
			m_Com13.SetInputLen(0);
			m_Com13.GetInput();
			i++;
	}

	if(i<=comnum)
	{	
		if(m_Com14.GetPortOpen())
			m_Com14.SetPortOpen(FALSE);

			m_Com14.SetCommPort(m_nPort=com[i]);//________________________________________________________端口设置
			if(!m_Com14.GetPortOpen())
			m_Com14.SetPortOpen(TRUE);
		else
			AfxMessageBox("cannot open serial port");//______________________________________first close the port thentest if open 

			m_Com14.SetSettings("19200,n,8,1");
			m_Com14.SetRThreshold(32);
			m_Com14.SetInputMode(1);
			m_Com14.SetInputLen(0);
			m_Com14.GetInput();
			i++;
	}

}



void CMy7_10_3Dlg::OnMove(int x, int y) 
{
	CDialog::OnMove(x, y);
}

void CMy7_10_3Dlg::DrawDefaultFrame()
{
	CDC *pDC;
	CString str;
	pDC=m_Pic.GetDC();
	for(int	i=0;i<800;i++)
		for(int	j=0;j<400;j++)
		{
			pDC->SetPixel(i+30,j,RGB(255,255,255));
		}
	DrawLine(30,YREF,XREF,YREF,RGB(0,0,0),pDC);
	DrawLine(30,YREF,30,0,RGB(0,0,0),pDC);
	for( i=0;i<11;i++)
	{
		str.Format(_T("%d"),i);
		pDC->TextOut(i*60+30,YREF,str);
		if(i!=0)
			DrawLine(i*60+30,YREF,i*60+30,0,RGB(200,200,200),pDC);
	}
	for( i=1;i<13;i++)
	{
		str.Format(_T("%d"),i*10);
		pDC->TextOut(0,YREF-i*40,str);
		if(i!=0)
			DrawLine(30,YREF-i*40,630,YREF-i*40,RGB(200,200,200),pDC);

	}//________________________________________________________________________画出基本结构图
	CDC *LDC;
	LDC=m_PicColorList.GetDC();
	if(Combo_Board!=15)
	{

		str="";
		char	a[2];
		
		for(int j=0;j<50;j++)
			LDC->SetPixel(i,j,RGB(212,208,200));
		for(i=0;i<9;i++)
			for(int	j=0;j<50;j++)
				for(int	k=0;k<50;k++)
				{
					sprintf(a,"%d",i+1);
					str=a;
					LDC->SetPixel(i*100+j,k,ColorList[i+1]);
					LDC->TextOut(i*100+50,25,str);
					if(i==8)
						LDC->TextOut(i*100+100,25,"点");
				}
	//	delete	a;
	}
	if(Combo_Board==15)
	{
	
		str="";
		for(i=0;i<900;i++)
			for(int j=0;j<50;j++)
				LDC->SetPixel(i,j,RGB(212,208,200));
		char	a[2];
		for(i=0;i<14;i++)
			for(int	j=0;j<50;j++)
				for(int	k=0;k<50;k++)
				{
					sprintf(a,"%d",i+1);
					str=a;
					LDC->SetPixel(i*64+j,k,ColorList2[i+1]);
					LDC->TextOut(i*64+50,25,str);
					if(i==8)
						LDC->TextOut(i*100+100,25,"板");
				}
	//	delete a;
	}
	LDC->DeleteDC();
	pDC->DeleteDC();


//________________________________________________________________________DrawColorList
}

void CMy7_10_3Dlg::SaveData()
{
//	CFile	PFile;
//	if(!PFile.Open("data.txt",CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite))
//	{
//		AfxMessageBox("Can't op`en file.");
//	}
//	else
//	{
		char	tempchar[2000];
		CString	char_total;
		char_total=tempchar;
		char_total.Empty();
		CTime	machinetime;
		CString	machinetimestr;
		machinetime=CTime::GetCurrentTime();
		machinetimestr+=(machinetime.Format("*20%y-%m-%d\t&%H:%M:%S\n"));
		PFile.SeekToEnd();
		CArchive	PFile_archive(&PFile,CArchive::store,50);
		int	length=machinetimestr.GetLength();
		PFile_archive.WriteString(machinetimestr);
		for(int	i=1;i<15;i++)
			for(int	j=1;j<10;j++)
			{
				int	l=sprintf(tempchar,"\t%c",'#');
				if(i<10)//______________________________________________________________________________changed
				{
					l+=sprintf(tempchar+l," %d",0);
					l+=sprintf(tempchar+l,"%d",i);
				}
				else	l+=sprintf(tempchar+l," %d",i);
				l+=sprintf(tempchar+l,"-%d",j);
				if(time>59)
					for(int	k=time-59;k<time+1;k+=5)
					{
						l+=sprintf(tempchar+l," %d",Temp[i][j][k]);
					}
				else
				{
					int count=1;
					for(int	k=0;k<60-time;k+=5)
					{l+=sprintf(tempchar+l," %d",Temp[i][j][Combo_Span*10-60+k]);
						count++;
					}
					for(k=0;k<time;k+=5)
					{if(count<13)
						l+=sprintf(tempchar+l," %d",Temp[i][j][time]);
					count++;
					}
					if(count<12)
						l+=sprintf(tempchar+l," %d",Temp[i][j][time]);
				}
				sprintf(tempchar+l,"\n");
			PFile_archive.WriteString(tempchar);
					
//			}
	//	char	*data_charrespect;
	//	CString	data_chartotal;
	//	gcvt(data_2[1],5,data_charrespect);
	//	data_chartotal+=data_charrespect;
		

	//	PFile_archive.WriteString(data_2);

	}

}
	

void CMy7_10_3Dlg::OnButton4() 
{
	// TODO: Add your control notification handler code here
	((CButton *)this->GetDlgItem(IDC_BUTTON6))->EnableWindow(TRUE);

	if(TimerFlag==1) 
		this->KillTimer(m_nTimer);
	TimerFlag=0;
	LenDecide=0;
	int	LenDecideSmall=1,LenDecideLarge=0,LenJumper=0;
	int	LenJumperStore=0;
	PFile.SeekToBegin();
	for(int	i=0;i<15;i++)
		for(int	j=0;j<10;j++)
			for(int	k=0;k<601;k++)
				Temp_2[i][j][k]=18;

	int	TempPosRow=0,TempPos=0;

	int	len,start,end;//len-----length,start-----string lable
	m_GetTime.GetWindowText(ReadTime);
	int	a[5];
	CString	b;
	for(i=0;i<4;i++)
	{
		if(i==0)
		{start=0;
		end=0;
		}
		if(i==3)
			{
				start=++end;
				end=ReadTime.GetLength();
			}
		else{
			int	mid;
			if(i!=0)
				start=++end;
			mid=ReadTime.Find('-',end);
			end=mid;
			}
		len=end-start;
		b=ReadTime.Mid(start,len);
		a[i]=atoi(b);
	}
	char	dest[200];
	int		l=0;
	
	//l=sprintf(dest+l,"*%d",a[0]);
	if(a[0]<10)
		l+=sprintf(dest+l,"0%d",a[0]);
	else
		l+=sprintf(dest+l,"%d",a[0]);
	if(a[1]<10)
		l+=sprintf(dest+l,"-0%d",a[1]);
	else
		l+=sprintf(dest+l,"-%d",a[1]);
	if(a[2]<10)
		l+=sprintf(dest+l,"\t&0%d",a[2]);
	else
		l+=sprintf(dest+l,"\t&%d",a[2]);
	if(a[3]<10)
		l+=sprintf(dest+l,":0%d",a[3]);
	else
		l+=sprintf(dest+l,":%d",a[3]);
	CString str="",strlist;
	strlist=dest;//______________________________________________gettimelist


	m_GetSpan.GetWindowText(ReadSpan);
	ReadSpanValue=atoi(ReadSpan);//______________________________gettimeSpan
	
	if(ReadSpanValue>50)
		LenDecideLarge=LenDecide=ReadSpanValue/50+1;
	else	if(ReadSpanValue<50&&ReadSpanValue>0)
		LenDecideSmall=LenDecide=50/ReadSpanValue;//_________________decide the data's length between to get;
	//dest='*'++'-'+ReadTime_1[1]+'-'+ReadTime_1[2]+'\t'+'&'+ReadTime_1[3]+':'+ReadTime_1[4];
	int	endflag=0;
	int	TextHour,TextMinute,TextTimeLen,TextSecond;
	int	findflag=0;

	char * buffer = new char[File_Read_Number];
	for(i=0;endflag==0;i++)//_____________________________________________1 minute's recycle
	{	

		int	pos1=PFile.GetPosition();
		if(pos1>(int)PFile.GetLength())//_______________________________________________end flag
		{
			endflag=1;
			break;
		}
		PFile.ReadHuge (buffer,7000);
		str.Format("%s",buffer);
		int	TextDay=str.Find('*');
		//________________________________________________left for day check
		TextDay=atoi(buffer+TextDay+9);

		TextTimeLen=str.Find('&')+1;
		TextHour=atoi(buffer+TextTimeLen);

		TextTimeLen=TextTimeLen+3;
		TextMinute=atoi(buffer+TextTimeLen);

		TextTimeLen+=3;
		TextSecond=atoi(buffer+TextTimeLen);//____________time check
		//if(str.Find('a')!=-1)
		//	findflag=true;
		int	abc=0;
		abc=str.Find('*',1);
		//if(abc==-1)
		//{
		//	endflag=1;		
		//	AfxMessageBox("ss");
		//}

		int	find2=str.Find(strlist);
		if(a[1]*24*60+a[2]*60+a[3]-1<TextDay*24*60+TextHour*60+TextMinute&&TextDay*24*60+TextHour*60+TextMinute<a[1]*24*60+a[2]*60+a[3]+ReadSpanValue)
			findflag=1;
	//________________________________________________find flag

		if((TextHour*60+TextMinute<a[2]*60+a[3]+ReadSpanValue)&&(TextHour*60+TextMinute>a[2]*60+a[3]-1))///___________1minute's detail
		{
			if((ReadSpanValue<50||ReadSpanValue==50)&&findflag==1&&endflag!=1)
			{
				int len=0,board,point,num=1;
				while(num<127)//14 * 9 
				{
					len=str.Find('#',len);
					board=convertchar(str.GetAt(len+2))*10+convertchar(str.GetAt(len+3));
					point=convertchar(str.GetAt(len+5));
					for(int	i=0;i<12;i++)
					{
						if(i==0)
							len=str.Find(' ',len+5);
						else
							len=str.Find(' ',++len);
						Temp_2[board][point][(TextHour*60+TextMinute-a[2]*60-a[3])*12+i]=atoi(buffer+len+1);
					}
					num++;
				}

			
					TempPosRow++;
			}

			else	if(ReadSpanValue>50&&findflag==1&&endflag!=1)
			{
				int len=0,board,point,num=1;
					if(LenJumperStore!=0)
						LenJumper=LenJumperStore;		
				while(num<127)
				{
					int	LenJumperLoad=LenJumperStore;
					len=str.Find('#',len);
					board=convertchar(str.GetAt(len+2))*10+convertchar(str.GetAt(len+3));
					point=convertchar(str.GetAt(len+5));
					for(int	i=0;i<12;i++)
					{					
						if(i==0)
							len=str.Find(' ',len+5);
						else
							len=str.Find(' ',++len);
						if(LenJumperLoad%LenDecide==0)
						{
							Temp_2[board][point][((TextHour*60+TextMinute -a[2]*60-a[3])*12+i)/LenDecide]=atoi(buffer+len+1);
						}
						if(board==1&&point==1)
							LenJumper++;
						LenJumperLoad++;
					}
					if(board==14&&point==9)
						LenJumperStore=LenJumper;
					num++;
				}
			}
	

		}

		int	pos2=pos1+abc;
		PFile.Seek(pos2,CFile::begin);
	}
	delete	[] buffer;

	int	containerflag;
	if(LenDecideLarge!=0)
		containerflag=0;
	else	containerflag=LenDecideSmall;
	DrawDefaultFrameRE(ReadSpanValue);//___________________________________________draw block
	if(Combo_Board!=15&&Combo_Point!=10)
		DrawDetailRe(Combo_Board,Combo_Point,containerflag);
	else	if(Combo_Board!=15&&Combo_Point==10)
	{
		for(i=1;i<10;i++)
		{
			DrawDetailRe(Combo_Board,i,containerflag);
		}
	}
	else	if(Combo_Board==15&&Combo_Point!=10)
	{
		for(i=1;i<15;i++)
		{
			DrawDetailRe(i,Combo_Point,containerflag);
		}
	}
	else	if(Combo_Board==15&&Combo_Point==10)
	{
		for(i=1;i<15;i++)
			for(int	j=1;j<10;j++)
			{
				DrawDetailRe(i,j,containerflag);
			}
	}
 	int asdf=1;
//	ASSERT(str.Find(dest)!=-1);
	//PFile.SeekToBegin();
	//CArchive	write(&PFile,CArchive::store,50);
	//write.Write(strlist,strlist.GetLength());

	
	
	//	if(NULL)
//	{
//		PFile.ReadHuge (buffer,1000);
//		str.Format ("%s",buffer);
//		str.Find ("*");

	//	while(fp != NULL)
	//	{

	//	}
//	}
}

void CMy7_10_3Dlg::OnChangeEdit2() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here


}

int CMy7_10_3Dlg::convertchar(char a)
{

	int x;
	if((48<=a)&(a<=57))
		x=(int)(a-'0');
	else if((65<=(int)a)&((int)a<=70))
		x=(int)(a-'A'+10);
	else if((97<=(int)a)&((int)a<=102))
		x=(int)(a-'a'+10);
	else x=0;
	return x;

}

void CMy7_10_3Dlg::DrawDetailRe(int	board,int	point,int	containerflag)
{
	if(containerflag==0)//Draw when time is long	
		for(int	i=1;i<600;i++)
			DrawDetailForRe(board,point,i,1);
	else{
		for(int i=1;i<600/containerflag;i++)//Draw when time is short
			DrawDetailForRe(board,point,i,containerflag);
	}
}

//DEL void CMy7_10_3Dlg::DrawDetailForRe()
//DEL {
//DEL 
//DEL }

void CMy7_10_3Dlg::DrawDetailForRe(int board,int	point,int time,int	span)
{
	float	span_2=(float)span;
	int timepix1,temppix1,timepix2,temppix2;
	timepix1=(int)((time-1)*span_2);
	temppix1=Temp_2[board][point][time-1]*4;
	
	timepix2=(int)(time*span_2);
	temppix2=Temp_2[board][point][time]*4;
	CDC	*dc;
	dc=m_Pic.GetDC();
	if(Combo_Board!=15)
		DrawLine(timepix1+30,YREF-temppix1,timepix2+30,YREF-temppix2,ColorList[point],dc);
	else
		DrawLine(timepix1+30,YREF-temppix1,timepix2+30,YREF-temppix2,ColorList2[board],dc);
	dc->DeleteDC();
 
}

void CMy7_10_3Dlg::OnButtonFileDialog() 
{
	// TODO: Add your control notification handler code here
	CFileDialog dlg(true);
	CString filename;
	char	*filenamechar;
	static char BASED_CODE szFilter[] = "Chart Files (*.xlc)|*.xlc|Worksheet Files (*.xls)|*.xls|Data Files (*.xlc;*.xls)|*.xlc; *.xls|All Files (*.*)|*.*||";

	if(dlg.DoModal () == IDOK)
	{
		filename = dlg.GetPathName();
		int len=filename.GetLength();
		filenamechar=new char[len];
		//filename.
		//CFile	SourceFile(filename,CFile::modeReadWrite);
		PFile.Close();
		CopyFile((LPCTSTR) filename ,&"data.txt",false);
		PFile.Open("data.txt",CFile::modeCreate|CFile::modeNoTruncate|CFile::modeReadWrite);
		delete	filenamechar;
	}//dlg.GetFileName
}


BOOL CMy7_10_3Dlg::DestroyWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	/*char	 *abc="123";
	PFile.SeekToBegin();
	PFile.Write(abc,3);	*/


	CTime	EndTime=CTime::GetCurrentTime();
	int	j;
	char	a[100];
	j=sprintf(a,"%d-",EndTime.GetYear());
	j+=sprintf(a+j,"%d-",EndTime.GetMonth());
	j+=sprintf(a+j,"%d%t",EndTime.GetDay());
	j+=sprintf(a+j,"%d:",EndTime.GetHour());
	j+=sprintf(a+j,"%d",EndTime.GetMinute());

	EndTimeStr=a;
	return CDialog::DestroyWindow();

}

void CMy7_10_3Dlg::OnButton5() 
{
	// TODO: Add your control notification handler code here
	CFileDialog dlg(false);
	CString filename;
	char	*filenamechar;
	static char BASED_CODE szFilter[] = "Chart Files (*.xlc)|*.xlc|Worksheet Files (*.xls)|*.xls|Data Files (*.xlc;*.xls)|*.xlc; *.xls|All Files (*.*)|*.*||";

	if(dlg.DoModal () == IDOK)
	{
		filename = dlg.GetPathName();
		int len=filename.GetLength();
		filenamechar=new char[len];
		//filename.
		//CFile	SourceFile(filename,CFile::modeReadWrite);
		
//		if(PFile.Open()==1)
			PFile.Close();
		CopyFile( &"data.txt",(LPCTSTR) filename,false);
		PFile.Open("data.txt",CFile::modeCreate|CFile::modeNoTruncate|CFile::modeReadWrite);
		delete	filenamechar;
	}//dlg.GetFileName	
}

void CMy7_10_3Dlg::DrawDefaultFrame(int Combo_Span)
{
	CDC *pDC,*OldDC;

	CString str;
	pDC=m_Pic.GetDC();
	//	pDC->DeleteDC();
	OldDC=pDC;
	for(int	i=0;i<800;i++)
		for(int	j=0;j<400;j++)
		{
			pDC->SetPixel(i+30,j,RGB(255,255,255));
		}
	DrawLine(30,YREF,XREF,YREF,RGB(0,0,0),pDC);
	DrawLine(30,YREF,30,0,RGB(0,0,0),pDC);



	int macro=CurrentTime/Combo_Span/10;
	int TimeLable[11];
	char	TimeLable_char[5];
	CString	TimeLable_str[11];
	//CString
	//for(i=0;i<11;i++)
	//	TimeLable_str[i]=new char[3];
	for(i=0;i<11;i++)
	{
		TimeLable[i]=macro*Combo_Span*10+i*Combo_Span;
	//	CString	a=TimeLable[i];
		//sprintf(TimeLable_str[i],"%d",TimeLable[i]);
		_itoa(TimeLable[i],TimeLable_char,10);
		TimeLable_str[i]=TimeLable_char;
		int		a=1;
	}
		
		

	for( i=0;i<11;i++)
	{
		str.Format(_T("%d"),i);
		pDC->TextOut(i*60+30,YREF,TimeLable_str[i]);
		if(i!=0)
			DrawLine(i*60+30,YREF,i*60+30,0,RGB(200,200,200),pDC);
	}
	for( i=1;i<13;i++)
	{
		str.Format(_T("%d"),i*10);
		pDC->TextOut(0,YREF-i*40,str);
		if(i!=0)
			DrawLine(30,YREF-i*40,630,YREF-i*40,RGB(200,200,200),pDC);

	}//________________________________________________________________________画出基本结构图

	CDC *LDC;
	LDC=m_PicColorList.GetDC();
		
	if(Combo_Board!=15)
	{
		str="";
		char	a[2];
		for(i=0;i<900;i++)
			for(int j=0;j<50;j++)
				LDC->SetPixel(i,j,RGB(212,208,200));
		for(i=0;i<9;i++)
			for(int	j=0;j<50;j++)
				for(int	k=0;k<50;k++)
				{
					sprintf(a,"%d",i+1);
					str=a;
					LDC->SetPixel(i*100+j,k,ColorList[i+1]);
					LDC->TextOut(i*100+50,25,str);
					if(i==8)
					LDC->TextOut(i*100+100,25,"点");
				}
	}
	if(Combo_Board==15)
	{
		str="";
		for(i=0;i<900;i++)
			for(int j=0;j<50;j++)
				LDC->SetPixel(i,j,RGB(212,208,200));
		char	a[2];
		for(i=0;i<14;i++)
			for(int	j=0;j<50;j++)
				for(int	k=0;k<50;k++)
				{
					sprintf(a,"%d",i+1);
					str=a;
					LDC->SetPixel(i*64+j,k,ColorList2[i+1]);
					LDC->TextOut(i*64+50,25,str);
					if(i==8)
						LDC->TextOut(i*100+100,25,"板");
				}
				//deleteda;
	}
	LDC->DeleteDC();

}

void CMy7_10_3Dlg::DrawDefaultFrameRE(int m_GetSpan)
{

//	DrawDefaultFrame();
	DrawDefaultFrame_Text();
	CDC *pDC,*OldDC;

	CString str;
	pDC=m_Pic.GetDC();
	//	pDC->DeleteDC();
	OldDC=pDC;
	for(int	i=0;i<800;i++)
		for(int	j=0;j<400;j++)
		{
			pDC->SetPixel(i+30,j,RGB(255,255,255));
		}
	DrawLine(30,YREF,XREF,YREF,RGB(0,0,0),pDC);
	DrawLine(30,YREF,30,0,RGB(0,0,0),pDC);



	int macro;
	int TimeLable[11];
	char	TimeLable_char[5];
	CString	TimeLable_str[11];
	//CString
	//for(i=0;i<11;i++)
	//	TimeLable_str[i]=new char[3];
/*	for(i=0;i<11;i++)
	{
		TimeLable[i]=macro*Combo_Span*10+i*Combo_Span;
		//CString	a=TimeLable[i];
		//sprintf(TimeLable_str[i],"%d",TimeLable[i]);
		_itoa(TimeLable[i],TimeLable_char,10);
		TimeLable_str[i]=TimeLable_char;
		int		a=1;
	}
*/

	if(m_GetSpan>50)
	{
		macro=m_GetSpan/50+1;
		for(int	i=0;i<11;i++)
		{
			TimeLable[i]=macro*50/10*i;
			_itoa(TimeLable[i],TimeLable_char,10);
			TimeLable_str[i]=TimeLable_char;
		}
	}

	if((m_GetSpan<50&&m_GetSpan>0)||m_GetSpan==50)
	{
		macro=50/m_GetSpan;
		for(int	i=0;i<11;i++)
		{
			TimeLable[i]=m_GetSpan*i/10;
			_itoa(TimeLable[i],TimeLable_char,10);
			TimeLable_str[i]=TimeLable_char;
		}
	}

		
		

	for( i=0;i<11;i++)
	{
		str.Format(_T("%d"),i);
		pDC->TextOut(i*60+30,YREF,TimeLable_str[i]);
		if(i!=0)
			DrawLine(i*60+30,YREF,i*60+30,0,RGB(200,200,200),pDC);
	}
	for( i=1;i<13;i++)
	{
		str.Format(_T("%d"),i*10);
		pDC->TextOut(0,YREF-i*40,str);
		if(i!=0)
			DrawLine(30,YREF-i*40,630,YREF-i*40,RGB(200,200,200),pDC);

	}//________________________________________________________________________画出基本结构图

	CDC *LDC;
	LDC=m_PicColorList.GetDC();
		
	if(Combo_Board!=15)
	{
		str="";
		char	a[2];
		for(i=0;i<900;i++)
			for(int j=0;j<50;j++)
				LDC->SetPixel(i,j,RGB(212,208,200));
		for(i=0;i<9;i++)
			for(int	j=0;j<50;j++)
				for(int	k=0;k<50;k++)
				{
					sprintf(a,"%d",i+1);
					str=a;
					LDC->SetPixel(i*100+j,k,ColorList[i+1]);
					LDC->TextOut(i*100+50,25,str);
					if(i==8)
					LDC->TextOut(i*100+100,25,"点");
				}
	}
	if(Combo_Board==15)
	{
		str="";
		for(i=0;i<900;i++)
			for(int j=0;j<50;j++)
				LDC->SetPixel(i,j,RGB(212,208,200));
		char	a[2];
		for(i=0;i<14;i++)
			for(int	j=0;j<50;j++)
				for(int	k=0;k<50;k++)
				{
					sprintf(a,"%d",i+1);
					str=a;
					LDC->SetPixel(i*64+j,k,ColorList2[i+1]);
					LDC->TextOut(i*64+50,25,str);
					if(i==8)
						LDC->TextOut(i*100+100,25,"板");
				}
				//deleteda;
	}
	LDC->DeleteDC();

}

void CMy7_10_3Dlg::DrawDefaultFrame_Text()
{
	CDC *pDC;
	pDC=m_Pic.GetDC();
	for(int	i=0;i<800;i++)
		for(int	j=400;j<450;j++)
		{
			pDC->SetPixel(i,j,RGB(255,255,255));
		}

	pDC->DeleteDC();
}

void CMy7_10_3Dlg::OnButton6() 
{

	// TODO: Add your control notification handler code here
	int	InitTempValueInt[15][10],TopTempValueInt[15][10];
	int	InitTempTimeInt[15][10],TopTempTimeInt[15][10];
	int InitFlag,InitPos,TopValue,TopPos;
	for(int	i=1;i<15;i++)
		for(int	j=1;j<10;j++)
		{
			InitFlag=0;InitPos=1;TopValue=0;TopPos=1;
			for(int	k=1;k<601;k++)
			{
				if(InitFlag==0&&Temp_2[i][j][k]!=18)
				{
					InitFlag=1;
					InitTempValueInt[i][j]=Temp_2[i][j][k];
					InitPos=k;
					if(ReadSpanValue>50)
						InitTempTimeInt[i][j]=LenDecide*5*InitPos/60;
					else	InitTempTimeInt[i][j]=5*InitPos/60;
					//InitTime
				}


				if(Temp_2[i][j][k]>TopValue)
				{
					TopValue=Temp_2[i][j][k];
					TopPos=k;
					TopTempValueInt[i][j]=Temp_2[i][j][TopPos];
					if(ReadSpanValue>50)
						TopTempTimeInt[i][j]=LenDecide*5*TopPos/60;
					else
						TopTempTimeInt[i][j]=5*TopPos/60;
					//TopTime
				}
			}
		}

//The following code is to change int to Cstring type for the report creation;
			 char str[10];

			for(i=1;i<15;i++)
				for(int	j=1;j<10;j++)
				{	InitTempValue[i][j]="";
					_itoa(InitTempValueInt[i][j],str,10);
					InitTempValue[i][j]=str;
				}
			for(i=1;i<15;i++)		
				for(int	j=1;j<10;j++)
				{
						TopTempValue[i][j]="";
					_itoa(TopTempValueInt[i][j],str,10);
					TopTempValue[i][j]=str;
				}
			for(i=1;i<15;i++)		
				for(int	j=1;j<10;j++)
				{
					InitTempTime[i][j]="";
					_itoa(InitTempTimeInt[i][j],str,10);
					InitTempTime[i][j]=str;
				}
			for(i=1;i<15;i++)		
				for(int	j=1;j<10;j++)
				{
					TopTempTime[i][j]="";
					_itoa(TopTempTimeInt[i][j],str,10);
					TopTempTime[i][j]=str;
				}



	CStdioFile file; 
	if (file.Open("Report.htm",CFile::modeCreate | CFile::modeWrite | CFile::typeText) 
	 == FALSE) { 
	AfxMessageBox("Can't create the Report.htm file!",MB_ICONSTOP); 
  
	} 


 // VYTVORENI HLAVICKY SOUBORU 
 file.WriteString("<!DOCTYPE html public \"-//W3C//DTD HTML 4.0 Transitional//EN\"><!--\n"); 
 file.WriteString("<META http-equiv=\"Content-Type\" content=\"text/html; charset=windows-1252\">\n"); 


 file.WriteString("<html>\n"); 
 file.WriteString("<style type=\"text/css\">\n"); 
 file.WriteString("body {\n"); 
 file.WriteString("\tFONT-SIZE: 10pt; BACKGROUND: white; COLOR: black; FONT-FAMILY: Tahoma, Arial, Helvetica, sans-serif;\n"); 
 file.WriteString("}\n"); 
 file.WriteString("h1 {\n"); 
 file.WriteString("\tFONT-SIZE: 14pt; text-weight: 800; text-align: center; margin-bottom: 0;\n"); 
 file.WriteString("}\n"); 
 file.WriteString("h2 {\n"); 
 file.WriteString("\tFONT-SIZE: 12pt; text-align: center; margin-top: 0;\n"); 
 file.WriteString("}\n"); 
 file.WriteString("a {\n"); 
 file.WriteString("\tTEXT-DECORATION: none\n"); 
 file.WriteString("}\n"); 
 file.WriteString("a:link {\n"); 
 file.WriteString("\tCOLOR: navy; TEXT-DECORATION: none\n"); 
 file.WriteString("}\n"); 
 file.WriteString("a:visited {\n"); 
 file.WriteString("\tCOLOR: navy; TEXT-DECORATION: none\n"); 
 file.WriteString("}\n"); 
 file.WriteString("a:hover {\n"); 
 file.WriteString("\tCOLOR: red; TEXT-DECORATION: underline\n"); 
 file.WriteString("}\n"); 
 file.WriteString("</style>\n"); 
 file.WriteString("<body>\n"); 

 CString	Temp="";//___________________establishing the row of the form

 file.WriteString("<h2>测试报告</h2>\n"); 
 file.WriteString("<p>开始时间<p>\n"); 
 file.WriteString(ReadTime);
 file.WriteString("\n<p>");
 file.WriteString("持续时间<p>\n");
 file.WriteString(ReadSpan);
 file.WriteString("分钟\n");
 file.WriteString( "<p>");
 file.WriteString("起始温度\n");
 file.WriteString("<TABLE cellPadding=3 border=1>\n");
 file.WriteString("<TBODY><TR><TD><B>板号/点阵</TD><TD><B>1</B></TD><TD><B>2</B></TD><TD><B>3</B></TD><TD><B>4</B></TD><TD><B>5</B></TD><TD><B>6</B></TD><TD><B>7</B></TD><TD><B>8</B></TD><TD><B>9</B></TD></TR>\n");
 file.WriteString(" <TR><TD><B>板1</B></TD>");
 for(i=1;i<10;i++)
 {
	 Temp+="<TD>";
	 Temp+=InitTempValue[1][i];
	 Temp+="/";
	 Temp+=InitTempTime[1][i];
	 Temp+="</TD>";
 }
 file.WriteString(Temp);
 file.WriteString("</TR>\n");
  file.WriteString(" <TR><TD><B>板2</B></TD>");
  Temp="";
 for(i=1;i<10;i++)
 {
	 Temp+="<TD>";
	 Temp+=InitTempValue[2][i];
	 Temp+="/";
	 Temp+=InitTempTime[2][i];
	 Temp+="</TD>";
 }
 file.WriteString(Temp);
 file.WriteString("</TR>\n");
  file.WriteString(" <TR><TD><B>板3</B></TD>");
  Temp="";
 for(i=1;i<10;i++)
 {
	 Temp+="<TD>";
	 Temp+=InitTempValue[3][i];
	 Temp+="/";
	 Temp+=InitTempTime[3][i];
	 Temp+="</TD>";
 }
 file.WriteString(Temp);
 file.WriteString("</TR>\n");
  file.WriteString(" <TR><TD><B>板4</B></TD>");
  Temp="";
 for(i=1;i<10;i++)
 {
	 Temp+="<TD>";
	 Temp+=InitTempValue[4][i];
	 Temp+="/";
	 Temp+=InitTempTime[4][i];
	 Temp+="</TD>";
 }
 file.WriteString(Temp);
 file.WriteString("</TR>\n");
  file.WriteString(" <TR><TD><B>板5</B></TD>");
  Temp="";
 for(i=1;i<10;i++)
 {
	 Temp+="<TD>";
	 Temp+=InitTempValue[5][i];
	 Temp+="/";
	 Temp+=InitTempTime[5][i];
	 Temp+="</TD>";
 }
 file.WriteString(Temp);
 file.WriteString("</TR>\n");
  file.WriteString(" <TR><TD><B>板6</B></TD>");
  Temp="";
  for(i=1;i<10;i++)
 {
	 Temp+="<TD>";
	 Temp+=InitTempValue[6][i];
	 Temp+="/";
	 Temp+=InitTempTime[6][i];
	 Temp+="</TD>";
 }
 file.WriteString(Temp);
 file.WriteString("</TR>\n");
  file.WriteString(" <TR><TD><B>板7</B></TD>");
  Temp="";
 for(i=1;i<10;i++)
 {
	 Temp+="<TD>";
	 Temp+=InitTempValue[7][i];
	 Temp+="/";
	 Temp+=InitTempTime[7][i];
	 Temp+="</TD>";
 }
 file.WriteString(Temp);
 file.WriteString("</TR>\n");
  file.WriteString(" <TR><TD><B>板8</B></TD>");
  Temp="";
 for(i=1;i<10;i++)
 {
	 Temp+="<TD>";
	 Temp+=InitTempValue[8][i];
	 Temp+="/";
	 Temp+=InitTempTime[8][i];
	 Temp+="</TD>";
 }
 file.WriteString(Temp);
 file.WriteString("</TR>\n");
  file.WriteString(" <TR><TD><B>板9</B></TD>");
  Temp="";
 for(i=1;i<10;i++)
 {
	 Temp+="<TD>";
	 Temp+=InitTempValue[9][i];
	 Temp+="/";
	 Temp+=InitTempTime[9][i];
	 Temp+="</TD>";
 }
 file.WriteString(Temp);
 file.WriteString("</TR>\n");
  file.WriteString(" <TR><TD><B>板10</B></TD>");
  Temp="";
 for(i=1;i<10;i++)
 {
	 Temp+="<TD>";
	 Temp+=InitTempValue[10][i];
	 Temp+="/";
	 Temp+=InitTempTime[10][i];
	 Temp+="</TD>";
 }
 file.WriteString(Temp);
 file.WriteString("</TR>\n");
  file.WriteString(" <TR><TD><B>板11</B></TD>");
  Temp="";
 for(i=1;i<10;i++)
 {
	 Temp+="<TD>";
	 Temp+=InitTempValue[11][i];
	 Temp+="/";
	 Temp+=InitTempTime[11][i];
	 Temp+="</TD>";
 }
 file.WriteString(Temp);
 file.WriteString("</TR>\n");
  file.WriteString(" <TR><TD><B>板12</B></TD>");
  Temp="";
 for(i=1;i<10;i++)
 {
	 Temp+="<TD>";
	 Temp+=InitTempValue[12][i];
	 Temp+="/";
	 Temp+=InitTempTime[12][i];
	 Temp+="</TD>";
 }
 file.WriteString(Temp);
 file.WriteString("</TR>\n");
  file.WriteString(" <TR><TD><B>板13</B></TD>");
  Temp="";
 for(i=1;i<10;i++)
 {
	 Temp+="<TD>";
	 Temp+=InitTempValue[13][i];
	 Temp+="/";
	 Temp+=InitTempTime[13][i];
	 Temp+="</TD>";
 }
 file.WriteString(Temp);
 file.WriteString("</TR>\n");
  file.WriteString(" <TR><TD><B>板14</B></TD>");
  Temp="";
 for(i=1;i<10;i++)
 {
	 Temp+="<TD>";
	 Temp+=InitTempValue[14][i];
	 Temp+="/";
	 Temp+=InitTempTime[14][i];
	 Temp+="</TD>";
 }
 file.WriteString(Temp);
 file.WriteString("</TR>\n");
 file.WriteString(" </TBODY></TABLE>");
 file.WriteString( "<p>");



 file.WriteString("最高温度\n");
 file.WriteString("<TABLE cellPadding=3 border=1>\n");
 file.WriteString("<TBODY><TR><TD><B>板号/点阵</TD><TD><B>1</B></TD><TD><B>2</B></TD><TD><B>3</B></TD><TD><B>4</B></TD><TD><B>5</B></TD><TD><B>6</B></TD><TD><B>7</B></TD><TD><B>8</B></TD><TD><B>9</B></TD></TR>\n");
 file.WriteString(" <TR><TD><B>板1</B></TD>");
 Temp="";
 for(i=1;i<10;i++)
 {
	 Temp+="<TD>";
	 Temp+=TopTempValue[1][i];
	 Temp+="/";
	 Temp+=TopTempTime[1][i];
	 Temp+="</TD>";
 }
 file.WriteString(Temp);
 file.WriteString("</TR>\n");
 file.WriteString(" <TR><TD><B>板2</B></TD>");
  Temp="";
 for(i=1;i<10;i++)
 {
	 Temp+="<TD>";
	 Temp+=TopTempValue[2][i];
	 Temp+="/";
	 Temp+=TopTempTime[2][i];
	 Temp+="</TD>";
 }
 file.WriteString(Temp);
 file.WriteString("</TR>\n");file.WriteString(" <TR><TD><B>板3</B></TD>");
  Temp="";
 for(i=1;i<10;i++)
 {
	 Temp+="<TD>";
	 Temp+=TopTempValue[3][i];
	 Temp+="/";
	 Temp+=TopTempTime[3][i];
	 Temp+="</TD>";
 }
 file.WriteString(Temp);
 file.WriteString("</TR>\n");
 file.WriteString(" <TR><TD><B>板4</B></TD>");
  Temp="";
 for(i=1;i<10;i++)
 {
	 Temp+="<TD>";
	 Temp+=TopTempValue[4][i];
	 Temp+="/";
	 Temp+=TopTempTime[4][i];
	 Temp+="</TD>";
 }
 file.WriteString(Temp);
 file.WriteString("</TR>\n");
 file.WriteString(" <TR><TD><B>板5</B></TD>");
  Temp="";
 for(i=1;i<10;i++)
 {
	 Temp+="<TD>";
	 Temp+=TopTempValue[5][i];
	 Temp+="/";
	 Temp+=TopTempTime[5][i];
	 Temp+="</TD>";
 }
 file.WriteString(Temp);
 file.WriteString("</TR>\n");
 file.WriteString(" <TR><TD><B>板6</B></TD>");
  Temp="";
 for(i=1;i<10;i++)
 {
	 Temp+="<TD>";
	 Temp+=TopTempValue[6][i];
	 Temp+="/";
	 Temp+=TopTempTime[6][i];
	 Temp+="</TD>";
 }
 file.WriteString(Temp);
 file.WriteString("</TR>\n");
 file.WriteString(" <TR><TD><B>板7</B></TD>");
  Temp="";
 for(i=1;i<10;i++)
 {
	 Temp+="<TD>";
	 Temp+=TopTempValue[7][i];
	 Temp+="/";
	 Temp+=TopTempTime[7][i];
	 Temp+="</TD>";
 }
 file.WriteString(Temp);
 file.WriteString("</TR>\n");
 file.WriteString(" <TR><TD><B>板8</B></TD>");
  Temp="";
 for(i=1;i<10;i++)
 {
	 Temp+="<TD>";
	 Temp+=TopTempValue[8][i];
	 Temp+="/";
	 Temp+=TopTempTime[8][i];
	 Temp+="</TD>";
 }
 file.WriteString(Temp);
 file.WriteString("</TR>\n");
 file.WriteString(" <TR><TD><B>板9</B></TD>");
  Temp="";
 for(i=1;i<10;i++)
 {
	 Temp+="<TD>";
	 Temp+=TopTempValue[9][i];
	 Temp+="/";
	 Temp+=TopTempTime[9][i];
	 Temp+="</TD>";
 }
 file.WriteString(Temp);
 file.WriteString("</TR>\n");
 file.WriteString(" <TR><TD><B>板10</B></TD>");
  Temp="";
 for(i=1;i<10;i++)
 {
	 Temp+="<TD>";
	 Temp+=TopTempValue[10][i];
	 Temp+="/";
	 Temp+=TopTempTime[10][i];
	 Temp+="</TD>";
 }
 file.WriteString(Temp);
 file.WriteString("</TR>\n");
 file.WriteString(" <TR><TD><B>板11</B></TD>");
  Temp="";
 for(i=1;i<10;i++)
 {
	 Temp+="<TD>";
	 Temp+=TopTempValue[11][i];
	 Temp+="/";
	 Temp+=TopTempTime[11][i];
	 Temp+="</TD>";
 }
 file.WriteString(Temp);
 file.WriteString("</TR>\n");
 file.WriteString(" <TR><TD><B>板12</B></TD>");
  Temp="";
 for(i=1;i<10;i++)
 {
	 Temp+="<TD>";
	 Temp+=TopTempValue[12][i];
	 Temp+="/";
	 Temp+=TopTempTime[12][i];
	 Temp+="</TD>";
 }
 file.WriteString(Temp);
 file.WriteString("</TR>\n");
 file.WriteString(" <TR><TD><B>板13</B></TD>");
  Temp="";
 for(i=1;i<10;i++)
 {
	 Temp+="<TD>";
	 Temp+=TopTempValue[13][i];
	 Temp+="/";
	 Temp+=TopTempTime[13][i];
	 Temp+="</TD>";
 }
 file.WriteString(Temp);
 file.WriteString("</TR>\n");
 file.WriteString(" <TR><TD><B>板14</B></TD>");
  Temp="";
 for(i=1;i<10;i++)
 {
	 Temp+="<TD>";
	 Temp+=TopTempValue[14][i];
	 Temp+="/";
	 Temp+=TopTempTime[14][i];
	 Temp+="</TD>";
 }
 file.WriteString(Temp);
 file.WriteString("</TR>\n");
 file.WriteString(" </TBODY></TABLE>");

  
 file.WriteString("</body>\n"); 
 file.WriteString("</html>\n"); 
 file.Close(); 

}
