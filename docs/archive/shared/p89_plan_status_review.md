# P89 plan §3.1 kinsn status review

Scope: reviewed `docs/kernel-jit-optimization-plan.md` §3.1 against the kinsn research/design documents under `docs/tmp/20260329/` plus the earlier targeted 2026-03-24/26 documents named in the task. I also used two 2026-03-23 documents where the existing plan row already depended on those conclusions (`Frozen map inlining`, `Spill/fill 消除`).

| 候选 | plan 表当前状态 | 调研实际结论 | 是否需要更新 plan |
| --- | --- | --- | --- |
| WIDE_MEM | ✅ 已实现 | 已实现项；本轮未发现新的 kinsn research 结论要求改状态。 | 否 |
| ROTATE | ✅ 已实现 | 已实现项；本轮未发现新的 kinsn research 结论要求改状态。 | 否 |
| COND_SELECT | ✅ 已实现 | 已实现项；本轮未发现新的 kinsn research 结论要求改状态。 | 否 |
| BITFIELD_EXTRACT | ✅ 已实现 | 已实现项；本轮 ARM64 调研建议的是扩展现有 extract 覆盖 UBFX copy-form，而不是改此行状态（`docs/tmp/20260329/arm64_kinsn_research_20260329.md:416`）。 | 否 |
| BRANCH_FLIP | ✅ 已实现；Paper B PGO pass（非默认） | 已实现项；不属于本轮 kinsn 候选状态刷新，未发现相反结论。 | 否 |
| ENDIAN_FUSION | ✅ 已实现 | 已实现项；本轮未发现新的 kinsn research 结论要求改状态。 | 否 |
| Dynamic map inlining | ✅ pass 已实现；v3 runtime wiring 待迁移 | ✅ 值得做；v1 设计收窄为 ARRAY/常量 key/固定 offset/watch-serve（`docs/tmp/20260324/dynamic_map_inlining_design_20260324.md:7`），真实 workload 的 dynamic map specialization 空间大（`docs/tmp/20260323/map_inlining_opportunity_analysis_20260323.md:640`）。 | 否 |
| Verifier const prop | ✅ 已实现 | ✅ 值得做；verifier-assisted const prop 比 SIMD 更稳，后续 dead branch/DCE/strength reduction 收益面大（`docs/tmp/20260323/simd_constprop_opportunity_analysis_20260323.md:13`, `docs/tmp/20260323/simd_constprop_opportunity_analysis_20260323.md:601`）。 | 否 |
| DCE | ✅ 已实现 | ✅ 与 const prop / map inline 联动；本轮未发现需改状态。 | 否 |
| Bounds check merge | ✅ 已实现 | ✅ 值得做 merge/hoist，不是纯 delete；42 guard 中严格冗余 0%，但 83.3% 位于可 merge ladder（`docs/tmp/20260324/bounds_check_elimination_research_20260324.md:17`, `docs/tmp/20260324/bounds_check_elimination_research_20260324.md:572`）。 | 否 |
| 128-bit LDP/STP | ✅ module 已实现 | ✅ ARM64 值得做，x86 不值得做 native path；ARM64 pair site 总计 1641，其中 STX 1441（`docs/tmp/20260324/128bit_wide_loadstore_research_20260324.md:10`, `docs/tmp/20260324/128bit_wide_loadstore_research_20260324.md:102`, `docs/tmp/20260324/128bit_wide_loadstore_research_20260324.md:522`）。 | 否 |
| Bulk memory kinsn | ✅ x86 + ARM64 kinsn modules 已实现 | ✅ 值得做 no-FPU bulk memory；x86 v1 走 `rep movsb/stosb`，ARM64 v1 走 `LDP/STP`/`XZR`，不做 true SIMD 主线（`docs/tmp/20260324/simd_kinsn_design_20260324.md:14`, `docs/tmp/20260324/simd_kinsn_design_20260324.md:742`）。 | 否 |
| ADDR_CALC (LEA) | ❌ 低优先级 | ❌ 不做第一波；strict LEA 只有 14 sites / 7 objects，corpus geomean 预期不可见（`docs/tmp/20260324/addr_calc_lea_research_20260324.md:9`, `docs/tmp/20260324/addr_calc_lea_research_20260324.md:626`, `docs/tmp/20260324/addr_calc_lea_research_20260324.md:653`）。 | 是，说明更精确 |
| Helper call specialization | 🔄 调研完成 | 📝 值得做；P0 是 `skb_load_bytes -> direct packet access`，590 sites 且 Cilium 428；`probe_read_kernel` 不适合当普通 load peephole（`docs/tmp/20260324/helper_call_inlining_research_20260324.md:12`, `docs/tmp/20260324/helper_call_inlining_research_20260324.md:499`, `docs/tmp/20260324/helper_call_inlining_research_20260324.md:536`）。 | 是 |
| Frozen map inlining | ❌ 不做 | ❌ 不值得优先做；显式 frozen map hot-path helper lookup 接近 0，当前生态几乎没人 freeze 业务 hot-path map（`docs/tmp/20260323/map_inlining_opportunity_analysis_20260323.md:55`, `docs/tmp/20260323/map_inlining_opportunity_analysis_20260323.md:627`）。 | 否 |
| Subprog inline | ⏸ 不在 OSDI 主线 | ⏸ 有实验价值但不进当前主线；834 callsites / 67 objects，live REJIT 最大 blocker 是新 `func_info/line_info` metadata（`docs/tmp/20260326/subprog_inline_research_20260326.md:11`, `docs/tmp/20260326/subprog_inline_research_20260326.md:14`）。 | 是，说明更精确 |
| Const propagation | ↗ 归入 #424 | 已归入 verifier const prop；本轮未发现需独立展开。 | 否 |
| SIMD (FPU) | ❌ 不进 OSDI 主线 | ❌ x86 true-SIMD 不进主线；ARM64 NEON 仅作为 ≥1KiB 且 `may_use_simd()` 成立的 phase 2，主线做 no-FPU wide-machine kinsn/scalar CRC（`docs/tmp/20260326/simd_fpu_kinsn_deep_research_20260326.md:1125`, `docs/tmp/20260326/simd_fpu_kinsn_deep_research_20260326.md:1147`, `docs/tmp/20260326/simd_fpu_kinsn_deep_research_20260326.md:1195`）。 | 否 |
| Tail-call specialization | ✅ 调研完成 | 📝 值得做；贡献点应是 dynamic tail-call site inline-cache specialization，phase 1 聚焦 guarded constant-key fast path；blocker 是 site-local key profiling 与 poke_tab shape（`docs/tmp/20260326/tail_call_specialization_research_20260326.md:16`, `docs/tmp/20260326/tail_call_specialization_research_20260326.md:31`, `docs/tmp/20260326/tail_call_specialization_research_20260326.md:961`, `docs/tmp/20260326/tail_call_specialization_research_20260326.md:970`）。 | 是 |
| Spill/fill 消除 | ❌ 不做 | ❌ 通用 spill/fill peephole 独立优先级低；内核已有 `KF_FASTCALL` 相关删除，保守匹配只有几十对（`docs/tmp/20260323/comprehensive_optimization_survey_20260323.md:53`, `docs/tmp/20260323/comprehensive_optimization_survey_20260323.md:540`）。 | 否 |
| POPCNT/CLZ/CTZ | ❌ 不做 | ❌ 当前不值得做；POPCNT/CLZ/CTZ corpus 无站点支撑（`docs/tmp/20260329/bit_ops_kinsn_research_20260329.md:15`, `docs/tmp/20260329/bit_ops_kinsn_research_20260329.md:249`, `docs/tmp/20260329/bit_ops_kinsn_research_20260329.md:252`）。 | 否 |
| CRC32 | ⏸ 不做默认 pass | ⏸ broad corpus 不值得优先做，但 loxilb/SCTP CRC32C 是窄而深的专项机会；2 个 byte-update site，建议 CRC32C-only scalar step8/step64（`docs/tmp/20260329/crc32_kinsn_research_20260329.md:8`, `docs/tmp/20260329/crc32_kinsn_research_20260329.md:42`, `docs/tmp/20260329/crc32_kinsn_research_20260329.md:392`, `docs/tmp/20260329/crc32_kinsn_research_20260329.md:410`）。 | 是，状态更精确 |
| CCMP | 📝 值得做 | 📝 值得做 restricted first wave；实际是 4957 sites / 6228 saved branches，不是 74 sites（`docs/tmp/20260329/arm64_kinsn_research_20260329.md:83`, `docs/tmp/20260329/arm64_kinsn_research_20260329.md:145`, `docs/tmp/20260329/arm64_kinsn_research_20260329.md:409`）。 | 是 |
| Prefetch | 📝 设计完成 | 📝 设计完成且值得作为 runtime-guided memory-hint showcase；17391+21 potential lookup sites，但无 profile 默认不插，hot/missy site 预期 2.5-25ns/exec（`docs/tmp/20260329/memory_hints_kinsn_research_20260329.md:11`, `docs/tmp/20260329/prefetch_kinsn_design_20260329.md:9`, `docs/tmp/20260329/prefetch_kinsn_design_20260329.md:24`, `docs/tmp/20260329/prefetch_kinsn_design_20260329.md:684`）。 | 是，状态补“值得做” |
| NT store | ❌ 不做 | ❌ 当前阶段不值得优先做；direct ringbuf reserve/submit 只有 10/9，主要写热点在 helper 内部（`docs/tmp/20260329/memory_hints_kinsn_research_20260329.md:12`, `docs/tmp/20260329/memory_hints_kinsn_research_20260329.md:246`, `docs/tmp/20260329/memory_hints_kinsn_research_20260329.md:310`）。 | 否 |
| PDEP/PEXT | ❌ 不做 | ❌ 不值得做；严格候选 0，AMD Zen1/2 风险且 ARM64 无对等单指令（`docs/tmp/20260329/bit_ops_kinsn_research_20260329.md:18`, `docs/tmp/20260329/bit_ops_kinsn_research_20260329.md:245`）。 | 否 |
| SHRX/SHLX | ❌ 不做 | ❌ 不值得做；site 多但 upstream x86 BPF JIT 已覆盖，增量收益接近 0（`docs/tmp/20260329/bit_ops_kinsn_research_20260329.md:16`, `docs/tmp/20260329/bit_ops_kinsn_research_20260329.md:141`, `docs/tmp/20260329/bit_ops_kinsn_research_20260329.md:243`）。 | 否 |
| MADD/MSUB | ⏸ 低优先级 | ⏸ MADD 可以做但只是二级优化，47 direct sites；MSUB direct site 为 0，不进 first wave（`docs/tmp/20260329/arm64_kinsn_research_20260329.md:85`, `docs/tmp/20260329/arm64_kinsn_research_20260329.md:420`, `docs/tmp/20260329/arm64_kinsn_research_20260329.md:424`）。 | 是 |
| UBFX/BFI | ⏸ 低优先级 | 📝 UBFX 应作为现有 extract pass 的 copy-form 补强，74 with-copy sites；BFI strong sites 为 0，不做（`docs/tmp/20260329/arm64_kinsn_research_20260329.md:87`, `docs/tmp/20260329/arm64_kinsn_research_20260329.md:89`, `docs/tmp/20260329/arm64_kinsn_research_20260329.md:416`, `docs/tmp/20260329/arm64_kinsn_research_20260329.md:424`）。 | 是 |
| RDTSC | 📝 待做 | ❌ 不做透明 rewrite；需求强但抽象不对，若做应是显式 opt-in x86 timing primitive，默认 pipeline 不做（`docs/tmp/20260329/rdtsc_adc_kinsn_research_20260329.md:8`, `docs/tmp/20260329/rdtsc_adc_kinsn_research_20260329.md:163`, `docs/tmp/20260329/rdtsc_adc_kinsn_research_20260329.md:296`）。 | 是 |
| ADC/SBB | 📝 待做 | ❌ 不进默认 pipeline；语义合格但当前 corpus 0 add/sub carry-chain site，workload 压力极低（`docs/tmp/20260329/rdtsc_adc_kinsn_research_20260329.md:9`, `docs/tmp/20260329/rdtsc_adc_kinsn_research_20260329.md:204`, `docs/tmp/20260329/rdtsc_adc_kinsn_research_20260329.md:290`, `docs/tmp/20260329/rdtsc_adc_kinsn_research_20260329.md:297`）。 | 是 |
| SETcc/CSET | 📝 待做 | 未充分评估；未找到专门调研文档。 | 是，标为待调研 |
| ANDN | 📝 待做 | 未充分评估；未找到专门调研文档。 | 是，标为待调研 |
| BLSI/BLSR/BLSMSK | 📝 待做 | 未充分评估；未找到专门调研文档。 | 是，标为待调研 |
| 除法强度削减 | 📝 待做 | 未充分评估；只有 verifier const-prop/strength-reduction 的泛化论证，没有 division-specific corpus census（`docs/tmp/20260323/simd_constprop_opportunity_analysis_20260323.md:13`, `docs/tmp/20260323/simd_constprop_opportunity_analysis_20260323.md:318`）。 | 是，标为待调研 |
| PAUSE/YIELD | ❌ 不做 | ❌ 不值得优先推进；compiled corpus 普通 `bpf_spin_lock` 为 0，helper 内部已有 arch wait hint，BPF-side hint 指令收益不足（`docs/tmp/20260329/pause_yield_kinsn_research_20260329.md:10`, `docs/tmp/20260329/pause_yield_kinsn_research_20260329.md:55`, `docs/tmp/20260329/pause_yield_kinsn_research_20260329.md:234`）。 | 否 |
| 寄存器重分配 | 📝 待做 | 未充分评估；`rejit_register_mapping` 调研的是受限 spill-to-register，不是纯 bytecode register reallocation。 | 是，标为待调研 |
| REJIT spill-to-register | 📝 设计完成 | 📝 值得做；任意 reg_map 不现实，受限 spill-to-register 可行，arm64 x23/x24 先做，x86 r12 后做（`docs/tmp/20260329/rejit_register_mapping_research_20260329.md:10`, `docs/tmp/20260329/rejit_register_mapping_research_20260329.md:20`, `docs/tmp/20260329/rejit_register_mapping_research_20260329.md:790`）。 | 是，状态补“值得做” |
| Region kinsn（寄存器扩展） | 📝 待做 | 未充分评估；未找到专门调研文档，且当前 kinsn v2 仍需先明确 region ABI / proof-lowering 边界。 | 是，标为待调研 |

## 待调研

以下 §3.1 行仍缺少专门调研文档，plan 表应明确保留为 `📝 待做（待调研）`：

- `SETcc/CSET`: 需要区分 standalone boolean-set kinsn 与现有 `COND_SELECT`/ARM64 `CSET` lowering 的覆盖关系。
- `ANDN`: 需要 corpus census for `a & ~b` / mask-clear idioms，且要核对 x86 BMI1-only 与 ARM64 fallback 的 ROI。
- `BLSI/BLSR/BLSMSK`: 需要 bitmap/lowest-set-bit idiom census。
- `除法强度削减`: 需要 division-specific constant-divisor corpus census；现有资料只证明 verifier const-prop 可能打开 generic strength reduction 空间。
- `寄存器重分配`: 需要独立评估纯 bytecode BPF-register remapping；不要和 `REJIT spill-to-register` 混为一项。
- `Region kinsn（寄存器扩展）`: 需要先定义 region ABI、verifier proof model、native emit 与现有 kinsn v2 proof-lowering 的关系。
