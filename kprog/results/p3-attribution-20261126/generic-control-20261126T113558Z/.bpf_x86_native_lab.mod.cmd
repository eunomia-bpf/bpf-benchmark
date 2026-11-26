savedcmd_bpf_x86_native_lab.mod := printf '%s\n'   bpf_x86_native_lab.o | awk '!x[$$0]++ { print("./"$$0) }' > bpf_x86_native_lab.mod
