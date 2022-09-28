#include "Pipeline.h"

#pragma comment(lib, "d3d11.lib")

namespace Pipeline
{
    namespace
    {
        ID3D11Device        * Device;
        ID3D11DeviceContext * DeviceContext;
        IDXGISwapChain      * SwapChain;
    }

    void Procedure(HWND const hWindow, UINT const uMessage, WPARAM const wParam, LPARAM const lParam)
    {
        switch (uMessage)
        {
            case WM_APP:
            {
                return;
            }
            case WM_SIZE:
            {
                return;
            }
            case WM_CREATE:
            {
                DXGI_SWAP_CHAIN_DESC descriptor = DXGI_SWAP_CHAIN_DESC();

                descriptor.BufferDesc.Format  = DXGI_FORMAT_B8G8R8A8_UNORM;
                descriptor.SampleDesc.Count   = 1;
                descriptor.BufferUsage        = DXGI_USAGE_RENDER_TARGET_OUTPUT;
                descriptor.SwapEffect         = DXGI_SWAP_EFFECT_DISCARD;
                descriptor.BufferCount        = 1;
                descriptor.OutputWindow       = hWindow;
                descriptor.Windowed           = true;

                D3D11CreateDeviceAndSwapChain
                (
                    nullptr,
                    D3D_DRIVER_TYPE_HARDWARE,
                    nullptr,
                    0,
                    nullptr,
                    0,
                    D3D11_SDK_VERSION,
                    &descriptor,
                    &SwapChain,
                    &Device,
                    nullptr,
                    &DeviceContext
                );

                return;
            }
            case WM_DESTROY:
            {
                SwapChain->Release();
                DeviceContext->Release();
                Device->Release();

                return;
            }
        }
    }
}