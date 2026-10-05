# bpftool arm64 batch workaround options (2026-05-14)

## Verdict
Best zero-code-change runner workaround: none; `script -q -c "bpftool batch file ..."` can mask the child exit code in an ad-hoc shell command, but it does not avoid the bpftool bug, still prints the bpftool error, hides real failures, and cannot be injected through the existing Katran/corpus bpftool executable knobs.

## Test matrix

All arm64 tests used the local qemu-user Docker path:

```bash
printf 'version\nversion\nversion\n' > /tmp/test_batch_nop.txt
sudo docker run --rm --platform linux/arm64 \
  -v /tmp/test_batch_nop.txt:/tmp/batch.txt:ro \
  bpf-benchmark/runner-runtime:arm64 \
  <variant>
```

| variant | exit code | stderr | works? | mechanism |
| --- | ---: | --- | --- | --- |
| `bpftool batch file /tmp/batch.txt` | 255 | `Error: reading batch file failed: Illegal seek` | No | Baseline reproduction. All 3 `version` lines print, then `do_batch()` trips on stale `errno`. |
| `bpftool -j batch file /tmp/batch.txt` | 255 | none; JSON error object on stdout | No | JSON mode changes the output writer, but `do_batch()` still checks stale `errno` after the loop. |
| `bpftool -p batch file /tmp/batch.txt` | 255 | none; pretty JSON error object on stdout | No | Same as `-j`; pretty mode only changes JSON formatting. |
| `bpftool -q batch file /tmp/batch.txt` | 255 | `Error: unrecognized option '-q'` | No | This bpftool has no quiet option. |
| `cat /tmp/batch.txt \| bpftool batch file -` | 255 | `Error: reading batch file failed: Illegal seek` | No | The stdin path is supported, but the same final `errno` check runs. |
| `bpftool batch file /tmp/batch.txt > /dev/null 2>&1; echo $?` | inner 255 | hidden | No | Suppressing all output hides the symptom text only; bpftool still exits failure. |
| `bpftool batch file /tmp/batch.txt 2>/dev/null` | 255 | hidden | No | Hides stderr only; exit remains failed. |
| `bpftool batch file <(cat /tmp/batch.txt)` | 255 | `Error: reading batch file failed: Illegal seek` | No | Process substitution changes the file path to `/dev/fd/N`; `do_batch()` still fails after EOF. |
| `bpftool batch file /proc/self/fd/0 < /tmp/batch.txt` | 255 | `Error: reading batch file failed: Illegal seek` | No | Explicit fd path also reaches the same `fopen()`/`fgets()` loop and final check. |
| `script -q -c "bpftool batch file /tmp/batch.txt" /dev/null` | 0 | none; bpftool error appears on stdout | Ad-hoc mask only | GNU `script` defaults to its own exit status, so it masks the child `255`; it does not fix bpftool. `script -q -e -c ...` reports `255`. |
| `unbuffer bpftool batch file /tmp/batch.txt` | 127 | `unbuffer not installed` | No | The runtime image does not include `unbuffer`. |
| `stdbuf -o0 -e0 bpftool batch file /tmp/batch.txt` | 255 | `Error: reading batch file failed: Illegal seek` | No | Disabling stdio buffering does not clear or avoid the stale `errno`. |
| `setsid bpftool batch file /tmp/batch.txt < /dev/null` | 255 | `Error: reading batch file failed: Illegal seek` | No | Detaching the session does not affect the batch loop or `errno` check. |

Additional environment-variable tests:

| variant | exit code | stderr | works? | mechanism |
| --- | ---: | --- | --- | --- |
| `LIBC_FATAL_STDERR_=1 bpftool batch file /tmp/batch.txt` | 255 | `Error: reading batch file failed: Illegal seek` | No | Affects glibc fatal diagnostics, not normal stdio `errno`. |
| `LD_BIND_NOW=1 bpftool batch file /tmp/batch.txt` | 255 | `Error: reading batch file failed: Illegal seek` | No | Eager dynamic binding does not affect the stale `errno` path. |
| `MALLOC_ARENA_MAX=1 bpftool batch file /tmp/batch.txt` | 255 | `Error: reading batch file failed: Illegal seek` | No | Malloc arena policy is irrelevant to the final `errno` check. |
| `MALLOC_CHECK_=3 bpftool batch file /tmp/batch.txt` | 255 | `Error: reading batch file failed: Illegal seek` | No | No malloc consistency failure is involved. |
| `MALLOC_PERTURB_=165 bpftool batch file /tmp/batch.txt` | 255 | `Error: reading batch file failed: Illegal seek` | No | Heap perturbation does not affect `do_batch()`. |
| `GLIBC_TUNABLES=glibc.malloc.tcache_count=0 bpftool batch file /tmp/batch.txt` | 255 | `Error: reading batch file failed: Illegal seek` | No | Tcache disablement does not affect `do_batch()`. |
| `LD_DEBUG=libs bpftool batch file /tmp/batch.txt` | 255 | loader logs plus same bpftool error | No | Loader diagnostics add stderr writes; they do not reset `errno`. |
| `LD_DEBUG=libs LD_DEBUG_OUTPUT=/tmp/bpftool-ld-debug bpftool batch file /tmp/batch.txt` | 255 | `Error: reading batch file failed: Illegal seek` | No | Redirecting loader diagnostics does not affect bpftool's final check. |
| `POSIXLY_CORRECT=1 bpftool batch file /tmp/batch.txt` | 255 | `Error: reading batch file failed: Illegal seek` | No | Getopt behavior changes are irrelevant once `do_batch()` runs. |

Additional bpftool flag tests:

| variant | exit code | stderr | works? | mechanism |
| --- | ---: | --- | --- | --- |
| `bpftool -d batch file /tmp/batch.txt` | 255 | `Error: reading batch file failed: Illegal seek` | No | Debug mode only enables libbpf/verifier logging. |
| `bpftool -f batch file /tmp/batch.txt` | 255 | `Error: reading batch file failed: Illegal seek` | No | `--bpffs` does not change batch parsing or output. |
| `bpftool -m batch file /tmp/batch.txt` | 255 | `Error: reading batch file failed: Illegal seek` | No | `--mapcompat` is unrelated to batch EOF handling. |
| `bpftool -n batch file /tmp/batch.txt` | 255 | `Error: reading batch file failed: Illegal seek` | No | `--nomount` is unrelated to batch EOF handling. |
| `bpftool -L batch file /tmp/batch.txt` | 255 | `Error: reading batch file failed: Illegal seek` | No | Loader mode is unused by `version` and does not change `do_batch()`. |
| `bpftool -V batch file /tmp/batch.txt` | 0 | none | No | `-V` bypasses command dispatch and prints version once; it does not process the batch. |
| `bpftool -h batch file /tmp/batch.txt` | 0 | usage text | No | `-h` bypasses command dispatch and prints help; it does not process the batch. |
| `bpftool -S batch file /tmp/batch.txt` | 234 | missing `-i`/`-k` error | No | Fails before batch execution. |
| `bpftool -i /tmp/no-cert batch file /tmp/batch.txt` | 234 | requires `--sign` error | No | Fails before batch execution. |
| `bpftool -B /tmp/no-btf batch file /tmp/batch.txt` | 255 | failed to parse BTF | No | Fails before batch execution. |

Batch-content/no-op probes:

| variant | exit code | stderr | works? | mechanism |
| --- | ---: | --- | --- | --- |
| empty batch file | 255 | `Error: reading batch file failed: Illegal seek` | No | Even with zero commands, stale `errno` reaches the final check. |
| comment-only batch file | 255 | `Error: reading batch file failed: Illegal seek` | No | Comments are ignored, but the final check still runs. |
| `bpftool batch file /dev/null` | 255 | `Error: reading batch file failed: Illegal seek` | No | A real empty file-like input still fails. |
| `version` followed by comment/blank lines | 255 | `Error: reading batch file failed: Illegal seek` | No | Later no-op lines do not clear `errno`. |
| `help` | 255 | usage text plus same error | No | `help` prints and returns 0, but the final `errno` check still fails. |
| `version > /dev/null` as a batch line | 255 | same error | No | Batch parsing is not shell parsing; `do_version()` ignores the extra tokens and still writes output. |

## Recommended path

No usable zero-code-change workaround exists for `make corpus`/Katran. The only command that returned `0` while running the batch was:

```bash
sudo docker run --rm --platform linux/arm64 \
  -v /tmp/test_batch_nop.txt:/tmp/batch.txt:ro \
  bpf-benchmark/runner-runtime:arm64 \
  /bin/bash -lc 'script -q -c "bpftool batch file /tmp/batch.txt" /dev/null'
```

That is not a real fix. It prints `Error: reading batch file failed: Illegal seek`, and `script -q -e -c "bpftool batch file /tmp/batch.txt" /dev/null` proves the child still exits `255`. It also cannot be injected through the existing Katran call because the runner resolves a single bpftool executable path and then appends `batch file <path>` as argv. Setting `BPFTOOL_BIN='script -q -c bpftool /dev/null'` fails resolver validation because the value is not an executable path.

Minimum-code-change ranking if source edits become allowed later:

1. Fix bpftool userspace batch EOF handling in `vendor/linux-framework/tools/bpf/bpftool/main.c`. Prefer replacing the global stale-`errno` post-loop test with an actual stream-error check, or otherwise clearing `errno` only around `fgets()` in a way that preserves real `E2BIG`/read-error reporting.
2. Add a very small runner-visible bpftool wrapper only for the arm64/qemu-user batch failure. This is less clean because it would need to distinguish the known false failure from real batch command failures and would add another executable artifact.
3. Replace Katran's batch update path with direct libbpf/BPF syscall map updates from Python. This is robust but has more implementation and ABI surface than fixing bpftool's one bad error check.

## Sources tested

- `vendor/linux-framework/tools/bpf/bpftool/main.c:327`: `do_batch()` entry point.
- `vendor/linux-framework/tools/bpf/bpftool/main.c:338`: batch accepts exactly `batch file FILE`.
- `vendor/linux-framework/tools/bpf/bpftool/main.c:350`: `FILE == "-"` selects stdin.
- `vendor/linux-framework/tools/bpf/bpftool/main.c:359`: JSON mode starts the batch output array but does not change EOF handling.
- `vendor/linux-framework/tools/bpf/bpftool/main.c:361`: line-reading loop uses `fgets()`.
- `vendor/linux-framework/tools/bpf/bpftool/main.c:404`: JSON mode wraps each command's output.
- `vendor/linux-framework/tools/bpf/bpftool/main.c:414`: each batch line dispatches through `cmd_select()`.
- `vendor/linux-framework/tools/bpf/bpftool/main.c:425`: final `if (errno && errno != ENOENT)` check that causes the false failure.
- `vendor/linux-framework/tools/bpf/bpftool/main.c:429`: success path prints `processed %u commands`.
- `vendor/linux-framework/tools/bpf/bpftool/main.c:444`: supported long options are `json`, `help`, `pretty`, `version`, `bpffs`, `mapcompat`, `nomount`, `debug`, `use-loader`, `sign`, and `base-btf`.
- `vendor/linux-framework/tools/bpf/bpftool/main.c:480`: getopt string has no `q` option.
- `vendor/linux-framework/tools/bpf/bpftool/main.c:490`: `-p` implies JSON mode.
- `vendor/linux-framework/tools/bpf/bpftool/main.c:512`: `-d` only enables debug logging.
- `vendor/linux-framework/tools/bpf/bpftool/main.c:561`: `-V` takes the version path instead of command dispatch.
- `vendor/linux-framework/tools/bpf/bpftool/common.c:43`: `p_err()` implementation.
- `vendor/linux-framework/tools/bpf/bpftool/common.c:48`: JSON errors go through the JSON writer.
- `vendor/linux-framework/tools/bpf/bpftool/common.c:53`: non-JSON errors go to stderr.
- `vendor/linux-framework/tools/bpf/bpftool/Documentation/common_options.rst:14`: documented JSON option.
- `vendor/linux-framework/tools/bpf/bpftool/Documentation/common_options.rst:18`: documented pretty JSON option.
- `vendor/linux-framework/tools/bpf/bpftool/Documentation/common_options.rst:21`: documented debug option.
- `runner/libs/app_runners/katran.py:264`: Katran map batch helper.
- `runner/libs/app_runners/katran.py:270`: Katran invokes `[resolve_bpftool_binary(), "batch", "file", batch_path]`.
- `runner/libs/app_runners/katran.py:611`: Katran map configuration path.
- `runner/libs/app_runners/katran.py:617`: Katran always uses `_bpftool_map_update_batch()` for this setup.
- `runner/libs/__init__.py:18`: recognized bpftool env vars are `BPFTOOL_BIN` and `BPFTOOL`.
- `runner/libs/__init__.py:91`: `resolve_bpftool_binary()` checks those env vars.
- `runner/libs/__init__.py:93`: env value is treated as a single executable candidate.
- `runner/libs/__init__.py:99`: fallback bpftool candidates.
- `runner/suites/_common.py:283`: suite runtime env construction.
- `runner/suites/_common.py:297`: runtime `PATH` is reconstructed.
- `runner/suites/_common.py:308`: runtime `BPFTOOL_BIN` is set from `args.bpftool_bin`.
- `runner/libs/run_contract.py:222`: corpus run-config accepted host inputs do not include `BPFTOOL_BIN` or `RUN_BPFTOOL_BIN`.
- `runner/libs/run_contract.py:285`: `run_bpftool_bin` defaults to `bpftool`.
- `runner/libs/run_contract.py:387`: run config exports that default as `RUN_BPFTOOL_BIN`.
- `runner/libs/workspace_layout.py:93`: runtime `PATH` builder.
- `runner/libs/workspace_layout.py:101`: standard runtime PATH entries searched for `bpftool`.
