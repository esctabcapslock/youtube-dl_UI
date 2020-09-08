
// XXMFCDlg.h: 헤더 파일
//

#pragma once


// CXXMFCDlg 대화 상자
class CXXMFCDlg : public CDialogEx
{
// 생성입니다.
public:
	CXXMFCDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_XXMFC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedRadio1();
	// 라디오 버튼 제어 변수 추가
	int xx_radio;
};
