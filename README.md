<<<<<<< HEAD
# my_first_vscode_pico - Raspberry Pi Pico Project

## Building
```bash
mkdir build
cd build
cmake ..
make -j4
```

## Flashing
1. Hold BOOTSEL button on Pico while plugging in USB
2. Copy `my_first_vscode_pico.uf2` to RPI-RP2 drive:
   ```bash
   cp my_first_vscode_pico.uf2 /media/$USER/RPI-RP2/
   ```

## Serial Output
```bash
picocom -b 115200 /dev/ttyACM0
```
=======
# Pico_Project-
my pico project for a remote 
>>>>>>> origin/main
