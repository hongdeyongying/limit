// BaseFormat.cpp: implementation of the CBaseFormat class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MyODBII.h"
#include "BaseFormat.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
//CBaseFormat * CBaseFormat::m_pCBaseFormat = NULL;

CBaseFormat::CBaseFormat()
{
}

CBaseFormat::~CBaseFormat()
{

}


CStringMethodMap g_CBaseFormatFactory;
CStringInstanceMap g_CStringInstanceMap;





CBaseFormatFactory<CBaseFormat> g_Factory("CBaseFormat");

//MyUtility::CFactory <CBaseFormat,CBaseFormat> g_CBaseFormatFactory("CBaseFormat","CBaseFormat");