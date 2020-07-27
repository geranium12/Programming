// WinTrash.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

#include "MyException.h"
#include "ListWithIterator.h"
#include "Controller.h"
#include "View.h"

#include "WinTrash.h"

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

const int STR_SIZE = 80;

List<int>* list1 = new List<int>;
View<int>* view = new View<int>();
Controller<int> controller(list1, view);

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
	   CW_USEDEFAULT, 0, 500, 500, nullptr, nullptr, hInstance, nullptr);

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
		hButtonPopFront, hButtonPopBack, hEditInput, hEditOutput, hButtonClear,
		hButtonAll, hButtonSum, hButtonMin;

    switch (message)
    {
	case WM_CREATE:
	{
		hEditInput = CreateWindow("Edit", "1", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_NUMBER, 300, 40, 100, 30, hWnd, (HMENU)ID_EDIT_INPUT, hInst, 0);
		hEditOutput = CreateWindow("Edit", "", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOVSCROLL | WS_VSCROLL | ES_LEFT | ES_MULTILINE | 
			ES_READONLY | ES_NUMBER, 50, 40, 200, 330, hWnd, (HMENU)ID_EDIT_OUTPUT, hInst, 0);

		hButtonFront = CreateWindow("Button", "Front", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTER , 300, 80, 100, 20, hWnd, (HMENU)ID_FRONT, hInst, 0);
		hButtonBack = CreateWindow("Button", "Back", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTER, 300, 110, 100, 20, hWnd, (HMENU)ID_BACK, hInst, 0);
		hButtonPushFront = CreateWindow("Button", "PushFront", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTER, 300, 140, 100, 20, hWnd, (HMENU)ID_PUSHFRONT, hInst, 0);
		hButtonPushBack = CreateWindow("Button", "PushBack", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTER, 300, 170, 100, 20, hWnd, (HMENU)ID_PUSHBACK, hInst, 0);
		hButtonPopFront = CreateWindow("Button", "PopFront", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTER, 300, 200, 100, 20, hWnd, (HMENU)ID_POPFRONT, hInst, 0);
		hButtonPopBack = CreateWindow("Button", "PopBack", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTER, 300, 230, 100, 20, hWnd, (HMENU)ID_POPBACK, hInst, 0);
		hButtonClear = CreateWindow("Button", "Clear", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTER, 300, 260, 100, 20, hWnd, (HMENU)ID_CLEAR, hInst, 0);
		hButtonAll = CreateWindow("Button", "Output", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTER, 300, 290, 100, 20, hWnd, (HMENU)ID_OUTPUT_ALL, hInst, 0);
		hButtonSum = CreateWindow("Button", "Sum", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTER, 300, 320, 100, 20, hWnd, (HMENU)ID_SUM, hInst, 0);
		hButtonMin = CreateWindow("Button", "Min", WS_CHILD | WS_VISIBLE | WS_BORDER | SS_CENTER, 300, 350, 100, 20, hWnd, (HMENU)ID_MIN, hInst, 0);
	}
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
			
			case ID_FRONT:
			{
				controller.Front(hWnd);
				break;
			}

			case ID_BACK:
			{
				controller.Back(hWnd);
				break;
			}
			
			case ID_PUSHFRONT:
			{
				int value = GetDlgItemInt(hWnd, ID_EDIT_INPUT, NULL, true);
				controller.PushFront(value, hWnd);
				break;
			}
			
			case ID_PUSHBACK:
			{
				int value = GetDlgItemInt(hWnd, ID_EDIT_INPUT, NULL, true);
				controller.PushBack(value, hWnd);
				break;
			}
			
			case ID_POPFRONT:
			{
				controller.PopFront(hWnd);
				break;
			}
			
			case ID_POPBACK:
			{
				controller.PopBack(hWnd);
				break;
			}
			
			case ID_CLEAR:
			{
				controller.Clear(hWnd);
				break;
			}
			
			case ID_OUTPUT_ALL:
			{
				controller.OutputAll(list1, hWnd);
				break;
			}
			
			case ID_SUM:
			{
				controller.Sum(hWnd);
				break;
			}
			case ID_MIN:
			{
				controller.Min(hWnd);
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
