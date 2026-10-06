# 2026-04-22 Delete Verification

- 只读验证；未改代码、未跑 VM。唯一写入是本报告。
- 最终扫描命令基线：`rg -u -n --glob '!vendor/**' --glob '!**/results/**' --glob '!runner/build-*/**' --glob '!docs/tmp/**' "<pattern>"`。
- 之所以用 `-u`：plain `rg` 会漏掉 ignore 规则下的 `runner/repos/**`，`prog_fds` 已实证会漏扫。
- `description:` 额外做了语义收窄：只把 “YAML 里的 per-tool description 字段” 作为 cleanup 目标面；否则 raw repo-wide YAML literal 会被 `runner/repos/**` 的 CRD/manifests 噪音淹没。

## Part 1: Pattern-by-Pattern

### ⚠ `target_programs`
- hit 数量：1
- 备注：active source dirs (`runner e2e corpus daemon tests`) 0 hit；repo-wide 唯一命中在历史计划文档。
- 明细：
  - `./docs/kernel-jit-optimization-plan.md:1041`

    ```text
     1039: | **662** | **Wave 1.5 AWS arm64 复验（2026-04-21）** | ✅ | `make aws-e2e RUN_TARGET_ARCH=arm64` **ALL PASSED**（tracee/tetragon/bpftrace/scx/bcc/katran 6/6）；`make aws-corpus RUN_TARGET_ARCH=arm64` status `ok`，`aws_arm64_corpus_20260422_044304_037607` **20/20 app ok**，applied-only geomean **0.986x**，applied sample 10。相对 pre-wave1 baseline `aws_arm64_corpus_20260421_213547_871838`：`applied_sample_count` **16→10**、`no_programs_changed_in_loader` **37→36**；applied 回落全部来自 `tracee/default` — 后 wave1 只报告两个 raw-syscall tracee program（与 AWS x86 post-wave1 一致），不是 rejit 问题。报告：`docs/tmp/wave1.5-aws-arm64-verify-20260421/summary.md`。commit `b9c807f0`。 |
     1040: | **663** | **2026-04-21/22 三目标 corpus authoritative 重跑** | ✅ | 单会话跑完 KVM x86 / AWS x86 / AWS arm64 三套 corpus，全部 20/20 app ok：`x86_kvm_corpus_20260421_232916_947372`（30 samples，all-comparable geomean **1.010x**，applied sample 12）；`aws_x86_corpus_20260422_012001_472335`（1 sample，**0.983x**，applied sample 10）；`aws_arm64_corpus_20260422_044304_037607`（1 sample，**0.986x**，applied sample 10）。三目标 `no_programs_changed_in_loader` 统一 **36**。该 reason 的真实语义见 #664 调研（不是 bytes same-size gap）。 |
    >1041: | **664** | **`no_programs_changed_in_loader` 语义 + program count 调研（2026-04-21）** | ✅ | 代码级结论：(a) reason 判定代码 `corpus/driver.py:471-540` 只看 daemon semantic signal（`summary.program_changed` / `total_sites_applied` / `passes_applied`），**根本没比较 bytes_jited/xlated/JIT image hash**。反例：`scx/rusty:rusty_exit_task` baseline/rejit 都 `bytes_jited=232` 但 `changed=true, comparable=true`。(b) 真实含义是混了三类的 observability bucket：0 site 命中 + pass 命中但 verifier 全 rollback（`tetragon/default:event_execve`：map_inline 7 sites rolled_back + const_prop 1 site rolled_back → `program_changed=false`）+ apply 成功但最终 program_changed=false。**非 apply bug，是 taxonomy 过粗**。(c) ~48 program 总量符合 app-centric 设计（旧口径 469 obj / 2019 prog 是 object-centric，非同一量级）：`katran=1` 按设计（`KatranRunner.start()` 只返回 balancer ingress）；`tracee=2/3` 是 FD-owned discovery undercount（`runner/libs/agent.py:90-141` attach 完关 fd 就不见了，历史 VM 曾测 44 个）；`tetragon=1` 是 corpus runner adapter 没传 e2e 的 `target_programs/apply_programs` config（`runner/libs/app_runners/__init__.py:63-69` vs `e2e/cases/tetragon/config_execve_rate.yaml:11-17`）。**建议动作**（未实施）：拆 exclusion reason 为 4 子类；Tracee runner 加 global `bpftool prog show` before/after diff 模式；Tetragon corpus 路径复用 e2e config。报告：`docs/tmp/no-changed-in-loader-investigation-20260421/summary.md`。 |
     1042: | **665** | **KVM x86 corpus rerun after `_configure_program_selection` TypeError fix（2026-04-22）** | ⚠️ | 失败 rerun `x86_kvm_corpus_20260422_054946_580134` 的根因是 `567df095` 删除 `_configure_program_selection()` 的 `measurement_mode` 形参时漏改 `run_suite()` active-session 调用；最小修复是在 `corpus/driver.py` 删掉 stray `measurement_mode=` kwarg。单 app 复验：`bcc/capable` `x86_kvm_corpus_20260422_063229_887355` ok，`bpftrace/tcpretrans` `x86_kvm_corpus_20260422_063749_285833` ok，attach failure 未复现。两次完整 `make vm-corpus SAMPLES=30` rerun 均 `20/20 app ok`：`x86_kvm_corpus_20260422_064321_184850`（all-comparable geomean **1.091x**，applied sample 16，`no_programs_changed_in_loader` 37）和 confirmatory `x86_kvm_corpus_20260422_073105_905677`（**1.105x**，16，37）。相对 authority run #663 的 `1.010x / 12 / 36` 仍偏高；主要漂动为 `tetragon/default` `1/0 -> 6/4`、`bpftrace/runqlat` `-5.9%`、`bpftrace/tcpretrans` `-15.4%`。报告：`docs/tmp/kvm-x86-rerun-20260421/summary.md`。 |
     1043: | **666** | **Wave 3 silent-failure review（2026-04-22）** | 🔍 | 1 CRITICAL（runner 把 `applied` 当 `changed` 用）+ 4 HIGH（bpftool schema drift / counts TypeError / daemon CPU-count fallback / tracee event parse 静默丢行）+ 2 MEDIUM + 1 LOW。报告：`docs/tmp/wave3-silent-failure-review-20260422/summary.md`。待修。 |
    ```
    判定：文档残留；历史调研/计划说明，不是 active source。


### ⚠ `apply_programs`
- hit 数量：1
- 备注：active source dirs (`runner e2e corpus daemon tests`) 0 hit；repo-wide 唯一命中在历史计划文档。
- 明细：
  - `./docs/kernel-jit-optimization-plan.md:1041`

    ```text
     1039: | **662** | **Wave 1.5 AWS arm64 复验（2026-04-21）** | ✅ | `make aws-e2e RUN_TARGET_ARCH=arm64` **ALL PASSED**（tracee/tetragon/bpftrace/scx/bcc/katran 6/6）；`make aws-corpus RUN_TARGET_ARCH=arm64` status `ok`，`aws_arm64_corpus_20260422_044304_037607` **20/20 app ok**，applied-only geomean **0.986x**，applied sample 10。相对 pre-wave1 baseline `aws_arm64_corpus_20260421_213547_871838`：`applied_sample_count` **16→10**、`no_programs_changed_in_loader` **37→36**；applied 回落全部来自 `tracee/default` — 后 wave1 只报告两个 raw-syscall tracee program（与 AWS x86 post-wave1 一致），不是 rejit 问题。报告：`docs/tmp/wave1.5-aws-arm64-verify-20260421/summary.md`。commit `b9c807f0`。 |
     1040: | **663** | **2026-04-21/22 三目标 corpus authoritative 重跑** | ✅ | 单会话跑完 KVM x86 / AWS x86 / AWS arm64 三套 corpus，全部 20/20 app ok：`x86_kvm_corpus_20260421_232916_947372`（30 samples，all-comparable geomean **1.010x**，applied sample 12）；`aws_x86_corpus_20260422_012001_472335`（1 sample，**0.983x**，applied sample 10）；`aws_arm64_corpus_20260422_044304_037607`（1 sample，**0.986x**，applied sample 10）。三目标 `no_programs_changed_in_loader` 统一 **36**。该 reason 的真实语义见 #664 调研（不是 bytes same-size gap）。 |
    >1041: | **664** | **`no_programs_changed_in_loader` 语义 + program count 调研（2026-04-21）** | ✅ | 代码级结论：(a) reason 判定代码 `corpus/driver.py:471-540` 只看 daemon semantic signal（`summary.program_changed` / `total_sites_applied` / `passes_applied`），**根本没比较 bytes_jited/xlated/JIT image hash**。反例：`scx/rusty:rusty_exit_task` baseline/rejit 都 `bytes_jited=232` 但 `changed=true, comparable=true`。(b) 真实含义是混了三类的 observability bucket：0 site 命中 + pass 命中但 verifier 全 rollback（`tetragon/default:event_execve`：map_inline 7 sites rolled_back + const_prop 1 site rolled_back → `program_changed=false`）+ apply 成功但最终 program_changed=false。**非 apply bug，是 taxonomy 过粗**。(c) ~48 program 总量符合 app-centric 设计（旧口径 469 obj / 2019 prog 是 object-centric，非同一量级）：`katran=1` 按设计（`KatranRunner.start()` 只返回 balancer ingress）；`tracee=2/3` 是 FD-owned discovery undercount（`runner/libs/agent.py:90-141` attach 完关 fd 就不见了，历史 VM 曾测 44 个）；`tetragon=1` 是 corpus runner adapter 没传 e2e 的 `target_programs/apply_programs` config（`runner/libs/app_runners/__init__.py:63-69` vs `e2e/cases/tetragon/config_execve_rate.yaml:11-17`）。**建议动作**（未实施）：拆 exclusion reason 为 4 子类；Tracee runner 加 global `bpftool prog show` before/after diff 模式；Tetragon corpus 路径复用 e2e config。报告：`docs/tmp/no-changed-in-loader-investigation-20260421/summary.md`。 |
     1042: | **665** | **KVM x86 corpus rerun after `_configure_program_selection` TypeError fix（2026-04-22）** | ⚠️ | 失败 rerun `x86_kvm_corpus_20260422_054946_580134` 的根因是 `567df095` 删除 `_configure_program_selection()` 的 `measurement_mode` 形参时漏改 `run_suite()` active-session 调用；最小修复是在 `corpus/driver.py` 删掉 stray `measurement_mode=` kwarg。单 app 复验：`bcc/capable` `x86_kvm_corpus_20260422_063229_887355` ok，`bpftrace/tcpretrans` `x86_kvm_corpus_20260422_063749_285833` ok，attach failure 未复现。两次完整 `make vm-corpus SAMPLES=30` rerun 均 `20/20 app ok`：`x86_kvm_corpus_20260422_064321_184850`（all-comparable geomean **1.091x**，applied sample 16，`no_programs_changed_in_loader` 37）和 confirmatory `x86_kvm_corpus_20260422_073105_905677`（**1.105x**，16，37）。相对 authority run #663 的 `1.010x / 12 / 36` 仍偏高；主要漂动为 `tetragon/default` `1/0 -> 6/4`、`bpftrace/runqlat` `-5.9%`、`bpftrace/tcpretrans` `-15.4%`。报告：`docs/tmp/kvm-x86-rerun-20260421/summary.md`。 |
     1043: | **666** | **Wave 3 silent-failure review（2026-04-22）** | 🔍 | 1 CRITICAL（runner 把 `applied` 当 `changed` 用）+ 4 HIGH（bpftool schema drift / counts TypeError / daemon CPU-count fallback / tracee event parse 静默丢行）+ 2 MEDIUM + 1 LOW。报告：`docs/tmp/wave3-silent-failure-review-20260422/summary.md`。待修。 |
    ```
    判定：文档残留；历史调研/计划说明，不是 active source。


### ✅ `expected_programs`
- hit 数量：0
- 备注：repo-wide 0 hit。
- 判定：零 active source match。

### ✅ `expected_program_names`
- hit 数量：0
- 备注：repo-wide 0 hit。
- 判定：零 active source match。

### ✅ `apply_program_names`
- hit 数量：0
- 备注：repo-wide 0 hit。
- 判定：零 active source match。

### ✅ `selected_tracee_programs`
- hit 数量：0
- 备注：repo-wide 0 hit。
- 判定：零 active source match。

### ✅ `selected_tetragon_programs`
- hit 数量：0
- 备注：repo-wide 0 hit。
- 判定：零 active source match。

### ✅ `selected_scx_programs`
- hit 数量：0
- 备注：repo-wide 0 hit。
- 判定：零 active source match。

### ✅ `select_configured_programs`
- hit 数量：0
- 备注：repo-wide 0 hit。
- 判定：零 active source match。

### ✅ `select_tracee_programs`
- hit 数量：0
- 备注：repo-wide 0 hit。
- 判定：零 active source match。

### ✅ `select_tetragon_programs`
- hit 数量：0
- 备注：repo-wide 0 hit。
- 判定：零 active source match。

### ✅ `select_scx_programs`
- hit 数量：0
- 备注：repo-wide 0 hit。
- 判定：零 active source match。

### ✅ `select_corpus_program_ids`
- hit 数量：0
- 备注：repo-wide 0 hit。
- 判定：零 active source match。

### ✅ `select_active_program_ids`
- hit 数量：0
- 备注：repo-wide 0 hit。
- 判定：零 active source match。

### ✅ `_filter_expected_programs`
- hit 数量：0
- 备注：repo-wide 0 hit。
- 判定：零 active source match。

### 🔴 `_select_program`
- hit 数量：2
- 备注：Katran 仍有活代码 helper 和调用位点；不是 rename/comment。
- 明细：
  - `./runner/libs/app_runners/katran.py:445`

    ```text
     443:         try:
     444:             session.__enter__(); self.session = session; self.command_used = list(command)
    >445:             self.programs = [dict(p) for p in session.programs]; self.program = self._select_program(self.programs)
     446:             self.maps_by_name = self._discover_maps(before_map_ids); self.attach_info = _attached_xdp_info(self.iface)
     447:         except Exception:
    ```
    判定：活代码残留；Katran 仍保留单程序选择 helper / 调用路径。

  - `./runner/libs/app_runners/katran.py:467`

    ```text
     465:         return {} if self.session is None else self.session.collector_snapshot()
     466: 
    >467:     def _select_program(self, programs: list[dict[str, object]]) -> dict[str, object]:
     468:         if not programs: raise RuntimeError("Katran server did not expose any BPF programs")
     469:         expected_names = {DEFAULT_KATRAN_PROGRAM_NAME, DEFAULT_KATRAN_PROGRAM_NAME[:BPF_OBJECT_NAME_LIMIT]}
    ```
    判定：活代码残留；Katran 仍保留单程序选择 helper / 调用路径。


### ✅ `wait_for_attached_programs`
- hit 数量：0
- 备注：repo-wide 0 hit。
- 判定：零 active source match。

### 🔴 `requested_prog_ids`
- hit 数量：34
- 备注：补充 grep：quoted key `"requested_prog_ids"` / `'requested_prog_ids'` 在 `runner e2e corpus daemon` 为 0，说明旧 artifact echo key 已删；但 runner/corpus 内部 helper / 形参 / 局部变量名仍大量保留。
- 明细：
  - `./corpus/driver.py:911`

    ```text
     909:     prog_ids: Sequence[int],
     910: ) -> dict[str, object]:
    >911:     requested_prog_ids = [int(value) for value in prog_ids if int(value) > 0]
     912:     if not requested_prog_ids:
     913:         return {}
    ```
    判定：活代码残留；内部局部变量/形参仍使用 `requested_prog_ids`，不是 artifact metadata key。

  - `./corpus/driver.py:912`

    ```text
     910: ) -> dict[str, object]:
     911:     requested_prog_ids = [int(value) for value in prog_ids if int(value) > 0]
    >912:     if not requested_prog_ids:
     913:         return {}
     914: 
    ```
    判定：活代码残留；内部局部变量/形参仍使用 `requested_prog_ids`，不是 artifact metadata key。

  - `./corpus/driver.py:921`

    ```text
     919:     applied_sites = 0
     920:     exit_code = 0
    >921:     for prog_id in requested_prog_ids:
     922:         record = rejit_program_result(rejit_result, prog_id)
     923:         if not record:
    ```
    判定：活代码残留；内部局部变量/形参仍使用 `requested_prog_ids`，不是 artifact metadata key。

  - `./corpus/driver.py:954`

    ```text
     952:         },
     953:         "program_counts": {
    >954:             "requested": len(requested_prog_ids),
     955:             "applied": sum(1 for record in per_program.values() if bool(record.get("applied"))),
     956:             "not_applied": sum(1 for record in per_program.values() if not bool(record.get("applied"))),
    ```
    判定：活代码残留；内部局部变量/形参仍使用 `requested_prog_ids`，不是 artifact metadata key。

  - `./corpus/driver.py:1079`

    ```text
     1077:     kinsn_recorded: bool = False
     1078: 
    >1079:     def requested_prog_ids(self) -> list[int]:
     1080:         return [int(value) for value in self.state.apply_prog_ids if int(value) > 0]
     1081: 
    ```
    判定：活代码残留；corpus session helper 方法名仍是 `requested_prog_ids()`。

  - `./corpus/driver.py:1295`

    ```text
     1293: 
     1294:                 if not fatal_error and active_sessions:
    >1295:                     requested_prog_ids = [
     1296:                         prog_id
     1297:                         for session in active_sessions
    ```
    判定：活代码残留；内部局部变量/形参仍使用 `requested_prog_ids`，不是 artifact metadata key。

  - `./corpus/driver.py:1298`

    ```text
     1296:                         prog_id
     1297:                         for session in active_sessions
    >1298:                         for prog_id in session.requested_prog_ids()
     1299:                     ]
     1300:                     scan_enabled_passes, benchmark_config, selection_source = _resolve_scan_pass_selection(None)
    ```
    判定：活代码残留；内部局部变量/形参仍使用 `requested_prog_ids`，不是 artifact metadata key。

  - `./corpus/driver.py:1302`

    ```text
     1300:                     scan_enabled_passes, benchmark_config, selection_source = _resolve_scan_pass_selection(None)
     1301:                     scan_results = prepared_daemon_session.session.scan_programs(
    >1302:                         requested_prog_ids,
     1303:                         enabled_passes=scan_enabled_passes,
     1304:                     )
    ```
    判定：活代码残留；内部局部变量/形参仍使用 `requested_prog_ids`，不是 artifact metadata key。

  - `./corpus/driver.py:1309`

    ```text
     1307:                         apply_enabled_passes_by_prog.update(
     1308:                             _resolve_apply_passes_by_program(
    >1309:                                 requested_prog_ids=session.requested_prog_ids(),
     1310:                                 lifecycle_state=session.state,
     1311:                                 scan_results=scan_results,
    ```
    判定：活代码残留；内部局部变量/形参仍使用 `requested_prog_ids`，不是 artifact metadata key。

  - `./corpus/driver.py:1318`

    ```text
     1316:                         session.scan_results = _slice_scan_results(
     1317:                             scan_results,
    >1318:                             session.requested_prog_ids(),
     1319:                         )
     1320: 
    ```
    判定：活代码残留；内部局部变量/形参仍使用 `requested_prog_ids`，不是 artifact metadata key。

  - `./corpus/driver.py:1322`

    ```text
     1320: 
     1321:                     grouped_prog_ids: dict[tuple[str, ...], list[int]] = {}
    >1322:                     for prog_id in requested_prog_ids:
     1323:                         pass_tuple = tuple(apply_enabled_passes_by_prog.get(int(prog_id), ()))
     1324:                         grouped_prog_ids.setdefault(pass_tuple, []).append(int(prog_id))
    ```
    判定：活代码残留；内部局部变量/形参仍使用 `requested_prog_ids`，不是 artifact metadata key。

  - `./corpus/driver.py:1339`

    ```text
     1337: 
     1338:                     merged_rejit_result = _merge_group_rejit_results(
    >1339:                         requested_prog_ids=requested_prog_ids,
     1340:                         group_results=group_rejit_results,
     1341:                         scan_enabled_passes=scan_enabled_passes,
    ```
    判定：活代码残留；内部局部变量/形参仍使用 `requested_prog_ids`，不是 artifact metadata key。

  - `./corpus/driver.py:1348`

    ```text
     1346:                         session.apply_result = _slice_rejit_result(
     1347:                             merged_rejit_result,
    >1348:                             session.requested_prog_ids(),
     1349:                         )
     1350:                         if session.kinsn_metadata is not None:
    ```
    判定：活代码残留；内部局部变量/形参仍使用 `requested_prog_ids`，不是 artifact metadata key。

  - `./runner/libs/rejit.py:809`

    ```text
     807:     daemon_stderr_path: Path | None = None,
     808: ) -> dict[str, object]:
    >809:     requested_prog_ids = [int(v) for v in (prog_ids or []) if int(v) > 0]
     810:     if not requested_prog_ids:
     811:         raise ValueError("apply_daemon_rejit requires at least one prog_id")
    ```
    判定：活代码残留；内部局部变量/形参仍使用 `requested_prog_ids`，不是 artifact metadata key。

  - `./runner/libs/rejit.py:810`

    ```text
     808: ) -> dict[str, object]:
     809:     requested_prog_ids = [int(v) for v in (prog_ids or []) if int(v) > 0]
    >810:     if not requested_prog_ids:
     811:         raise ValueError("apply_daemon_rejit requires at least one prog_id")
     812:     if daemon_socket_path is None:
    ```
    判定：活代码残留；内部局部变量/形参仍使用 `requested_prog_ids`，不是 artifact metadata key。

  - `./runner/libs/rejit.py:834`

    ```text
     832:                 "per_program": {int(pid): {"prog_id": int(pid), "applied": False, "changed": False,
     833:                                            "output": out, "exit_code": ec, "counts": zc, "error": msg}
    >834:                                 for pid in requested_prog_ids},
     835:                 "program_counts": {"requested": len(requested_prog_ids), "applied": 0, "not_applied": len(requested_prog_ids)},
     836:             }
    ```
    判定：活代码残留；内部局部变量/形参仍使用 `requested_prog_ids`，不是 artifact metadata key。

  - `./runner/libs/rejit.py:835`

    ```text
     833:                                            "output": out, "exit_code": ec, "counts": zc, "error": msg}
     834:                                 for pid in requested_prog_ids},
    >835:                 "program_counts": {"requested": len(requested_prog_ids), "applied": 0, "not_applied": len(requested_prog_ids)},
     836:             }
     837:     for prog_id in requested_prog_ids:
    ```
    判定：活代码残留；内部局部变量/形参仍使用 `requested_prog_ids`，不是 artifact metadata key。

  - `./runner/libs/rejit.py:837`

    ```text
     835:                 "program_counts": {"requested": len(requested_prog_ids), "applied": 0, "not_applied": len(requested_prog_ids)},
     836:             }
    >837:     for prog_id in requested_prog_ids:
     838:         _resp = _optimize_request(daemon_socket_path, prog_id, enabled_passes=enabled_passes, dry_run=False,
     839:                                    daemon_proc=daemon_proc, stdout_path=daemon_stdout_path, stderr_path=daemon_stderr_path)
    ```
    判定：活代码残留；内部局部变量/形参仍使用 `requested_prog_ids`，不是 artifact metadata key。

  - `./runner/libs/rejit.py:858`

    ```text
     856:         "output": "\n".join(o for o in outputs if o), "exit_code": exit_code, "per_program": per_program,
     857:         "counts": {"total_sites": total_sites, "applied_sites": applied_sites},
    >858:         "program_counts": {"requested": len(requested_prog_ids), "applied": n_applied, "not_applied": len(requested_prog_ids) - n_applied},
     859:         "error": "; ".join(errors),
     860:     }
    ```
    判定：活代码残留；内部局部变量/形参仍使用 `requested_prog_ids`，不是 artifact metadata key。

  - `./runner/libs/case_common.py:151`

    ```text
     149:     artifacts: dict[str, object] = field(default_factory=dict)
     150: 
    >151:     def requested_prog_ids(self) -> list[int]:
     152:         raw_prog_ids = self.apply_prog_ids or self.target_prog_ids
     153:         return [int(value) for value in raw_prog_ids if int(value) > 0]
    ```
    判定：活代码残留；`CaseLifecycleState` helper 方法名仍是 `requested_prog_ids()`。旧 artifact echo key 已删，但内部 API 名称未清。

  - `./runner/libs/case_common.py:299`

    ```text
     297: def _resolve_apply_passes_by_program(
     298:     *,
    >299:     requested_prog_ids: Sequence[int],
     300:     lifecycle_state: CaseLifecycleState,
     301:     scan_results: Mapping[int, Mapping[str, object]],
    ```
    判定：活代码残留；内部局部变量/形参仍使用 `requested_prog_ids`，不是 artifact metadata key。

  - `./runner/libs/case_common.py:309`

    ```text
     307:     explicit_passes = _normalize_enabled_passes(enabled_passes)
     308:     if enabled_passes is not None:
    >309:         return {int(prog_id): list(explicit_passes) for prog_id in requested_prog_ids}
     310:     if _BENCH_PASSES_ENV in os.environ:
     311:         selected = benchmark_rejit_enabled_passes()
    ```
    判定：活代码残留；内部局部变量/形参仍使用 `requested_prog_ids`，不是 artifact metadata key。

  - `./runner/libs/case_common.py:312`

    ```text
     310:     if _BENCH_PASSES_ENV in os.environ:
     311:         selected = benchmark_rejit_enabled_passes()
    >312:         return {int(prog_id): list(selected) for prog_id in requested_prog_ids}
     313:     if not isinstance(benchmark_config, Mapping):
     314:         raise RuntimeError("benchmark pass plan expected a loaded benchmark config")
    ```
    判定：活代码残留；内部局部变量/形参仍使用 `requested_prog_ids`，不是 artifact metadata key。

  - `./runner/libs/case_common.py:323`

    ```text
     321:             site_counts=_scan_record_counts(scan_results, int(prog_id)),
     322:         )
    >323:         for prog_id in requested_prog_ids
     324:     }
     325: 
    ```
    判定：活代码残留；内部局部变量/形参仍使用 `requested_prog_ids`，不是 artifact metadata key。

  - `./runner/libs/case_common.py:329`

    ```text
     327: def _merge_group_rejit_results(
     328:     *,
    >329:     requested_prog_ids: Sequence[int],
     330:     group_results: Sequence[tuple[list[int], Mapping[str, object]]],
     331:     scan_enabled_passes: Sequence[str],
    ```
    判定：活代码残留；内部局部变量/形参仍使用 `requested_prog_ids`，不是 artifact metadata key。

  - `./runner/libs/case_common.py:382`

    ```text
     380:     applied = any(bool(record.get("applied")) for record in per_program.values())
     381:     changed = any(bool(record.get("changed")) for record in per_program.values())
    >382:     n_req = len([p for p in requested_prog_ids if int(p) > 0])
     383:     n_applied = sum(1 for r in per_program.values() if bool(r.get("applied")))
     384:     merged: dict[str, object] = {
    ```
    判定：活代码残留；内部局部变量/形参仍使用 `requested_prog_ids`，不是 artifact metadata key。

  - `./runner/libs/case_common.py:438`

    ```text
     436:         lifecycle_state = start(setup_state)
     437:         artifacts.update(dict(lifecycle_state.artifacts))
    >438:         requested_prog_ids = lifecycle_state.requested_prog_ids()
     439:         if not requested_prog_ids:
     440:             raise RuntimeError("lifecycle did not provide any requested program ids")
    ```
    判定：活代码残留；内部局部变量/形参仍使用 `requested_prog_ids`，不是 artifact metadata key。

  - `./runner/libs/case_common.py:439`

    ```text
     437:         artifacts.update(dict(lifecycle_state.artifacts))
     438:         requested_prog_ids = lifecycle_state.requested_prog_ids()
    >439:         if not requested_prog_ids:
     440:             raise RuntimeError("lifecycle did not provide any requested program ids")
     441:         if bool(getattr(active_daemon_session, "load_kinsn", False)):
    ```
    判定：活代码残留；内部局部变量/形参仍使用 `requested_prog_ids`，不是 artifact metadata key。

  - `./runner/libs/case_common.py:464`

    ```text
     462:                 return _abort_result(baseline, "before_rejit")
     463: 
    >464:         requested_prog_ids = lifecycle_state.requested_prog_ids()
     465:         if not requested_prog_ids:
     466:             raise RuntimeError("lifecycle did not provide any requested program ids after baseline")
    ```
    判定：活代码残留；内部局部变量/形参仍使用 `requested_prog_ids`，不是 artifact metadata key。

  - `./runner/libs/case_common.py:465`

    ```text
     463: 
     464:         requested_prog_ids = lifecycle_state.requested_prog_ids()
    >465:         if not requested_prog_ids:
     466:             raise RuntimeError("lifecycle did not provide any requested program ids after baseline")
     467: 
    ```
    判定：活代码残留；内部局部变量/形参仍使用 `requested_prog_ids`，不是 artifact metadata key。

  - `./runner/libs/case_common.py:478`

    ```text
     476:         scan_kwargs["enabled_passes"] = list(scan_enabled_passes)
     477:         scan_results = active_daemon_session.scan_programs(
    >478:             requested_prog_ids,
     479:             **scan_kwargs,
     480:         )
    ```
    判定：活代码残留；内部局部变量/形参仍使用 `requested_prog_ids`，不是 artifact metadata key。

  - `./runner/libs/case_common.py:485`

    ```text
     483:             raise RuntimeError(daemon_error)
     484:         apply_enabled_passes_by_prog = _resolve_apply_passes_by_program(
    >485:             requested_prog_ids=requested_prog_ids,
     486:             lifecycle_state=lifecycle_state,
     487:             scan_results=scan_results,
    ```
    判定：活代码残留；内部局部变量/形参仍使用 `requested_prog_ids`，不是 artifact metadata key。

  - `./runner/libs/case_common.py:492`

    ```text
     490:         )
     491:         grouped_prog_ids: dict[tuple[str, ...], list[int]] = {}
    >492:         for prog_id in requested_prog_ids:
     493:             pass_tuple = tuple(apply_enabled_passes_by_prog.get(int(prog_id), ()))
     494:             grouped_prog_ids.setdefault(pass_tuple, []).append(int(prog_id))
    ```
    判定：活代码残留；内部局部变量/形参仍使用 `requested_prog_ids`，不是 artifact metadata key。

  - `./runner/libs/case_common.py:501`

    ```text
     499:         ]
     500:         rejit_result = _merge_group_rejit_results(
    >501:             requested_prog_ids=requested_prog_ids,
     502:             group_results=group_rejit_results,
     503:             scan_enabled_passes=scan_enabled_passes,
    ```
    判定：活代码残留；内部局部变量/形参仍使用 `requested_prog_ids`，不是 artifact metadata key。


### ⚠ `prog_fds`
- hit 数量：19
- 备注：补充 grep：`prog_fds` 在 `runner/libs e2e corpus daemon` 为 0；剩余命中都不是 Python runner scan/apply prerequisite。
- 明细：
  - `./docs/kernel-jit-optimization-plan.md:1013`

    ```text
     1011: | **634** | llvmbpf round-trip 四轮修复 | ✅ | **Round 1**：`last insn` 清零，lift 556→779，verifier 7→16（3.9%）。**Round 2**（.bpf.o 路径）：map relocation repair，verifier **157/413（38.0%）**。**Round 3**：GET_ORIGINAL+REJIT 正确路径打通，blocker 是 llvmbpf userspace 栈模型。**Round 4**：kernel_compatible_mode（512B stack + align 8 + implicit extern helper）。**BCC 17/17 全过**。**Tracee 9/33**（iter4）：kernel poke_tab 校验放宽（允许 insn_idx 变化）解决 tail-call EINVAL。剩余 24 fail：15 E2BIG + 8 ENOSPC + 1 verifier EPERM。-O1/Os/Oz 对 E2BIG 无帮助，需要 code-size 降低。报告：`llvmbpf_roundtrip_fix_report`、`llvmbpf_map_relocation_fix_report`、`llvmbpf_map_relocation_vm_results`、`llvmbpf_rejit_roundtrip_poc`、`llvmbpf_kernel_stack_fix_report`（均在 `docs/tmp/20260329/`）。 |
     1012: | 635 | 更多 app runner 实现 | ✅ | 6 个 runner（bcc/tracee/katran/tetragon/bpftrace/scx）。Commit `86bc953`。 |
    >1013: | **636** | 全面 benchmark 架构 review | ✅ | 5 CRITICAL + 14 HIGH + 10 MEDIUM + 2 LOW。核心：bpftool loadall 残留、corpus repeat 没跑、rejit.py prog_fds 丢弃、大量 object-centric 死代码、silent fallback。报告：`strict_final_review_20260329.md`。 |
     1014: | **637** | **新架构 corpus + E2E 端到端验证** | ✅ | corpus suite driver 重写完成（loader-instance lifecycle）。大规模清理 **-21462 行**（`579c081`）。import cycle 修复 5/5（`2dd43c8`）。新增 9 个 app runner。残留清理+Tracee重构（`3101592`）。**2026-04-02 本地 VM 重跑完成**：`make vm-corpus` **20/20 app ok**、applied-only / all-comparable geomean **1.033x**、applied sample **61**；`make vm-e2e` **6/6 ok**。新 YAML schema 已落到 `macro_apps.yaml`，object-centric 规划不再是主线。报告：`corpus_app_native_coverage_and_e2e_dedup`、`benchmark_framework_redesign`、`benchmark_yaml_redesign`、`corpus_e2e_deep_review`（均在 `docs/tmp/20260329/`）。 |
     1015: | 638 | 新 kinsn 调研（6 组） | ✅ | 全部完成。结论：(1) POPCNT/CLZ/PDEP/PEXT/SHRX — **❌ 不做**（corpus 无 site）；(2) ARM64 CCMP — **✅ 值得做**（74 site），MADD/UBFX 低优先级；(3) Prefetch — **✅ 值得做**（17391 map_lookup site，需 PGO），NT store — ❌ 不做；(4) CRC32 — ⏸ 不做默认 pass（loxilb 2 site）；(5) RDTSC + ADC — 待评估；(6) PAUSE/YIELD — ❌ 不做（kernel 已有）。报告均在 `docs/tmp/20260329/`：`bit_ops_kinsn_research`、`arm64_kinsn_research`、`memory_hints_kinsn_research`、`crc32_kinsn_research`、`rdtsc_adc_kinsn_research`、`pause_yield_kinsn_research`。 |
    ```
    判定：文档残留；历史问题记录。

  - `./docs/kernel-jit-optimization-plan.md:1017`

    ```text
     1015: | 638 | 新 kinsn 调研（6 组） | ✅ | 全部完成。结论：(1) POPCNT/CLZ/PDEP/PEXT/SHRX — **❌ 不做**（corpus 无 site）；(2) ARM64 CCMP — **✅ 值得做**（74 site），MADD/UBFX 低优先级；(3) Prefetch — **✅ 值得做**（17391 map_lookup site，需 PGO），NT store — ❌ 不做；(4) CRC32 — ⏸ 不做默认 pass（loxilb 2 site）；(5) RDTSC + ADC — 待评估；(6) PAUSE/YIELD — ❌ 不做（kernel 已有）。报告均在 `docs/tmp/20260329/`：`bit_ops_kinsn_research`、`arm64_kinsn_research`、`memory_hints_kinsn_research`、`crc32_kinsn_research`、`rdtsc_adc_kinsn_research`、`pause_yield_kinsn_research`。 |
     1016: | **639** | **PGO 方案设计 + LBR 验证** | ✅ | **Host-side LBR 对 guest BPF 尚未验证可用**（5s 窗口 IP/branch 命中数=0）。推荐 **Hybrid PGO**：(1) profiler.rs 保留为 hotness collector；(2) sampling 零侵入发现（IP ~+1.37%, LBR ~+1.83%）；(3) selective instrumentation 给 hot subset 补精确 per-branch 数据。优先 BranchFlipPass，PrefetchPass 等 SPE/precise memory。**AWS**: t4g 有 SPE 硬件但 Nitro 是否暴露需实测，t3 有 LBR 但 guest 是否可用需实测，bare metal 才无限制。报告：`bpf_pgo_design_20260329.md`。 |
    >1017: | **640** | **Strict review 修复（删除为主）** | ✅ | **-2865 行**。删除：x86/arm64 远端 benchmark 脚本（bpftool loadall）、catalog.py/object_discovery.py/commands.py（object-centric 死代码）、results.py object-centric 函数、过时测试（test_micro_driver/test_runner_results）。修复：corpus repeat 真跑、rejit.py prog_fds 保留、tracee_support fallback→fail-fast、scx_support ulimit fail-fast。二次 review 确认全部落地，无误删。pytest **71 passed**，daemon-tests **535 passed**。报告：`strict_review_fixes_20260329.md`、`strict_review_second_pass_20260329.md`。 |
     1018: | **641** | **llvmbpf E2BIG root cause 分析** | ✅ | **E2BIG 根因**：LLVM BPF backend lowering 不紧凑，净增 **9352 insns**（1.192x）。67.3% stack spill/reload（+6291）、38% helper marshaling（+3550）、22% scalarization（+2053）。opt -O2 反而比不优化小 ~2x，-Oz 无增量。真实 limit 是 `prog->pages` page-budget（非 1M insn limit）。**ENOSPC 根因**：verifier log buffer exhaustion（log_level=2 的 16MiB 不够），不是 code-size。报告：`llvmbpf_e2big_root_cause_20260329.md`。 |
     1019: | **642** | **llvmbpf Tracee 修复** | ✅ | **ENOSPC 8→0**（log_level=0 修复）。ok **9→10/33**（lkm_seeker_proc_tail 新通过）。Full set 37 程序：**13 ok / 23 E2BIG / 1 EPERM**。Phase 2 尝试 -regalloc=greedy/-Oz/--disable-loop-unrolling/noalias 全部无效（通过率不变）。**结论**：flag 调节收益为零，剩余 E2BIG 需要 backend lowering 定向减胀或 size-aware skip gate。报告：`llvmbpf_tracee_fix_20260329.md`。 |
    ```
    判定：文档残留；历史问题记录。

  - `./tests/unittest/rejit_regression.c:488`

    ```text
     486: 	pthread_t threads[CONCURRENT_THREADS];
     487: 	struct concurrent_thread_args args[CONCURRENT_THREADS];
    >488: 	int prog_fds[CONCURRENT_THREADS];
     489: 	char log_buf[65536];
     490: 	int i, total_success = 0;
    ```
    判定：合理保留；C 单测里的 loader FD 数组，不是 runner scan/apply prerequisite。

  - `./tests/unittest/rejit_regression.c:495`

    ```text
     493: 	for (i = 0; i < CONCURRENT_THREADS; i++) {
     494: 		memset(log_buf, 0, sizeof(log_buf));
    >495: 		prog_fds[i] = load_xdp_prog(prog_xdp_pass,
     496: 					     ARRAY_SIZE(prog_xdp_pass),
     497: 					     log_buf, sizeof(log_buf));
    ```
    判定：合理保留；C 单测里的 loader FD 数组，不是 runner scan/apply prerequisite。

  - `./tests/unittest/rejit_regression.c:498`

    ```text
     496: 					     ARRAY_SIZE(prog_xdp_pass),
     497: 					     log_buf, sizeof(log_buf));
    >498: 		if (prog_fds[i] < 0) {
     499: 			char msg[256];
     500: 			snprintf(msg, sizeof(msg),
    ```
    判定：合理保留；C 单测里的 loader FD 数组，不是 runner scan/apply prerequisite。

  - `./tests/unittest/rejit_regression.c:506`

    ```text
     504: 			/* Clean up already-loaded progs */
     505: 			while (--i >= 0)
    >506: 				close(prog_fds[i]);
     507: 			return;
     508: 		}
    ```
    判定：合理保留；C 单测里的 loader FD 数组，不是 runner scan/apply prerequisite。

  - `./tests/unittest/rejit_regression.c:513`

    ```text
     511: 	/* Launch threads concurrently */
     512: 	for (i = 0; i < CONCURRENT_THREADS; i++) {
    >513: 		args[i].prog_fd = prog_fds[i];
     514: 		args[i].thread_id = i;
     515: 		if (pthread_create(&threads[i], NULL, concurrent_rejit_worker,
    ```
    判定：合理保留；C 单测里的 loader FD 数组，不是 runner scan/apply prerequisite。

  - `./tests/unittest/rejit_regression.c:529`

    ```text
     527: 	for (i = 0; i < CONCURRENT_THREADS; i++) {
     528: 		__u32 retval = 0;
    >529: 		if (test_run_xdp(prog_fds[i], 1, &retval, NULL) < 0) {
     530: 			char msg[256];
     531: 			snprintf(msg, sizeof(msg),
    ```
    判定：合理保留；C 单测里的 loader FD 数组，不是 runner scan/apply prerequisite。

  - `./tests/unittest/rejit_regression.c:551`

    ```text
     549: cleanup:
     550: 	for (i = 0; i < CONCURRENT_THREADS; i++)
    >551: 		close(prog_fds[i]);
     552: }
     553: 
    ```
    判定：合理保留；C 单测里的 loader FD 数组，不是 runner scan/apply prerequisite。

  - `./tests/unittest/rejit_regression.c:999`

    ```text
     997: {
     998: 	const char *name = "parallel_subprog_rejit (fix 6: kallsyms double-delete)";
    >999: 	int prog_fds[PARALLEL_SUBPROG_PROGS];
     1000: 	pthread_t threads[PARALLEL_SUBPROG_PROGS];
     1001: 	struct subprog_thread_args args[PARALLEL_SUBPROG_PROGS];
    ```
    判定：合理保留；C 单测里的 loader FD 数组，不是 runner scan/apply prerequisite。

  - `./tests/unittest/rejit_regression.c:1019`

    ```text
     1017: 	for (i = 0; i < PARALLEL_SUBPROG_PROGS; i++) {
     1018: 		memset(log_buf, 0, sizeof(log_buf));
    >1019: 		prog_fds[i] = load_xdp_prog(prog_with_subprog,
     1020: 					     ARRAY_SIZE(prog_with_subprog),
     1021: 					     log_buf, sizeof(log_buf));
    ```
    判定：合理保留；C 单测里的 loader FD 数组，不是 runner scan/apply prerequisite。

  - `./tests/unittest/rejit_regression.c:1022`

    ```text
     1020: 					     ARRAY_SIZE(prog_with_subprog),
     1021: 					     log_buf, sizeof(log_buf));
    >1022: 		if (prog_fds[i] < 0) {
     1023: 			char msg[256];
     1024: 			snprintf(msg, sizeof(msg),
    ```
    判定：合理保留；C 单测里的 loader FD 数组，不是 runner scan/apply prerequisite。

  - `./tests/unittest/rejit_regression.c:1029`

    ```text
     1027: 			TEST_FAIL(name, msg);
     1028: 			while (--i >= 0)
    >1029: 				close(prog_fds[i]);
     1030: 			return;
     1031: 		}
    ```
    判定：合理保留；C 单测里的 loader FD 数组，不是 runner scan/apply prerequisite。

  - `./tests/unittest/rejit_regression.c:1036`

    ```text
     1034: 	/* Launch parallel REJIT threads */
     1035: 	for (i = 0; i < PARALLEL_SUBPROG_PROGS; i++) {
    >1036: 		args[i].prog_fd = prog_fds[i];
     1037: 		args[i].thread_id = i;
     1038: 		if (pthread_create(&threads[i], NULL, subprog_rejit_worker,
    ```
    判定：合理保留；C 单测里的 loader FD 数组，不是 runner scan/apply prerequisite。

  - `./tests/unittest/rejit_regression.c:1051`

    ```text
     1049: 	for (i = 0; i < PARALLEL_SUBPROG_PROGS; i++) {
     1050: 		__u32 retval = 0;
    >1051: 		if (test_run_xdp(prog_fds[i], 1, &retval, NULL) < 0) {
     1052: 			char msg[256];
     1053: 			snprintf(msg, sizeof(msg),
    ```
    判定：合理保留；C 单测里的 loader FD 数组，不是 runner scan/apply prerequisite。

  - `./tests/unittest/rejit_regression.c:1073`

    ```text
     1071: cleanup:
     1072: 	for (i = 0; i < PARALLEL_SUBPROG_PROGS; i++)
    >1073: 		close(prog_fds[i]);
     1074: }
     1075: 
    ```
    判定：合理保留；C 单测里的 loader FD 数组，不是 runner scan/apply prerequisite。

  - `./runner/repos/linux-selftests/tools/testing/selftests/bpf/prog_tests/bpf_obj_id.c:18`

    ```text
     16: 	struct bpf_link *links[nr_iters] = {};
     17: 	struct bpf_program *prog;
    >18: 	int prog_fds[nr_iters], map_fds[nr_iters];
     19: 	/* +1 to test for the info_len returned by kernel */
     20: 	struct bpf_prog_info prog_infos[nr_iters + 1];
    ```
    判定：合理保留；上游 linux-selftests 代码，不属本项目 cleanup 面。

  - `./runner/repos/linux-selftests/tools/testing/selftests/bpf/prog_tests/bpf_obj_id.c:52`

    ```text
     50: 		now = time(NULL);
     51: 		err = bpf_prog_test_load(file, BPF_PROG_TYPE_RAW_TRACEPOINT,
    >52: 				    &objs[i], &prog_fds[i]);
     53: 		/* test_obj_id.o is a dumb prog. It should never fail
     54: 		 * to load.
    ```
    判定：合理保留；上游 linux-selftests 代码，不属本项目 cleanup 面。

  - `./runner/repos/linux-selftests/tools/testing/selftests/bpf/prog_tests/bpf_obj_id.c:115`

    ```text
     113: 			goto done;
     114: 
    >115: 		err = bpf_prog_get_info_by_fd(prog_fds[i], &prog_infos[i],
     116: 					      &info_len);
     117: 		load_time = (real_time_ts.tv_sec - boot_time_ts.tv_sec)
    ```
    判定：合理保留；上游 linux-selftests 代码，不属本项目 cleanup 面。


### 🔴 `find_bpf_programs`
- hit 数量：2
- 备注：仅定义 + `__all__` 导出，无 caller。
- 明细：
  - `./runner/libs/agent.py:133`

    ```text
     131: 
     132: 
    >133: def find_bpf_programs(agent_name_or_pid: str | int) -> list[dict]:
     134:     pids = _resolve_pids(agent_name_or_pid)
     135:     if not pids:
    ```
    判定：dead code 残留；helper 定义仍在，但 repo 内无 caller。

  - `./runner/libs/agent.py:163`

    ```text
     161: __all__ = [
     162:     "bpftool_prog_show_records",
    >163:     "find_bpf_programs",
     164:     "start_agent",
     165:     "stop_agent",
    ```
    判定：dead code 残留；只剩 `__all__` 导出。


### ⚠ `sample_bpf_stats`
- hit 数量：21
- 备注：helper 与 callers 仍在，但都用于 workload / stats measurement，不再参与 program selection。
- 明细：
  - `./corpus/driver.py:23`

    ```text
     21: from runner.libs.app_runners.scx import ScxRunner
     22: from runner.libs.app_suite_schema import AppSpec, AppWorkload, load_app_suite_from_yaml
    >23: from runner.libs.bpf_stats import enable_bpf_stats, sample_bpf_stats
     24: from runner.libs.case_common import (
     25:     _append_pending_kinsn_metadata,
    ```
    判定：合理保留；测量/telemetry 采样，不参与 target/apply program 选择。

  - `./corpus/driver.py:246`

    ```text
     244:         )
     245:     else:
    >246:         initial_stats = sample_bpf_stats(sampled_prog_ids)
     247:     for _ in range(samples):
     248:         workload = runner.run_workload(workload_seconds).to_dict()
    ```
    判定：合理保留；测量/telemetry 采样，不参与 target/apply program 选择。

  - `./corpus/driver.py:258`

    ```text
     256:         )
     257:     else:
    >258:         final_stats = sample_bpf_stats(sampled_prog_ids)
     259:     if sampled_prog_id_map is not None:
     260:         sampled_to_target = {
    ```
    判定：合理保留；测量/telemetry 采样，不参与 target/apply program 选择。

  - `./corpus/driver.py:422`

    ```text
     420:         else:
     421:             try:
    >422:                 raw_stats = sample_bpf_stats(sampled_prog_ids)
     423:                 break
     424:             except RuntimeError as exc:
    ```
    判定：合理保留；测量/telemetry 采样，不参与 target/apply program 选择。

  - `./runner/libs/case_common.py:17`

    ```text
     15: from runner.libs import run_command
     16: from runner.libs.app_runners.base import AppRunner
    >17: from runner.libs.bpf_stats import compute_delta, list_program_ids, sample_bpf_stats
     18: from runner.libs.rejit import DaemonSession
     19: from runner.libs.kinsn import (
    ```
    判定：合理保留；测量/telemetry 采样，不参与 target/apply program 选择。

  - `./runner/libs/case_common.py:592`

    ```text
     590:     initial_stats: Mapping[int, Mapping[str, object]] | None = None,
     591: ) -> dict[str, object]:
    >592:     stats_source = sample_bpf_stats(list(prog_ids)) if initial_stats is None else initial_stats
     593:     before_bpf = {int(key): dict(value) for key, value in stats_source.items()}
     594:     cpu_holder: dict[int, dict[str, float]] = {}
    ```
    判定：合理保留；测量/telemetry 采样，不参与 target/apply program 选择。

  - `./runner/libs/case_common.py:614`

    ```text
     612:     if agent_pid is not None and int(agent_pid) > 0 and int(agent_pid) not in cpu_holder:
     613:         raise RuntimeError(f"agent cpu sampler produced no data for pid={int(agent_pid)}")
    >614:     after_bpf = sample_bpf_stats(list(prog_ids))
     615:     measurement: dict[str, object] = {
     616:         "workload": workload_result.to_dict(), "initial_stats": {int(k): dict(v) for k, v in before_bpf.items()},
    ```
    判定：合理保留；测量/telemetry 采样，不参与 target/apply program 选择。

  - `./runner/libs/bpf_stats.py:41`

    ```text
     39: 
     40: 
    >41: def sample_bpf_stats(
     42:     prog_ids: list[int] | tuple[int, ...],
     43: ) -> dict[int, dict[str, object]]:
    ```
    判定：合理保留；底层 BPF stats sampling helper 本体。

  - `./e2e/cases/scx/case.py:21`

    ```text
     19: from runner.libs.app_runners.base import AppRunner  # noqa: E402
     20: from runner.libs.app_runners.scx import ScxRunner, read_scx_ops, read_scx_state  # noqa: E402
    >21: from runner.libs.bpf_stats import compute_delta, sample_bpf_stats  # noqa: E402
     22: from runner.libs.metrics import (  # noqa: E402
     23:     sample_cpu_usage,
    ```
    判定：合理保留；测量/telemetry 采样，不参与 target/apply program 选择。

  - `./e2e/cases/scx/case.py:162`

    ```text
     160:         )
     161:     else:
    >162:         before_bpf = sample_bpf_stats(target_prog_ids)
     163:         before_live_prog_id_map = {}
     164:         before_live_programs = []
    ```
    判定：合理保留；测量/telemetry 采样，不参与 target/apply program 选择。

  - `./e2e/cases/scx/case.py:195`

    ```text
     193:         )
     194:     else:
    >195:         after_bpf = sample_bpf_stats(target_prog_ids)
     196:         after_live_prog_id_map = {}
     197:         after_live_programs = []
    ```
    判定：合理保留；测量/telemetry 采样，不参与 target/apply program 选择。

  - `./e2e/cases/scx/case.py:306`

    ```text
     304:     if not sampled_prog_ids:
     305:         raise RuntimeError("scx runner did not expose any live scheduler programs for BPF stats sampling")
    >306:     raw_stats = sample_bpf_stats(sampled_prog_ids)
     307:     live_to_logical = {
     308:         int(live_id): int(logical_id)
    ```
    判定：合理保留；测量/telemetry 采样，不参与 target/apply program 选择。

  - `./e2e/cases/tetragon/case.py:28`

    ```text
     26:     run_tetragon_workload,
     27: )
    >28: from runner.libs.bpf_stats import compute_delta, enable_bpf_stats, sample_bpf_stats  # noqa: E402
     29: from runner.libs.metrics import (  # noqa: E402
     30:     sample_cpu_usage,
    ```
    判定：合理保留；测量/telemetry 采样，不参与 target/apply program 选择。

  - `./e2e/cases/tetragon/case.py:158`

    ```text
     156:     exec_workload_cgroup: bool,
     157: ) -> dict[str, object]:
    >158:     before_bpf = sample_bpf_stats(prog_ids)
     159:     cpu_holder: dict[int, dict[str, float]] = {}
     160:     system_cpu_holder: dict[str, float] = {}
    ```
    判定：合理保留；测量/telemetry 采样，不参与 target/apply program 选择。

  - `./e2e/cases/tetragon/case.py:197`

    ```text
     195:         raise RuntimeError(f"agent cpu sampler produced no data for pid={agent_pid}")
     196: 
    >197:     after_bpf = sample_bpf_stats(prog_ids)
     198:     bpf_delta = compute_delta(before_bpf, after_bpf)
     199:     total_events = int((bpf_delta.get("summary") or {}).get("total_events", 0) or 0)
    ```
    判定：合理保留；测量/telemetry 采样，不参与 target/apply program 选择。

  - `./e2e/cases/katran/case.py:21`

    ```text
     19:     KatranRunner,
     20: )
    >21: from runner.libs.bpf_stats import compute_delta, enable_bpf_stats, sample_bpf_stats  # noqa: E402
     22: from runner.libs.case_common import (  # noqa: E402
     23:     host_metadata,
    ```
    判定：合理保留；测量/telemetry 采样，不参与 target/apply program 选择。

  - `./e2e/cases/katran/case.py:58`

    ```text
     56:     prog_ids: list[int],
     57: ) -> dict[str, object]:
    >58:     before_bpf = sample_bpf_stats(prog_ids)
     59:     system_cpu_holder: dict[str, float] = {}
     60:     sampler_errors: list[str] = []
    ```
    判定：合理保留；测量/telemetry 采样，不参与 target/apply program 选择。

  - `./e2e/cases/katran/case.py:74`

    ```text
     72:     if not system_cpu_holder:
     73:         raise RuntimeError("system cpu sampler produced no data")
    >74:     after_bpf = sample_bpf_stats(prog_ids)
     75:     return {
     76:         "workload": workload_result.to_dict(),
    ```
    判定：合理保留；测量/telemetry 采样，不参与 target/apply program 选择。

  - `./e2e/cases/tracee/case.py:38`

    ```text
     36:     run_tracee_workload,
     37: )
    >38: from runner.libs.bpf_stats import compute_delta, enable_bpf_stats, sample_bpf_stats  # noqa: E402
     39: from runner.libs.metrics import (  # noqa: E402
     40:     sample_cpu_usage,
    ```
    判定：合理保留；测量/telemetry 采样，不参与 target/apply program 选择。

  - `./e2e/cases/tracee/case.py:466`

    ```text
     464:     collector: TraceeOutputCollector | None,
     465: ) -> dict[str, object]:
    >466:     before_bpf = sample_bpf_stats(prog_ids)
     467:     if collector is not None:
     468:         collector.raise_event_file_error()
    ```
    判定：合理保留；测量/telemetry 采样，不参与 target/apply program 选择。

  - `./e2e/cases/tracee/case.py:504`

    ```text
     502:         raise RuntimeError(f"agent cpu sampler produced no data for pid={agent_pid}")
     503: 
    >504:     after_bpf = sample_bpf_stats(prog_ids)
     505:     if collector is not None:
     506:         collector.raise_event_file_error()
    ```
    判定：合理保留；测量/telemetry 采样，不参与 target/apply program 选择。


### ✅ `applied_any`
- hit 数量：0
- 备注：repo-wide 0 hit。
- 判定：零 active source match。

### ✅ `all_applied`
- hit 数量：0
- 备注：repo-wide 0 hit。
- 判定：零 active source match。

### ✅ `changed_any`
- hit 数量：0
- 备注：repo-wide 0 hit。
- 判定：零 active source match。

### ⚠ `all_changed`
- hit 数量：5
- 备注：active benchmark source dirs (`runner/libs e2e corpus daemon tests`) 0 hit；剩余命中在 upstream Katran build helper。
- 明细：
  - `./runner/repos/katran/build/fbcode_builder/getdeps/fetcher.py:92`

    ```text
     90:     """
     91: 
    >92:     def __init__(self, all_changed: bool = False) -> None:
     93:         """Construct a ChangeStatus object.  The default is to create
     94:         a status that indicates no changes, but passing all_changed=True
    ```
    判定：合理保留；upstream Katran getdeps helper，非本项目 benchmark 源码。

  - `./runner/repos/katran/build/fbcode_builder/getdeps/fetcher.py:94`

    ```text
     92:     def __init__(self, all_changed: bool = False) -> None:
     93:         """Construct a ChangeStatus object.  The default is to create
    >94:         a status that indicates no changes, but passing all_changed=True
     95:         will create one that indicates that everything changed"""
     96:         if all_changed:
    ```
    判定：合理保留；upstream Katran getdeps helper，非本项目 benchmark 源码。

  - `./runner/repos/katran/build/fbcode_builder/getdeps/fetcher.py:96`

    ```text
     94:         a status that indicates no changes, but passing all_changed=True
     95:         will create one that indicates that everything changed"""
    >96:         if all_changed:
     97:             self.source_files: int = 1
     98:             self.make_files: int = 1
    ```
    判定：合理保留；upstream Katran getdeps helper，非本项目 benchmark 源码。

  - `./runner/repos/katran/build/fbcode_builder/getdeps/fetcher.py:190`

    ```text
     188: 
     189:     def update(self) -> ChangeStatus:
    >190:         return ChangeStatus(all_changed=True)
     191: 
     192:     def hash(self) -> str:
    ```
    判定：合理保留；upstream Katran getdeps helper，非本项目 benchmark 源码。

  - `./runner/repos/katran/build/fbcode_builder/getdeps/fetcher.py:253`

    ```text
     251:     def update(self) -> ChangeStatus:
     252:         assert self.installed
    >253:         return ChangeStatus(all_changed=False)
     254: 
     255:     def hash(self) -> str:
    ```
    判定：合理保留；upstream Katran getdeps helper，非本项目 benchmark 源码。


### ✅ `legacy_total_sites_contract`
- hit 数量：0
- 备注：repo-wide 0 hit。
- 判定：零 active source match。

### ✅ `workload_kind`
- hit 数量：0
- 备注：repo-wide 0 hit。
- 判定：零 active source match。

### ✅ `get("message")`
- hit 数量：0
- 备注：daemon protocol fallback 链上 `get("message")` repo-wide 0 hit。
- 判定：零 active source match。

### ⚠ `get("error")`
- hit 数量：17
- 备注：repo-wide 17 hit，但都不是 daemon socket response fallback；全是 runner/app-local `error` 字段。
- 明细：
  - `./corpus/driver.py:507`

    ```text
     505:     apply_record: Mapping[str, object],
     506: ) -> str:
    >507:     apply_error = str(apply_record.get("error") or "").strip()
     508:     if baseline_exec_ns is None:
     509:         return "missing_baseline_exec_ns"
    ```
    判定：合理保留；runner/app-local `error` 字段读取，不是 daemon protocol fallback。

  - `./corpus/driver.py:630`

    ```text
     628:                     "changed": bool(row.get("changed")),
     629:                     "reason": str(row.get("comparison_exclusion_reason") or "unknown"),
    >630:                     "apply_error": str(((row.get("apply") or {}).get("error")) or ""),
     631:                 }
     632:             )
    ```
    判定：合理保留；runner/app-local `error` 字段读取，不是 daemon protocol fallback。

  - `./corpus/driver.py:934`

    ```text
     932:             total_sites += int(counts.get("total_sites", 0) or 0)
     933:             applied_sites += int(counts.get("applied_sites", 0) or 0)
    >934:         error = str(record.get("error") or "").strip()
     935:         if error:
     936:             errors.append(error)
    ```
    判定：合理保留；runner/app-local `error` 字段读取，不是 daemon protocol fallback。

  - `./corpus/driver.py:942`

    ```text
     940:     error_message = "; ".join(errors)
     941:     if not error_message and not per_program:
    >942:         error_message = str(rejit_result.get("error") or "").strip()
     943:     sliced = {
     944:         "applied": applied,
    ```
    判定：合理保留；runner/app-local `error` 字段读取，不是 daemon protocol fallback。

  - `./corpus/driver.py:1004`

    ```text
     1002: 
     1003:     normalized_apply_result = dict(apply_result or {})
    >1004:     apply_error = str(normalized_apply_result.get("error") or "").strip()
     1005:     if not _has_phase_measurement(programs_by_id):
     1006:         raise RuntimeError(
    ```
    判定：合理保留；runner/app-local `error` 字段读取，不是 daemon protocol fallback。

  - `./corpus/driver.py:1232`

    ```text
     1230:                             app=app.name,
     1231:                             status=result.get("status"),
    >1232:                             error=result.get("error"),
     1233:                             program_count=0,
     1234:                         )
    ```
    判定：合理保留；runner/app-local `error` 字段读取，不是 daemon protocol fallback。

  - `./corpus/driver.py:1285`

    ```text
     1283:                                 app=session.app.name,
     1284:                                 status=result.get("status"),
    >1285:                                 error=result.get("error"),
     1286:                                 program_count=0,
     1287:                             )
    ```
    判定：合理保留；runner/app-local `error` 字段读取，不是 daemon protocol fallback。

  - `./corpus/driver.py:1389`

    ```text
     1387:                     if str(session.kinsn_metadata.get("status") or "").strip() == "":
     1388:                         session.kinsn_metadata["status"] = "error" if fatal_error or session.error else "completed"
    >1389:                     if session.error and str(session.kinsn_metadata.get("error") or "").strip() == "":
     1390:                         session.kinsn_metadata["error"] = session.error
     1391:                     if fatal_error and str(session.kinsn_metadata.get("error") or "").strip() == "":
    ```
    判定：合理保留；runner/app-local `error` 字段读取，不是 daemon protocol fallback。

  - `./corpus/driver.py:1391`

    ```text
     1389:                     if session.error and str(session.kinsn_metadata.get("error") or "").strip() == "":
     1390:                         session.kinsn_metadata["error"] = session.error
    >1391:                     if fatal_error and str(session.kinsn_metadata.get("error") or "").strip() == "":
     1392:                         session.kinsn_metadata["error"] = fatal_error
     1393:                     _append_pending_kinsn_metadata(session.kinsn_metadata)
    ```
    判定：合理保留；runner/app-local `error` 字段读取，不是 daemon protocol fallback。

  - `./corpus/driver.py:1449`

    ```text
     1447:                 app=session.app.name,
     1448:                 status=result.get("status"),
    >1449:                 error=result.get("error"),
     1450:                 program_count=len(result.get("program_measurements") or {}),
     1451:             )
    ```
    判定：合理保留；runner/app-local `error` 字段读取，不是 daemon protocol fallback。

  - `./e2e/cases/scx/case.py:726`

    ```text
     724:     rejit_error = ""
     725:     if isinstance(rejit_result, Mapping):
    >726:         rejit_error = str(rejit_result.get("error") or "").strip()
     727:     if rejit_error:
     728:         limitations.append(f"Partial ReJIT/apply errors were reported: {rejit_error}")
    ```
    判定：合理保留；runner/app-local `error` 字段读取，不是 daemon protocol fallback。

  - `./e2e/cases/tetragon/case.py:748`

    ```text
     746:     error_message = ""
     747:     if not rejit_result_has_any_apply(rejit_result):
    >748:         error_message = str(rejit_result.get("error") or rejit_result.get("reason") or "").strip()
     749:         if not error_message:
     750:             error_message = "Tetragon reJIT did not apply"
    ```
    判定：合理保留；runner/app-local `error` 字段读取，不是 daemon protocol fallback。

  - `./e2e/cases/katran/case.py:141`

    ```text
     139:     comparison_reason = ""
     140:     status = "ok"
    >141:     error_message = str(rejit_result.get("error") or "").strip()
     142:     if error_message:
     143:         status = "error"
    ```
    判定：合理保留；runner/app-local `error` 字段读取，不是 daemon protocol fallback。

  - `./runner/libs/rejit.py:826`

    ```text
     824:             ec = int(profile_error.get("exit_code", 1) or 1)
     825:             out = str(profile_error.get("output") or "")
    >826:             msg = str(profile_error.get("error") or "profile collection failed")
     827:             zc: dict[str, int] = {"total_sites": 0, "applied_sites": 0}
     828:             return {
    ```
    判定：合理保留；runner/app-local `error` 字段读取，不是 daemon protocol fallback。

  - `./runner/libs/rejit.py:850`

    ```text
     848:         total_sites += int(rc.get("total_sites", 0) or 0)
     849:         applied_sites += int(rc.get("applied_sites", 0) or 0)
    >850:         if error := str(result.get("error") or "").strip():
     851:             errors.append(f"prog {prog_id}: {error}")
     852:     n_applied = sum(1 for r in per_program.values() if r.get("applied", False))
    ```
    判定：合理保留；runner/app-local `error` 字段读取，不是 daemon protocol fallback。

  - `./runner/libs/case_common.py:357`

    ```text
     355:             total_sites += int(counts.get("total_sites", 0) or 0)
     356:             applied_sites += int(counts.get("applied_sites", 0) or 0)
    >357:         error = str(result.get("error") or "").strip()
     358:         if error:
     359:             errors.append(error)
    ```
    判定：合理保留；runner/app-local `error` 字段读取，不是 daemon protocol fallback。

  - `./runner/libs/case_common.py:697`

    ```text
     695:             rejit = {"phase": "post_rejit", "status": "ok" if not rr else "error", "reason": rr,
     696:                      "measurement": post_measurement, **_shared}
    >697:         elif (rejit_error := str(rejit_apply.get("error") or "").strip()):
     698:             rejit = {"phase": "post_rejit", "status": "error", "reason": rejit_error, "measurement": None, **_shared}
     699:     return baseline, rejit
    ```
    判定：合理保留；runner/app-local `error` 字段读取，不是 daemon protocol fallback。


### ✅ `spawn_timeout_s`
- hit 数量：0
- 备注：repo-wide 0 hit。
- 判定：零 active source match。

### ⚠ `description:`
- hit 数量：25723
- 备注：语义收窄为“YAML 里的 per-tool description 字段”。清理目标面 `e2e/cases runner/libs corpus/config` 为 0 hit；raw repo-wide YAML 命中 25273，主要来自 `runner/repos/**` 上游 manifests/CRDs 与 `micro/config`，不对应本次 cleanup 项。
- focused 结果：`rg -u -n --glob '!vendor/**' --glob '!**/results/**' --glob '!runner/build-*/**' --glob '!docs/tmp/**' "description:" e2e/cases runner/libs corpus/config` -> 0 hit。
- raw repo-wide YAML 结果：25273 hit；top buckets:
  - `./runner/repos/calico/manifests/v1_crd_projectcalico_org.yaml`: 4272
  - `./runner/repos/calico/manifests/operator-crds.yaml`: 4272
  - `./runner/repos/calico/manifests/v3_projectcalico_org.yaml`: 3973
  - `./runner/repos/calico/charts/projectcalico.org.v3/templates/operator.tigera.io_installations.yaml`: 2138
  - `./runner/repos/calico/charts/crd.projectcalico.org.v1/templates/operator.tigera.io_installations.yaml`: 2138
  - `./runner/repos/KubeArmor/deployments/controller/cert-manager.yaml`: 926
  - `./runner/repos/calico/charts/projectcalico.org.v3/templates/operator.tigera.io_gatewayapis.yaml`: 627
  - `./runner/repos/calico/charts/crd.projectcalico.org.v1/templates/operator.tigera.io_gatewayapis.yaml`: 627
  - `./micro/config/micro_pure_jit.yaml`: 62
- 判定：清理目标面已删干净；raw literal 仍大量存在于上游 manifests / CRDs / micro benchmark YAML，不能算本次 cleanup 漏删。

## Part 2: 需要补删的清单

- HIGH: `requested_prog_ids` 仍在 `corpus/driver.py` / `runner/libs/rejit.py` / `runner/libs/case_common.py` 的活代码 helper、形参、局部变量里出现 34 次。旧 artifact echo key 已删，但 API/命名删除并不成立。
- MEDIUM: `runner/libs/app_runners/katran.py` 仍有活代码 `_select_program()` helper 和调用位点；Katran 没再把返回集收缩成单程序，但“选择单程序”这个 helper 本身没删掉。
- MEDIUM: `runner/libs/agent.py` 的 `find_bpf_programs()` 仍保留定义和导出，repo 内无 caller，属于 dead code residue。
- LOW: `docs/kernel-jit-optimization-plan.md` 仍保留 `target_programs` / `apply_programs` / `prog_fds` 历史文字；不是运行时 bug，但如果要求 literal-zero，需要文档补删。

## Part 3: 合理保留的清单

- `requested_prog_ids` 的旧 artifact echo path 确实已删：quoted key `"requested_prog_ids"` / `'requested_prog_ids'` 在 `runner e2e corpus daemon` 为 0。现存问题是内部 helper / 变量命名残留，不是 artifact metadata 继续外露。
- lifecycle container 现状：字段仍是 `target_prog_ids` / `apply_prog_ids`；没有 `requested_prog_ids` 字段。但 helper 方法名 `requested_prog_ids()` 仍存在于 `runner/libs/case_common.py` 和 `corpus/driver.py`。
- `prog_fds` 仅剩 C 单测里的 loader FD 数组、上游 linux-selftests、以及历史文档；`runner/libs e2e corpus daemon` 为 0，因此“scan/apply prerequisite 的 `prog_fds` 已删”这件事本身成立。
- `sample_bpf_stats` 和 callers 仍在，但用途是 workload / telemetry measurement（前后 run_cnt/run_time 采样），不是 activity-based selection，也不会重写 target/apply program set。
- daemon 协议 fallback 链已清：`get("message")` 为 0；`get("error")` 的 17 个命中都在 runner/app-local `error` 字段、artifact 组装或结果聚合上，不是 daemon socket response fallback。
- `all_changed` 仅出现在 `runner/repos/katran/build/fbcode_builder/getdeps/fetcher.py`，属于 upstream build helper，不是本项目 benchmark 主源码。
- `description:` 的清理目标面已是 0；raw repo-wide YAML 命中主要来自 `runner/repos/calico/**`、`runner/repos/KubeArmor/**` 等上游 manifests/CRDs，以及 `micro/config/micro_pure_jit.yaml` 的 benchmark 描述字段。

## Part 4: 总结

- strict literal-zero 覆盖率：`21/31` = `67.7%`。
- semantic cleanup 覆盖率（把 docs residue / upstream fixture / measurement-only retain 视为合理保留）：`28/31` = `90.3%`。
- 结论：前两波删除大体到位，但还没到“删干净”标准。最需要 Round 3 的是 3 个点：`requested_prog_ids` 命名残留、Katran `_select_program()` 活代码残留、`find_bpf_programs()` dead code。
- 是否需要 Round 3：需要，但范围很小，优先清理活代码 / dead code residue；文档文字残留可作为低优先级尾项。
