# ortho4x12 handwired

Custom handwired ortho5x13 keyboard.

Keyboard Maintainer: [Danny](https://github.com/nooges)  
Hardware Supported: Custom handwired 5x13 ortho keyboard  
Hardware Availability: 

Make example for this keyboard (after setting up your build environment):

    make handwired/ortho4x12:default

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Flashing
1. Get device into bootloader by pressing the reset key (Should be Rise + Lower + Esc)
2. Run `sudo make handwired/ortho4x12:default:dfu`. This should compile and upload the new firmware to the keyboard
