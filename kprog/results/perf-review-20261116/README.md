# Native-path performance source review

Reviewed 2026-11-16, starting from root 6abe4cd1d / kernel 099357174783,
while the coordinator owns source cleanup. This directory contains findings,
not implementation changes. No guest or new check was added. Line numbers refer
to the source read during this review; subsequent cleanup may move them.
`evidence.json` records the current source revision and retained measurements.

1. **Redundant fixed-frame saving is confirmed; the suspected tail-pop mismatch
   was rejected by tracing the actual call site.**

   Correction to the first review commit a61f12aae: the ABI metadata alone
   does not control the tail stub. `kprog/x86/native_lab/native_link/src/x86.rs:1469`
   calls build_x86_tail_call_inline with an explicit 0xf at line 1472, matching
   the kernel's four fixed saves. This code has been present since 6a3152eb70
   (11-11), not a cleanup change. Actual retained Cilium payload at offsets
   0x2b0–0x2b6 pops r15/r14/r13/rbx before the two counter-slot pops at
   0x2b7–0x2b8. Therefore the mask=0 in 34/0.abi does not demonstrate a bad
   tail transition, and the earlier assertion is withdrawn. It is not an
   established cause of Cilium's host path.

   The overhead finding still holds:
   `vendor/linux-framework/arch/x86/net/bpf_jit_comp.c:3799` sets all four
   callee-register booleans true; lines 3807–3817 save/restore them around P.
   Retained BCC sys_exit payload 25/0.blob independently begins with pushes
   of r15/r14/r13/r12/rbx and a 16-byte allocation. Both sets execute per call.
   This is a candidate for using the actual native ABI needs instead of an
   unconditional save set; no speed gain has been measured.

   `include/linux/bpf_native.h:38` carries callee_saved_mask, but the JIT above
   ignores it. `direct-native/bpf_x86_native_lab.c:402–408` does not assign
   that field, while the loader transports an ABI mask at
   `native_loader.cpp:3483`. The actual fixed-four convention and its tail
   caller agree; this parallel mask metadata and historical stripping logic
   should be consolidated carefully, not mistaken for a live mismatch.
   Any simplification must change the frame and tail cleanup together.

2. **Confirmed native map-update dispatch gap on the dominant BCC path.**

   `kprog/libnativeloader/src/native_loader.cpp:3117` initializes update sites
   with the generic `bpf_map_update_elem` target. Lines 3126–3150 specialize
   only small ARRAY/PERCPU_ARRAY values; known HASH updates keep that generic
   target. `x86.rs:1579` emits a call to it. Kernel
   `kernel/bpf/helpers.c:59` implements that wrapper with an RCU warning check
   and an indirect `map->ops->map_update_elem` call (lines 62–63).

   The eBPF side already removes this dispatch for a known map:
   `kernel/bpf/verifier.c:23944` patches directly to `ops->map_update_elem`.
   Delete operations similarly patch to map-specific operations at line 23947,
   while the native generic helper resolution at `x86.rs:1598` has no matching
   delete specialization. This is a concrete way native can lose despite a
   faster lookup. Bind the existing proven native map identity to the actual
   map operation at link time, retaining that operation's semantics; no new
   wrapper, selector or per-call validation is needed.

   Retained relocation records for BCC `sys_enter` contain one generic update
   call, one pid/tgid helper call, one fast-clock call and one cgroup helper
   call. `sys_exit` also retains a generic update call. Relocation presence is
   static, not a claim all conditional calls execute. Syscount calls update on
   every accepted syscall entry (`vendor/bpf/bcc/libbpf-tools/syscount.bpf.c:66`).

   The actual current stats-1 run is 131847_109569:

   | Group | eBPF ns/call | Native ns/call | eBPF time share | Installed B, eBPF → native |
   |---|---:|---:|---:|---:|
   | sys_enter | 85.796 | 87.185 | 31.74% | 108 → 153 |
   | sys_exit | 112.731 | 115.966 | 41.70% | 406 → 3483 |
   | four tracepoint__sys programs | 931.073 | 932.416 | 17.81% | 1486 → 6352 |
   | sched_switch | 129.648 | 180.201 | 0.94% | 935 → 3916 |

   The first two groups account for 73.44% of baseline BPF time. Across all
   recorded calls the means are 122.943 → 125.223 ns, or 0.981793x. Improving
   only scheduler probes cannot close the main gap. These sums retain all 25
   records in each arm; colliding names keep their individual IDs in evidence.

3. **Confirmed missing whole-program optimization of frozen BCC configuration.**

   `native_loader_context_lto.hpp:12` returns the original object for programs
   outside PERF_EVENT when there are no generated function bodies. Thus BCC's
   embedded IR is not optimized by this route. The subsequent machine-code
   rewrites cannot generally fold branches across a local helper call.

   `syscount.bpf.c:13` defaults `count_by_process` to false; the frozen runner
   uses only `-L -i 1` (`runner/libs/app_runners/bcc_set.py:35`).
   `vendor/repos/bcc/libbpf-tools/syscount.c:427` enables latency, while setting
   count_by_process at line 429 requires the separate process-count option.
   Consequently `syscount.bpf.c:107` guards the process-name read with a
   configuration branch that is false in this workload. The native payload
   still contains the branch and its cold code. Its two appended probe-read
   routines occupy 490 B, even though that guarded process-name path is unused.

   The kernel already recognizes frozen program-readonly map values:
   `kernel/bpf/verifier.c:7193` uses RDONLY_PROG, frozen and completed writes to
   establish immutability before direct reads. In contrast, native data binding
   at `native_loader.cpp:3000` supplies an address, not a constant initializer
   to LLVM. Consuming the actual existing immutable map facts for LTO would
   remove cold branches and their helper routines as a class. Do not replace
   all volatile reads blindly or assume mutable maps are constant. This is a
   missing optimization, not evidence that the source's optional branch should
   be deleted for configurations that use it.

4. **The generic ARRAY/LPM fast paths are a chain of local calls and dispatches.**

   `x86.rs:1809` rewrites generic map-helper calls to an appended ARRAY routine.
   Its fallback retains a generic helper relocation
   (`x86_runtime_array.rs:36`); `x86.rs:1823` then patches that relocation to
   the appended LPM routine. Therefore a non-ARRAY LPM lookup reaches the LPM
   code through the ARRAY fallback. Both routines preserve CALL/RET boundaries;
   they are not compiler-inlined into P at the call site.

   The ARRAY map-type compare is at `x86_runtime_array.rs:8`, with runtime key
   bounds at line 14. LPM adds map-type and 12-byte-key-shape tests at
   `x86_lpm_lookup.rs:10` and :12 before walking the trie. Loader shape
   specialization (`native_loader.cpp:2734–2803`) has no LPM case, so an actual
   known LPM map such as OTel's pid_page_to_mapping_info remains `kind=call`
   with the generic target in the retained plan. That loses an opportunity to
   select the known shape once at link time and avoid the dispatch chain.
   A genuinely unknown dynamic map still needs behavior for its actual type.

5. **Probe-read LTO retains substantial per-call overhead; policy and fault
   behavior are not implied away by stock verification.**

   `x86_probe_read.rs:37` pushes five registers. Lines 54–58 still call
   `copy_from_kernel_nofault_allowed` or `nmi_uaccess_okay`; user reads also
   test SMAP capability at line 64. The copy checks an R11 fault-status marker
   after each word/byte load (lines 94–95, 104–105), then restores pagefault
   state, conditionally zeroes the destination, and pops registers (:123–146).
   A four/eight-byte read still uses this general routine and its loop/length
   logic. The emitter's `share` at :150 means one copy per program/helper kind,
   not sharing among programs of the application.

   `arch/x86/mm/maccess.c:17–36` defines the real kernel-address policy and
   `mm/maccess.c:36–51` defines nesting/fault handling. These dynamic source
   addresses may legitimately fault; verifier acceptance of a probe-read call
   does not prove the source readable. Keep error/zeroing semantics. Candidate
   simplifications are link-time CPU-feature selection, known-size call-site
   lowering and direct exception recovery to the common fault exit, rather
   than a success-status branch after every load. The latter must fit the
   existing exception representation; it is not a license to drop recovery.

6. **LTO pieces: what the code buys, and what is actually measured.**

   | Piece | Source effect | Retained byte attribution / measured limit |
   |---|---|---|
   | Typed ARRAY/per-CPU ARRAY | Removes a generic helper dispatch; emits key test/address arithmetic (`x86.rs:3994`) | Native parity with optimizations eBPF already has; no isolated current gain measured. |
   | Runtime ARRAY + LPM | Replaces generic calls by the dispatch chain above | OTel sampling entry 67 + 330 appended B; no isolated current per-call gain. |
   | Hash | Shipped image contains a 2444-B custom routine in each participating program | BCC sys_exit 3465-B payload includes 2444 hash + 490 reads + 531 rest. Source f45bb2485 removes the custom routine in favor of the existing shared kernel raw lookup; unshipped, timing effect unknown. |
   | Probe reads | Direct recoverable loads, but preserves policy/nesting/zeroing and local call boundary | 490 B in sys_exit, 255 B in OTel sampling entry; no isolated current gain. |
   | Clock | `x86.rs:23` calls the same fast monotonic implementation directly | Kernel helper itself returns it (`kernel/bpf/helpers.c:178–181`). Removes wrapper linkage, not clock-source/seqlock work. |
   | Tail calls | Machine-code dispatch avoiding the nonfunctional C helper stub | Required semantics; uses the fixed-four convention in item 1; no tail-pop mismatch demonstrated. |
   | CPU/current-task helpers | Native generally retains helper calls via `x86.rs:1598` | Kernel verifier inlines CPU and task loads at `verifier.c:24000` and :24027. Current source has no matching native helper-specific rewrite; do not claim these calls are already inlined. |
   | Frozen data | Current loader supplies live data addresses | Missing whole-IR folding for BCC described above. |

   Historical combined speedups are not individual component measurements.
   Current BCC installed text is 38841 versus 7965 B (4.876x), so the half-size
   target is unmet. Hot helper implementations and duplicated/cold routines,
   not load-time validation strings, are the relevant byte contributors.

7. **Stage audit: which checks can affect the measured call.**

   | Source | Stage | Assessment |
   |---|---|---|
   | `direct-native/bpf_x86_native_lab.c:291–324`, relocation kinds/bounds, blob locks, debugfs permission/size checks | Upload/JIT load | Not a per-call cause. Emitted payload is copied once; those C guards do not run on each invocation. |
   | `arch/x86/net/bpf_jit_comp.c:3725` relocation validation | JIT load | Same distinction; deleting it cannot recover per-call time. |
   | `x86.rs:3995`, :4010, :4170 and emitted-slot validation in `*_share` | Userspace link | Validates emitter inputs before execution. Not native hot-path branches. |
   | ARRAY/LPM type/shape dispatch | Per lookup | Avoid for an already-proven fixed map identity/shape. |
   | ARRAY bounds, LPM query prefix/empty tree, lookup NULL, LRU reference bit, tail count/empty program slot | Per lookup/tail call | These implement observable operation semantics. Verification of pointer/argument types alone does not make dynamic values valid/nonempty. Fold only facts already established for that call. |
   | ARRAY update flags at `x86.rs:4197–4200` | Per update | BPF_NOEXIST/BPF_EXIST/error semantics; constant flags can specialize, unknown flags cannot simply disappear. |
   | Generic map wrapper RCU warning and operation dispatch | Per helper | Bypass via the same proven-map direct operation binding used by the stock verifier. |
   | Probe policy/fault handling | Per read | Dynamic semantics, with avoidable general-routine overhead as item 5. |
   | `include/linux/filter.h:707–720` stats accounting; `kernel/trace/bpf_trace.c:2079` recursion/RCU protection | Per event | Existing common kernel execution envelope, not a new native-only validation loop. |

8. **Confirmed Cilium cb translation bug; exact packet causality still open.**

   Native `vendor/bpf/cilium/bpf/include/linux/bpf.h:6081` lays out next/prev,
   dev/sk and tstamp before `__u32 cb[12]`, so native cb[0] is physical byte 40.
   The sole kernel BTF confirms sk_buff.cb=40, but that is not the translation
   of the public eBPF cb field. `net/core/filter.c:9868–9884` adds both
   offsetof(sk_buff, cb) and offsetof(qdisc_skb_cb, data). Kernel BTF gives
   the latter as 8, hence eBPF cb[0] means physical byte **48**, not 40.
   `include/linux/filter.h:947–964` documents why this qdisc prefix exists.

   Native ctx_store_meta/ctx_load_meta at `ctx/skb.h:153–161` index the wrong
   member directly. `lib/overloadable_skb.h:15–19` clears indices 0–4.
   This is visible in actual retained cil_from_container payload 34/0.blob:
   instruction offsets 0x45,0x4c,0x53,0x5a,0x61 store zero at skb+40,44,48,52,56.
   The translated eBPF range is 48,52,56,60,64. Native therefore clears the
   qdisc packet-length/segments/classid prefix and leaves the last two public
   metadata words uncleared. Other native metadata reads/writes have the same
   8-byte displacement. This is a demonstrated source/object semantic mismatch,
   unlike the rejected tail-mask hypothesis. A hybrid native context needs the
   public cb[5] view mapped to qdisc data, preserving the physical offsets of
   all following fields; simply copying sk_buff.cb's BTF offset repeats the bug.

   This explains a concrete way native can corrupt or misread packet metadata;
   the one-packet return/redirect comparison is still required to establish
   whether it produces the observed host path. The finding needs no new
   runtime check or benchmark change.

   **Separate configuration lead, not a confirmed loaded-value mismatch:**

   `vendor/bpf/Makefile:81–104` compiles a maximum-feature native variant,
   including HOST_ROUTING/ROUTING; lines 266–275 include the checked-in headers.
   `cilium/bpf/ep_config.h:7` explicitly calls itself a dummy header.
   `lib/static_data.h:65–86` uses direct global reads natively and BPF assembly
   references in the eBPF build. The native ELF's rt_info, cilium_net_ifindex,
   cilium_host_ifindex, interface_ifindex, endpoint_id and host_ep_id initial
   values are all zero (evidence.json).

   However, these initial values are not proof of the loaded values: the
   loader attempts to bind native globals to actual source DATASEC offsets
   (`native_loader.cpp:2969–3002`). The concrete hole is line 2971's continue
   if no corresponding data map is found. Later native relocation can embed
   literal ELF data (`x86.rs:2650–2665`). An unbound config variable may then
   retain its initial value. Go applies the agent constants at
   `vendor/repos/cilium/pkg/bpf/constants.go:23` and computes reachability from
   them at `pkg/bpf/reachability.go:31`. The two paths must consume the same
   applied configuration, not merely the same declaration spelling.

   The IPv4 host-route decision is visible at `bpf_lxc.c:1363`: rt_info feeds
   fib_redirect_v4; REDIRECT returns at :1378, while NOT_FWDED can fall through
   to the stack at :1381. `lxc_redirect_to_host` uses cilium_net_ifindex at
   :87–89. Compare those actual loaded values and the FIB result for the
   benchmark packet. The tail-pop mismatch initially suspected in item 1 was rejected
   by actual call-site and payload inspection. This review has not performed the requested one-packet
   eBPF/native comparison and does not declare which lead caused that packet.

9. **d9 tracing multiplication is not established by the retained ratios.**

   `runqlat.bpf.c:130` and :144 are tp_btf raw-tracepoint handlers, not ordinary
   fentry trampoline programs. Their path is
   `kernel/trace/bpf_trace.c:2073–2093`, with exactly one bpf_prog_run at :2088.
   Its stats envelope increments once at `include/linux/filter.h:718`.
   The native JIT body at `bpf_jit_comp.c:3806–3819` emits no second counter
   increment. Source inspection found no native second increment here.
   Other BCC tracing programs do not have the same count ratio: for example,
   fentry_vfs_open is 1.374x in 060435, while sched_switch is 2.510x.

   Kernel 099357174783 predates both images; the relevant shim attach source
   does not have a recorded change between the two publications. The old
   native scheduler image sizes are 3916/160 B and the newer run has the same
   sizes. Sizes do not establish byte identity or prove attachment equality.
   One visible native ID per name does not rule out two links to that ID.

   The heterogeneous workload's median call ratio is not a reference count of
   scheduler events. In d9 the sockfd work rises 77.564M→106.861M transfers and
   its CPU accounting 503.63→737.29 s; in the newer run it is near equal and
   scheduler counts fall (54.486M→47.023M). These observations support changed
   scheduling as an alternative explanation; they do not prove it. Therefore
   neither “twice per event” nor “2.5x actual context switches” is established.
   A same-window independent kernel event count plus program count/histogram
   would decide multiplicity. A fixed number of sched_yield calls alone is
   insufficient: yielding need not switch tasks. No new guest/check was run
   during coordinator cleanup, and the previous results are not reinstated.

10. **Concrete cleanup candidates for the coordinator.**

    - The non-native-header branch at `direct-native/bpf_x86_native_lab.c:105–328`
      and descriptor branch :411–424 cannot be selected on the sole kernel
      that provides linux/bpf_native.h. They are obsolete compatibility source,
      not runtime overhead. Keep the active direct-native measurement path.
    - Consolidate the redundant frame-mask machinery and duplicate saves in item 1.
      Maintaining a mask wire field that the actual JIT ignores earns no size.
    - Replace redundant known-map ARRAY→LPM runtime selection by one load-time
      choice; retain actual unknown-map behavior. Avoid duplicating an entire
      universal helper implementation in every program without a measured win.
    - Fold actual immutable configuration before helper emission, so cold
      optional branches do not drag unused generic probe routines into sys_exit.
    - `native_loader.cpp:3116–3152` builds update-site metadata in source BPF
      order; `x86.rs:1562–1564` consumes it by native emission ordinal.
      `main.rs:161–169` carries no native map identity for that update site.
      This is a correctness risk when independent compilers reorder calls,
      especially if an ARRAY update shape is applied to another map. It is not
      demonstrated as the current Cilium bug. Reuse proven native map identity
      instead of another positional metadata scheme or added runtime check.
    - `direct-native/bpf_x86_native_lab.c:546`, :592 and :634 re-arm the whole
      accumulated image after chunk/relocation/site writes. The prefix is
      repeatedly allocated/copied in :338–408: quadratic upload copying for
      many 128-byte chunks. This affects load time and source complexity,
      not per-call speed after installation.

The highest-value next source changes are leaner consistent frame saving, direct
map-specific update/delete calls, and actual frozen-value LTO. Current data
provide no isolated per-piece speedup, no half-size result, no proven tracing
double-execution cause and no confirmed Cilium packet fix. Those remain open. The cb access displacement above is confirmed independently of that packet attribution.
