# ARM64 bcc/set Subset Diagnosis - 2026-05-06

## Scope

1. Task: explain why `bcc/set` on ARM64 measured 7 BPF programs while KVM x86 measured 21.
2. Task: explain why ARM64 `cond_select` reports `matched=7 applied=0 skipped=7`.
3. Mode: read-only investigation of code and existing artifacts.
4. No code changes were made.
5. No daemon was spawned.
6. No corpus run was started.
7. No EC2 instance was launched.
8. The only write is this diagnosis document.
9. Primary ARM64 artifact:
   `corpus/results/aws_arm64_corpus_20260506_073741_286113/details/result.json`.
10. Primary KVM x86 artifacts:
    `corpus/results/x86_kvm_corpus_20260506_072100_405917/details/result.json`.
11. Primary KVM x86 follow-up artifact:
    `corpus/results/x86_kvm_corpus_20260506_072847_824797/details/result.json`.
12. Required source context:
    `runner/libs/app_runners/bcc_set.py`.
13. Required source context:
    `runner/libs/app_runners/bcc.py`.
14. Required source context:
    commit `c75bf9d5` ("Add bcc/set merged runner for parallel 8-tool corpus").
15. Design constraint: no ReJIT filtering; every live program returned by an app runner must naturally flow into ReJIT.
    Citation: `CLAUDE.md:5-10`.
16. Design constraint: benchmark apps must load their own BPF programs through real app startup.
    Citation: `CLAUDE.md:12-13`.
17. Design constraint: result payloads are raw measurement surfaces, not interpretation summaries.
    Citation: `CLAUDE.md:15-28`.
18. Design constraint: missing capabilities and command failures should not silently degrade.
    Citation: `CLAUDE.md:70-74`.
19. Design constraint: runner Python remains the stable boundary during v3 migration.
    Citation: `CLAUDE.md:86-101`.
20. Architecture context: BpfReJIT depends on transparent post-load optimization of live BPF programs.
    Citation: `docs/kernel-jit-optimization-plan.md:120-132`.
21. Architecture context: koperation are platform modules with verifier/JIT emit semantics.
    Citation: `docs/kernel-jit-optimization-plan.md:123-126`.
22. Cost constraint: ARM bench defaults stay on `t4g.small`, not larger instance classes.
    Citation: `CLAUDE.md:128-129`.

## Executive Conclusions

23. Q1 conclusion:
    ARM64 did not see 7 programs because binaries were missing.
24. Q1 conclusion:
    ARM64 did not see 7 programs because BCC is architecturally limited to 7 programs on ARM64.
25. Q1 conclusion:
    Existing individual ARM64 corpus artifacts show the same tools can attach programs when run one at a time.
26. Q1 actual root cause:
    `bcc/set` has a readiness/observability bug.
27. Q1 actual root cause:
    it waits for the global post-start BPF program set to become non-empty and stable.
28. Q1 actual root cause:
    then it labels each still-running child process as `attached`, even when fdinfo shows no program IDs for that child.
29. Q1 actual root cause:
    on the ARM64 run, only `vfsstat` and `syscount` had attached by the time the stable set was captured.
30. Q1 operational symptom:
    the artifact status is `ok`, but six tools have `prog_ids: []`.
31. Q1 closest listed possibility:
    a hybrid of possibility 2 and possibility 4.
32. Q1 nuance:
    the evidence does not show those six tools exited or failed to launch.
33. Q1 nuance:
    it shows the runner silently accepted live-but-not-yet-attached children as attached.
34. Q1 fix priority:
    P0, because the benchmark is measuring a different workload surface on ARM64.

35. Q2 conclusion:
    ARM64 `cond_select` is not a verifier acceptance problem.
36. Q2 conclusion:
    ARM64 `cond_select` is not explained by a missing `bpf_select` module.
37. Q2 conclusion:
    target kop probing is not the immediate blocker for the observed skip reason.
38. Q2 actual root cause:
    `CondSelectPass` checks `ctx.platform.has_cmov` before checking `bpf_select64`.
39. Q2 actual root cause:
    `has_cmov` is only enabled by x86 feature detection or a target feature named `cmov`.
40. Q2 actual root cause:
    ARM64 target feature detection intentionally emits no features.
41. Q2 actual root cause:
    therefore ARM64 always returns `platform lacks CMOV support` before using the ARM64 `bpf_select` CSEL kop.
42. Q2 site-shape nuance:
    ARM64 matched different sites because Q1 left only `vfsstat` and `syscount` programs in scope.
43. Q2 fix priority:
    P1 after the `bcc/set` coverage fix, because Q1 currently hides the full ARM64 `bcc/set` corpus.

## c75bf9d5 Runner Behavior

44. Commit `c75bf9d5` added the new `bcc/set` app to the macro app list.
45. Current catalog includes the eight individual BCC apps and then `bcc/set`.
46. Individual BCC entries:
    `bcc/capable`, `bcc/biosnoop`, `bcc/vfsstat`, `bcc/opensnoop`.
    Citation: `runner/libs/benchmark_catalog.py:19-24`.
47. Individual BCC entries:
    `bcc/tcpconnect`, `bcc/tcplife`, `bcc/runqlat`.
    Citation: `runner/libs/benchmark_catalog.py:25-27`.
48. New merged BCC entry:
    `name="bcc/set"`, `runner="bcc_set"`, workload `stress_ng_os_io_network`, duration 5s.
    Citation: `runner/libs/benchmark_catalog.py:28-33`.
49. The `bcc_set` adapter resolves all eight binaries before runner construction.
    Citation: `runner/libs/app_runners/__init__.py:31-47`.
50. The adapter fails early if any binary is missing.
    Citation: `runner/libs/app_runners/__init__.py:48-51`.
51. That makes "missing binary but status ok" unlikely if the adapter path ran.
52. The corpus driver preserves `runner.artifacts["result_details"]`.
    Citation: `corpus/driver.py:161-165`.
53. The corpus result builder emits preserved runner details into `runner_details`.
    Citation: `corpus/driver.py:390-396`.
54. Therefore the `_tool_startup` information is expected to be present in `result.json`.
55. The ARM64 artifact does include `runner_details.bcc_set.tool_startup`.
    Citation: `corpus/results/aws_arm64_corpus_20260506_073741_286113/details/result.json:1236-1238`.

## bcc/set Source Semantics

56. `BCC_SET_TOOL_SPECS` names exactly the eight requested tools.
57. Tools:
    `capable`, `biosnoop`, `vfsstat`, `opensnoop`.
    Citation: `runner/libs/app_runners/bcc_set.py:34-39`.
58. Tools:
    `syscount -L -i 1`, `tcpconnect`, `tcplife`, `runqlat`.
    Citation: `runner/libs/app_runners/bcc_set.py:39-42`.
59. Runner construction requires a resolved binary for each tool.
    Citation: `runner/libs/app_runners/bcc_set.py:107-116`.
60. `start()` initializes every tool's status as `pending`.
    Citation: `runner/libs/app_runners/bcc_set.py:125-132`.
61. `start()` then spawns each child in a fault-tolerant loop.
    Citation: `runner/libs/app_runners/bcc_set.py:134-143`.
62. If `_spawn_child()` raises, that tool is recorded as `failed` and the loop continues.
    Citation: `runner/libs/app_runners/bcc_set.py:137-141`.
63. If no child was spawned, `bcc/set` fails the whole app.
    Citation: `runner/libs/app_runners/bcc_set.py:145-146`.
64. After spawning, `bcc/set` waits for a global stable program set.
    Citation: `runner/libs/app_runners/bcc_set.py:148-153`.
65. The global stable wait is not per-child.
66. The global stable wait receives no child process handles.
67. Therefore the wait cannot know whether all eight tools have attached.
68. The stable wait returns as soon as any non-empty program set stays unchanged for the stable window.
    Citation: `runner/libs/app_runners/process_support.py:54-68`.
69. It polls live programs after `before_ids`.
    Citation: `runner/libs/app_runners/process_support.py:73-80`.
70. It increments stable observations when the current program ID set is unchanged.
    Citation: `runner/libs/app_runners/process_support.py:81-85`.
71. It returns when `programs` is non-empty and stable observations meet the threshold.
    Citation: `runner/libs/app_runners/process_support.py:96-97`.
72. That condition can be satisfied by a subset of the eight tools.
73. After the global wait, `bcc/set` dedupes the returned programs.
    Citation: `runner/libs/app_runners/bcc_set.py:158-160`.
74. `bcc/set` then computes the returned live program ID set.
    Citation: `runner/libs/app_runners/bcc_set.py:162-166`.
75. For each spawned tool, it checks whether the process has exited.
    Citation: `runner/libs/app_runners/bcc_set.py:168-181`.
76. For each still-running child, it reads fdinfo program IDs and intersects them with the global live set.
    Citation: `runner/libs/app_runners/bcc_set.py:182`.
77. Crucial bug:
    it records `status="attached"` even if that intersection is empty.
    Citation: `runner/libs/app_runners/bcc_set.py:182-184`.
78. Crucial bug:
    it increments `live_tools` regardless of whether `prog_ids` is empty.
    Citation: `runner/libs/app_runners/bcc_set.py:182-184`.
79. The only full failure is `live_tools == 0`.
    Citation: `runner/libs/app_runners/bcc_set.py:186-187`.
80. So six empty children plus two real children still yields app status `ok`.
81. `BCCRunner` for one tool is stricter than `bcc/set`.
82. The single-tool runner passes the child process to `wait_until_program_set_stable`.
    Citation: `runner/libs/app_runners/bcc.py:414-423`.
83. The single-tool runner fails if no programs are found.
    Citation: `runner/libs/app_runners/bcc.py:424-427`.
84. The single-tool runner stores only discovered programs after that gate.
    Citation: `runner/libs/app_runners/bcc.py:428-429`.
85. This difference explains why individual BCC tools can be healthy while the merged runner can return early.

## Q1 Artifact Comparison

86. KVM x86 verification artifact `072100` has `bcc/set` as the only app.
    Citation: `corpus/results/x86_kvm_corpus_20260506_072100_405917/details/result.json:105-107`.
87. The `072100` baseline BPF map lists 21 programs.
88. Program IDs include `6`, `7`, `10`, `11`, `12`, `13`, `14`, `17`, `22`, `23`, `24`.
    Citation: `corpus/results/x86_kvm_corpus_20260506_072100_405917/details/result.json:108-205`.
89. Program IDs also include `25`, `28`, `29`, `30`, `33`, `34`, `35`, `38`, `39`, `40`.
    Citation: `corpus/results/x86_kvm_corpus_20260506_072100_405917/details/result.json:207-296`.
90. The `072100` runner details show all eight tools with non-empty `prog_ids`.
91. `capable` has program `17`.
    Citation: `corpus/results/x86_kvm_corpus_20260506_072100_405917/details/result.json:1235-1244`.
92. `biosnoop` has programs `25`, `39`, `40`.
    Citation: `corpus/results/x86_kvm_corpus_20260506_072100_405917/details/result.json:1246-1257`.
93. `vfsstat` has programs `10`, `11`, `12`, `13`, `14`.
    Citation: `corpus/results/x86_kvm_corpus_20260506_072100_405917/details/result.json:1259-1272`.
94. `opensnoop` has programs `22`, `23`, `24`.
    Citation: `corpus/results/x86_kvm_corpus_20260506_072100_405917/details/result.json:1274-1285`.
95. `syscount` has programs `6`, `7`.
    Citation: `corpus/results/x86_kvm_corpus_20260506_072100_405917/details/result.json:1287-1300`.
96. `tcpconnect` has programs `33`, `34`, `35`.
    Citation: `corpus/results/x86_kvm_corpus_20260506_072100_405917/details/result.json:1302-1313`.
97. `tcplife` has program `38`.
    Citation: `corpus/results/x86_kvm_corpus_20260506_072100_405917/details/result.json:1315-1324`.
98. `runqlat` has programs `28`, `29`, `30`.
    Citation: `corpus/results/x86_kvm_corpus_20260506_072100_405917/details/result.json:1326-1337`.

99. KVM x86 follow-up artifact `072847` repeats the same 21-program surface.
100. It lists program IDs `6`, `7`, `10`, `11`, `12`, `13`, `14`, `19`, `22`, `23`, `24`.
     Citation: `corpus/results/x86_kvm_corpus_20260506_072847_824797/details/result.json:108-205`.
101. It lists program IDs `27`, `28`, `29`, `32`, `33`, `34`, `37`, `38`, `39`, `40`.
     Citation: `corpus/results/x86_kvm_corpus_20260506_072847_824797/details/result.json:207-296`.
102. The `072847` runner details also show all eight tools with non-empty `prog_ids`.
103. `capable` has program `19`.
     Citation: `corpus/results/x86_kvm_corpus_20260506_072847_824797/details/result.json:3335-3344`.
104. `biosnoop` has programs `38`, `39`, `40`.
     Citation: `corpus/results/x86_kvm_corpus_20260506_072847_824797/details/result.json:3346-3357`.
105. `vfsstat` has programs `10`, `11`, `12`, `13`, `14`.
     Citation: `corpus/results/x86_kvm_corpus_20260506_072847_824797/details/result.json:3359-3372`.
106. `opensnoop` has programs `22`, `23`, `24`.
     Citation: `corpus/results/x86_kvm_corpus_20260506_072847_824797/details/result.json:3374-3385`.
107. `syscount` has programs `6`, `7`.
     Citation: `corpus/results/x86_kvm_corpus_20260506_072847_824797/details/result.json:3387-3400`.
108. `tcpconnect` has programs `32`, `33`, `34`.
     Citation: `corpus/results/x86_kvm_corpus_20260506_072847_824797/details/result.json:3402-3413`.
109. `tcplife` has program `37`.
     Citation: `corpus/results/x86_kvm_corpus_20260506_072847_824797/details/result.json:3415-3424`.
110. `runqlat` has programs `27`, `28`, `29`.
     Citation: `corpus/results/x86_kvm_corpus_20260506_072847_824797/details/result.json:3426-3437`.

111. ARM64 artifact `073741` has `bcc/set` as the only app.
     Citation: `corpus/results/aws_arm64_corpus_20260506_073741_286113/details/result.json:120-124`.
112. The ARM64 baseline BPF map lists exactly 7 programs.
113. These are `do_read`, `do_write`, `do_fsync`, `do_open`, raw sys_enter, `do_create`, raw sys_exit.
     Citation: `corpus/results/aws_arm64_corpus_20260506_073741_286113/details/result.json:125-188`.
114. The ARM64 app-level error field is empty.
     Citation: `corpus/results/aws_arm64_corpus_20260506_073741_286113/details/result.json:199-200`.
115. ARM64 `runner_details` show all eight tool commands were started.
     Citation: `corpus/results/aws_arm64_corpus_20260506_073741_286113/details/result.json:1236-1323`.
116. ARM64 `capable` command exists in runner details, but `prog_ids` is empty.
     Citation: `corpus/results/aws_arm64_corpus_20260506_073741_286113/details/result.json:1239-1246`.
117. ARM64 `biosnoop` command exists in runner details, but `prog_ids` is empty.
     Citation: `corpus/results/aws_arm64_corpus_20260506_073741_286113/details/result.json:1248-1255`.
118. ARM64 `vfsstat` has the five program IDs `82`, `83`, `84`, `87`, `89`.
     Citation: `corpus/results/aws_arm64_corpus_20260506_073741_286113/details/result.json:1257-1270`.
119. ARM64 `opensnoop` command exists in runner details, but `prog_ids` is empty.
     Citation: `corpus/results/aws_arm64_corpus_20260506_073741_286113/details/result.json:1272-1279`.
120. ARM64 `syscount` has the two program IDs `88`, `90`.
     Citation: `corpus/results/aws_arm64_corpus_20260506_073741_286113/details/result.json:1281-1294`.
121. ARM64 `tcpconnect` command exists in runner details, but `prog_ids` is empty.
     Citation: `corpus/results/aws_arm64_corpus_20260506_073741_286113/details/result.json:1296-1303`.
122. ARM64 `tcplife` command exists in runner details, but `prog_ids` is empty.
     Citation: `corpus/results/aws_arm64_corpus_20260506_073741_286113/details/result.json:1305-1312`.
123. ARM64 `runqlat` command exists in runner details, but `prog_ids` is empty.
     Citation: `corpus/results/aws_arm64_corpus_20260506_073741_286113/details/result.json:1314-1321`.
124. Therefore ARM64's seven programs are exactly `vfsstat` plus `syscount`.
125. The six empty tools are not visible as app errors.
126. The six empty tools are only visible by inspecting `runner_details.bcc_set.tool_startup`.
127. The field name `status="attached"` is misleading for empty `prog_ids`.
128. That misleading state is directly produced by `bcc_set.py`.
     Citation: `runner/libs/app_runners/bcc_set.py:182-184`.

## ARM64 Runtime Image Inspection

129. The local image `bpf-benchmark/runner-runtime:arm64` is present.
130. Docker reports it as `Architecture=arm64`, `Os=linux`.
131. A read-only, network-disabled container inspection found all eight scripts.
132. Found `/usr/sbin/capable-bpfcc`.
133. Found `/usr/sbin/biosnoop-bpfcc`.
134. Found `/usr/sbin/vfsstat-bpfcc`.
135. Found `/usr/sbin/opensnoop-bpfcc`.
136. Found `/usr/sbin/syscount-bpfcc`.
137. Found `/usr/sbin/tcpconnect-bpfcc`.
138. Found `/usr/sbin/tcplife-bpfcc`.
139. Found `/usr/sbin/runqlat-bpfcc`.
140. All eight were executable Python scripts.
141. This rejects Q1 possibility 1.
142. Independent file-cited support:
     the ARM64 result records every command path under `/usr/sbin`.
     Citation: `corpus/results/aws_arm64_corpus_20260506_073741_286113/details/result.json:1239-1321`.
143. Independent source support:
     if any binary had been unresolved, adapter construction would have failed before the runner.
     Citation: `runner/libs/app_runners/__init__.py:42-51`.

## Existing Individual ARM64 BCC Evidence

144. Existing pre-merge ARM64 corpus artifacts show the same BCC tools can work individually.
145. The `20260422_044304_037607` artifact reports `bcc/capable` status `ok`, `program_count=1`.
     Citation: `corpus/results/aws_arm64_corpus_20260422_044304_037607/details/result.json:36220-36231`.
146. The same artifact reports `bcc/biosnoop` status `ok`, `program_count=2`.
     Citation: `corpus/results/aws_arm64_corpus_20260422_044304_037607/details/result.json:36284-36311`.
147. The same artifact reports `bcc/vfsstat` status `ok`, `program_count=3`.
     Citation: `corpus/results/aws_arm64_corpus_20260422_044304_037607/details/result.json:36313-36347`.
148. The same artifact reports `bcc/opensnoop` status `ok`, `program_count=2`.
     Citation: `corpus/results/aws_arm64_corpus_20260422_044304_037607/details/result.json:36349-36376`.
149. The same artifact reports `bcc/syscount` status `ok`, `program_count=2`.
     Citation: `corpus/results/aws_arm64_corpus_20260422_044304_037607/details/result.json:36378-36405`.
150. The same artifact reports `bcc/tcpconnect` status `ok`, `program_count=3`.
     Citation: `corpus/results/aws_arm64_corpus_20260422_044304_037607/details/result.json:36407-36441`.
151. The same artifact reports `bcc/tcplife` status `ok`, `program_count=1`.
     Citation: `corpus/results/aws_arm64_corpus_20260422_044304_037607/details/result.json:36443-36463`.
152. The same artifact reports `bcc/runqlat` status `ok`, `program_count=3`.
     Citation: `corpus/results/aws_arm64_corpus_20260422_044304_037607/details/result.json:36465-36492`.
153. Therefore individual ARM64 tool support existed before `bcc/set`.
154. The current ARM64 `bcc/set` missing tools are not explained by absent ARM64 BCC packages.
155. The current ARM64 `bcc/set` missing tools are not explained by those tools being globally unsupported on ARM64.
156. The per-tool counts differ from x86 in some cases, but that is not the seven-program failure.
157. In the failing merged run, six of the eight tools contributed zero programs.
158. That is a merged-run startup/readiness issue, not a normal ARM64 per-tool count.

## Q1 Decision Table

159. Possibility 1:
     ARM64 image missing some BCC tool binaries.
160. Decision:
     rejected.
161. Evidence:
     all eight command paths are recorded in ARM64 runner details.
     Citation: `corpus/results/aws_arm64_corpus_20260506_073741_286113/details/result.json:1239-1321`.
162. Evidence:
     adapter would have failed if any tool binary was missing.
     Citation: `runner/libs/app_runners/__init__.py:42-51`.

163. Possibility 2:
     Some BCC tools fail to launch, and tolerant spawn hides it.
164. Decision:
     partially matches the observed status behavior, but not the literal evidence.
165. Evidence:
     spawn failures are caught and recorded as `failed`.
     Citation: `runner/libs/app_runners/bcc_set.py:137-141`.
166. Evidence:
     ARM64 records do not show `failed`; they show `attached` with empty IDs.
     Citation: `corpus/results/aws_arm64_corpus_20260506_073741_286113/details/result.json:1239-1321`.
167. Interpretation:
     the tools likely remained alive but were not attached when the global stable set was captured.
168. Interpretation:
     `bcc/set` does not distinguish "process alive but no BPF program yet" from "attached".
     Citation: `runner/libs/app_runners/bcc_set.py:174-184`.

169. Possibility 3:
     ARM64 BCC tools attach fewer programs each than x86.
170. Decision:
     rejected as the cause of 7 total.
171. Evidence:
     prior individual ARM64 artifacts have programs for all eight tools.
     Citation: `corpus/results/aws_arm64_corpus_20260422_044304_037607/details/result.json:36220-36492`.
172. Evidence:
     current merged ARM64 surface is not "all tools fewer"; it is only two tools non-empty.
     Citation: `corpus/results/aws_arm64_corpus_20260506_073741_286113/details/result.json:1239-1321`.

173. Possibility 4:
     Some attach failures are recorded but the schema does not show them unless inspecting startup records.
174. Decision:
     operationally close, but the record still lacks an explicit failure.
175. Evidence:
     startup records are available in `runner_details`.
     Citation: `corpus/driver.py:390-396`.
176. Evidence:
     empty `prog_ids` reveal missing per-tool BPF programs.
     Citation: `corpus/results/aws_arm64_corpus_20260506_073741_286113/details/result.json:1239-1321`.
177. Problem:
     those records say `status="attached"` and do not contain stderr/stdout tails for empty-ID tools.
178. Problem:
     the operator must infer failure from the empty `prog_ids`.
179. Root classification:
     silent incomplete attachment in the merged runner.

## Q1 Root Cause

180. The `bcc/set` runner snapshots a global live BPF program set.
181. That snapshot can become stable before all eight tools finish compiling and attaching.
182. This race is more likely on ARM64 because BCC startup and kernel header compilation are slower on `t4g.small`.
183. The code does not require every tool to expose at least one program.
184. The code does not require every live process to have non-empty fdinfo program IDs.
185. The code records live processes as `attached` even with `prog_ids=[]`.
186. ARM64 captured the first stable subset:
     five `vfsstat` programs and two `syscount` programs.
187. The result status remained `ok`.
188. That is consistent with the source's `live_tools > 0` rule.
     Citation: `runner/libs/app_runners/bcc_set.py:182-187`.
189. It is inconsistent with the intended "all 8 tools attached" mental model.
190. It is also inconsistent with fail-fast guidance.
     Citation: `CLAUDE.md:70-74`.

## Q2 Artifact Evidence

191. ARM64 loaded all expected kop modules.
192. ARM64 expected module list includes `bpf_select`.
     Citation: `corpus/results/aws_arm64_corpus_20260506_073741_286113/details/result.json:7-16`.
193. ARM64 module load has `failed_modules: []`.
     Citation: `corpus/results/aws_arm64_corpus_20260506_073741_286113/details/result.json:17-30`.
194. ARM64 loaded module list includes `bpf_select`.
     Citation: `corpus/results/aws_arm64_corpus_20260506_073741_286113/details/result.json:31-40`.
195. ARM64 `lsmod` snapshot includes `bpf_select` and no missing expected modules.
     Citation: `corpus/results/aws_arm64_corpus_20260506_073741_286113/details/result.json:68-90`.
196. Therefore Q2 hypothesis 2 is rejected.

197. ARM64 `cond_select` matched one site in each of seven programs.
198. Program `82` reports `matched=1 applied=0 skipped=1`.
     Citation: `corpus/results/aws_arm64_corpus_20260506_073741_286113/details/result.json:303-320`.
199. Program `83` reports `matched=1 applied=0 skipped=1`.
     Citation: `corpus/results/aws_arm64_corpus_20260506_073741_286113/details/result.json:440-455`.
200. Program `84` reports `matched=1 applied=0 skipped=1`.
     Citation: `corpus/results/aws_arm64_corpus_20260506_073741_286113/details/result.json:575-590`.
201. Program `87` reports `matched=1 applied=0 skipped=1`.
     Citation: `corpus/results/aws_arm64_corpus_20260506_073741_286113/details/result.json:710-725`.
202. Program `88` reports `matched=1 applied=0 skipped=1`.
     Citation: `corpus/results/aws_arm64_corpus_20260506_073741_286113/details/result.json:845-860`.
203. Program `89` reports `matched=1 applied=0 skipped=1`.
     Citation: `corpus/results/aws_arm64_corpus_20260506_073741_286113/details/result.json:982-997`.
204. Program `90` reports `matched=1 applied=0 skipped=1`.
     Citation: `corpus/results/aws_arm64_corpus_20260506_073741_286113/details/result.json:1118-1133`.
205. Every ARM64 skip reason is `platform lacks CMOV support`.
206. That skip reason is present in every cited block above.
207. There is no verifier failure in those blocks.
208. There is no `bpf_select64 kfunc not available` skip reason in the current ARM64 artifact.

209. KVM x86 follow-up applies eight `cond_select` sites.
210. Seven are applied in `sched_switch`.
     Citation: `corpus/results/x86_kvm_corpus_20260506_072847_824797/details/result.json:2012-2024`.
211. The corresponding program record names that program `sched_switch`.
     Citation: `corpus/results/x86_kvm_corpus_20260506_072847_824797/details/result.json:2112-2120`.
212. One is applied in `trace_req_start`.
     Citation: `corpus/results/x86_kvm_corpus_20260506_072847_824797/details/result.json:3084-3095`.
213. The corresponding program record names that program `trace_req_start`.
     Citation: `corpus/results/x86_kvm_corpus_20260506_072847_824797/details/result.json:3184-3192`.
214. So the x86 `matched=8 applied=8 skipped=0` statement matches the artifact.
215. The x86 applied sites are not the same program set as the ARM64 skipped sites.
216. That site difference is caused by Q1's reduced ARM64 program surface.
217. The site difference does not explain the ARM64 skip reason.

## Q2 Source Evidence

218. `CondSelectPass` is documented as lowering branch/mov patterns through `bpf_select64`.
     Citation: `bpfopt/crates/bpfopt/src/passes/cond_select.rs:15-29`.
219. The first runtime check in `CondSelectPass::run` is `ctx.platform.has_cmov`.
     Citation: `bpfopt/crates/bpfopt/src/passes/cond_select.rs:93-108`.
220. If `has_cmov` is false, it returns a skipped result with reason `platform lacks CMOV support`.
     Citation: `bpfopt/crates/bpfopt/src/passes/cond_select.rs:99-107`.
221. The `bpf_select64` registry check happens only after the CMOV check.
     Citation: `bpfopt/crates/bpfopt/src/passes/cond_select.rs:110-137`.
222. Therefore the observed ARM64 reason proves the pass exited before target-kfunc availability mattered.
223. `PlatformCapabilities` includes a boolean named `has_cmov`.
     Citation: `bpfopt/crates/bpfopt/src/pass.rs:697-706`.
224. `detect_platform()` sets `has_cmov=true` under `target_arch = "x86_64"`.
     Citation: `bpfopt/crates/bpfopt/src/main.rs:661-675`.
225. `detect_platform()` sets only the arch under `target_arch = "aarch64"`.
     Citation: `bpfopt/crates/bpfopt/src/main.rs:661-667`.
226. Target feature application resets `has_cmov=false` and only re-enables it for feature token `cmov`.
     Citation: `bpfopt/crates/bpfopt/src/main.rs:736-749`.
227. Daemon target JSON includes `features`.
     Citation: `daemon/src/bpf.rs:48-52`.
228. Daemon target probing writes `features: detect_features()`.
     Citation: `daemon/src/bpf.rs:85-99`.
229. x86 target feature detection pushes `cmov`.
     Citation: `daemon/src/bpf.rs:635-651`.
230. ARM64 target feature detection intentionally emits nothing.
     Citation: `daemon/src/bpf.rs:653-656`.
231. This is the direct code path for ARM64 `has_cmov=false`.
232. `cond_select` pass metadata requires target kop `bpf_select64`.
     Citation: `bpfopt/crates/bpfopt/src/passes/mod.rs:90-92`.
233. `cond_select` is described as `CMOV/CSEL`.
     Citation: `bpfopt/crates/bpfopt/src/passes/mod.rs:110-113`.
234. The CLI validates `cond_select` by requiring `bpf_select64`.
     Citation: `bpfopt/crates/bpfopt/src/main.rs:437-442`.
235. ARM64 has an actual `bpf_select64` module implementation.
236. ARM64 module comment says branchless conditional select via CSEL.
     Citation: `module/arm64/bpf_select.c:1-4`.
237. ARM64 module defines `bpf_select64`.
     Citation: `module/arm64/bpf_select.c:8-14`.
238. ARM64 emitter creates `tst` plus `csel`.
     Citation: `module/arm64/bpf_select.c:55-69`.
239. ARM64 emitter writes those two instructions when emitting.
     Citation: `module/arm64/bpf_select.c:98-105`.
240. ARM64 kop descriptor wires `emit_arm64`.
     Citation: `module/arm64/bpf_select.c:108-114`.
241. x86 module analogously implements CMOV.
     Citation: `module/x86/bpf_select.c:92-100`.
242. x86 descriptor wires `emit_x86`.
     Citation: `module/x86/bpf_select.c:148-154`.
243. Therefore the bpfopt gate is stale or misnamed for ARM64.
244. ARM64 should be admitted based on CSEL/select capability, not x86 CMOV naming.

## Q2 Hypothesis Table

245. Hypothesis 1:
     ARM64 `cond_select` pass has different verifier acceptance behavior.
246. Decision:
     rejected for this artifact.
247. Evidence:
     the pass returns a skip from bpfopt before ReJIT verifier behavior is relevant.
     Citation: `bpfopt/crates/bpfopt/src/passes/cond_select.rs:99-107`.
248. Artifact evidence:
     skip reason is `platform lacks CMOV support`, not a verifier error.
     Citation: `corpus/results/aws_arm64_corpus_20260506_073741_286113/details/result.json:303-320`.

249. Hypothesis 2:
     ARM64 kop module for `cond_select` is missing or different.
250. Decision:
     missing is rejected; different is true but not a failure.
251. Evidence:
     ARM64 loaded `bpf_select`.
     Citation: `corpus/results/aws_arm64_corpus_20260506_073741_286113/details/result.json:31-40`.
252. Evidence:
     ARM64 `bpf_select` is intentionally CSEL-backed.
     Citation: `module/arm64/bpf_select.c:55-114`.
253. Evidence:
     x86 `bpf_select` is CMOV-backed.
     Citation: `module/x86/bpf_select.c:92-154`.

254. Hypothesis 3:
     ARM64 daemon `target.json` is missing kop entries that x86 has.
255. Decision:
     not supported as the immediate cause.
256. Evidence:
     the current artifact did not retain a `target.json`.
257. Evidence:
     the skip reason proves bpfopt exited at the platform feature check before the kop registry check.
     Citation: `bpfopt/crates/bpfopt/src/passes/cond_select.rs:99-137`.
258. Evidence:
     module load confirms the kernel-side `bpf_select` module was resident.
     Citation: `corpus/results/aws_arm64_corpus_20260506_073741_286113/details/result.json:68-90`.
259. Caveat:
     a future debug capture should still retain the target file to verify BTF IDs.

260. Hypothesis 4:
     ARM64 matched different sites, and those sites all skip.
261. Decision:
     partially true but incomplete.
262. Evidence:
     ARM64 matched seven sites in `vfsstat` and `syscount` programs.
     Citation: `corpus/results/aws_arm64_corpus_20260506_073741_286113/details/result.json:125-188`.
263. Evidence:
     x86 applied sites in `sched_switch` and `trace_req_start`.
     Citation: `corpus/results/x86_kvm_corpus_20260506_072847_824797/details/result.json:2012-2024`.
264. Evidence:
     x86 applied sites also include `trace_req_start`.
     Citation: `corpus/results/x86_kvm_corpus_20260506_072847_824797/details/result.json:3084-3095`.
265. But:
     ARM64 sites skip for the same platform-level reason, not per-site verifier or shape reasons.
266. Root classification:
     stale platform feature gate plus Q1's reduced program surface.

## Prior ARM64 cond_select Status

267. Local prior ARM64 artifacts were scanned for `cond_select` applied entries.
268. No local ARM64 artifact had `cond_select` entries with `sites_applied > 0`.
269. Earlier April artifacts had structural skip reasons or `bpf_select64 kfunc not available`.
270. The current May 6 artifact is different:
     it has real matches and all skip due `platform lacks CMOV support`.
271. This means ARM64 `cond_select` has not been proven to apply in the local corpus history.
272. The current failure is now precise enough to fix without a new corpus run.

## Fix Plan

273. P0 fix:
     make `bcc/set` fail or wait until every spawned tool has at least one BPF program.
274. Files:
     `runner/libs/app_runners/bcc_set.py`.
275. Estimated size:
     45-70 LoC.
276. Required behavior:
     after spawning all children, poll each child fdinfo until every child has a non-empty program ID set or exits.
277. Required behavior:
     if a child exits before exposing programs, record `failed` with stderr/stdout tail and fail `bcc/set`.
278. Required behavior:
     if a child remains live but has no program IDs until timeout, record `failed` with stderr/stdout tail and fail `bcc/set`.
279. Required behavior:
     do not return a partial program set as `ok`.
280. Required behavior:
     keep returning all discovered programs for all attached tools.
281. Required non-behavior:
     do not filter ReJIT programs.
     Citation: `CLAUDE.md:5-10`.
282. Required non-behavior:
     do not exclude slow ARM64 tools or pass-specific program types.
283. Implementation detail:
     factor a helper like `_wait_for_all_tool_program_ids(spawned)`.
284. Implementation detail:
     reuse `_program_ids_from_fdinfo()`.
     Citation: `runner/libs/app_runners/bcc_set.py:64-90`.
285. Implementation detail:
     require non-empty per-tool IDs before recording `attached`.
286. Implementation detail:
     keep `wait_until_program_set_stable()` only after all tools have exposed at least one program, or replace it with per-tool stability.
287. Risk:
     some BCC tools may legitimately attach zero programs on a given kernel.
288. Counterpoint:
     existing individual ARM64 data shows these eight do attach programs.
     Citation: `corpus/results/aws_arm64_corpus_20260422_044304_037607/details/result.json:36220-36492`.
289. Test target:
     unit-test the status transition with a fake fdinfo reader and fake poll results.
290. Test purpose:
     catch the exact bug where `status=attached` is emitted with `prog_ids=[]`.
291. Test quality:
     this is a behavioral error-path/state-transition test, not a trivial getter test.
     Citation: `CLAUDE.md:79-84`.

292. P0 companion fix:
     make empty program IDs visible as an error, not informational metadata.
293. Files:
     `runner/libs/app_runners/bcc_set.py`, possibly `corpus/driver.py` only if existing details plumbing is insufficient.
294. Estimated size:
     15-30 LoC.
295. Required behavior:
     `runner_details` should include a real `failed` status and error string for no-program children.
296. Required behavior:
     preserve child stderr/stdout tail on the failure record.
297. Source hook:
     `_record_tool_status()` already supports `error`, `stderr_tail`, and `stdout_tail`.
     Citation: `runner/libs/app_runners/bcc_set.py:280-304`.
298. Result plumbing:
     `runner_details` already reaches final result payload.
     Citation: `corpus/driver.py:390-396`.
299. Avoid:
     adding informational-only `limitations` or similar fields.
     Citation: `CLAUDE.md:67-68`.

300. P1 fix:
     unbreak ARM64 `cond_select` feature gating.
301. Files:
     `bpfopt/crates/bpfopt/src/passes/cond_select.rs`,
     `bpfopt/crates/bpfopt/src/pass.rs`,
     maybe `daemon/src/bpf.rs`.
302. Estimated minimal size:
     8-15 LoC if allowing `Arch::Aarch64` in the current gate.
303. Estimated cleaner size:
     30-55 LoC if renaming capability to a generic conditional-select capability.
304. Minimal patch shape:
     admit `ctx.platform.arch == Arch::Aarch64` in addition to `ctx.platform.has_cmov`.
305. Better patch shape:
     replace `has_cmov` in this pass with `has_cond_select` or `has_branchless_select`.
306. Better patch shape:
     initialize it from x86 CMOV and ARM64 CSEL support.
307. Better patch shape:
     update skip reason to `platform lacks branchless select support`.
308. Required behavior:
     still require `bpf_select64` target kop.
     Citation: `bpfopt/crates/bpfopt/src/main.rs:437-442`.
309. Required behavior:
     do not proceed if target lacks `bpf_select64`.
     Citation: `bpfopt/crates/bpfopt/src/passes/cond_select.rs:110-137`.
310. Unit test:
     add a focused ARM64 platform context test where `arch=Aarch64`, `select64_btf_id` is set, and a simple site applies.
311. Unit test:
     add a test that x86/no-CMOV still skips if no generic select capability exists.
312. Why not just emit `cmov` feature from ARM64 daemon:
     it is semantically misleading; ARM64 has CSEL, not CMOV.
313. Why not just remove the platform check:
     non-x86/non-ARM64 targets should still fail fast.

314. P2 fix:
     capture enough target probing diagnostics for future architecture investigations.
315. Files:
     likely daemon command artifact plumbing or runner debug mode.
316. Estimated size:
     20-40 LoC if limited to failure/debug artifacts.
317. Constraint:
     do not add redundant informational fields to normal result payloads.
     Citation: `CLAUDE.md:67-68`.
318. Suggested form:
     when a kop pass skips for target/platform reasons, preserve target JSON in failure/debug artifacts, not summary metrics.
319. Reason:
     Q2 requested `target.json`, but this artifact did not retain it.
320. Priority:
     lower than fixing the actual gate.

## Final Answers

321. Q1 answer:
     actual cause is a `bcc/set` startup readiness bug.
322. Q1 answer:
     the ARM64 image has the tools, and individual ARM64 artifacts show the tools can attach.
323. Q1 answer:
     `bcc/set` captured only the first stable subset of live BPF programs.
324. Q1 answer:
     it then marked still-running children with empty fdinfo program sets as `attached`.
325. Q1 answer:
     the seven programs are exactly `vfsstat` plus `syscount`.
326. Q1 answer:
     the result schema contains the clue in `runner_details`, but it does not surface the condition as an error.
327. Q1 closest listed possibility:
     possibility 4 for the operator workflow, plus possibility 2's tolerant runner behavior, but not literal launch failures.

328. Q2 answer:
     actual cause is bpfopt's platform feature gate.
329. Q2 answer:
     ARM64 loads `bpf_select`, and the ARM64 module has a CSEL emitter.
330. Q2 answer:
     `CondSelectPass` exits before using it because `ctx.platform.has_cmov` is false on ARM64.
331. Q2 answer:
     x86 applies because x86 feature detection sets `cmov`.
332. Q2 answer:
     ARM64 sites are different due Q1, but the skip reason is platform-level and applies to every site.
333. Q2 closest listed hypothesis:
     none exactly; hypothesis 4 is partly true for site identity, but the direct cause is a stale CMOV-only gate.
