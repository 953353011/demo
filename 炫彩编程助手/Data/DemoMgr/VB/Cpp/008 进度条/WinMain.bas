Attribute VB_Name = "WinMain"
'Ver xcgui 1.8.9 +  time 2015.10.22



Dim hEdit As Long
Dim hEdit1 As Long

Private Function L(data As String) As String
L = StrConv(data, vbUnicode)
End Function


Public Function OnProgChange(ByVal pos As Long, ByRef pbHandled As Long) As Long


Debug.Print pos

OnProgChange = 0
End Function


Private Sub Main()
    
    bOk = XInitXCGUI(0)

    If bOk Then

    Dim hWindow As Long
    hWindow = XWnd_Create(0, 0, 500, 300, L("www.xcgui.com"), _
    0, xc_window_style_default)

    Dim hProgBar  As Long
    hProgBar = XProgBar_Create(0, 0, 100, 20, hWindow)
    
    Call XEle_RegEventC(hProgBar, XE_PROGRESSBAR_CHANGE, AddressOf OnProgChange)

    Call XProgBar_SetPos(hProgBar, 5)
    
    
    
        If hWindow <> 0 Then

            XWnd_ShowWindow hWindow, 5
            XRunXCGUI

        End If

        XExitXCGUI
    
    End If


End Sub

