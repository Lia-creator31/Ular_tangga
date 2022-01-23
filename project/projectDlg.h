
// projectDlg.h : header file
//

#pragma once


// CprojectDlg dialog
class CprojectDlg : public CDialogEx
{
// Construction
public:
	CprojectDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROJECT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CStatic m_pic;
	CButton m_tampil;
	afx_msg void OnBnClickedButton1();
	CString m_display;
	afx_msg void OnBnClickedAcak();
	int x1;
	int x2;
	int y1;
	int y2;
	CDC* pDCLingkaran;
	CDC* pDCRectangle;
	void geser(int x);
	void reset();
	void Ular();
	void Tangga();
	CString m_display2;
	int x3;
	int x4;
	int y3;
	int y4;
	CDC* pDCLingkaran2;
	void geser2(int x2);
	int Ular2();
	int Tangga2();
	afx_msg void OnBnClickedAcak2();
	CButton m_acak;
	CButton m_acak2;
	CButton m_gerak;
	CButton m_gerak2;
	void reset2();
	void reset3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnBnClickedButton6();
	CButton m_hapus;
	afx_msg void OnBnClickedButton5();
};
