// HttpClient.cpp: implementation of the CHttpClient class.
//
//////////////////////////////////////////////////////////////////////

#ifdef WIN32
#include "StdAfx.h"
#endif
#include "HttpClient.h"
/*
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif
*/

#include "Connection.h"


#include "CHtml.h"

#include "gzip_mem.h"


//#include <iostream>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CHttpClient::CHttpClient()
{
	m_sSesDir= "./";
}

CHttpClient::~CHttpClient()
{

}

int CHttpClient::SendAndRecv()
{
	m_iStatus = -1;
	CConnection conn;

	//LoadSession();


	string sHead,sPara;

	string sCont;

	sHead = m_sMethod;
	if(m_sMethod == "POST")
	{
		sHead += " ";
		sHead += m_sLocation;
		sHead += " ";
		sHead += m_sReqProtocol;
		sHead += "\r\n";

		string hh;

		//���Ӵ����ԣ�����֧��soap��Э��Ĳ�����֧��
		if ( (m_mFixPara.size() == 0) && (m_mInpPara.size() == 1) &&( m_mInpPara.find("raw_data")!= m_mInpPara.end()))
		{
			sPara = m_mInpPara["raw_data"];
		}
		else
		{
			sPara = m_mFixPara.Join() +"&";

			sPara += m_mInpPara.Join("&","=",CBaseEncode::UrlEncode);
		}

		m_mReqHead["Content-Length"] = CBaseEncode::IntToString(sPara.size());
		
		sHead += m_mReqHead.Join("\r\n",":",CBaseEncode::UrlEncode);


		sHead += "\r\n\r\n";

		sCont = sHead + sPara;

	}
	else if(m_sMethod == "GET")
	{	

		string hh;

		sPara= m_mFixPara.Join();
		if(!sPara.empty())
			sPara+="&";

		sPara += m_mInpPara.Join("&","=",CBaseEncode::UrlEncode);

		sHead += " ";
		sHead += m_sLocation;

		if(!sPara.empty())
			sHead +=  "?" + sPara;
		sHead += " ";
		sHead += m_sReqProtocol;
		sHead += "\r\n";

		sHead += m_mReqHead.Join("\r\n",":",CBaseEncode::UrlEncode);


		sHead += "\r\n";
		sHead += "\r\n";

		sCont = sHead ;

		
	}
	
	//cout << m_sHost  << " : " << m_sPort << " : " << m_iType <<  " : " << m_sClientCert  <<" : " << m_sRootCert <<" : " << m_sClientCertPwd << endl;
	//sme_s_log(NULL,8,SME_ERRLINE,"__send[%s]",sCont.c_str());
	
	conn.Open(m_sHost.c_str(),CBaseEncode::StringToInt(m_sPort),m_iType,m_sRootCert.c_str(),m_sClientCert.c_str(),m_sClientCertPwd.c_str(),m_mReqHead["Host"].c_str());
	
	int sz = conn.Send(sCont.c_str(),sCont.size());



	//tracer.Out("111111");
//	tracer.Out("%s",sCont.c_str());

	char szResponse[2048]={0};

	sz = 0;		
	





	do
	{			
		memset(szResponse,0,sizeof(szResponse));
		sz = conn.Read(szResponse,sizeof(szResponse));	
		
if(sz!= 0)
{
		m_sResBody.append(szResponse,sz);
		//core sme_b_log(NULL,8,SME_ERRLINE,szResponse,sz);
		//sme_s_log(NULL,8,SME_ERRLINE,"__recv[%s]",szResponse);
		
	//file1.Write(szResponse,sz);

//		tracer.Out("%s",szResponse);
}
	}while(sz > 0);
	
	m_iStatus = Analysis();
	//sme_s_log(NULL,8,SME_ERRLINE,"__m_iStatus=[%d]",m_iStatus);

	/*

	//�ս�����
	string sDat ;

	if(!m_mInpPara["TextBoxBeginDate"].empty())   //������Ϣ
	{
		sDat = CModulePath::GetInstance()->m_sDatDir + "\\"+m_mInpPara["TextBoxBeginDate"]+".html" ;
	}
	else if(!m_mInpPara["TX_QQID"].empty())   //������Ϣ
	{
		sDat = CModulePath::GetInstance()->m_sDatDir + "\\"+m_mInpPara["TX_QQID"]+".html" ;
	}
	else
	{
		
		sDat = CModulePath::GetInstance()->m_sTmpDir + "\\tmp"+m_mInpPara["pnr"]+".html" ;
	//	return 0;
	}

	CFile file1;
	file1.Open(sDat.c_str(),CFile::modeCreate|CFile::modeWrite|CFile::shareDenyWrite  );


	file1.Write(m_sResBody.data(),m_sResBody.size());
	file1.Close();
	*/

	
	return 0;
}
int CHttpClient::LoadSession()
{
	string fses = m_sSesDir + "\\" + CBaseEncode::TrimLeft(m_mReqHead["Host"])+".ses.xml";//CModulePath::GetInstance()->m_sSesDir + "\\" + CBaseEncode::TrimLeft(m_mReqHead["Host"])+".ses.xml";

	CHtml doc;
	
	int retcd = doc.ParseFile(fses.c_str());
	
	if ( retcd != 0 )
	{
		return -1;
	}
		
	string url,cookie;
	if(1 == doc.GetElementByTagName("url"))
	{
		url = ((CElement *)doc.GetResult(0))->GetInnerText();
	}
	
	if(1 == doc.GetElementByTagName("cookie"))
	{
		cookie = ((CElement *)doc.GetResult(0))->GetInnerText();
	}

	CBaseEncode::UrlDecode(url);
	if((url==m_mReqHead["Host"] )&& (cookie.size()!=0))
	{
		m_mReqHead["Cookie"] = CBaseEncode::UrlDecode(cookie);
	}
	

	return 0;
}

int CHttpClient::LoadConfig(const string & fname,const string & servid)
{
	string err_msg,tmp;
	
	int i = 0;

	CHtml doc;
	
	int retcd = doc.ParseFile(fname.c_str());
	
	if ( retcd != 0 )
	{
		err_msg = "��ȡ�����ļ���";
		err_msg+= fname;
		err_msg+= "��ʧ�ܣ�";
		return -1;
	}
	
	CElement *nodeService = NULL;
	
	for(i=0;i<doc.GetElementByTagName("service");i++)
	{
		CElement *pEle = (CElement*)doc.GetResult(i);
		
		if( pEle->GetAttrValue("id",tmp) == servid)
		{
			nodeService = pEle;
			break;
		}
	}
	
	if(nodeService == 0)
	{
		err_msg = "�����ļ���";
		err_msg+= fname;
		err_msg+= "��û�С�";
		err_msg+= servid;
		err_msg+= "�������ã�";
		return -1;
	}
//��ȡporttype
	CElement * nodePort ;
	nodePort = 1==nodeService->GetElementByTagName( "porttype" )?(CElement*)nodeService->GetResult(0):NULL;

	if(!nodePort)
	{
		err_msg = "�����ļ���";
		err_msg+= fname;
		err_msg+= "���ġ�";
		err_msg+= servid;
		err_msg+= "������porttype��Ϣ��";
		return -1;
	}

	{
		nodePort->GetAttrValue("method",m_sMethod);
		nodePort->GetAttrValue("url",m_sLocation);
		
		m_sReqProtocol = nodePort->GetAttrValue("name",tmp);
		m_sReqProtocol += "/";
		m_sReqProtocol += nodePort->GetAttrValue("version",tmp);
		
		nodePort->GetAttrValue("host",m_sHost);
		nodePort->GetAttrValue("port",m_sPort);
	}
	CElement * nodePortProtocol = (1<=nodePort->GetElementByTagName( "protocol" ))?(CElement*)nodePort->GetResult(0):NULL;
	if(!nodePortProtocol)
	{
		m_iType = HTTP;
	}
	else
	{
		nodePortProtocol->GetAttrValue("ssl",tmp);
		if(tmp == "none")m_iType = HTTP;
		else if(tmp == "serv")m_iType = HTTPS_SERVER_VALID;
		else if(tmp == "clnt")m_iType = HTTPS_NO_VALID;
		else if(tmp == "both")m_iType = HTTPS_BOTH_VALID;
		else
		{
			err_msg = "��֧�ֵ�Э�顾";
			err_msg+= tmp;
			err_msg+= "��";
			return -1;
		}	
	}

	if(m_iType != HTTP)
	{
		for( i=0;i<nodePort->GetElementByTagName( "cert" );i++)
		{
			CElement * nodePortCert = (CElement*)nodePort->GetResult(i);
			
			nodePortCert->GetAttrValue("name",tmp);
			if(tmp == "private" )
			{
				nodePortCert->GetAttrValue("path",m_sClientCert);
				nodePortCert->GetAttrValue("passwd",m_sClientCertPwd);
			}
			else if(tmp == "trust" )
			{
				nodePortCert->GetAttrValue("path",m_sRootCert);
			}
			else
			{
				;
			}
		}
	}

//��ȡheaders

	for(i=0;i<nodeService->GetElementByTagName( "header" );i++)
	{
		CElement * pEle = (CElement*)nodeService->GetResult(i);
		
		string name,value;
		
		pEle->GetAttrValue("name",name);
		pEle->GetAttrValue("value",value);

		m_mReqHead.insert(CStringMap::value_type(name,value));
		
	}

	
//��ȡparameters
	//
	for(i=0;i<nodeService->GetElementByTagName( "parameter" );i++)
	{
		CElement * pEle = (CElement*)nodeService->GetResult(i);
		
		string name,value,type;
		
		pEle->GetAttrValue("name",name);
		pEle->GetAttrValue("value",value);
		pEle->GetAttrValue("type",type);
		
		if(type == string("fix"))
			m_mFixPara.insert(CStringMap::value_type(name,value));
		else if(type == string("inp"))
			m_mInpPara.insert(CStringMap::value_type(name,value));
		else
		{
			err_msg = "��֧�ֵĲ������͡�";
			err_msg+= name;
			err_msg+= "��";
			return -1;
		}

		m_mReqHead.insert(CStringMap::value_type(name,value));
		
	}
//��ȡresponses
	//nodeResponse = node->FirstChild( "response" );


	return 0;
}

/*
  0 �ɹ�
  1 ʧ�ܣ���״̬��
  2 ʧ�ܣ�������
  3 chunk Error
  */
int CHttpClient::Analysis()
{
	string curLine;

	string curText;

	string::const_iterator iter = m_sResBody.begin();
	string::const_iterator iterText=m_sResBody.begin();


reget_state:
	//ȡ��һ������ : HTTP/1.1 100 Continue
	CBaseEncode::get_first_line(m_sResBody,iter,curLine);

	CStringVector curArr;

	curArr.Split(curLine," ");

	if(curArr.size() != 3) return 1;

	m_sResProtocol = curArr[0];
	m_sRetCode = curArr[1];
	m_sRetDes = curArr[2];

	//ȡ���ģ�����û��1**
	if(CBaseEncode::get_first_http_text(m_sResBody,iterText)!=0)
		return 2;

	//�������е�ͷ
	/*
		Server: Microsoft-IIS/5.0
		Date: Wed, 22 Apr 2009 03:37:32 GMT
		X-Powered-By: ASP.NET
	*/

	while(iter < iterText)
	{
		CBaseEncode::get_first_line(iter,iterText,curLine);
		
		curArr.Split(curLine,":");

		if(curArr.size() >= 2)
		{
			string tmp = curLine.substr(curArr[0].size()+1/*,curLine.size()-curArr[0].size()*/);
			CBaseEncode::TrimLeft(tmp);
			if((curArr[0] != string("Set-Cookie")) && 
				(curArr[0] != string("Set-cookie"))&& 
				(curArr[0] != string("set-cookie"))
				)
			{
				m_mResHead[curArr[0]] = tmp;
			}
			else
			{
				m_aResCookie.push_back(CCookie(tmp));
			}
		}

	}

	//��������Ϊ 100�����iterText��ʼȡ�����
	if(m_sRetCode == string("100"))
	{
		iter = iterText;
		goto reget_state;
	}
	else if (m_sRetCode == string("302"))
	{
		m_sResBody = m_mResHead["Location"];

		return 0;
	}

	//sme_s_log(NULL,8,SME_ERRLINE,"__gzip_b[%s]",m_sResBody.c_str());


	m_sResBody.erase(0,iterText-m_sResBody.begin());
	
	//sme_s_log(NULL,8,SME_ERRLINE,"__gzip_b1[%s]",m_sResBody.c_str());



	//�������ݣ������chunk�ģ�����֮  Transfer-Encoding: chunked
	//�����ѹ���Ľ�ѹ�������ؽ�ѹ����
	string sTmp;

	if(CBaseEncode::TrimLeft(m_mResHead["Content-Encoding"]) == string("gzip"))
	{
		sTmp = GUnzip(m_sResBody);
		m_sResBody = sTmp;

		//sme_s_log(NULL,8,SME_ERRLINE,"__gzip[%s]",sTmp.c_str());
	}

	if(CBaseEncode::TrimLeft(m_mResHead["Transfer-Encoding"]) == string("chunked"))
	{
		string::const_iterator iterTagBegin = m_sResBody.begin();
		string::const_iterator iterTagCur = iterTagBegin;
		int block_size = 0;

		do
		{
				//iter = m_sResBody.begin();

				CBaseEncode::get_first_line(m_sResBody,iterTagCur,curLine);

				if(curLine.empty()) 
				{
					if(iterTagCur != m_sResBody.end())
						continue;
				}
				
				block_size = CBaseEncode::HexToInt(curLine);

				if(block_size < 0) return 3;

				if(block_size > 0)
				{
					//m_sResBody.erase(0,iterTagCur-iterTagBegin);
					
					#ifdef WIN32
						sTmp.append(iterTagCur,block_size);
					#else
						string str = m_sResBody.substr(iterTagCur-m_sResBody.begin(),block_size);
						sTmp.append(str );
					#endif
					iterTagCur += block_size;
					iterTagBegin = iterTagCur;

				}

		}while((block_size > 0) && (iterTagCur != m_sResBody.end()));


		m_sResBody= sTmp;

	}


	//sme_s_log(NULL,8,SME_ERRLINE,"__Analysis_end[%s]",m_sResBody.c_str());

	return 0;
}


int CHttpClient::StoreSession()
{
	CStringMap mCookie;

	//
	string sReqCookie = m_mReqHead["Cookie"];

	mCookie.Split(sReqCookie,"; ");


	if(m_aResCookie.size() == 0)
		return 0;

	for(int i=0;i<m_aResCookie.size();i++)
	{
		mCookie[m_aResCookie[i].m_sName] = m_aResCookie[i].m_sValue; 
	}

	string sCookie ;

	mCookie.Join(sCookie.c_str(),"; ");

	string sContent = "<?xml version=\"1.0\" ?>\r\n";
	sContent+= " <root>\r\n";
	sContent+= " <cookie>" + CBaseEncode::UrlEncode(sCookie) + "</cookie>\r\n";
	sContent+= " <url>" + CBaseEncode::UrlEncode(m_sHost) + "</url>\r\n";
	sContent+= " </root>\r\n";

	string fses = m_sSesDir + "/" + m_sHost+".ses.xml";


	FILE *stream = NULL;
	if( (stream  = fopen( fses.c_str(), "w" )) != NULL )
	{
		fwrite(sContent.data(),sizeof(char),sContent.size(),stream);
		fclose( stream ) ;
	}


	return 0;
}
