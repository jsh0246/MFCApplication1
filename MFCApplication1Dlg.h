
// MFCApplication1Dlg.h: 헤더 파일
//

#pragma once


// CMFCApplication1Dlg 대화 상자
class CMFCApplication1Dlg : public CDialogEx
{
// 생성입니다.
public:
	CMFCApplication1Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	void MoveCircle();
	void DrawCircle(unsigned char* fm, int x, int y, int nRadius, int color);
	void CalDelta();
	bool IsInCircle(int x, int y, int nCenterX, int nCenterY, int nRadius);
	bool ValidImgPos(int x, int y);
	bool ValidImgPosInv(int x);
	void UpdateDisplay();
	void ClearDisplay();
	CString strClip(CString str, int nType);
	bool myUtil_CheckDir(CString sDirName);

private :
	CImage m_image;
	CPoint start, dest, omw;
	double dDx, dDy;
	int nRadius;
	int nColor;
	int nFrame;

public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
};
