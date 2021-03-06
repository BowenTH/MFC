
// CSdiSquaresDoc.cpp : CCSdiSquaresDoc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "CSdiSquares.h"
#endif

#include "CSdiSquaresDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CCSdiSquaresDoc

IMPLEMENT_DYNCREATE(CCSdiSquaresDoc, CDocument)

BEGIN_MESSAGE_MAP(CCSdiSquaresDoc, CDocument)
	ON_COMMAND(ID_COLOR_RED, OnColrRed)
	ON_COMMAND(ID_COLOR_YELLOW,OnColrYellow)
	ON_COMMAND(ID_COLOR_GREEN,OnColrGreen)
	ON_COMMAND(ID_COLOR_CYAN,OnColrCyan)
	ON_COMMAND(ID_COLOR_BLUE,OnColrBlue)
	ON_COMMAND(ID_COLOR_WHITE,OnColrWhite)

	ON_UPDATE_COMMAND_UI(ID_COLOR_RED, OnUpdateColorRed)
	ON_UPDATE_COMMAND_UI(ID_COLOR_YELLOW,OnUpdateColorYellow)
	ON_UPDATE_COMMAND_UI(ID_COLOR_GREEN,OnUpdateColorGreen)
	ON_UPDATE_COMMAND_UI(ID_COLOR_CYAN,OnUpdateColorCyan)
	ON_UPDATE_COMMAND_UI(ID_COLOR_BLUE,OnUpdateColorBlue)
	ON_UPDATE_COMMAND_UI(ID_COLOR_WHITE,OnUpdateColorWhite)
END_MESSAGE_MAP()


// CCSdiSquaresDoc 构造/析构

CCSdiSquaresDoc::CCSdiSquaresDoc()
{
	// TODO: 在此添加一次性构造代码

}

CCSdiSquaresDoc::~CCSdiSquaresDoc()
{
}

//************************************
// Method:    OnNewDocument
// FullName:  CCSdiSquaresDoc::OnNewDocument
// Access:    virtual public 
// Returns:   BOOL
// Qualifier:
//************************************
BOOL CCSdiSquaresDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	for (int i = 0;i<4;i++)
	{
		for (int j=0;j<4;j++)
		{
			m_clrGrid[i][j] = RGB(255,255,255);
		}
	}
	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CCSdiSquaresDoc 序列化

void CCSdiSquaresDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
		for (int i = 0;i<4;i++)
		
			for (int j=0;j<4;j++)
				ar<< m_clrGrid[i][j];
			ar<< m_clrCurrentColor;		
	}
	else
	{
		// TODO: 在此添加加载代码
		for (int i = 0;i<4;i++)

			for (int j=0;j<4;j++)
				ar>> m_clrGrid[i][j];
		ar>> m_clrCurrentColor;		
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CCSdiSquaresDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void CCSdiSquaresDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:  strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CCSdiSquaresDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CCSdiSquaresDoc 诊断

#ifdef _DEBUG
void CCSdiSquaresDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCSdiSquaresDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}

void CCSdiSquaresDoc::OnColrRed()
{
	m_clrCurrentColor = RGB(255,0,0);
}

void CCSdiSquaresDoc::OnColrYellow()
{
	m_clrCurrentColor = RGB(255,255,0);
}

void CCSdiSquaresDoc::OnColrGreen()
{
	m_clrCurrentColor = RGB(0,255,0);
}

void CCSdiSquaresDoc::OnColrCyan()
{
	m_clrCurrentColor = RGB(0,255,255);
}

void CCSdiSquaresDoc::OnColrBlue()
{
	m_clrCurrentColor = RGB(0,0,255);
}

void CCSdiSquaresDoc::OnColrWhite()
{
	m_clrCurrentColor = RGB(255,255,255);
}

void CCSdiSquaresDoc::OnUpdateColorRed( CCmdUI* pCmdUI )
{
	pCmdUI->SetRadio(m_clrCurrentColor == RGB(255,0,0));
}

void CCSdiSquaresDoc::OnUpdateColorYellow( CCmdUI* pCmdUI )
{
	pCmdUI->SetRadio(m_clrCurrentColor == RGB(255,255,0));
}

void CCSdiSquaresDoc::OnUpdateColorGreen( CCmdUI* pCmdUI )
{
	pCmdUI->SetRadio(m_clrCurrentColor == RGB(0,255,0));
}

void CCSdiSquaresDoc::OnUpdateColorCyan( CCmdUI* pCmdUI )
{
	pCmdUI->SetRadio(m_clrCurrentColor == RGB(0,255,255));
}

void CCSdiSquaresDoc::OnUpdateColorBlue( CCmdUI* pCmdUI )
{
	pCmdUI->SetRadio(m_clrCurrentColor == RGB(0,0,255));
}

void CCSdiSquaresDoc::OnUpdateColorWhite( CCmdUI* pCmdUI )
{
	pCmdUI->SetRadio(m_clrCurrentColor == RGB(255,255,255));
}

COLORREF CCSdiSquaresDoc::GetSquare( int i,int j )
{
	ASSERT(i>=0&&i<=3 && j>=0&&j<=3);
	return m_clrGrid[i][j];
}

COLORREF CCSdiSquaresDoc::GetCurrentColor()
{
	return m_clrCurrentColor;
}

void CCSdiSquaresDoc::SetSquare( int i,int j,COLORREF color )
{
	ASSERT(i>=0&&i<=3 && j>=0&&j<=3);
	m_clrGrid[i][j] = color;
	SetModifiedFlag(TRUE);
	UpdateAllViews(NULL);
}

#endif //_DEBUG


// CCSdiSquaresDoc 命令
