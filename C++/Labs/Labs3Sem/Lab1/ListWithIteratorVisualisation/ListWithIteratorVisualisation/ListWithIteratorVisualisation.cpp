// WinTrash.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "WinTrash.h"

#define MAX_LOADSTRING 100
#define	ID_FRONT	1001
#define ID_BACK	1002
#define ID_PUSHFRONT	1003
#define ID_PUSHBACK	1004
#define ID_POPFRONT	1005
#define ID_POPBACK	1006
#define ID_EDIT_OUTPUT	1007
#define ID_EDIT_INPUT	1008
#define ID_CLEAR	1009
#define ID_OUTPUT_ALL	1010

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

const int STR_SIZE = 80;
List<int> list1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

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
    LoadStringW(hInstance, IDC_WINTRASH, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINTRASH));

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

    return (int) msg.wParam;
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

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINTRASH));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINTRASH);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
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
	   CW_USEDEFAULT, 0, 500, 400, nullptr, nullptr, hInstance, nullptr);

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
	static HWND hButtonFront, hButtonBack, hButtonPushFront, hButtonPushBack,
		hButtonPopFront, hButtonPopBack, hEditInput, hEditOutput, hButtonClear, hButtonAll;

    switch (message)
    {
	case WM_CREATE:
	{
		hEditInput = CreateWindow(L"Edit", L"1", WS_CHILD | WS_VISIBLE | WS_BORDER, 300, 40, 100, 30, hWnd, (HMENU)ID_EDIT_INPUT, hInst, 0);
		hEditOutput = CreateWindow(L"Edit", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOVSCROLL | WS_VSCROLL | ES_LEFT | ES_MULTILINE | 
			ES_READONLY, 50, 40, 200, 270, hWnd, (HMENU)ID_EDIT_OUTPUT, hInst, 0);

		hButtonFront = CreateWindow(L"Button", L"Front", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTER , 300, 80, 100, 20, hWnd, (HMENU)ID_FRONT, hInst, 0);
		hButtonBack = CreateWindow(L"Button", L"Back", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTER, 300, 110, 100, 20, hWnd, (HMENU)ID_BACK, hInst, 0);
		hButtonPushFront = CreateWindow(L"Button", L"PushFront", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTER, 300, 140, 100, 20, hWnd, (HMENU)ID_PUSHFRONT, hInst, 0);
		hButtonPushBack = CreateWindow(L"Button", L"PushBack", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTER, 300, 170, 100, 20, hWnd, (HMENU)ID_PUSHBACK, hInst, 0);
		hButtonPopFront = CreateWindow(L"Button", L"PopFront", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTER, 300, 200, 100, 20, hWnd, (HMENU)ID_POPFRONT, hInst, 0);
		hButtonPopBack = CreateWindow(L"Button", L"PopBack", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTER, 300, 230, 100, 20, hWnd, (HMENU)ID_POPBACK, hInst, 0);
		hButtonClear = CreateWindow(L"Button", L"Clear", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTER, 300, 260, 100, 20, hWnd, (HMENU)ID_CLEAR, hInst, 0);
		hButtonAll = CreateWindow(L"Button", L"Output", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTER, 300, 290, 100, 20, hWnd, (HMENU)ID_OUTPUT_ALL, hInst, 0);
	}
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
			case ID_FRONT:
			{
				try
				{
					std::string str = std::to_string(list1.Front());
					SetWindowTextA(hEditOutput, LPCSTR(str.c_str()));
				}
				catch (MyException &ex)
				{
					wchar_t * wcstring1 = new wchar_t[STR_SIZE];
					size_t convertedChars = 0;
					mbstowcs_s(&convertedChars, wcstring1, STR_SIZE, ex.get_info(), _TRUNCATE);
					wchar_t * wcstring2 = new wchar_t[STR_SIZE];
					convertedChars = 0;
					mbstowcs_s(&convertedChars, wcstring2, STR_SIZE, ex.get_func(), _TRUNCATE);
					MessageBox(hWnd, wcstring1, wcstring2, 0);
				}
				break;
			}
			case ID_BACK:
			{
				try
				{
					std::string str = std::to_string(list1.Back());
					SetWindowTextA(hEditOutput, LPCSTR(str.c_str()));
				}
				catch (MyException &ex)
				{
					wchar_t * wcstring1 = new wchar_t[STR_SIZE];
					size_t convertedChars = 0;
					mbstowcs_s(&convertedChars, wcstring1, STR_SIZE, ex.get_info(), _TRUNCATE);
					wchar_t * wcstring2 = new wchar_t[STR_SIZE];
					convertedChars = 0;
					mbstowcs_s(&convertedChars, wcstring2, STR_SIZE, ex.get_func(), _TRUNCATE);
					MessageBox(hWnd, wcstring1, wcstring2, 0);
				}
				break;
			}
			case ID_PUSHFRONT:
			{
				char *cstr = new char[STR_SIZE];
				GetWindowTextA(hEditInput, cstr, 10);
				char *pEnd;

				try
				{
					int i = 0;
					if (!strlen(cstr))
						throw MyException("", "", 0, "", "Error input!");

					int temp = strtol(cstr, &pEnd, 10);
					if (strlen(pEnd) != 0)
						throw MyException("", "", 0, "", "Error input!");
					list1.PushFront(temp);
					
				}
				catch (MyException &ex)
				{
					// Convert char* string to a wchar_t* string.
					wchar_t * wcstring = new wchar_t[STR_SIZE];
					size_t convertedChars = 0;
					mbstowcs_s(&convertedChars, wcstring, STR_SIZE, ex.get_info(), _TRUNCATE);
					MessageBox(hWnd, wcstring, LPCWSTR(""), 0);
				}
				break;
			}
			case ID_PUSHBACK:
			{
				char *cstr = new char[STR_SIZE];
				GetWindowTextA(hEditInput, cstr, 10);
				char *pEnd;

				try
				{
					int i = 0;
					if (!strlen(cstr))
						throw MyException("", "", 0, "", "Error input!");

					int temp = strtol(cstr, &pEnd, 10);
					if (strlen(pEnd) != 0)
						throw MyException("", "", 0, "", "Error input!");
					list1.PushBack(temp); 

				}
				catch (MyException &ex)
				{
					// Convert char* string to a wchar_t* string.
					wchar_t * wcstring = new wchar_t[STR_SIZE];
					size_t convertedChars = 0;
					mbstowcs_s(&convertedChars, wcstring, STR_SIZE, ex.get_info(), _TRUNCATE);
					MessageBox(hWnd, wcstring, LPCWSTR(""), 0);
				}
				break;
			}
			case ID_POPFRONT:
			{
				try {
					list1.PopFront();
				}
				catch (MyException &ex)
				{
					wchar_t * wcstring1 = new wchar_t[STR_SIZE];
					size_t convertedChars = 0;
					mbstowcs_s(&convertedChars, wcstring1, STR_SIZE, ex.get_info(), _TRUNCATE);
					wchar_t * wcstring2 = new wchar_t[STR_SIZE];
					convertedChars = 0;
					mbstowcs_s(&convertedChars, wcstring2, STR_SIZE, ex.get_func(), _TRUNCATE);
					MessageBox(hWnd, wcstring1, wcstring2, 0);
				}
				break;
			}
			case ID_POPBACK:
			{
				try {
					list1.PopBack();
				}
				catch (MyException &ex)
				{
					wchar_t * wcstring1 = new wchar_t[STR_SIZE];
					size_t convertedChars = 0;
					mbstowcs_s(&convertedChars, wcstring1, STR_SIZE, ex.get_info(), _TRUNCATE);
					wchar_t * wcstring2 = new wchar_t[STR_SIZE];
					convertedChars = 0;
					mbstowcs_s(&convertedChars, wcstring2, STR_SIZE, ex.get_func(), _TRUNCATE);
					MessageBox(hWnd, wcstring1, wcstring2, 0);
				}
				break;
			}
			case ID_CLEAR:
			{
				list1.Clear();
				break;
			}
			case ID_OUTPUT_ALL:
			{
				if (list1.IsEmpty())
					SetWindowTextA(hEditOutput, LPCSTR("The list is empty!"));
				else
				{
					std::string str;
					for (auto element = list1.begin(); element != list1.end(); ++element)
					{
						str.append(std::to_string(*element) + "\r\n");
					}
					SetWindowTextA(hEditOutput, LPCSTR(str.c_str()));
				}
				break;
			}
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
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
            EndPaint(hWnd, &ps);
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
