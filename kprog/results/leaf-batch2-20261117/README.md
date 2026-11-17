# Leaf batch 2 (2026-11-17): handed to omp

The coordinator wrote these changes and hands them to omp (operator 2026-11-17: "让 omp 统筹 codex 或者自己做"), because PERF is editing the same x86_probe_read.rs and one writer per file keeps the shared tree clean. omp schedules the batch after the coordinator's ktime batch logs "image ok"; PERF or omp applies the edits once PERF's own work in those files is committed.

## What each piece does

| File | Applies to | Change |
|---|---|---|
| `x86_task.rs`, `task_driver.c`, `task_edit.py` | native_link `src/x86_task.rs` (new), `fixtures/task_driver.c` (new), `main.rs`, `x86.rs`, `x86_probe_read.rs`, loader `native_loader_lto.hpp` | bpf_get_current_uid_gid as one shared leaf: (gid << 32) \| uid read from current->cred (init_user_ns maps are the identity, perf review 307288825); -EINVAL for a NULL current. Layout facts task_struct.cred, cred.uid, cred.gid from running BTF (guest offsets 8 and 12). The same script changes the kernel-string loop: DEC ECX after the NUL branch ends the count with its zero flag, and a copied NUL skips the final store (perf review 701cbef1c). |
| `cilium_edit.py` | `vendor/bpf/Makefile` | Cilium lxc, host and xdp objects compile with cilium-agent's own switches for the frozen workload (MONITOR_AGGREGATION 0, so every packet is traced as the agent's ep_config.h leaves it; policy audit and verdict notify; IPv4 masquerade and nodeport; routing; host endpoint for bpf_host; the agent's CIDR prefilter for xdp). Node addresses vary per run and stay runtime values. Source: the agent's generated headers in /workspaces/kprog-raw/perf/20261113-cilium-context-runtime-retry2/baseline-state/state. |
| `rename_edit.py` | `x86_ktime.rs`, `fixtures/ktime_driver.c` | The ktime leaf's other branches call the kernel's own ktime_get_mono_fast_ns; the variable and the fixture stub take the name kernel_call / kernel_ktime. Bytes stay the same. |

## Apply and test

```
python3 kprog/results/leaf-batch2-20261117/task_edit.py
python3 kprog/results/leaf-batch2-20261117/cilium_edit.py
python3 kprog/results/leaf-batch2-20261117/rename_edit.py
( exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing; flock -s 8; cd kprog/x86/native_lab/native_link && taskset -c 8-23 cargo test --release )
( exec 8>/workspaces/.agent-state/kprog-lanes/locks/timing; flock -s 8; cmake --build runner/build-llvmbpf --target native_loader_shared -j1 )
```

Each edit script asserts the exact text it replaces; when an anchor moved (for example after PERF's jiffies fields in main.rs), place the same change by hand. Expected host results: 41 linker tests plus the uid_gid test; the kernel-string fixture (193 vectors) passes with the shorter loop; kernel.bin and user.bin stay byte-identical, kernel-string.bin shrinks.

PERF 2026-11-17: `task_edit.py` reads its committed component assets directly.
The loader check uses the canonical `runner/build-llvmbpf` target used by
the frozen image recipe; the old component-local CMake cache still names
`native-sim/libnativeloader` and is not another build to refresh. The
committed `run-host.sh` runs the full linker suite and this loader target
on CPU 19 under timing SH, with persistent output including all fixture
temporaries. Its actual test count supersedes the early estimate above.

## Batch

Image, one-image check (native replacements per app unchanged, zero native-loader failures), then Tracee (uid_gid, kernel strings) and Cilium (switches) through the frozen entry, stats on, 3 x 60 s, holding locks/batch from image build to last timing. Cilium's ratio is expected to fall from its unequal-work 2.8x toward an equal-work value; check its per-program paths with arm-paths-20261116/paths.py.

## Applied host receipts

PERF 2026-11-17T12:45:12Z: applied after the clock image's `image ok` at
12:07:47Z, preserving the prior user/compat string leaves. The full linker
suite passes 43 tests, with three existing opt-in tests ignored and no
filter. The canonical loader target builds successfully. Raw:
`/workspaces/kprog-raw/perf/leaf-batch2-20261117/host-20261117T121810Z-2564495`;
small receipts: `host-summary.json`, `host-output.txt`, `loader-output.txt`.

The UID/GID fixture executes six current-credential/NULL-current vectors
in a 53-byte shared body. It reuses the existing GS encoding and call-slot
helpers instead of duplicating their validation. Credential BTF lookups
use the existing error propagation; the proposed additional empty catch
was not added. Older captured plans may omit credential facts.

Kernel strings shrink 284 to 282 host payload bytes and pass the existing
193 vectors. The compat-string fixture shrinks 775 to 773 B because it
shares that shorter kernel leaf. Kernel/user scalars, user strings and
scalar compat remain byte-identical at 366 / 370 / 400 / 827 B. Clock
renaming leaves the emitter's byte literals unchanged; its 341-byte
fixture passes 15 vectors. These are host payload sizes, not installed
app totals or per-call gains.

The full suite now retains its ten generated proof fixtures in persistent
`TMPDIR`; the one cleanup call that deleted them was removed. No new app
program filter, runtime check or optimization switch was introduced.

Cilium's producer rules previously did not depend on the Makefile that
defines their flags. Native object recipes now include that dependency,
so committed flag changes trigger recompilation across the native object
families. `run-producer-plan.sh` records the Cilium Make dry run under
timing SH. The dry run completed at 12:54:28Z: seven compilation commands,
all using the common `-O3` flags (`producer-plan.json`).

The actual canonical Cilium producer build passed at 13:09:03Z (started
13:08:55Z, CPU 19, timing SH and image EX, 32 GiB address-space limit).
Its log is retained at
`/workspaces/kprog-raw/perf/leaf-batch2-20261117/cilium-20261117T130722Z-2576741/make.log`.
All seven objects were compiled, staged in place and their manifest generated.
The three loaded object families now take the agent switches; overlay,
sock and wireguard retain their previous broader options. Machine optimization
flags remain the same for all apps. `record-producer.sh` records the staged
ELF section and file sizes under timing SH and image SH; these include
embedded IR/debug information and are not installed native sizes.
The reader completed at 13:37:21Z; `producer-sizes.txt` preserves every
section and file size. Program code also lives in named sections such as
`tc/tail`, so `.text` alone is not the producer's executable-byte total.

Batch-2 LTO source is committed as `8b31e4533`. Omp reviews the joined diff
and schedules image, six-app check and Tracee/Cilium timing after the
coordinator's clock and quiet rerun batches finish. Installed app bytes,
per-call time and body/helper/map attribution remain pending. PERF has
published no additional image or started a guest for this step.
