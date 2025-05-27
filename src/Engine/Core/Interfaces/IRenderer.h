/**
 * @file	IRenderer.h
 * @brief	渲染器接口
 * @author	LambShaun
 **/

#pragma once
#include<windows.h>

namespace Engine{
namespace Core{

class IRenderer{
public:
 virtual ~IRenderer() = default;
 virtual bool Initialize(HWND hWnd, int width, int height) = 0; //初始化渲染器
 virtual void Shutdown() = 0; 
 virtual void BeginFrame() = 0; // 开始渲染帧
 virtual void EndFrame() = 0;
 virtual void ClearScreen(float r, float g, float b) = 0; // 用指定颜色清空屏幕
 virtual void DrawRectangle(int x, int y, int width, int height, float r,
                            float g, float b) = 0; // 仅边框
 virtual void DrawFilledRectangle(int x, int y, int width, int height, float r,
                                  float g, float b) = 0; // 填充内容
};
} // namespace Core

} // namespace Engin


