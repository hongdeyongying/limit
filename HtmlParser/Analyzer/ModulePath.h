// ModulePath.h: interface for the CModulePath class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MODULEPATH_H__360F72B8_F3BE_4D64_A9ED_FF7840C29485__INCLUDED_)
#define AFX_MODULEPATH_H__360F72B8_F3BE_4D64_A9ED_FF7840C29485__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
#include <iostream>
using namespace std;

class CModulePath  
{
protected:
	CModulePath(string exe_path,string top_dir);
public:
	virtual ~CModulePath();

	static CModulePath * GetInstance();


	
	string m_sExePath;
	string m_sTopDir;
	string m_sDatDir;
	string m_sLogDir;
	string m_sCnfDir;
	string m_sBinDir;
	string m_sLibDir;
	string m_sSesDir;
	string m_sTmpDir;

private:
	static CModulePath * m_Instance;


};

#endif // !defined(AFX_MODULEPATH_H__360F72B8_F3BE_4D64_A9ED_FF7840C29485__INCLUDED_)
