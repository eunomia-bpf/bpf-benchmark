# Probe-read wrappers as C in checked-sim-c LTO

Inline the kernel's bpf_probe_read_user/kernel common wrappers around its own
copy_from_user_nofault/copy_from_kernel_nofault. Preserve u32 size, int result
sign extension, and full destination zeroing on a negative result. Address
policy, SMAP, pagefault state, fault recovery and user/NMI restrictions remain
inside those existing kernel copy functions. Compat and string helpers retain
their existing calls. B and its helper calls remain unchanged.

The compiler records the selected C helper names. The native compilation links
only a needed C module before O3; the loader binds the two copy symbols through
its existing kallsyms/link-plan mechanism. No runtime selector or new check.

run.sh replaces the sole checked compiler tools and loader in place under
timing SH/image EX on CPU19. The local Makefile tests native wrapper execution,
u32 truncation, partial-copy error zeroing and surrounding bytes, retained
compat calls, and four actual proof/kernel links using the one kernel's symbols.
Host callbacks test the wrapper contract; they do not execute kernel copy code.
App performance and actual kernel copies await OMP's combined LTO batch.
