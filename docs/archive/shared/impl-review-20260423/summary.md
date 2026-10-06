# Impl Review Summary (2026-04-23)

## Part 1 — 按 6 角度的 findings

### 1. X taxonomy split

No actionable bug found.

- `corpus/driver.py:529-542` makes the four new no-change buckets mutually exclusive on the per-program path: `no_passes_requested -> zero_sites_found -> all_sites_rolled_back -> applied_but_identical -> fallback`.
- `corpus/driver.py:563-592` only calls `_apply_record_no_change_reason()` when that program's flattened `changed` bit is false, so one program cannot land in multiple new buckets.
- `corpus/driver.py:965-1015` preserves the Round 3A flattened top-level `changed` / `applied` schema while also carrying per-program `enabled_passes`, so `runner/libs/rejit.py:201-296` and `corpus/driver.py:501-526` stay aligned.
- Residual check: if `no_programs_changed_in_loader` remains non-zero after this series, that is now a real signal of malformed apply metadata or a missed control-flow path, not the expected bucket for ordinary no-change programs.

### 2. I-prod tracee `--events all`

#### Finding 2.1

- Severity: `HIGH`
- File:line: `runner/libs/app_runners/process_support.py:15-46`, `runner/libs/app_runners/tracee.py:345-355`, `runner/libs/app_runners/tracee.py:494-496`, `e2e/cases/tracee/case.py:66`
- Why it matters:
  - Crash / never-healthy startup already fails correctly in `TraceeAgentSession.__enter__()`.
  - The silent path is different: once Tracee becomes "healthy", `wait_until_program_set_stable()` returns the last seen partial set on timeout instead of failing.
  - With `--events all`, that turns a slow attach into an undercounted corpus run instead of a hard failure, which then pollutes the new X taxonomy and makes `missing_baseline_exec_ns` / total-program deltas look better than reality.
  - The current `60s` default is also tight for a VM when the APP summary already anticipated roughly `120-154` loaded programs.
- Ready-to-apply diff:

```diff
diff --git a/runner/libs/app_runners/process_support.py b/runner/libs/app_runners/process_support.py
index 3e9560e1..f8a4a5d7 100644
--- a/runner/libs/app_runners/process_support.py
+++ b/runner/libs/app_runners/process_support.py
@@ -41,8 +41,13 @@ def wait_until_program_set_stable(
             last_programs = [dict(program) for program in programs]
         elif programs and last_change_at is not None and (now - last_change_at) >= stable_window:
             return [dict(program) for program in programs]
         if now >= deadline:
-            return [dict(program) for program in last_programs]
+            preview = ",".join(str(pid) for pid in (last_ids or ())[:12]) or "<none>"
+            raise RuntimeError(
+                "BPF program set did not stabilize before timeout "
+                f"(timeout_s={timeout_s}, last_program_count={len(last_programs)}, "
+                f"last_program_ids={preview})"
+            )
         time.sleep(min(poll_interval, max(0.0, deadline - now)))
diff --git a/runner/libs/app_runners/tracee.py b/runner/libs/app_runners/tracee.py
index 0f4b9f3b..e00c3ee1 100644
--- a/runner/libs/app_runners/tracee.py
+++ b/runner/libs/app_runners/tracee.py
@@ -492,7 +492,7 @@ def run_tracee_workload(spec: Mapping[str, object], duration_s: int) -> WorkloadResult:
 
 
 DEFAULT_CONFIG = ROOT_DIR / "e2e" / "cases" / "tracee" / "config.yaml"
-DEFAULT_LOAD_TIMEOUT_S = 60
+DEFAULT_LOAD_TIMEOUT_S = 120
 DEFAULT_STARTUP_SETTLE_S = 5.0
diff --git a/e2e/cases/tracee/case.py b/e2e/cases/tracee/case.py
index 9b0cd07f..597872dc 100644
--- a/e2e/cases/tracee/case.py
+++ b/e2e/cases/tracee/case.py
@@ -63,7 +63,7 @@ DEFAULT_WARMUP_DURATION_S = 5
 DEFAULT_SMOKE_WARMUP_DURATION_S = 2
 DEFAULT_LATENCY_PROBE_COUNT = 8
 DEFAULT_SMOKE_LATENCY_PROBE_COUNT = 3
 DEFAULT_LATENCY_PROBE_TIMEOUT_S = 5.0
-DEFAULT_LOAD_TIMEOUT_S = 60
+DEFAULT_LOAD_TIMEOUT_S = 120
 DEFAULT_LATENCY_PROBE_ATTEMPTS = 3
 DEFAULT_BOOTSTRAP_ITERATIONS = 2000
 DEFAULT_BOOTSTRAP_SEED = 20260328
```

### 3. I-prod Katran healthcheck

#### Finding 3.1

- Severity: `BLOCKER`
- File:line: `runner/libs/app_runners/katran.py:445-456`, `runner/libs/app_runners/katran.py:769-776`, `runner/libs/app_runners/__init__.py:69-93`
- Why it matters:
  - `KatranServerSession.__init__()` uses `DEFAULT_ROOT_MAP_POS` in a default argument before that constant is defined.
  - Python evaluates default arguments at function definition time, so importing `runner.libs.app_runners.katran` raises `NameError` immediately.
  - This blocks `get_app_runner("katran", ...)`, and since `katran` is part of `macro_apps.yaml`, it blocks `vm-corpus` for the default suite.
  - Static review also suggests the intended healthcheck behavior itself is fail-fast after startup: the Katran server is launched with `-healthchecker_prog`, `-ipip_intf`, `-ipip6_intf`, `-map_path`, `-prog_pos`, and upstream Katran throws if the healthcheck attach fails. The blocking bug is earlier: import-time module load.
- Ready-to-apply diff:

```diff
diff --git a/runner/libs/app_runners/katran.py b/runner/libs/app_runners/katran.py
index af438575..7fccfce0 100644
--- a/runner/libs/app_runners/katran.py
+++ b/runner/libs/app_runners/katran.py
@@ -48,6 +48,9 @@ HTTP_TIMEOUT_S = 5.0
 SERVER_START_TIMEOUT_S = 15.0
 TOPOLOGY_SETTLE_S = 2.0
 
+DEFAULT_ROOT_MAP_POS = 2
+DEFAULT_HC_V4_TUN_IFACE = "ipip0"
+DEFAULT_HC_V6_TUN_IFACE = "ipip60"
 
 def _map_show_records() -> list[dict[str, object]]:
     payload = run_json_command([resolve_bpftool_binary(), "-j", "-p", "map", "show"], timeout=30)
@@ -771,9 +774,6 @@ DEFAULT_INTERFACE = "katran0"
 DEFAULT_CONCURRENCY = 4
 DEFAULT_TEST_RUN_BATCH_REPEAT = 128
 DEFAULT_WORKLOAD_SPEC = {"kind": "network"}
 DEFAULT_LOAD_TIMEOUT_S = DEFAULT_KATRAN_SERVER_LOAD_TIMEOUT_S
-DEFAULT_ROOT_MAP_POS = 2
-DEFAULT_HC_V4_TUN_IFACE = "ipip0"
-DEFAULT_HC_V6_TUN_IFACE = "ipip60"
 
 
 def _resolve_katran_bpf_artifact(*relative_candidates: str) -> Path:
```

No second Katran finding beyond this blocker.

- `runner/libs/app_runners/katran.py:490-515` does pass the new healthcheck/root-map arguments through.
- `runner/repos/katran/example_grpc/katran_server.cpp:40-59` confirms `hc_forwarding` defaults to `true`.
- `runner/repos/katran/katran/lib/KatranLb.cpp:779-786,935-956` shows healthcheck load/attach failures are hard failures, not silent skips, once the Python-side import issue is fixed.

### 4. I-prod 6 个新 workload variant

#### Finding 4.1

- Severity: `MEDIUM`
- File:line: `runner/libs/workload.py:739-760`, `runner/libs/workload.py:967-997`
- Why it matters:
  - Two selected "exact coverage" workloads still degrade silently when their key sub-action is unavailable.
  - `tracee_system_edge_mix` turns `cgroup mkdir/rmdir` failure into a note only, so `cgroup_mkdir_signal` / `cgroup_rmdir_signal` can disappear without failing the run.
  - `open_family_storm` turns `openat2` failure into a note only, so the workload can claim success while never exercising `__x64_sys_openat2`.
  - This is exactly the class of reverse silent-failure the review was supposed to catch.
- Ready-to-apply diff:

```diff
diff --git a/runner/libs/workload.py b/runner/libs/workload.py
index 04768d57..9f58fb61 100644
--- a/runner/libs/workload.py
+++ b/runner/libs/workload.py
@@ -743,7 +743,7 @@ def run_tracee_system_edge_mix_workload(duration_s: int | float) -> WorkloadResu
         notes: list[str] = []
         start = time.monotonic()
         deadline = start + max(0.2, float(duration_s))
         ops_total = 0.0
-        cgroup_note = ""
+        cgroup_exercised = False
         missing_path = str(root / "definitely-missing-execveat")
         while time.monotonic() < deadline:
             _run_execveat_once("/bin/true")
@@ -752,11 +752,13 @@ def run_tracee_system_edge_mix_workload(duration_s: int | float) -> WorkloadResu
             _exercise_dup_family(dup_path)
             _exercise_socketpair_once()
             _accept4_roundtrip()
-            if not cgroup_note:
-                cgroup_note = _exercise_cgroup_mkdir_rmdir_once() or ""
+            if not cgroup_exercised:
+                cgroup_result = _exercise_cgroup_mkdir_rmdir_once()
+                if cgroup_result:
+                    raise RuntimeError(cgroup_result)
+                cgroup_exercised = True
             ops_total += 1.0
-        if cgroup_note:
-            notes.append(cgroup_note)
         return _finish_result(ops_total, time.monotonic() - start, "", _notes_text(notes))
@@ -975,18 +977,14 @@ def run_open_family_storm_workload(duration_s: int | float) -> WorkloadResult:
         deadline = start + max(0.2, float(duration_s))
         ops_total = 0.0
         notes: list[str] = []
-        openat2_noted = False
         try:
             while time.monotonic() < deadline:
                 fd_open = _libc_open(target, os.O_RDONLY | os.O_CLOEXEC)
                 fd_openat = _libc_openat(dirfd, target.name, os.O_RDONLY | os.O_CLOEXEC)
                 fd_openat2 = -1
                 try:
                     try:
                         fd_openat2 = _libc_openat2(dirfd, target.name, os.O_RDONLY | os.O_CLOEXEC)
                     except OSError as exc:
-                        if not openat2_noted:
-                            openat2_noted = True
-                            notes.append(f"openat2 unavailable: {exc}")
+                        raise RuntimeError(f"open_family_storm requires openat2: {exc}") from exc
                     ops_total += 1.0
                 finally:
                     _close_quietly(fd_open)
```

Additional workload review notes, but no extra bug:

- `runner/libs/workload.py:249-284,763-775` shows `tracee_module_load_loop` really does `modprobe` load/unload cycles against `repo_kernel_modules_root()` and fails loudly if there is no eligible module; it is not silently skipped.
- `runner/libs/workload.py:778-799` shows `tracee_io_vector_mix` really issues `write/writev/pwritev/read/readv/preadv`.
- `tracee_module_load_loop` and `tracee_io_vector_mix` are dispatchable (`runner/libs/workload.py:1137-1140`, `runner/libs/app_runners/tracee.py:468-473`) but are not selected anywhere in the current `macro_apps.yaml`, so they do not affect the next `vm-corpus` run.

### 5. I-daemon map_inline 放宽

#### Finding 5.1

- Severity: `LOW`
- File:line: `daemon/src/passes/map_inline.rs:2553-2561`, `daemon/src/passes/map_inline_tests.rs:625-672`
- Why it matters:
  - The implementation correctly keeps null-check recognition pinned to zero-offset aliases only.
  - The gap is test coverage: the new tests lock in positive alias-offset loads, but they do not explicitly lock in the negative case that a non-zero-offset alias must **not** be treated as a removable null check.
  - That is not a present bug, but it is the easiest future regression point in this relaxation.
- Ready-to-apply diff:

```diff
diff --git a/daemon/src/passes/map_inline_tests.rs b/daemon/src/passes/map_inline_tests.rs
index 9db79236..083d6ea0 100644
--- a/daemon/src/passes/map_inline_tests.rs
+++ b/daemon/src/passes/map_inline_tests.rs
@@ -643,6 +643,24 @@ fn classify_r0_uses_tracks_alias_offset_loads() {
     assert!(uses.other_uses.is_empty());
 }
 
+#[test]
+fn classify_r0_uses_does_not_treat_non_zero_alias_offset_as_null_check() {
+    let insns = vec![
+        call_helper(HELPER_MAP_LOOKUP_ELEM),
+        BpfInsn::mov64_reg(6, 0),
+        add64_imm(6, 4),
+        jeq_imm(6, 0, 1),
+        BpfInsn::ldx_mem(BPF_W, 3, 6, 0),
+    ];
+
+    let uses = classify_r0_uses(&insns, 0);
+    assert_eq!(uses.null_check_pc, None);
+    assert_eq!(uses.other_uses, vec![3]);
+    assert_eq!(
+        uses.fixed_loads,
+        vec![FixedLoadUse { pc: 4, dst_reg: 3, size: BPF_W, offset: 4 }]
+    );
+}
+
 #[test]
 fn classify_r0_uses_can_follow_callee_saved_alias_across_helper_when_enabled() {
     let insns = vec![
```

### 6. `macro_apps.yaml` 切换

#### Finding 6.1

- Severity: `HIGH`
- File:line: `corpus/config/macro_apps.yaml:86-102`, `e2e/cases/tetragon/config_execve_rate.yaml:7-12`, `e2e/cases/tracee/config.yaml:17-30`, `e2e/driver.py:297-325`
- Why it matters:
  - The new `corpus` workload selections are wired, but the parallel `e2e` names are not.
  - `e2e/driver.py` hard-filters case configs to the suite-selected `e2e` workload names and raises if they are absent.
  - Today the suite requests `tetragon_exec_connect_mix` and `tracee_system_edge_mix`, while the checked-in case configs only expose `exec_storm` and `tracee_default`.
  - This does not block `vm-corpus`, but it does break generic `vm-e2e` / `e2e/driver.py all` verification for the same suite.
- Ready-to-apply diff:

```diff
diff --git a/corpus/config/macro_apps.yaml b/corpus/config/macro_apps.yaml
index 57efc056..9db447f6 100644
--- a/corpus/config/macro_apps.yaml
+++ b/corpus/config/macro_apps.yaml
@@ -87,7 +87,7 @@ apps:
   - name: tetragon/default
     runner: tetragon
     workload:
       corpus: tetragon_exec_connect_mix
-      e2e: tetragon_exec_connect_mix
+      e2e: exec_storm
 
   - name: katran
     runner: katran
@@ -99,7 +99,7 @@ apps:
   - name: tracee/default
     runner: tracee
     workload:
       corpus: tracee_system_edge_mix
-      e2e: tracee_system_edge_mix
+      e2e: tracee_default
     duration_s: 5
 
   - name: bpftrace/capable
```

Cross-check on workload-regression risk:

- `runner/libs/workload.py:722-736` keeps Tetragon's exec load and adds connect load, so the switch from `exec_storm` to `tetragon_exec_connect_mix` should preserve `event_execve`-family baseline while unlocking the `tcp_connect` block.
- `runner/libs/workload.py:739-760` still exercises file-open and connect-related paths indirectly through `os.open()` and `socket.create_connection()` inside `_accept4_roundtrip()`, so I do not see a second coverage regression bug there beyond the silent cgroup failure noted above.

## Part 2 — 跨 round 交互分析

### X × I-prod

- `tracee --events all` is the main total-program multiplier. If it works correctly, `tracee/default` should jump from the current `37` loaded programs to roughly `120-154`, and suite-wide total programs move from `122` to about `207-241`.
- The new X taxonomy then matters immediately: many of those newly loaded Tracee programs still will not get baseline run counts from the selected workload, so `missing_baseline_exec_ns` should remain the dominant exclusion reason even after the split.
- The important review outcome is that X only tells the truth if Tracee startup is fail-fast. With the current soft stable-set timeout, Tracee can return a partial attachment set and make the X reason counts look artificially cleaner than reality.

### X × workload switches

- `tracee_system_edge_mix` should convert the currently changed-but-missing-baseline Tracee programs `144/145/146/157/169/171/172` into comparable rows if the workload really exercises `execveat`, `dup`, `accept4`, failed exec, and cgroup create/remove.
- `tetragon_exec_connect_mix` should convert the currently changed-but-missing-baseline `tcp_connect` subset, but the uplift is smaller than the original Y estimate because only `112/113/114` are already changed today; the other programs in that block are still unchanged and would move into X's no-change split rather than `applied`.
- `bcc/opensnoop` and `bcc/vfsstat` are different: the new exact workloads should improve baseline exercise, but the current programs are unchanged today, so the main effect is likely `missing_baseline_exec_ns -> zero_sites_found`, not `missing -> applied`.
- `tracee_module_load_loop` and `tracee_io_vector_mix` are implemented but dormant in the current suite, so they should not be counted in the next VM uplift.

### X × I-daemon

- The new map-inline relaxations should primarily convert a small number of current no-change rows into changed/applied rows; they do not materially change the total discovered-program count.
- That means the taxonomy effect is mostly a bucket migration:
  - before: many unchanged programs collapsed into `no_programs_changed_in_loader`
  - after: the same population should split mostly into `zero_sites_found`, then a smaller `all_sites_rolled_back`, then very few `applied_but_identical`
- `no_programs_changed_in_loader` should be near-zero after this series. If it is still materially present, I would treat that as evidence that X is not exhaustive in practice.

## Part 3 — VM 前必修清单

### `BLOCKER`

- Fix the Katran import-time `NameError` in `runner/libs/app_runners/katran.py` before `vm-corpus`. As-is, the suite cannot construct the Katran runner at all.

### `HIGH`

- Make Tracee fail when the program set never stabilizes and raise the load timeout to `120s`; otherwise `--events all` can silently undercount.
- Restore valid `e2e` workload names in `macro_apps.yaml` (or add matching entries to the case configs) before trusting `vm-e2e` / `e2e/driver.py all`.

## Part 4 — 预期 VM 结果

Assuming the series is correct **and** the `BLOCKER` / `HIGH` items above are fixed:

- `total programs`
  - Current: `122`
  - Expected next run: about `207-241`
  - Main driver: `tracee/default` moving from `37` loaded programs toward roughly `120-154`, plus Katran moving from `1` toward `3`.

- `applied_sample_count`
  - Current: `23`
  - Expected next run: about `35-45`
  - Reasoning:
    - `tracee_system_edge_mix`: roughly `+7`
    - `tetragon_exec_connect_mix`: roughly `+3`
    - `map_inline` relaxation: roughly `+2..8`
    - `tracee --events all`: possible extra upside, but much smaller than the total-program increase because many extra programs will still be outside the selected workload's exercised set

- `comparison_exclusion_reason` distribution
  - `missing_baseline_exec_ns`: still dominant, roughly `135-155`
  - `zero_sites_found`: roughly `25-40`
  - `all_sites_rolled_back`: roughly `3-7`
  - `applied_but_identical`: roughly `0-2`
  - `no_passes_requested`: `0`
  - `no_programs_changed_in_loader`: should be approximately `0`; any real count here is a red flag

- likely failure / non-success paths
  - `Katran` import failure if the constant-order blocker is left as-is
  - `Tracee` startup timeout before health if the VM is especially slow
  - `Tracee` stable-set timeout after health if `--events all` keeps attaching longer than the post-health timeout window
  - `tracee_system_edge_mix` cgroup path not permitted in the VM: with the proposed fix this fails loudly; without it, it silently drops two target programs
  - `open_family_storm` on a kernel/runtime where `openat2` is unavailable: with the proposed fix this fails loudly; without it, it silently degrades
  - `tracee_module_load_loop` is not in the current suite, but if enabled later it depends on `modprobe`, root, and a usable repo-provided modules tree

## Part 5 — 判定

`1 blocker must fix before VM`
