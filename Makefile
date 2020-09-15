AS = aarch64-none-elf-as
CXX = aarch64-none-elf-g++
CXXFLAGS = -ffreestanding -O2 -Wall -Wextra -Isrc

QEMU = qemu-system-aarch64
QEMUFLAGS = -M raspi3 -no-reboot -monitor stdio -d int -no-shutdown 

CXX_SRC = $(shell find . -type f -name '*.cpp')

build:
	mkdir -p Bin
	$(CXX) $(CXXFLAGS) $(CXX_SRC) -c
	mv *o Bin
	$(CXX) -ffreestanding -O2 -nostdlib Bin/*.o -lgcc -T linker.ld -o Bin/kernel.elf
	aarch64-none-elf-objcopy Bin/kernel.elf -O binary kernel8.img
qemu: build
	$(QEMU) $(QEMUFLAGS) -kernel kernel8.img
