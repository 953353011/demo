Attribute VB_Name = "WinMain"
'Ver xcgui 1.8.9 +  time 2015.10.22




Private Function L(data As String) As String
L = StrConv(data, vbUnicode)
End Function


Public Function OnClick(ByRef bHandle As Long) As Long

    MsgBox "��ɫ����"
    bHandle = True
    OnClick = 0

End Function

Private Sub Main()
    
    bOk = XInitXCGUI(0)

    If bOk Then

        Dim hWindow As Long
            
        hWindow = XWnd_Create(0, 0, 300, 200, L("�Ų�VB����"), 0, xc_window_style_default)

        hBtn = XBtn_Create(8, 30, 100, 20, L("button"), hWindow)
        
        '���ð�ťΪ ��ѡ�� ����Ŀ����Լ��� button_type_��ͷ��
             XBtn_SetType hBtn, button_type_check
        ' ������� �� ����ۿ���������ͨ��ť����ҿ���ע�͵�����һ�е�
             XBtn_SetStyle hBtn, button_style_default

        If hWindow <> 0 Then

            XWnd_ShowWindow hWindow, 5
            XRunXCGUI

        End If

        XExitXCGUI
    
    End If


End Sub

