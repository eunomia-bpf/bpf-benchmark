# Native code now against the 2026-05-29 build

Operator 2026-11-15 ~22:59 UTC: "旧路线（编译过程里改写 IR，你后来禁止了）头文件路线 应该性能是一样的.  你要不要对比之前的版本?"

`compare_code.py` compares the executable sections (SHF_EXECINSTR PROGBITS, relocations unapplied) of every
`*.native.o` in the image payload `vendor/build/native-bpf/x86/stage/<app>` with the 2026-05-29 build kept at
`/workspaces/kprog-raw/paper-tree-untracked/vendor/build/native-bpf/x86/stage/<app>`, and Katran's timed
header-route object and the 2026-11-14 map-sink object with the 05-29 one. Output: `result.txt`.

Measured 2026-11-15T23:14:37Z:

- Katran balancer is byte-identical to 05-29 (xdp 7,965 B, .text 319 B); 3 of 4 Katran objects identical.
- BCC 7 of 8 identical (biosnoop 1,293 -> 1,307 B); Cilium 5 of 7 (bpf_xdp 23,964 -> 24,214 B, bpf_lxc same size, other bytes); OTel identical.
- Tracee 3 of 3 differ (1,615,175 -> 1,457,903 B); Tetragon's 88 objects are new after 05-29.
- The 2026-11-14 map-sink object (IR rewrite in the compile, removed on the operator's order) is 7,535 B and differs from 05-29.

So Katran's change from the 05-29 floor (1.113x, stats off) to about 1.03x comes after P: linker LTO, loader, kernel or the timing method.
