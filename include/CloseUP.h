#pragma once
#include "RendererHook.h"

class CloseUP
{
public:
	static void Init();

private:
	CloseUP() = default;
	static CloseUP* GetSingleton();

private:
	RendererHook renderer;
};
