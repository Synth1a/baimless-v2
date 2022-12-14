#pragma once
#include <Windows.h>

typedef void*   (*CreateInterfaceFn)        (const char *pName, int *pReturnCode);
typedef void    (*pfnDemoCustomDataCallback)(unsigned char *pData, size_t iSize);




enum class MoveType_t
{
    MOVETYPE_NONE = 0,
    MOVETYPE_ISOMETRIC,
    MOVETYPE_WALK,
    MOVETYPE_STEP,
    MOVETYPE_FLY,
    MOVETYPE_FLYGRAVITY,
    MOVETYPE_VPHYSICS,
    MOVETYPE_PUSH,
    MOVETYPE_NOCLIP,
    MOVETYPE_LADDER,
    MOVETYPE_OBSERVER,
    MOVETYPE_CUSTOM,
    MOVETYPE_LAST = MOVETYPE_CUSTOM,
    MOVETYPE_MAX_BITS = 4
};

enum EntityFlags : int
{
    FL_ONGROUND =   (1 << 0),
    FL_DUCKING =    (1 << 1),
    FL_WATERJUMP =  (1 << 2),
    FL_ONTRAIN =    (1 << 3),
    FL_INRAIN =     (1 << 4),
    FL_FROZEN =     (1 << 5),
    FL_ATCONTROLS = (1 << 6),
    FL_CLIENT =     (1 << 7),
    FL_FAKECLIENT = (1 << 8)
};


enum class ItemDefinitionIndex : short
{
    WEAPON_NONE = 0,
    WEAPON_DEAGLE,
    WEAPON_ELITE,
    WEAPON_FIVESEVEN,
    WEAPON_GLOCK,
    WEAPON_AK47 = 7,
    WEAPON_AUG,
    WEAPON_AWP,
    WEAPON_FAMAS,
    WEAPON_G3SG1,
    WEAPON_GALIL = 13,
    WEAPON_M249,
    WEAPON_M4A4 = 16,
    WEAPON_MAC10,
    WEAPON_P90 = 19,
    WEAPON_MP5SD = 23,
    WEAPON_UMP45,
    WEAPON_XM1014,
    WEAPON_BIZON,
    WEAPON_MAG7,
    WEAPON_NEGEV,
    WEAPON_SAWEDOFF,
    WEAPON_TEC9,
    WEAPON_ZEUS,
    WEAPON_P2000,
    WEAPON_MP7,
    WEAPON_MP9,
    WEAPON_NOVA,
    WEAPON_P250,
    WEAPON_SHIELD,
    WEAPON_SCAR20,
    WEAPON_SG553,
    WEAPON_SSG08,
    WEAPON_KNIFEGG,
    WEAPON_KNIFE,
    WEAPON_FLASHBANG,
    WEAPON_HEGRENADE,
    WEAPON_SMOKEGRENADE,
    WEAPON_MOLOTOV,
    WEAPON_DECOY,
    WEAPON_INC,
    WEAPON_C4,
    WEAPON_HEALTHSHOT = 57,
    WEAPON_KNIFE_T = 59,
    WEAPON_M4A1S,
    WEAPON_USPS,
    WEAPON_CZ75 = 63,
    WEAPON_REVOLVER,
    WEAPON_TAGRENADE = 68,
    WEAPON_FISTS,
    WEAPON_BREACHCHARGE,
    WEAPON_TABLET = 72,
    WEAPON_MELEE = 74,
    WEAPON_AXE,
    WEAPON_HAMMER,
    WEAPON_SPANNER = 78,
    WEAPON_KNIFE_GHOST = 80,
    WEAPON_FIREBOMB,
    WEAPON_DIVERSION,
    WEAPON_FRAG_GRENADE,
    WEAPON_SNOWBALL,
    WEAPON_BUMPMINE,
    WEAPON_KNIFE_BAYONET = 500,
    WEAPON_KNIFE_CSS = 503,
    WEAPON_KNIFE_FLIP = 505,
    WEAPON_KNIFE_GUT,
    WEAPON_KNIFE_KARAMBIT,
    WEAPON_KNIFE_M9_BAYONET,
    WEAPON_KNIFE_TACTICAL,
    WEAPON_KNIFE_FALCHION = 512,
    WEAPON_KNIFE_SURVIVAL_BOWIE = 514,
    WEAPON_KNIFE_BUTTERFLY,
    WEAPON_KNIFE_PUSH = 516,
    WEAPON_KNIFE_CORD = 517,
    WEAPON_KNIFE_CANIS = 518,
    WEAPON_KNIFE_URSUS = 519,
    WEAPON_KNIFE_GYPSY_JACKKNIFE,
    WEAPON_KNIFE_OUTDOOR = 521,
    WEAPON_KNIFE_STILETTO = 522,
    WEAPON_KNIFE_WIDOWMAKER,
    WEAPON_KNIFE_SKELETON = 525,
    GLOVE_STUDDED_BLOODHOUND = 5027,
    GLOVE_T_SIDE = 5028,
    GLOVE_CT_SIDE = 5029,
    GLOVE_SPORTY = 5030,
    GLOVE_SLICK = 5031,
    GLOVE_LEATHER_WRAP = 5032,
    GLOVE_MOTORCYCLE = 5033,
    GLOVE_SPECIALIST = 5034,
    GLOVE_HYDRA = 5035
};



enum class CSWeaponType : int
{
    WEAPONTYPE_KNIFE = 0,
    WEAPONTYPE_PISTOL,
    WEAPONTYPE_SUBMACHINEGUN,
    WEAPONTYPE_RIFLE,
    WEAPONTYPE_SHOTGUN,
    WEAPONTYPE_SNIPER_RIFLE,
    WEAPONTYPE_MACHINEGUN,
    WEAPONTYPE_C4,
    WEAPONTYPE_PLACEHOLDER,
    WEAPONTYPE_GRENADE,
    WEAPONTYPE_UNKNOWN
};

class WeaponInfo_t
{
public:
    char pad_0000[4]; //0x0000
    char* ConsoleName; //0x0004
    char pad_0008[12]; //0x0008
    int max_clip; //0x0014
    char pad_0018[12]; //0x0018
    int iMaxClip2; //0x0024
    char pad_0028[4]; //0x0028
    char* szWorldModel; //0x002C
    char* szViewModel; //0x0030
    char* szDropedModel; //0x0034
    char pad_0038[4]; //0x0038
    char* N00000984; //0x003C
    char pad_0040[56]; //0x0040
    char* szEmptySound; //0x0078
    char pad_007C[4]; //0x007C
    char* szBulletType; //0x0080
    char pad_0084[4]; //0x0084
    char* hud_name; //0x0088
    char* weapon_name; //0x008C
    char pad_0090[60]; //0x0090
    int type; //0x00CC
    int iWeaponPrice; //0x00D0
    int iKillAward; //0x00D4
    char* szAnimationPrefex; //0x00D8
    float flCycleTime; //0x00DC
    float flCycleTimeAlt; //0x00E0
    float flTimeToIdle; //0x00E4
    float flIdleInterval; //0x00E8
    bool bFullAuto; //0x00EC
    char pad_00ED[3]; //0x00ED
    int damage; //0x00F0
    float headshotmultiplyier;
    float armor_ratio; //0x00F4
    int iBullets; //0x00F8
    float penetration; //0x00FC
    float flFlinchVelocityModifierLarge; //0x0100
    float flFlinchVelocityModifierSmall; //0x0104
    float range; //0x0108
    float range_modifier; //0x010C
    char pad_0110[28]; //0x0110
    int iCrosshairMinDistance; //0x012C
    float flMaxPlayerSpeed; //0x0130
    float max_speed_alt; //0x0134
    char pad_0138[4]; //0x0138
    float flSpread; //0x013C
    float flSpreadAlt; //0x0140
    float flInaccuracyCrouch; //0x0144
    float flInaccuracyCrouchAlt; //0x0148
    float flInaccuracyStand; //0x014C
    float flInaccuracyStandAlt; //0x0150
    float flInaccuracyJumpIntial; //0x0154
    float flInaccaurcyJumpApex;
    float flInaccuracyJump; //0x0158
    float flInaccuracyJumpAlt; //0x015C
    float flInaccuracyLand; //0x0160
    float flInaccuracyLandAlt; //0x0164
    float flInaccuracyLadder; //0x0168
    float flInaccuracyLadderAlt; //0x016C
    float flInaccuracyFire; //0x0170
    float flInaccuracyFireAlt; //0x0174
    float flInaccuracyMove; //0x0178
    float flInaccuracyMoveAlt; //0x017C
    float flInaccuracyReload; //0x0180
    int iRecoilSeed; //0x0184
    float flRecoilAngle; //0x0188
    float flRecoilAngleAlt; //0x018C
    float flRecoilVariance; //0x0190
    float flRecoilAngleVarianceAlt; //0x0194
    float flRecoilMagnitude; //0x0198
    float flRecoilMagnitudeAlt; //0x019C
    float flRecoilMagnatiudeVeriance; //0x01A0
    float flRecoilMagnatiudeVerianceAlt; //0x01A4
    float flRecoveryTimeCrouch; //0x01A8
    float flRecoveryTimeStand; //0x01AC
    float flRecoveryTimeCrouchFinal; //0x01B0
    float flRecoveryTimeStandFinal; //0x01B4
    int iRecoveryTransititionStartBullet; //0x01B8
    int iRecoveryTransititionEndBullet; //0x01BC
    bool bUnzoomAfterShot; //0x01C0
    char pad_01C1[31]; //0x01C1
    char* szWeaponClass; //0x01E0
    char pad_01E4[56]; //0x01E4
    float flInaccuracyPitchShift; //0x021C
    float flInaccuracySoundThreshold; //0x0220
    float flBotAudibleRange; //0x0224
    char pad_0228[12]; //0x0228
    bool bHasBurstMode; //0x0234
};// Size=0x01A8
