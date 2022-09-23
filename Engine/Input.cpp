#include "Input.h"

#include <Windows.h>

namespace Input
{
    void Procedure(HWND const hWindow, UINT const uMessage, WPARAM const wParam, LPARAM const lParam)
    {
        switch (uMessage)
        {
            case WM_APP:
            {
                return;
            }
            case WM_MOUSEWHEEL : { return; } 
            case WM_MOUSEHWHEEL: { return; } 
            case WM_MOUSEMOVE  : { return; }
            case WM_LBUTTONDOWN: { return; } 
            case WM_RBUTTONDOWN: { return; }
            case WM_MBUTTONDOWN: { return; } 
            case WM_XBUTTONDOWN: { return; } 
            case WM_SYSKEYDOWN : { return; } 
            case WM_KEYDOWN    : { return; } 
            case WM_LBUTTONUP  : { return; }
            case WM_RBUTTONUP  : { return; }
            case WM_MBUTTONUP  : { return; }
            case WM_XBUTTONUP  : { return; }
            case WM_SYSKEYUP   : { return; }
            case WM_KEYUP      : { return; }  
        }
    }
};