#include <Windows.h>

#pragma comment(linker,"/entry:WinMainCRTStartup /subsystem:console")

// _In_ : 값이 들어오지 않으면 프로그램을 시작하지 않겠다는 매크로 
// HINSTANCE (Instance Handle)
// 프로세서의 주소를 정수 형태로 저장할 수 있는 자료형

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

	// 1. 윈도우 구성할 클래스 작성하고 등록 
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

		RegisterClassEx(&wndClass);				// 클래스 등록 함수  
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

					// 메시지 처리
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





	// 2. 등록한 클래스로 윈도우 생성
	// 3. 메세지 루프를  통한 프로그램의 실행  
 	// 4. 종료
}






