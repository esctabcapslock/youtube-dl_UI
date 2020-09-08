﻿
// XXMFCDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "XXMFC.h"
#include "XXMFCDlg.h"
#include "afxdialogex.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CXXMFCDlg 대화 상자



CXXMFCDlg::CXXMFCDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_XXMFC_DIALOG, pParent)
	, xx_radio(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CXXMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO1, xx_radio);
}

BEGIN_MESSAGE_MAP(CXXMFCDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CXXMFCDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_RADIO2, &CXXMFCDlg::OnBnClickedRadio2)
	ON_EN_CHANGE(IDC_EDIT1, &CXXMFCDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_RADIO1, &CXXMFCDlg::OnBnClickedRadio1)
END_MESSAGE_MAP()


// CXXMFCDlg 메시지 처리기

BOOL CXXMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CXXMFCDlg::OnPaint()
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
HCURSOR CXXMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CXXMFCDlg::OnBnClickedButton1()
{
	CString str, dir(""), mp4("--merge-output-format mp4 "), mp3("-x --audio-format mp3 --audio-quality 0 "),pa(" && pause"),cmd,cmd2;
	GetDlgItemText(IDC_EDIT1, str);
	cmd = (xx_radio ? mp4 : mp3) + str;
	//cmd2 = cmd + pa;
	int point = cmd.Find(L"&list");
	if (point>5) cmd = cmd.Left(point);
	//MessageBox(cmd);
	//char* ar = LPSTR(LPCTSTR(cmd2));
	//system("dr && pause");
	//int kk = system(ar);
	//system("dir");
	//https://blog.naver.com/tipsware/221307958643
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	ShellExecute(NULL, _T("open"), _T("youtube-dl.exe"), cmd, NULL, SW_SHOW);
}


void CXXMFCDlg::OnBnClickedRadio2()
{
	xx_radio = 1;
	//CString strr;
	//strr.Format(_T("%d"), xx_radio);
	//MessageBox(strr);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CXXMFCDlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CXXMFCDlg::OnBnClickedRadio1()
{
	xx_radio = 0;
	//CString strr;
	//strr.Format(_T("%d"), xx_radio);
	//MessageBox(strr);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
