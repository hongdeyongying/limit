// Tracer.cpp: implementation of the CTracer class.
//
//////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "Tracer.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

#define MAX_LOG_SIZE    2049
#define LOG_FILE_PATH "./"
CTracer tracer;

CTracer::CTracer()
{
	memset(path,0,sizeof(path));
	memset(datetime,0,sizeof(datetime));
}

CTracer::~CTracer()
{
	memset(path,0,sizeof(path));
	memset(datetime,0,sizeof(datetime));
}

void CTracer::Out(char *fmt, ... )
{
	CSingleEntry  keep_one_thread;

	FILE *fp;
	char sFileName[PATH_MAX_SIZE];
	char buf[TRACER_MAX_BUF_SIZE];

	memset(buf,0,sizeof(buf));
	GetTime();

	va_list  ap;
	if (*fmt) 
	{
	 	va_start(ap,fmt);
//	 	vsprintf(buf,fmt, ap);
	 	_vsnprintf(buf,sizeof(buf)-1,fmt, ap);
	 	va_end(ap);
	}
	
	//Write log to file
	if(strlen(path)==0)
		_snprintf(sFileName,sizeof(sFileName),"%strc_00.log",LOG_FILE_PATH);
	else
		_snprintf(sFileName,sizeof(sFileName),"%s",path);


	if (( fp = fopen(sFileName,"a+")) == NULL)  
		return ;


	fprintf(fp,"\r\n%s%s\r\n",datetime,buf);
	fclose(fp);

	return;	
}


void CTracer::Init(const char * dir)
{
	logMode = 0;
	strncpy(path,dir,sizeof(path));
}


int CTracer::GetMMDD(char *mmdd)
{
	time_t    Time;
    struct tm *T;
    char 	date[30];
    
    memset(date,0,sizeof(date));

    time(&Time);
    T=localtime(&Time);
    sprintf(date, "%02d%02d",T->tm_mon+1,T->tm_mday);
    
    strcpy(mmdd,date);
    //free(T);
    return(0);
}

int CTracer::GetTime()
{
	time_t    Time;
    struct tm *T;
    char    tt[10];
    char 	date[30];
    
    memset(date,0,sizeof(date));

    time(&Time);
    T=localtime(&Time);
    sprintf(date, "%04d-%02d-%02d",T->tm_year+1900,T->tm_mon+1,T->tm_mday);
    sprintf(tt, " %02d:%02d:%02d", T->tm_hour, T->tm_min, T->tm_sec);
    strcat(date, tt);

	memset(datetime,0,sizeof(datetime));
    
    strcpy(datetime,date);
    //free(T);
    return(0);
}

int CTracer::GetYYMM(char *yymm)
{
	time_t    Time;
    struct tm *T;
    char 	date[30];
    
    memset(date,0,sizeof(date));

    time(&Time);
    T=localtime(&Time);
    sprintf(date, "%04d%02d",T->tm_year+1900,T->tm_mon+1);
    
    strcpy(yymm,date+2);
    //free(T);
    return(0);
}

void CTracer::HexOut(const char * hexbuf,int len)
{
	char * tmpbuf;
	tmpbuf=(char *)malloc(2*len+3);
	memset(tmpbuf,0,2*len+3);
	*tmpbuf='[';
	AsciiToBcd2(hexbuf,len,tmpbuf+1);
	*(tmpbuf+2*len+1)=']';
	Out("%s",tmpbuf);
	free(tmpbuf);
}

void CTracer::HexOut(const char * caption,const char * hexbuf,int len)
{
	char * tmpbuf;
	tmpbuf=(char *)malloc(2*len+3);
	memset(tmpbuf,0,2*len+3);
	*tmpbuf='[';
	AsciiToBcd2(hexbuf,len,tmpbuf+1);
	*(tmpbuf+2*len+1)=']';
	Out("%s %s",caption,tmpbuf);
	free(tmpbuf);
}
void CTracer::HexOut(int type,const char * caption,const char * hexbuf,int len)
{
        char * tmpbuf;
	tmpbuf=(char *)malloc(2*len+3);
	memset(tmpbuf,0,2*len+3);
	*tmpbuf='[';
	AsciiToBcd2(hexbuf,len,tmpbuf+1);
	*(tmpbuf+2*len+1)=']';
	Out("%s %s",caption,tmpbuf);
	free(tmpbuf);
}
void CTracer::HexOut(int type, const char * hexbuf,int len)
{
	char * tmpbuf;
	tmpbuf=(char *)malloc(2*len+3);
	memset(tmpbuf,0,2*len+3);
	*tmpbuf='[';
	AsciiToBcd2(hexbuf,len,tmpbuf+1);
	*(tmpbuf+2*len+1)=']';
	Out("%s",tmpbuf);
	free(tmpbuf);
}

int CTracer::AsciiToBcd2(const char *ascii, int len, char *bcd)
{
	char *tbl="0123456789ABCDEF";
	unsigned char t;
	for(int i=0;i<len;i++)
	{
		t=(ascii[i]&(0xf0));
		t=t>>4;
		bcd[2*i]=*(tbl+t);
		t=(ascii[i]&(0x0f));
		bcd[2*i+1]=*(tbl+t);		
	}	
	return (2*len);
}

int CTracer::Bcd2ToAscii(const char *bcd, int len, int align, char *ascii)
{
	char *tbl="0123456789ABCDEF";
	int i,j;
	char *tmpbuf;
	tmpbuf=(char *) malloc((len+1)*sizeof(char));
	memset(tmpbuf,'0',len+1);
	if((align!=0)&&(len%2)!=0)//ÓÒ¶ÔÆë
	{
		memcpy(tmpbuf+1,bcd,len);
	}
	else	//×ó¶ÔÆë
	{
		memcpy(tmpbuf,bcd,len);
	}
	for(i=0;i<((len+1)/2);i++)
	{
		for(j=0;j<16;j++)
			if(*(tbl+j)==tmpbuf[2*i])
				break;
		if(j==16)
		{
			free(tmpbuf);
			return -1;
		}
		ascii[i]=j;
		ascii[i] = ascii[i] << 4;
		for(j=0;j<16;j++)
			if(*(tbl+j)==tmpbuf[2*i+1])
				break;
		if(j==16)
		{
			free(tmpbuf);
			return -1;
		}
		ascii[i] += j;
	}	
	free(tmpbuf);
	return (len+1)/2;
}
