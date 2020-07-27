// WindowsProject1.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "WindowsProject1.h"
#define _USE_MATH_DEFINES 
#include <cmath>
#include <string>
//#include <cstring>

#define MAX_LOADSTRING 100
#define	ID_EDIT_INPUT	1
#define	ID_EDIT_SIN	2
#define ID_EDIT_COS	3
#define ID_EDIT_TAN 4
#define ID_EDIT_COTAN 5
#define ID_BUTTON 6
#define ID_STATIC1 7
#define ID_BUTTON_DEG_RAD 8

using namespace std;

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

const int STR_NUMBER_SIZE = 10;
const int STR_SIZE = 300;

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

double Sinus(double x);
double Cosinus(double x);
double Tangens(double x);
double Cotangens(double x);
bool Check(double x);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: Place code here.

	// Initialize global strings
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_WINDOWSPROJECT1, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSPROJECT1));

	MSG msg;

	// Main message loop:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSPROJECT1));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WINDOWSPROJECT1);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // Store instance handle in our global variable

	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, 200, 280, nullptr, nullptr, hInstance, nullptr);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static HWND hButton, hStatic1, hEditInput, hEditSin, hEditCos, hEditTan, hEditCotan, hButtonDegRad;
	static HMENU hMainMenu, hFileMenu;
	static char flag = false;

	switch (message)
	{
	case WM_CREATE:
	{
		hStatic1 = CreateWindow(L"Static", L"Input a number", WS_CHILD | WS_VISIBLE | BS_CENTER | SS_CENTER, 50, 7, 100, 10, hWnd, (HMENU)ID_STATIC1, hInst, 0);
		hEditInput = CreateWindow(L"Edit", L"1", WS_CHILD | WS_VISIBLE | WS_BORDER, 50, 30, 90, 20, hWnd, (HMENU)ID_EDIT_INPUT, hInst, 0);
		hEditSin = CreateWindow(L"Edit", L"SIN", WS_CHILD | WS_VISIBLE | WS_BORDER, 50, 60, 40, 20, hWnd, (HMENU)ID_EDIT_SIN, hInst, 0);
		hEditCos = CreateWindow(L"Edit", L"COS", WS_CHILD | WS_VISIBLE | WS_BORDER, 100, 60, 40, 20, hWnd, (HMENU)ID_EDIT_COS, hInst, 0);
		hEditTan = CreateWindow(L"Edit", L"TAN", WS_CHILD | WS_VISIBLE | WS_BORDER, 50, 100, 40, 20, hWnd, (HMENU)ID_EDIT_TAN, hInst, 0);
		hEditCotan = CreateWindow(L"Edit", L"COTAN", WS_CHILD | WS_VISIBLE | WS_BORDER, 100, 100, 40, 20, hWnd, (HMENU)ID_EDIT_COTAN, hInst, 0);
		hButton = CreateWindow(L"Button", L"=", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 50, 130, 90, 40, hWnd, (HMENU)ID_BUTTON, hInst, 0);
		hButtonDegRad = CreateWindow(L"Button", L"DEG", WS_CHILD | WS_VISIBLE | WS_BORDER, 73, 180, 45, 30, hWnd, (HMENU)ID_BUTTON_DEG_RAD, hInst, 0);
		flag = false;
		//Button_SetCheck(hRadioButton1, BST_CHECKED);
		/*
		hFileMenu = CreatePopupMenu();
		CreateMenuItem(hFileMenu, "Âûõîä", 3, EXIT_PROGRAM, NULL, FALSE, MFT_STRING);
		CreateMenuItem(hMainMenu, "Ìåíþ âûõîäà", 1, MENU_PROGRAM, hFileMenu, FALSE, MFT_STRING);
		CreateMenuItem(hMainMenu, "Î ïðîãðàììå", 2, MENU_ABOUT, 0, FALSE, MFT_STRING);
		SetMenu(hWnd, hMainMenu);
		DrawMenuBar(hWnd);

		case MENU_ABOUT:
			MessageBox(hWnd, "Ïðîãðàììà âûïîëíåíà ×åðíÿâñêèì Äìèòðèåì äëÿ ñåáÿ è áóäóþùèõ ïîêîëåíèé :), 2016", "Î ïðîãðàììå", 0);
			break;
		case ID_BUTTON1:
			SendMessage(hEdit1, WM_GETTEXT, sizeof(number1) / sizeof(number1[0]), (LPARAM)number1);

			char buffer[20];
			_itoa_s(atoi(number1) + atoi(number2), buffer, 10);

			SetWindowText(hEdit3, (LPCSTR)buffer);
			SetFocus(hEdit1);
		*/
	}
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case ID_BUTTON:
		{
			// Sinus
			string str;
			GetWindowTextA(hEditInput, LPSTR(str.c_str()), 10);
			char *pEnd;
			double x = strtod(str.c_str(), &pEnd);
			if (flag)
			{
				while (x > (M_PI * 2))
				{
					x -= (M_PI * 2);
				}
			}
			else
			{
				while (x > 360)
				{
					x -= 360;
				}
			}
			if (flag)
			{
				str = to_string(sin(x));
			}
			else
			{
				str = to_string(sin(x * M_PI / 180.));
			}
			SetWindowTextA(hEditSin, LPCSTR(str.c_str()));

			// Cosinus
			if (flag)
			{
				str = to_string(cos(x));
			}
			else
			{
				str = to_string(cos(x * M_PI / 180.));
			}
			SetWindowTextA(hEditCos, LPCSTR(str.c_str()));

			// Tangens
			if (flag)
			{
				if (fabs(x - M_PI_2) < 0.01)
				{
					str = "Error";
				}
				else
				{
					str = to_string(sin(x) / cos(x));
				}
			}
			else
			{
				if (fabs(x - 90) < 0.01)
				{
					str = "Error";
				}
				else
				{
					str = to_string(sin(x * M_PI / 180.) / cos(x * M_PI / 180.));
				}
			}
			SetWindowTextA(hEditTan, LPCSTR(str.c_str()));

			// Cotangens
			if (flag)
			{
				if ((fabs(x - M_PI) < 0.01) || (fabs(x) < 0.01))
				{
					str = "Error";
				}
				else
				{
					str = to_string(cos(x) / sin(x));
				}
			}
			else
			{
				if ((fabs(x - 180.) < 0.01) || (fabs(x) < 0.01))
				{
					str = "Error";
				}
				else
				{
					str = to_string(cos(x * M_PI / 180.) / sin(x * M_PI / 180.));
				}
			}
			SetWindowTextA(hEditCotan, LPCSTR(str.c_str()));

			SetFocus(hEditInput);
			break;
		}
		case ID_BUTTON_DEG_RAD:
		{
			if (flag == false)
			{
				SetWindowTextA(hButtonDegRad, LPCSTR("RAD"));
				flag = true;
			}
			else
			{
				SetWindowTextA(hButtonDegRad, LPCSTR("DEG"));
				flag = false;
			}
			break;
		}
		case IDM_ABOUT:
		{
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		}
		case IDM_EXIT:
		{
			DestroyWindow(hWnd);
			break;
		}
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code that uses hdc here...
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

double Sinus(double x)
{
	return sin(x);
}

double Cosinus(double x)
{
	return cos(x);
}

double Tangens(double x)
{
	return atan(x);
}

double Cotangens(double x)
{
	return 1. / atan(x);
}

bool Check(double x)
{
	if (fabs(x - 90.) < 0.000001)
		return false;
	else
		return true;
}