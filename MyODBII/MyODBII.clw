; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCarInfoView
LastTemplate=CFormView
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MyODBII.h"
LastPage=0

ClassCount=17
Class1=CMyODBIIApp
Class2=CMyODBIIDoc
Class3=CMyODBIIViewLog
Class4=CMainFrame
Class7=CSensorsDataView
Class9=CSensorsDataDoc

ResourceCount=7
Resource1=IDR_MAINFRAME
Resource2=IDD_DIALOG_SETTING
Class10=CErrorCodeDoc
Class11=CErrorCodeFrame
Class12=CSensorsDataFrame
Class13=CMyOBDIIFrame
Resource3=IDD_ABOUTBOX
Class5=CChildFrame
Class6=CAboutDlg
Class8=CErrorCodeView
Class14=CSettingDlg
Resource4=IDR_MYODBITYPE
Resource5=IDR_ERRCDTYPE
Class15=CCarInfoFrame
Class16=CCarInfoDoc
Class17=CCarInfoView
Resource6=IDR_SENSORTYPE
Resource7=FORM_CAR_INFO

[CLS:CMyODBIIApp]
Type=0
HeaderFile=MyODBII.h
ImplementationFile=MyODBII.cpp
Filter=N
BaseClass=CWinApp
VirtualFilter=AC
LastObject=BTN_CAPTURE

[CLS:CMyODBIIDoc]
Type=0
HeaderFile=MyODBIIDoc.h
ImplementationFile=MyODBIIDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC

[CLS:CMyODBIIViewLog]
Type=0
HeaderFile=MyODBIIViewLog.h
ImplementationFile=MyODBIIView.cpp
Filter=C
BaseClass=CListView
VirtualFilter=VWC
LastObject=ID_VIEW_TOOLBAR


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CMDIFrameWnd
VirtualFilter=fWC
LastObject=MENU_VIEW_CAR_INFO


[CLS:CChildFrame]
Type=0
HeaderFile=ChildFrm.h
ImplementationFile=ChildFrm.cpp
Filter=M


[CLS:CAboutDlg]
Type=0
HeaderFile=MyODBII.cpp
ImplementationFile=MyODBII.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_PRINT_SETUP
Command4=ID_FILE_MRU_FILE1
Command5=ID_APP_EXIT
Command6=MENU_VIEW_LOG
Command7=MENU_VIEW_SENSORS
Command8=MENU_VIEW_TROUBLE_CODE
Command9=ID_VIEW_TOOLBAR
Command10=ID_VIEW_STATUS_BAR
Command11=MENU_VIEW_CAR_INFO
Command12=ID_APP_ABOUT
Command13=MENU_COMM_CONFIG
Command14=MENU_ODBII_BEGIN
Command15=MENU_ODBII_END
Command16=MENU_CLEAR_TCD
CommandCount=16

[TB:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_APP_ABOUT
Command5=MENU_COMM_CONFIG
Command6=MENU_ODBII_BEGIN
Command7=MENU_ODBII_END
CommandCount=7

[MNU:IDR_MYODBITYPE]
Type=1
Class=CMyODBIIViewLog
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_CLOSE
Command4=ID_FILE_SAVE
Command5=ID_FILE_SAVE_AS
Command6=ID_FILE_PRINT
Command7=ID_FILE_PRINT_PREVIEW
Command8=ID_FILE_PRINT_SETUP
Command9=ID_FILE_MRU_FILE1
Command10=ID_APP_EXIT
Command11=ID_EDIT_UNDO
Command12=ID_EDIT_CUT
Command13=ID_EDIT_COPY
Command14=ID_EDIT_PASTE
Command15=MENU_VIEW_LOG
Command16=MENU_VIEW_SENSORS
Command17=MENU_VIEW_TROUBLE_CODE
Command18=ID_VIEW_TOOLBAR
Command19=ID_VIEW_STATUS_BAR
Command20=ID_WINDOW_NEW
Command21=ID_WINDOW_CASCADE
Command22=ID_WINDOW_TILE_HORZ
Command23=ID_WINDOW_ARRANGE
Command24=ID_APP_ABOUT
Command25=MENU_COMM_CONFIG
Command26=MENU_ODBII_BEGIN
Command27=MENU_ODBII_END
Command28=MENU_CLEAR_TCD
CommandCount=28

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[CLS:CSensorsDataView]
Type=0
HeaderFile=SensorsDataView.h
ImplementationFile=SensorsDataView.cpp
BaseClass=CListView
Filter=C
VirtualFilter=VWC
LastObject=MENU_REFRESH

[CLS:CErrorCodeView]
Type=0
HeaderFile=ErrorCodeView.h
ImplementationFile=ErrorCodeView.cpp
BaseClass=CListView
Filter=C
VirtualFilter=VWC
LastObject=MENU_REFRESH

[CLS:CSensorsDataDoc]
Type=0
HeaderFile=SensorsDataDoc.h
ImplementationFile=SensorsDataDoc.cpp
BaseClass=CDocument
Filter=N

[CLS:CErrorCodeDoc]
Type=0
HeaderFile=ErrorCodeDoc.h
ImplementationFile=ErrorCodeDoc.cpp
BaseClass=CDocument
Filter=N

[CLS:CErrorCodeFrame]
Type=0
HeaderFile=ErrorCodeFrame.h
ImplementationFile=ErrorCodeFrame.cpp
BaseClass=CMDIChildWnd
Filter=M

[CLS:CSensorsDataFrame]
Type=0
HeaderFile=SensorsDataFrame.h
ImplementationFile=SensorsDataFrame.cpp
BaseClass=CMDIChildWnd
Filter=M

[CLS:CMyOBDIIFrame]
Type=0
HeaderFile=MyOBDIIFrame.h
ImplementationFile=MyOBDIIFrame.cpp
BaseClass=CMDIChildWnd
Filter=T
VirtualFilter=fWC
LastObject=CMyOBDIIFrame

[DLG:IDD_DIALOG_SETTING]
Type=1
Class=CSettingDlg
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT_COM,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT_BOUNDRATE,edit,1350631552

[CLS:CSettingDlg]
Type=0
HeaderFile=SettingDlg.h
ImplementationFile=SettingDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT_COM
VirtualFilter=dWC

[TB:IDR_MYODBITYPE]
Type=1
Class=?
Command1=BTN_CAPTURE
Command2=BTN_STOP
CommandCount=2

[MNU:IDR_SENSORTYPE]
Type=1
Class=CSensorsDataView
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_CLOSE
Command4=ID_FILE_SAVE
Command5=ID_FILE_SAVE_AS
Command6=ID_FILE_PRINT
Command7=ID_FILE_PRINT_PREVIEW
Command8=ID_FILE_PRINT_SETUP
Command9=ID_FILE_MRU_FILE1
Command10=ID_APP_EXIT
Command11=ID_EDIT_UNDO
Command12=ID_EDIT_CUT
Command13=ID_EDIT_COPY
Command14=ID_EDIT_PASTE
Command15=MENU_VIEW_LOG
Command16=MENU_VIEW_SENSORS
Command17=MENU_VIEW_TROUBLE_CODE
Command18=ID_VIEW_TOOLBAR
Command19=ID_VIEW_STATUS_BAR
Command20=MENU_REFRESH
Command21=ID_WINDOW_NEW
Command22=ID_WINDOW_CASCADE
Command23=ID_WINDOW_TILE_HORZ
Command24=ID_WINDOW_ARRANGE
Command25=ID_APP_ABOUT
Command26=MENU_COMM_CONFIG
Command27=MENU_ODBII_BEGIN
Command28=MENU_ODBII_END
Command29=MENU_CLEAR_TCD
CommandCount=29

[MNU:IDR_ERRCDTYPE]
Type=1
Class=CErrorCodeView
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_CLOSE
Command4=ID_FILE_SAVE
Command5=ID_FILE_SAVE_AS
Command6=ID_FILE_PRINT
Command7=ID_FILE_PRINT_PREVIEW
Command8=ID_FILE_PRINT_SETUP
Command9=ID_FILE_MRU_FILE1
Command10=ID_APP_EXIT
Command11=ID_EDIT_UNDO
Command12=ID_EDIT_CUT
Command13=ID_EDIT_COPY
Command14=ID_EDIT_PASTE
Command15=MENU_VIEW_LOG
Command16=MENU_VIEW_SENSORS
Command17=MENU_VIEW_TROUBLE_CODE
Command18=ID_VIEW_TOOLBAR
Command19=ID_VIEW_STATUS_BAR
Command20=MENU_REFRESH
Command21=ID_WINDOW_NEW
Command22=ID_WINDOW_CASCADE
Command23=ID_WINDOW_TILE_HORZ
Command24=ID_WINDOW_ARRANGE
Command25=ID_APP_ABOUT
Command26=MENU_COMM_CONFIG
Command27=MENU_ODBII_BEGIN
Command28=MENU_ODBII_END
Command29=MENU_CLEAR_TCD
CommandCount=29

[CLS:CCarInfoFrame]
Type=0
HeaderFile=CarInfoFrame.h
ImplementationFile=CarInfoFrame.cpp
BaseClass=CMDIChildWnd
Filter=M
VirtualFilter=mfWC

[CLS:CCarInfoDoc]
Type=0
HeaderFile=CarInfoDoc.h
ImplementationFile=CarInfoDoc.cpp
BaseClass=CDocument
Filter=N

[CLS:CCarInfoView]
Type=0
HeaderFile=CarInfoView.h
ImplementationFile=CarInfoView.cpp
BaseClass=CFormView
Filter=D
VirtualFilter=VWC
LastObject=IDC_LIST_DAT_CI

[DLG:FORM_CAR_INFO]
Type=1
Class=CCarInfoView
ControlCount=1
Control1=IDC_LIST_DAT_CI,SysListView32,1350631425

