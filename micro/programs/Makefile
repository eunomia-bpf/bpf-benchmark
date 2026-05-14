DEB_HOST_MULTIARCH := $(shell gcc -print-multiarch 2>/dev/null || dpkg-architecture -qDEB_HOST_MULTIARCH 2>/dev/null)
SYS_INCLUDE_FLAGS := $(if $(DEB_HOST_MULTIARCH),-I/usr/include/$(DEB_HOST_MULTIARCH))
OUTPUT_DIR ?= $(CURDIR)
CLANG ?= clang

CFLAGS := -Wall -Wextra -O2 -g -target bpf $(SYS_INCLUDE_FLAGS) -MMD -MP
NATIVE_CFLAGS := -Wall -Wextra -O2 -g -fPIC -shared -DMICRO_NATIVE $(SYS_INCLUDE_FLAGS) -MMD -MP

BPF_SRCS := $(wildcard *.bpf.c)
BPF_OBJS := $(patsubst %.bpf.c,$(OUTPUT_DIR)/%.bpf.o,$(BPF_SRCS))
BPF_DEPS := $(patsubst %.bpf.c,$(OUTPUT_DIR)/%.bpf.d,$(BPF_SRCS))
NATIVE_SOS := $(patsubst %.bpf.c,$(OUTPUT_DIR)/%.native.so,$(BPF_SRCS))
NATIVE_DEPS := $(patsubst %.bpf.c,$(OUTPUT_DIR)/%.native.d,$(BPF_SRCS))

.PHONY: all clean

all: $(BPF_OBJS) $(NATIVE_SOS)

$(OUTPUT_DIR)/%.bpf.o: %.bpf.c | $(OUTPUT_DIR)
	$(CLANG) $(CFLAGS) -MF "$(OUTPUT_DIR)/$*.bpf.d" -MT "$@" -c -o "$@" "$<"

$(OUTPUT_DIR)/%.native.so: %.bpf.c | $(OUTPUT_DIR)
	$(CLANG) $(NATIVE_CFLAGS) -MF "$(OUTPUT_DIR)/$*.native.d" -MT "$@" -o "$@" "$<"

$(OUTPUT_DIR):
	mkdir -p "$@"

clean:
	rm -f \
		"$(OUTPUT_DIR)"/*.bpf.o \
		"$(OUTPUT_DIR)"/*.bpf.d \
		"$(OUTPUT_DIR)"/*.native.so \
		"$(OUTPUT_DIR)"/*.native.d \
		"$(OUTPUT_DIR)"/*.bpf.bin \
		"$(OUTPUT_DIR)"/*.directive.bin \
		"$(OUTPUT_DIR)"/*.policy.bin

-include $(BPF_DEPS) $(NATIVE_DEPS)
