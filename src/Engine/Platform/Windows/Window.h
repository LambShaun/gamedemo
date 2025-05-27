/**
 * @file	Window.h
 * @brief	Windows平台
 * @author	LambShaun
 **/

#pragma once
#include<windows.h>
#include<string>

namespace Game{
namespace GameLogic{
   class CelesteGame;     
} // namespace GameLogic
    
} // namespace Game

namespace Engine{
namespace Platform{
class Window {
public:
 Window(HINSTANCE hInstance, const std::wstring& title, int clientWidth,
        int clientHeight);
 ~Window();

 bool Create(); // 创建窗口
 void Show(int nCmdShow);   // 使窗口可见
 HWND GetHWND() const { return hWnd_;} // 返回窗口的句柄
 int GetClientWidth() const { return clientWidth_; } 
 int GetClientHeight() const { return clientHeight_; }
 void SetGameInstance(Game::GameLogic::CelesteGame* game); // 指向游戏逻辑实例 (CelesteGame) 的指针

 static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam,
                                 LPARAM lParam);

private:
 HINSTANCE hInstance_;
 HWND hWnd_;
 std::wstring title_;
 int clientWidth_;
 int clientHeight_;
 Game::GameLogic::CelesteGame* gameInstance_ = nullptr;
};
} // namespace Platform

} // namespace Engine

