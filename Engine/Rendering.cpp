#include "Rendering.h"

#include <Windows.h>

namespace Pipeline
{ void Procedure(HWND const, UINT const, WPARAM const, LPARAM const); }

namespace Rendering
{
    void Procedure(HWND const hWindow, UINT const uMessage, WPARAM const wParam, LPARAM const lParam)
    {
        switch (uMessage)
        {
            case WM_APP :
            {
                Pipeline::Procedure(hWindow, uMessage, wParam, lParam);

                return;
            }
            case WM_SIZE :
            {
                Pipeline::Procedure(hWindow, uMessage, wParam, lParam);

                return;
            }
            case WM_CREATE :
            {
                Pipeline::Procedure(hWindow, uMessage, wParam, lParam);

                return;
            }
            case WM_DESTROY :
            {
                Pipeline::Procedure(hWindow, uMessage, wParam, lParam);

                return;
            }
        }
    }
};