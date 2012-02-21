
// dlpmsView.cpp : implementation of the CdlpmsView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "dlpms.h"
#endif

#include "dlpmsDoc.h"
#include "dlpmsView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CdlpmsView

IMPLEMENT_DYNCREATE(CdlpmsView, CView)

BEGIN_MESSAGE_MAP(CdlpmsView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CdlpmsView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CdlpmsView construction/destruction

CdlpmsView::CdlpmsView()
{
	// TODO: add construction code here

}

CdlpmsView::~CdlpmsView()
{
}

BOOL CdlpmsView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CdlpmsView drawing

void CdlpmsView::OnDraw(CDC* /*pDC*/)
{
	CdlpmsDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CdlpmsView printing


void CdlpmsView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CdlpmsView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CdlpmsView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CdlpmsView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CdlpmsView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CdlpmsView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CdlpmsView diagnostics

#ifdef _DEBUG
void CdlpmsView::AssertValid() const
{
	CView::AssertValid();
}

void CdlpmsView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CdlpmsDoc* CdlpmsView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CdlpmsDoc)));
	return (CdlpmsDoc*)m_pDocument;
}
#endif //_DEBUG


// CdlpmsView message handlers
