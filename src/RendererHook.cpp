#include "RendererHook.h"

void RendererHook::Install()
{
	SKSE::AllocTrampoline(14 * 2);
	stl::write_thunk_call<D3DInitHook>();
}

void RendererHook::D3DInitHook::thunk()
{
	func();

	logger::info("RenderManager initializing ...");

	 auto renderer = RE::BSGraphics::Renderer::GetSingleton();
	if (!renderer)
	{
		logger::error("Cannot find renderer. Initialization failed!");
		return;
	}
	auto render_data = renderer->GetRendererData();
	if (!render_data)
	{
		logger::error("Cannot get renderer data. Initialization failed!");
		return;
	}

	logger::info("Getting swapchain...");
	auto render_window = renderer->GetCurrentRenderWindow();
	if (!render_window)
	{
		logger::error("Cannot get render_window. Initialization failed!");
		return;
	}
	auto swapchain = render_window->swapChain;
	if (!swapchain)
	{
		logger::error("Cannot get swapChain. Initialization failed!");
		return;
	}

	logger::info("Getting swapchain desc...");
	REX::W32::DXGI_SWAP_CHAIN_DESC sd{};
	if (swapchain->GetDesc(std::addressof(sd)) < 0)
	{
		logger::error("IDXGISwapChain::GetDesc failed.");
		return;
	}

	device = render_data->forwarder;
	context = render_data->context;
}
