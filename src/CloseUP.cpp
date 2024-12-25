#include "CloseUP.h"

void CloseUP::Init()
{
	GetSingleton()->renderer.Install();
}

CloseUP* CloseUP::GetSingleton()
{
	static CloseUP singleton;
	return &singleton;
}
