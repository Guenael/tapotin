# tapotin

![tapotin](https://github.com/guenael/tapotin/art/tapotin-pcb.png)
![Last commit](https://img.shields.io/github/last-commit/Guenael/tapotin)
![Commit activity](https://img.shields.io/github/commit-activity/m/Guenael/tapotin)

***WORK IN PROGRESS***

# Description

Tapotin is a simple 42-keys ortho-linear keyboard, based on QMK driver and a Raspberry Pico (RP2040). The design is heavily inspired by the community, specially by [Pi5Keyboard](https://github.com/luke-schutt/Pi5Keyboard) and [chocV](https://github.com/brickbots/chocV) projects.

Kicad was used for the PCB design, and it was a nice project to switch from professional tools to a community/free PCB editor. For this first version, I used a RPi Pico board, but I plan to solder the RP2040 directly on the main PCB if I like this new keyboard.

# My requirements

- [QMK](https://qmk.fm/) based
- [RP2040](https://en.wikipedia.org/wiki/RP2040) based
- Mono-block (non-split keyboard, I tried it, and I don't like it)
- [Ortholinear](https://en.wiktionary.org/wiki/ortholinear) (offset only for the pinky)
- Left/right clear separation
- Angle 2x 10°
- 42 keys: 2*((3*6)+3)
- [Miryoku](https://github.com/manna-harbour/miryoku) layout based
- PCB specs:
  - Base/solder : 1.6mm
  - Keys plate  : 1.2mm

# Assembly

The RPi Pico board is soldered up-side down, and touch both PCB (main & key plate)

# My layout 

Here there be dragons... 20 years ago, I designed my own version of a [Dvorak layout](https://en.wikipedia.org/wiki/Dvorak_keyboard_layout), that include some requirements around programming, and accents. I like it, and I have to go all in one more time, because after 20 years, there is no way back :)

I really liked the concept of [Miryoku](https://github.com/manna-harbour/miryoku) keyboard, so I created my own version based on my custom Dvorak. One of the main difference with the original Miryoku design is that I keep an extra column for the pinky, for 3D/CAD applications with a direct access to some meta keys.

Note: Do not follow my layout, it's very specific, but if your are curious, you can check this page full of references and ideas: [Best layouts](https://www.keyboard-design.com/best-layouts.html) 

# QMK section

## Bootloader

Enter the bootloader mode by holding the RP2040 reset button down while plugging it in.

## Build

Make example for this keyboard (after setting up your build environment):

    make tapotin:default

Flashing example for this keyboard:

    make tapotin:default:flash

## Documentation

- [Build environment setup](https://docs.qmk.fm/#/getting_started_build_tools)
- [Make instructions](https://docs.qmk.fm/#/getting_started_make_guide)
- [QMK Guide](https://docs.qmk.fm/#/newbs)
