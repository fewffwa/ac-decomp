#include "ef_effect_control.h"
#include "m_common_data.h"

static void eSK_init(xyz_t pos, int prio, s16 angle, GAME* game, u16 item_name, s16 arg0, s16 arg1);
static void eSK_ct(eEC_Effect_c* effect, GAME* game, void* ct_arg);
static void eSK_mv(eEC_Effect_c* effect, GAME* game);
static void eSK_dw(eEC_Effect_c* effect, GAME* game);

eEC_PROFILE_c iam_ef_shock = {
    // clang-format off
    &eSK_init,
    &eSK_ct,
    &eSK_mv,
    &eSK_dw,
    eEC_IGNORE_DEATH,
    eEC_NO_CHILD_ID,
    eEC_DEFAULT_DEATH_DIST,
    // clang-format on
};

typedef struct Unk {
    f32 unk_00;
    f32 unk_04;
    f32 unk_08;
    f32 unk_0C;
    f32 unk_10;
    f32 unk_14;
    f32 unk_18;
} Unk;

static void eSK_init(xyz_t pos, int prio, s16 angle, GAME* game, u16 item_name, s16 arg0, s16 arg1) {
    Unk local_28;
    xyz_t local_34;
    
    local_28.unk_00 = 0.0f;
    local_28.unk_04 = 1.0f;
    local_28.unk_08 = 0.0f;
    local_28.unk_0C = 0.0f;
    local_28.unk_10 = -0.1f;
    local_28.unk_14 = 0.0f;
    local_28.unk_18 = 1.0f;
    
    local_34.x = 0.0;
    local_34.y = 4.0;
    local_34.z = 6.0;
    
    eEC_CLIP->make_effect_proc(0, pos, &local_34, game, &local_28, item_name, prio, 0,0) ;
}

static void eSK_ct(eEC_Effect_c* effect, GAME* game, void* ct_arg) {
    // TODO
}

static void eSK_mv(eEC_Effect_c* effect, GAME* game) {
    short temp = 14 - effect->timer;

    if (temp == 0) {
        sAdo_OngenTrgStart(45,&effect->position);
}
}

static void eSK_dw(eEC_Effect_c* effect, GAME* game) {
    // TODO
}
