Attribute VB_Name = "XCConst"

Public Const XC_ERROR                               As Long = -1 '///<��������

Public Const XC_WINDOW                              As Long = 1 '///<����

Public Const XC_MODALWINDOW                         As Long = 2 '///<ģ̬����

Public Const XC_FRAMEWND                            As Long = 3 '///<��ܴ���

Public Const XC_FLOATWND                            As Long = 4 '///<��������

Public Const XC_COMBOBOXWINDOW                      As Long = 11 '//comboBoxWindow_        ��Ͽ򵯳������б���

Public Const XC_POPUPMENUWINDOW                     As Long = 12 '//popupMenuWindow_       �����˵�������

Public Const XC_POPUPMENUCHILDWINDOW                As Long = 13 '//popupMenuChildWindow_  �����˵��Ӵ���

Public Const XC_ELE                                 As Long = 21 '///<����Ԫ��

Public Const XC_BUTTON                              As Long = 22 '///<��ť

Public Const XC_RICHEDIT                            As Long = 23 '///<���ı��༭��

Public Const XC_COMBOBOX                            As Long = 24 '///<������Ͽ�Ԫ��

Public Const XC_SCROLLBAR                           As Long = 25 '///<������Ԫ��

Public Const XC_SCROLLVIEW                          As Long = 26 '///<������ͼԪ��

Public Const XC_LIST                                As Long = 27 '///<�б�Ԫ��

Public Const XC_LISTBOX                             As Long = 28 '///<�б��Ԫ��

Public Const XC_LISTVIEW                            As Long = 29 '��ͼ��

Public Const XC_TREE                                As Long = 30 '///<��Ԫ��

Public Const XC_MENUBAR                             As Long = 31 '///<�˵���

Public Const XC_SLIDERBAR                           As Long = 32 '///<������

Public Const XC_PROGRESSBAR                         As Long = 33 '///<������

Public Const XC_TOOLBAR                             As Long = 34 '///<������

Public Const XC_MONTHCAL                            As Long = 35 '///<����Ԫ��

Public Const XC_DATETIME                            As Long = 36 '///<ʱ��Ԫ��

Public Const XC_PROPERTYGRID                        As Long = 37 '///<��������

Public Const XC_RICHEDIT_COLOR                      As Long = 38 '///<��ɫѡ��Ԫ��

Public Const XC_RICHEDIT_SET                        As Long = 39 '

Public Const XC_TABBAR                              As Long = 40 '///<tab��

Public Const XC_TEXTLINK                            As Long = 41 '///<�ı����Ӱ�ť

Public Const XC_PANE                                As Long = 42 '///<���ִ���

Public Const XC_PANE_SPLIT                          As Long = 43 '///<���ִ����϶��ָ���

Public Const XC_MENUBAR_BUTTON                      As Long = 44 '///<�˵����ϵİ�ť

Public Const XC_TOOLBAR_BUTTON                      As Long = 45 '///<�������ϰ�ť

Public Const XC_PROPERTYPAGE_LABEL                  As Long = 46 '///<����ҳ��ǩ��ť

Public Const XC_PIER                                As Long = 47 '///<����ͣ����ͷ

Public Const XC_BUTTON_MENU                         As Long = 48 '///<�����˵���ť

Public Const XC_VIRTUAL_ELE                         As Long = 49 '///<����Ԫ��

Public Const XC_RICHEDIT_FILE                       As Long = 50 '///<RichEditFile �ļ�ѡ��༭��

Public Const XC_RICHEDIT_FOLDER                     As Long = 51 '///<RichEditFolder  �ļ���ѡ��༭��

Public Const XC_LIST_HEADER                         As Long = 52 '///<�б�ͷԪ��

Public Const XC_SHAPE                               As Long = 61 '///<��״����

Public Const XC_SHAPE_TEXT                          As Long = 62 '///<��״����-�ı�

Public Const XC_SHAPE_PICTURE                       As Long = 63 '///<��״����-ͼƬ

Public Const XC_SHAPE_RECT                          As Long = 64 '///<��״����-����

Public Const XC_SHAPE_ELLIPSE                       As Long = 65 '///<��״����-Բ

Public Const XC_SHAPE_LINE                          As Long = 66 '///<��״����-ֱ��

Public Const XC_SHAPE_GROUPBOX                      As Long = 67 '///<��״����-���

Public Const XC_SHAPE_GIF                           As Long = 68 '///<��״����-GIF

Public Const XC_MENU                                As Long = 81 '///<�����˵�

Public Const XC_IMAGE                               As Long = 82 '///<ͼƬ����

Public Const XC_HDRAW                               As Long = 83 '///<��ͼ����

Public Const XC_FONT                                As Long = 84 '///<�Ų�����

Public Const XC_FLASH                               As Long = 85 '///<flash

Public Const XC_PANE_CELL                           As Long = 86 '

Public Const XC_WEB                                 As Long = 87 '

Public Const XC_LAYOUT_OBJECT                       As Long = 101 '///<���ֶ���LayoutObject

Public Const XC_ADAPTER                             As Long = 102 '

Public Const XC_ADAPTER_TABLE                       As Long = 103 '///<����������AdapterTable

Public Const XC_ADAPTER_TREE                        As Long = 104 '///<����������AdapterTree

Public Const XC_ADAPTER_LISTVIEW                    As Long = 105 '///<����������AdapterListView

Public Const XC_ADAPTER_MAP                         As Long = 106 '///<����������AdapterMap

Public Const XC_LAYOUT_LISTVIEW                     As Long = 111 '

Public Const XC_LAYOUT_LIST                         As Long = 112 '

Public Const XC_LAYOUT_OBJECT_GROUP                 As Long = 113 '

Public Const XC_LAYOUT_OBJECT_ITEM                  As Long = 114 '

Public Const XC_LAYOUT_PANEL                        As Long = 115 '

Public Const XC_BKINFOM                             As Long = 116 '

Public Const xc_window_style_nothing                As Long = 0 '///<ʲôҲû��

Public Const xc_window_style_caption                As Long = 1 'Ĭ��Ϊ�󶨱�����Ԫ��

Public Const xc_window_style_border                 As Long = 2 '��ô�߿򲼾ִ�СΪ0

Public Const xc_window_style_center                 As Long = 4 '///<���ھ���

Public Const xc_window_style_drag_border            As Long = 8 '///<�϶����ڱ߿�

Public Const xc_window_style_drag_window            As Long = 16 '///<�϶�����

Public Const xc_window_style_allow_maxWindow        As Long = 32 '///���������

Public Const xc_window_style_default                As Long = 47 '

Public Const xc_window_style_default2               As Long = 43 '

Public Const xc_window_style_modal                  As Long = 7 '

Public Const window_position_error                  As Long = -1 '///<����

Public Const window_position_top                    As Long = 0 '///<top

Public Const window_position_bottom                 As Long = 1 '///<bottom

Public Const window_position_left                   As Long = 2 '///<left

Public Const window_position_right                  As Long = 3 '///<right

Public Const window_position_body                   As Long = 4 '///<body

Public Const window_position_window                 As Long = 5 '///<window ��������

Public Const window_transparent_false               As Long = 0 '��͸��

Public Const window_transparent_shaped              As Long = 1 '����

Public Const window_transparent_shadow              As Long = 2 '��ǰδ����.

Public Const window_transparent_simple              As Long = 3 'ָ��͸��ɫ.

Public Const window_transparent_win7                As Long = 4 '��ǰδ����.

Public Const menu_item_flags_normal                 As Long = 0 '///<����

Public Const menu_item_flags_select                 As Long = 1 '///<ѡ��

Public Const menu_item_flags_check                  As Long = 2 '///<��ѡ

Public Const menu_item_flags_popup                  As Long = 4 '///<����

Public Const menu_item_flags_separator              As Long = 8 'ID�ű�����

Public Const menu_item_flags_disable                As Long = 16 '///<����

Public Const menu_popup_position_left_top           As Long = 0 '///<���Ͻ�

Public Const menu_popup_position_left_bottom        As Long = 1 '///<���½�

Public Const menu_popup_position_right_top          As Long = 2 '///<���Ͻ�

Public Const menu_popup_position_right_bottom       As Long = 3 '///<���½�

Public Const menu_popup_position_center_left        As Long = 4 '///<�����

Public Const menu_popup_position_center_top         As Long = 5 '///<�Ͼ���

Public Const menu_popup_position_center_right       As Long = 6 '///<�Ҿ���

Public Const menu_popup_position_center_bottom      As Long = 7 '///<�¾���

Public Const image_draw_type_default                As Long = 0 '///<Ĭ��

Public Const image_draw_type_stretch                As Long = 1 '///<����

Public Const image_draw_type_adaptive               As Long = 2 '�Ź���

Public Const image_draw_type_tile                   As Long = 3 '///<ƽ��

Public Const image_draw_type_fixed_ratio            As Long = 4 '����ԭʼ����ѹ����ʾͼƬ

Public Const image_draw_type_adaptive_border        As Long = 5 '///<�Ź��񲻻����м�����

Public Const common_state3_leave                    As Long = 0 '///<�뿪

Public Const common_state3_stay                     As Long = 1 '///<ͣ��

Public Const common_state3_down                     As Long = 2 '///<����

Public Const button_state_leave                     As Long = 0 '///<�뿪״̬

Public Const button_state_stay                      As Long = 1 '///<ͣ��״̬

Public Const button_state_down                      As Long = 2 '///<����״̬

Public Const button_state_check                     As Long = 3 '///<ѡ��״̬

Public Const button_state_disable                   As Long = 4 '///<����״̬

Public Const button_type_default                    As Long = 0 '///<Ĭ������

Public Const button_type_check                      As Long = 1 '///<��ѡ��ť

Public Const button_type_radio                      As Long = 2 '///<��ѡ��ť

Public Const button_type_close                      As Long = 3 '///<���ڹرհ�ť

Public Const button_type_min                        As Long = 4 '///<������С����ť

Public Const button_type_max                        As Long = 5 '///<������󻯻�ԭ��ť

Public Const button_style_default                   As Long = 0 '///<Ĭ�Ϸ��

Public Const button_style_check                     As Long = 1 '///<��ѡ��ť

Public Const button_style_radio                     As Long = 2 '///<��ѡ��ť

Public Const button_style_scrollbar_up              As Long = 3 '�ϰ�ť

Public Const button_style_scrollbar_down            As Long = 4 '�°�ť

Public Const button_style_scrollbar_left            As Long = 5 '��ť

Public Const button_style_scrollbar_right           As Long = 6 '�Ұ�ť

Public Const button_style_scrollbar_slider          As Long = 7 '����

Public Const button_style_tabBar_button             As Long = 8 '///<TabBar�ϵİ�ť

Public Const button_style_toolBar_left              As Long = 9 '///<ToolBar�������ť

Public Const button_style_toolBar_right             As Long = 10 '///<ToolBar�ҹ�����ť

Public Const button_style_toolBar_expand            As Long = 11 '///<չ��������ť

Public Const button_style_pane_close                As Long = 12 '///<����رհ�ť

Public Const button_style_pane_lock                 As Long = 13 '///<����������ť

Public Const button_style_pane_menu                 As Long = 14 '///<���������˵���ť

Public Const button_style_pane_dockH                As Long = 15 '///<��ܴ�����߻��ұ���ͷ�ϰ�ť

Public Const button_style_pane_dockV                As Long = 16 '///<��ܴ����ϱ߻��±���ͷ�ϰ�ť

Public Const comboBox_state_leave                   As Long = 0 '///<����뿪״̬

Public Const comboBox_state_stay                    As Long = 1 '///<���ͣ��״̬

Public Const comboBox_state_down                    As Long = 2 '///<����״̬

Public Const list_item_state_leave                  As Long = 0 '///<������뿪״̬

Public Const list_item_state_stay                   As Long = 1 '///<�����ͣ��״̬

Public Const list_item_state_select                 As Long = 2 '///<��ѡ��״̬

Public Const tree_item_state_leave                  As Long = 0 '///<������뿪״̬

Public Const tree_item_state_stay                   As Long = 1 '///<�����ͣ��״̬

Public Const tree_item_state_select                 As Long = 2 '///<��ѡ��״̬

Public Const button_icon_align_left                 As Long = 0 '///<ͼ�������

Public Const button_icon_align_top                  As Long = 1 '///<ͼ���ڶ���

Public Const button_icon_align_right                As Long = 2 '///<ͼ�����ұ�

Public Const button_icon_align_bottom               As Long = 3 '///<ͼ���ڵײ�

Public Const layout_size_type_fixed                 As Long = 0 '///<ָ����С

Public Const layout_size_type_fill                  As Long = 1 '///<fill ��丸

Public Const layout_size_type_auto                  As Long = 2 '�������ݼ����С

Public Const layout_size_type_weight                As Long = 3 '���ձ�������ʣ��ռ�

Public Const layout_size_type_disable               As Long = 4 '///<disable ��ʹ��

Public Const list_drawItemBk_flags_nothing          As Long = 0 '///<������

Public Const list_drawItemBk_flags_leave            As Long = 1 '///<��������뿪״̬���

Public Const list_drawItemBk_flags_stay             As Long = 2 '///<�������ѡ��״̬���

Public Const list_drawItemBk_flags_select           As Long = 4 '///<�������ͣ��״̬�����

Public Const list_drawItemBk_flags_group_leave      As Long = 8 '����Ϊ��ʱ

Public Const messageBox_flags_other                 As Long = 0 '///<����

Public Const messageBox_flags_ok                    As Long = 1 '///<ȷ����ť

Public Const messageBox_flags_cancel                As Long = 2 '///<ȡ����ť

Public Const propertyGrid_item_type_text            As Long = 0 '�ַ�������

Public Const propertyGrid_item_type_edit            As Long = 1 '///<�༭��

Public Const propertyGrid_item_type_edit_color      As Long = 2 '///<��ɫѡ��Ԫ��

Public Const propertyGrid_item_type_edit_file       As Long = 3 '///<�ļ�ѡ��༭��

Public Const propertyGrid_item_type_edit_set        As Long = 4 '///<����

Public Const propertyGrid_item_type_comboBox        As Long = 5 '///<��Ͽ�

Public Const propertyGrid_item_type_group           As Long = 6 '///<��

Public Const zorder_top                             As Long = 1 '///<������

Public Const zorder_bottom                          As Long = 2 '///<������

Public Const zorder_before                          As Long = 3 '///<ָ��Ŀ������

Public Const zorder_after                           As Long = 4 '///<ָ��Ŀ������

Public Const layout_align_left                      As Long = 0 '

Public Const layout_align_top                       As Long = 1 '

Public Const layout_align_right                     As Long = 2 '

Public Const layout_align_bottom                    As Long = 3 '

Public Const layout_align_center                    As Long = 4 '

Public Const layout_align_equidistant               As Long = 5 '

Public Const align_error                            As Long = -1 '

Public Const align_left                             As Long = 0 '

Public Const align_top                              As Long = 1 '

Public Const align_right                            As Long = 2 '

Public Const align_bottom                           As Long = 3 '

Public Const align_center                           As Long = 4 '

Public Const dock_align_left                        As Long = 0 '

Public Const dock_align_top                         As Long = 1 '

Public Const dock_align_right                       As Long = 2 '

Public Const dock_align_bottom                      As Long = 3 '

Public Const pane_state_any                         As Long = 0 '

Public Const pane_state_lock                        As Long = 1 '

Public Const pane_state_dock                        As Long = 2 '

Public Const pane_state_float                       As Long = 3 '

Public Const bkInfo_type_error                      As Long = 0 '

Public Const bkInfo_type_fill                       As Long = 1 '///<���

Public Const bkInfo_type_border                     As Long = 2 '///<�߿�

Public Const bkInfo_type_image                      As Long = 3 '///<ͼƬ

Public Const bkInfo_type_triangle                   As Long = 4 '///<������

Public Const bkInfo_type_rectangle                  As Long = 5 '///<����

Public Const bkInfo_type_ellipse                    As Long = 6 '///<Բ��

Public Const bkInfo_type_roundRect                  As Long = 7 '///<Բ�Ǿ���

Public Const window_state_flag_nothing              As Long = 0 '///<��

Public Const window_state_whole_leave               As Long = 1 '///<��������

Public Const window_state_body_leave                As Long = 2 '///<����-body

Public Const window_state_top_leave                 As Long = 4 '///<����-top

Public Const window_state_bottom_leave              As Long = 8 '///<����-bottom

Public Const window_state_left_leave                As Long = 16 '///<����-left

Public Const window_state_right_leave               As Long = 32 '///<����-right

Public Const element_state_flag_nothing             As Long = 0 '///<��

Public Const element_state_flag_enable              As Long = 1 '///<����

Public Const element_state_flag_disable             As Long = 2 '///<����

Public Const element_state_flag_focus               As Long = 4 '///<����

Public Const element_state_flag_focus_no            As Long = 8 '///<�޽���

Public Const element_state_flag_leave               As Long = 16 '///<����뿪

Public Const element_state_flag_stay                As Long = 32 '///<Ϊ��չģ�鱣��

Public Const element_state_flag_down                As Long = 64 '///<Ϊ��չģ�鱣��

Public Const button_state_flag_leave                As Long = 16 '///<����뿪

Public Const button_state_flag_stay                 As Long = 32 '///<���ͣ��

Public Const button_state_flag_down                 As Long = 64 '///<��갴��

Public Const button_state_flag_check                As Long = 128 '///<ѡ��

Public Const button_state_flag_check_no             As Long = 256 '///<δѡ��

Public Const button_state_flag_WindowRestore        As Long = 512 '//���ڻ�ԭ

Public Const button_state_flag_WindowMaximize       As Long = 1024 '//�������

Public Const comboBox_state_flag_leave              As Long = 16 '///<����뿪

Public Const comboBox_state_flag_stay               As Long = 32 '///<���ͣ��

Public Const comboBox_state_flag_down               As Long = 64 '///<��갴��

Public Const listBox_state_flag_item_leave          As Long = 128 '///<������뿪

Public Const listBox_state_flag_item_stay           As Long = 256 '///<�����ͣ��

Public Const listBox_state_flag_item_select         As Long = 512 '///<��ѡ��

Public Const listBox_state_flag_item_select_no      As Long = 1024 '///<��δѡ��

Public Const list_state_flag_item_leave             As Long = 128 '///<������뿪

Public Const list_state_flag_item_stay              As Long = 256 '///<�����ͣ��

Public Const list_state_flag_item_select            As Long = 512 '///<��ѡ��

Public Const list_state_flag_item_select_no         As Long = 1024 '///<��δѡ��

Public Const listView_state_flag_item_leave         As Long = 128 '///<������뿪

Public Const listView_state_flag_item_stay          As Long = 256 '///<�����ͣ��

Public Const listView_state_flag_item_select        As Long = 512 '///<��ѡ��

Public Const listView_state_flag_item_select_no     As Long = 1024 '///<��δѡ��

Public Const listView_state_flag_group_leave        As Long = 2048 '///<������뿪

Public Const listView_state_flag_group_stay         As Long = 4096 '///<�����ͣ��

Public Const listView_state_flag_group_select       As Long = 8192 '///<��ѡ��

Public Const listView_state_flag_group_select_no    As Long = 16384 '///<��δѡ��

Public Const tree_state_flag_item_leave             As Long = 128 '///<������뿪

Public Const tree_state_flag_item_stay              As Long = 256 '��δʹ��

Public Const tree_state_flag_item_select            As Long = 512 '///<��ѡ��

Public Const tree_state_flag_item_select_no         As Long = 1024 '///<��δѡ��

Public Const monthCal_state_flag_leave              As Long = 16 '///<�뿪״̬

Public Const monthCal_state_flag_item_leave         As Long = 128 '///< ��-�뿪

Public Const monthCal_state_flag_item_stay          As Long = 256 '///< ��-ͣ��

Public Const monthCal_state_flag_item_down          As Long = 512 '///< ��-����

Public Const monthCal_state_flag_item_select        As Long = 1024 '///< ��-ѡ��

Public Const monthCal_state_flag_item_select_no     As Long = 2048 '///< ��-δѡ��

Public Const monthCal_state_flag_item_today         As Long = 4096 '///< ��-����

Public Const monthCal_state_flag_item_other         As Long = 8192 '///< ��-���¼�����

Public Const monthCal_state_flag_item_last_month    As Long = 16384 '///< ��-����

Public Const monthCal_state_flag_item_cur_month     As Long = 32768 '///< ��-����

Public Const monthCal_state_flag_item_next_month    As Long = 65536 '///< ��-����

Public Const propertyGrid_state_flag_item_leave     As Long = 128 '

Public Const propertyGrid_state_flag_item_stay      As Long = 256 '

Public Const propertyGrid_state_flag_item_select    As Long = 512 '

Public Const propertyGrid_state_flag_item_select_no As Long = 1024 '

Public Const pane_state_flag_leave                  As Long = 128 '

Public Const pane_state_flag_stay                   As Long = 256 '

Public Const pane_state_flag_caption                As Long = 512 '

Public Const pane_state_flag_body                   As Long = 1024 '

Public Const monthCal_button_type_today             As Long = 0 '///< ���찴ť

Public Const monthCal_button_type_last_year         As Long = 1 '///< ��һ��

Public Const monthCal_button_type_next_year         As Long = 2 '///< ��һ��

Public Const monthCal_button_type_last_month        As Long = 3 '///< ��һ��

Public Const monthCal_button_type_next_month        As Long = 4 '///< ��һ��

Public Const XWM_WINDPROC                           As Long = 28672 '

Public Const XWM_REDRAW_ELE                         As Long = 28675 '

Public Const XWM_DRAW_T                             As Long = 28673 '

Public Const XWM_MENU_POPUP                         As Long = 28677 '

Public Const XWM_MENU_POPUP_WND                     As Long = 28678 '

Public Const XWM_MENU_SELECT                        As Long = 28679 '

Public Const XWM_MENU_EXIT                          As Long = 28680 '

Public Const XWM_MENU_DRAW_BACKGROUND               As Long = 28681 '

Public Const XWM_MENU_DRAWITEM                      As Long = 28682 '

Public Const XWM_COMBOBOX_POPUP_DROPLIST            As Long = 28683 '

Public Const XWM_FLOAT_PANE                         As Long = 28684 '

Public Const XC_WINDOW_BODY                         As Long = 10 '

Public Const IDM_CLIP                               As Long = 1000000000 '

Public Const IDM_COPY                               As Long = 1000000001 '

Public Const IDM_PASTE                              As Long = 1000000002 '

Public Const IDM_DELETE                             As Long = 1000000003 '

Public Const IDM_SELECTALL                          As Long = 1000000004 '

Public Const IDM_DELETEALL                          As Long = 1000000005 '

Public Const IDM_LOCK                               As Long = 1000000006 '

Public Const IDM_DOCK                               As Long = 1000000007 '

Public Const IDM_FLOAT                              As Long = 1000000008 '

Public Const IDM_HIDE                               As Long = 1000000009 '

Public Const XE_LBUTTONDOWN                         As Long = 10 '

Public Const XE_LBUTTONUP                           As Long = 11 '

Public Const XE_RBUTTONDOWN                         As Long = 12 '

Public Const XE_RBUTTONUP                           As Long = 13 '

Public Const XE_LBUTTONDBCLICK                      As Long = 14 '

Public Const XE_RBUTTONDBCLICK                      As Long = 15 '

Public Const XE_SETFOCUS                            As Long = 31 '

Public Const XE_KILLFOCUS                           As Long = 32 '

Public Const XE_DESTROY                             As Long = 33 '

Public Const XE_BNCLICK                             As Long = 34 '

Public Const XE_BUTTON_CHECK                        As Long = 35 '

Public Const XE_SIZE                                As Long = 36 '

Public Const XE_SHOW                                As Long = 37 '

Public Const XE_SETFONT                             As Long = 38 '

Public Const XE_KEYDOWN                             As Long = 39 '

Public Const XE_CHAR                                As Long = 40 '

Public Const XE_SETCAPTURE                          As Long = 51 '

Public Const XE_KILLCAPTURE                         As Long = 52 '

Public Const XE_SETCURSOR                           As Long = 53 '

Public Const XE_SCROLLVIEW_SCROLL_H                 As Long = 54 '

Public Const XE_SCROLLVIEW_SCROLL_V                 As Long = 55 '

Public Const XE_SBAR_SCROLL                         As Long = 56 '

Public Const XE_MENU_POPUP                          As Long = 57 '

Public Const XE_MENU_POPUP_WND                      As Long = 58 '

Public Const XE_MENU_SELECT                         As Long = 59 '

Public Const XE_MENU_DRAW_BACKGROUND                As Long = 60 '

Public Const XE_MENU_DRAWITEM                       As Long = 61 '

Public Const XE_MENU_EXIT                           As Long = 62 '

Public Const XE_SLIDERBAR_CHANGE                    As Long = 63 '

Public Const XE_PROGRESSBAR_CHANGE                  As Long = 64 '

Public Const XE_COMBOBOX_SELECT                     As Long = 71 '

Public Const XE_COMBOBOX_POPUP_LIST                 As Long = 72 '

Public Const XE_COMBOBOX_EXIT_LIST                  As Long = 73 '

Public Const XE_LISTBOX_TEMP_CREATE                 As Long = 81 '

Public Const XE_LISTBOX_TEMP_CREATE_END             As Long = 82 '

Public Const XE_LISTBOX_TEMP_DESTROY                As Long = 83 '

Public Const XE_LISTBOX_TEMP_ADJUST_COORDINATE      As Long = 84 '

Public Const XE_LISTBOX_DRAWITEM                    As Long = 85 '

Public Const XE_LISTBOX_SELECT                      As Long = 86 '

Public Const XE_LIST_TEMP_CREATE                    As Long = 101 '

Public Const XE_LIST_TEMP_CREATE_END                As Long = 102 '

Public Const XE_LIST_TEMP_DESTROY                   As Long = 103 '

Public Const XE_LIST_TEMP_ADJUST_COORDINATE         As Long = 104 '

Public Const XE_LIST_DRAWITEM                       As Long = 105 '

Public Const XE_LIST_SELECT                         As Long = 106 '

Public Const XE_LIST_HEADER_DRAWITEM                As Long = 107 '

Public Const XE_LIST_HEADER_CLICK                   As Long = 108 '

Public Const XE_LIST_HEADER_WIDTH_CHANGE            As Long = 109 '

Public Const XE_LIST_HEADER_TEMP_CREATE             As Long = 110 '

Public Const XE_LIST_HEADER_TEMP_CREATE_END         As Long = 111 '

Public Const XE_LIST_HEADER_TEMP_DESTROY            As Long = 112 '

Public Const XE_LIST_HEADER_TEMP_ADJUST_COORDINATE  As Long = 113 '

Public Const XE_TREE_TEMP_CREATE                    As Long = 121 '

Public Const XE_TREE_TEMP_CREATE_END                As Long = 122 '

Public Const XE_TREE_TEMP_DESTROY                   As Long = 123 '

Public Const XE_TREE_TEMP_ADJUST_COORDINATE         As Long = 124 '

Public Const XE_TREE_DRAWITEM                       As Long = 125 '

Public Const XE_TREE_SELECT                         As Long = 126 '

Public Const XE_TREE_EXPAND                         As Long = 127 '

Public Const XE_TREE_DRAG_ITEM_ING                  As Long = 128 '

Public Const XE_TREE_DRAG_ITEM                      As Long = 129 '

Public Const XE_LISTVIEW_TEMP_CREATE                As Long = 141 '

Public Const XE_LISTVIEW_TEMP_CREATE_END            As Long = 142 '

Public Const XE_LISTVIEW_TEMP_DESTROY               As Long = 143 '

Public Const XE_LISTVIEW_TEMP_ADJUST_COORDINATE     As Long = 144 '

Public Const XE_LISTVIEW_DRAWITEM                   As Long = 145 '

Public Const XE_LISTVIEW_SELECT                     As Long = 146 '

Public Const XE_LISTVIEW_EXPAND                     As Long = 147 '

Public Const XE_PGRID_VALUE_CHANGE                  As Long = 151 '

Public Const XE_PGRID_ITEM_SET                      As Long = 152 '

Public Const XE_PGRID_ITEM_SELECT                   As Long = 153 '

Public Const XE_RICHEDIT_CHANGE                     As Long = 161 '

Public Const XE_RICHEDIT_SET                        As Long = 162 '

Public Const XE_TABBAR_SELECT                       As Long = 221 '

Public Const XE_TABBAR_DELETE                       As Long = 222 '

Public Const XE_MONTHCAL_CHANGE                     As Long = 231 '

Public Const XE_DATETIME_CHANGE                     As Long = 241 '

Public Const XE_DATETIME_POPUP_MONTHCAL             As Long = 242 '

Public Const XE_DATETIME_EXIT_MONTHCAL              As Long = 243 '

Public Const XE_DROPFILES                           As Long = 250 '

Public Const XC_PARAM_HIMAGE                        As Long = 10 '

Public Const XC_PARAM_HDRAW                         As Long = 11 '

Public Const XC_PARAM_P_RECT                        As Long = 12 '

Public Const XC_PARAM_P_POINT                       As Long = 13 '

Public Const XC_PARAM_P_SIZE                        As Long = 14 '

Public Const XC_PARAM_P_BOOL                        As Long = 15 '

Public Const XC_PARAM_P_listBox_item_i              As Long = 16 '

Public Const XC_PARAM_P_list_header_item_i          As Long = 17 '

Public Const XC_PARAM_P_list_item_i                 As Long = 18 '

Public Const XC_PARAM_P_listView_item_i             As Long = 19 '

Public Const XC_PARAM_P_tree_item_i                 As Long = 20 '

Public Const XC_PARAM_P_menu_popupWnd               As Long = 21 '

Public Const XC_PARAM_P_menu_drawBackground         As Long = 22 '

Public Const XC_PARAM_P_menu_drawItem               As Long = 23 '

Public Const XC_PARAM_HDROP                         As Long = 24 '

Public Const XC_PARAM_P_tree_dragItem_i             As Long = 25 '

Public Const XC_WINDOW_TOP                          As Long = 1 '

Public Const XC_WINDOW_BOTTOM                       As Long = 2 '

Public Const XC_WINDOW_LEFT                         As Long = 3 '

Public Const XC_WINDOW_RIGHT                        As Long = 4 '

Public Const XC_WINDOW_TOPLEFT                      As Long = 5 '

Public Const XC_WINDOW_TOPRIGHT                     As Long = 6 '

Public Const XC_WINDOW_BOTTOMLEFT                   As Long = 7 '

Public Const XC_WINDOW_BOTTOMRIGHT                  As Long = 8 '

Public Const XC_WINDOW_CAPTION                      As Long = 9 '

Public Const XC_ID_ROOT                             As Long = 0 '

Public Const XE_ELEPROCE                            As Long = 1 '

Public Const XE_PAINT_END                           As Long = 3 '

Public Const XE_MOUSESTAY                           As Long = 6 '

Public Const XE_MOUSEHOVER                          As Long = 7 '

Public Const XE_MOUSELEAVE                          As Long = 8 '

Public Const XE_MOUSEWHEEL                          As Long = 9 '

Public Const XE_PAINT                               As Long = 2 '

Public Const XE_PAINT_SCROLLVIEW                    As Long = 4 '

Public Const XE_MOUSEMOVE                           As Long = 5 '

Public Const XC_PARAM_int                           As Long = 1 '

Public Const XC_PARAM_uint                          As Long = 2 '

Public Const XC_PARAM_BOOL                          As Long = 3 '

Public Const XC_PARAM_CHAR                          As Long = 4 '

Public Const XC_PARAM_BYTE                          As Long = 5 '

Public Const XC_PARAM_HXCGUI                        As Long = 6 '

Public Const XC_PARAM_HWINDOW                       As Long = 7 '

Public Const XC_PARAM_HELE                          As Long = 8 '

Public Const XC_PARAM_HMENUX                        As Long = 9 '

Public Const XC_ID_ERROR                            As Long = -1 '

Public Const XC_ID_FIRST                            As Long = -2 '

Public Const XC_ID_LAST                             As Long = -3 '

Type rect

    x As Long
    y As Long
    cx As Long
    cy As Long

End Type

Type Point

    x As Long
    y As Long

End Type

Type size

    cx As Long
    cy As Long

End Type

Type LOGFONTW

    lfHeight As Long
    lfWidth As Long
    lfEscapement As Long
    lfOrientation As Long
    lfWeight As Long
    lfItalic As Byte
    lfUnderline As Byte
    lfStrikeOut As Byte
    lfCharSet As Byte
    lfOutPrecision As Byte
    lfClipPrecision As Byte
    lfQuality As Byte
    lfPitchAndFamily As Byte
    lfFaceName(32) As Integer

End Type

Type LOGFONT

    lfHeight As Long
    lfWidth As Long
    lfEscapement As Long
    lfOrientation As Long
    lfWeight As Long
    lfItalic As Byte
    lfUnderline As Byte
    lfStrikeOut As Byte
    lfCharSet As Byte
    lfOutPrecision As Byte
    lfClipPrecision As Byte
    lfQuality As Byte
    lfPitchAndFamily As Byte
    lfFaceName(32) As Byte

End Type


Type SpaceSize_

    leftSize As Long
    topSize As Long
    RightSzie As Long
    bottom As Long

End Type

Type PaddingSize_

    leftSize As Long
    topSize As Long
    RightSzie As Long
    bottom As Long

End Type

Type RECTF

    left As Single '
    top As Single '
    right As Single '
    bottom As Single '

End Type

Type BorderSize_

    leftSize As Long '
    topSize As Long '
    rightSize As Long '
    bottomSize As Long '

End Type

Type Position

    iRow As Long '
    iColumn As Long '

End Type

Type template_info_i

    Info As Long '

End Type

Type listBox_item_i

    nUserData As Long '///<�û�������
    nHeight As Long '///<��Ĭ�ϸ߶�
    nSelHeight As Long '///<��ѡ��ʱ�߶�
    nState As Long '///<״̬
    index As Long '///<������
    rcItem As rect '///<������
    hLayout As Long '///<���ֶ���
    Info As template_info_i '///<ģ����Ϣ

End Type

Type listBox_item_Info_i

    nUserData As Long '//�û�������
    nHeight As Long '
    nSelHeight As Long '

End Type

Type listView_item_id_i

    iGroup As Long '///<������
    iItem As Long '///<������

End Type

Type list_item_i

    index As Long '
    iSubItem As Long '
    nUserData As Long '
    nState As Long '
    rcItem As rect '
    hLayout As Long '///<���ֶ���
    Info As template_info_i '///<ģ����Ϣ

End Type

Type list_header_item_i

    index As Long '
    nUserData As Long '
    nState As Long '
    rcItem As rect '
    hLayout As Long '///<���ֶ���
    Info As template_info_i '///<ģ����Ϣ

End Type

Type tree_item_i

    nID As Long '
    nDepth As Long '
    nState As Long '
    nHeight As Long '
    nSelHeight As Long '
    nUserData As Long '
    bExpand As Boolean '
    rcItem As rect '
    hLayout As Long '///<���ֶ���
    Info As template_info_i '///<ģ����Ϣ

End Type

Type listView_item_i

    iGroup As Long '///<������������ -1û����
    iItem As Long '///<����������λ������,�������Ϊ-1,��ôΪ��
    nUserData As Long '///<�û�������
    nState As Long '///<״̬
    rcItem As rect '///<��������,�����߿�
    hLayout As Long '///<���ֶ���
    Info As template_info_i '///<ģ����Ϣ

End Type

Type layout_info_i

    widthType As Long '
    heightType As Long '
    width As Integer '//���
    height As Integer '//�߶�

End Type

Type menu_popupWnd_i

    hWindow As Long '//���ھ��
    nParentID As Long '//����ID

End Type

Type menu_drawBackground_i

    hMenu As Long '///<�˵����
    hWindow As Long '///<��ǰ�����˵���Ĵ��ھ��
    nParentID As Long '///<����ID

End Type

Type menu_drawItem_i

    hMenu As Long '///<�˵����
    hWindow As Long '///<��ǰ�����˵���Ĵ��ھ��
    nID As Long '///<ID
    nState As Long '///<״̬ @ref menu_item_flags_
    rcItem As rect '///<����
    hIcon As Long '///<�˵���ͼ��
    Text As String '///<�ı�

End Type

Type tree_drag_item_i

    nDragItem As Long '///< �϶���ID
    nDestItem As Long '///< Ŀ����ID
    nType As Long '///< ͣ�����Ŀ��λ��,1:ͣ�ŵ�Ŀ�������,2:ͣ�ŵ�Ŀ�������,3:ͣ�ŵ�Ŀ��ĵ�����

End Type

Type xc_font_info_i

    nSize As Long '///<�����С,��λ(pt,��).
    bBold As Boolean '///<����
    bItalic As Boolean '///<б��
    bUnderline As Boolean '///<�»���
    bStrikeout As Boolean '///<ɾ����
    aName(32) As Integer '///<��������

End Type

Type POINTF

    x As Single '
    y As Single '

End Type

Type monthCal_item_i

    nDay As Long '///< ����
    nType As Long '///< 1����,2����,3����
    nState As Long '///< ���״̬ monthCal_state_flag_
    rcItem As rect '///< ������

End Type

