# tetragon 32MiB ReJIT E2BIG/ENOSPC diagnosis

Artifact: `corpus/results/x86_kvm_corpus_20260507_002840_650501/details/apps/tetragon__observer.json`

Scope: read-only diagnosis. No code changes.

## 1. E2BIG root cause

`errno 7` is not from verifier rejection and not from daemon fd_array size.

The ReJIT path has two relevant `-E2BIG` sites:

- Early argument validation: `vendor/linux-framework/kernel/bpf/syscall.c:3632-3636`
  - `attr->rejit.insn_cnt > BPF_COMPLEXITY_LIMIT_INSNS`
  - `attr->rejit.fd_array_cnt > BPF_PROG_REJIT_MAX_FD_ARRAY`
- Post-verifier size guard: `vendor/linux-framework/kernel/bpf/syscall.c:3771-3789`
  - after `bpf_check()`, `bpf_prog_select_runtime()`, and `bpf_prog_mark_insn_arrays_ready()`
  - rejects when `bpf_prog_size(tmp->len) > prog->pages * PAGE_SIZE`

The prog 22/23 logs contain verifier completion summaries:

```text
processed 28188 insns ... total_states 1409 ...
processed 10265 insns ... total_states 730 ...
```

That means `bpf_check()` completed. The matching kernel site is therefore the post-verifier guard at `syscall.c:3787-3789`.

Supporting code:

- `bpf_prog_size()` is `max(sizeof(struct bpf_prog), offsetof(struct bpf_prog, insns[proglen]))`: `vendor/linux-framework/include/linux/filter.h:1028-1031`
- `bpf_prog_alloc_no_stats()` rounds allocation to pages and stores `fp->pages`: `vendor/linux-framework/kernel/bpf/core.c:106-124`
- `struct bpf_prog` keeps instructions in an embedded flexible array after metadata fields: `vendor/linux-framework/include/linux/bpf.h:1830-1864`
- ReJIT later copies the new verified instructions into the old object: `vendor/linux-framework/kernel/bpf/syscall.c:3486-3493`

So this is an in-place object-capacity limit. It is not a generic "raise fd_array/BTF limit" problem.

## 2. prog 22/23 specific features

| prog | name | type | bytes_xlated | maps | failed pass | pass delta | raw before -> after | verifier summary |
| --- | --- | --- | ---: | ---: | --- | ---: | ---: | --- |
| 22 | `event_execve` | tracepoint | 20272 | 16 | `cond_select` | +22 insns | 2468 -> 2490 | processed 28188 |
| 23 | `execve_send` | tracepoint | 8064 | 9 | `cond_select` | +10 insns | 936 -> 946 | processed 10265 |

The map counts come from `daemon.stderr.log` `map_snapshot prog_id=...` lines. Those lines are produced by `write_bpftool_map_snapshots()` iterating `snapshot.maps`: `daemon/src/commands.rs:810-832`; `snapshot.maps` comes from `prog_info.map_ids`: `daemon/src/bpf.rs:67-80` and `daemon/src/bpf.rs:130-147`.

The daemon fd_array is built from `snapshot.info.map_ids` plus probed kinsn module fds at `daemon/src/commands.rs:458-460`. Counts 16 and 9 are well below the kernel ReJIT fd_array cap of 64 at `vendor/linux-framework/kernel/bpf/syscall.c:3607-3608`, so fd_array is not the trigger.

The distinguishing feature is page-boundary pressure plus a positive-size `cond_select` rewrite:

- prog 22 current xlated length: `20272 / 8 = 2534` verified insns. Raw input before `cond_select` was 2468, so verifier/JIT-side expansion is about 66 insns. `cond_select` adds 22 raw insns, likely producing about 2556 verified insns. That crosses the original 5-page allocation by roughly one cache line.
- prog 23 current xlated length: `8064 / 8 = 1008` verified insns. Raw input before `cond_select` was 936, so expansion is about 72 insns. `cond_select` adds 10 raw insns, likely producing about 1018 verified insns. That crosses the original 2-page allocation.

This also explains why neighboring programs do not hit E2BIG: many have more page slack or prior passes shrink them before a growth pass. The two E2BIG programs both hit `cond_select` growth before any later shrink pass can run. `cond_select` emits replacement streams at `bpfopt/crates/bpfopt/src/passes/cond_select.rs:214-237`.

## 3. ENOSPC status

All 111 `errno 28` programs fail at `noop` with `log_level=2`.

`noop` is the state-producing bootstrap before verifier-state consumers. In this artifact:

```text
errno 28 failed pass: ("noop", log_level=2) => 111 programs
```

First 10 ENOSPC programs:

| prog | name | type | bytes_xlated | maps | failed pass | log level | subprog_count |
| ---: | --- | --- | ---: | ---: | --- | ---: | --- |
| 30 | `generic_kprobe_process_filter` | kprobe | 17992 | 13 | `noop` | 2 | not recoverable from truncated tail |
| 31 | `generic_kprobe_actions` | kprobe | 8752 | 17 | `noop` | 2 | not recoverable from truncated tail |
| 34 | `generic_kprobe_filter_arg` | kprobe | 17544 | 24 | `noop` | 2 | not recoverable from truncated tail |
| 36 | `generic_kprobe_actions` | kprobe | 8752 | 17 | `noop` | 2 | not recoverable from truncated tail |
| 39 | `generic_kprobe_process_filter` | kprobe | 17992 | 13 | `noop` | 2 | not recoverable from truncated tail |
| 40 | `generic_kprobe_filter_arg` | kprobe | 17544 | 24 | `noop` | 2 | not recoverable from truncated tail |
| 42 | `generic_kprobe_filter_arg` | kprobe | 17544 | 24 | `noop` | 2 | not recoverable from truncated tail |
| 43 | `generic_kprobe_process_filter` | kprobe | 17992 | 13 | `noop` | 2 | not recoverable from truncated tail |
| 45 | `generic_kprobe_actions` | kprobe | 8752 | 17 | `noop` | 2 | not recoverable from truncated tail |
| 49 | `generic_kprobe_actions` | kprobe | 8752 | 17 | `noop` | 2 | not recoverable from truncated tail |

The subprogram count is not available from this artifact for ENOSPC rows. With the current kernel log mode, ENOSPC returns a circular tail of the verifier log, not the beginning containing `func#N @...` headers. The artifact has no retained failure-artifact directory, and `result.json` does not include func metadata.

Kernel reason:

- ReJIT passes `attr->rejit.log_level`, `log_size`, and `log_buf` through to the internal load verifier attr: `vendor/linux-framework/kernel/bpf/syscall.c:3648-3654`
- verifier initializes the log at `vendor/linux-framework/kernel/bpf/verifier.c:26377-26379`
- verifier finalizes after verification stats are printed: `vendor/linux-framework/kernel/bpf/verifier.c:26530-26539`
- log finalization returns `-ENOSPC` when actual log size exceeded the supplied buffer: `vendor/linux-framework/kernel/bpf/log.c:284-295`
- non-`BPF_LOG_FIXED` logging is a rotating user buffer, so the retained content is the tail: `vendor/linux-framework/kernel/bpf/log.c:93-104` and `vendor/linux-framework/kernel/bpf/log.c:226-279`

This means ENOSPC is "verifier log did not fit", not verifier setup failure. The sampled decoded log lengths are effectively the 32MiB cap:

| prog | decoded verifier log bytes | tail |
| ---: | ---: | --- |
| 30 | 33,554,430 | `processed 169047 insns ...` |
| 31 | 33,554,429 | `processed 111338 insns ...` |
| 34 | 33,554,429 | `processed 207836 insns ...` |

The top-level `rejit_result.error` line alone is 3,776,844,728 bytes. The per-program error strings duplicate the logs again. This is why the app detail JSON is 15GB.

## 4. Is 64MiB required?

Current evidence is interval-censored:

- 16MiB run (`x86_kvm_corpus_20260506_233740_843089`) had 142 ENOSPC.
- 32MiB run has 111 ENOSPC.
- Therefore 31 programs have verbose `noop` logs in `(16MiB, 32MiB]`.
- The remaining 111 programs have true log size `>32MiB`.

The exact maximum tetragon verbose log size is not recoverable from this artifact because ReJIT's UAPI does not expose `log_true_size`. `BPF_PROG_LOAD` has `log_true_size` at `vendor/linux-framework/include/uapi/linux/bpf.h:1631-1635`, but fork ReJIT's attr stops at `flags`: `vendor/linux-framework/include/uapi/linux/bpf.h:1935-1944`, mirrored by `bpfopt/crates/kernel-sys/src/lib.rs:58-71`.

The average successful verifier log size for the 75 ok programs is also not recoverable here. Successful verifier logs are written only inside daemon workdirs; this run has no `details/failure-artifacts/`, and successful workdirs are deleted by `WorkDir::drop()` at `daemon/src/commands.rs:101-108`.

So 64MiB is not proven sufficient, but any cap <=32MiB is proven insufficient for 111 tetragon programs.

## 5. Fix directions

### E2BIG

Preferred fix: keep growing transforms from producing a ReJIT candidate that cannot fit the original in-place `struct bpf_prog` allocation.

Concrete options:

1. Make `cond_select` growth-aware.
   - Code site: `bpfopt/crates/bpfopt/src/passes/cond_select.rs:214-237`
   - Skip or limit sites where `replacement_len > old_len` unless a caller-provided growth budget says the program has enough page slack.
   - This still runs ReJIT for every program; it only avoids a pass-local transform that cannot be installed.

2. Add daemon-side page-slack preflight for clearer diagnostics.
   - Code site after bytecode read/decode and before ReJIT: `daemon/src/commands.rs:607-649`
   - Need daemon to retain both original `xlated_prog_len` and original bytecode length. `ProgramInfo::from_info()` currently chooses `orig_prog_len` over `xlated_prog_len`: `daemon/src/bpf.rs:110-125`.
   - This should be diagnostic or budget input to bpfopt, not a hidden fallback that silently skips ReJIT.

Kernel-side "increase the limit" is not a small limit bump. The guard protects the later in-place `memcpy()` into the old flexible-array allocation at `vendor/linux-framework/kernel/bpf/syscall.c:3486-3493`. Growing the object would require safely replacing a live `struct bpf_prog *` referenced by fds, links, maps, trampolines, and call sites.

### ENOSPC/OOM

Preferred daemon-side fixes:

1. Stop serializing full verifier logs into JSON errors.
   - Current full-log formatting is in `bpfopt/crates/kernel-sys/src/lib.rs:460-470`.
   - Daemon also writes the raw verifier log to a workdir file at `daemon/src/commands.rs:180-193`.
   - Return bounded error text: errno, pass, log path, log byte count, and first/last N KiB. Do not embed multi-GB logs in `error`, `error_message`, or top-level response strings.

2. Replace anonymous `Vec<u8>` log buffers with file-backed mmap buffers.
   - Current allocation: `daemon/src/commands.rs:180`.
   - Current retry cap: `bpfopt/crates/kernel-sys/src/lib.rs:1376-1426`; max is `bpfopt/crates/kernel-sys/src/lib.rs:43-50`.
   - Change `kernel_sys::prog_rejit()` to accept `&mut [u8]` or a log-buffer abstraction so daemon can pass a temp-file mmap. This keeps the syscall ABI unchanged but moves dirty pages out of anonymous RSS.

3. Do not base64-tar failure workdirs unless the runner requested retained artifacts.
   - Daemon currently tars failures at `daemon/src/commands.rs:30-34` and attaches them at `daemon/src/commands.rs:376-389`.
   - Runner discards the field when `failure_artifacts_dir` is `None`: `runner/libs/rejit.py:419-423`.
   - Add an explicit request flag in `runner/libs/rejit.py:382-389` and parse it in `daemon/src/server.rs:102-149`, so normal smoke runs do not build large in-memory tar/base64 payloads.

4. Add ReJIT `log_true_size` as a kernel/UAPI improvement.
   - This is not daemon-only, but it is the clean way to know whether 64MiB is enough.
   - Mirror `BPF_PROG_LOAD`'s `log_true_size` field into the ReJIT attr and copy the value out after `bpf_check()`.

Avoid as default:

- Changing `noop` from `log_level=2` to `log_level=1`. It would reduce logs, but it removes verifier states needed by `map_inline` and `const_prop`, changing pass coverage.
- Treating ENOSPC as success. Kernel did not complete ReJIT installation, and partial verifier-state logs are not a safe input for state-consuming passes.

## 6. Risks

- `cond_select` growth limiting can reduce optimization coverage. It should report explicit skip reasons so coverage loss is auditable.
- Daemon preflight based on `xlated_prog_len` is an estimate unless the kernel exposes `prog->pages`; use it for budgeting and diagnostics, not as a silent correctness gate.
- File-backed mmap log buffers reduce anon RSS but increase page-cache and disk I/O pressure. With 16 workers and 64MiB buffers, worst-case dirty footprint is still about 1GiB before accounting for workdir logs.
- Bounded JSON errors make artifacts smaller but require a separate retained log path for deep debugging.
- Adding `log_true_size` changes the fork UAPI and requires synchronized `kernel-sys` layout tests.
