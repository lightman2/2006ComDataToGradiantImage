// 7_10_3.h : main header file for the 7_10_3 application
//

#if !defined(AFX_7_10_3_H__5C311B74_14B1_4BCC_BEF7_D723336937C5__INCLUDED_)
#define AFX_7_10_3_H__5C311B74_14B1_4BCC_BEF7_D723336937C5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMy7_10_3App:
// See 7_10_3.cpp for the implementation of this class
//

class CMy7_10_3App : public CWinApp
{
public:
	CMy7_10_3App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMy7_10_3App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMy7_10_3App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_7_10_3_H__5C311B74_14B1_4BCC_BEF7_D723336937C5__INCLUDED_)
