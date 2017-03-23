# Microsoft Developer Studio Project File - Name="MyODBII" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=MyODBII - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "MyODBII.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "MyODBII.mak" CFG="MyODBII - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "MyODBII - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "MyODBII - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "MyODBII - Win32 Release"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386 /out:"F:\SOFT\MyOBDII\Bin\MyODBII.exe" /FORCE:MULTIPLE
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "MyODBII - Win32 Debug"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GR /GX /ZI /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR /FD /GZ /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /out:"F:\SOFT\MyOBDII\Bin\MyODBII.exe" /pdbtype:sept /FORCE:MULTIPLE
# SUBTRACT LINK32 /profile /pdb:none /incremental:no /map

!ENDIF 

# Begin Target

# Name "MyODBII - Win32 Release"
# Name "MyODBII - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\BaseFormat.cpp
# End Source File
# Begin Source File

SOURCE=.\CarInfoDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\CarInfoFrame.cpp
# End Source File
# Begin Source File

SOURCE=.\CarInfoView.cpp
# End Source File
# Begin Source File

SOURCE=.\common\html\CAttribute.cpp
# End Source File
# Begin Source File

SOURCE=.\common\html\CBase.cpp
# End Source File
# Begin Source File

SOURCE=.\common\utility\CBaseEncode.cpp
# End Source File
# Begin Source File

SOURCE=.\common\utility\CCommandLineInfo.cpp
# End Source File
# Begin Source File

SOURCE=.\common\fileconfig\CConfigElement.cpp
# End Source File
# Begin Source File

SOURCE=.\common\fileconfig\CConfigEntry.cpp
# End Source File
# Begin Source File

SOURCE=.\common\html\CElement.cpp
# End Source File
# Begin Source File

SOURCE=.\common\utility\CFactory.cpp
# End Source File
# Begin Source File

SOURCE=.\ChildFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\common\html\CHtml.cpp
# End Source File
# Begin Source File

SOURCE=.\common\html\CHtmlTagMap.cpp
# End Source File
# Begin Source File

SOURCE=.\common\utility\CMyException.cpp
# End Source File
# Begin Source File

SOURCE=.\common\utility\CMySmartPoint.cpp
# End Source File
# Begin Source File

SOURCE=.\common\html\CNode.cpp
# End Source File
# Begin Source File

SOURCE=.\CODBIIRawdata.cpp
# End Source File
# Begin Source File

SOURCE=.\CODBIIRawdataVector.cpp
# End Source File
# Begin Source File

SOURCE=.\common\fileconfig\CParamerter.cpp
# End Source File
# Begin Source File

SOURCE=.\CSensorData.cpp
# End Source File
# Begin Source File

SOURCE=.\CSensorDataVectorMap.cpp
# End Source File
# Begin Source File

SOURCE=.\common\CSerial.cpp
# End Source File
# Begin Source File

SOURCE=.\common\fileconfig\CService.cpp
# End Source File
# Begin Source File

SOURCE=.\common\utility\CStringMap.cpp
# End Source File
# Begin Source File

SOURCE=.\common\utility\CStringVector.cpp
# End Source File
# Begin Source File

SOURCE=.\common\utility\CStringVectorMap.cpp
# End Source File
# Begin Source File

SOURCE=.\common\html\CTag.cpp
# End Source File
# Begin Source File

SOURCE=.\common\html\CText.cpp
# End Source File
# Begin Source File

SOURCE=.\common\fileconfig\CVariable.cpp
# End Source File
# Begin Source File

SOURCE=.\ErrorCodeDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\ErrorCodeFrame.cpp
# End Source File
# Begin Source File

SOURCE=.\ErrorCodeView.cpp
# End Source File
# Begin Source File

SOURCE=.\global_var.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\ModulePath.cpp
# End Source File
# Begin Source File

SOURCE=.\MyOBDIICommThread.cpp
# End Source File
# Begin Source File

SOURCE=.\MyOBDIIFrame.cpp
# End Source File
# Begin Source File

SOURCE=.\MyODBII.cpp
# End Source File
# Begin Source File

SOURCE=.\MyODBII.rc
# End Source File
# Begin Source File

SOURCE=.\MyODBIIDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\MyODBIIView.cpp
# End Source File
# Begin Source File

SOURCE=.\MyWinThread.cpp
# End Source File
# Begin Source File

SOURCE=.\OBDIIFormat.cpp
# End Source File
# Begin Source File

SOURCE=.\OBDIIFormat_0114.cpp
# End Source File
# Begin Source File

SOURCE=.\OBDIIFormat_0121.cpp
# End Source File
# Begin Source File

SOURCE=.\OBDIIFormat_0130.cpp
# End Source File
# Begin Source File

SOURCE=.\OBDIIFormat_0153.cpp
# End Source File
# Begin Source File

SOURCE=.\OBDIIFormat_02.cpp
# End Source File
# Begin Source File

SOURCE=.\OBDIIFormat_09.cpp
# End Source File
# Begin Source File

SOURCE=.\SensorsDataDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\SensorsDataFrame.cpp
# End Source File
# Begin Source File

SOURCE=.\SensorsDataView.cpp
# End Source File
# Begin Source File

SOURCE=.\SettingDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\BaseFormat.h
# End Source File
# Begin Source File

SOURCE=.\CarInfoDoc.h
# End Source File
# Begin Source File

SOURCE=.\CarInfoFrame.h
# End Source File
# Begin Source File

SOURCE=.\CarInfoView.h
# End Source File
# Begin Source File

SOURCE=.\common\html\CAttribute.h
# End Source File
# Begin Source File

SOURCE=.\common\html\CBase.h
# End Source File
# Begin Source File

SOURCE=.\common\utility\CBaseEncode.h
# End Source File
# Begin Source File

SOURCE=.\common\utility\CCommandLineInfo.h
# End Source File
# Begin Source File

SOURCE=.\common\fileconfig\CConfigElement.h
# End Source File
# Begin Source File

SOURCE=.\common\fileconfig\CConfigElementMap.h
# End Source File
# Begin Source File

SOURCE=.\common\fileconfig\CConfigEntry.h
# End Source File
# Begin Source File

SOURCE=.\common\html\CElement.h
# End Source File
# Begin Source File

SOURCE=.\ChildFrm.h
# End Source File
# Begin Source File

SOURCE=.\common\html\CHtml.h
# End Source File
# Begin Source File

SOURCE=.\common\html\CHtmlTagMap.h
# End Source File
# Begin Source File

SOURCE=.\common\utility\CLocalIP.h
# End Source File
# Begin Source File

SOURCE=.\common\utility\CMyException.h
# End Source File
# Begin Source File

SOURCE=.\CMyMessage.h
# End Source File
# Begin Source File

SOURCE=.\common\utility\CMySmartPoint.h
# End Source File
# Begin Source File

SOURCE=.\common\html\CNode.h
# End Source File
# Begin Source File

SOURCE=.\CODBIIRawdata.h
# End Source File
# Begin Source File

SOURCE=.\CODBIIRawdataVector.h
# End Source File
# Begin Source File

SOURCE=.\common\fileconfig\CParamerter.h
# End Source File
# Begin Source File

SOURCE=.\common\fileconfig\CParameterMap.h
# End Source File
# Begin Source File

SOURCE=.\CSensorData.h
# End Source File
# Begin Source File

SOURCE=.\CSensorDataVector.h
# End Source File
# Begin Source File

SOURCE=.\CSensorDataVectorMap.h
# End Source File
# Begin Source File

SOURCE=.\common\CSerial.h
# End Source File
# Begin Source File

SOURCE=.\common\fileconfig\CService.h
# End Source File
# Begin Source File

SOURCE=.\common\fileconfig\CServiceMap.h
# End Source File
# Begin Source File

SOURCE=.\common\utility\CStdMapCStringVector.h
# End Source File
# Begin Source File

SOURCE=.\common\utility\CStdMapString.h
# End Source File
# Begin Source File

SOURCE=.\common\utility\CStdVectorString.h
# End Source File
# Begin Source File

SOURCE=.\common\utility\CStringMap.h
# End Source File
# Begin Source File

SOURCE=.\common\utility\CStringVector.h
# End Source File
# Begin Source File

SOURCE=.\common\utility\CStringVectorMap.h
# End Source File
# Begin Source File

SOURCE=.\common\html\CTag.h
# End Source File
# Begin Source File

SOURCE=.\common\html\CTagMap.h
# End Source File
# Begin Source File

SOURCE=.\common\html\CText.h
# End Source File
# Begin Source File

SOURCE=.\common\utility\CTime.h
# End Source File
# Begin Source File

SOURCE=.\common\fileconfig\CVariable.h
# End Source File
# Begin Source File

SOURCE=.\common\fileconfig\CVariableMap.h
# End Source File
# Begin Source File

SOURCE=.\common\utility\CVectorString.h
# End Source File
# Begin Source File

SOURCE=.\ErrorCodeDoc.h
# End Source File
# Begin Source File

SOURCE=.\ErrorCodeFrame.h
# End Source File
# Begin Source File

SOURCE=.\ErrorCodeView.h
# End Source File
# Begin Source File

SOURCE=.\common\html\ESTATE.h
# End Source File
# Begin Source File

SOURCE=.\common\html\ESYMBOL.h
# End Source File
# Begin Source File

SOURCE=.\common\html\ETAG.h
# End Source File
# Begin Source File

SOURCE=.\global_var.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\ModulePath.h
# End Source File
# Begin Source File

SOURCE=.\MyOBDIICommThread.h
# End Source File
# Begin Source File

SOURCE=.\MyOBDIIFrame.h
# End Source File
# Begin Source File

SOURCE=.\MyODBII.h
# End Source File
# Begin Source File

SOURCE=.\MyODBIIDoc.h
# End Source File
# Begin Source File

SOURCE=.\MyODBIIViewLog.h
# End Source File
# Begin Source File

SOURCE=.\common\fileconfig\mysoft_config.h
# End Source File
# Begin Source File

SOURCE=.\common\html\mysoft_html.h
# End Source File
# Begin Source File

SOURCE=.\common\utility\mysoft_utility.h
# End Source File
# Begin Source File

SOURCE=.\MyWinThread.h
# End Source File
# Begin Source File

SOURCE=.\OBDIIFormat.h
# End Source File
# Begin Source File

SOURCE=.\OBDIIFormat_0114.h
# End Source File
# Begin Source File

SOURCE=.\OBDIIFormat_0121.h
# End Source File
# Begin Source File

SOURCE=.\OBDIIFormat_0130.h
# End Source File
# Begin Source File

SOURCE=.\OBDIIFormat_0153.h
# End Source File
# Begin Source File

SOURCE=.\OBDIIFormat_02.h
# End Source File
# Begin Source File

SOURCE=.\OBDIIFormat_09.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\SensorsDataDoc.h
# End Source File
# Begin Source File

SOURCE=.\SensorsDataFrame.h
# End Source File
# Begin Source File

SOURCE=.\SensorsDataView.h
# End Source File
# Begin Source File

SOURCE=.\SettingDlg.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\MyODBII.ico
# End Source File
# Begin Source File

SOURCE=.\res\MyODBII.rc2
# End Source File
# Begin Source File

SOURCE=.\res\MyODBIIDoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\myodbity.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=.\MyODBII.reg
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
