
// MFCApplication1Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
//#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CMFCApplication1Dlg 대화 상자



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	// 값 초기화
	start = {0, 0 };
	dest = {600, 400 };
	nFrame = 10;
	nColor = 80;
	dDx = dDy = 0.0;
	nRadius = 0;
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, start.x);
	DDX_Text(pDX, IDC_EDIT2, start.y);
	DDX_Text(pDX, IDC_EDIT3, dest.x);
	DDX_Text(pDX, IDC_EDIT4, dest.y);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication1Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication1Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication1Dlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 메시지 처리기

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// (Draw BG 버튼) 흰 배경 그리기(화면 초기화)
void CMFCApplication1Dlg::OnBnClickedButton1()
{
	ClearDisplay();
	CalDelta();
}

// (Draw 버튼) x1 y1 좌표에 원을 하나 그림, 반지름은 10~100 사이의 무작위 값
void CMFCApplication1Dlg::OnBnClickedButton2()
{
	ClearDisplay();
	UpdateData(true);

	unsigned char* fm = (unsigned char*)m_image.GetBits();
	int nPitch = m_image.GetPitch();

	// 반지름을 10 - 100 사이의 난수로 결정
	SYSTEMTIME st;
	GetLocalTime(&st);
	srand((unsigned int)st.wMilliseconds);
	nRadius = rand() % 91 + 10;

	DrawCircle(fm, start.x, start.y, nRadius, nColor);

	UpdateDisplay();
}

// (Action 버튼) x1 y1 -> x2 y2로 일정 거리만큼 원 이동하면서 파일로 저장
void CMFCApplication1Dlg::OnBnClickedButton3()
{
	CalDelta();

	for (int i = 0; i < nFrame; i++) {
		MoveCircle();
		Sleep(30);
	}
}

// (Open 버튼) 파일 불러오기
void CMFCApplication1Dlg::OnBnClickedButton4()
{
	CString filter = _T("Image Files (*.jpg; *.jpeg; *.bmp)|*.jpg;*.jpeg;*.bmp|All Files (*.*)|*.*||");
	CFileDialog dlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST | OFN_HIDEREADONLY, filter, this);

	if (dlg.DoModal() == IDOK)
	{
		CString filePath = dlg.GetPathName();

		if (m_image != NULL) {
			m_image.Destroy();
		}

		m_image.Load(filePath);

		// 파일 경로에 있는 xy좌표와 반지름을 가져와서 num[]에 순서대로 저장
		int num[3];
		CString filename = strClip(filePath, 3);
		_stscanf_s(filename, _T("%d %d %d"), &num[0], &num[1], &num[2]);

		// 원의 중점에 X자를 그림
		unsigned char* fm = (unsigned char*)m_image.GetBits();
		int nHeight = m_image.GetHeight();
		int nPitch = -m_image.GetPitch();

		int centerPos = num[0] - (num[1] * nPitch);
		for (int i = -3; i <= 3; i++) {
			if(ValidImgPosInv(centerPos - (nPitch * i) + i))
				fm[centerPos - (nPitch * i) + i] = 255;
			if (ValidImgPosInv(centerPos - (nPitch * i) - i))
				fm[centerPos - (nPitch * i) - i] = 255;
		}

		// xy좌표 문자열을 만들고 출력
		CString pos;
		pos.Format(L"(%d,%d)", num[0], num[1]);

		CClientDC dc(this);
		m_image.Draw(dc, 0, 0);

		dc.SetBkMode(TRANSPARENT);
		dc.TextOutW(num[0]+5, num[1]+5, pos);
		
		Invalidate(false);
	}
}

// 하나의 원을 그리고 다음원을 그릴 수 있도록 dDx, dDy 값만큼 좌표 이동, 그림을 파일로 저장
void CMFCApplication1Dlg::MoveCircle()
{
	int nWidth = m_image.GetWidth();
	int nHeight = m_image.GetHeight();
	int nPitch = m_image.GetPitch();
	unsigned char* fm = (unsigned char*)m_image.GetBits();

	memset(fm, 0xff, sizeof(unsigned char) * nWidth * nHeight);
	//DrawCircle(fm, omw.x, omw.y, nRadius, 0xff);

	omw.x += (int)dDx;
	omw.y += (int)dDy;

	DrawCircle(fm, omw.x, omw.y, nRadius, nColor);

	CString filename;

	// 파일명에 좌표값과 반지름 정보 저장(Images 폴더안에 bmp로 저장)
	myUtil_CheckDir(L"Images");
	filename.Format(L"Images\\%d %d %d.bmp", omw.x, omw.y, nRadius);
	m_image.Save(filename);

	UpdateDisplay();
}

// 중심 x,y로부터 반지름이 nRadius인 원을 그림, 색깔은 nColor
void CMFCApplication1Dlg::DrawCircle(unsigned char* fm, int x, int y, int nRadius, int nColor)
{
	int nPitch = m_image.GetPitch();

	for (int j = y-nRadius; j <= y + nRadius; j++) {
		for (int i = x-nRadius; i <= x + nRadius; i++) {
			if (ValidImgPos(i, j) && IsInCircle(i, j, x, y, nRadius)) {
				fm[j * nPitch + i] = nColor;
			}
		}
	}
}

// 프레임마다 움직일 거리 계산
void CMFCApplication1Dlg::CalDelta()
{
	UpdateData(true);

	omw.x = start.x;
	omw.y = start.y;

	dDx = (dest.x - start.x) / (double)nFrame;
	dDy = (dest.y - start.y) / (double)nFrame;
}

// 사각형에서 반지름 안에 있는 점들을 골라서 원을 그리기 위한 함수
bool CMFCApplication1Dlg::IsInCircle(int x, int y, int nCenterX, int nCenterY, int nRadius)
{
	double dDist = (x - nCenterX) * (x - nCenterX) + (y - nCenterY) * (y - nCenterY);

	if (dDist < nRadius * nRadius) {
		return true;
	}
	else {
		return false;
	}
}

// CImage.Create() 이후 좌표값이 화면 안에 있는지 판별
bool CMFCApplication1Dlg::ValidImgPos(int x, int y)
{
	if (x < 0 || x >= m_image.GetWidth() || y < 0 || y >= m_image.GetHeight())
		return false;
	else
		return true;
}

// CImage.Load() 이후 좌표값이 화면 안에 있는지 판별
bool CMFCApplication1Dlg::ValidImgPosInv(int x)
{
	int nHeight = m_image.GetHeight();
	int nPitch = -m_image.GetPitch();

	if (x < nPitch && x > -nPitch * nHeight + nPitch - 1)
		return true;
	else
		return false;
}

// 화면을 새로 그림
void CMFCApplication1Dlg::UpdateDisplay()
{
	CClientDC dc(this);
	m_image.Draw(dc, 0, 0);
}

// 화면을 지우고 새로 그림
void CMFCApplication1Dlg::ClearDisplay()
{
	int nWidth = 640;
	int nHeight = 480;
	int nBpp = 8;

	if (m_image != NULL) {
		m_image.Destroy();
	}

	m_image.Create(nWidth, -nHeight, nBpp);

	if (nBpp == 8) {
		static RGBQUAD rgb[256];
		for (int i = 0; i < 256; i++) {
			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;
		}
		m_image.SetColorTable(0, 256, rgb);
	}

	unsigned char* fm = (unsigned char*)m_image.GetBits();
	memset(fm, 0xff, sizeof(unsigned char) * nWidth * nHeight);

	UpdateDisplay();
}

// 파일이름의 문자열에서 케이스에 따라 정보를 추출하는 함수
// Source from : https://lwj789.tistory.com/160
// Type
// 0: 파일 경로만 복사
// 1: 파일 이름만 복사
// 2: 파일 확장자 복사
// 3: 확장자를 뺀 파일명 복사
// 4: 2번케이스의 파일 확장자에서 .을 뺌.
CString CMFCApplication1Dlg::strClip(CString str, int nType)
{
	//파일 Full Path를 복사
	TCHAR szTmp[4096];
	StrCpy(szTmp, str);
	CString strTmp;

	CString strResult = _T("");

	switch (nType)
	{
	case 0:
		//파일의 경로만 복사.
		PathRemoveFileSpec(szTmp);
		strResult = szTmp;
		break;
	case 1:
		// 1: 파일 이름만 복사
		strResult = PathFindFileName(szTmp);
		//strResult = szTmp;
		break;
	case 2:
		// 2: 파일 확장자 복사
		strResult = PathFindExtension(szTmp);
		break;
	case 3:
		// 3: 확장자를 뺀 파일명 복사
		strTmp = PathFindFileName(szTmp);
		ZeroMemory(szTmp, 4096);
		StrCpy(szTmp, strTmp);
		PathRemoveExtension(szTmp);
		strResult = szTmp;
		break;
	case 4:
		// 4: 2번케이스의 파일 확장자에서 .을 뺌.
		strResult = PathFindExtension(szTmp);
		strResult = strResult.Right(strResult.GetLength() - 1);
		break;
	}

	return strResult;
}

// 폴더가 없으면 폴더 생성, 있으면 아무것도 안함
// Source from https://blog.naver.com/kimmin2_/222384183007
bool CMFCApplication1Dlg::myUtil_CheckDir(CString sDirName)
{
	CFileFind file;
	CString strFile = L"Images"; // 폴더 경로 
	// 경로 폴더가 있다면 1, 없다면 0을 반환
	bool bResult = file.FindFile(sDirName + strFile);

	if (!bResult)
	{
		// 폴더 생성
		bResult = CreateDirectory(sDirName + "\\", NULL);
		if (!bResult)
		{
			/*Error*/
			return FALSE;
		}
		return TRUE;
	}
	return FALSE;
}