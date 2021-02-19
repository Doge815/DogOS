kernel_source_files := $(shell find src/source/kernel -name *.c)
kernel_object_files := $(patsubst src/source/kernel/%.c, build/kernel/%.o, $(kernel_source_files))

x86_64_std_source_files := $(shell find src/source/x86_64 -name *.c)
x86_64_std_object_files := $(patsubst src/source/x86_64/%.c, build/x86_64/%.o, $(x86_64_std_source_files))

x86_64_asm_source_files := $(shell find src/source/x86_64 -name *.asm)
x86_64_asm_object_files := $(patsubst src/source/x86_64/%.asm, build/x86_64/%.o, $(x86_64_asm_source_files))

x86_64_object_files := $(x86_64_std_object_files) $(x86_64_asm_object_files)

$(kernel_object_files): build/kernel/%.o : src/source/kernel/%.c
	mkdir -p $(dir $@) && \
	x86_64-elf-gcc -c -I src/intf -ffreestanding $(patsubst build/kernel/%.o, src/source/kernel/%.c, $@) -o $@

$(x86_64_std_object_files): build/x86_64/%.o : src/source/x86_64/%.c
	mkdir -p $(dir $@) && \
	x86_64-elf-gcc -c -I src/intf -ffreestanding $(patsubst build/x86_64/%.o, src/source/x86_64/%.c, $@) -o $@

$(x86_64_asm_object_files): build/x86_64/%.o : src/source/x86_64/%.asm
	mkdir -p $(dir $@) && \
	nasm -f elf64 $(patsubst build/x86_64/%.o, src/source/x86_64/%.asm, $@) -o $@

.PHONY: build-x86_64
build-x86_64: $(kernel_object_files) $(x86_64_object_files)
	mkdir -p x86_64 && \
	x86_64-elf-ld -n -o x86_64/kernel.bin -T targets/x86_64/linker.ld $(kernel_object_files) $(x86_64_object_files) && \
	cp x86_64/kernel.bin targets/x86_64/iso/boot/kernel.bin && \
	grub-mkrescue /usr/lib/grub/i386-pc -o x86_64/kernel.iso targets/x86_64/iso
