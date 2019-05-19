/*
 * 
 * BlzFans@hotmail.com
 * http://wke.sf.net
 * http://www.github.com/BlzFans/wke
 * licence LGPL
 *
 */

/*

### Ŀ��

 ��ͷ�ļ���Ҫ���� https://www.github.com/cexer/wke �Ľӿڻ��������˵������Ż���������ҪĿ����Ϊ��ͳһ
 �𽥳��ֵĲ�ͬ�� wke ʵ�ַ�֧�Ļ����ӿڡ�
 
### ԭ��

 ��ͷ�ļ�Ϊ��Щ��ͬ�� wke ʵ���ƶ�һ�������Ľӿڱ�׼����ʵ��������ӿڱ�׼֮�ϵĶ����Ƽ��ݡ�����ԭ��

 - ��ͷ�ļ���������������ͷ�ļ������Ͷ��壬�ر���ϵͳ��ص�ͷ�ļ������Ͷ��壬�����ⲿ�����������ͻ��
 - �ӿ�����ʹ�õ��ַ�������ʹ�� wchar_t �ַ����͵��ַ�����ͬʱ������ wkeChar == wchar_t��
 - �ӿڶ���Ӧ�ü򵥡�ֱ�ӣ����������Һ���׼ȷ������ʹ�á�����͡��ӿڣ����磺�ϳ��� wkeConfigure �ӿڡ�

### ��ʷ

2016-11-19 22:25 cexer ��ɳ������塣

2016-11-19 22:52 cexer ����Ⱥ������޸ģ�

    - Zero���� ���� wkeSetHostWindow �� WebView ��λ��ƫ�Ʋ�����
    - Zero���� ���� wkeOnDownloadFile �ص���
    - Zero���� ȥ�� wkeSendNativeMessage��wkePostNativeMessage��
    - Zero���� ȥ������εĽӿڣ����ֻ��Ҫ�ڲ�ʵ��ʹ�á�
    - ���Ͻ��� wkeExecCommand ����ֵ�޸�Ϊ int��
    - ���Ͻ��� �޸� wkeGetCaretRect ���ط�ʽΪ�������ء�

2016-11-21 22:41 cexer ����Ⱥ������޸ģ�

    - Zero���� ���� wkeFireInternalEvent �ӿڡ�
    - Zero���� ȥ�� wkeCreateWebWindow �Լ�����OSR�޹صĺ�����
    - ���ͶƱ �޸ĵ���Լ��Ϊ stdcall��
    - Zero���� ���� wkeSetVisible��wkeIsVisible��

2016-11-22 23:25 cexer ����Ⱥ������޸ģ�

    - Zero���� �����ȡ����״̬�Ľӿڣ��ۺ�Ϊһ�� wkeGetLoadingStatus��
    - ���Ͻ��� �޸� wkeLoadingStatus ��ö��ֵ��

2016-11-23 01:58 cexer ����Ⱥ������޸ģ�

    - ���Ͻ��� ���� wkeSetStoragePath �ӿڣ��������ڱ��� localStorage��cache file��WebSQL ���ļ��ĸ�Ŀ¼��
    - ���Ͻ��� �޸� wkeNavigationCallback �ص��ķ���ֵ���Ӷ���ָ���˵�����������ֹ��ת��Ϊ���ء�
    - Zero���� ���ӻ� wkeGetContentWidth��wkeGetContentHeight��
    - cexer���� ͳһ FILE_XXXX �ص�����������Ϊ wkeFileXxxxCallback
    - cexer���� ɾ�� wkeJSParamCount �Ƚӿڡ�
    - cexer���� ������ wkeJSGetState -> wkeGetJSState��wkeJSExecute -> wkeEvaluateJS��wkeJSEval -> wkeJSEvalute

2016-11-23 10:32 cexer ����Ⱥ������޸ģ�

	- ���Ͻ��� ���� WKE_STATIC ����жϣ���֧�־�̬���ӡ�
	- ���Ͻ��� �������� wkeWebView �����Ͷ��壬����������ʵ�����͡�
	- cexer���� ���� WKE_API_VERSION ָ�������ӿڵİ汾��
    - Ⱥ�ں��� ���� wkeJSEvaluate -> wkeJSEval��

### ����

 ��Ⱥ 178168957 ���ۡ�
 

*/

#ifndef WKE_H
#define WKE_H

//////////////////////////////////////////////////////////////////////////


#if defined(__cplusplus)
#   define WKE_EXTERN_C extern "C"
#else
#   define WKE_EXTERN_C
#endif


#if defined(WKE_BUILD)
#   define WKE_SYMBOL __declspec(dllexport)
#else
#   define WKE_SYMBOL __declspec(dllimport)
#endif


#if !defined(WKE_STATIC)
#   define WKE_API  WKE_EXTERN_C WKE_SYMBOL
#else
#	define WKE_API  WKE_EXTERN_C
#endif



#define WKE_CALL __stdcall

/*
    WKE ������ʵ�ֽ��鶼ʹ�� A.B.C.D ����ʽ������ A �����˽ӿڰ汾���� WKE_API_VERSION ָ���İ汾��
    ����ֻҪ A �汾�ţ��ӿڰ汾�ţ�һ�£����ڴ˰汾�ӿڵ�����ʵ��֮��Ϳ��޷��滻��
*/
#define WKE_API_VERSION   0


typedef struct 
{
    int x;
    int y;
    int width;
    int height;

} wkeRect;


typedef            wchar_t    wkeChar;
typedef struct    wkeWebView   wkeWebView;
typedef            __int64    wkeJSValue;
typedef struct  __wkeJSState  wkeJSState;
typedef struct  __wkeJSData   wkeJSData;



#if !defined(__cplusplus)
#   ifndef HAVE_BOOL
        typedef unsigned char bool;
#       define true  1
#       define false 0
#   endif

#   ifndef HAVE_WCHAR_T
        typedef unsigned short wchar_t;
#   endif
#endif


/*
 *c interface
 *----------------------------------------------------------------------------------------------------------
 *
 */

#if defined(__cplusplus)
extern "C"
{
#endif


//ȫ������
WKE_API void           WKE_CALL wkeInitialize();
WKE_API void           WKE_CALL wkeFinalize();
WKE_API unsigned       WKE_CALL wkeGetVersion();
WKE_API const wkeChar* WKE_CALL wkeGetVersionString();

//ȫ������
WKE_API void           WKE_CALL wkeSetProxyServer(const wkeChar* proxy);
WKE_API void           WKE_CALL wkeSetCookieFile(const wkeChar* file);
WKE_API void           WKE_CALL wkeSetStoragePath(const wkeChar* directory);

//�ڴ����
WKE_API void*          WKE_CALL wkeMalloc(size_t bytes);
WKE_API void           WKE_CALL wkeFree(void* ptr);


//ҳ�洴��������
WKE_API wkeWebView*    WKE_CALL wkeCreateWebView();
WKE_API void           WKE_CALL wkeDestroyWebView(wkeWebView* webView);


//ҳ������
WKE_API void           WKE_CALL wkeSetHostWindow(wkeWebView* webWindow, void* window, int offsetX, int offsetY);
WKE_API void*          WKE_CALL wkeGetHostWindow(wkeWebView* webWindow);

WKE_API void           WKE_CALL wkeSetUserAgent(wkeWebView* webView, const wkeChar* userAgent);
WKE_API const wkeChar* WKE_CALL wkeGetUserAgent(wkeWebView* webView);

WKE_API void           WKE_CALL wkeResize(wkeWebView* webView, int width, int height);
WKE_API int            WKE_CALL wkeGetWidth(wkeWebView* webView);
WKE_API int            WKE_CALL wkeGetHeight(wkeWebView* webView);
WKE_API int            WKE_CALL wkeGetContentWidth(wkeWebView* webView);
WKE_API int            WKE_CALL wkeGetContentHeight(wkeWebView* webView);

WKE_API void           WKE_CALL wkeSetVisible(wkeWebView* webView, bool visible);
WKE_API bool           WKE_CALL wkeIsVisible(wkeWebView* webView);

WKE_API const wkeChar* WKE_CALL wkeGetTitle(wkeWebView* webView);

WKE_API void           WKE_CALL wkeSetFocus(wkeWebView* webView);
WKE_API void           WKE_CALL wkeKillFocus(wkeWebView* webView);

WKE_API void           WKE_CALL wkeSetZoomFactor(wkeWebView* webView, float factor);
WKE_API float          WKE_CALL wkeGetZoomFactor(wkeWebView* webView);

WKE_API void           WKE_CALL wkeSetMediaVolume(wkeWebView* webView, float volume);
WKE_API float          WKE_CALL wkeGetMediaVolume(wkeWebView* webView);

WKE_API const wkeChar* WKE_CALL wkeGetCookie(wkeWebView* webView);
WKE_API void           WKE_CALL wkeSetCookieEnabled(wkeWebView* webView, bool enable);
WKE_API bool           WKE_CALL wkeIsCookieEnabled(wkeWebView* webView);


//���ء�������
WKE_API void           WKE_CALL wkeLoadURL(wkeWebView* webView, const wkeChar* url);
WKE_API void           WKE_CALL wkePostURL(wkeWebView* wkeView,const wkeChar* url, const void* data, int dataBytes);
WKE_API void           WKE_CALL wkeLoadHTML(wkeWebView* webView, const wkeChar* html);

WKE_API bool           WKE_CALL wkeCanGoBack(wkeWebView* webView);
WKE_API bool           WKE_CALL wkeGoBack(wkeWebView* webView);
WKE_API bool           WKE_CALL wkeCanGoForward(wkeWebView* webView);
WKE_API bool           WKE_CALL wkeGoForward(wkeWebView* webView);

WKE_API void           WKE_CALL wkeStopLoading(wkeWebView* webView);
WKE_API void           WKE_CALL wkeReload(wkeWebView* webView);

//����״̬
typedef enum
{
    WKE_STATE_UNINITIALIZED,    //��δ����wkeLoad����
    WKE_STATE_LOADING,          //���ڼ���
    WKE_STATE_LOADING_SUCCEED,  //���ݼ��سɹ�
    WKE_STATE_LOADING_FAILED,   //���ݼ���ʧ��
    WKE_STATE_DOCUMENT_READY    //�ĵ��Ѿ��������

} wkeLoadingStatus;

WKE_API wkeLoadingStatus WKE_CALL wkeGetLoadingStatus(wkeWebView* webView);


//������ؽӿ�
WKE_API bool           WKE_CALL wkeIsTransparent(wkeWebView* webView);
WKE_API void           WKE_CALL wkeSetTransparent(wkeWebView* webView, bool transparent);
WKE_API void           WKE_CALL wkePaint(wkeWebView* webView, void* bits, int pitch);
WKE_API bool           WKE_CALL wkeRepaintIfNeeded(wkeWebView* webView);
WKE_API void*          WKE_CALL wkeGetViewDC(wkeWebView* webView);
WKE_API bool           WKE_CALL wkeGetCaretRect(wkeWebView* webView, wkeRect* rect);


//ִ�б༭������
/*
    SelectAll   ȫѡ
    Copy        ����
    Cut         ����
    Paste       ճ��
    Delete      ɾ��
*/
WKE_API int            WKE_CALL wkeExecuteCommand(wkeWebView* webView, const wkeChar* command, const wkeChar* args);


//�ű��ӿ�
WKE_API wkeJSState*    WKE_CALL wkeGetJSState(wkeWebView* webView);
WKE_API wkeJSValue     WKE_CALL wkeEvaluateJS(wkeWebView* webView, const wkeChar* code);



//���������Ϣ

typedef enum
{
    WKE_LBUTTON = 0x01,
    WKE_RBUTTON = 0x02,
    WKE_SHIFT   = 0x04,
    WKE_CONTROL = 0x08,
    WKE_MBUTTON = 0x10,

} wkeMouseFlags;

typedef enum
{
    WKE_EXTENDED = 0x0100,
    WKE_REPEAT = 0x4000,

} wkeKeyFlags;

typedef enum
{
    WKE_MSG_MOUSEMOVE       =  0x0200,
    WKE_MSG_LBUTTONDOWN     =  0x0201,
    WKE_MSG_LBUTTONUP       =  0x0202,
    WKE_MSG_LBUTTONDBLCLK   =  0x0203,
    WKE_MSG_RBUTTONDOWN     =  0x0204,
    WKE_MSG_RBUTTONUP       =  0x0205,
    WKE_MSG_RBUTTONDBLCLK   =  0x0206,
    WKE_MSG_MBUTTONDOWN     =  0x0207,
    WKE_MSG_MBUTTONUP       =  0x0208,
    WKE_MSG_MBUTTONDBLCLK   =  0x0209,
    WKE_MSG_MOUSEWHEEL      =  0x020A,

} wkeMouseMessage;

WKE_API bool           WKE_CALL wkeFireMouseEvent(wkeWebView* webView, wkeMouseMessage message, int x, int y, unsigned flags);
WKE_API bool           WKE_CALL wkeFireContextMenuEvent(wkeWebView* webView, int x, int y, unsigned flags);
WKE_API bool           WKE_CALL wkeFireMouseWheelEvent(wkeWebView* webView, int x, int y, int delta, unsigned flags);
WKE_API bool           WKE_CALL wkeFireKeyUpEvent(wkeWebView* webView, unsigned virtualKeyCode, unsigned flags, bool systemKey);
WKE_API bool           WKE_CALL wkeFireKeyDownEvent(wkeWebView* webView, unsigned virtualKeyCode, unsigned flags, bool systemKey);
WKE_API bool           WKE_CALL wkeFireKeyPressEvent(wkeWebView* webView, unsigned charCode, unsigned flags, bool systemKey);
WKE_API void*          WKE_CALL wkeFireInternalEvent(wkeWebView* webView, unsigned message, void* lparam, void* wparam);

//ҳ�����ı�ص�
WKE_API void           WKE_CALL wkeOnTitleChanged(wkeWebView* webView, void (WKE_CALL *TitleChangedCallback)(wkeWebView* webView, const wkeChar* title));

//ҳ��URL�ı�ص�
WKE_API void           WKE_CALL wkeOnURLChanged(wkeWebView* webView, void (WKE_CALL *UrlChangedCallback)(wkeWebView* webView, const wkeChar* url));

//ҳ������Ѹ��»ص�
WKE_API void           WKE_CALL wkeOnPaintUpdated(wkeWebView* webView, void (WKE_CALL *wkePaintUpdatedCallback)(wkeWebView* webView, const void* hdc, int x, int y, int cx, int cy));

//alertʵ�ֻص�
WKE_API void           WKE_CALL wkeOnAlertBox(wkeWebView* webView, void (WKE_CALL *AlertBoxCallback)(wkeWebView* webView, const wkeChar* message));

//confirmʵ�ֻص�
WKE_API void           WKE_CALL wkeOnConfirmBox(wkeWebView* webView, bool (WKE_CALL *wkeConfirmBoxCallback)(wkeWebView* webView, const wkeChar* message));

//promptʵ�ֻص������ص��ַ�������ʹ�� wkeMalloc �����ڴ�
WKE_API void WKE_CALL wkeOnPromptBox( wkeWebView* webView, bool (WKE_CALL *PromptBoxCallback)( wkeWebView* webView, const wchar_t* msg, const wchar_t* defaultResult, WTFString* result) );

//���ػص�
WKE_API void           WKE_CALL wkeOnDownloadFile(wkeWebView* webView, bool (WKE_CALL *wkeDownloadFileCallback)(wkeWebView* webView, const wkeChar* url, const wkeChar* mimeType));

//����̨��Ϣʵ�ֻص�
typedef enum 
{
    WKE_MESSAGE_SOURCE_HTML,
    WKE_MESSAGE_SOURCE_XML,
    WKE_MESSAGE_SOURCE_JS,
    WKE_MESSAGE_SOURCE_NETWORK,
    WKE_MESSAGE_SOURCE_CONSOLE_API,
    WKE_MESSAGE_SOURCE_OTHER

} wkeMessageSource;

typedef enum 
{
    WKE_MESSAGE_TYPE_LOG,
    WKE_MESSAGE_TYPE_DIR,
    WKE_MESSAGE_TYPE_DIR_XML,
    WKE_MESSAGE_TYPE_TRACE,
    WKE_MESSAGE_TYPE_START_GROUP,
    WKE_MESSAGE_TYPE_START_GROUP_COLLAPSED,
    WKE_MESSAGE_TYPE_END_GROUP,
    WKE_MESSAGE_TYPE_ASSERT

} wkeMessageType;

typedef enum 
{
    WKE_MESSAGE_LEVEL_TIP,
    WKE_MESSAGE_LEVEL_LOG,
    WKE_MESSAGE_LEVEL_WARNING,
    WKE_MESSAGE_LEVEL_ERROR,
    WKE_MESSAGE_LEVEL_DEBUG

} wkeMessageLevel;

typedef struct
{
    wkeMessageSource source;
    wkeMessageType type;
    wkeMessageLevel level;
    const wkeChar* message;
    const wkeChar* url;
    unsigned lineNumber;

} wkeConsoleMessage;


WKE_API void           WKE_CALL wkeOnConsoleMessage(wkeWebView* webView,  void (WKE_CALL *ConsoleMessageCallback)(wkeWebView* webView, const wkeConsoleMessage* message) );


//ҳ���ڷ��������ص�
typedef enum
{
    WKE_NAVIGATION_TYPE_LINKCLICK,
    WKE_NAVIGATION_TYPE_FORMSUBMITTE,
    WKE_NAVIGATION_TYPE_BACKFORWARD,
    WKE_NAVIGATION_TYPE_RELOAD,
    WKE_NAVIGATION_TYPE_FORMRESUBMITT,
    WKE_NAVIGATION_TYPE_OTHER

} wkeNavigationType;

//ָ������ʵ�ʶ���
typedef enum
{
    WKE_NAVIGATION_CONTINUE, //�����˵���
    WKE_NAVIGATION_ABORT,    //��ֹ�˵���
    WKE_NAVIGATION_DOWNLOAD  //�˵���ǿ��ת��Ϊ���أ����ᴥ�� wkeOnDownloadFile �ص�

} wkeNavigationAction;

typedef wkeNavigationAction (WKE_CALL *wkeNavigationCallback)(wkeWebView* webView, wkeNavigationType navigationType, const wkeChar* url);
WKE_API void           WKE_CALL wkeOnNavigation(wkeWebView* webView, wkeNavigationCallback callback);


//ҳ�����½�ҳ�洰�ڻص�
typedef struct  
{
    wkeNavigationType navigationType;
    const wkeChar* url;
    const wkeChar* target;

    wkeRect rectangle;

    bool menuBarVisible;
    bool statusBarVisible;
    bool toolBarVisible;
    bool locationBarVisible;
    bool scrollbarsVisible;
    bool resizable;
    bool fullscreen;

} wkeNewViewInfo;


//ҳ���ĵ�������ɻص�
typedef struct
{
    const wkeChar* url;
    wkeJSState* frameJSState;
    wkeJSState* mainFrameJSState;

} wkeDocumentReadyInfo;


WKE_API void           WKE_CALL wkeOnDocumentReady(wkeWebView* webView, void (WKE_CALL *DocumentReadyCallback)(wkeWebView* webView, const wkeDocumentReadyInfo* info) );


//ҳ���������ؽ������ɹ���ʧ�ܣ��ص�
WKE_API void           WKE_CALL wkeOnLoadingFinish(wkeWebView* webView, void (WKE_CALL *LoadingFinishCallback)(wkeWebView* webView, const wkeChar* url, bool failed, const wkeChar* failedReason) );


//JS��������
typedef enum
{
	WKE_JSTYPE_NUMBER,
	WKE_JSTYPE_STRING,
	WKE_JSTYPE_BOOLEAN,
	WKE_JSTYPE_OBJECT,
	WKE_JSTYPE_FUNCTION,
	WKE_JSTYPE_UNDEFINED,

} wkeJSType;

WKE_API wkeJSType      WKE_CALL wkeJSTypeOf(wkeJSState* es, wkeJSValue v);
WKE_API bool           WKE_CALL wkeJSIsNumber(wkeJSState* es, wkeJSValue v);
WKE_API bool           WKE_CALL wkeJSIsString(wkeJSState* es, wkeJSValue v);
WKE_API bool           WKE_CALL wkeJSIsBool(wkeJSState* es, wkeJSValue v);
WKE_API bool           WKE_CALL wkeJSIsObject(wkeJSState* es, wkeJSValue v);
WKE_API bool           WKE_CALL wkeJSIsFunction(wkeJSState* es, wkeJSValue v);
WKE_API bool           WKE_CALL wkeJSIsUndefined(wkeJSState* es, wkeJSValue v);
WKE_API bool           WKE_CALL wkeJSIsNull(wkeJSState* es, wkeJSValue v);
WKE_API bool           WKE_CALL wkeJSIsArray(wkeJSState* es, wkeJSValue v);
WKE_API bool           WKE_CALL wkeJSIsTrue(wkeJSState* es, wkeJSValue v);
WKE_API bool           WKE_CALL wkeJSIsFalse(wkeJSState* es, wkeJSValue v);

//��ȡJS����ֵ
WKE_API int            WKE_CALL wkeJSToInt(wkeJSState* es, wkeJSValue v);
WKE_API float          WKE_CALL wkeJSToFloat(wkeJSState* es, wkeJSValue v);
WKE_API double         WKE_CALL wkeJSToDouble(wkeJSState* es, wkeJSValue v);
WKE_API bool           WKE_CALL wkeJSToBool(wkeJSState* es, wkeJSValue v);
WKE_API const wkeChar* WKE_CALL wkeJSToTempString(wkeJSState* es, wkeJSValue v);

//����JS��������
WKE_API wkeJSValue     WKE_CALL wkeJSInt(wkeJSState* es, int n);
WKE_API wkeJSValue     WKE_CALL wkeJSFloat(wkeJSState* es, float f);
WKE_API wkeJSValue     WKE_CALL wkeJSDouble(wkeJSState* es, double d);
WKE_API wkeJSValue     WKE_CALL wkeJSBool(wkeJSState* es, bool b);
WKE_API wkeJSValue     WKE_CALL wkeJSUndefined(wkeJSState* es);
WKE_API wkeJSValue     WKE_CALL wkeJSNull(wkeJSState* es);
WKE_API wkeJSValue     WKE_CALL wkeJSTrue(wkeJSState* es);
WKE_API wkeJSValue     WKE_CALL wkeJSFalse(wkeJSState* es);
WKE_API wkeJSValue     WKE_CALL wkeJSString(wkeJSState* es, const wkeChar* str);
WKE_API wkeJSValue     WKE_CALL wkeJSEmptyObject(wkeJSState* es);
WKE_API wkeJSValue     WKE_CALL wkeJSEmptyArray(wkeJSState* es);

//��JS���󡢺���
typedef wkeJSValue    (WKE_CALL *wkeJSGetPropertyCallback)(wkeJSState* es, wkeJSValue object, const wkeChar* prop );
typedef bool          (WKE_CALL *wkeJSSetPropertyCallback)(wkeJSState* es, wkeJSValue object, const wkeChar* prop, wkeJSValue value );
typedef wkeJSValue    (WKE_CALL *wkeJSCallAsFunctionCallback)(wkeJSState* es, wkeJSValue object, wkeJSValue* args, int argCount);
typedef void          (WKE_CALL *wkeJSFinalizeCallback)(wkeJSData* data );


typedef struct __wkeJSData
{
	wkeJSGetPropertyCallback propertyGet;
	wkeJSSetPropertyCallback propertySet;
	wkeJSFinalizeCallback finalize;
	wkeJSCallAsFunctionCallback callAsFunction;
	void* userdata;
} wkeJSData;


WKE_API wkeJSValue     WKE_CALL wkeJSObject(wkeJSState* es, wkeJSData* data );
WKE_API wkeJSValue     WKE_CALL wkeJSFunction(wkeJSState* es, wkeJSData* data );
WKE_API wkeJSData*     WKE_CALL wkeJSGetData(wkeJSState* es, wkeJSValue object);

//WebView��������
WKE_API wkeWebView*    WKE_CALL wkeJSGetWebView(wkeJSState* es);

//ֱ��ִ��JS����
WKE_API wkeJSValue     WKE_CALL wkeJSEval(wkeJSState* es, const wkeChar* code);

//JS�������
WKE_API wkeJSValue     WKE_CALL wkeJSCall(wkeJSState* es, wkeJSValue object, wkeJSValue func, const wkeJSValue* args, int argCount);
WKE_API wkeJSValue     WKE_CALL wkeJSGet(wkeJSState* es, wkeJSValue object, const wkeChar* prop);
WKE_API void           WKE_CALL wkeJSSet(wkeJSState* es, wkeJSValue object, const wkeChar* prop, wkeJSValue value);
WKE_API wkeJSValue     WKE_CALL wkeJSGetAt(wkeJSState* es, wkeJSValue object, int index);
WKE_API void           WKE_CALL wkeJSSetAt(wkeJSState* es, wkeJSValue object, int index, wkeJSValue value);
WKE_API int            WKE_CALL wkeJSGetLength(wkeJSState* es, wkeJSValue object);
WKE_API void           WKE_CALL wkeJSSetLength(wkeJSState* es, wkeJSValue object, int length);

WKE_API wkeJSValue     WKE_CALL wkeJSGlobalObject(wkeJSState* es);
WKE_API wkeJSValue     WKE_CALL wkeJSCallGlobal(wkeJSState* es, wkeJSValue func, wkeJSValue* args, int argCount);
WKE_API wkeJSValue     WKE_CALL wkeJSGetGlobal(wkeJSState* es, const wkeChar* prop);
WKE_API void           WKE_CALL wkeJSSetGlobal(wkeJSState* es, const wkeChar* prop, wkeJSValue value);

//JS�����ռ����
WKE_API void           WKE_CALL  wkeJSAddRef(wkeJSState* es, wkeJSValue v);
WKE_API void           WKE_CALL  wkeJSReleaseRef(wkeJSState* es, wkeJSValue v);
WKE_API void           WKE_CALL  wkeJSCollectGarbge(); 




#ifdef __cplusplus
}
#endif


#endif//#ifndef WKE_H
