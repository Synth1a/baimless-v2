#include <algorithm>
#include "kit_parser.h"
#include "Utils/Interfaces.h"
#include <iostream>
#include <string>
#include <fstream>
#include <Utils\Utils.h>
#include <codecvt>

std::vector<Kit_t> k_skins;
std::vector<Kit_t> k_gloves;
std::vector<Kit_t> k_stickers;

class CCStrike15ItemSchema;
class CCStrike15ItemSystem;

template <typename Key, typename Value>
struct Node_t
{
    int previous_id;		//0x0000
    int next_id;			//0x0004
    void* _unknown_ptr;		//0x0008
    int _unknown;			//0x000C
    Key key;				//0x0010
    Value value;			//0x0014
};

template <typename Key, typename Value>
struct Head_t
{
    Node_t<Key, Value>* memory;		//0x0000
    int allocation_count;			//0x0004
    int grow_size;					//0x0008
    int start_element;				//0x000C
    int next_available;				//0x0010
    int _unknown;					//0x0014
    int last_element;				//0x0018
}; //Size=0x001C

   // could use CUtlString but this is just easier and CUtlString isn't needed anywhere else
struct String_t
{
    char* buffer;	//0x0000
    int capacity;	//0x0004
    int grow_size;	//0x0008
    int length;		//0x000C
}; //Size=0x0010

struct CPaintKit
{
    int id;						//0x0000

    String_t name;				//0x0004
    String_t description;		//0x0014
    String_t item_name;			//0x0024
    String_t material_name;		//0x0034
    String_t image_inventory;	//0x0044

    char pad_0x0054[0x8C];		//0x0054
}; //Size=0x00E0

struct CStickerKit
{
    int id;

    int item_rarity;

    String_t name;
    String_t description;
    String_t item_name;
    String_t material_name;
    String_t image_inventory;

    int tournament_event_id;
    int tournament_team_id;
    int tournament_player_id;
    bool is_custom_sticker_material;

    float rotate_end;
    float rotate_start;

    float scale_min;
    float scale_max;

    float wear_min;
    float wear_max;

    String_t image_inventory2;
    String_t image_inventory_large;

    uint32_t pad0[4];
};

void InitializeKits()
{
    static std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;

    auto sig_address = Utils::PatternScan(GetModuleHandle("client.dll"), "E8 ?? ?? ?? ?? FF 76 0C 8D 48 04 E8");

    // Skip the opcode, read rel32 address
    auto item_system_offset = *reinterpret_cast<int32_t*>(sig_address + 1);

    // Add the offset to the end of the instruction
    auto item_system_fn = reinterpret_cast<CCStrike15ItemSystem * (*)()>(sig_address + 5 + item_system_offset);

    // Skip VTable, first member variable of ItemSystem is ItemSchema
    auto item_schema = reinterpret_cast<CCStrike15ItemSchema*>(uintptr_t(item_system_fn()) + sizeof(void*));

    // Dump paint kits
    {
        // Skip the instructions between, skip the opcode, read rel32 address
        auto get_paint_kit_definition_offset = *reinterpret_cast<int32_t*>(sig_address + 11 + 1);

        // Add the offset to the end of the instruction
        auto get_paint_kit_definition_fn = reinterpret_cast<CPaintKit * (__thiscall*)(CCStrike15ItemSchema*, int)>(sig_address + 11 + 5 + get_paint_kit_definition_offset);

        // Skip instructions, skip opcode, read offset
        auto start_element_offset = *reinterpret_cast<intptr_t*>(uintptr_t(get_paint_kit_definition_fn) + 8 + 2);

        // Calculate head base from start_element's offset
        auto head_offset = start_element_offset - 12;

        auto map_head = reinterpret_cast<Head_t<int, CPaintKit*>*>(uintptr_t(item_schema) + head_offset);

        for (int i = 0; i <= map_head->last_element; ++i)
        {
            auto paint_kit = map_head->memory[i].value;

            if (paint_kit->id == 9001)
                continue;

            const wchar_t* wide_name = g_Localize->Find(paint_kit->item_name.buffer + 1);
            auto name = converter.to_bytes(wide_name);

            if (paint_kit->id < 10000)
                k_skins.push_back({ paint_kit->id, name });
            else
                k_gloves.push_back({ paint_kit->id, name });
        }

        std::sort(k_skins.begin(), k_skins.end());
        std::sort(k_gloves.begin(), k_gloves.end());
    }
}


