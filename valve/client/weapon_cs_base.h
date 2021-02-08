#pragma once

#include "base_entity.h"

struct cs_weapon_info {

	char _pad0[ 0x88 ];
	const char* m_hud_name;
	char _pad1[ 0x3c ];
	int m_weapon_type;

};

struct weapon_cs_base : base_entity {

	inline auto get_max_speed( ) {

		return m_utils.get_v_func< float( __thiscall* )( void* ) >( this, 441 )( this );

	}

	inline auto get_cs_wpn_data( ) {

		return m_utils.get_v_func< cs_weapon_info* ( __thiscall* )( void* ) >( this, 460 )( this ); // 8B 81 ? ? ? ? 85 C0 0F 84 ? ? ? ? C3

	}

};