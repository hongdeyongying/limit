// AnalyzerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Analyzer.h"
#include "AnalyzerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	CString	m_strDesc;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	m_strDesc = _T(
		"原创软件开发的一个Html分析库"
		"\r\n提供了对html文件或字符串的解析和查询功能，支持流解析。"
		"\r\n可提供window与linux下的二进制库或源码"
		"\r\n\r\n"
		"如果有需要，可以通过如下联系方式获取最新消息"
		"\r\n邮件：authorship@vip.qq.com"
		"\r\n网站 ：http://www.my-soft.net.cn/html_analyzer/"
		);
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	DDX_Text(pDX, IDC_EDIT1, m_strDesc);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAnalyzerDlg dialog

CAnalyzerDlg::CAnalyzerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAnalyzerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAnalyzerDlg)
	m_strSource = _T("<!-- aaa --> <html><head><title>Test</title></head><body name=bbc><p id=abc>aaaaa</p></body></html>");
	m_strFilePath = _T("");
	m_strParam = _T("abc");
	m_strParam2 = _T("");
	m_iTagSearchMode = 0;
	m_strRichSrc = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAnalyzerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAnalyzerDlg)
	DDX_Control(pDX, IDFILE, m_btnFile);
	DDX_Control(pDX, IDOK, m_btnWhole);
	DDX_Control(pDX, IDC_BUTTON_mid, m_btnMid);
	DDX_Control(pDX, IDC_BUTTON_end, m_btnEnd);
	DDX_Control(pDX, IDC_BUTTON_begin, m_btnBegin);
	DDX_Control(pDX, IDC_TREE1, m_treeCtrl);
	DDX_Text(pDX, IDC_EDIT1, m_strSource);
	DDX_Text(pDX, IDC_EDIT2, m_strFilePath);
	DDX_Text(pDX, IDC_EDIT_PARAM, m_strParam);
	DDX_Text(pDX, IDC_EDIT_PARAM2, m_strParam2);
	DDX_Text(pDX, IDC_EDIT_TAGNAME_MODE, m_iTagSearchMode);
	DDX_Text(pDX, IDC_RICHEDIT1, m_strRichSrc);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAnalyzerDlg, CDialog)
	//{{AFX_MSG_MAP(CAnalyzerDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDFILE, OnFileParse)
	ON_BN_CLICKED(IDC_BUTTON_begin, OnBUTTONbegin)
	ON_BN_CLICKED(IDC_BUTTON_mid, OnBUTTONmid)
	ON_BN_CLICKED(IDC_BUTTON_end, OnBUTTONend)
	ON_COMMAND(ID_MENUITEM_VER, OnMenuitemVer)
	ON_COMMAND(ID_MENUITEM_ONLINE, OnMenuitemOnline)
	ON_COMMAND(ID_MENUITEM_MAN, OnMenuitemMan)
	ON_BN_CLICKED(IDC_BUTTON_Clear, OnBUTTONClear)
	ON_BN_CLICKED(IDC_BUTTON_S_TAG, OnButtonSTag)
	ON_BN_CLICKED(IDC_BUTTON_S_ID, OnButtonSId)
	ON_BN_CLICKED(IDC_BUTTON_S_NAME, OnButtonSName)
	ON_BN_CLICKED(BTN_NV, OnNv)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAnalyzerDlg message handlers

BOOL CAnalyzerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here

	string logPath = CModulePath::GetInstance()->m_sLogDir + "/sr.log";

	tracer.Init(logPath.c_str());
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CAnalyzerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CAnalyzerDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CAnalyzerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}



void CAnalyzerDlg::OnOK() 
{
	// TODO: Add extra validation here
	m_btnWhole.ModifyStyle(0,WS_DISABLED);
	this->Invalidate();

	UpdateData(TRUE);;


	m_Doc.Parse((LPCTSTR)m_strSource,CHtml::CONTEXT_WHOLE);


	HTREEITEM root = m_treeCtrl.InsertItem("Document");

	int j = m_Doc.Child().size();

	for(int i = 0 ;i<j;i++)
	{
		CNode *p = m_Doc.Child(i);
		string tmp = "";
		p->ToString();
		HTREEITEM posroot = m_treeCtrl.InsertItem(m_Doc.Child()[i]->ToString().c_str(),root);

		GenTree(p,posroot);
	}

	m_btnWhole.ModifyStyle(WS_DISABLED,0);
	this->Invalidate();
//	CDialog::OnOK();
}

void CAnalyzerDlg::GenTree(const CNode *root, HTREEITEM &pos)
{
	const CElement *pEle = dynamic_cast<const CElement *>( root);

	if(pEle)
	{
		int j = pEle->Child().size();

		for(int i = 0 ;i<j;i++)
		{
			CNode *p = pEle->Child(i);
			string tmp = p->ToString();
			HTREEITEM posroot = m_treeCtrl.InsertItem(tmp.c_str(),pos);
			GenTree(p,posroot);
		}

	}
}

void CAnalyzerDlg::OnButton1() 
{
	CFileDialog fdlg(TRUE);
	
	if(fdlg.DoModal() == IDOK)
	{
		m_strFilePath = fdlg.GetPathName();
		UpdateData(FALSE);
	}
}

UINT ThreadParseFile(LPVOID dat)
{
	CAnalyzerDlg *pDlg = (CAnalyzerDlg *)dat;

	CHtml &doc = pDlg->m_Doc;

	doc.ParseFile((LPCTSTR) pDlg->m_strFilePath);

	//doc.Parse((LPCTSTR)m_strSource,CHtml::CONTEXT_WHOLE);


	HTREEITEM root = pDlg->m_treeCtrl.InsertItem("Document");

	int j = doc.Child().size();

	for(int i = 0 ;i<j;i++)
	{
		CNode *p = doc.Child(i);
		string tmp = "";
		p->ToString();
		HTREEITEM posroot = pDlg->m_treeCtrl.InsertItem(doc.Child()[i]->ToString().c_str(),root);

		pDlg->GenTree(p,posroot);
	}
	pDlg->m_btnFile.ModifyStyle(WS_DISABLED,0);
	pDlg->Invalidate();
	
	return 0;
}

void CAnalyzerDlg::OnFileParse() 
{
	
	UpdateData(TRUE);
	m_btnFile.ModifyStyle(0,WS_DISABLED);



	AfxBeginThread(ThreadParseFile,this);

	this->Invalidate();

	
	

}


 //enum ECONTEXT {CONTEXT_FIRST,CONTEXT_MIDDLE,CONTEXT_LAST,CONTEXT_WHOLE};
void CAnalyzerDlg::OnBUTTONbegin() 
{	

	m_btnBegin.ModifyStyle(0,WS_DISABLED);
	UpdateData(TRUE);

	m_Doc.Parse((LPCTSTR)m_strSource,CHtml::CONTEXT_FIRST);
	
	m_btnMid.ModifyStyle(WS_DISABLED,0);
	m_btnEnd.ModifyStyle(WS_DISABLED,0);
	this->Invalidate();
}

void CAnalyzerDlg::OnBUTTONmid() 
{
	UpdateData(TRUE);

	m_Doc.Parse((LPCTSTR)m_strSource,CHtml::CONTEXT_MIDDLE);
}

void CAnalyzerDlg::OnBUTTONend() 
{
	UpdateData(TRUE);

	m_Doc.Parse((LPCTSTR)m_strSource,CHtml::CONTEXT_LAST);


	HTREEITEM root = m_treeCtrl.InsertItem("Document");

	int j = m_Doc.Child().size();

	for(int i = 0 ;i<j;i++)
	{
		CNode *p = m_Doc.Child(i);
		string tmp = "";
		p->ToString();
		HTREEITEM posroot = m_treeCtrl.InsertItem(m_Doc.Child()[i]->ToString().c_str(),root);

		GenTree(p,posroot);
	}

	
	m_btnBegin.ModifyStyle(WS_DISABLED,0);
	m_btnMid.ModifyStyle(0,WS_DISABLED);
	m_btnEnd.ModifyStyle(0,WS_DISABLED);
	this->Invalidate();
}

void CAnalyzerDlg::OnMenuitemVer() 
{
	CAboutDlg dlg;
	dlg.DoModal();
}

void CAnalyzerDlg::OnMenuitemOnline() 
{
	ShellExecute(NULL, "open", "http://www.my-soft.net.cn",NULL, NULL, SW_SHOWNORMAL);
}

void CAnalyzerDlg::OnMenuitemMan() 
{
	ShellExecute(NULL, "open", "http://www.my-soft.net.cn",NULL, NULL, SW_SHOWNORMAL);
}

void CAnalyzerDlg::OnBUTTONClear() 
{
	m_treeCtrl.DeleteAllItems();
}


void CAnalyzerDlg::OnButtonSTag() 
{
	UpdateData(TRUE);

	int res = m_Doc.GetElementByTagName((LPCTSTR)m_strParam,m_iTagSearchMode);

	if(res == 0)
	{
		AfxMessageBox("未找到符合条件的节点！");
		return;
	}
	
	CString rootResult;
	rootResult.Format("GetElementByTagName(\"%s\",%d) ->Search Result [%d] ",m_strParam,m_iTagSearchMode,res);
	
	HTREEITEM root = m_treeCtrl.InsertItem(rootResult);


	int j = m_Doc.GetResult().size();

	for(int i = 0 ;i<j;i++)
	{
		const CNode *p = m_Doc.GetResult(i);
		string tmp = "";
		p->ToString();
		HTREEITEM posroot = m_treeCtrl.InsertItem(m_Doc.GetResult(i)->ToString().c_str(),root);

		GenTree(p,posroot);
	}

}

void CAnalyzerDlg::OnButtonSId() 
{
	UpdateData(TRUE);

	int res = m_Doc.GetElementByID((LPCTSTR)m_strParam);

	if(res == 0)
	{
		AfxMessageBox("未找到符合条件的节点！");
		return;
	}
	
	CString rootResult;
	rootResult.Format("GetElementByID(\"%s\") ->Search Result [%d] ",m_strParam,res);
	
	HTREEITEM root = m_treeCtrl.InsertItem(rootResult);


	int j = m_Doc.GetResult().size();

	for(int i = 0 ;i<j;i++)
	{
		const CNode *p = m_Doc.GetResult(i);
		string tmp = "";
		p->ToString();
		HTREEITEM posroot = m_treeCtrl.InsertItem(m_Doc.GetResult(i)->ToString().c_str(),root);

		GenTree(p,posroot);
	}
	
	if (j == 1)
	{
		CElement t_ele;

		const CElement * pEle = dynamic_cast<const CElement *>(m_Doc.GetResult(0));
		if( !pEle) return;
		int res = pEle->GetElementByTagName("tr",&t_ele);

		if(res == 0)
		{
			//AfxMessageBox("未找到符合条件的节点！");
			return;
		}
		
		CString rootResult;
		rootResult.Format("GetElementByTagName(\"tr\") ->Search Result [%d] ",res);
		
		HTREEITEM root = m_treeCtrl.InsertItem(rootResult);


		int j = t_ele.GetResult().size();

		for(int i = 0 ;i<j;i++)
		{
			const CElement * p = dynamic_cast<const CElement *>(t_ele.GetResult(i));
			if(!p) continue;

			HTREEITEM posroot = m_treeCtrl.InsertItem(p->GetInnerText().c_str(),root);

		//	GenTree(p,posroot);
		}
	}

}

void CAnalyzerDlg::OnButtonSName() 
{
	UpdateData(TRUE);

	int res = m_Doc.GetElementByName((LPCTSTR)m_strParam);

	if(res == 0)
	{
		AfxMessageBox("未找到符合条件的节点！");
		return;
	}
	
	CString rootResult;
	rootResult.Format("GetElementByName(\"%s\") ->Search Result [%d] ",m_strParam,res);
	
	HTREEITEM root = m_treeCtrl.InsertItem(rootResult);


	int j = m_Doc.GetResult().size();

	for(int i = 0 ;i<j;i++)
	{
		const CNode *p = m_Doc.GetResult(i);
		string tmp = "";
		p->ToString();
		HTREEITEM posroot = m_treeCtrl.InsertItem(m_Doc.GetResult(i)->ToString().c_str(),root);

		GenTree(p,posroot);
	}
	
}

void CAnalyzerDlg::OnNv() 
{
	UpdateData(TRUE);

	int res = m_Doc.GetElementByAttrNV((LPCTSTR)m_strParam2,(LPCTSTR)m_strParam);

	if(res == 0)
	{
		AfxMessageBox("未找到符合条件的节点！");
		return;
	}
	
	CString rootResult;
	rootResult.Format("GetElementByAttrNV(\"%s:%s\") ->Search Result [%d] ",m_strParam2,m_strParam,res);
	
	HTREEITEM root = m_treeCtrl.InsertItem(rootResult);


	int j = m_Doc.GetResult().size();

	for(int i = 0 ;i<j;i++)
	{
		const CNode *p = m_Doc.GetResult(i);
		string tmp = "";
		p->ToString();
		HTREEITEM posroot = m_treeCtrl.InsertItem(m_Doc.GetResult(i)->ToString().c_str(),root);

		GenTree(p,posroot);
	}
}

#include "StrArray.h"


//变量空间
map<string,string> g_mStringVars;
map<string,CElement *> g_mElementVars;
map<string,int> g_mIntVars;

//关键字节点首字符串
#define translator_head "my-soft::"
//关键字节点
map<string,int> g_mKey;
//运算符
map<string,int> g_mKeyOp;

void Init()
{
	g_mKey.insert(map<string,int>::value_type("my-soft::if", 10));
	g_mKey.insert(map<string,int>::value_type("my-soft::true", 11));
	g_mKey.insert(map<string,int>::value_type("my-soft::fasle", 12));

	g_mKey.insert(map<string,int>::value_type("my-soft::for", 20));
	g_mKey.insert(map<string,int>::value_type("my-soft::continue", 21));
	g_mKey.insert(map<string,int>::value_type("my-soft::break", 22));

	g_mKey.insert(map<string,int>::value_type("my-soft::echo", 3));

	g_mKey.insert(map<string,int>::value_type("my-soft::assign", 4));

	g_mKey.insert(map<string,int>::value_type("my-soft::return", 5));


	g_mKeyOp.insert(map<string,int>::value_type("has", 1));
	g_mKeyOp.insert(map<string,int>::value_type("equ", 2));
	g_mKeyOp.insert(map<string,int>::value_type("big", 3));
	g_mKeyOp.insert(map<string,int>::value_type("little", 4));
	g_mKeyOp.insert(map<string,int>::value_type("minus", 5));
	g_mKeyOp.insert(map<string,int>::value_type("add", 6));

}

bool ProcessTranslate(const string &expr)
{
	//检查() 是否匹配

	return true;
}

int CAnalyzerDlg::Html2Xml(const CHtml & in,const CNode * rule,string &out)
{
	const CElement *pEle = dynamic_cast<const CElement *>( rule);


	if(pEle)
	{
		string aa = pEle->GetTagName();
		if((aa.find(translator_head) == 0) && 
			(g_mKey.find(aa) != g_mKey.end()))
		{			
			switch(g_mKey[aa])
			{
			case 10://if
			case 11:
			case 12:
				{
					CElement tmp;

					string cond;
					pEle->GetAttrValue("condition",cond);
//检查cond的值
					if(ProcessTranslate(cond ))
					{
						pEle->GetElementByTagName("my-soft::true",&tmp);
					}
					else
					{
						pEle->GetElementByTagName("my-soft::false",&tmp);
					}
					int j = tmp.Child().size();

					for(int i = 0 ;i<j;i++)
					{
						CNode *p = tmp.Child(i);
						if(Html2Xml(in, p,out)!= 0)
							return 1;
					}
					break;



				}
			case 20:
				{
				}
			case 21:
				{
				}
			case 22:
				{
				}
			case 3:
				{
				}
			case 4:
				{
				}
			case 5:
				return 1;

			}
		}
		else
		{
			out += pEle->ToString();
			int j = pEle->Child().size();

			for(int i = 0 ;i<j;i++)
			{
				CNode *p = pEle->Child(i);
				if(Html2Xml(in, p,out)!= 0)
					return 1;
			}

			out += "</";
			out += aa;
			out += ">";

		}

	}
	else
	{
		out += rule->ToString();
	}
	return 0;
}
int CAnalyzerDlg::Html2Xml(const string &in, const string &rule, string &out)
{
	Init();

	CHtml htmlIn;	htmlIn.Parse(in);
	CHtml htmlRule;	htmlRule.Parse(rule);

	for(int i=0; i < htmlRule.Child().size();i++)
	{
		if(Html2Xml(htmlIn,htmlRule.Child(i),out) != 0)
			break;
	}
	return 1;

}
#include "myFlow/CMyExpression.h"
#include "myFlow/CMyHtml2XmlWorker.h"
#include "myFlow/CMyDispatcher.h"
void CAnalyzerDlg::OnButton2() 
{
	UpdateData(TRUE);

	/*CMyExpression  expr;
	
	//text(item(tag(parse_html(1,G%3A%5CNEW_LIFE%5CTranslate%5Chtml2xml%2Etxt),a,0),0))
	//text(item(tag(parse_html(1,G%3A%5CNEW_LIFE%5CTranslate%5Chtml2xml%2Etxt),if,2),0))
	//expr.Identify("text(item(tag(parse_html(1,G%3A%5CNEW%5FLIFE%5CTranslate%5Chtml2xml%2Etxt),my%2dsoft,1),1))");
	expr.Identify((LPCTSTR)m_strSource);

	CMyHtml2XmlWorker worker;

	string a = expr.Execute(&worker);

	string b= worker.FetchVarValue(a);

	AfxMessageBox(b.c_str());

*/


	{
		CMyDispatcher disp;
		string res;
		
		int i = 0;

		string inParas("datetime=2009-12-26");
		i = disp.StartWork((LPCTSTR)m_strFilePath,res,inParas);
		//AfxMessageBox(res.c_str());

		m_strRichSrc = res.c_str();

		UpdateData(FALSE);
	}

}
