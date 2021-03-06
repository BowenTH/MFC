
// CSdiSquaresView.cpp : CCSdiSquaresView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "CSdiSquares.h"
#endif

#include "CSdiSquaresDoc.h"
#include "CSdiSquaresView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCSdiSquaresView

IMPLEMENT_DYNCREATE(CCSdiSquaresView, CView)

BEGIN_MESSAGE_MAP(CCSdiSquaresView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CCSdiSquaresView 构造/析构

CCSdiSquaresView::CCSdiSquaresView()
{
	// TODO: 在此处添加构造代码

}

CCSdiSquaresView::~CCSdiSquaresView()
{
}

BOOL CCSdiSquaresView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CCSdiSquaresView 绘制

void CCSdiSquaresView::OnDraw(CDC* pDC)
{
	CCSdiSquaresDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->SetMapMode(MM_LOENGLISH);
	// TODO: 在此处为本机数据添加绘制代码
	for (int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++){
			COLORREF color = pDoc->GetSquare(i,j);
			CBrush brush(color);
			int x1=(j*100)+50;
			int y1 = (i*-100)-50;
			int x2 = x1 +100;
			int y2 = y1 -100;
			CRect rect(x1,y1,x2,y2);
			pDC->FillRect(rect,&brush);
		}
	}

	for (int x=50;x<=450;x+=100)
	{
		pDC->MoveTo(x,-50);
		pDC->LineTo(x,-450);
	}
	for (int y =-50;y>=-450;y-=100)
	{
		pDC->MoveTo(50,y);
		pDC->LineTo(450,y);
	}

}

void CCSdiSquaresView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CCSdiSquaresView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CCSdiSquaresView 诊断

#ifdef _DEBUG
void CCSdiSquaresView::AssertValid() const
{
	CView::AssertValid();
}

void CCSdiSquaresView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCSdiSquaresDoc* CCSdiSquaresView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCSdiSquaresDoc)));
	return (CCSdiSquaresDoc*)m_pDocument;
}
#endif //_DEBUG


// CCSdiSquaresView 消息处理程序


void CCSdiSquaresView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CView::OnLButtonDown(nFlags, point);
	CClientDC dc(this);
	dc.SetMapMode(MM_LOENGLISH);
	CPoint pos = point;
	dc.DPtoLP(&pos);
	if (pos.x>=50&&pos.x<=450 &&pos.y<=-50&&pos.y>=-450)
	{
		int i = (-pos.y - 50)/100;
		int j = (pos.x - 50)/100;
		CCSdiSquaresDoc* pDoc = GetDocument();
		COLORREF clrCurrentColor = pDoc->GetCurrentColor();
		pDoc->SetSquare(i,j,clrCurrentColor);
	}
}
