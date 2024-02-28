#include <tchar.h>
#include <windows.h>
#include <stdio.h>
#include <cstring>

LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

TCHAR szClassName[ ] = _T("CodeBlocksWindowsApp");
HWND textfield,button,textbox1,textbox2;

char texts1[20],texts2[20];
int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    HWND hwnd;
    MSG messages;
    WNDCLASSEX wincl;

    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;
    wincl.style = CS_DBLCLKS;
    wincl.cbSize = sizeof (WNDCLASSEX);


    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;
    wincl.cbClsExtra = 0;
    wincl.cbWndExtra = 0;
    wincl.hbrBackground = (HBRUSH) CreateSolidBrush(RGB(0, 255, 0));

    if (!RegisterClassEx (&wincl))
        return 0;

    hwnd = CreateWindowEx (
           0,
           szClassName,
           _T("My Calculator"),
           WS_SYSMENU,
           CW_USEDEFAULT,
           CW_USEDEFAULT,
           250,
           200,
           HWND_DESKTOP,
           NULL,
           hThisInstance,
           NULL
           );

    ShowWindow (hwnd, nCmdShow);

    if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

    while (GetMessage (&messages, NULL, 0, 0))
    {
        TranslateMessage(&messages);
        DispatchMessage(&messages);
    }

    return messages.wParam;
}

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
        case WM_CREATE:
            textfield = CreateWindow("STATIC",
                                     "Please input two numbers",
                                     WS_VISIBLE | WS_CHILD,
                                     30, 15, 175, 25,
                                     hwnd, NULL, NULL, NULL);

            button = CreateWindow("BUTTON",
                                  "+", WS_VISIBLE | WS_CHILD | WS_BORDER,
                                  40, 125, 30, 30,
                                  hwnd, (HMENU)1, NULL, NULL);
            button = CreateWindow("BUTTON",
                                  "-", WS_VISIBLE | WS_CHILD | WS_BORDER,
                                  80, 125, 30, 30,
                                  hwnd, (HMENU)2, NULL, NULL);
            button = CreateWindow("BUTTON",
                                  "*", WS_VISIBLE | WS_CHILD | WS_BORDER,
                                  120, 125, 30, 30,
                                  hwnd, (HMENU)3, NULL, NULL);
            button = CreateWindow("BUTTON",
                                  "/", WS_VISIBLE | WS_CHILD | WS_BORDER,
                                  160, 125, 30, 30,
                                  hwnd, (HMENU)4, NULL, NULL);

            textbox1 = CreateWindow("EDIT",
                                   "", WS_BORDER | WS_CHILD | WS_VISIBLE,
                                   30, 50, 175, 25,
                                   hwnd, NULL, NULL, NULL);
            textbox2 = CreateWindow("EDIT",
                                   "", WS_BORDER | WS_CHILD | WS_VISIBLE,
                                   30, 80, 175, 25,
                                   hwnd, NULL, NULL, NULL);
            break;

        case WM_COMMAND:
            switch(LOWORD(wParam)){
                case 1:
                    {int gwtstat1 = 0, gwtstat2 = 0;
                    gwtstat1 = GetWindowText(textbox1,&texts1[0],20);
                    gwtstat2 = GetWindowText(textbox2,&texts2[0],20);

                    double ans = atof(texts1)+atof(texts2);
                    char answer[50];
                    sprintf(answer,"%.3lf",ans);
                    ::MessageBox(hwnd,answer,"Result",MB_OK);
                    break;}
                case 2:
                    {int gwtstat1 = 0, gwtstat2 = 0;
                    gwtstat1 = GetWindowText(textbox1,&texts1[0],20);
                    gwtstat2 = GetWindowText(textbox2,&texts2[0],20);

                    double ans = atof(texts1)-atof(texts2);
                    char answer[50];
                    sprintf(answer,"%.3lf",ans);
                    ::MessageBox(hwnd,answer,"Result",MB_OK);
                    break;}
                case 3:
                    {int gwtstat1 = 0, gwtstat2 = 0;
                    gwtstat1 = GetWindowText(textbox1,&texts1[0],20);
                    gwtstat2 = GetWindowText(textbox2,&texts2[0],20);

                    double ans = atof(texts1)*atof(texts2);
                    char answer[50];
                    sprintf(answer,"%.3lf",ans);
                    ::MessageBox(hwnd,answer,"Result",MB_OK);
                    break;}
                case 4:
                    {int gwtstat1 = 0, gwtstat2 = 0;
                    gwtstat1 = GetWindowText(textbox1,&texts1[0],20);
                    gwtstat2 = GetWindowText(textbox2,&texts2[0],20);

                    double ans = atof(texts1)/atof(texts2);
                    char answer[50];
                    sprintf(answer,"%.3lf",ans);
                    ::MessageBox(hwnd,answer,"Result",MB_OK);
                    break;}
            }
            break;
        case WM_DESTROY:
            PostQuitMessage (0);
            break;
        default:
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}
