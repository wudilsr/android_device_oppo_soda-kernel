VERSION = 4
PATCHLEVEL = 19

headers_install:
	@mkdir -p $(O)/usr/include
	@rsync -mrq --exclude='.internal-backup' $(shell pwd)/* $(O)/usr/include

all:
	@true

