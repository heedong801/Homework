// Fill out your copyright notice in the Description page of Project Settings.


#include "ClientBlueprintFunctionLibrary.h"

bool UClientBlueprintFunctionLibrary::FStringToUTF8(const FString& _FString, std::string& _UTF8)
{
	ANSICHAR* Ptr = TCHAR_TO_UTF8(*_FString);
	_UTF8 = std::string(Ptr);
	return true;
}

bool UClientBlueprintFunctionLibrary::StringToData(const std::string& _String, std::vector<uint8> _Data) 
{
	// 일단 밀고
	_Data.clear();
	_Data.resize(_String.size() + 1);
	_Data[_String.size()] = 0;
	std::copy(_String.begin(), _String.end(), _Data.begin());

	return true;
}

bool UClientBlueprintFunctionLibrary::UTF8ToFString(const std::string& _UTF8, FString& _FString)
{
	_FString = FString(UTF8_TO_TCHAR(&_UTF8[0]));
	return true;
}

bool UClientBlueprintFunctionLibrary::FStringToUTF8Data(const FString& _FString, std::vector<uint8> _Data) 
{
	std::string Text = "";
	FStringToUTF8(_FString, Text);
	StringToData(Text, _Data);

	return true;
}