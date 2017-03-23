// Tracer.h: interface for the CTracer class.

//

//////////////////////////////////////////////////////////////////////



#if !defined(AFX_TRACER_H__4095FBF6_B440_4E76_9E1D_1CA25F8A0393__INCLUDED_)

#define AFX_TRACER_H__4095FBF6_B440_4E76_9E1D_1CA25F8A0393__INCLUDED_



#if _MSC_VER > 1000

#pragma once

#endif // _MSC_VER > 1000





#include <stdarg.h>

#include <time.h>

#include <string.h>

#include <stdio.h> 

#include <stdlib.h>

#include "SingleEntry.h"

#define TRACER_MAX_BUF_SIZE 402400
#define PATH_MAX_SIZE	1024

class CTracer  

{
public:

	void HexOut(int type,const char * hexbuf,int len);

	void HexOut(const char * hexbuf,int len);

	void HexOut(int type,const char * caption,const char * hexbuf,int len);

	void HexOut(const char * caption,const char * hexbuf,int len);


	void Out(char * fmt,...);

	CTracer();
	
	void Init(const char * dir);

	virtual ~CTracer();



private:


	char datetime[30];

	char path[256];

	char m_strLogsvrIP[30];  

	char m_strLogsvrPort[30];

	int  logMode;



	int Bcd2ToAscii(const char *bcd,int len,int align,char *ascii);

	int AsciiToBcd2(const char *ascii,int len,char *bcd);

	int GetYYMM(char *yymm);

	int GetTime();

	int GetMMDD(char * mmdd);


};

extern CTracer tracer;

#endif // !defined(AFX_TRACER_H__4095FBF6_B440_4E76_9E1D_1CA25F8A0393__INCLUDED_)

