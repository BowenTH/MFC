
// CSdiSquaresView.h : CCSdiSquaresView 类的接口
//

#pragma once


class CCSdiSquaresView : public CView
{
protected: // 仅从序列化创建
	CCSdiSquaresView();
	DECLARE_DYNCREATE(CCSdiSquaresView)

// 特性
public:
	CCSdiSquaresDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CCSdiSquaresView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // CSdiSquaresView.cpp 中的调试版本
inline CCSdiSquaresDoc* CCSdiSquaresView::GetDocument() const
   { return reinterpret_cast<CCSdiSquaresDoc*>(m_pDocument); }
#endif

