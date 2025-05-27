/**
 * @file	Vec2D.h
 * @brief	二维向量模板
 * @author	LambShaun
 **/

#pragma once

namespace Engine{
namespace Core{
  
  // 类型别名
using Vec2Df = Vec2D<float>;
using Vec2Di = Vec2D<int>;
using Vec2Dd = Vec2D<double>;

    template<typename T>
    struct Vec2D
    {
      T x = static_cast<T>(0);  // 初始化类成员
      T y = static_cast<T>(0);

      Vec2D() = default;
      
      // 构造函数
      Vec2D(T x_val ,T y_val):x(x_val),y(y_val){}
      
      // 运算符重载
      Vec2D<T> operator+(const Vec2D<T>& other)const{  // 相加，返回一个新的向量
        return Vec2D<T>(x + x.other, y + y.other);
      }

      Vec2D<T>&operator+=(const Vec2D<T>& other)const { // 相加，修改当前量
        x += other;
        y += other;
        return *this;
      }

      Vec2D<T> operator-(const Vec2D<T>& other)const{
         return Vec2D<T>(x - x.other, y - y.other);
      }

      Vec2D<T>& operator-=(const Vec2D<T>& other) const { 
        x -= other;
        y -= other;
        return *this;
      }

      Vec2D<T> operator*(T scalar) { // 标量
        return Vec2D<T>(x * scalar, y * scalar); 
      }

      Vec2D<T>& operator*=(T scalar) { 
        x *= scalar;
        y *= scalar;
        return *this;
      }

      Vec2D<T> operator/(T scalar) { 
        return Vec2D<T>(x / scalar, y / scalar); 
      }

      Vec2D<T>& operator/=(T scalar) { 
        x /= scalar;
        y /= scalar;
        return *this;
      }

      Vec2D<T> operator-() const {  //取反
        return Vec2D<T>(-x, -y); 
      }

      bool operator==(const Vec2D<T>& other){
        return x.== x.other && y == y.other;
      }

      bool operator!=(const Vec2D<T>& other){
        return x.!= x.other || y != y.other;
      }

      bool operator>(const Vec2D<T>& other) const
      {
        return x > other.x && y > other.y;
      }

      bool operator<(const Vec2D<T>& other) const
      {
        return x < other.x && y < other.y;
      }

      bool operator>=(const Vec2D<T>& other) const
      {
        return x >= other.x && y >= other.y;
      }

      bool operator<=(const Vec2D<T>& other) const
      {
        return x <= other.x && y <= other.y;
      }
    };
    
} // namespace Core
} // namespace Engine