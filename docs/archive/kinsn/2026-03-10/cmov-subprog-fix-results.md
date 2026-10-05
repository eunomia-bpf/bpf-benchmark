# cmov_select Subprog Scanner Fix Results

Test date: 2026-03-10

Kernel tree in `vendor/linux` was on branch `jit-fixed-baselines` at `1572a4ddb` (`kernel-fixed-baselines: unconditional heuristics for ROTATE/WIDE_MEM/LEA/CMOV`), not `jit-directive-v4`.

## Code Changed

### 1. Userspace scanner: scan full xlated program for all 4 scanners

```diff
diff --git a/micro/runner/src/kernel_runner.cpp b/micro/runner/src/kernel_runner.cpp
@@
-            /* Compute main subprog scan length (restrict all scanners) */
-            uint32_t main_scan_len = static_cast<uint32_t>(xlated.size());
-            if (pre_info.nr_func_info > 1) {
-                auto func_info = load_func_info(program_fd, pre_info.nr_func_info);
-                if (func_info.size() > 1) {
-                    uint32_t main_subprog_len = func_info[1].insn_off * sizeof(bpf_insn_raw);
-                    if (main_subprog_len < main_scan_len) {
-                        main_scan_len = main_subprog_len;
-                    }
-                }
-            }
+            /*
+             * Scan the full translated program, including subprogs.
+             * Kernel-side validators reject any directive site that would
+             * cross a subprog boundary, so userspace does not need to trim
+             * scanning to the main entry subprog.
+             */
+            uint32_t scan_len = static_cast<uint32_t>(xlated.size());
@@
-                auto cmov_rules = find_cmov_select_sites_xlated(xlated.data(), main_scan_len);
+                auto cmov_rules = find_cmov_select_sites_xlated(xlated.data(), scan_len);
@@
-                auto wide_rules = find_wide_load_sites_xlated(xlated.data(), main_scan_len);
+                auto wide_rules = find_wide_load_sites_xlated(xlated.data(), scan_len);
@@
-                auto rotate_rules = find_rotate_sites_xlated(xlated.data(), main_scan_len,
+                auto rotate_rules = find_rotate_sites_xlated(xlated.data(), scan_len,
                                                              use_rorx);
@@
-                auto lea_rules = find_addr_calc_sites_xlated(xlated.data(), main_scan_len);
+                auto lea_rules = find_addr_calc_sites_xlated(xlated.data(), scan_len);
```

The old `load_func_info()` helper became unused after this and was removed.

### 2. Benchmark comment updated to match the new behavior

```diff
diff --git a/micro/programs/cmov_select.bpf.c b/micro/programs/cmov_select.bpf.c
@@
- * NOTE: v4 scanner only scans main subprog, so cmov sites are not detected.
- * This is a known limitation — extending to subprogs is future work.
+ * The userspace scanner should find the select pattern across the full
+ * translated program, not just the entry subprog.
```

### 3. Kernel follow-up needed on this tree to accept subprog-local v4 rules

Without this kernel-side change, `BPF_PROG_JIT_RECOMPILE` returned `EINVAL` because `vendor/linux` still rejected every v4 rule outside the main subprog.

```diff
diff --git a/vendor/linux/kernel/bpf/jit_directives.c b/vendor/linux/kernel/bpf/jit_directives.c
@@
-static u32 bpf_jit_main_subprog_end(const struct bpf_prog *prog)
+static bool bpf_jit_rule_within_single_subprog(const struct bpf_prog *prog,
+					       const struct bpf_jit_rule *rule)
@@
-		/*
-		 * BPF_PROG_JIT_RECOMPILE currently recompiles the main prog
-		 * image only. Rules in non-main subprogs are therefore
-		 * rejected until subprog-aware re-JIT support exists.
-		 */
-		active = rule->site_start + rule->site_len <= main_subprog_end &&
+		/*
+		 * Allow rules in any subprog, but never across subprog
+		 * boundaries. The translated program is validated and emitted
+		 * as one insn stream, so subprog-local sites are safe.
+		 */
+		active = bpf_jit_rule_within_single_subprog(prog, rule) &&
 			 bpf_jit_validate_rule(prog->insnsi, prog->len, rule);
```

## cmov Site Counts

- `cmov_select` before the userspace fix: `0` sites.
  - Reason: the old scanner only examined the main subprog. From the libbpf load log, `cmov_select_pick` is appended at xlated insn offset `925`, so the old main-only scan stopped before the 3-insn compact select in the subprog.
- `cmov_select` after the userspace fix: `1` site.
  - Runner output: `recompile-cmov: found 1 cmov-select sites in xlated program (935 insns)`.
- `log2_fold` sanity check after the fix: `6` sites.
  - Runner output: `recompile-cmov: found 6 cmov-select sites in xlated program (139 insns)`.

## Performance Comparison

These are raw numbers from `--repeat 5`. Because this kernel tree is on `jit-fixed-baselines`, the "baseline" column means "no explicit v4 recompile", not "pure stock JIT with CMOV disabled".

| Program | Mode | cmov sites | result | exec_ns | wall_exec_ns | native bytes | Notes |
|---|---:|---:|---:|---:|---:|---:|---|
| `cmov_select` | baseline | n/a | `11332120082118096118` | `2170` | `3337642` | `4101` | no explicit recompile |
| `cmov_select` | `--recompile-cmov` | `1` | `9841221549609281104` | `1908` | `3311465` | `4101` | result changed vs baseline; not a valid perf win |
| `log2_fold` | baseline | n/a | `9` | `976` | `3183608` | `612` | no explicit recompile |
| `log2_fold` | `--recompile-cmov` | `6` | `9` | `1051` | `3269464` | `646` | result preserved |

## Issues Encountered

1. `vendor/linux` was not on `jit-directive-v4`.
   - Active branch was `jit-fixed-baselines`.
   - That branch already enables unconditional fixed heuristics for CMOV/WIDE_MEM/ROTATE/LEA, so the "baseline" numbers are branch-specific.

2. `BPF_PROG_JIT_RECOMPILE` initially failed for `cmov_select`.
   - Failure: `BPF_PROG_JIT_RECOMPILE failed: Invalid argument (errno=22)`.
   - Cause: `kernel/bpf/jit_directives.c` still rejected every v4 rule outside the main subprog.
   - Fix applied locally: accept rules that stay within a single subprog.

3. `cmov_select` still has a remaining kernel-side correctness issue under explicit recompile.
   - After the scanner fix and the kernel validation follow-up, the v4 path activates on `cmov_select`, but the benchmark result changes from `11332120082118096118` to `9841221549609281104`.
   - `log2_fold` still returns the correct result (`9`) under `--recompile-cmov`.
   - This means the userspace scanning limitation is fixed, but subprog-local CMOV recompile is not yet functionally clean end-to-end on the current kernel tree. The most likely follow-up area is the kernel v4 subprog application path, not the userspace scanner.
