ifeq ($(V),1)
VERBOSE=-v
else
VERBOSE=
endif

ifeq ($(D),1)
DIAGNOSIS=-D
else
DIAGNOSIS=
endif

.PHONY: build

build: 
	@xmake --build $(VERBOSE) $(DIAGNOSIS) $(TARGET)

rebuild: 
	@xmake --rebuild $(VERBOSE) $(DIAGNOSIS) $(TARGET)

install: 
	@xmake install $(VERBOSE) $(DIAGNOSIS) $(TARGET)

uninstall: 
	@xmake uninstall $(VERBOSE) $(DIAGNOSIS) $(TARGET)

package: 
	@xmake package $(VERBOSE) $(DIAGNOSIS) $(TARGET)

clean: 
	@xmake clean $(VERBOSE) $(DIAGNOSIS) $(TARGET)

run: 
	@xmake run $(VERBOSE) $(DIAGNOSIS) $(TARGET)

debug: 
	@xmake run -d $(VERBOSE) $(DIAGNOSIS) $(TARGET)

ifneq ($(PLAT),)
ifneq ($(ARCH),)
ifneq ($(MODE),)
CONFIG=xmake config -c $(VERBOSE) $(DIAGNOSIS) -p $(PLAT) -a $(ARCH) -m $(MODE) $(TARGET)
else
CONFIG=xmake config -c $(VERBOSE) $(DIAGNOSIS) -p $(PLAT) -a $(ARCH) $(TARGET)
endif
else
CONFIG=xmake config -c $(VERBOSE) $(DIAGNOSIS) -p $(PLAT) $(TARGET)
endif
else
CONFIG=xmake config -c $(VERBOSE) $(DIAGNOSIS) $(TARGET)
endif
config: 
	@$(CONFIG)

