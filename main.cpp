#include <windows.h>
#include "nya_commonhooklib.h"
#include "toml++/toml.hpp"

const char *langNameRaw = 0;
std::string langName;

const char *tlateFileRaw = 0;
std::string tlateFile;
const char *tmanFileRaw = 0;
std::string tmanFile;
const char *fontDataRaw = 0;
std::string fontData;
const char *fontBaseRaw = 0;
std::string fontBase;

uintptr_t Call406690= 0x406690;

void __attribute__((naked)) ReturnLanguageName() {
    __asm__ (
        "mov eax, %0\n\t"
        "ret\n\t"
        :
        : "m" (langNameRaw)
    );
}

void __attribute__((naked)) ReturnTlateLang() {
    __asm__ (
        "mov eax, %0\n\t"
        "pop edx\n\t"
        "pop ecx\n\t"
        "pop ebx\n\t"
        "ret\n\t"
        :
        : "m" (tlateFileRaw)
    );
}

uintptr_t ReturnTmanLang_Call401190 = 0x401190;
uintptr_t ReturnTmanLang_RetAddress = 0x4E7F28;
void __attribute__((naked)) ReturnTmanLang() {
    __asm__ (
        "mov eax, %0\n\t"
        "call %1\n\t"
        "jmp %2\n\t"
        :
        : "m" (tmanFileRaw), "m" (ReturnTmanLang_Call401190), "m" (ReturnTmanLang_RetAddress)
    );
}

uintptr_t ReturnFontData1_Call406A20 = 0x406A20;
uintptr_t ReturnFontData1_RetAddress = 0x418557;
void __attribute__((naked)) ReturnFontData1() {
    __asm__ (
        "mov eax, %0\n\t"
        "call %1\n\t"
        "jmp %2\n\t"
        :
        : "m" (fontDataRaw), "m" (ReturnFontData1_Call406A20), "m" (ReturnFontData1_RetAddress)
    );
}

uintptr_t ReturnFontData2_RetAddress = 0x4194F9;
void __attribute__((naked)) ReturnFontData2() {
    __asm__ (
        "mov eax, %0\n\t"
        "call %1\n\t"
        "jmp %2\n\t"
        :
        : "m" (fontDataRaw), "m" (ReturnFontData1_Call406A20), "m" (ReturnFontData2_RetAddress)
    );
}

uintptr_t ReturnFontBase1_RetAddress = 0x418451;
void __attribute__((naked)) ReturnFontBase1() {
    __asm__ (
        "mov eax, %0\n\t"
        "mov esi, 0x0FFFFFFFF\n\t"
        "jmp %1\n\t"
        :
        : "m" (fontBaseRaw), "m" (ReturnFontBase1_RetAddress)
    );
}

uintptr_t ReturnFontBase2_RetAddress = 0x418470;
void __attribute__((naked)) ReturnFontBase2() {
    __asm__ (
        "mov eax, %0\n\t"
        "mov ecx, 0x0A8\n\t"
        "jmp %1\n\t"
        :
        : "m" (fontBaseRaw), "m" (ReturnFontBase2_RetAddress)
    );
}

uintptr_t ReturnFontBase3_RetAddress = 0x418484;
void __attribute__((naked)) ReturnFontBase3() {
    __asm__ (
        "xor ecx, ecx\n\t"
        "xor edx, edx\n\t"
        "mov eax, %0\n\t"
        "jmp %1\n\t"
        :
        : "m" (fontBaseRaw), "m" (ReturnFontBase3_RetAddress)
    );
}

uintptr_t ReturnFontBase4_RetAddress = 0x41853E;
void __attribute__((naked)) ReturnFontBase4() {
    __asm__ (
        "mov eax, %0\n\t"
        "xor ecx, ecx\n\t"
        "xor ebx, ebx\n\t"
        "xor edx, edx\n\t"
        "jmp %1\n\t"
        :
        : "m" (fontBaseRaw), "m" (ReturnFontBase4_RetAddress)
    );
}

uintptr_t ReturnFontBase5_RetAddress = 0x4195D3;
void __attribute__((naked)) ReturnFontBase5() {
    __asm__ (
        "mov eax, %0\n\t"
        "mov ebx, 0x0A8\n\t"
        "xor edx, edx\n\t"
        "call %1\n\t"
        "div ebx\n\t"
        "xor ecx, ecx\n\t"
        "mov esi, eax\n\t"
        "xor ebx, ebx\n\t"
        "xor edx, edx\n\t"
        "mov eax, %0\n\t"
        "jmp %2\n\t"
        :
        : "m" (fontBaseRaw), "m" (Call406690), "m" (ReturnFontBase5_RetAddress)
    );
}

uintptr_t ReturnFontBase6_RetAddress = 0x4194E2;
void __attribute__((naked)) ReturnFontBase6() {
    __asm__ (
        "mov [ebp-0x168], eax\n\t"
        "mov eax, %0\n\t"
        "jmp %1"
        :
        : "m" (fontBaseRaw), "m" (ReturnFontBase6_RetAddress)
    );
}

uintptr_t ReturnFontBase7_RetAddress = 0x4194C5;
void __attribute__((naked)) ReturnFontBase7() {
    __asm__ (
        "mov [ebp-0x188], eax\n\t"
        "mov eax, %0\n\t"
        "jmp %1"
        :
        : "m" (fontBaseRaw), "m" (ReturnFontBase7_RetAddress)
    );
}

uintptr_t Setup406690_RetAddress = 0x41964A;
void __attribute__((naked)) Setup406690() {
    __asm__ (
        "mov eax, %0\n\t"
        "call %2\n\t"
        "mov eax, %1\n\t"
        "mov edx, 0x501F64\n\t"
        "call %2\n\t"
        "mov [ebp-0x168], eax\n\t"
        "mov eax, %0\n\t"
        "jmp %3"
        :
        : "m" (fontBaseRaw), "m" (fontDataRaw), "m" (Call406690), "m" (Setup406690_RetAddress)
    );
}

BOOL WINAPI DllMain(HINSTANCE, DWORD fdwReason, LPVOID) {
    switch( fdwReason ) {
        case DLL_PROCESS_ATTACH: {
            if (NyaHookLib::GetEntryPoint() != 0xEF6C2) {
                MessageBoxA(nullptr, "Unsupported game version! Make sure you're using Nestle Edition v1.3 (.exe size of 1366016 bytes)", "Well...", MB_ICONERROR);
                return TRUE;

            }

            auto config = toml::parse_file("TIRLangs_gcp.toml");
            langName = config["audio"]["lang"].value_or("ENGLISH");
            tlateFile = config["text"]["tlate"].value_or("language/tlate_en.dat");
            tmanFile = config["text"]["tman"].value_or("language/tman_en.dat");
            fontData = config["font"]["fontdata"].value_or("fonts/fontdata.dat");
            fontBase = config["font"]["fontbase"].value_or("fonts/fontbase.dat");

            langNameRaw = langName.c_str();
            tlateFileRaw = tlateFile.c_str();
            tmanFileRaw = tmanFile.c_str();
            fontDataRaw = fontData.c_str();
            fontBaseRaw = fontBase.c_str();

            NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x4AFA03, &ReturnLanguageName);
            NyaHookLib::PatchRelative(NyaHookLib::JMP, 0x493255, &ReturnTlateLang);
            NyaHookLib::PatchRelative(NyaHookLib::JMP, 0x4E7F1E, &ReturnTmanLang);

            NyaHookLib::PatchRelative(NyaHookLib::JMP, 0x41854D, &ReturnFontData1);
            NyaHookLib::PatchRelative(NyaHookLib::JMP, 0x4194EF, &ReturnFontData2);

            NyaHookLib::PatchRelative(NyaHookLib::JMP, 0x418447, &ReturnFontBase1);
            NyaHookLib::PatchRelative(NyaHookLib::JMP, 0x418466, &ReturnFontBase2);
            NyaHookLib::PatchRelative(NyaHookLib::JMP, 0x41847B, &ReturnFontBase3);
            NyaHookLib::PatchRelative(NyaHookLib::JMP, 0x418533, &ReturnFontBase4);
            NyaHookLib::PatchRelative(NyaHookLib::JMP, 0x4194BA, &ReturnFontBase7);
            NyaHookLib::PatchRelative(NyaHookLib::JMP, 0x4194D7, &ReturnFontBase6);
            NyaHookLib::PatchRelative(NyaHookLib::JMP, 0x4195B3, &ReturnFontBase5);

            NyaHookLib::PatchRelative(NyaHookLib::JMP, 0x419626, &Setup406690);
        } break;
        default:
            break;
    }
    return TRUE;
}
