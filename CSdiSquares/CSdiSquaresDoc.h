
// CSdiSquaresDoc.h : CCSdiSquaresDoc 类的接口
//


#pragma once


class CCSdiSquaresDoc : public CDocument
{
protected: // 仅从序列化创建
	CCSdiSquaresDoc();
	DECLARE_DYNCREATE(CCSdiSquaresDoc)

// 特性
public:

// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CCSdiSquaresDoc();
	void SetSquare(int i,int j,COLORREF color);
	COLORREF GetSquare(int i,int j);
	COLORREF GetCurrentColor();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	COLORREF m_clrCurrentColor;
	COLORREF m_clrGrid[4][4];
// 生成的消息映射函数
protected:
	
	afx_msg void OnColrRed();
	afx_msg void OnColrYellow();
	afx_msg void OnColrGreen();
	afx_msg void OnColrCyan();
	afx_msg void OnColrBlue();
	afx_msg void OnColrWhite();
	afx_msg void OnUpdateColorRed(CCmdUI* pCmdUI);	
	afx_msg void OnUpdateColorYellow(CCmdUI* pCmdUI);
	afx_msg void OnUpdateColorGreen(CCmdUI* pCmdUI);
	afx_msg void OnUpdateColorCyan(CCmdUI* pCmdUI);
	afx_msg void OnUpdateColorBlue(CCmdUI* pCmdUI);
	afx_msg void OnUpdateColorWhite(CCmdUI* pCmdUI);
	DECLARE_MESSAGE_MAP()


#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
