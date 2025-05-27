/**
 * @file	GDIRenderer.h
 * @brief	GDI渲染器
 * @author	LambShaun
 **/

#pragma once
#include"Engine/Core/Interfaces/IRenderer.h"
#include"windows.h"

namespace Engine{
namespace Function{
namespace Graphics{

class GDIRenderer:public Engine::Core::IRenderer {
public:
 GDIRenderer();
 ~GDIRenderer();

 bool Initialize(HWND hWnd, int width, int height) override; 
 void Shutdown() override; 
 void BeginFrame() override; 
 void EndFrame() override;
 void ClearScreen(float r, float g, float b) override; 
 void DrawRectangle(int x, int y, int width, int height, float r,
                            float g, float b) override; 
 void DrawFilledRectangle(int x, int y, int width, int height, float r,
                                  float g, float b) override; 

private:
 HWND hWnd_ = nullptr;
 HDC hWindowDC_ = nullptr;    // DC for the actual window
 HDC hMemoryDC_ = nullptr;    // Off-screen DC for double buffering
 HBITMAP hBitmap_ = nullptr;    // Bitmap in hMemoryDC
 HBITMAP hOldBitmap_ = nullptr; // Original bitmap in hMemoryDC
 int renderWidth_ = 0;
 int renderHeight_ = 0;
};
} // namespace Graphics

} // namespace Function

 } // namespace Engine
 