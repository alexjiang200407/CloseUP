#pragma once

class RendererHook
{
	struct D3DInitHook
	{
		static void                                    thunk();
		static inline REL::Relocation<decltype(thunk)> func;

		static constexpr auto id = RELOCATION_ID(75595, 77226);
		static constexpr auto offset = OFFSET(0x9, 0x275);

		static inline std::atomic<bool> initialized = false;
	};

public:
	void Install();


private:
	static inline REX::W32::ID3D11Device*        device = nullptr;
	static inline REX::W32::ID3D11DeviceContext* context = nullptr;
};
