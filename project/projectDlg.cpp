
// projectDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "project.h"
#include "projectDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CprojectDlg dialog



CprojectDlg::CprojectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PROJECT_DIALOG, pParent)
	, m_display(_T("0"))
	, m_display2(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	x1 = 0;
	x2 = 0;
	y1 = 0;
	y2 = 0;
}

void CprojectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PIC, m_pic);
	DDX_Control(pDX, IDC_BUTTON1, m_tampil);
	DDX_Text(pDX, IDC_EDIT1, m_display);
	DDX_Text(pDX, IDC_EDIT2, m_display2);
	DDX_Control(pDX, IDC_BUTTON2, m_acak);
	DDX_Control(pDX, IDC_BUTTON3, m_acak2);
	DDX_Control(pDX, IDC_BUTTON4, m_gerak);
	DDX_Control(pDX, IDC_BUTTON5, m_gerak2);
	DDX_Control(pDX, IDC_BUTTON6, m_hapus);
}

BEGIN_MESSAGE_MAP(CprojectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CprojectDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CprojectDlg::OnBnClickedAcak)
	ON_BN_CLICKED(IDC_BUTTON3, &CprojectDlg::OnBnClickedAcak2)
	ON_BN_CLICKED(IDC_BUTTON4, &CprojectDlg::OnBnClickedButton4)
	ON_EN_CHANGE(IDC_EDIT3, &CprojectDlg::OnEnChangeEdit3)
	ON_BN_CLICKED(IDC_BUTTON6, &CprojectDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON5, &CprojectDlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// CprojectDlg message handlers

BOOL CprojectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
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
	UpdateData(TRUE);
	m_acak.EnableWindow(FALSE);
	m_acak2.EnableWindow(FALSE);
	m_gerak.EnableWindow(FALSE);
	m_gerak2.EnableWindow(FALSE);
	m_hapus.EnableWindow(FALSE);
	x1 = 0;
	x2 = 40;
	y1 = 240;
	y2 = 280;
	// membentuk piont pertama 
	pDCLingkaran = m_pic.GetDC();
	CDC dcMempiont;

	x3 = 0;
	x4 = 40;
	y3 = 240;
	y4 = 280;
	//membentuk piont kedua 
	pDCLingkaran2 = m_pic.GetDC();
	CDC dcMemPiont2;

	//membentuk rectangle 
	pDCRectangle = m_pic.GetDC();
	CDC dcMemRec;
	UpdateData(FALSE);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CprojectDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CprojectDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CprojectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CprojectDlg::OnBnClickedButton1()
{
	//disable tombol start
	m_tampil.EnableWindow(FALSE);
	//enable tombol acak
	m_acak.EnableWindow(TRUE);
	m_acak2.EnableWindow(TRUE);
	m_gerak.EnableWindow(TRUE);
	m_gerak2.EnableWindow(TRUE);
	m_hapus.EnableWindow(FALSE);
	// TODO: Add your control notification handler code here
	CDC* pDC = m_pic.GetDC();
	CDC dcMem;
	CPen pen(PS_SOLID, 1, RGB(255, 255, 255)); //warna background
	CPen* pOldPen = pDC->SelectObject(&pen);
	pDC->Rectangle(4, 4, 280, 280);

	CDC* pDC1 = m_pic.GetDC();
	CDC dcMem1;
	CPen pen1(PS_SOLID, 4, RGB(255, 0, 255)); //warna background
	CPen* pOldPen1 = pDC1->SelectObject(&pen1);

	//garis vertikal selisih 40
	pDC1->MoveTo(0, 0);
	pDC1->LineTo(0, 280);
	pDC1->MoveTo(40, 0);
	pDC1->LineTo(40, 280);
	pDC1->MoveTo(80, 0);
	pDC1->LineTo(80, 280);
	pDC1->MoveTo(120, 0);
	pDC1->LineTo(120, 280);
	pDC1->MoveTo(160, 0);
	pDC1->LineTo(160, 280);
	pDC1->MoveTo(200, 0);
	pDC1->LineTo(200, 280);
	pDC1->MoveTo(240, 0);
	pDC1->LineTo(240, 280);
	pDC1->MoveTo(280, 0);
	pDC1->LineTo(280, 280);


	//garis horizontal selisih 40
	pDC1->MoveTo(0, 0);
	pDC1->LineTo(280, 0);
	pDC1->MoveTo(0, 40);
	pDC1->LineTo(280, 40);
	pDC1->MoveTo(0, 80);
	pDC1->LineTo(280, 80);
	pDC1->MoveTo(0, 120);
	pDC1->LineTo(280, 120);
	pDC1->MoveTo(0, 160);
	pDC1->LineTo(280, 160);
	pDC1->MoveTo(0, 200);
	pDC1->LineTo(280, 200);
	pDC1->MoveTo(0, 240);
	pDC1->LineTo(280, 240);
	pDC1->MoveTo(0, 280);
	pDC1->LineTo(280, 280);

	CDC* pDC2 = m_pic.GetDC();
	CDC dcMem2;
	CPen pen2(PS_SOLID, 5, RGB(255, 150, 0)); //warna background
	CPen* pOldPen2 = pDC2->SelectObject(&pen2);

	// membentuk pion
	CPen penpiont(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
	CPen* pOldPenpiont = pDCLingkaran->SelectObject(&penpiont);
	pDCLingkaran->Ellipse(x1, y1, x2, y2);

	//membentuk pion2
	CPen penpiont2(PS_SOLID, 5, RGB(0, 0, 255)); //warna background
	CPen* pOldPenpiont2 = pDCLingkaran2->SelectObject(&penpiont2);
	pDCLingkaran2->Ellipse(x3, y3, x4, y4);

	//membentuk angka 
	CDC* pDC5 = m_pic.GetDC();
	CDC dcMem5;
	CPen pen5(PS_SOLID, 1, RGB(0, 0, 0)); //warna landmark hitam
	CPen* pOldPen5 = pDC5->SelectObject(&pen5);
	pDC5->TextOut(20, 255, _T("0"));
	pDC5->TextOut(60, 255, _T("1"));
	pDC5->TextOut(100, 255, _T("2"));
	pDC5->TextOut(140, 255, _T("3"));
	pDC5->TextOut(180, 255, _T("4"));
	pDC5->TextOut(220, 255, _T("5"));
	pDC5->TextOut(260, 255, _T("6"));
	pDC5->TextOut(260, 215, _T("7"));
	pDC5->TextOut(220, 215, _T("8"));
	pDC5->TextOut(180, 215, _T("9"));
	pDC5->TextOut(140, 215, _T("10"));
	pDC5->TextOut(100, 215, _T("11"));
	pDC5->TextOut(60, 215, _T("12"));
	pDC5->TextOut(20, 215, _T("13"));
	pDC5->TextOut(20, 175, _T("14"));
	pDC5->TextOut(60, 175, _T("15"));
	pDC5->TextOut(100, 175, _T("16"));
	pDC5->TextOut(140, 175, _T("17"));
	pDC5->TextOut(180, 175, _T("18"));
	pDC5->TextOut(220, 175, _T("19"));
	pDC5->TextOut(260, 135, _T("20"));
	pDC5->TextOut(260, 135, _T("21"));
	pDC5->TextOut(220, 135, _T("22"));
	pDC5->TextOut(180, 135, _T("23"));
	pDC5->TextOut(140, 135, _T("24"));
	pDC5->TextOut(100, 135, _T("25"));
	pDC5->TextOut(60, 135, _T("26"));
	pDC5->TextOut(20, 135, _T("27"));
	pDC5->TextOut(20, 95, _T("28"));
	pDC5->TextOut(60, 95, _T("29"));
	pDC5->TextOut(100, 95, _T("30"));
	pDC5->TextOut(140, 95, _T("31"));
	pDC5->TextOut(180, 95, _T("32"));
	pDC5->TextOut(220, 95, _T("33"));
	pDC5->TextOut(260, 95, _T("34"));
	pDC5->TextOut(260, 55, _T("35"));
	pDC5->TextOut(220, 55, _T("36"));
	pDC5->TextOut(180, 55, _T("37"));
	pDC5->TextOut(140, 55, _T("38"));
	pDC5->TextOut(100, 55, _T("39"));
	pDC5->TextOut(60, 55, _T("40"));
	pDC5->TextOut(20, 55, _T("41"));
	pDC5->TextOut(20, 15, _T("42"));
	pDC5->TextOut(60, 15, _T("43"));
	pDC5->TextOut(100, 15, _T("44"));
	pDC5->TextOut(140, 15, _T("45"));
	pDC5->TextOut(180, 15, _T("46"));
	pDC5->TextOut(220, 15, _T("47"));
	pDC5->TextOut(260, 15, _T("48"));

	//ular selisih 10
	pDC2->Ellipse(90, 150, 110, 125);
	pDC2->MoveTo(100, 150);
	pDC2->LineTo(100, 190);
	pDC2->MoveTo(100, 190);
	pDC2->LineTo(60, 190);
	pDC2->MoveTo(60, 190);
	pDC2->LineTo(60, 230);

	pDC2->Ellipse(205, 30, 235, 10);
	pDC2->MoveTo(220, 30);
	pDC2->LineTo(220, 70);
	pDC2->MoveTo(220, 70);
	pDC2->LineTo(180, 70);

	pDC2->Ellipse(245, 190, 275, 170);
	pDC2->MoveTo(260, 190);
	pDC2->LineTo(260, 270);
	pDC2->MoveTo(260, 270);
	pDC2->LineTo(220, 270);

	//Tangga selisih 10 dan 20
	CDC* pDC3 = m_pic.GetDC();
	CDC dcMem3;
	CPen pen3(PS_SOLID, 4, RGB(0, 255, 150)); //warna background
	CPen* pOldPen3 = pDC3->SelectObject(&pen3);

	pDC3->MoveTo(170, 250);
	pDC3->LineTo(130, 150);
	pDC3->MoveTo(190, 250);
	pDC3->LineTo(150, 150);

	pDC3->MoveTo(140, 170);
	pDC3->LineTo(155, 170);
	pDC3->MoveTo(149, 190);
	pDC3->LineTo(167, 190);
	pDC3->MoveTo(158, 210);
	pDC3->LineTo(175, 210);
	pDC3->MoveTo(162, 230);
	pDC3->LineTo(183, 230);
	//Tangga selisih 10 dan 20

	pDC3->MoveTo(210, 150);
	pDC3->LineTo(50, 70);
	pDC3->MoveTo(210, 130);
	pDC3->LineTo(70, 60);

	pDC3->MoveTo(82, 82);
	pDC3->LineTo(107, 82);
	pDC3->MoveTo(114, 102);
	pDC3->LineTo(148, 102);
	pDC3->MoveTo(153, 122);
	pDC3->LineTo(189, 122);
}


void CprojectDlg::OnBnClickedAcak()
{
	// TODO: Add your control notification handler code here
	int random = 0;
	srand(time(0));
	random = rand() % 6 + 1;
	m_display.Format(_T("%d"), random);
	CPen penrec(PS_SOLID, 0, RGB(0, 0, 0));
	CPen* pOldePenrectangle = pDCRectangle->SelectObject(&penrec);
	pDCRectangle->Rectangle(x1, y1, x2, y2);
	geser(random);
	Tangga();
	Ular();
	CPen penpiont(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
	CPen* pOldPenpiont = pDCLingkaran->SelectObject(&penpiont);
	pDCLingkaran->Ellipse(x1, y1, x2, y2);
	reset();
	if (x1 == 240 && x2 == 280 && y1 == 0 && y2 == 40) {
		UpdateData(TRUE);
		m_acak.EnableWindow(FALSE);
		m_hapus.EnableWindow(TRUE);
	}

	UpdateData(FALSE);
}


void CprojectDlg::geser(int x)
{
	// TODO: Add your implementation code here.
	if (y1 == 240 && y2 == 280) {
		while (x) {
			if (x1 != 240 && x != 280) {

				x1 += 40;
				x2 += 40;
				x--;


			}
			else {
				y1 -= 40;
				y2 -= 40;
				x--;
				break;
			}
		}
	}
	if (y1 == 200 && y2 == 240) {
		while (x) {
			if (x1 != 0 && x != 40) {

				x1 -= 40;
				x2 -= 40;
				x--;

			}
			else {
				y1 -= 40;
				y2 -= 40;
				x--;
				break;
			}
		}
	}
	if (y1 == 160 && y2 == 200) {
		while (x) {
			if (x1 != 240 && x != 280) {

				x1 += 40;
				x2 += 40;
				x--;

			}
			else {
				y1 -= 40;
				y2 -= 40;
				x--;
				break;
			}
		}
	}
	if (y1 == 120 && y2 == 160) {
		while (x) {
			if (x1 != 0 && x != 40) {

				x1 -= 40;
				x2 -= 40;
				x--;

			}
			else {
				y1 -= 40;
				y2 -= 40;
				x--;
				break;
			}
		}
	}
	if (y1 == 80 && y2 == 120) {
		while (x) {
			if (x1 != 240 && x != 280) {

				x1 += 40;
				x2 += 40;
				x--;

			}
			else {
				y1 -= 40;
				y2 -= 40;
				x--;
				break;
			}
		}
	}
	if (y1 == 40 && y2 == 80) {
		while (x) {
			if (x1 != 0 && x != 40) {

				x1 -= 40;
				x2 -= 40;
				x--;

			}
			else {
				y1 -= 40;
				y2 -= 40;
				x--;
				break;
			}
		}
	}
	if (y1 == 0 && y2 == 40) {
		while (x) {
			if (x1 != 240 && x != 280) {

				x1 += 40;
				x2 += 40;
				x--;

			}
			else {
				x1 = 240;
				x2 = 280;
				y1 = 0;
				y2 = 40;
				break;
			}
		}
	}
}
void CprojectDlg::Tangga()
{
	// TODO: Add your implementation code here.
	if (x1 == 160 && y1 == 240 && x2 == 200 && y2 == 280) {
		y1 = 120;
		y2 = 160;
		x1 = 120;
		x2 = 160;
	}
	else if (x1 == 200 && y1 == 120 && x2 == 240 && y2 == 160) {
		y1 = 40;
		y2 = 80;
		x1 = 40;
		x2 = 80;
	}
}

void CprojectDlg::Ular() {
	if (x1 == 80 && y1 == 120 && x2 == 120 && y2 == 160) {
		y1 = 200;
		y2 = 240;
		x1 = 40;
		x2 = 80;
	}
	else if (x1 == 200 && y1 == 0 && x2 == 240 && y2 == 40) {
		y1 = 40;
		y2 = 80;
		x1 = 160;
		x2 = 200;
	}
	else if (x1 == 160 && y1 == 240 && x2 == 200 && y2 == 280) {
		y1 = 240;
		y2 = 280;
		x1 = 200;
		x2 = 240;
	}
}
void CprojectDlg::OnBnClickedAcak2()
{
	// TODO: Add your control notification handler code here
	int random = 0;
	srand(time(0));
	random = rand() % 6 + 1;
	m_display2.Format(_T("%d"), random);
	CPen penrec(PS_SOLID, 0, RGB(0, 0, 0));
	CPen* pOldePenrectangle = pDCRectangle->SelectObject(&penrec);
	pDCRectangle->Rectangle(x3, y3, x4, y4);
	geser2(random);
	Tangga2();
	Ular2();
	CPen penpiont2(PS_SOLID, 5, RGB(0, 0, 255)); //warna background
	CPen* pOldPenpiont2 = pDCLingkaran2->SelectObject(&penpiont2);
	pDCLingkaran2->Ellipse(x3, y3, x4, y4);
	reset();
	if (x3 == 240 && x4 == 280 && y3 == 0 && y4 == 40) {
		UpdateData(TRUE);
		m_acak2.EnableWindow(FALSE);
		m_hapus.EnableWindow(TRUE);
	}
	UpdateData(FALSE);
}
void CprojectDlg::geser2(int x12)
{
	// TODO: Add your implementation code here.
	if (y3 == 240 && y4 == 280) {
		while (x12) {
			if (x3 != 240 && x4 != 280) {

				x3 += 40;
				x4 += 40;
				x12--;
			}
			else {
				y3 -= 40;
				y4 -= 40;
				x12--;
				break;
			}
		}
	}
	if (y3 == 200 && y4 == 240) {
		while (x12) {
			if (x3 != 0 && x4 != 40) {
				x3 -= 40;
				x4 -= 40;
				x12--;

			}
			else {
				y3 -= 40;
				y4 -= 40;
				x12--;
				break;
			}
		}
	}
	if (y3 == 160 && y4 == 200) {
		while (x12) {
			if (x3 != 240 && x4 != 280) {

				x3 += 40;
				x4 += 40;
				x12--;
			}
			else {
				y3 -= 40;
				y4 -= 40;
				x12--;
				break;
			}
		}
	}
	if (y3 == 120 && y4 == 160) {
		while (x12) {
			if (x3 != 0 && x4 != 40) {

				x3 -= 40;
				x4 -= 40;
				x12--;
			}
			else {
				y3 -= 40;
				y4 -= 40;
				x12--;
				break;
			}
		}
	}
	if (y3 == 80 && y4 == 120) {
		while (x12) {
			if (x3 != 240 && x4 != 280) {

				x3 += 40;
				x4 += 40;
				x12--;
			}
			else {
				y3 -= 40;
				y4 -= 40;
				x12--;
				break;
			}
		}
	}
	if (y3 == 40 && y4 == 80) {
		while (x12) {
			if (x3 != 0 && x4 != 40) {

				x3 -= 40;
				x4 -= 40;
				x12--;

			}
			else {
				y3 -= 40;
				y4 -= 40;
				x12--;
				break;
			}
		}
	}
	if (y3 == 0 && y4 == 40) {
		while (x12) {
			if (x3 != 240 && x4 != 280) {

				x3 += 40;
				x4 += 40;
				x12--;
			}
			else {
				x3 = 240;
				x4 = 280;
				y3 = 0;
				y4 = 40;
				break;
			}
		}
	}

}
int CprojectDlg::Tangga2()
{
	// TODO: Add your implementation code here.
	if (x3 == 160 && y3 == 240 && x4 == 200 && y4 == 280) {
		y3 = 120;
		y4 = 160;
		x3 = 120;
		x4 = 160;
	}
	else if (x3 == 200 && y3 == 120 && x4 == 240 && y4 == 160) {
		y3 = 40;
		y4 = 80;
		x3 = 40;
		x4 = 80;
	}
	return 0;
}

int CprojectDlg::Ular2() {
	if (x3 == 80 && y3 == 120 && x4 == 120 && y4 == 160) {
		y3 = 200;
		y4 = 240;
		x3 = 40;
		x4 = 80;
	}
	else if (x3 == 200 && y3 == 0 && x4 == 240 && y4 == 40) {
		y3 = 40;
		y4 = 80;
		x3 = 160;
		x4 = 200;
	}
	else if (x3 == 160 && y3 == 240 && x4 == 200 && y4 == 280) {
		y3 = 240;
		y4 = 280;
		x3 = 200;
		x4 = 240;
	}
	return 0;
}
void CprojectDlg::reset() {
	// TODO: Add your control notification handler code here
	CDC* pDC = m_pic.GetDC();
	CDC dcMem;
	CPen pen(PS_SOLID, 1, RGB(255, 255, 255)); //warna background
	CPen* pOldPen = pDC->SelectObject(&pen);
	pDC->Rectangle(4, 4, 280, 280);

	CDC* pDC1 = m_pic.GetDC();
	CDC dcMem1;
	CPen pen1(PS_SOLID, 4, RGB(255, 0, 255)); //warna background
	CPen* pOldPen1 = pDC1->SelectObject(&pen1);

	//garis vertikal selisih 40
	pDC1->MoveTo(0, 0);
	pDC1->LineTo(0, 280);
	pDC1->MoveTo(40, 0);
	pDC1->LineTo(40, 280);
	pDC1->MoveTo(80, 0);
	pDC1->LineTo(80, 280);
	pDC1->MoveTo(120, 0);
	pDC1->LineTo(120, 280);
	pDC1->MoveTo(160, 0);
	pDC1->LineTo(160, 280);
	pDC1->MoveTo(200, 0);
	pDC1->LineTo(200, 280);
	pDC1->MoveTo(240, 0);
	pDC1->LineTo(240, 280);
	pDC1->MoveTo(280, 0);
	pDC1->LineTo(280, 280);


	//garis horizontal selisih 40
	pDC1->MoveTo(0, 0);
	pDC1->LineTo(280, 0);
	pDC1->MoveTo(0, 40);
	pDC1->LineTo(280, 40);
	pDC1->MoveTo(0, 80);
	pDC1->LineTo(280, 80);
	pDC1->MoveTo(0, 120);
	pDC1->LineTo(280, 120);
	pDC1->MoveTo(0, 160);
	pDC1->LineTo(280, 160);
	pDC1->MoveTo(0, 200);
	pDC1->LineTo(280, 200);
	pDC1->MoveTo(0, 240);
	pDC1->LineTo(280, 240);
	pDC1->MoveTo(0, 280);
	pDC1->LineTo(280, 280);

	CDC* pDC2 = m_pic.GetDC();
	CDC dcMem2;
	CPen pen2(PS_SOLID, 5, RGB(255, 150, 0)); //warna background
	CPen* pOldPen2 = pDC2->SelectObject(&pen2);

	// membentuk pion
	CPen penpiont(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
	CPen* pOldPenpiont = pDCLingkaran->SelectObject(&penpiont);
	pDCLingkaran->Ellipse(x1, y1, x2, y2);

	//membentuk pion2
	CPen penpiont2(PS_SOLID, 5, RGB(0, 0, 255)); //warna background
	CPen* pOldPenpiont2 = pDCLingkaran2->SelectObject(&penpiont2);
	pDCLingkaran2->Ellipse(x3, y3, x4, y4);

	//membentuk angka 
	CDC* pDC5 = m_pic.GetDC();
	CDC dcMem5;
	CPen pen5(PS_SOLID, 1, RGB(0, 0, 0)); //warna landmark hitam
	CPen* pOldPen5 = pDC5->SelectObject(&pen5);
	pDC5->TextOut(20, 255, _T("0"));
	pDC5->TextOut(60, 255, _T("1"));
	pDC5->TextOut(100, 255, _T("2"));
	pDC5->TextOut(140, 255, _T("3"));
	pDC5->TextOut(180, 255, _T("4"));
	pDC5->TextOut(220, 255, _T("5"));
	pDC5->TextOut(260, 255, _T("6"));
	pDC5->TextOut(260, 215, _T("7"));
	pDC5->TextOut(220, 215, _T("8"));
	pDC5->TextOut(180, 215, _T("9"));
	pDC5->TextOut(140, 215, _T("10"));
	pDC5->TextOut(100, 215, _T("11"));
	pDC5->TextOut(60, 215, _T("12"));
	pDC5->TextOut(20, 215, _T("13"));
	pDC5->TextOut(20, 175, _T("14"));
	pDC5->TextOut(60, 175, _T("15"));
	pDC5->TextOut(100, 175, _T("16"));
	pDC5->TextOut(140, 175, _T("17"));
	pDC5->TextOut(180, 175, _T("18"));
	pDC5->TextOut(220, 175, _T("19"));
	pDC5->TextOut(260, 135, _T("20"));
	pDC5->TextOut(260, 135, _T("21"));
	pDC5->TextOut(220, 135, _T("22"));
	pDC5->TextOut(180, 135, _T("23"));
	pDC5->TextOut(140, 135, _T("24"));
	pDC5->TextOut(100, 135, _T("25"));
	pDC5->TextOut(60, 135, _T("26"));
	pDC5->TextOut(20, 135, _T("27"));
	pDC5->TextOut(20, 95, _T("28"));
	pDC5->TextOut(60, 95, _T("29"));
	pDC5->TextOut(100, 95, _T("30"));
	pDC5->TextOut(140, 95, _T("31"));
	pDC5->TextOut(180, 95, _T("32"));
	pDC5->TextOut(220, 95, _T("33"));
	pDC5->TextOut(260, 95, _T("34"));
	pDC5->TextOut(260, 55, _T("35"));
	pDC5->TextOut(220, 55, _T("36"));
	pDC5->TextOut(180, 55, _T("37"));
	pDC5->TextOut(140, 55, _T("38"));
	pDC5->TextOut(100, 55, _T("39"));
	pDC5->TextOut(60, 55, _T("40"));
	pDC5->TextOut(20, 55, _T("41"));
	pDC5->TextOut(20, 15, _T("42"));
	pDC5->TextOut(60, 15, _T("43"));
	pDC5->TextOut(100, 15, _T("44"));
	pDC5->TextOut(140, 15, _T("45"));
	pDC5->TextOut(180, 15, _T("46"));
	pDC5->TextOut(220, 15, _T("47"));
	pDC5->TextOut(260, 15, _T("48"));

	//ular selisih 10
	pDC2->Ellipse(90, 150, 110, 125);
	pDC2->MoveTo(100, 150);
	pDC2->LineTo(100, 190);
	pDC2->MoveTo(100, 190);
	pDC2->LineTo(60, 190);
	pDC2->MoveTo(60, 190);
	pDC2->LineTo(60, 230);

	pDC2->Ellipse(205, 30, 235, 10);
	pDC2->MoveTo(220, 30);
	pDC2->LineTo(220, 70);
	pDC2->MoveTo(220, 70);
	pDC2->LineTo(180, 70);

	pDC2->Ellipse(245, 190, 275, 170);
	pDC2->MoveTo(260, 190);
	pDC2->LineTo(260, 270);
	pDC2->MoveTo(260, 270);
	pDC2->LineTo(220, 270);

	//Tangga selisih 10 dan 20
	CDC* pDC3 = m_pic.GetDC();
	CDC dcMem3;
	CPen pen3(PS_SOLID, 4, RGB(0, 255, 150)); //warna background
	CPen* pOldPen3 = pDC3->SelectObject(&pen3);

	pDC3->MoveTo(170, 250);
	pDC3->LineTo(130, 150);
	pDC3->MoveTo(190, 250);
	pDC3->LineTo(150, 150);

	pDC3->MoveTo(140, 170);
	pDC3->LineTo(155, 170);
	pDC3->MoveTo(149, 190);
	pDC3->LineTo(167, 190);
	pDC3->MoveTo(158, 210);
	pDC3->LineTo(175, 210);
	pDC3->MoveTo(162, 230);
	pDC3->LineTo(183, 230);
	//Tangga selisih 10 dan 20

	pDC3->MoveTo(210, 150);
	pDC3->LineTo(50, 70);
	pDC3->MoveTo(210, 130);
	pDC3->LineTo(70, 60);

	pDC3->MoveTo(82, 82);
	pDC3->LineTo(107, 82);
	pDC3->MoveTo(114, 102);
	pDC3->LineTo(148, 102);
	pDC3->MoveTo(153, 122);
	pDC3->LineTo(189, 122);
}


void CprojectDlg::OnBnClickedButton4()
{
	// TODO: Add your control notification handler code here
	m_hapus.EnableWindow(TRUE);
	reset2();
	int data, move = 0;
	data = GetDlgItemInt(IDC_EDIT3);
	move = move + data;
	CDC* pDC5 = m_pic.GetDC();
	CDC dcMem5;
	CPen pen5(PS_SOLID, 1, RGB(0, 0, 0)); //warna landmark hitam
	CPen* pOldPen5 = pDC5->SelectObject(&pen5);
	if (move == 0) {
		x1 = 0;
		y1 = 240;
		x2 = 40;
		y2 = 280;
		CPen penpiont(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont = pDCLingkaran->SelectObject(&penpiont);
		pDCLingkaran->Ellipse(x1, y1, x2, y2);
		pDC5->TextOut(20, 255, _T("0"));
	}
	else if (move == 1) {
		x1 = 40;
		y1 = 240;
		x2 = 80;
		y2 = 280;
		CPen penpiont(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont = pDCLingkaran->SelectObject(&penpiont);
		pDCLingkaran->Ellipse(x1, y1, x2, y2);
		pDC5->TextOut(60, 255, _T("1"));
	}
	else if (move == 2) {
		x1 = 80;
		y1 = 240;
		x2 = 120;
		y2 = 280;
		CPen penpiont(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont = pDCLingkaran->SelectObject(&penpiont);
		pDCLingkaran->Ellipse(x1, y1, x2, y2);
		pDC5->TextOut(100, 255, _T("2"));
	}
	else if (move == 3) {
		x1 = 120;
		y1 = 240;
		x2 = 160;
		y2 = 280;
		CPen penpiont(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont = pDCLingkaran->SelectObject(&penpiont);
		pDCLingkaran->Ellipse(x1, y1, x2, y2);
		pDC5->TextOut(140, 255, _T("3"));
	}
	else if (move == 4) {
		x1 = 120;
		y1 = 120;
		x2 = 160;
		y2 = 160;
		CPen penpiont(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont = pDCLingkaran->SelectObject(&penpiont);
		pDCLingkaran->Ellipse(x1, y1, x2, y2);
		pDC5->TextOut(140, 135, _T("24"));
	}
	else if (move == 5) {
		x1 = 200;
		y1 = 240;
		x2 = 240;
		y2 = 280;
		CPen penpiont(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont = pDCLingkaran->SelectObject(&penpiont);
		pDCLingkaran->Ellipse(x1, y1, x2, y2);
		pDC5->TextOut(220, 255, _T("5"));
	}
	else if (move == 6) {
		x1 = 240;
		y1 = 240;
		x2 = 280;
		y2 = 280;
		CPen penpiont(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont = pDCLingkaran->SelectObject(&penpiont);
		pDCLingkaran->Ellipse(x1, y1, x2, y2);
		pDC5->TextOut(260, 255, _T("6"));
	}
	else if (move == 7) {
		x1 = 240;
		y1 = 200;
		x2 = 280;
		y2 = 240;
		CPen penpiont(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont = pDCLingkaran->SelectObject(&penpiont);
		pDCLingkaran->Ellipse(x1, y1, x2, y2);
		pDC5->TextOut(260, 215, _T("7"));
	}
	else if (move == 8) {
		x1 = 200;
		y1 = 200;
		x2 = 240;
		y2 = 240;
		CPen penpiont(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont = pDCLingkaran->SelectObject(&penpiont);
		pDCLingkaran->Ellipse(x1, y1, x2, y2);
		pDC5->TextOut(220, 215, _T("8"));
	}
	else if (move == 9) {
		x1 = 160;
		y1 = 200;
		x2 = 200;
		y2 = 240;
		CPen penpiont(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont = pDCLingkaran->SelectObject(&penpiont);
		pDCLingkaran->Ellipse(x1, y1, x2, y2);
		pDC5->TextOut(180, 215, _T("9"));
	}
	else if (move == 10) {
	x1 = 120;
	y1 = 200;
	x2 = 160;
	y2 = 240;
		CPen penpiont(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont = pDCLingkaran->SelectObject(&penpiont);
		pDCLingkaran->Ellipse(x1, y1, x2, y2);
		pDC5->TextOut(140, 215, _T("10"));
	}
	else if (move == 11) {
	x1 = 80;
	y1 = 200;
	x2 = 120;
	y2 = 240;
		CPen penpiont(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont = pDCLingkaran->SelectObject(&penpiont);
		pDCLingkaran->Ellipse(x1, y1, x2, y2);
		pDC5->TextOut(100, 215, _T("11"));
	}
	else if (move == 12) {
	x1 = 40;
	y1 = 200;
	x2 = 80;
	y2 = 240;
		CPen penpiont(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont = pDCLingkaran->SelectObject(&penpiont);
		pDCLingkaran->Ellipse(x1, y1, x2, y2);
		pDC5->TextOut(60, 215, _T("12"));
	}
	else if (move == 13) {
	x1 = 0;
	y1 = 200;
	x2 = 40;
	y2 = 240;
		CPen penpiont(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont = pDCLingkaran->SelectObject(&penpiont);
		pDCLingkaran->Ellipse(x1, y1, x2, y2);
		pDC5->TextOut(20, 215, _T("13"));
	}
	else if (move == 14) {
	x1 = 0;
	y1 = 160;
	x2 = 40;
	y2 = 200;
		CPen penpiont(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont = pDCLingkaran->SelectObject(&penpiont);
		pDCLingkaran->Ellipse(x1, y1, x2, y2);
		pDC5->TextOut(20, 175, _T("14"));
	}
	else if (move == 15) {
	x1 = 40;
	y1 = 160;
	x2 = 80;
	y2 = 200;
		CPen penpiont(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont = pDCLingkaran->SelectObject(&penpiont);
		pDCLingkaran->Ellipse(x1, y1, x2, y2);
		pDC5->TextOut(60, 175, _T("15"));
	}
	else if (move == 16) {
	x1 = 80;
	y1 = 160;
	x2 = 120;
	y2 = 200;
		CPen penpiont(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont = pDCLingkaran->SelectObject(&penpiont);
		pDCLingkaran->Ellipse(x1, y1, x2, y2);
		pDC5->TextOut(100, 175, _T("16"));
	}
	else if (move == 17) {
	x1 = 120;
	y1 = 160;
	x2 = 160;
	y2 = 200;
		CPen penpiont(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont = pDCLingkaran->SelectObject(&penpiont);
		pDCLingkaran->Ellipse(x1, y1, x2, y2);
		pDC5->TextOut(140, 175, _T("17"));
	}
	else if (move == 18) {
	x1 = 160;
	y1 = 160;
	x2 = 200;
	y2 = 200;
		CPen penpiont(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont = pDCLingkaran->SelectObject(&penpiont);
		pDCLingkaran->Ellipse(x1, y1, x2, y2);
		pDC5->TextOut(180, 175, _T("18"));
	}
	else if (move == 19) {
	x1 = 200;
	y1 = 160;
	x2 = 240;
	y2 = 200;
		CPen penpiont(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont = pDCLingkaran->SelectObject(&penpiont);
		pDCLingkaran->Ellipse(x1, y1, x2, y2);
		pDC5->TextOut(220, 175, _T("19"));
	}
	else if (move == 20) {
	x1 = 200;
	y1 = 240;
	x2 = 240;
	y2 = 280;
	CPen penpiont(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
	CPen* pOldPenpiont = pDCLingkaran->SelectObject(&penpiont);
	pDCLingkaran->Ellipse(x1, y1, x2, y2);
	pDC5->TextOut(220, 255, _T("5"));
	}
	else if (move == 21) {
	x1 = 240;
	y1 = 120;
	x2 = 280;
	y2 = 160;
		CPen penpiont(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont = pDCLingkaran->SelectObject(&penpiont);
		pDCLingkaran->Ellipse(x1, y1, x2, y2);
		pDC5->TextOut(260, 135, _T("21"));
	}
	else if (move == 22) {
	x1 = 40;
	y1 = 40;
	x2 = 80;
	y2 = 80;
	CPen penpiont(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
	CPen* pOldPenpiont = pDCLingkaran->SelectObject(&penpiont);
	pDCLingkaran->Ellipse(x1, y1, x2, y2);
	pDC5->TextOut(60, 55, _T("40"));
	}
	else if (move == 23) {
	x1 = 160;
	y1 = 120;
	x2 = 200;
	y2 = 160;
		CPen penpiont(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont = pDCLingkaran->SelectObject(&penpiont);
		pDCLingkaran->Ellipse(x1, y1, x2, y2);
		pDC5->TextOut(180, 135, _T("23"));
	}
	else if (move == 24) {
	x1 = 120;
	y1 = 120;
	x2 = 160;
	y2 = 160;
		CPen penpiont(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont = pDCLingkaran->SelectObject(&penpiont);
		pDCLingkaran->Ellipse(x1, y1, x2, y2);
		pDC5->TextOut(140, 135, _T("24"));
	}
	else if (move == 25) {
	x1 = 40;
	y1 = 200;
	x2 = 80;
	y2 = 240;
	CPen penpiont(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
	CPen* pOldPenpiont = pDCLingkaran->SelectObject(&penpiont);
	pDCLingkaran->Ellipse(x1, y1, x2, y2);
	pDC5->TextOut(60, 215, _T("12"));
	}
	else if (move == 26) {
	x1 = 40;
	y1 = 120;
	x2 = 80;
	y2 = 160;
		CPen penpiont(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont = pDCLingkaran->SelectObject(&penpiont);
		pDCLingkaran->Ellipse(x1, y1, x2, y2);
		pDC5->TextOut(60, 135, _T("26"));
	}
	else if (move == 27) {
	x1 = 0;
	y1 = 120;
	x2 = 40;
	y2 = 160;
		CPen penpiont(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont = pDCLingkaran->SelectObject(&penpiont);
		pDCLingkaran->Ellipse(x1, y1, x2, y2);
		pDC5->TextOut(20, 135, _T("27"));
	}
	else if (move == 28) {
	x1 = 0;
	y1 = 80;
	x2 = 40;
	y2 = 120;
		CPen penpiont(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont = pDCLingkaran->SelectObject(&penpiont);
		pDCLingkaran->Ellipse(x1, y1, x2, y2);
		pDC5->TextOut(20, 95, _T("28"));
	}
	else if (move == 29) {
	x1 = 40;
	y1 = 80;
	x2 = 80;
	y2 = 120;
		CPen penpiont(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont = pDCLingkaran->SelectObject(&penpiont);
		pDCLingkaran->Ellipse(x1, y1, x2, y2);
		pDC5->TextOut(60, 95, _T("29"));
	}
	else if (move == 30) {
	x1 = 80;
	y1 = 80;
	x2 = 120;
	y2 = 120;
		CPen penpiont(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont = pDCLingkaran->SelectObject(&penpiont);
		pDCLingkaran->Ellipse(x1, y1, x2, y2);
		pDC5->TextOut(100, 95, _T("30"));
	}
	else if (move == 31) {
	x1 = 120;
	y1 = 80;
	x2 = 160;
	y2 = 120;
		CPen penpiont(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont = pDCLingkaran->SelectObject(&penpiont);
		pDCLingkaran->Ellipse(x1, y1, x2, y2);
		pDC5->TextOut(140, 95, _T("31"));
	}
	else if (move == 32) {
	x1 =160;
	y1 = 80;
	x2 = 200;
	y2 = 120;
		CPen penpiont(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont = pDCLingkaran->SelectObject(&penpiont);
		pDCLingkaran->Ellipse(x1, y1, x2, y2);
		pDC5->TextOut(180, 95, _T("32"));
	}
	else if (move == 33) {
	x1 = 200;
	y1 = 80;
	x2 = 240;
	y2 = 120;
		CPen penpiont(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont = pDCLingkaran->SelectObject(&penpiont);
		pDCLingkaran->Ellipse(x1, y1, x2, y2);
		pDC5->TextOut(220, 95, _T("33"));
	}
	else if (move == 34) {
	x1 = 240;
	y1 = 80;
	x2 = 280;
	y2 = 120;
		CPen penpiont(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont = pDCLingkaran->SelectObject(&penpiont);
		pDCLingkaran->Ellipse(x1, y1, x2, y2);
		pDC5->TextOut(260, 95, _T("34"));
	}
	else if (move == 35) {
	x1 = 240;
	y1 = 40;
	x2 = 280;
	y2 = 80;
		CPen penpiont(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont = pDCLingkaran->SelectObject(&penpiont);
		pDCLingkaran->Ellipse(x1, y1, x2, y2);
		pDC5->TextOut(260, 55, _T("35"));
	}
	else if (move == 36) {
	x1 = 200;
	y1 = 40;
	x2 = 240;
	y2 = 80;
		CPen penpiont(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont = pDCLingkaran->SelectObject(&penpiont);
		pDCLingkaran->Ellipse(x1, y1, x2, y2);
		pDC5->TextOut(220, 55, _T("36"));
	}
	else if (move == 37) {
	x1 = 160;
	y1 = 40;
	x2 = 200;
	y2 = 80;
		CPen penpiont(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont = pDCLingkaran->SelectObject(&penpiont);
		pDCLingkaran->Ellipse(x1, y1, x2, y2);
		pDC5->TextOut(180, 55, _T("37"));
	}
	else if (move == 38) {
	x1 = 120;
	y1 = 40;
	x2 = 160;
	y2 = 80;
		CPen penpiont(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont = pDCLingkaran->SelectObject(&penpiont);
		pDCLingkaran->Ellipse(x1, y1, x2, y2);
		pDC5->TextOut(140, 55, _T("38"));
	}
	else if (move == 39) {
	x1 = 80;
	y1 = 40;
	x2 = 120;
	y2 = 80;
		CPen penpiont(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont = pDCLingkaran->SelectObject(&penpiont);
		pDCLingkaran->Ellipse(x1, y1, x2, y2);
		pDC5->TextOut(100, 55, _T("39"));
	}
	else if (move == 40) {
	x1 = 40;
	y1 = 40;
	x2 = 80;
	y2 = 80;
		CPen penpiont(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont = pDCLingkaran->SelectObject(&penpiont);
		pDCLingkaran->Ellipse(x1, y1, x2, y2);
		pDC5->TextOut(60, 55, _T("40"));
	}
	else if (move == 41) {
	x1 = 0;
	y1 = 40;
	x2 = 40;
	y2 = 80;
		CPen penpiont(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont = pDCLingkaran->SelectObject(&penpiont);
		pDCLingkaran->Ellipse(x1, y1, x2, y2);
		pDC5->TextOut(20, 55, _T("41"));
	}
	else if (move == 42) {
	x1 = 0;
	y1 = 0;
	x2 = 40;
	y2 = 40;
		CPen penpiont(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont = pDCLingkaran->SelectObject(&penpiont);
		pDCLingkaran->Ellipse(x1, y1, x2, y2);
		pDC5->TextOut(20, 15, _T("42"));
	}
	else if (move == 43) {
	x1 = 40;
	y1 = 0;
	x2 = 80;
	y2 = 40;
		CPen penpiont(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont = pDCLingkaran->SelectObject(&penpiont);
		pDCLingkaran->Ellipse(x1, y1, x2, y2);
		pDC5->TextOut(60, 15, _T("43"));
	}
	else if (move == 44) {
	x1 = 80;
	y1 = 0;
	x2 = 120;
	y2 = 40;
		CPen penpiont(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont = pDCLingkaran->SelectObject(&penpiont);
		pDCLingkaran->Ellipse(x1, y1, x2, y2);
		pDC5->TextOut(100, 15, _T("44"));
	}
	else if (move == 45) {
	x1 = 120;
	y1 = 0;
	x2 = 160;
	y2 = 40;
		CPen penpiont(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont = pDCLingkaran->SelectObject(&penpiont);
		pDCLingkaran->Ellipse(x1, y1, x2, y2);
		pDC5->TextOut(140, 15, _T("45"));
	}
	else if (move == 46) {
	x1 = 160;
	y1 = 0;
	x2 = 240;
	y2 = 40;
		CPen penpiont(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont = pDCLingkaran->SelectObject(&penpiont);
		pDCLingkaran->Ellipse(x1, y1, x2, y2);
		pDC5->TextOut(180, 15, _T("46"));
	}
	else if (move == 47) {
	x1 = 160;
	y1 = 40;
	x2 = 200;
	y2 = 80;
	CPen penpiont(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
	CPen* pOldPenpiont = pDCLingkaran->SelectObject(&penpiont);
	pDCLingkaran->Ellipse(x1, y1, x2, y2);
	pDC5->TextOut(180, 55, _T("37"));
	}
	else if (move == 48) {
	x1 = 240;
	y1 = 0;
	x2 = 280;
	y2 = 40;
		CPen penpiont(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont = pDCLingkaran->SelectObject(&penpiont);
		pDCLingkaran->Ellipse(x1, y1, x2, y2);
		pDC5->TextOut(260, 15, _T("48"));
		UpdateData(TRUE);
		m_gerak.EnableWindow(FALSE);
		m_hapus.EnableWindow(TRUE);
	}
	//reset2(move);
}

void CprojectDlg::reset2() {
	// TODO: Add your control notification handler code here
	CDC* pDC = m_pic.GetDC();
	CDC dcMem;
	CPen pen(PS_SOLID, 1, RGB(255, 255, 255)); //warna background
	CPen* pOldPen = pDC->SelectObject(&pen);
	pDC->Rectangle(4, 4, 280, 280);

	CDC* pDC1 = m_pic.GetDC();
	CDC dcMem1;
	CPen pen1(PS_SOLID, 4, RGB(255, 0, 255)); //warna background
	CPen* pOldPen1 = pDC1->SelectObject(&pen1);

	//membentuk pion2
	CPen penpiont2(PS_SOLID, 5, RGB(0, 0, 255)); //warna background
	CPen* pOldPenpiont2 = pDCLingkaran2->SelectObject(&penpiont2);
	pDCLingkaran2->Ellipse(x3, y3, x4, y4);

	//garis vertikal selisih 40
	pDC1->MoveTo(0, 0);
	pDC1->LineTo(0, 280);
	pDC1->MoveTo(40, 0);
	pDC1->LineTo(40, 280);
	pDC1->MoveTo(80, 0);
	pDC1->LineTo(80, 280);
	pDC1->MoveTo(120, 0);
	pDC1->LineTo(120, 280);
	pDC1->MoveTo(160, 0);
	pDC1->LineTo(160, 280);
	pDC1->MoveTo(200, 0);
	pDC1->LineTo(200, 280);
	pDC1->MoveTo(240, 0);
	pDC1->LineTo(240, 280);
	pDC1->MoveTo(280, 0);
	pDC1->LineTo(280, 280);


	//garis horizontal selisih 40
	pDC1->MoveTo(0, 0);
	pDC1->LineTo(280, 0);
	pDC1->MoveTo(0, 40);
	pDC1->LineTo(280, 40);
	pDC1->MoveTo(0, 80);
	pDC1->LineTo(280, 80);
	pDC1->MoveTo(0, 120);
	pDC1->LineTo(280, 120);
	pDC1->MoveTo(0, 160);
	pDC1->LineTo(280, 160);
	pDC1->MoveTo(0, 200);
	pDC1->LineTo(280, 200);
	pDC1->MoveTo(0, 240);
	pDC1->LineTo(280, 240);
	pDC1->MoveTo(0, 280);
	pDC1->LineTo(280, 280);

	CDC* pDC2 = m_pic.GetDC();
	CDC dcMem2;
	CPen pen2(PS_SOLID, 4, RGB(255, 150, 0)); //warna background
	CPen* pOldPen2 = pDC2->SelectObject(&pen2);

	//membentuk angka 
	CDC* pDC5 = m_pic.GetDC();
	CDC dcMem5;
	CPen pen5(PS_SOLID, 1, RGB(0, 0, 0)); //warna landmark hitam
	CPen* pOldPen5 = pDC5->SelectObject(&pen5);
	pDC5->TextOut(20, 255, _T("0"));
	pDC5->TextOut(60, 255, _T("1"));
	pDC5->TextOut(100, 255, _T("2"));
	pDC5->TextOut(140, 255, _T("3"));
	pDC5->TextOut(180, 255, _T("4"));
	pDC5->TextOut(220, 255, _T("5"));
	pDC5->TextOut(260, 255, _T("6"));
	pDC5->TextOut(260, 215, _T("7"));
	pDC5->TextOut(220, 215, _T("8"));
	pDC5->TextOut(180, 215, _T("9"));
	pDC5->TextOut(140, 215, _T("10"));
	pDC5->TextOut(100, 215, _T("11"));
	pDC5->TextOut(60, 215, _T("12"));
	pDC5->TextOut(20, 215, _T("13"));
	pDC5->TextOut(20, 175, _T("14"));
	pDC5->TextOut(60, 175, _T("15"));
	pDC5->TextOut(100, 175, _T("16"));
	pDC5->TextOut(140, 175, _T("17"));
	pDC5->TextOut(180, 175, _T("18"));
	pDC5->TextOut(220, 175, _T("19"));
	pDC5->TextOut(260, 135, _T("20"));
	pDC5->TextOut(260, 135, _T("21"));
	pDC5->TextOut(220, 135, _T("22"));
	pDC5->TextOut(180, 135, _T("23"));
	pDC5->TextOut(140, 135, _T("24"));
	pDC5->TextOut(100, 135, _T("25"));
	pDC5->TextOut(60, 135, _T("26"));
	pDC5->TextOut(20, 135, _T("27"));
	pDC5->TextOut(20, 95, _T("28"));
	pDC5->TextOut(60, 95, _T("29"));
	pDC5->TextOut(100, 95, _T("30"));
	pDC5->TextOut(140, 95, _T("31"));
	pDC5->TextOut(180, 95, _T("32"));
	pDC5->TextOut(220, 95, _T("33"));
	pDC5->TextOut(260, 95, _T("34"));
	pDC5->TextOut(260, 55, _T("35"));
	pDC5->TextOut(220, 55, _T("36"));
	pDC5->TextOut(180, 55, _T("37"));
	pDC5->TextOut(140, 55, _T("38"));
	pDC5->TextOut(100, 55, _T("39"));
	pDC5->TextOut(60, 55, _T("40"));
	pDC5->TextOut(20, 55, _T("41"));
	pDC5->TextOut(20, 15, _T("42"));
	pDC5->TextOut(60, 15, _T("43"));
	pDC5->TextOut(100, 15, _T("44"));
	pDC5->TextOut(140, 15, _T("45"));
	pDC5->TextOut(180, 15, _T("46"));
	pDC5->TextOut(220, 15, _T("47"));
	pDC5->TextOut(260, 15, _T("48"));

	//ular selisih 10
	pDC2->Ellipse(90, 150, 110, 125);
	pDC2->MoveTo(100, 150);
	pDC2->LineTo(100, 190);
	pDC2->MoveTo(100, 190);
	pDC2->LineTo(60, 190);
	pDC2->MoveTo(60, 190);
	pDC2->LineTo(60, 230);

	pDC2->Ellipse(205, 30, 235, 10);
	pDC2->MoveTo(220, 30);
	pDC2->LineTo(220, 70);
	pDC2->MoveTo(220, 70);
	pDC2->LineTo(180, 70);

	pDC2->Ellipse(245, 190, 275, 170);
	pDC2->MoveTo(260, 190);
	pDC2->LineTo(260, 270);
	pDC2->MoveTo(260, 270);
	pDC2->LineTo(220, 270);

	//Tangga selisih 10 dan 20
	CDC* pDC3 = m_pic.GetDC();
	CDC dcMem3;
	CPen pen3(PS_SOLID, 4, RGB(0, 255, 150)); //warna background
	CPen* pOldPen3 = pDC3->SelectObject(&pen3);

	pDC3->MoveTo(170, 250);
	pDC3->LineTo(130, 150);
	pDC3->MoveTo(190, 250);
	pDC3->LineTo(150, 150);

	pDC3->MoveTo(140, 170);
	pDC3->LineTo(155, 170);
	pDC3->MoveTo(149, 190);
	pDC3->LineTo(167, 190);
	pDC3->MoveTo(158, 210);
	pDC3->LineTo(175, 210);
	pDC3->MoveTo(162, 230);
	pDC3->LineTo(183, 230);
	//Tangga selisih 10 dan 20

	pDC3->MoveTo(210, 150);
	pDC3->LineTo(50, 70);
	pDC3->MoveTo(210, 130);
	pDC3->LineTo(70, 60);

	pDC3->MoveTo(82, 82);
	pDC3->LineTo(107, 82);
	pDC3->MoveTo(114, 102);
	pDC3->LineTo(148, 102);
	pDC3->MoveTo(153, 122);
	pDC3->LineTo(189, 122);

}

void CprojectDlg::OnEnChangeEdit3()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CprojectDlg::OnBnClickedButton6()
{
	// TODO: Add your control notification handler code here
	m_tampil.EnableWindow(FALSE);
	//enable tombol acak
	m_acak.EnableWindow(TRUE);
	m_acak2.EnableWindow(TRUE);
	m_gerak.EnableWindow(TRUE);
	m_gerak2.EnableWindow(TRUE);
	CDC* pDC = m_pic.GetDC();
	CDC dcMem;
	CPen pen(PS_SOLID, 1, RGB(255, 255, 255)); //warna background
	CPen* pOldPen = pDC->SelectObject(&pen);
	pDC->Rectangle(4, 4, 280, 280);

	CDC* pDC1 = m_pic.GetDC();
	CDC dcMem1;
	CPen pen1(PS_SOLID, 4, RGB(255, 0, 255)); //warna background
	CPen* pOldPen1 = pDC1->SelectObject(&pen1);

	//garis vertikal selisih 40
	pDC1->MoveTo(0, 0);
	pDC1->LineTo(0, 280);
	pDC1->MoveTo(40, 0);
	pDC1->LineTo(40, 280);
	pDC1->MoveTo(80, 0);
	pDC1->LineTo(80, 280);
	pDC1->MoveTo(120, 0);
	pDC1->LineTo(120, 280);
	pDC1->MoveTo(160, 0);
	pDC1->LineTo(160, 280);
	pDC1->MoveTo(200, 0);
	pDC1->LineTo(200, 280);
	pDC1->MoveTo(240, 0);
	pDC1->LineTo(240, 280);
	pDC1->MoveTo(280, 0);
	pDC1->LineTo(280, 280);


	//garis horizontal selisih 40
	pDC1->MoveTo(0, 0);
	pDC1->LineTo(280, 0);
	pDC1->MoveTo(0, 40);
	pDC1->LineTo(280, 40);
	pDC1->MoveTo(0, 80);
	pDC1->LineTo(280, 80);
	pDC1->MoveTo(0, 120);
	pDC1->LineTo(280, 120);
	pDC1->MoveTo(0, 160);
	pDC1->LineTo(280, 160);
	pDC1->MoveTo(0, 200);
	pDC1->LineTo(280, 200);
	pDC1->MoveTo(0, 240);
	pDC1->LineTo(280, 240);
	pDC1->MoveTo(0, 280);
	pDC1->LineTo(280, 280);

	CDC* pDC2 = m_pic.GetDC();
	CDC dcMem2;
	CPen pen2(PS_SOLID, 4, RGB(255, 150, 0)); //warna background
	CPen* pOldPen2 = pDC2->SelectObject(&pen2);


	//membentuk angka 
	CDC* pDC5 = m_pic.GetDC();
	CDC dcMem5;
	CPen pen5(PS_SOLID, 1, RGB(0, 0, 0)); //warna landmark hitam
	CPen* pOldPen5 = pDC5->SelectObject(&pen5);
	pDC5->TextOut(20, 255, _T("0"));
	pDC5->TextOut(60, 255, _T("1"));
	pDC5->TextOut(100, 255, _T("2"));
	pDC5->TextOut(140, 255, _T("3"));
	pDC5->TextOut(180, 255, _T("4"));
	pDC5->TextOut(220, 255, _T("5"));
	pDC5->TextOut(260, 255, _T("6"));
	pDC5->TextOut(260, 215, _T("7"));
	pDC5->TextOut(220, 215, _T("8"));
	pDC5->TextOut(180, 215, _T("9"));
	pDC5->TextOut(140, 215, _T("10"));
	pDC5->TextOut(100, 215, _T("11"));
	pDC5->TextOut(60, 215, _T("12"));
	pDC5->TextOut(20, 215, _T("13"));
	pDC5->TextOut(20, 175, _T("14"));
	pDC5->TextOut(60, 175, _T("15"));
	pDC5->TextOut(100, 175, _T("16"));
	pDC5->TextOut(140, 175, _T("17"));
	pDC5->TextOut(180, 175, _T("18"));
	pDC5->TextOut(220, 175, _T("19"));
	pDC5->TextOut(260, 135, _T("20"));
	pDC5->TextOut(260, 135, _T("21"));
	pDC5->TextOut(220, 135, _T("22"));
	pDC5->TextOut(180, 135, _T("23"));
	pDC5->TextOut(140, 135, _T("24"));
	pDC5->TextOut(100, 135, _T("25"));
	pDC5->TextOut(60, 135, _T("26"));
	pDC5->TextOut(20, 135, _T("27"));
	pDC5->TextOut(20, 95, _T("28"));
	pDC5->TextOut(60, 95, _T("29"));
	pDC5->TextOut(100, 95, _T("30"));
	pDC5->TextOut(140, 95, _T("31"));
	pDC5->TextOut(180, 95, _T("32"));
	pDC5->TextOut(220, 95, _T("33"));
	pDC5->TextOut(260, 95, _T("34"));
	pDC5->TextOut(260, 55, _T("35"));
	pDC5->TextOut(220, 55, _T("36"));
	pDC5->TextOut(180, 55, _T("37"));
	pDC5->TextOut(140, 55, _T("38"));
	pDC5->TextOut(100, 55, _T("39"));
	pDC5->TextOut(60, 55, _T("40"));
	pDC5->TextOut(20, 55, _T("41"));
	pDC5->TextOut(20, 15, _T("42"));
	pDC5->TextOut(60, 15, _T("43"));
	pDC5->TextOut(100, 15, _T("44"));
	pDC5->TextOut(140, 15, _T("45"));
	pDC5->TextOut(180, 15, _T("46"));
	pDC5->TextOut(220, 15, _T("47"));
	pDC5->TextOut(260, 15, _T("48"));

	//ular selisih 10
	pDC2->Ellipse(90, 150, 110, 125);
	pDC2->MoveTo(100, 150);
	pDC2->LineTo(100, 190);
	pDC2->MoveTo(100, 190);
	pDC2->LineTo(60, 190);
	pDC2->MoveTo(60, 190);
	pDC2->LineTo(60, 230);

	pDC2->Ellipse(205, 30, 235, 10);
	pDC2->MoveTo(220, 30);
	pDC2->LineTo(220, 70);
	pDC2->MoveTo(220, 70);
	pDC2->LineTo(180, 70);

	pDC2->Ellipse(245, 190, 275, 170);
	pDC2->MoveTo(260, 190);
	pDC2->LineTo(260, 270);
	pDC2->MoveTo(260, 270);
	pDC2->LineTo(220, 270);

	//Tangga selisih 10 dan 20
	CDC* pDC3 = m_pic.GetDC();
	CDC dcMem3;
	CPen pen3(PS_SOLID, 4, RGB(0, 255, 150)); //warna background
	CPen* pOldPen3 = pDC3->SelectObject(&pen3);

	pDC3->MoveTo(170, 250);
	pDC3->LineTo(130, 150);
	pDC3->MoveTo(190, 250);
	pDC3->LineTo(150, 150);

	pDC3->MoveTo(140, 170);
	pDC3->LineTo(155, 170);
	pDC3->MoveTo(149, 190);
	pDC3->LineTo(167, 190);
	pDC3->MoveTo(158, 210);
	pDC3->LineTo(175, 210);
	pDC3->MoveTo(162, 230);
	pDC3->LineTo(183, 230);
	//Tangga selisih 10 dan 20

	pDC3->MoveTo(210, 150);
	pDC3->LineTo(50, 70);
	pDC3->MoveTo(210, 130);
	pDC3->LineTo(70, 60);

	pDC3->MoveTo(82, 82);
	pDC3->LineTo(107, 82);
	pDC3->MoveTo(114, 102);
	pDC3->LineTo(148, 102);
	pDC3->MoveTo(153, 122);
	pDC3->LineTo(189, 122);

	// membentuk pion
	x1 = 0;
	x2 = 40;
	y1 = 240;
	y2 = 280;
	CPen penpiont(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
	CPen* pOldPenpiont = pDCLingkaran->SelectObject(&penpiont);
	pDCLingkaran->Ellipse(x1, y1, x2, y2);

	//membentuk pion2
	x3 = 0;
	y3 = 240;
	x4 = 40;
	y4 = 280;
	CPen penpiont2(PS_SOLID, 5, RGB(0, 0, 255)); //warna background
	CPen* pOldPenpiont2 = pDCLingkaran2->SelectObject(&penpiont2);
	pDCLingkaran2->Ellipse(x3, y3, x4, y4);
	
}
void CprojectDlg::reset3() {
	// TODO: Add your control notification handler code here
	CDC* pDC = m_pic.GetDC();
	CDC dcMem;
	CPen pen(PS_SOLID, 1, RGB(255, 255, 255)); //warna background
	CPen* pOldPen = pDC->SelectObject(&pen);
	pDC->Rectangle(4, 4, 280, 280);

	CDC* pDC1 = m_pic.GetDC();
	CDC dcMem1;
	CPen pen1(PS_SOLID, 4, RGB(255, 0, 255)); //warna background
	CPen* pOldPen1 = pDC1->SelectObject(&pen1);

	// membentuk pion
	CPen penpiont(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
	CPen* pOldPenpiont = pDCLingkaran->SelectObject(&penpiont);
	pDCLingkaran->Ellipse(x1, y1, x2, y2);

	//garis vertikal selisih 40
	pDC1->MoveTo(0, 0);
	pDC1->LineTo(0, 280);
	pDC1->MoveTo(40, 0);
	pDC1->LineTo(40, 280);
	pDC1->MoveTo(80, 0);
	pDC1->LineTo(80, 280);
	pDC1->MoveTo(120, 0);
	pDC1->LineTo(120, 280);
	pDC1->MoveTo(160, 0);
	pDC1->LineTo(160, 280);
	pDC1->MoveTo(200, 0);
	pDC1->LineTo(200, 280);
	pDC1->MoveTo(240, 0);
	pDC1->LineTo(240, 280);
	pDC1->MoveTo(280, 0);
	pDC1->LineTo(280, 280);


	//garis horizontal selisih 40
	pDC1->MoveTo(0, 0);
	pDC1->LineTo(280, 0);
	pDC1->MoveTo(0, 40);
	pDC1->LineTo(280, 40);
	pDC1->MoveTo(0, 80);
	pDC1->LineTo(280, 80);
	pDC1->MoveTo(0, 120);
	pDC1->LineTo(280, 120);
	pDC1->MoveTo(0, 160);
	pDC1->LineTo(280, 160);
	pDC1->MoveTo(0, 200);
	pDC1->LineTo(280, 200);
	pDC1->MoveTo(0, 240);
	pDC1->LineTo(280, 240);
	pDC1->MoveTo(0, 280);
	pDC1->LineTo(280, 280);

	CDC* pDC2 = m_pic.GetDC();
	CDC dcMem2;
	CPen pen2(PS_SOLID, 4, RGB(255, 150, 0)); //warna background
	CPen* pOldPen2 = pDC2->SelectObject(&pen2);

	//membentuk angka 
	CDC* pDC5 = m_pic.GetDC();
	CDC dcMem5;
	CPen pen5(PS_SOLID, 1, RGB(0, 0, 0)); //warna landmark hitam
	CPen* pOldPen5 = pDC5->SelectObject(&pen5);
	pDC5->TextOut(20, 255, _T("0"));
	pDC5->TextOut(60, 255, _T("1"));
	pDC5->TextOut(100, 255, _T("2"));
	pDC5->TextOut(140, 255, _T("3"));
	pDC5->TextOut(180, 255, _T("4"));
	pDC5->TextOut(220, 255, _T("5"));
	pDC5->TextOut(260, 255, _T("6"));
	pDC5->TextOut(260, 215, _T("7"));
	pDC5->TextOut(220, 215, _T("8"));
	pDC5->TextOut(180, 215, _T("9"));
	pDC5->TextOut(140, 215, _T("10"));
	pDC5->TextOut(100, 215, _T("11"));
	pDC5->TextOut(60, 215, _T("12"));
	pDC5->TextOut(20, 215, _T("13"));
	pDC5->TextOut(20, 175, _T("14"));
	pDC5->TextOut(60, 175, _T("15"));
	pDC5->TextOut(100, 175, _T("16"));
	pDC5->TextOut(140, 175, _T("17"));
	pDC5->TextOut(180, 175, _T("18"));
	pDC5->TextOut(220, 175, _T("19"));
	pDC5->TextOut(260, 135, _T("20"));
	pDC5->TextOut(260, 135, _T("21"));
	pDC5->TextOut(220, 135, _T("22"));
	pDC5->TextOut(180, 135, _T("23"));
	pDC5->TextOut(140, 135, _T("24"));
	pDC5->TextOut(100, 135, _T("25"));
	pDC5->TextOut(60, 135, _T("26"));
	pDC5->TextOut(20, 135, _T("27"));
	pDC5->TextOut(20, 95, _T("28"));
	pDC5->TextOut(60, 95, _T("29"));
	pDC5->TextOut(100, 95, _T("30"));
	pDC5->TextOut(140, 95, _T("31"));
	pDC5->TextOut(180, 95, _T("32"));
	pDC5->TextOut(220, 95, _T("33"));
	pDC5->TextOut(260, 95, _T("34"));
	pDC5->TextOut(260, 55, _T("35"));
	pDC5->TextOut(220, 55, _T("36"));
	pDC5->TextOut(180, 55, _T("37"));
	pDC5->TextOut(140, 55, _T("38"));
	pDC5->TextOut(100, 55, _T("39"));
	pDC5->TextOut(60, 55, _T("40"));
	pDC5->TextOut(20, 55, _T("41"));
	pDC5->TextOut(20, 15, _T("42"));
	pDC5->TextOut(60, 15, _T("43"));
	pDC5->TextOut(100, 15, _T("44"));
	pDC5->TextOut(140, 15, _T("45"));
	pDC5->TextOut(180, 15, _T("46"));
	pDC5->TextOut(220, 15, _T("47"));
	pDC5->TextOut(260, 15, _T("48"));

	//ular selisih 10
	pDC2->Ellipse(90, 150, 110, 125);
	pDC2->MoveTo(100, 150);
	pDC2->LineTo(100, 190);
	pDC2->MoveTo(100, 190);
	pDC2->LineTo(60, 190);
	pDC2->MoveTo(60, 190);
	pDC2->LineTo(60, 230);

	pDC2->Ellipse(205, 30, 235, 10);
	pDC2->MoveTo(220, 30);
	pDC2->LineTo(220, 70);
	pDC2->MoveTo(220, 70);
	pDC2->LineTo(180, 70);

	pDC2->Ellipse(245, 190, 275, 170);
	pDC2->MoveTo(260, 190);
	pDC2->LineTo(260, 270);
	pDC2->MoveTo(260, 270);
	pDC2->LineTo(220, 270);

	//Tangga selisih 10 dan 20
	CDC* pDC3 = m_pic.GetDC();
	CDC dcMem3;
	CPen pen3(PS_SOLID, 4, RGB(0, 255, 150)); //warna background
	CPen* pOldPen3 = pDC3->SelectObject(&pen3);

	pDC3->MoveTo(170, 250);
	pDC3->LineTo(130, 150);
	pDC3->MoveTo(190, 250);
	pDC3->LineTo(150, 150);

	pDC3->MoveTo(140, 170);
	pDC3->LineTo(155, 170);
	pDC3->MoveTo(149, 190);
	pDC3->LineTo(167, 190);
	pDC3->MoveTo(158, 210);
	pDC3->LineTo(175, 210);
	pDC3->MoveTo(162, 230);
	pDC3->LineTo(183, 230);
	//Tangga selisih 10 dan 20

	pDC3->MoveTo(210, 150);
	pDC3->LineTo(50, 70);
	pDC3->MoveTo(210, 130);
	pDC3->LineTo(70, 60);

	pDC3->MoveTo(82, 82);
	pDC3->LineTo(107, 82);
	pDC3->MoveTo(114, 102);
	pDC3->LineTo(148, 102);
	pDC3->MoveTo(153, 122);
	pDC3->LineTo(189, 122);

}

void CprojectDlg::OnBnClickedButton5()
{
	// TODO: Add your control notification handler code here

	// TODO: Add your control notification handler code here
	m_hapus.EnableWindow(TRUE);
	reset3();
	int data, move = 0;
	data = GetDlgItemInt(IDC_EDIT4);
	move = move + data;
	CDC* pDC5 = m_pic.GetDC();
	CDC dcMem5;
	CPen pen5(PS_SOLID, 1, RGB(0, 0, 0)); //warna landmark hitam
	CPen* pOldPen5 = pDC5->SelectObject(&pen5);
	if (move == 0) {
		x3 = 0;
		y3 = 240;
		x4 = 40;
		y4 = 280;
		CPen penpiont2(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont2 = pDCLingkaran2->SelectObject(&penpiont2);
		pDCLingkaran2->Ellipse(x3, y3, x4, y4);
		pDC5->TextOut(20, 255, _T("0"));
	}
	else if (move == 1) {
		x3 = 40;
		y3 = 240;
		x4 = 80;
		y4 = 280;
		CPen penpiont2(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont2 = pDCLingkaran2->SelectObject(&penpiont2);
		pDCLingkaran2->Ellipse(x3, y3, x4, y4);
		pDC5->TextOut(60, 255, _T("1"));
	}
	else if (move == 2) {
		x3 = 80;
		y3 = 240;
		x4 = 120;
		y4 = 280;
		CPen penpiont2(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont2 = pDCLingkaran2->SelectObject(&penpiont2);
		pDCLingkaran2->Ellipse(x3, y3, x4, y4);
		pDC5->TextOut(100, 255, _T("2"));
	}
	else if (move == 3) {
		x3 = 120;
		y3 = 240;
		x4 = 160;
		y4 = 280;
		CPen penpiont2(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont2 = pDCLingkaran->SelectObject(&penpiont2);
		pDCLingkaran2->Ellipse(x3, y3, x4, y4);
		pDC5->TextOut(140, 255, _T("3"));
	}
	else if (move == 4) {
		x3 = 120;
		y3 = 120;
		x4 = 160;
		y4 = 160;
		CPen penpiont2(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont2 = pDCLingkaran->SelectObject(&penpiont2);
		pDCLingkaran2->Ellipse(x3, y3, x4, y4);
		pDC5->TextOut(140, 135, _T("24"));
	}
	else if (move == 5) {
		x3 = 200;
		y3 = 240;
		x4 = 240;
		y4 = 280;
		CPen penpiont2(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont2 = pDCLingkaran->SelectObject(&penpiont2);
		pDCLingkaran2->Ellipse(x3, y3, x4, y4);
		pDC5->TextOut(220, 255, _T("5"));
	}
	else if (move == 6) {
		x3 = 240;
		y3 = 240;
		x4 = 280;
		y4 = 280;
		CPen penpiont2(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont2 = pDCLingkaran->SelectObject(&penpiont2);
		pDCLingkaran2->Ellipse(x3, y3, x4, y4);
		pDC5->TextOut(260, 255, _T("6"));
	}
	else if (move == 7) {
		x3 = 240;
		y3 = 200;
		x4 = 280;
		y4 = 240;
		CPen penpiont2(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont2 = pDCLingkaran->SelectObject(&penpiont2);
		pDCLingkaran2->Ellipse(x3, y3, x4, y4);
		pDC5->TextOut(260, 215, _T("7"));
	}
	else if (move == 8) {
		x3 = 200;
		y3 = 200;
		x4 = 240;
		y4 = 240;
		CPen penpiont2(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont2 = pDCLingkaran->SelectObject(&penpiont2);
		pDCLingkaran2->Ellipse(x3, y3, x4, y4);
		pDC5->TextOut(220, 215, _T("8"));
	}
	else if (move == 9) {
		x3 = 160;
		y3 = 200;
		x4 = 200;
		y4 = 240;
		CPen penpiont2(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont2 = pDCLingkaran->SelectObject(&penpiont2);
		pDCLingkaran2->Ellipse(x3, y3, x4, y4);
		pDC5->TextOut(180, 215, _T("9"));
	}
	else if (move == 10) {
		x3 = 120;
		y3 = 200;
		x4 = 160;
		y4 = 240;
		CPen penpiont2(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont2 = pDCLingkaran->SelectObject(&penpiont2);
		pDCLingkaran2->Ellipse(x3, y3, x4, y4);
		pDC5->TextOut(140, 215, _T("10"));
	}
	else if (move == 11) {
		x3 = 80;
		y3 = 200;
		x4 = 120;
		y4 = 240;
		CPen penpiont2(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont2 = pDCLingkaran->SelectObject(&penpiont2);
		pDCLingkaran2->Ellipse(x3, y3, x4, y4);
		pDC5->TextOut(100, 215, _T("11"));
	}
	else if (move == 12) {
		x3 = 40;
		y3 = 200;
		x4 = 80;
		y4 = 240;
		CPen penpiont2(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont2 = pDCLingkaran->SelectObject(&penpiont2);
		pDCLingkaran2->Ellipse(x3, y3, x4, y4);
		pDC5->TextOut(60, 215, _T("12"));

	}
	else if (move == 13) {
		x3 = 0;
		y3 = 200;
		x4 = 40;
		y4 = 240;
		CPen penpiont2(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont2 = pDCLingkaran->SelectObject(&penpiont2);
		pDCLingkaran2->Ellipse(x3, y3, x4, y4);
		pDC5->TextOut(20, 215, _T("13"));
	}
	else if (move == 14) {
		x3 = 0;
		y3 = 160;
		x4 = 40;
		y4 = 200;
		CPen penpiont2(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont2 = pDCLingkaran->SelectObject(&penpiont2);
		pDCLingkaran2->Ellipse(x3, y3, x4, y4);
		pDC5->TextOut(20, 175, _T("14"));
	}
	else if (move == 15) {
		x3 = 40;
		y3 = 160;
		x4 = 80;
		y4 = 200;
		CPen penpiont2(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont2 = pDCLingkaran->SelectObject(&penpiont2);
		pDCLingkaran2->Ellipse(x3, y3, x4, y4);
		pDC5->TextOut(60, 175, _T("15"));
	}
	else if (move == 16) {
		x3 = 80;
		y3 = 160;
		x4 = 120;
		y4 = 200;
		CPen penpiont2(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont2 = pDCLingkaran->SelectObject(&penpiont2);
		pDCLingkaran2->Ellipse(x3, y3, x4, y4);
		pDC5->TextOut(100, 175, _T("16"));
	}
	else if (move == 17) {
		x3 = 120;
		y3 = 160;
		x4 = 160;
		y4 = 200;
		CPen penpiont2(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont2 = pDCLingkaran->SelectObject(&penpiont2);
		pDCLingkaran2->Ellipse(x3, y3, x4, y4);
		pDC5->TextOut(140, 175, _T("17"));
	}
	else if (move == 18) {
		x3 = 160;
		y3 = 160;
		x4 = 200;
		y4 = 200;
		CPen penpiont2(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont2 = pDCLingkaran->SelectObject(&penpiont2);
		pDCLingkaran2->Ellipse(x3, y3, x4, y4);
		pDC5->TextOut(180, 175, _T("18"));
	}
	else if (move == 19) {
		x3 = 200;
		y3 = 160;
		x4 = 240;
		y4 = 200;
		CPen penpiont2(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont2 = pDCLingkaran->SelectObject(&penpiont2);
		pDCLingkaran2->Ellipse(x3, y3, x4, y4);
		pDC5->TextOut(220, 175, _T("19"));
	}
	else if (move == 20) {
	x3 = 200;
	y3 = 240;
	x4 = 240;
	y4 = 280;
	CPen penpiont2(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
	CPen* pOldPenpiont2 = pDCLingkaran->SelectObject(&penpiont2);
	pDCLingkaran2->Ellipse(x3, y3, x4, y4);
	pDC5->TextOut(220, 255, _T("5"));
	}
	else if (move == 21) {
		x3 = 240;
		y3 = 120;
		x4 = 280;
		y4 = 160;
		CPen penpiont2(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont2 = pDCLingkaran->SelectObject(&penpiont2);
		pDCLingkaran2->Ellipse(x3, y3, x4, y4);
		pDC5->TextOut(260, 135, _T("21"));
	}
	else if (move == 22) {
	x3 = 40;
	y3 = 40;
	x4 = 80;
	y4 = 80;
	CPen penpiont2(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
	CPen* pOldPenpiont2 = pDCLingkaran->SelectObject(&penpiont2);
	pDCLingkaran2->Ellipse(x3, y3, x4, y4);
	pDC5->TextOut(60, 55, _T("40"));
	}
	else if (move == 23) {
		x3 = 160;
		y3 = 120;
		x4 = 200;
		y4 = 160;
		CPen penpiont2(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont2 = pDCLingkaran->SelectObject(&penpiont2);
		pDCLingkaran2->Ellipse(x3, y3, x4, y4);
		pDC5->TextOut(180, 135, _T("23"));
	}
	else if (move == 24) {
		x3 = 120;
		y3 = 120;
		x4 = 160;
		y4 = 160;
		CPen penpiont2(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont2 = pDCLingkaran->SelectObject(&penpiont2);
		pDCLingkaran2->Ellipse(x3, y3, x4, y4);
		pDC5->TextOut(140, 135, _T("24"));
	}
	else if (move == 25) {
	x3 = 40;
	y3 = 200;
	x4 = 80;
	y4 = 240;
	CPen penpiont2(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
	CPen* pOldPenpiont2 = pDCLingkaran->SelectObject(&penpiont2);
	pDCLingkaran2->Ellipse(x3, y3, x4, y4);
	pDC5->TextOut(60, 215, _T("12"));
	}
	else if (move == 26) {
		x3 = 40;
		y3 = 120;
		x4 = 80;
		y4 = 160;
		CPen penpiont2(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont2 = pDCLingkaran->SelectObject(&penpiont2);
		pDCLingkaran2->Ellipse(x3, y3, x4, y4);
		pDC5->TextOut(60, 135, _T("26"));
	}
	else if (move == 27) {
		x3 = 0;
		y3 = 120;
		x4 = 40;
		y4 = 160;
		CPen penpiont2(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont2 = pDCLingkaran->SelectObject(&penpiont2);
		pDCLingkaran2->Ellipse(x3, y3, x4, y4);
		pDC5->TextOut(20, 135, _T("27"));
	}
	else if (move == 28) {
		x3 = 0;
		y3 = 80;
		x4 = 40;
		y4 = 120;
		CPen penpiont2(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont2 = pDCLingkaran->SelectObject(&penpiont2);
		pDCLingkaran2->Ellipse(x3, y3, x4, y4);
		pDC5->TextOut(20, 95, _T("28"));
	}
	else if (move == 29) {
		x3 = 40;
		y3 = 80;
		x4 = 80;
		y4 = 120;
		CPen penpiont2(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont2 = pDCLingkaran->SelectObject(&penpiont2);
		pDCLingkaran2->Ellipse(x3, y3, x4, y4);
		pDC5->TextOut(60, 95, _T("29"));
	}
	else if (move == 30) {
		x3 = 80;
		y3 = 80;
		x4 = 120;
		y4 = 120;
		CPen penpiont2(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont2 = pDCLingkaran->SelectObject(&penpiont2);
		pDCLingkaran2->Ellipse(x3, y3, x4, y4);
		pDC5->TextOut(100, 95, _T("30"));
	}
	else if (move == 31) {
		x3 = 120;
		y3 = 80;
		x4 = 160;
		y4 = 120;
		CPen penpiont2(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont2 = pDCLingkaran->SelectObject(&penpiont2);
		pDCLingkaran2->Ellipse(x3, y3, x4, y4);
		pDC5->TextOut(140, 95, _T("31"));
	}
	else if (move == 32) {
		x3 = 160;
		y3 = 80;
		x4 = 200;
		y4 = 120;
		CPen penpiont2(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont2 = pDCLingkaran->SelectObject(&penpiont2);
		pDCLingkaran2->Ellipse(x3, y3, x4, y4);
		pDC5->TextOut(180, 95, _T("32"));
	}
	else if (move == 33) {
		x3 = 200;
		y3 = 80;
		x4 = 240;
		y4 = 120;
		CPen penpiont2(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont2 = pDCLingkaran->SelectObject(&penpiont2);
		pDCLingkaran2->Ellipse(x3, y3, x4, y4);
		pDC5->TextOut(220, 95, _T("33"));
	}
	else if (move == 34) {
		x3 = 240;
		y3 = 80;
		x4 = 280;
		y4 = 120;
		CPen penpiont2(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont2 = pDCLingkaran->SelectObject(&penpiont2);
		pDCLingkaran2->Ellipse(x3, y3, x4, y4);
		pDC5->TextOut(260, 95, _T("34"));
	}
	else if (move == 35) {
		x3 = 240;
		y3 = 40;
		x4 = 280;
		y4 = 80;
		CPen penpiont2(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont2 = pDCLingkaran->SelectObject(&penpiont2);
		pDCLingkaran2->Ellipse(x3, y3, x4, y4);
		pDC5->TextOut(260, 55, _T("35"));
	}
	else if (move == 36) {
		x3 = 200;
		y3 = 40;
		x4 = 240;
		y4 = 80;
		CPen penpiont2(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont2 = pDCLingkaran->SelectObject(&penpiont2);
		pDCLingkaran2->Ellipse(x3, y3, x4, y4);
		pDC5->TextOut(220, 55, _T("36"));
	}
	else if (move == 37) {
		x3 = 160;
		y3 = 40;
		x4 = 200;
		y4 = 80;
		CPen penpiont2(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont2 = pDCLingkaran->SelectObject(&penpiont2);
		pDCLingkaran2->Ellipse(x3, y3, x4, y4);
		pDC5->TextOut(180, 55, _T("37"));
	}
	else if (move == 38) {
		x3 = 120;
		y3 = 40;
		x4 = 160;
		y4 = 80;
		CPen penpiont2(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont2 = pDCLingkaran->SelectObject(&penpiont2);
		pDCLingkaran2->Ellipse(x3, y3, x4, y4);
		pDC5->TextOut(140, 55, _T("38"));
	}
	else if (move == 39) {
		x3 = 80;
		y3 = 40;
		x4 = 120;
		y4 = 80;
		CPen penpiont2(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont2 = pDCLingkaran->SelectObject(&penpiont2);
		pDCLingkaran2->Ellipse(x3, y3, x4, y4);
		pDC5->TextOut(100, 55, _T("39"));
	}
	else if (move == 40) {
		x3 = 40;
		y3 = 40;
		x4 = 80;
		y4 = 80;
		CPen penpiont2(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont2 = pDCLingkaran->SelectObject(&penpiont2);
		pDCLingkaran2->Ellipse(x3, y3, x4, y4);
		pDC5->TextOut(60, 55, _T("40"));
	}
	else if (move == 41) {
		x3 = 0;
		y3 = 40;
		x4 = 40;
		y4 = 80;
		CPen penpiont2(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont2 = pDCLingkaran->SelectObject(&penpiont2);
		pDCLingkaran2->Ellipse(x3, y3, x4, y4);
		pDC5->TextOut(20, 55, _T("41"));
	}
	else if (move == 42) {
		x3 = 0;
		y3 = 0;
		x4 = 40;
		CPen penpiont2(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont2 = pDCLingkaran->SelectObject(&penpiont2);
		pDCLingkaran2->Ellipse(x3, y3, x4, y4);
		pDC5->TextOut(20, 15, _T("42"));
	}
	else if (move == 43) {
		x3 = 40;
		y3 = 0;
		x4 = 80;
		y4 = 40;
		CPen penpiont2(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont2 = pDCLingkaran->SelectObject(&penpiont2);
		pDCLingkaran2->Ellipse(x3, y3, x4, y4);
		pDC5->TextOut(60, 15, _T("43"));
	}
	else if (move == 44) {
		x3 = 80;
		y3 = 0;
		x4 = 120;
		y4 = 40;
		CPen penpiont2(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont2 = pDCLingkaran->SelectObject(&penpiont2);
		pDCLingkaran2->Ellipse(x3, y3, x4, y4);
		pDC5->TextOut(100, 15, _T("44"));
	}
	else if (move == 45) {
		x3 = 120;
		y3 = 0;
		x4 = 160;
		y4 = 40;
		CPen penpiont2(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont2 = pDCLingkaran->SelectObject(&penpiont2);
		pDCLingkaran2->Ellipse(x3, y3, x4, y4);
		pDC5->TextOut(140, 15, _T("45"));
	}
	else if (move == 46) {
		x3 = 160;
		y3 = 0;
		x4 = 240;
		y4 = 40;
		CPen penpiont2(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont2 = pDCLingkaran->SelectObject(&penpiont2);
		pDCLingkaran2->Ellipse(x3, y3, x4, y4);
		pDC5->TextOut(180, 15, _T("46"));
	}
	else if (move == 47) {
	x3 = 160;
	y3 = 40;
	x4 = 200;
	y4 = 80;
	CPen penpiont2(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
	CPen* pOldPenpiont2 = pDCLingkaran->SelectObject(&penpiont2);
	pDCLingkaran2->Ellipse(x3, y3, x4, y4);
	pDC5->TextOut(180, 55, _T("37"));
	}
	else if (move == 48) {
		x3 = 240;
		y3 = 0;
		x4 = 280;
		y4 = 40;
		CPen penpiont2(PS_SOLID, 5, RGB(255, 0, 0)); //warna background
		CPen* pOldPenpiont2 = pDCLingkaran->SelectObject(&penpiont2);
		pDCLingkaran2->Ellipse(x3, y3, x4, y4);
		pDC5->TextOut(260, 15, _T("48"));
		UpdateData(TRUE);
		m_gerak2.EnableWindow(FALSE);
		m_hapus.EnableWindow(TRUE);
	}
}