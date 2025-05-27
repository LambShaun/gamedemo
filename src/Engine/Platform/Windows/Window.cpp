#include"Engine/Platform/Windows/Window.h"
#include"Game/GameLogic/CelesteGame.h"

namespace Engine{
namespace Platform{ 
Window::Window(HINSTANCE hInstance, const std::wstring& title, int clientWidth, int clientHeight) :
	hInstance_(hInstance), title_(title),
	clientWidth_(clientWidth), clientHeight_(clientHeight),
	hWnd_(nullptr), gameInstance_(nullptr) {}

Window::~Window(){
    if(hWnd_){
      DestroyWindow(hWnd_); // 如果窗口句柄有效则先销毁
    }
}

void Window::SetGameInstance(Game::GameLogic::CelesteGame*game){
  gameInstance_ = game;
}

bool Window::Create(){
  WNDCLASSEXW wcex = {};
  wcex.cbSize = sizeof(WNDCLASSEXW);
  wcex.style = CS_HREDRAW | CS_VREDRAW;
  wcex.lpfnWndProc = WndProc;
  0;
  wcex.cbWndExtra = sizeof(Window*);
  wcex.hInstance = hInstance_;
  wcex.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
  wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
  wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
  wcex.lpszMenuName = nullptr;
  wcex.lpszClassName = title_.c_str();
  wcex.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);

  if(!RegisterClassExW(&wcex)){
    return false;
  }

  // 调整窗口尺寸
  RECT windowRect = {0, 0, clientWidth_, clientHeight_}; 
  AdjustWindowRect(&windowRect,WS_OVERLAPPEDWINDOW,false); // 计算窗口大小
  int adjustedWidth = windowRect.right - windowRect.left;
  int adjustedHeight = windowRect.bottom - windowRect.top;
  
  hWnd_ = CreateWindowExW(
  0,
  title_.c_str(),title_.c_str(),
  WS_OVERLAPPEDWINDOW,
  CW_USEDEFAULT, CW_USEDEFAULT,
  adjustedWidth, adjustedHeight,
  nullptr,nullptr,hInstance_,
  this);

  // 验证客户区尺寸
  if(hWnd_){
    RECT actualClientRect;
    GetClientRect(hWnd_, &actualClientRect);  // 获取实际的客户端尺寸
    clientWidth_ = actualClientRect.right - actualClientRect.left; // 用实际尺寸更新成员变量
    clientHeight_ = actualClientRect.bottom - actualClientRect.top;
  }
  return hWnd_ != nullptr;
}

void Window::Show(int nCmdShow) {
    if (hWnd_) {
        ShowWindow(hWnd_, nCmdShow);
        UpdateWindow(hWnd_);
    }
}

LRESULT CALLBACK Window::WndProc(HWND hWnd,UINT message ,WPARAM wParam,LPARAM lParam){
	Window* pWindow = nullptr;
	if (message == WM_NCCREATE) {
		CREATESTRUCT* pCreate = (CREATESTRUCT*)lParam; // lParam 包含一个指向 CREATESTRUCT 结构体的指针
		pWindow = (Window*)pCreate->lpCreateParams;  // lpCreateParams 就是 CreateWindowExW 时传递的 this 指针
		SetWindowLongPtr(hWnd, GWLP_USERDATA, (LONG_PTR)pWindow); // 将 Window 对象指针存储在窗口的附加数据区
	}else {
        // 对于其他消息 从窗口的附加数据区中获取之前存储的 Window 对象指针
		pWindow = (Window*)GetWindowLongPtr(hWnd, GWLP_USERDATA);
	}
    // 如果成功获取了 Window 对象指针并且该对象关联了一个游戏实例
	if (pWindow && pWindow->gameInstance_) {
        //TODO
	}
    switch(message){
        case WM_KEYDOWN:{
            if (wParam == VK_ESCAPE) {
	            PostQuitMessage(0);
            }
        } break;

        case WM_PAINT:{
          PAINTSTRUCT ps;
          BeginPaint(hWnd, &ps);
          EndPaint(hWnd, &ps);
        } break;

        case WM_SIZE:{
            if(pWindow){ // 检查
              pWindow->clientWidth_ = LOWORD(lParam);
              pWindow->clientHeight_ = HIWORD(lParam);
            }
        } break;

        case WM_CLOSE: {
          PostQuitMessage(0);
	      return 0;
        }break;
			 
        case WM_DESTROY: {

        }break;

    default:
	return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;

}

} // namespace Platform

} // namespace Engine
