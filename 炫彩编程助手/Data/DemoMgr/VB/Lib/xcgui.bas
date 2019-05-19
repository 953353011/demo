Attribute VB_Name = "XCGUI"


Declare Function XDateTime_Create Lib "xcgui.dll" (ByVal x As Long, ByVal y As Long, ByVal cx As Long, ByVal cy As Long, ByVal hParent As Long) As Long
Declare Sub XDateTime_SetStyle Lib "xcgui.dll" (ByVal hEle As Long, ByVal nStyle As Long)
Declare Function XDateTime_GetStyle Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XDateTime_GetTime Lib "xcgui.dll" (ByVal hEle As Long, ByVal pnHour As Long, ByVal pnMinute As Long, ByVal pnSecond As Long)
Declare Sub XDateTime_SetTime Lib "xcgui.dll" (ByVal hEle As Long, ByVal nHour As Long, ByVal nMinute As Long, ByVal nSecond As Long)
Declare Sub XDateTime_GetDate Lib "xcgui.dll" (ByVal hEle As Long, ByVal pnYear As Long, ByVal pnMonth As Long, ByVal pnDay As Long)
Declare Sub XDateTime_SetDate Lib "xcgui.dll" (ByVal hEle As Long, ByVal nYear As Long, ByVal nMonth As Long, ByVal nDay As Long)
Declare Function XDateTime_GetSelBkColor Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XDateTime_SetSelBkColor Lib "xcgui.dll" (ByVal hEle As Long, ByVal crSelectBk As Long, ByVal alpha As Byte)
Declare Function XDateTime_GetButton Lib "xcgui.dll" (ByVal hEle As Long, ByVal nType As Long) As Long
Declare Function XMonthCal_Create Lib "xcgui.dll" (ByVal x As Long, ByVal y As Long, ByVal cx As Long, ByVal cy As Long, ByVal hParent As Long) As Long
Declare Sub XMonthCal_SetToday Lib "xcgui.dll" (ByVal hEle As Long, ByVal nYear As Long, ByVal nMonth As Long, ByVal nDay As Long)
Declare Sub XMonthCal_GetToday Lib "xcgui.dll" (ByVal hEle As Long, ByVal pnYear As Long, ByVal pnMonth As Long, ByVal pnDay As Long)
Declare Sub XMonthCal_SeSelDate Lib "xcgui.dll" (ByVal hEle As Long, ByVal nYear As Long, ByVal nMonth As Long, ByVal nDay As Long)
Declare Sub XMonthCal_GetSelDate Lib "xcgui.dll" (ByVal hEle As Long, ByVal pnYear As Long, ByVal pnMonth As Long, ByVal pnDay As Long)
Declare Function XMonthCal_GetButton Lib "xcgui.dll" (ByVal hEle As Long, ByVal nType As Long) As Long
Declare Function XC_UnicodeToAnsi Lib "xcgui.dll" (ByVal pIn As String, ByVal inLen As Long, ByVal pOut As String, ByVal outLen As Long) As Long
Declare Function XC_AnsiToUnicode Lib "xcgui.dll" (ByVal pIn As String, ByVal inLen As Long, ByVal pOut As String, ByVal outLen As Long) As Long
Declare Sub XC_DebugToFileInfo Lib "xcgui.dll" (ByVal pInfo As String)
Declare Function XC_IsHELE Lib "xcgui.dll" (ByVal hEle As Long) As Boolean
Declare Function XC_IsHWINDOW Lib "xcgui.dll" (ByVal hWindow As Long) As Boolean
Declare Function XC_IsShape Lib "xcgui.dll" (ByVal hShape As Long) As Boolean
Declare Function XC_IsHXCGUI Lib "xcgui.dll" (ByVal hXCGUI As Long, ByVal nType As Long) As Boolean
Declare Function XC_hWindowFromHWnd Lib "xcgui.dll" (ByVal hWnd As Long) As Long
Declare Function XC_RegisterWindowClassName Lib "xcgui.dll" (ByVal pClassName As String) As Boolean
Declare Function XC_IsSViewExtend Lib "xcgui.dll" (ByVal hEle As Long) As Boolean
Declare Function XC_GetObjectType Lib "xcgui.dll" (ByVal hXCGUI As Long) As Long
Declare Function XC_GetObjectByID Lib "xcgui.dll" (ByVal nID As Long) As Long
Declare Function XC_GetResIDValue Lib "xcgui.dll" (ByVal pName As String) As Long
Declare Sub XC_SetPaintFrequency Lib "xcgui.dll" (ByVal nMilliseconds As Long)
Declare Function XC_RectInRect Lib "xcgui.dll" (ByVal pRect1 As rect, ByVal pRect2 As rect) As Boolean
Declare Sub XC_CombineRect Lib "xcgui.dll" (ByVal pDest As rect, ByVal pSrc1 As rect, ByVal pSrc2 As rect)
Declare Sub XC_ShowLayoutFrame Lib "xcgui.dll" (ByVal bShow As Boolean)
Declare Sub XC_EnableDebugFile Lib "xcgui.dll" (ByVal bEnable As Boolean)
Declare Sub XC_SetLayoutFrameColor Lib "xcgui.dll" (ByVal color As Long)
Declare Sub XC_EnableErrorMessageBox Lib "xcgui.dll" (ByVal bEnabel As Boolean)
Declare Function XC_LoadLayout Lib "xcgui.dll" (ByVal pFileName As String, ByVal hParent As Long) As Long
Declare Function XC_LoadLayoutFromString Lib "xcgui.dll" (ByVal pStringXML As String, ByVal hParent As Long) As Long
Declare Function XC_LoadResource Lib "xcgui.dll" (ByVal pFileName As String, ByVal pDir As String) As Boolean
Declare Function XC_LoadResourceFromString Lib "xcgui.dll" (ByVal pStringXML As String, ByVal pDir As String) As Boolean
Declare Function XC_LoadTemplate Lib "xcgui.dll" (ByVal nType As Long, ByVal pFileName As String) As template_info_i
Declare Function XC_LoadTemplateFromString Lib "xcgui.dll" (ByVal nType As Long, ByVal pStringXML As String) As template_info_i
Declare Sub XC_TemplateDestroy Lib "xcgui.dll" (ByVal pInfo As template_info_i)
Declare Sub XC_GetTextSize Lib "xcgui.dll" (ByVal pString As String, ByVal length As Long, ByVal hFontx As Long, ByVal pOutSize As size)
Declare Sub XC_GetTextShowSize Lib "xcgui.dll" (ByVal pString As String, ByVal length As Long, ByVal hFontx As Long, ByVal pOutSize As size)
Declare Function XC_GetDefaultFont Lib "xcgui.dll" () As Long
Declare Sub XC_SetDefaultFont Lib "xcgui.dll" (ByVal hFontx As Long)
Declare Sub XC_InitFont Lib "xcgui.dll" (ByVal pFont As LOGFONTW, ByVal pName As String, ByVal size As Long, ByVal bBold As Boolean, ByVal bItalic As Boolean, ByVal bUnderline As Boolean, ByVal bStrikeOut As Boolean)
Declare Function XC_Malloc Lib "xcgui.dll" (ByVal size As Long) As Long
Declare Sub XC_Free Lib "xcgui.dll" (ByVal p As Long)
'Declare Sub _XC_SetType Lib "xcgui.dll" (ByVal hXCGUI As Long,ByVal nType As Long)
'Declare Sub _XC_AddType Lib "xcgui.dll" (ByVal hXCGUI As Long,ByVal nType As Long)
'Declare Sub _XC_BindData Lib "xcgui.dll" (ByVal hXCGUI As Long,ByVal data As Long)
'Declare Function _XC_GetBindData Lib "xcgui.dll" (ByVal hXCGUI As Long) As Long
Declare Function XInitXCGUI Lib "xcgui.dll" (ByVal pText As String) As Boolean
Declare Sub XRunXCGUI Lib "xcgui.dll" ()
Declare Sub XExitXCGUI Lib "xcgui.dll" ()
Declare Function XBkInfoM_Create Lib "xcgui.dll" () As Long
Declare Sub XBkInfoM_Destroy Lib "xcgui.dll" (ByVal hBkInfoM As Long)
Declare Function XBkInfoM_SetBkInfo Lib "xcgui.dll" (ByVal hBkInfoM As Long, ByVal pText As String) As Long
Declare Sub XBkInfoM_AddBorder Lib "xcgui.dll" (ByVal hBkInfoM As Long, ByVal nState As Long, ByVal color As Long, ByVal alpha As Byte, ByVal width As Long)
Declare Sub XBkInfoM_AddFill Lib "xcgui.dll" (ByVal hBkInfoM As Long, ByVal nState As Long, ByVal color As Long, ByVal alpha As Byte)
Declare Sub XBkInfoM_AddImage Lib "xcgui.dll" (ByVal hBkInfoM As Long, ByVal nState As Long, ByVal hImage As Long)
Declare Function XBkInfoM_GetCount Lib "xcgui.dll" (ByVal hBkInfoM As Long) As Long
Declare Sub XBkInfoM_Clear Lib "xcgui.dll" (ByVal hBkInfoM As Long)
Declare Function XBkInfoM_Draw Lib "xcgui.dll" (ByVal hBkInfoM As Long, ByVal nState As Long, ByVal hDraw As Long, ByVal pRect As rect) As Boolean
Declare Function XBkInfoM_DrawEx Lib "xcgui.dll" (ByVal hBkInfoM As Long, ByVal nState As Long, ByVal hDraw As Long, ByVal pRect As rect, ByVal nStateFilter As Long) As Boolean
Declare Function XBtn_Create Lib "xcgui.dll" (ByVal x As Long, ByVal y As Long, ByVal cx As Long, ByVal cy As Long, ByVal pName As String, ByVal hParent As Long) As Long
Declare Function XBtn_IsCheck Lib "xcgui.dll" (ByVal hEle As Long) As Boolean
Declare Function XBtn_SetCheck Lib "xcgui.dll" (ByVal hEle As Long, ByVal bCheck As Boolean) As Boolean
Declare Sub XBtn_SetState Lib "xcgui.dll" (ByVal hEle As Long, ByVal nState As Long)
Declare Function XBtn_GetState Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Function XBtn_GetStateEx Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XBtn_SetStyle Lib "xcgui.dll" (ByVal hEle As Long, ByVal nStyle As Long)
Declare Function XBtn_GetStyle Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XBtn_SetType Lib "xcgui.dll" (ByVal hEle As Long, ByVal nType As Long)
Declare Function XBtn_GetType Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XBtn_SetGroupID Lib "xcgui.dll" (ByVal hEle As Long, ByVal nID As Long)
Declare Function XBtn_GetGroupID Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XBtn_SetBindEle Lib "xcgui.dll" (ByVal hEle As Long, ByVal hBindEle As Long)
Declare Function XBtn_GetBindEle Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XBtn_SetTextAlign Lib "xcgui.dll" (ByVal hEle As Long, ByVal nFlags As Long)
Declare Function XBtn_GetTextAlign Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XBtn_SetIconAlign Lib "xcgui.dll" (ByVal hEle As Long, ByVal align As Long)
Declare Sub XBtn_SetOffset Lib "xcgui.dll" (ByVal hEle As Long, ByVal x As Long, ByVal y As Long)
Declare Sub XBtn_SetOffsetIcon Lib "xcgui.dll" (ByVal hEle As Long, ByVal x As Long, ByVal y As Long)
Declare Sub XBtn_SetIconSpace Lib "xcgui.dll" (ByVal hEle As Long, ByVal size As Long)
Declare Sub XBtn_GetText Lib "xcgui.dll" (ByVal hEle As Long, ByVal pOut As Long, ByVal nOutLen As Long)
Declare Sub XBtn_SetText Lib "xcgui.dll" (ByVal hEle As Long, ByVal pName As String)
Declare Sub XBtn_SetIcon Lib "xcgui.dll" (ByVal hEle As Long, ByVal hImage As Long)
Declare Sub XBtn_SetIconDisable Lib "xcgui.dll" (ByVal hEle As Long, ByVal hImage As Long)
Declare Sub XBtn_AddAnimationFrame Lib "xcgui.dll" (ByVal hEle As Long, ByVal hImage As Long, ByVal uElapse As Long)
Declare Sub XBtn_EnableAnimation Lib "xcgui.dll" (ByVal hEle As Long, ByVal bEnable As Boolean, ByVal bLoopPlay As Boolean)
Declare Sub XBtn_AddBkBorder Lib "xcgui.dll" (ByVal hEle As Long, ByVal nState As Long, ByVal color As Long, ByVal alpha As Byte, ByVal width As Long)
Declare Sub XBtn_AddBkFill Lib "xcgui.dll" (ByVal hEle As Long, ByVal nState As Long, ByVal color As Long, ByVal alpha As Byte)
Declare Sub XBtn_AddBkImage Lib "xcgui.dll" (ByVal hEle As Long, ByVal nState As Long, ByVal hImage As Long)
Declare Function XBtn_GetBkInfoCount Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XBtn_ClearBkInfo Lib "xcgui.dll" (ByVal hEle As Long)
Declare Function XComboBox_Create Lib "xcgui.dll" (ByVal x As Long, ByVal y As Long, ByVal cx As Long, ByVal cy As Long, ByVal hParent As Long) As Long
Declare Function XComboBox_SetSelItem Lib "xcgui.dll" (ByVal hEle As Long, ByVal iIndex As Long) As Boolean
Declare Sub XComboBox_GetButtonRect Lib "xcgui.dll" (ByVal hEle As Long, ByVal pRect As rect)
Declare Sub XComboBox_SetButtonSize Lib "xcgui.dll" (ByVal hEle As Long, ByVal size As Long)
Declare Sub XComboBox_SetDropHeight Lib "xcgui.dll" (ByVal hEle As Long, ByVal height As Long)
Declare Function XComboBox_GetDropHeight Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XComboBox_BindApapter Lib "xcgui.dll" (ByVal hEle As Long, ByVal hAdapter As Long)
Declare Function XComboBox_GetApapter Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XComboBox_SetItemTemplateXML Lib "xcgui.dll" (ByVal hEle As Long, ByVal pXmlFile As String)
Declare Sub XComboBox_SetItemTemplateXMLFromString Lib "xcgui.dll" (ByVal hEle As Long, ByVal pStringXML As String)
Declare Sub XComboBox_EnableDrawButton Lib "xcgui.dll" (ByVal hEle As Long, ByVal bEnable As Boolean)
Declare Sub XComboBox_EnableEdit Lib "xcgui.dll" (ByVal hEle As Long, ByVal bEdit As Boolean)
Declare Sub XComboBox_AddBkBorder Lib "xcgui.dll" (ByVal hEle As Long, ByVal nState As Long, ByVal color As Long, ByVal alpha As Byte, ByVal width As Long)
Declare Sub XComboBox_AddBkFill Lib "xcgui.dll" (ByVal hEle As Long, ByVal nState As Long, ByVal color As Long, ByVal alpha As Byte)
Declare Sub XComboBox_AddBkImage Lib "xcgui.dll" (ByVal hEle As Long, ByVal nState As Long, ByVal hImage As Long)
Declare Function XComboboX_GetBkInfoCount Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XComboBox_ClearBkInfo Lib "xcgui.dll" (ByVal hEle As Long)
Declare Function XComboBox_GetSelItem Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Function XComboBox_GetState Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XAdapter_Destroy Lib "xcgui.dll" (ByVal hAdapter As Long)
Declare Function XAdapterListView_Create Lib "xcgui.dll" () As Long
Declare Function XAdapterListView_Group_AddColumn Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal pName As String) As Long
Declare Function XAdapterListView_Group_AddItemText Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal pValue As String) As Long
Declare Function XAdapterListView_Group_AddItemTextEx Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal pName As String, ByVal pValue As String) As Long
Declare Function XAdapterListView_Group_AddItemImage Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal hImage As Long) As Long
Declare Function XAdapterListView_Group_AddItemImageEx Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal pName As String, ByVal hImage As Long) As Long
Declare Function XAdapterListView_Group_SetText Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iGroup As Long, ByVal iColumn As Long, ByVal pValue As String) As Boolean
Declare Function XAdapterListView_Group_SetTextEx Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iGroup As Long, ByVal pName As String, ByVal pValue As String) As Boolean
Declare Function XAdapterListView_Group_SetImage Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iGroup As Long, ByVal iColumn As Long, ByVal hImage As Long) As Boolean
Declare Function XAdapterListView_Group_SetImageEx Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iGroup As Long, ByVal pName As String, ByVal hImage As Long) As Boolean
Declare Function XAdapterListView_Group_GetCount Lib "xcgui.dll" (ByVal hAdapter As Long) As Long
Declare Function XAdapterListView_Item_GetCount Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iGroup As Long) As Long
Declare Function XAdapterListView_Item_AddColumn Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal pName As String) As Long
Declare Function XAdapterListView_Item_AddItemText Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iGroup As Long, ByVal pValue As String) As Long
Declare Function XAdapterListView_Item_AddItemTextEx Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iGroup As Long, ByVal pName As String, ByVal pValue As String) As Long
Declare Function XAdapterListView_Item_AddItemImage Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iGroup As Long, ByVal hImage As Long) As Long
Declare Function XAdapterListView_Item_AddItemImageEx Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iGroup As Long, ByVal pName As String, ByVal hImage As Long) As Long
Declare Function XAdapterListView_Item_SetText Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iGroup As Long, ByVal iItem As Long, ByVal iColumn As Long, ByVal pValue As String) As Boolean
Declare Function XAdapterListView_Item_SetTextEx Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iGroup As Long, ByVal iItem As Long, ByVal pName As String, ByVal pValue As String) As Boolean
Declare Function XAdapterListView_Item_SetImage Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iGroup As Long, ByVal iItem As Long, ByVal iColumn As Long, ByVal hImage As Long) As Boolean
Declare Function XAdapterListView_Item_SetImageEx Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iGroup As Long, ByVal iItem As Long, ByVal pName As String, ByVal hImage As Long) As Boolean
Declare Function XAdapterListView_Group_DeleteItem Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iGroup As Long) As Boolean
Declare Sub XAdapterListView_Group_DeleteAllChildItem Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iGroup As Long)
Declare Function XAdapterListView_Item_DeleteItem Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iGroup As Long, ByVal iItem As Long) As Boolean
Declare Sub XAdapterListView_DeleteAll Lib "xcgui.dll" (ByVal hAdapter As Long)
Declare Sub XAdapterListView_DeleteAllGroup Lib "xcgui.dll" (ByVal hAdapter As Long)
Declare Sub XAdapterListView_DeleteAllItem Lib "xcgui.dll" (ByVal hAdapter As Long)
Declare Sub XAdapterListView_DeleteColumnGroup Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iColumn As Long)
Declare Sub XAdapterListView_DeleteColumnItem Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iColumn As Long)
Declare Function XAdapterListView_Item_GetTextEx Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iGroup As Long, ByVal iItem As Long, ByVal pName As String, ByVal pOut As Long, ByVal nOutLen As Long) As Boolean
Declare Function XAdapterListView_Item_GetImageEx Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iGroup As Long, ByVal iItem As Long, ByVal pName As String) As Long
Declare Function XAdapterTable_Create Lib "xcgui.dll" () As Long
Declare Function XAdapterTable_AddColumn Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal pName As String) As Long
Declare Function XAdapterTable_SetColumn Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal pColName As String) As Long
Declare Function XAdapterTable_AddItemText Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal pValue As String) As Long
Declare Function XAdapterTable_AddItemTextEx Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal pName As String, ByVal pValue As String) As Long
Declare Function XAdapterTable_AddItemImage Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal hImage As Long) As Long
Declare Function XAdapterTable_AddItemImageEx Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal pName As String, ByVal hImage As Long) As Long
Declare Function XAdapterTable_InsertItemText Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iItem As Long, ByVal pValue As String) As Boolean
Declare Function XAdapterTable_InsertItemTextEx Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iItem As Long, ByVal pName As String, ByVal pValue As String) As Boolean
Declare Function XAdapterTable_InsertItemImage Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iItem As Long, ByVal hImage As Long) As Boolean
Declare Function XAdapterTable_InsertItemImageEx Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iItem As Long, ByVal pName As String, ByVal hImage As Long) As Boolean
Declare Function XAdapterTable_SetItemText Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iItem As Long, ByVal iColumn As Long, ByVal pValue As String) As Boolean
Declare Function XAdapterTable_SetItemTextEx Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iItem As Long, ByVal pName As String, ByVal pValue As String) As Boolean
Declare Function XAdapterTable_SetItemImage Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iItem As Long, ByVal iColumn As Long, ByVal hImage As Long) As Boolean
Declare Function XAdapterTable_SetItemImageEx Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iItem As Long, ByVal pName As String, ByVal hImage As Long) As Boolean
Declare Function XAdapterTable_DeleteItem Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iItem As Long) As Boolean
Declare Function XAdapterTable_DeleteItemEx Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iItem As Long, ByVal nCount As Long) As Boolean
Declare Sub XAdapterTable_DeleteItemAll Lib "xcgui.dll" (ByVal hAdapter As Long)
Declare Sub XAdapterTable_DeleteColumnAll Lib "xcgui.dll" (ByVal hAdapter As Long)
Declare Function XAdapterTable_GetCount Lib "xcgui.dll" (ByVal hAdapter As Long) As Long
Declare Function XAdapterTable_GetCountColumn Lib "xcgui.dll" (ByVal hAdapter As Long) As Long
Declare Function XAdapterTable_GetItemText Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iItem As Long, ByVal iColumn As Long, ByVal pOut As Long, ByVal nOutLen As Long) As Boolean
Declare Function XAdapterTable_GetItemImage Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iItem As Long, ByVal iColumn As Long) As Long
Declare Function XAdapterTable_GetItemTextEx Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iItem As Long, ByVal pName As String, ByVal pOut As Long, ByVal nOutLen As Long) As Boolean
Declare Function XAdapterTable_GetItemImageEx Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal iItem As Long, ByVal pName As String) As Long
Declare Function XAdapterTree_Create Lib "xcgui.dll" () As Long
Declare Function XAdapterTree_AddColumn Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal pName As String) As Long
Declare Function XAdapterTree_SetColumn Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal pColName As String) As Long
Declare Function XAdapterTree_InsertItemText Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal pValue As String, ByVal nParentID As Long, ByVal insertID As Long) As Long
Declare Function XAdapterTree_InsertItemTextEx Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal pName As String, ByVal pValue As String, ByVal nParentID As Long, ByVal insertID As Long) As Long
Declare Function XAdapterTree_InsertItemImage Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal hImage As Long, ByVal nParentID As Long, ByVal insertID As Long) As Long
Declare Function XAdapterTree_InsertItemImageEx Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal pName As String, ByVal hImage As Long, ByVal nParentID As Long, ByVal insertID As Long) As Long
Declare Function XAdapterTree_GetCount Lib "xcgui.dll" (ByVal hAdapter As Long) As Long
Declare Function XAdapterTree_GetCountColumn Lib "xcgui.dll" (ByVal hAdapter As Long) As Long
Declare Function XAdapterTree_SetItemText Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal nID As Long, ByVal iColumn As Long, ByVal pValue As String) As Boolean
Declare Function XAdapterTree_SetItemTextEx Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal nID As Long, ByVal pName As String, ByVal pValue As String) As Boolean
Declare Function XAdapterTree_SetItemImage Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal nID As Long, ByVal iColumn As Long, ByVal hImage As Long) As Boolean
Declare Function XAdapterTree_SetItemImageEx Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal nID As Long, ByVal pName As String, ByVal hImage As Long) As Boolean
Declare Function XAdapterTree_GetItemTextEx Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal nID As Long, ByVal pName As String, ByVal pOut As Long, ByVal nOutLen As Long) As Boolean
Declare Function XAdapterTree_GetItemImageEx Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal nID As Long, ByVal pName As String) As Long
Declare Function XAdapterTree_DeleteItem Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal nID As Long) As Boolean
Declare Sub XAdapterTree_DeleteItemAll Lib "xcgui.dll" (ByVal hAdapter As Long)
Declare Sub XAdapterTree_DeleteColumnAll Lib "xcgui.dll" (ByVal hAdapter As Long)
Declare Function XAdapterMap_Create Lib "xcgui.dll" () As Long
Declare Function XAdapterMap_AddItemText Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal pName As String, ByVal pValue As String) As Boolean
Declare Function XAdapterMap_AddItemImage Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal pName As String, ByVal hImage As Long) As Boolean
Declare Function XAdapterMap_DeleteItem Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal pName As String) As Boolean
Declare Function XAdapterMap_GetCount Lib "xcgui.dll" (ByVal hAdapter As Long) As Long
Declare Function XAdapterMap_GetItemText Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal pName As String, ByVal pOut As Long, ByVal nOutLen As Long) As Boolean
Declare Function XAdapterMap_GetItemImage Lib "xcgui.dll" (ByVal hAdapter As Long, ByVal pName As String) As Long
'Declare Sub _XC_DebugPrintf Lib "xcgui.dll" (ByVal level As Long,ByVal pFormat As String,ByVal ���� As Long)
'Declare Sub _XC_DebugPrintfW Lib "xcgui.dll" (ByVal level As Long,ByVal pFormat As String,ByVal ���� As Long)
'Declare Sub xtrace Lib "xcgui.dll" (ByVal pFormat As String, ByVal ���� As Long)
'Declare Sub xtracew Lib "xcgui.dll" (ByVal pFormat As String, ByVal ���� As Long)
Declare Function XDraw_Create Lib "xcgui.dll" (ByVal hdc As Long) As Long
Declare Sub XDraw_Destroy Lib "xcgui.dll" (ByVal hDraw As Long)
Declare Sub XDraw_SetOffset Lib "xcgui.dll" (ByVal hDraw As Long, ByVal x As Long, ByVal y As Long)
Declare Sub XDraw_GetOffset Lib "xcgui.dll" (ByVal hDraw As Long, ByVal pX As Long, ByVal pY As Long)
Declare Sub XDraw_RestoreGDIOBJ Lib "xcgui.dll" (ByVal hDraw As Long)
Declare Function XDraw_GetHDC Lib "xcgui.dll" (ByVal hDraw As Long) As Long
Declare Sub XDraw_SetBrushColor Lib "xcgui.dll" (ByVal hDraw As Long, ByVal color As Long, ByVal alpha As Byte)
Declare Sub XDraw_SetTextAlign Lib "xcgui.dll" (ByVal hDraw As Long, ByVal nFlag As Long)
Declare Sub XDraw_SetTextVertical Lib "xcgui.dll" (ByVal hDraw As Long, ByVal bVertical As Boolean)
Declare Sub XDraw_SetFontX Lib "xcgui.dll" (ByVal hDraw As Long, ByVal hFontx As Long)
Declare Sub XDraw_SetFont Lib "xcgui.dll" (ByVal hDraw As Long, ByVal size As Long)
Declare Sub XDraw_SetFont2 Lib "xcgui.dll" (ByVal hDraw As Long, ByVal pName As String, ByVal size As Long)
Declare Sub XDraw_SetFont3 Lib "xcgui.dll" (ByVal hDraw As Long, ByVal pLogFont As LOGFONT)
Declare Sub XDraw_SetLineWidth Lib "xcgui.dll" (ByVal hDraw As Long, ByVal nWidth As Long)
Declare Function XDraw_SetBkMode Lib "xcgui.dll" (ByVal hDraw As Long, ByVal bTransparent As Boolean) As Long
Declare Sub XDraw_EnableSmoothingMode Lib "xcgui.dll" (ByVal hDraw As Long, ByVal bEnable As Boolean)
Declare Function XDraw_CreateSolidBrush Lib "xcgui.dll" (ByVal hDraw As Long, ByVal crColor As Long) As Long
Declare Function XDraw_CreatePen Lib "xcgui.dll" (ByVal hDraw As Long, ByVal fnPenStyle As Long, ByVal nWidth As Long, ByVal crColor As Long) As Long
Declare Function XDraw_CreateRectRgn Lib "xcgui.dll" (ByVal hDraw As Long, ByVal nLeftRect As Long, ByVal nTopRect As Long, ByVal nRightRect As Long, ByVal nBottomRect As Long) As Long
Declare Function XDraw_CreateRoundRectRgn Lib "xcgui.dll" (ByVal hDraw As Long, ByVal nLeftRect As Long, ByVal nTopRect As Long, ByVal nRightRect As Long, ByVal nBottomRect As Long, ByVal nWidthEllipse As Long, ByVal nHeightEllipse As Long) As Long
Declare Function XDraw_CreatePolygonRgn Lib "xcgui.dll" (ByVal hDraw As Long, ByVal pPt As Point, ByVal cPoints As Long, ByVal fnPolyFillMode As Long) As Long
Declare Function XDraw_SelectClipRgn Lib "xcgui.dll" (ByVal hDraw As Long, ByVal hrgn As Long) As Long
Declare Sub XDraw_FillRect Lib "xcgui.dll" (ByVal hDraw As Long, ByVal pRect As rect)
Declare Sub XDraw_FillRectColor Lib "xcgui.dll" (ByVal hDraw As Long, ByVal pRect As rect, ByVal color As Long, ByVal alpha As Byte)
Declare Function XDraw_FillRgn Lib "xcgui.dll" (ByVal hDraw As Long, ByVal hrgn As Long, ByVal hbr As Long) As Boolean
Declare Sub XDraw_FillEllipse Lib "xcgui.dll" (ByVal hDraw As Long, ByVal pRect As rect)
Declare Sub XDraw_DrawEllipse Lib "xcgui.dll" (ByVal hDraw As Long, ByVal pRect As rect)
Declare Sub XDraw_FillRoundRect Lib "xcgui.dll" (ByVal hDraw As Long, ByVal pRect As rect, ByVal nWidth As Long, ByVal nHeight As Long)
Declare Sub XDraw_DrawRoundRect Lib "xcgui.dll" (ByVal hDraw As Long, ByVal pRect As rect, ByVal nWidth As Long, ByVal nHeight As Long)
Declare Function XDraw_Rectangle Lib "xcgui.dll" (ByVal hDraw As Long, ByVal nLeftRect As Long, ByVal nTopRect As Long, ByVal nRightRect As Long, ByVal nBottomRect As Long) As Boolean
Declare Sub XDraw_DrawGroupBox_Rect Lib "xcgui.dll" (ByVal hDraw As Long, ByVal pRect As rect, ByVal pName As String, ByVal textColor As Long, ByVal textAlpha As Byte, ByVal pOffset As Point)
Declare Sub XDraw_DrawGroupBox_RoundRect Lib "xcgui.dll" (ByVal hDraw As Long, ByVal pRect As rect, ByVal pName As String, ByVal textColor As Long, ByVal textAlpha As Byte, ByVal pOffset As Point, ByVal nWidth As Long, ByVal nHeight As Long)
Declare Sub XDraw_GradientFill2 Lib "xcgui.dll" (ByVal hDraw As Long, ByVal color1 As Long, ByVal alpha1 As Byte, ByVal color2 As Long, ByVal alpha2 As Byte, ByVal pRect As rect, ByVal mode As Long)
Declare Function XDraw_GradientFill4 Lib "xcgui.dll" (ByVal hDraw As Long, ByVal color1 As Long, ByVal color2 As Long, ByVal color3 As Long, ByVal color4 As Long, ByVal pRect As rect, ByVal mode As Long) As Boolean
Declare Function XDraw_FrameRgn Lib "xcgui.dll" (ByVal hDraw As Long, ByVal hrgn As Long, ByVal hbr As Long, ByVal nWidth As Long, ByVal nHeight As Long) As Boolean
Declare Sub XDraw_FrameRect Lib "xcgui.dll" (ByVal hDraw As Long, ByVal pRect As rect)
Declare Sub XDraw_FocusRect Lib "xcgui.dll" (ByVal hDraw As Long, ByVal pRect As rect)
Declare Sub XDraw_DrawLine Lib "xcgui.dll" (ByVal hDraw As Long, ByVal x1 As Long, ByVal y1 As Long, ByVal x2 As Long, ByVal y2 As Long)
Declare Function XDraw_MoveToEx Lib "xcgui.dll" (ByVal hDraw As Long, ByVal x As Long, ByVal y As Long, ByVal lpPoint As Point) As Boolean
Declare Function XDraw_LineTo Lib "xcgui.dll" (ByVal hDraw As Long, ByVal nXEnd As Long, ByVal nYEnd As Long) As Boolean
Declare Function XDraw_Polyline Lib "xcgui.dll" (ByVal hDraw As Long, ByVal pArrayPt As Point, ByVal arrayPtSize As Long) As Boolean
Declare Sub XDraw_Dottedline Lib "xcgui.dll" (ByVal hDraw As Long, ByVal x1 As Long, ByVal y1 As Long, ByVal x2 As Long, ByVal y2 As Long)
Declare Function XDraw_SetPixel Lib "xcgui.dll" (ByVal hDraw As Long, ByVal x As Long, ByVal y As Long, ByVal crColor As Long) As Long
Declare Sub XDraw_Check Lib "xcgui.dll" (ByVal hDraw As Long, ByVal x As Long, ByVal y As Long, ByVal color As Long, ByVal bCheck As Boolean)
Declare Function XDraw_DrawIconEx Lib "xcgui.dll" (ByVal hDraw As Long, ByVal xLeft As Long, ByVal yTop As Long, ByVal hIcon As Long, ByVal cxWidth As Long, ByVal cyWidth As Long, ByVal istepIfAniCur As Long, ByVal hbrFlickerFreeDraw As Long, ByVal diFlags As Long) As Boolean
Declare Function XDraw_BitBlt Lib "xcgui.dll" (ByVal hDrawDest As Long, ByVal nXDest As Long, ByVal nYDest As Long, ByVal nWidth As Long, ByVal nHeight As Long, ByVal hdcSrc As Long, ByVal nXSrc As Long, ByVal nYSrc As Long, ByVal dwRop As Long) As Boolean
Declare Function XDraw_BitBlt2 Lib "xcgui.dll" (ByVal hDrawDest As Long, ByVal nXDest As Long, ByVal nYDest As Long, ByVal nWidth As Long, ByVal nHeight As Long, ByVal hDrawSrc As Long, ByVal nXSrc As Long, ByVal nYSrc As Long, ByVal dwRop As Long) As Boolean
Declare Function XDraw_AlphaBlend Lib "xcgui.dll" (ByVal hDraw As Long, ByVal nXOriginDest As Long, ByVal nYOriginDest As Long, ByVal nWidthDest As Long, ByVal nHeightDest As Long, ByVal hdcSrc As Long, ByVal nXOriginSrc As Long, ByVal nYOriginSrc As Long, ByVal nWidthSrc As Long, ByVal nHeightSrc As Long, ByVal alpha As Long) As Boolean
Declare Sub XDraw_TriangularArrow Lib "xcgui.dll" (ByVal hDraw As Long, ByVal align As Long, ByVal x As Long, ByVal y As Long, ByVal width As Long, ByVal height As Long)
Declare Sub XDraw_DrawPolygon Lib "xcgui.dll" (ByVal hDraw As Long, ByVal points As Point, ByVal nCount As Long)
Declare Sub XDraw_DrawPolygonF Lib "xcgui.dll" (ByVal hDraw As Long, ByVal points As POINTF, ByVal nCount As Long)
Declare Sub XDraw_FillPolygon Lib "xcgui.dll" (ByVal hDraw As Long, ByVal points As Point, ByVal nCount As Long)
Declare Sub XDraw_FillPolygonF Lib "xcgui.dll" (ByVal hDraw As Long, ByVal points As POINTF, ByVal nCount As Long)
Declare Sub XDraw_Image Lib "xcgui.dll" (ByVal hDraw As Long, ByVal hImage As Long, ByVal x As Long, ByVal y As Long)
Declare Sub XDraw_Image2 Lib "xcgui.dll" (ByVal hDraw As Long, ByVal hImage As Long, ByVal x As Long, ByVal y As Long, ByVal width As Long, ByVal height As Long)
Declare Sub XDraw_ImageStretch Lib "xcgui.dll" (ByVal hDraw As Long, ByVal hImage As Long, ByVal x As Long, ByVal y As Long, ByVal width As Long, ByVal height As Long)
Declare Sub XDraw_ImageAdaptive Lib "xcgui.dll" (ByVal hDraw As Long, ByVal hImage As Long, ByVal pRect As rect, ByVal bOnlyBorder As Boolean)
Declare Sub XDraw_ImageExTile Lib "xcgui.dll" (ByVal hDraw As Long, ByVal hImage As Long, ByVal pRect As rect, ByVal flag As Long)
Declare Sub XDraw_ImageSuper Lib "xcgui.dll" (ByVal hDraw As Long, ByVal hImage As Long, ByVal pRect As rect, ByVal bClip As Boolean)
Declare Sub XDraw_ImageSuper2 Lib "xcgui.dll" (ByVal hDraw As Long, ByVal hImage As Long, ByVal pRcDest As rect, ByVal pSrcRect As rect)
Declare Sub XDraw_DrawText Lib "xcgui.dll" (ByVal hDraw As Long, ByVal lpString As String, ByVal nCount As Long, ByVal lpRect As rect)
Declare Sub XDraw_DrawTextUnderline Lib "xcgui.dll" (ByVal hDraw As Long, ByVal lpString As String, ByVal nCount As Long, ByVal lpRect As rect, ByVal colorLine As Long, ByVal alphaLine As Byte)
Declare Sub XDraw_TextOut Lib "xcgui.dll" (ByVal hDraw As Long, ByVal nXStart As Long, ByVal nYStart As Long, ByVal lpString As String, ByVal cbString As Long)
Declare Sub XDraw_TextOutEx Lib "xcgui.dll" (ByVal hDraw As Long, ByVal nXStart As Long, ByVal nYStart As Long, ByVal lpString As String)
Declare Sub XDraw_TextOutA Lib "xcgui.dll" (ByVal hDraw As Long, ByVal nXStart As Long, ByVal nYStart As Long, ByVal lpString As String)
Declare Sub XDraw_SetAlpha Lib "xcgui.dll" (ByVal hDraw As Long, ByVal alpha As Byte)
Declare Sub XDraw_SetAlphaEx Lib "xcgui.dll" (ByVal hdc As Long, ByVal alpha As Byte)
Declare Function XEle_Create Lib "xcgui.dll" (ByVal x As Long, ByVal y As Long, ByVal cx As Long, ByVal cy As Long, ByVal hParent As Long) As Long
Declare Sub XEle_RegEventEx Lib "xcgui.dll" (ByVal hEle As Long, ByVal pEvent As Long)
Declare Function XEle_RemoveEventEx Lib "xcgui.dll" (ByVal hEle As Long, ByVal pEvent As Long) As Boolean
Declare Sub XEle_RegEventC Lib "xcgui.dll" (ByVal hEle As Long, ByVal nEvent As Long, ByVal pFun As Long)
Declare Sub XEle_RegEventC1 Lib "xcgui.dll" (ByVal hEle As Long, ByVal nEvent As Long, ByVal pFun As Long)
Declare Sub XEle_RegEventC2 Lib "xcgui.dll" (ByVal hEle As Long, ByVal nEvent As Long, ByVal pFun As Long)
Declare Function XEle_RemoveEventC Lib "xcgui.dll" (ByVal hEle As Long, ByVal nEvent As Long, ByVal pFun As Long) As Boolean
Declare Function XEle_SendEvent Lib "xcgui.dll" (ByVal hEle As Long, ByVal hEventEle As Long, ByVal nEvent As Long, ByVal wParam As Long, ByVal lParam As Long) As Long
Declare Function XEle_PostEvent Lib "xcgui.dll" (ByVal hEle As Long, ByVal hEventEle As Long, ByVal nEvent As Long, ByVal wParam As Long, ByVal lParam As Long) As Boolean
Declare Function XEle_IsShow Lib "xcgui.dll" (ByVal hEle As Long) As Boolean
Declare Function XEle_IsEnable Lib "xcgui.dll" (ByVal hEle As Long) As Boolean
Declare Function XEle_IsEnableFocus Lib "xcgui.dll" (ByVal hEle As Long) As Boolean
Declare Function XEle_IsDrawFocus Lib "xcgui.dll" (ByVal hEle As Long) As Boolean
Declare Function XEle_IsEnableEvent_XE_PAINT_END Lib "xcgui.dll" (ByVal hEle As Long) As Boolean
Declare Function XEle_IsMouseThrough Lib "xcgui.dll" (ByVal hEle As Long) As Boolean
Declare Function XEle_IsBkTransparent Lib "xcgui.dll" (ByVal hEle As Long) As Boolean
Declare Function XEle_IsKeyTab Lib "xcgui.dll" (ByVal hEle As Long) As Boolean
Declare Function XEle_IsSwitchFocus Lib "xcgui.dll" (ByVal hEle As Long) As Boolean
Declare Function XEle_IsEnable_XE_MOUSEWHEEL Lib "xcgui.dll" (ByVal hEle As Long) As Boolean
Declare Sub XEle_Enable Lib "xcgui.dll" (ByVal hEle As Long, ByVal bEnable As Boolean)
Declare Sub XEle_EnableFocus Lib "xcgui.dll" (ByVal hEle As Long, ByVal bEnable As Boolean)
Declare Sub XEle_EnableDrawFocus Lib "xcgui.dll" (ByVal hEle As Long, ByVal bEnable As Boolean)
Declare Sub XEle_EnableEvent_XE_PAINT_END Lib "xcgui.dll" (ByVal hEle As Long, ByVal bEnable As Boolean)
Declare Sub XEle_EnableBkTransparent Lib "xcgui.dll" (ByVal hEle As Long, ByVal bEnable As Boolean)
Declare Sub XEle_EnableMouseThrough Lib "xcgui.dll" (ByVal hEle As Long, ByVal bEnable As Boolean)
Declare Sub XEle_EnableKeyTab Lib "xcgui.dll" (ByVal hEle As Long, ByVal bEnable As Boolean)
Declare Sub XEle_EnableSwitchFocus Lib "xcgui.dll" (ByVal hEle As Long, ByVal bEnable As Boolean)
Declare Sub XEle_EnableEvent_XE_MOUSEWHEEL Lib "xcgui.dll" (ByVal hEle As Long, ByVal bEnable As Boolean)
Declare Function XEle_SetRect Lib "xcgui.dll" (ByVal hEle As Long, ByVal pRect As rect, ByVal bRedraw As Boolean) As Boolean
Declare Function XEle_SetRectEx Lib "xcgui.dll" (ByVal hEle As Long, ByVal x As Long, ByVal y As Long, ByVal cx As Long, ByVal cy As Long, ByVal bRedraw As Boolean) As Boolean
Declare Function XEle_SetRectLogic Lib "xcgui.dll" (ByVal hEle As Long, ByVal pRect As rect, ByVal bRedraw As Boolean) As Boolean
Declare Sub XEle_GetRect Lib "xcgui.dll" (ByVal hEle As Long, ByVal pRect As rect)
Declare Sub XEle_GetRectLogic Lib "xcgui.dll" (ByVal hEle As Long, ByVal pRect As rect)
Declare Sub XEle_GetClientRect Lib "xcgui.dll" (ByVal hEle As Long, ByVal pRect As rect)
Declare Sub XEle_GetWndClientRect Lib "xcgui.dll" (ByVal hEle As Long, ByVal pRect As rect)
Declare Function XEle_GetWidth Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Function XEle_GetHeight Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XEle_RectWndClientToEleClient Lib "xcgui.dll" (ByVal hEle As Long, ByVal pRect As rect)
Declare Sub XEle_PointWndClientToEleClient Lib "xcgui.dll" (ByVal hEle As Long, ByVal pPt As Point)
Declare Sub XEle_RectClientToWndClient Lib "xcgui.dll" (ByVal hEle As Long, ByVal pRect As rect)
Declare Sub XEle_PointClientToWndClient Lib "xcgui.dll" (ByVal hEle As Long, ByVal pPt As Point)
Declare Function XEle_AddEle Lib "xcgui.dll" (ByVal hEle As Long, ByVal hChildEle As Long) As Boolean
Declare Function XEle_InsertEle Lib "xcgui.dll" (ByVal hEle As Long, ByVal hChildEle As Long, ByVal index As Long) As Boolean
Declare Sub XEle_RemoveEle Lib "xcgui.dll" (ByVal hEle As Long)
Declare Function XEle_AddShape Lib "xcgui.dll" (ByVal hEle As Long, ByVal hShape As Long) As Boolean
Declare Function XEle_SetZOrder Lib "xcgui.dll" (ByVal hEle As Long, ByVal index As Long) As Boolean
Declare Function XEle_SetZOrderEx Lib "xcgui.dll" (ByVal hEle As Long, ByVal hDestEle As Long, ByVal nType As Long) As Boolean
Declare Function XEle_GetZOrder Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XEle_ShowEle Lib "xcgui.dll" (ByVal hEle As Long, ByVal bShow As Boolean)
Declare Function XEle_GetType Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Function XEle_GetHWND Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Function XEle_GetHWINDOW Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XEle_SetCursor Lib "xcgui.dll" (ByVal hEle As Long, ByVal hCursor As Long)
Declare Function XEle_GetCursor Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XEle_SetID Lib "xcgui.dll" (ByVal hEle As Long, ByVal id As Long)
Declare Function XEle_GetID Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Function XEle_GetParentEle Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Function XEle_GetParent Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XEle_SetTextColor Lib "xcgui.dll" (ByVal hEle As Long, ByVal color As Long, ByVal alpha As Byte)
Declare Function XEle_GetTextColor Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XEle_SetFocusBorderColor Lib "xcgui.dll" (ByVal hEle As Long, ByVal color As Long, ByVal alpha As Byte)
Declare Function XEle_GetFocusBorderColor Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XEle_SetFont Lib "xcgui.dll" (ByVal hEle As Long, ByVal hFontx As Long)
Declare Function XEle_GetFont Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XEle_SetAlpha Lib "xcgui.dll" (ByVal hEle As Long, ByVal alpha As Byte)
Declare Function XEle_GetChildCount Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Function XEle_GetChildByIndex Lib "xcgui.dll" (ByVal hEle As Long, ByVal index As Long) As Long
Declare Function XEle_GetChildByID Lib "xcgui.dll" (ByVal hEle As Long, ByVal id As Long) As Long
Declare Function XEle_GetChildShapeCount Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Function XEle_GetChildShapeByIndex Lib "xcgui.dll" (ByVal hEle As Long, ByVal index As Long) As Long
Declare Function XEle_HitChildEle Lib "xcgui.dll" (ByVal hEle As Long, ByVal pPt As Point) As Long
Declare Sub XEle_BindLayoutObject Lib "xcgui.dll" (ByVal hEle As Long, ByVal hLayout As Long)
Declare Function XEle_GetLayoutObject Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Function XEle_GetParentLayoutObject Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XEle_SetUserData Lib "xcgui.dll" (ByVal hEle As Long, ByVal nData As Long)
Declare Function XEle_GetUserData Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XEle_GetContentSize Lib "xcgui.dll" (ByVal hEle As Long, ByVal pSize As size)
Declare Sub XEle_SetCapture Lib "xcgui.dll" (ByVal hEle As Long, ByVal b As Boolean)
Declare Sub XEle_SetLayoutWidth Lib "xcgui.dll" (ByVal hEle As Long, ByVal nType As Long, ByVal nWidth As Long)
Declare Sub XEle_SetLayoutHeight Lib "xcgui.dll" (ByVal hEle As Long, ByVal nType As Long, ByVal nHeight As Long)
Declare Sub XEle_GetLayoutWidth Lib "xcgui.dll" (ByVal hEle As Long, ByVal pType As Long, ByVal pWidth As Long)
Declare Sub XEle_GetLayoutHeight Lib "xcgui.dll" (ByVal hEle As Long, ByVal pType As Long, ByVal pHeight As Long)
Declare Sub XEle_RedrawEle Lib "xcgui.dll" (ByVal hEle As Long, ByVal bImmediate As Boolean)
Declare Sub XEle_RedrawRect Lib "xcgui.dll" (ByVal hEle As Long, ByVal pRect As rect, ByVal bImmediate As Boolean)
Declare Sub XEle_Destroy Lib "xcgui.dll" (ByVal hEle As Long)
Declare Sub XEle_AddBkBorder Lib "xcgui.dll" (ByVal hEle As Long, ByVal color As Long, ByVal alpha As Byte, ByVal width As Long)
Declare Sub XEle_AddBkFill Lib "xcgui.dll" (ByVal hEle As Long, ByVal color As Long, ByVal alpha As Byte)
Declare Sub XEle_AddBkImage Lib "xcgui.dll" (ByVal hEle As Long, ByVal hImage As Long)
Declare Function XEle_GetBkInfoCount Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Sub XEle_ClearBkInfo Lib "xcgui.dll" (ByVal hEle As Long)
Declare Function XEle_GetBkInfoManager Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Function XEle_GetStateFlags Lib "xcgui.dll" (ByVal hEle As Long) As Long
Declare Function XEle_DrawFocus Lib "xcgui.dll" (ByVal hEle As Long, ByVal hDraw As Long, ByVal pRect As rect) As Boolean
Declare Sub XEle_EnableTransparentChannel Lib "xcgui.dll" (ByVal hEle As Long, ByVal bEnable As Boolean)
Declare Sub XEle_SetToolTip Lib "xcgui.dll" (ByVal hEle As Long, ByVal pText As String)
Declare Sub XEle_GetToolTip Lib "xcgui.dll" (ByVal hEle As Long, ByVal pOut As Long, ByVal nOutLen As Long)
Declare Sub XEle_EnableToolTip Lib "xcgui.dll" (ByVal hEle As Long, ByVal bEnable As Boolean)
Declare Sub XEle_AdjustLayoutObject Lib "xcgui.dll" (ByVal hEle As Long)
Declare Sub XEle_AdjustLayout Lib "xcgui.dll" (ByVal hEle As Long)
Declare Function XEle_RegEventTest Lib "xcgui.dll" (ByVal nEvent As Long, ByVal pParamType As Long) As Boolean
Declare Function XFont_Create Lib "xcgui.dll" (ByVal size As Long) As Long
Declare Function XFont_Create2 Lib "xcgui.dll" (ByVal pName As String, ByVal size As Long, ByVal bBold As Boolean, ByVal bItalic As Boolean, ByVal bUnderline As Boolean, ByVal bStrikeOut As Boolean) As Long
Declare Function XFont_Create3 Lib "xcgui.dll" (ByVal pInfo As xc_font_info_i) As Long
Declare Function XFont_CreateEx Lib "xcgui.dll" (ByVal pFontInfo As LOGFONTW) As Long
Declare Function XFont_CreateFromHFONT Lib "xcgui.dll" (ByVal hFont As Long) As Long
Declare Function XFont_CreateFromFont Lib "xcgui.dll" (ByVal pFont As Long) As Long
Declare Sub XFont_EnableAutoDestroy Lib "xcgui.dll" (ByVal hFontx As Long, ByVal bEnable As Boolean)
Declare Function XFont_GetFont Lib "xcgui.dll" (ByVal hFontx As Long) As Long
Declare Sub XFont_GetFontInfo Lib "xcgui.dll" (ByVal hFontx As Long, ByVal pInfo As xc_font_info_i)
Declare Sub XFont_AddRef Lib "xcgui.dll" (ByVal hFontx As Long)
Declare Sub XFont_Release Lib "xcgui.dll" (ByVal hFontx As Long)
Declare Function XFont_GetRefCount Lib "xcgui.dll" (ByVal hFontx As Long) As Long
Declare Sub XFont_Destroy Lib "xcgui.dll" (ByVal hFontx As Long)
Declare Function XFrameWnd_Create Lib "xcgui.dll" (ByVal x As Long, ByVal y As Long, ByVal cx As Long, ByVal cy As Long, ByVal pTitle As String, ByVal hWndParent As Long, ByVal XCStyle As Long) As Long
Declare Function XFrameWnd_CreateEx Lib "xcgui.dll" (ByVal dwExStyle As Long, ByVal lpClassName As String, ByVal lpWindowName As String, ByVal dwStyle As Long, ByVal x As Long, ByVal y As Long, ByVal cx As Long, ByVal cy As Long, ByVal hWndParent As Long, ByVal XCStyle As Long) As Long
Declare Sub XFrameWnd_GetLayoutAreaRect Lib "xcgui.dll" (ByVal hWindow As Long, ByVal pRect As rect)
Declare Sub XFrameWnd_SetView Lib "xcgui.dll" (ByVal hWindow As Long, ByVal hEle As Long)
Declare Sub XFrameWnd_SetPaneSplitBarColor Lib "xcgui.dll" (ByVal hWindow As Long, ByVal color As Long, ByVal alpha As Byte)
Declare Function XFrameWnd_AddPane Lib "xcgui.dll" (ByVal hWindow As Long, ByVal hPaneDest As Long, ByVal hPaneNew As Long, ByVal align As Long) As Boolean
Declare Function XFrameWnd_MergePane Lib "xcgui.dll" (ByVal hWindow As Long, ByVal hPaneDest As Long, ByVal hPaneNew As Long) As Boolean
Declare Function XImage_LoadFile Lib "xcgui.dll" (ByVal pImageName As String, ByVal bStretch As Boolean) As Long
Declare Function XImage_LoadFileAdaptive Lib "xcgui.dll" (ByVal pImageName As String, ByVal leftSize As Long, ByVal topSize As Long, ByVal rightSize As Long, ByVal bottomSize As Long) As Long
Declare Function XImage_LoadFileRect Lib "xcgui.dll" (ByVal pImageName As String, ByVal x As Long, ByVal y As Long, ByVal cx As Long, ByVal cy As Long) As Long
Declare Function XImage_LoadResAdaptive Lib "xcgui.dll" (ByVal id As Long, ByVal pType As String, ByVal leftSize As Long, ByVal topSize As Long, ByVal rightSize As Long, ByVal bottomSize As Long) As Long
Declare Function XImage_LoadRes Lib "xcgui.dll" (ByVal id As Long, ByVal pType As String, ByVal bStretch As Boolean) As Long
Declare Function XImage_LoadZip Lib "xcgui.dll" (ByVal pZipFileName As String, ByVal pImageName As String, ByVal pPassword As String, ByVal bStretch As Boolean) As Long
Declare Function XImage_LoadZipAdaptive Lib "xcgui.dll" (ByVal pZipFileName As String, ByVal pImageName As String, ByVal pPassword As String, ByVal x1 As Long, ByVal x2 As Long, ByVal y1 As Long, ByVal y2 As Long) As Long
Declare Function XImage_LoadZipRect Lib "xcgui.dll" (ByVal pZipFileName As String, ByVal pImageName As String, ByVal pPassword As String, ByVal x As Long, ByVal y As Long, ByVal cx As Long, ByVal cy As Long) As Long
Declare Function XImage_LoadMemory Lib "xcgui.dll" (ByVal pBuffer As Long, ByVal nSize As Long, ByVal bStretch As Boolean) As Long
Declare Function XImage_LoadMemoryRect Lib "xcgui.dll" (ByVal pBuffer As Long, ByVal nSize As Long, ByVal x As Long, ByVal y As Long, ByVal cx As Long, ByVal cy As Long, ByVal bStretch As Boolean) As Long
Declare Function XImage_LoadMemoryAdaptive Lib "xcgui.dll" (ByVal pBuffer As Long, ByVal nSize As Long, ByVal leftSize As Long, ByVal topSize As Long, ByVal rightSize As Long, ByVal bottomSize As Long) As Long
Declare Function XImage_LoadFromImage Lib "xcgui.dll" (ByVal pImage As Long) As Long
Declare Function XImage_LoadFileFromExtractIcon Lib "xcgui.dll" (ByVal pImageName As String) As Long
Declare Function XImage_LoadFileFromHICON Lib "xcgui.dll" (ByVal hIcon As Long) As Long
Declare Function XImage_LoadFileFromHBITMAP Lib "xcgui.dll" (ByVal hBitmap As Long) As Long
Declare Function XImage_IsStretch Lib "xcgui.dll" (ByVal hImage As Long) As Boolean
Declare Function XImage_IsAdaptive Lib "xcgui.dll" (ByVal hImage As Long) As Boolean
Declare Function XImage_IsTile Lib "xcgui.dll" (ByVal hImage As Long) As Boolean
Declare Function XImage_SetDrawType Lib "xcgui.dll" (ByVal hImage As Long, ByVal nType As Long) As Boolean
Declare Function XImage_SetDrawTypeAdaptive Lib "xcgui.dll" (ByVal hImage As Long, ByVal leftSize As Long, ByVal topSize As Long, ByVal rightSize As Long, ByVal bottomSize As Long) As Boolean
Declare Sub XImage_SetTranColor Lib "xcgui.dll" (ByVal hImage As Long, ByVal color As Long)
Declare Sub XImage_SetTranColorEx Lib "xcgui.dll" (ByVal hImage As Long, ByVal color As Long, ByVal tranColor As Byte)
Declare Function XImage_SetRotateAngle Lib "xcgui.dll" (ByVal hImage As Long, ByVal fAngle As Single) As Single
Declare Sub XImage_EnableTranColor Lib "xcgui.dll" (ByVal hImage As Long, ByVal bEnable As Boolean)
Declare Sub XImage_EnableAutoDestroy Lib "xcgui.dll" (ByVal hImage As Long, ByVal bEnable As Boolean)
Declare Sub XImage_EnableCenter Lib "xcgui.dll" (ByVal hImage As Long, ByVal bCenter As Boolean)
Declare Function XImage_IsCenter Lib "xcgui.dll" (ByVal hImage As Long) As Boolean
Declare Function XImage_GetDrawType Lib "xcgui.dll" (ByVal hImage As Long) As Long
Declare Function XImage_GetWidth Lib "xcgui.dll" (ByVal hImage As Long) As Long
Declare Function XImage_GetHeight Lib "xcgui.dll" (ByVal hImage As Long) As Long
Declare Sub XImage_AddRef Lib "xcgui.dll" (ByVal hImage As Long)
Declare Sub XImage_Release Lib "xcgui.dll" (ByVal hImage As Long)
Declare Function XImage_GetRefCount Lib "xcgui.dll" (ByVal hImage As Long) As Long
Declare Sub XImage_Destroy Lib "xcgui.dll" (ByVal hImage As Long)



'
'
'vb6���������������¼���:
'Boolean�������� ���� �����洢Ϊ 16 λ       ֻ���� True ���� False
'Byte�������� �������������洢Ϊ 8 λ         ��Χ�� 0 �� 255 ֮��
'Currency�������� ���������洢Ϊ 64 λ      ��Χ���Դ� -922,337,203,685,477.5808 �� 922,337,203,685,477.5807
'Date�������� �������������洢Ϊ  64 λ
'                              ���ڷ�Χ�� 100 �� 1 �� 1 �յ� 9999 �� 12 �� 31 �գ�
'                              ʱ����Դ� 0:00:00 �� 23:59:59��
'
'Decimal�������͡���  �����洢Ϊ 96 λ
'
'Double�������� ����  �����洢Ϊ 64 λ
'Integer�������� ����  �����洢Ϊ 16 λ������ΧΪ -32,768 �� 32,767 ֮��
'Long�������� �������������洢Ϊ 32 λ������Χ�� -2,147,483,648 �� 2,147,483,647
'Object�������� �������洢Ϊ 32 λ��4 ���ֽڣ��ĵ�ַ��ʽ
'Single��������          �����洢Ϊ IEEE 32 λ
'
'String�������� �ַ���������: �䳤�붨�����ַ���?
'                              �䳤�ַ������ɰ�����Լ 20 �� ( 2^31)���ַ���
'                              �����ַ����ɰ��� 1 ����Լ 64K ( 2^16 ) ���ַ���
'�û�������������
'Variant��������
'----------------------------------
'Boolean�������� Boolean �����洢Ϊ 16 λ��2 ���ֽڣ�����ֵ��ʽ����ֻ���� True ���� False��Boolean ������ֵ��ʾΪ True �� False����ʹ�� Print ��ʱ�򣩣����� #TRUE# �� #FALSE#����ʹ�� Write # ��ʱ�򣩡�ʹ�ùؼ��� True �� False �ɽ� Boolean ������ֵΪ������״̬�е�һ����
'��ת����������ֵ����Ϊ Boolean ֵʱ��0 ��ת�� False����������ֵ���� True����ת�� Boolean ֵΪ��������������ʱ��False ��Ϊ 0���� True ��Ϊ -1��
'------------------------------------
'Byte��������
'Byte �����洢Ϊ�������͡��޷������͡�8 λ��1���ֽڣ�����ֵ��ʽ����Χ�� 0 �� 255 ֮�䡣
'Byte ���������ڴ洢����������ʱ�����á�
'------------------------------------
'Currency��������
'Currency �����洢Ϊ 64 λ��8 ���ֽڣ����͵���ֵ��ʽ��Ȼ����� 10,000 ����һ������������С��������� 15 λ���֣��ұ��� 4 λ���֡����ֱ�ʾ���ķ�Χ���Դ� -922,337,203,685,477.5808 �� 922,337,203,685,477.5807��Currency �����������ַ�Ϊat�� (@)��
'Currency ���������ڻ��Ҽ����붨������к����ã������ֳ��Ͼ����ر���Ҫ��
'------------------------------------
'Date��������
'Date �����洢Ϊ IEEE 64 λ��8 ���ֽڣ�������ֵ��ʽ������Ա�ʾ�����ڷ�Χ�� 100 �� 1 �� 1 �յ� 9999 �� 12 �� 31 �գ���ʱ����Դ� 0:00:00 �� 23:59:59���κοɱ��ϵ��ı����ڶ����Ը�ֵ�� Date ���������������������ַ��� (#) �����������磬#January 1, 1993# �� #1 Jan 93#��
'Date ��������ݼ�����еĶ����ڸ�ʽ����ʾ��ʱ������ݼ������ʱ���ʽ��12 �� 24 Сʱ�ƣ�����ʾ��
'����������ֵ����Ҫת��Ϊ Date ��ʱ��С������ߵ�ֵ��ʾ������Ϣ����С�����ұߵ�ֵ���ʾʱ�䡣��ҹΪ 0 ������Ϊ 0.5����������ʾ 1899 �� 12 �� 30 ��֮ǰ�����ڡ�
'------------------------------------------
'Decimal��������
'Decimal �����洢Ϊ 96 λ��12 ���ֽڣ��޷��ŵ�������ʽ��������һ�� 10 �����������������Ӿ�����С�������������λ�����䷶Χ�� 0 �� 28���������Ϊ 0��û��С��λ���������£����Ŀ���ֵΪ +/-79,228,162,514,264,337,593,543,950,335�������� 28 ��С��λ������£����ֵΪ +/-7.9228162514264337593543950335������С�ķ���ֵΪ +/-0.0000000000000000000000000001��
'ע�� ��ʱ��Decimal ��������ֻ���� Variant��ʹ�ã�Ҳ����˵����������һ����Ϊ Decimal �����͡��������� Cdec ����������һ��������Ϊ Decimal �� Variant��
'-------------------------------------------
'Double��������
'Double��˫���ȸ����ͣ������洢Ϊ IEEE 64 λ��8 ���ֽڣ�������ֵ����ʽ�����ķ�Χ�ڸ�����ʱ���Ǵ� -1.79769313486232E308 �� -4.94065645841247E-324����������ʱ���Ǵ� 4.94065645841247E-324 �� 1.79769313486232E308��Double �����������ַ������ַ��� (#)��
'-------------------------------------------
'Integer��������
'Integer �����洢Ϊ 16λ��2 ���ֽڣ�����ֵ��ʽ���䷶ΧΪ -32,768 �� 32,767 ֮�䡣Integer �����������ַ��ǰٷֱȷ��� (%)��
'Ҳ������ Integer ��������ʾö��ֵ��ö��ֵ�ɰ���һ�����޼��ϣ��ü��ϰ�����Ԫ�ض���Ψһ��������ÿһ������������ʹ��ʱ�������ĵ��������������塣ö��ֵΪ����֪������ѡ��������ѡ���ṩ��һ�ַ���ķ��������磬black = 0��white = 1 �ȵȡ��Ϻõı��������ʹ�� Const ��佫ÿ��ö��ֵ����ɳ�����
'---------------------------------------------
'Long��������
'Long�������ͣ������洢Ϊ 32 λ��4 ���ֽڣ��з��ŵ���ֵ��ʽ���䷶Χ�� -2,147,483,648 �� 2,147,483,647��Long �����������ַ�Ϊ�ͺ� (&)��
'---------------------------------------------
'Object��������
'Object �����洢Ϊ 32 λ��4 ���ֽڣ��ĵ�ַ��ʽ����Ϊ��������á����� Set ��䣬����Ϊ Object �ı������Ը�ֵΪ�κζ�������á�
'ע�� ��Ȼ�� Object ���������ı���������Ӧ�����Ը��ֶ�������ã����ǰ󶨵��������õĶ������������ڣ�����ʱ���󶨡�Ҫǿ�������ڣ�����ʱ�䣩�󶨵Ļ����뽫��������ø�ֵ�����ض������������ı�����
'-----------------------------------------------
'Single��������
'Single�������ȸ����ͣ������洢Ϊ IEEE 32 λ��4 ���ֽڣ�������ֵ����ʽ�����ķ�Χ�ڸ�����ʱ���Ǵ� -3.402823E38 �� -1.401298E-45������������ʱ���Ǵ� 1.401298E-45 �� 3.402823E38��Single �����������ַ�Ϊ��̾�� (!)��
'------------------------------------------------
'String��������
'�ַ���������: �䳤�붨�����ַ���?
'�䳤�ַ������ɰ�����Լ 20 �� ( 2^31)���ַ���
'�����ַ����ɰ��� 1 ����Լ 64K ( 2^16 ) ���ַ���
'ע�� Public �����ַ�����������ģ����ʹ�á�
'String ֮�ַ���ķ�Χ�� 0 �� 255���ַ�����ǰ 128 ���ַ���0 �� 127����Ӧ�ڱ�׼�� U.S. �����ϵ��ַ�����š���ǰ 128 ���ַ��� ASCII �ַ��������������ͬ���� 128 ���ַ���128 �� 255������������ַ�����������ַ����������ţ����ҷ��ż�������String �����������ַ�Ϊ��Ԫ�� ($)��
'---------------------------------------------------
'Variant��������
'
'Variant ��������������û����ʽ���������� Dim��Private��Public �� Static����䣩Ϊ�������ͱ������������͡�Variant �������Ͳ�û�����������ַ���
'
'Variant ��һ��������������ͣ����˶��� String ���ݼ��û����������⣬���԰����κ���������ݡ�Variant Ҳ���԰��� Empty��Error��Nothing �� Null������ֵ�������� VarType ������ TypeName ������������δ��� Variant �е����ݡ�
'
'��ֵ���ݿ������κ����ͻ�ʵ����������ʱ��Χ�� -1.797693134862315E308 �� -4.94066E-324������ʱ��� 4.94066E-324 �� 1.797693134862315E308��ͨ������ֵVariant ���ݱ���Ϊ�� Variant ��ԭ�����������͡����磬�����һ�� Integer��ֵ�� Variant����������������Ѵ� Variant ���� Integer ������Ȼ�����������������Ժ� Byte��Integer��Long �� Single ֮һ��Variant ִ�У������������ԭ���������͵�������Χʱ������ Variant �еĽ�����������ϴ���������͡��� Byte �������� Integer��Integer �������� Long���� Long��Single ������Ϊ Double���� Variant �������� Currency��Decimal �� Double ֵ�������Ǹ��Եķ�Χʱ���ᷢ������
'
'������ Variant �����������滻�κ��������ͣ������������Ӧ�ԡ���� Variant ���������������֣����������ַ�������ʾ���ֻ�������ʵ�ʵ�ֵ����ʾ���⽫�������������������磺
'
'Dim MyVar As Variant
'MyVar = 98052
'
'��ǰ��������У�MyVar ����һʵ��ֵΪ 98052 ����ֵ�������������������������ӿ��Զ� Variant �������㣬���а�����ֵ���ܱ�����Ϊ��ֵ���ַ������ݡ������ + ���������� MyVar �������������ֵ� Variant ����ֵ���͵ı�����ӣ��������һ�����͡�
'
'Empty ֵ���������δ��ʼ����������ʼֵ����Variant �������ں� Empty �� Variant ����ֵ���������б�ʾ 0������������ַ����������������ʾ�㳤�ȵ��ַ��� ("")��
'
'��Ӧ�� Empty �� Null Ū�졣Null �Ǳ�ʾ Variant ����ȷʵ����һ����Ч���ݡ�
'
'�� Variant �У�Error ������ָʾ�ڹ����г��ִ���ʱ������ֵ��Ȼ�����������������Ĵ������������򲢲�������ͨ��Ӧ�ó��򼶵Ĵ�����������ó���Ա����Ӧ�ó��������ݴ˴���ֵ��ȡ������ж��������� CVErr ������ʵ��ת��Ϊ����ֵ������ Error ֵ��
'--------------------------------------------------
'�û�������������
'
'�������κ��� Type ��䶨����������͡��û��Զ������Ϳɰ���һ������ĳ���������͵�����Ԫ�ء������һ����ǰ������û��Զ������͡����磺
'
'Type MyType
'  MyName As String  '�����ַ��������洢һ�����֡�
'  MyBirthDate As Date  '�������ڱ����洢һ�����ա�
'  MySex As Integer  '�������ͱ����洢�Ա�
'End Type            '��0 ΪŮ��1 Ϊ�У�
'
'
