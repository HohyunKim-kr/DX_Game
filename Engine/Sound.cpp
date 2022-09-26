#include <Windows.h>

#include "Sound.h"

namespace Sound
{
    void Procedure(HWND const hWindow, UINT const uMessage, WPARAM const wParam, LPARAM const lParam)
    {
        switch (uMessage)
        {
            case WM_CREATE :
            {
                return;
            }
            case WM_DESTROY :
            {
                return;
            }
        }
    }
};