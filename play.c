#include <windows.h>
#include <mmsystem.h>
#include <stdint.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        return 1;
    }

    const char *dllPath = argv[1];
    int resId = atoi(argv[2]);

    HMODULE hMod = LoadLibraryA(dllPath);
    if (!hMod) return 1;

    PlaySoundW((LPCWSTR)(uintptr_t)resId, hMod, SND_RESOURCE | SND_SYNC);

    FreeLibrary(hMod);
    return 0;
}
