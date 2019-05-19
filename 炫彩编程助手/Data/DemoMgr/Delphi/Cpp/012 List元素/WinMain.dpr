program WinMain;

{$APPTYPE GUI}

uses
  Windows,SysUtils,
  XCGUI in 'XCGUI.pas';


var
  hWindow : Integer ;
  hList : Integer ;
  hAdapterHeader : Integer;
  hAdapterBody   : Integer;
begin

  { TODO -oUser -cConsole Main : Insert code here }
  XInitXCGUI(nil) ; //��ʼ����Դ
  hWindow := XWnd_Create(0,0,500,300,'��ɫ����',0,15);  //��������

  hList := XList_Create(0,0,500,300,hWindow);
  XList_SetItemTemplateXML(hList,'List_Item.xml');
  XList_AddColumn(hList,150);

  hAdapterHeader := XAdMap_Create();
  XList_BindAdapterHeader(hList,hAdapterHeader);
  XAdMap_AddItemText(hAdapterHeader,'name','aaaa');

  hAdapterBody := XAdTable_Create();
  XList_BindAdapter(hList,hAdapterBody);
  XAdTable_AddColumn(hAdapterBody,'name');
  XList_SetColumnWidth(hList,0,150);


  //XAdTable_InsertItemText()
  XAdTable_AddItemText(hAdapterBody,'dasemimi');


  XWnd_ShowWindow(hWindow,5);      //��ʾ����
  XRunXCGUI();                     //���г���
  XExitXCGUI();                    //������Դ
end.




