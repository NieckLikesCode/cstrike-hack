#include "hooked.h"

bool hooked::setup( ) {

	m_console.log( "hooking functions..." );

	m_detour.setup( "C_BasePlayer::CreateMove", m_signatures.m_create_move, &create_move );

	m_detour.setup( "C_EngineVGui::Paint", m_signatures.m_paint, &paint );

	m_detour.setup( "ClientModeShared::GetViewModelFOV", m_signatures.m_get_view_model_fov, &get_view_model_fov );

	m_detour.setup( "C_WeaponCSBase::DrawCrosshair", m_signatures.m_draw_crosshair, &draw_crosshair );

	m_detour.setup( "CCSGOPlayerAnimState::Update", m_signatures.m_update, &update );

	m_detour.setup( "CCSGOPlayerAnimState::ModifyEyePosition", m_signatures.m_modify_eye_position, &modify_eye_position );

	m_detour.setup( "CCSGOPlayerAnimState::DoProceduralFootPlant", m_signatures.m_do_procedural_foot_plant, &do_procedural_foot_plant );

	m_detour.setup( "CCSGOPlayerAnimState::SetUpVelocity", m_signatures.m_setup_velocity, &set_up_velocity );

	m_detour.setup( "CCSGOPlayerAnimState::SetUpMovement", m_signatures.m_setup_movement, &set_up_movement );

	m_console.log( "hooked functions" );

	return true;

}

void hooked::unload( ) {

	m_detour.unload( );

}