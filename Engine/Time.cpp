#include "Time.h"
#include <Windows.h>

namespace Time
{
    void Procedure(HWND const hWindow, UINT const uMessage, WPARAM const wParam, LPARAM const lParam)
    {
        switch (uMessage)
        {
            case WM_APP :
            {
                return;
            }
        }
    }
};