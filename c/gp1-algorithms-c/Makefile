
.PHONY: update_gplib

externals/libs/windows_x64:
	mkdir -p $@

externals/bin/windows_x64:
	mkdir -p $@

externals/libs/linux_x64:
	mkdir -p $@

externals/bin/linux_x64:
	mkdir -p $@

externals/include/gp/gplib.h: ~/dev/gplib/include/gp/gplib.h
	cp $< $@

externals/libs/windows_x64/libgpdll.a: ~/dev/gplib/libgpdll.a | externals/libs/windows_x64
	cp $< $@

externals/bin/windows_x64/libgp.dll: ~/dev/gplib/libgp.dll | externals/libs/windows_x64
	cp $< $@

externals/bin/linux_x64/libgp.so: ~/dev/gplib/libgp.so | externals/bin/linux_x64
	cp $< $@

ifeq ($(PLATFORM),windows_x64)
update_gplib: externals/include/gp/gplib.h externals/libs/windows_x64/libgpdll.a externals/bin/windows_x64/libgp.dll
else
update_gplib: externals/include/gp/gplib.h externals/bin/linux_x64/libgp.so
endif

