# POC Validation Report

## Outcome

The POC works end to end.

- Kernel changes were reviewed, committed, built, and booted under `virtme-ng`.
- Userspace hint generation and load-time attachment were implemented in `micro/`.
- The `load_byte_recompose` benchmark ran successfully both with and without directives inside the guest.
- The directive-enabled run was measurably faster: median `exec_ns` dropped from `288.0` to `130.5` (`0.453x` baseline, `2.21x` speedup, `54.7%` lower median runtime).

Raw benchmark JSON is in `docs/tmp/poc-validation-results.json`.

## Code Review Findings

### 1. Blob format does not match the v7 design

The current UAPI in `vendor/linux/include/uapi/linux/bpf.h` is a simplified POC format:

- `struct bpf_jit_directive_hdr { magic, version, rec_size, rec_cnt, insn_cnt }`
- `struct bpf_jit_directive_rec { kind, reserved, site_idx, payload }`

That is not the v7 blob contract from `docs/tmp/bpf-jit-advisor-v7.md`, which requires:

- exact-image digest binding;
- CPU contract payloads;
- explicit stage tagging;
- richer per-record interval metadata;
- stage-aware validation and telemetry.

Conclusion: the kernel/UAPI format is adequate for this POC, but it is not v7-complete.

### 2. Bad directive behavior is POC-correct, but not v7 fail-closed

`kernel/bpf/jit_directives.c:bpf_jit_directives_load()` silently returns `NULL` when the memfd, blob header, record size, record count, or instruction count is invalid. Unsupported records are filtered out individually.

That gives the current POC behavior:

- bad blob or bad record -> directive is ignored;
- BPF program still loads and runs normally.

This matches the requested POC behavior for this validation pass. It does not match the stricter v7 model, where fatal blob/header mismatches should reject load with an error and stage-specific rejections should be reported explicitly.

### 3. The original `wide_load` matcher was too narrow; this was fixed

The benchmark hot path in `micro/programs/load_byte_recompose.bpf.c` is not a fixed four-byte ladder. The generated BPF contains:

- one four-byte recomposition site;
- one eight-byte little-endian recomposition site in the hot loop.

The original verifier matcher only accepted a narrow four-byte sequence and would miss the benchmark’s profitable case. I updated `kernel/bpf/verifier.c` so the matcher now:

- accepts widths `4` and `8`;
- tracks byte-load, shift, and OR expressions instead of one hard-coded order;
- verifies that all lanes form one contiguous little-endian load window;
- rejects matches that cross jump points or have unsafe live-out temps;
- only widens when alignment/pointer-class checks are acceptable.

This change is why the benchmark now rewrites successfully.

### 4. Pipeline placement is correct

`bpf_jit_directives_apply()` is invoked after `do_check()` and the verifier-side cleanup passes, and before:

- `convert_ctx_accesses()`
- `do_misc_fixups()`

That matches the intended verifier-stage placement from the v7 design notes: rewrite the verified BPF program before later stock fixups consume it.

### 5. Userspace loader issues found and fixed

Two userspace issues blocked end-to-end loading initially:

- synthetic map IDs in the manual loader were off by one;
- map-FD relocation matched any instruction with `src_reg == 1`, instead of only `LD_IMM64` pseudo-map instructions.

After fixing both, manual `BPF_PROG_LOAD` with `jit_directives_fd` succeeded in the guest.

## Commit / Build / Boot

### Commit

Kernel changes in `vendor/linux` were committed as:

- `266712bf6` `POC: BPF JIT directive framework with wide_load rewrite`

### Build

The kernel built successfully with the existing tree configuration using:

```sh
make -j$(nproc)
```

Artifact produced:

- `vendor/linux/arch/x86/boot/bzImage`

### Boot

The kernel booted successfully with `virtme-ng` using:

```sh
vng --run . \
  --user root \
  --cwd /home/yunwei37/workspace/bpf-benchmark \
  --rwdir /home/yunwei37/workspace/bpf-benchmark \
  --cpus 4 \
  --memory 4G \
  --exec "python3 /home/yunwei37/workspace/bpf-benchmark/docs/tmp/run_poc_validation_in_vm.py"
```

Inside the guest:

- `uname -r` reported `7.0.0-rc2-g266712bf690c`

That confirms the VM was running the POC kernel built from the committed tree.

## Userspace Hint Tooling

### `micro/tools/directive_hint.c`

Added a standalone hint generator that:

1. reads a BPF ELF object;
2. scans its BPF instructions for byte-load recomposition patterns;
3. emits a directive blob matching the current POC kernel format.

For `load_byte_recompose.bpf.o`, it found two directive sites:

- `site_idx=14`, `width=4`
- `site_idx=30`, `width=8`

### `micro_exec --directive-blob`

The runner now accepts:

```sh
--directive-blob <path>
```

When present, the runner takes the manual `BPF_PROG_LOAD` path and sets:

- `prog_flags |= BPF_F_JIT_DIRECTIVES_FD`
- `jit_directives_fd = <sealed memfd containing blob>`

That is the path used for the successful guest benchmark run.

## Benchmark Results

Program:

- `micro/programs/load_byte_recompose.bpf.o`

Method:

- guest execution on the POC kernel;
- `2` warmups and `10` measured runs per configuration;
- `repeat=200`, `input_size=1032`;
- same input memory image for both runs.

### Summary Table

| Configuration | Median `exec_ns` | Median `compile_ns` | `xlated_prog_len` | `jited_prog_len` |
| --- | ---: | ---: | ---: | ---: |
| Baseline | 288.0 | 4,977,988.5 | 744 | 422 |
| With `wide_load` directives | 130.5 | 14,886,718.0 | 504 | 296 |

### Delta

- Median runtime delta: `-157.5 ns`
- Runtime ratio: `0.453x` baseline
- Speedup: `2.21x`
- Median runtime reduction: `54.7%`
- JIT code size reduction: `422 -> 296` bytes (`29.9%` smaller)
- Post-verifier BPF size reduction: `744 -> 504` bytes (`32.3%` smaller)

Functional correctness also held across runs:

- return value stayed `2`
- computed result stayed `1253018829653002637`

### Interpretation

The performance result is consistent with the intended optimization target. The rewritten program eliminates byte-load/shift/OR ladders and replaces them with direct wide loads, which substantially reduces both BPF instruction count and native JIT output size on this benchmark.

Compile/load time increased in the directive path. That is expected for this POC because the directive-enabled run goes through a manual loader path and does extra blob parsing/validation. The important result here is steady-state execution speed, not one-time load latency.

## Conclusion

Yes: this POC demonstrates the mechanism/policy split end to end.

What was proven:

- userspace can analyze a BPF program and emit optional optimization hints;
- the kernel can accept those hints independently of the base program load path;
- the verifier can validate and apply the requested rewrite safely enough for the target case;
- the rewritten program produces smaller JIT output and a clear runtime win on the intended benchmark.

Caveats:

- the blob UAPI/parser is still a POC format, not the full v7 interface;
- malformed blobs currently fail open by being ignored, rather than using v7 fatal header rejection plus stage-specific telemetry;
- `wide_load` is currently the only implemented directive family.

For the stated validation goal, the answer is positive: the mechanism works, and it produces a measurable improvement on `load_byte_recompose`.
