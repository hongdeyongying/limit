// ModulePath.cpp: implementation of the CModulePath class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ModulePath.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CModulePath * CModulePath::m_Instance = NULL;

CModulePath * CModulePath::GetInstance()
{
	if(m_Instance == NULL)
	{
		char szBuf[MAX_PATH] = {0};
		DWORD  dw = ::GetModuleFileName(NULL,szBuf,MAX_PATH);

		if(dw == 0) return NULL;
		
		char *p = strstr(szBuf,"\\Bin\\");

		if(!p) return NULL;

		string sExePath = szBuf;
		string sTopDir = string(szBuf,p);

		m_Instance = new CModulePath(sExePath,sTopDir);

	}

	return m_Instance;
}

CModulePath::CModulePath(string exe_path,string top_dir):m_sExePath(exe_path),m_sTopDir(top_dir)
{
	m_sBinDir = m_sTopDir + string("\\Bin");
	m_sCnfDir = m_sTopDir + string("\\Cnf");
	m_sDatDir = m_sTopDir + string("\\Dat");
	m_sLogDir = m_sTopDir + string("\\Log");
	m_sLibDir = m_sTopDir + string("\\Lib");
	m_sSesDir = m_sTopDir + string("\\Ses");

	SetCurrentDirectory(m_sBinDir.c_str());

}

CModulePath::~CModulePath()
{

}
