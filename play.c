#include <windows.h>
#include <mmsystem.h>
#include <stdint.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 3) {
        return 1;
    }

    if (argc == 2) {
        // Reproducir directamente un archivo WAV
        const char *wavPath = argv[1];
        if (!PlaySoundA(wavPath, NULL, SND_FILENAME | SND_SYNC)) {
            return 1;
        }
        return 0;
    }

    // argc == 3, reproducir recurso dentro de DLL
    const char *dllPath = argv[1];
    int resId = atoi(argv[2]);

    HMODULE hMod = LoadLibraryA(dllPath);
    if (!hMod) return 1;

    if (!PlaySoundW((LPCWSTR)(uintptr_t)resId, hMod, SND_RESOURCE | SND_SYNC)) {
        FreeLibrary(hMod);
        return 1;
    }

    FreeLibrary(hMod);
    return 0;
}
