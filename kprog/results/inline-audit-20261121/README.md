# Inlining in the O3 natives of image 3b5fa4b40 (2026-11-21, coordinator)

Operator 2026-11-21 ~09:0x UTC: "编译参数固定 O3. 不需要调代码大小了. 确保 inline 啥的都正常就好".

`calls.py` sorts every call left in the shipped x86 natives (`vendor/build/native-bpf/x86/stage`) by target
(`calls.txt`); `tetragon_local_calls.py` names Tetragon's calls to local functions and lists the same objects'
eBPF subprograms (`tetragon_local_calls.txt`).

- Our header helpers (`__kprog_*`, extern inline with always_inline): 0 out-of-line definitions and 0 calls in all six
  apps, so every one is inlined; the clock reads call `ktime_get_mono_fast_ns` directly (BCC 16, Cilium 204, Katran 8,
  OTel 14, Tetragon 22 sites).
- Calls to local functions: OTel, Cilium, Tracee 0; BCC 2; Katran 3; Tetragon 265. Tetragon's targets (`do_action`,
  `filter_char_buf`, `filter_32ty`, `filter_inet`, ...) are the functions its eBPF build also keeps as separate
  subprograms (bpf-to-bpf calls), so the native code keeps the source's call structure; what eBPF inlines, the O3
  native inlines too.
- `memset`/`memcpy` calls: Tetragon 5,910 / 13, Tracee 823 / 19, OTel 5, BCC 2. These are large zero-fills and copies:
  with `-mgeneral-regs-only` clang calls the kernel's memset/memcpy above its inline size, where the eBPF backend
  expands them into stores.
