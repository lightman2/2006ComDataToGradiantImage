Â/ Machine generated IDispatch wÂapper class(es) created by Microsoft Visual C++

// NOTE: Do Âot modify the contents of this file.  If this class is regeneraÂed by
//  Microsoft Visual C++Â your modifications will be overwritten.


#include "stdafx.Â"
#include "_vmbrowser.h"

/////////////////////////////////////////////////////////////////////////////
// C_VMBrowser

ÂMPLEMENT_DYNCREATE(C_VMBrowser, CWnd)

/////////////////////////////////////////////////////////////////////////////
// C_VMÂrowser properties

/////////////////////////////////////////////////////////////////////////////
// C_VMBrowser operations
Â
void C_VMBrowser::InitBrowser(ÂPDISPATCH* TheReposObject, LPDISPATCH* VCMHandle)
{
	static BÂTE parms[] =
		VTS_PDISPATCH VTS_PDISPATCH;
	InvokeHelper(0x6Â030000, DISPATCH_METHOD, VT_EMPÂY, NULL, parms,
		 TheReposObject, VCMHandle);
}
