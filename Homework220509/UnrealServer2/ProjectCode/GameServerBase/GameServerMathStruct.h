#pragma once

// 윈도우에서 기본지원해주는 
#include <d3d11.h>
#include <DirectXCollision.h>

// 여러분들이 개발하는 환경은?
// window니까 기본 설치되어 있어
// simd연산을 사용해서 속력이 빠르다.
// 

// 다이렉트 x 라이브러리를 사용하려는 이유

struct FVector4 
{
public:
	static const FVector4 ZeroVector;
	///** A zero vector (0,0,0) */
	//static CORE_API const FVector ZeroVector;

	///** One vector (1,1,1) */
	//static CORE_API const FVector OneVector;

	///** Unreal up vector (0,0,1) */
	//static CORE_API const FVector UpVector;

	///** Unreal down vector (0,0,-1) */
	//static CORE_API const FVector DownVector;

	///** Unreal forward vector (1,0,0) */
	//static CORE_API const FVector ForwardVector;

	///** Unreal backward vector (-1,0,0) */
	//static CORE_API const FVector BackwardVector;

	///** Unreal right vector (0,1,0) */
	//static CORE_API const FVector RightVector;

	///** Unreal left vector (0,-1,0) */
	//static CORE_API const FVector LeftVector;

	///** Unit X axis vector (1,0,0) */
	//static CORE_API const FVector XAxisVector;

	///** Unit Y axis vector (0,1,0) */
	//static CORE_API const FVector YAxisVector;

	///** Unit Z axis vector (0,0,1) */
	//static CORE_API const FVector ZAxisVector;
public:
	union 
	{
		struct
		{
			float X;
			float Y;
			float Z;
			float W;
		};

		// int 1 int 1
		// 00000001 00000000 00000000 00000000  00000001 00000000 00000000 00000000
		// 16바이트 자료형이에요,.
		DirectX::XMVECTOR DxVector;
		float Arr[4];
	};

	FVector4& operator+=(const FVector4& _Value)
	{
		X += _Value.X;
		Y += _Value.Y;
		Z += _Value.Z;

		return *this;
	}

	// 빼면 방향이 나옵니다.
	FVector4 operator-(const FVector4& _Value)
	{
		return { X - _Value.X, Y - _Value.Y, Z - _Value.Z };
	}

	FVector4 operator+(const FVector4& _Value)
	{
		return { X + _Value.X, Y + _Value.Y, Z + _Value.Z };
	}

	FVector4 operator*(const float _Value)
	{
		return { X * _Value, Y * _Value, Z * _Value };
	}



	static FVector4 Normalize3D(const FVector4& _Value)
	{
		// 피타고라스의 정리
		// sqrt(x제곱 + y제곱) => 빗변의 제곱
		// 

		DirectX::XMVECTOR Vec = DirectX::XMVector3Normalize(_Value.DxVector);
		// sqrt(X * X + Y * Y);
		return Vec;
	}

	FVector4 Normalize3DReturn() const
	{
		// 피타고라스의 정리
		// sqrt(x제곱 + y제곱) => 빗변의 제곱
		// 

		DirectX::XMVECTOR Vec = DirectX::XMVector3Normalize(DxVector);
		// sqrt(X * X + Y * Y);
		return Vec;
	}

	void Normalize3DSelf() 
	{
		// 피타고라스의 정리
		// sqrt(x제곱 + y제곱) => 빗변의 제곱
		// 

		DxVector = DirectX::XMVector3Normalize(DxVector);
		
		// sqrt(X * X + Y * Y);
		return;
	}



	static float Length3D(const FVector4& _Value)
	{
		// 피타고라스의 정리
		// sqrt(x제곱 + y제곱) => 빗변의 제곱
		// 

		DirectX::XMVECTOR Vec = DirectX::XMVector3Length(_Value.DxVector);
		// sqrt(X * X + Y * Y);
		return Vec.m128_f32[0];
	}

	float Length3DReturn() const
	{
		// 피타고라스의 정리
		// sqrt(x제곱 + y제곱) => 빗변의 제곱
		// 

		DirectX::XMVECTOR Vec = DirectX::XMVector3Length(DxVector);
		// sqrt(X * X + Y * Y);
		return Vec.m128_f32[0];
	}

	static float Length2D(const FVector4& _Value)
	{
		// 피타고라스의 정리
		// sqrt(x제곱 + y제곱) => 빗변의 제곱
		// 

		DirectX::XMVECTOR Vec = DirectX::XMVector2Length(_Value.DxVector);
		// sqrt(X * X + Y * Y);
		return Vec.m128_f32[0];
	}

	float Length2DReturn() const
	{
		// 피타고라스의 정리
		// sqrt(x제곱 + y제곱) => 빗변의 제곱
		// 

		DirectX::XMVECTOR Vec = DirectX::XMVector2Length(DxVector);
		// sqrt(X * X + Y * Y);
		return Vec.m128_f32[0];
	}

	std::string ToString() 
	{
		return "X : " + std::to_string(X) + " Y : " + std::to_string(Y) + " Z : " + std::to_string(Z);
	}


	FVector4 HalfVector3D()
	{
		return { X*0.5f , Y * 0.5f, Z * 0.5f };
	}


	DirectX::XMFLOAT3 ConvertXMFloat3()
	{
		return { X , Y , Z};
	}

	DirectX::XMFLOAT4 ConvertXMFloat4()
	{
		return { X , Y , Z, W };
	}



	FVector4 Subtraction2D(const FVector4& _Value)
	{
		return { X - _Value.X, Y - _Value.Y };
	}

	FVector4 Subtraction3D(const FVector4& _Value)
	{
		return operator-(_Value);
	}

	FVector4()
		: X(0.0f), Y(0.0f), Z(0.0f)
	{

	}

	FVector4(float _X, float _Y)
		: X(_X), Y(_Y), Z(0.0f)
	{

	}


	FVector4(float _X, float _Y, float _Z)
		: X(_X), Y(_Y), Z(_Z)
	{

	}


	FVector4(DirectX::XMVECTOR _Value)
		: DxVector(_Value)
	{
		
	}
};


