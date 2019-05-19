// WinMain.h : main header file for the WINMAIN application
//

#if !defined(AFX_WINMAIN_H__DC58E8D1_5F70_4420_976C_55CC07C3D840__INCLUDED_)
#define AFX_WINMAIN_H__DC58E8D1_5F70_4420_976C_55CC07C3D840__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CWinMainApp:
// See WinMain.cpp for the implementation of this class
//

class CWinMainApp : public CWinApp
{
public:
	CWinMainApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWinMainApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CWinMainApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WINMAIN_H__DC58E8D1_5F70_4420_976C_55CC07C3D840__INCLUDED_)
