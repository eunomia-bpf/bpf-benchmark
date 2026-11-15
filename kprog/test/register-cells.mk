ROOT := /workspaces/repository
FORMAL := $(ROOT)/kprog/formal
# Reuse these existing products rather than keeping a second oracle build.
BUILD := $(FORMAL)/build
INCLUDES := -I$(FORMAL) -I$(ROOT)/kprog/x86 -I$(ROOT)/kprog -I$(ROOT)/vendor/libbpf/include/uapi -I$(ROOT)/vendor/libbpf/src
CFLAGS := -O2 -Wall -Wextra -fsanitize=undefined -fno-sanitize-recover=undefined
.PHONY: host
host:
	install -d $(BUILD)
	$(CC) $(CFLAGS) $(INCLUDES) $(FORMAL)/oracles/test_x86_reg_dispatch_route_host.c -o $(BUILD)/test_x86_reg_dispatch_route_host
	$(BUILD)/test_x86_reg_dispatch_route_host
	$(CC) $(CFLAGS) $(INCLUDES) -include $(FORMAL)/oracles/arm64_entry_environment_host.h -DKPROG_TEST_EXCLUSIVE_FAILURE=0 -include $(FORMAL)/oracles/arm64_exclusive_choice_host.h $(FORMAL)/oracles/x86_route_host.c -o $(BUILD)/x86_route_host
	$(BUILD)/x86_route_host
	$(CC) $(CFLAGS) $(INCLUDES) -c $(FORMAL)/c/X86Pointer.c -o $(BUILD)/x86_pointer_binding.o
	$(CC) $(CFLAGS) $(INCLUDES) -DPROFILE=64 -DSCALAR_FACTS=1 $(FORMAL)/oracles/test_x86_storage_profile_host.c $(BUILD)/x86_pointer_binding.o -o $(BUILD)/test_x86_storage_profile_host
	$(BUILD)/test_x86_storage_profile_host
