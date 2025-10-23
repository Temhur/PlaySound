#include <windows.h>
#include <mmsystem.h>
#include <stdint.h>

#pragma comment(lib, "winmm.lib")

int main() {
    HMODULE hMod = LoadLibraryW(L"C:\\Windows\\System32\\imageres.dll");
    if (!hMod) return 1;

    // Recurso WAV 5080
    uintptr_t resId = 5080;
    PlaySoundW((LPCWSTR)resId, hMod, SND_RESOURCE | SND_SYNC);

    FreeLibrary(hMod);
    return 0;
}
