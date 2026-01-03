# TiR Langs

The mod allow to set up a custom language, which is not supported in the original game.

## Installation

- Make sure you have the Nestle Edition v1.3 of the game, as this is the only version this plugin is compatible with. (exe size of 1366016 bytes)
- Plop the files into your game folder, edit `TIRLangs_gcp.toml` to change the options to your liking.

## Feature List

- Change language of a mechanic audio
- Change in-game language files
- Change font (needed for a non-Latin language)

## Building

Building is done on an Arch Linux system with Qt Creator and vcpkg being used for the build process. 

Before you begin, clone [nya-common](https://github.com/gaycoderprincess/nya-common) to a folder next to this one, so it can be found.

Required packages: `mingw-w64-gcc vcpkg`

To install all dependencies, use:
```console
vcpkg install tomlplusplus:x86-mingw-static
```

Once installed, copy files from `~/.vcpkg/vcpkg/installed/x86-mingw-static/`:

- `include` dir to `nya-common/3rdparty`
- `lib` dir to `nya-common/lib32`

You should be able to build the project now in Qt Creator.
