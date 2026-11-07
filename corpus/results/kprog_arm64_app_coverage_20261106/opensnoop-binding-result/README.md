# Opensnoop actual ARM binding failure identified

The same complete BCC package and matched published kernel/other ten modules
were rerun with a private diagnostic native_lab module. Its only change is one
error print on the existing missing-relocation rejection; acceptance is unchanged.

The diagnostic identifies chunk0/relocation0/kind2/offset32, matching the
memset CALL26 at native proof offset0x20. The simulator expands libc memset into
writes, while the module requires a real BPF helper invocation for this external
native relocation. There is no BPF helper invocation to the kernel memset target.

The prior opensnoop EINVAL is therefore an external-libc binding mismatch,
rather than a demonstrated stack rejection. All program attempts and app errors
are retained; this run does not establish application completion.

The repair uses ordinary local native ELF byte-loop memset, as already used on
x86. Then native and proof contain the same real instruction body, with normal
call/return and byte-write semantics. No binding rule is relaxed and no proof-only
libc exception is introduced. The subsequent embedded-libc result records its
CPU controls and fresh all23 BCC proof builds.

The diagnostic source/module, complete raw module build and actual QEMU app run,
per-program requests/replacements/counters and original proof relocations remain.
The exact unchanged BCC payload is in ../runtime-context-v27/.

The multiline raw application error CSV is gzip-preserved as app-outcomes.csv.gz.
