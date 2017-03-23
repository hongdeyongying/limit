# Microsoft Developer Studio Project File - Name="Analyzer" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Analyzer - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Analyzer.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Analyzer.mak" CFG="Analyzer - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Analyzer - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Analyzer - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Analyzer - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "Analyzer - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GR /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 libeay32.lib ssleay32.lib Ws2_32.lib /nologo /subsystem:windows /debug /machine:I386 /out:"../SETUP/Bin/Analyzer.exe" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "Analyzer - Win32 Release"
# Name "Analyzer - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\Analyzer.cpp
# End Source File
# Begin Source File

SOURCE=.\Analyzer.rc
# End Source File
# Begin Source File

SOURCE=.\AnalyzerDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\html\CAttribute.cpp
# End Source File
# Begin Source File

SOURCE=.\html\CBase.cpp
# End Source File
# Begin Source File

SOURCE=.\html\CElement.cpp
# End Source File
# Begin Source File

SOURCE=.\html\CHtml.cpp
# End Source File
# Begin Source File

SOURCE=.\html\CHtmlTagMap.cpp
# End Source File
# Begin Source File

SOURCE=.\myFlow\CMyAny.cpp
# End Source File
# Begin Source File

SOURCE=.\myFlow\CMyDispatcher.cpp
# End Source File
# Begin Source File

SOURCE=.\myFlow\CMyExpression.cpp
# End Source File
# Begin Source File

SOURCE=.\myFlow\CMyHtml2XmlWorker.cpp
# End Source File
# Begin Source File

SOURCE=.\myFlow\CMyVarSpace.cpp
# End Source File
# Begin Source File

SOURCE=.\myFlow\CMyWorker.cpp
# End Source File
# Begin Source File

SOURCE=.\html\CNode.cpp
# End Source File
# Begin Source File

SOURCE=.\myFlow\httpcall\Connection.cpp
# End Source File
# Begin Source File

SOURCE=.\html\CTag.cpp
# End Source File
# Begin Source File

SOURCE=.\html\CText.cpp
# End Source File
# Begin Source File

SOURCE=.\myFlow\httpcall\HttpClient.cpp
# End Source File
# Begin Source File

SOURCE=.\ModulePath.cpp
# End Source File
# Begin Source File

SOURCE=.\SingleEntry.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\StrArray.cpp
# End Source File
# Begin Source File

SOURCE=.\XML\tinystr.cpp
# End Source File
# Begin Source File

SOURCE=.\XML\tinyxml.cpp
# End Source File
# Begin Source File

SOURCE=.\XML\tinyxmlerror.cpp
# End Source File
# Begin Source File

SOURCE=.\XML\tinyxmlparser.cpp
# End Source File
# Begin Source File

SOURCE=.\Tracer\Tracer.cpp
# End Source File
# Begin Source File

SOURCE=.\Utility.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\Analyzer.h
# End Source File
# Begin Source File

SOURCE=.\AnalyzerDlg.h
# End Source File
# Begin Source File

SOURCE=.\html\CAttribute.h
# End Source File
# Begin Source File

SOURCE=.\html\CBase.h
# End Source File
# Begin Source File

SOURCE=.\html\CElement.h
# End Source File
# Begin Source File

SOURCE=.\html\CHtml.h
# End Source File
# Begin Source File

SOURCE=.\html\CHtmlTagMap.h
# End Source File
# Begin Source File

SOURCE=.\myFlow\CMyAny.h
# End Source File
# Begin Source File

SOURCE=.\myFlow\CMyAnyMap.h
# End Source File
# Begin Source File

SOURCE=.\myFlow\CMyDispatcher.h
# End Source File
# Begin Source File

SOURCE=.\myFlow\CMyExpression.h
# End Source File
# Begin Source File

SOURCE=.\myFlow\CMyHtml2XmlWorker.h
# End Source File
# Begin Source File

SOURCE=.\myFlow\CMyVarSpace.h
# End Source File
# Begin Source File

SOURCE=.\myFlow\CMyWorker.h
# End Source File
# Begin Source File

SOURCE=.\html\CNode.h
# End Source File
# Begin Source File

SOURCE=.\myFlow\httpcall\Connection.h
# End Source File
# Begin Source File

SOURCE=.\html\CTag.h
# End Source File
# Begin Source File

SOURCE=.\html\CTagMap.h
# End Source File
# Begin Source File

SOURCE=.\html\CText.h
# End Source File
# Begin Source File

SOURCE=.\html\ESTATE.h
# End Source File
# Begin Source File

SOURCE=.\html\ESYMBOL.h
# End Source File
# Begin Source File

SOURCE=.\html\ETAG.h
# End Source File
# Begin Source File

SOURCE=.\myFlow\EVarType.h
# End Source File
# Begin Source File

SOURCE=.\myFlow\httpcall\HttpClient.h
# End Source File
# Begin Source File

SOURCE=.\ModulePath.h
# End Source File
# Begin Source File

SOURCE=.\html\mysoft_html.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\SingleEntry.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\StrArray.h
# End Source File
# Begin Source File

SOURCE=.\XML\tinystr.h
# End Source File
# Begin Source File

SOURCE=.\XML\tinyxml.h
# End Source File
# Begin Source File

SOURCE=.\Tracer\Tracer.h
# End Source File
# Begin Source File

SOURCE=.\Utility.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\Analyzer.ico
# End Source File
# Begin Source File

SOURCE=.\res\Analyzer.rc2
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
