VERSION = 4
PATCHLEVEL = 19
SUBLEVEL = 152

headers_install:
	@mkdir -p $(O)/usr/include
	@rsync -mrq --exclude=Makefile $(shell pwd)/* $(O)/usr/include

all:
	@echo "kernel-headers is a UAPI stub, not a buildable kernel tree." >&2
	@echo "Keep TARGET_FORCE_PREBUILT_KERNEL := true in BoardConfig.mk, or" >&2
	@echo "point TARGET_KERNEL_SOURCE at a real kernel source tree." >&2
	@exit 1
