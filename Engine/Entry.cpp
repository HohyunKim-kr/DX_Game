#include <Windows.h>

#pragma comment(linker,"/entry:WinMainCRTStartup /subsystem:console")

// _In_ : ���� ������ ������ ���α׷��� �������� �ʰڴٴ� ��ũ�� 
// HINSTANCE (Instance Handle)
// ���μ����� �ּҸ� ���� ���·� ������ �� �ִ� �ڷ���

LRESULT CALLBACK Procedure
(
	HWND   const hWindow,
	UINT   const uMessage,
	WPARAM const wParam,
	LPARAM const lParam
)
{
	switch(uMessage)
	{
		case WM_CREATE:
			return 0;
		default:
			return DefWindowProc(hWindow, uMessage, wParam, lParam);
	}
}

int APIENTRY WinMain
(
	_In_	 HINSTANCE const hInstance,
	_In_opt_ HINSTANCE const hprevInstance,
	_In_	 LPSTR	   const lpCmdLine,
	_In_	 int	   const nCmdshow
)
{
	
	HWND hwnd = nullptr;

	// 1. ������ ������ Ŭ���� �ۼ��ϰ� ��� 
	{	
		WNDCLASSEX wndClass = WNDCLASSEX();

		wndClass.cbSize			= sizeof(WNDCLASSEX);
		wndClass.lpfnWndProc	= Procedure;
		wndClass.hInstance		= hInstance;
		wndClass.hIcon			= LoadIcon(nullptr,IDI_APPLICATION);
		wndClass.hIconSm		= LoadIcon(nullptr, IDI_APPLICATION);
		wndClass.hCursor		= LoadIcon(nullptr,IDC_ARROW);
		wndClass.hbrBackground  = static_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
		wndClass.lpszClassName	= "Window";
		// cbClsExtra		= 0;
		// cbWndExtra		= 0;
		// lpszMenuName		= nullptr;
		// style			= WS_OVERLAPPEDWINDOW;

		RegisterClassEx(&wndClass);				// Ŭ���� ��� �Լ�  
	}

	{
		CREATESTRUCT window = CREATESTRUCT();
		
		window.lpszClass			= "Window";
		window.lpszName				= "Game";
		window.style				= WS_CAPTION | WS_SYSMENU;
		window.hInstance			= hInstance;
		window.cx					= 1280;
		window.cy					= 720;
		window.x					= 100;
		window.y					= 100;

		hwnd = CreateWindowEx
		(
			window.dwExStyle,
			window.lpszClass,
			window.lpszName,
			window.style,
			window.x,
			window.y,
			window.cx,
			window.cy,
			window.hwndParent,
			window.hMenu,
			window.hInstance,
			window.lpCreateParams
		);

		ShowWindow(hwnd, SW_RESTORE);

		{
			MSG msg = MSG();


			while (true)
			{
				if (PeekMessage(&msg, HWND(), WM_NULL, WM_NULL, PM_REMOVE))
				{
					if (msg.message == WM_QUIT)
						return static_cast<int>(msg.wParam);

					// �޽��� ó��
					DispatchMessage(&msg);
				}
				else
				{
					SendMessage(hwnd, WM_APP, NULL, NULL);
				}
			}

			return 0;
		}
	}





	// 2. ����� Ŭ������ ������ ����
	// 3. �޼��� ������  ���� ���α׷��� ����  
 	// 4. ����
}






