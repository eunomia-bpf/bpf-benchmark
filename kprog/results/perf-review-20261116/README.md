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
   `kernel/bpf/helpers.c:59` contains an RCU warning check in source
   and an indirect `map->ops->map_update_elem` call (lines 62–63). The warning
   is compiled away in the sole kernel: see the machine-code refinement below.

   The eBPF side already removes this dispatch for a known map:
   `kernel/bpf/verifier.c:23944` patches directly to `ops->map_update_elem`.
   Delete operations similarly patch to map-specific operations at line 23947,
   while the native generic helper resolution at `x86.rs:1598` has no matching
   delete specialization. This is a concrete way native can lose despite a
   faster lookup. Bind the existing proven native map identity to the actual
   map operation at link time, retaining that operation's semantics; no new
   wrapper, selector or per-call validation is needed.

   Existing source support makes this a smaller implementation than a new
   map-type/function-name resolver. The direct module's
   `bpf_x86_native_lab.c:754–775` gets the map by FD and returns its actual
   ops->map_update_elem. Lines 801–804 route the FD request, and :880–881
   publish the map_update_elem file. The stock-path module has the same
   operation in `kprog_stock.c:197–218`, :244–247 and :296. These are source
   capabilities; the current image's endpoint behavior needs its functional
   check when implementation resumes.

   Loader `src/native_loader.cpp:435–480` already has the common FD-query
   reader, with map-pointer and direct-value callers at :483–492. It can
   consume the existing update query using the map FD established by the
   original-source binding. Thread the result through the existing map/link
   facts and select it by actual native argument provenance. Extend the same
   module query machinery for delete. This avoids another symbol catalogue
   and the source/native ordinal pairing identified above. The existing
   stub map-reference array at :1152–1177 and registered map bindings at
   :4071 keep their lifetime role; querying a function address is a load-time
   operation, separate from those references and from each measured call.

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

   Retained fixed-size calls make one part of that overhead concrete.
   The native copy loop at `x86_probe_read.rs:89–108` handles u64 chunks,
   then individual bytes. The sole kernel's `mm/maccess.c:39–46` handles
   u64, u32, u16 and u8 chunks; its configuration enables efficient unaligned
   access (`build-x86/.config:842`). Successful kernel reads therefore have
   the following source-load counts, with a native fault-status branch after
   each load:

   | Requested bytes | Native loads | Kernel loads |
   |---|---|---|
   | 2 | 2 byte loads | 1 u16 load |
   | 4 | 4 byte loads | 1 u32 load |
   | 6 | 6 byte loads | 1 u32 + 1 u16 load |
   | 12 | 1 u64 + 4 byte loads | 1 u64 + 1 u32 load |

   This occurs in retained application code, beyond a synthetic shape.
   Replay 27 tcp_v4_connect_ret has size=2 calls at blob +0x99/+0xac and
   size=4 calls at +0x131/+0x225, all targeting the general routine +0x2d6;
   its byte-load/status loop is at +0x34d. Replay 21 sched_switch has size=4
   calls including +0x7c/+0xf8/+0x153/+0x374 into +0x3b6, with its byte loop
   at +0x42d. These are static retained sites, with dynamic branch frequency
   still to measure. `small-probe-reads.json` records exact call bytes, target
   offsets and artifact hashes.

   Existing known-size facts can lower a two/four-byte read to one recoverable
   operation, matching the kernel's width while retaining policy, fault
   nesting and full-destination clearing on failure. General residual copying
   can likewise use the kernel's u32/u16 widths. String reads have their own
   NUL semantics and remain a separate case. The installed-byte/per-call trade
   needs measurement: sched_switch contributes only 0.94% of baseline BCC
   time in item 2, while sys_exit's retained reads are an eight-byte pointer
   and a sixteen-byte string. This candidate addresses a concrete cost, with
   the dominant sys_enter/sys_exit map/configuration work still pending.

6. **LTO pieces: what the code buys, and what is actually measured.**

   | Piece | Source effect | Retained byte attribution / measured limit |
   |---|---|---|
   | Typed ARRAY/per-CPU ARRAY | Removes a generic helper dispatch; emits key test/address arithmetic (`x86.rs:3994`) | Native parity with optimizations eBPF already has; no isolated current gain measured. |
   | Runtime ARRAY + LPM | Replaces generic calls by the dispatch chain above | OTel sampling entry 67 + 330 appended B; no isolated current per-call gain. |
   | Hash | Shipped image contains a 2444-B custom routine in each participating program | BCC sys_exit 3465-B payload includes 2444 hash + 490 reads + 531 rest. Source f45bb2485 removes the custom routine in favor of the existing shared kernel raw lookup; unshipped, timing effect unknown. |
   | Probe reads | Direct recoverable loads, but preserves policy/nesting/zeroing and local call boundary | 490 B in sys_exit, 255 B in OTel sampling entry; no isolated current gain. |
   | Clock | `x86.rs:23` calls the same fast monotonic implementation directly | Kernel helper itself returns it (`kernel/bpf/helpers.c:178–181`). Removes wrapper linkage, not clock-source/seqlock work. |
   | Tail calls | Machine-code dispatch avoiding the nonfunctional C helper stub | Required semantics; uses the fixed-four convention in item 1; no tail-pop mismatch demonstrated. |
   | CPU/current-task helpers | `x86.rs:1500` already calls `probe_read::percpu` before generic resolution | GS-relative CPU-ID/current-task loads exist since 3880cda8f2; applicability depends on actual per-CPU/address facts. The previous claim that no native rewrite existed was wrong; see item 14. |
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
   | Generic map wrapper operation dispatch | Per helper | The source RCU warning is absent in the sole compiled kernel. Bind the proven map operation directly as the stock verifier does. |
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

   Two adjacent virtual-field differences belong in the same context fix.
   `lib/overloadable_skb.h:21–24` clears tc_classid only under __bpf__.
   Kernel `net/core/filter.c:9888–9901` translates that field to the 16-bit
   qdisc prefix at skb+46. Native currently clears it accidentally through its
   misplaced cb[1] store. After correcting cb to +48, that accidental clear
   disappears: the intended tc_classid write must also be represented explicitly.
   This is source parity, not a new validation check.

   Native `ctx/skb.h:143–146` also substitutes ctx->len for ctx->wire_len.
   Kernel `net/core/filter.c:10087–10095` instead reads qdisc_skb_cb.pkt_len,
   at skb+40. These are distinct fields, so len is not a general semantic
   replacement. `lib/edt.h:93` and `lib/token_bucket.h:46–47` consume wire_len.
   This review has not established that these branches execute in the benchmark
   or that the two lengths differ for its packets; it is a class-level context
   correctness gap, not a measured explanation for the current throughput.

   Conversely, `ctx/skb.h:180–188` checks dev for NULL when obtaining ifindex.
   The eBPF conversion at `net/core/filter.c:9797–9804` performs the same
   check. It is not an extra native-only guard to remove. Native data_end at
   `ctx/skb.h:80–83` recomputes data+(len-data_len), whereas the eBPF conversion
   at `net/core/filter.c:9917–9924` reads the pointer precomputed by
   `include/linux/filter.h:897–903`. Choosing the same already-maintained
   virtual view can avoid extra field loads/arithmetic; this is a source cost,
   with no isolated per-call gain claimed.

   Two more field semantics belong to that public-context translation.
   Native `include/linux/bpf.h:6093` makes queue_mapping a u16, while the
   public declaration at :6163 is u32. A native assignment therefore truncates
   its value before a later pass can recover it. The sole kernel's
   `filter.c:9835–9845` instead preserves the old mapping for values at least
   65535. For an existing mapping of 7, assigning 65536 leaves 7 on that kernel
   path but writes 0 through the native u16 field. This is a source-derived
   boundary example, with benchmark occurrence still open. Cilium's
   `lib/edt.h:44–49` contains the assignment under ENABLE_BANDWIDTH_MANAGER.
   Existing packet-physical-layout.c:29 already records store_max_exclusive
   for this field, and socket-context-lower.cpp:176–181 applies that kernel
   store behavior before truncation. Reuse those public-width/semantic facts.

   Timestamp access also carries program-specific semantics. With the sole
   kernel's CONFIG_NET_XGRESS=y, `filter.c:9687–9711` returns zero for an
   ingress delivery timestamp when the program has not read tstamp_type.
   Writes at :9722–9745 then clear the timestamp-type bits at ingress for
   such a program. Native's physical tstamp field at header :6086 performs
   a plain read/store. Cilium EDT reads it at :90 and writes it at :107;
   reachability and actual timestamp state in the benchmark still need
   evidence. These observations extend the context class beyond offset
   generation: retain public operand width and the original program's field
   access semantics while binding physical fields from the sole kernel.
   They are source parity cases, with current throughput attribution open.

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

   Compile-time feature flags form a separate binding boundary. In this
   native build, `-DENABLE_HOST_ROUTING=1` and `-DENABLE_ROUTING=1` are fixed
   in `vendor/bpf/Makefile:81–104`. `lib/config.h:6–14` implements is_defined
   through preprocessor expansion, so bpf_lxc.c:1361's host-routing condition
   is constant true. It is not a CONFIG() variable in .rodata.config, and
   binding live DATASEC values cannot change it. Upstream agent config emits
   ENABLE_HOST_ROUTING conditionally (`pkg/datapath/linux/config/config.go:374`)
   and ENABLE_ROUTING per endpoint (:674). This identifies a real source of
   potentially different compiled paths and excess code separate from the
   global-value binder. It does not establish which macros were present in
   the actual eBPF arm; inspect that arm's retained generated headers/objects
   before calling a particular feature different. Correcting cb or binding
   all global values alone does not settle this compile-time parity question.

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

11. **Machine-code refinement of map dispatch, and the existing path to binding.**

    The sole kernel's System.map identifies bpf_map_update_elem at
    ffffffff814b8a30 and bpf_map_delete_elem at ffffffff814b8a60. The retained
    static disassembly in `kernel-map-wrapper-disassembly.txt` shows each as
    an __fentry__ site, two loads (map->ops at +0x20, then operation +0x68
    or +0x70), and a jump to __x86_indirect_thunk_rax at ffffffff82012c80.
    The source RCU warning is absent from both compiled wrappers; deleting its
    source cannot improve their per-call cost in this kernel. DEBUG_LOCK_ALLOC
    and PROVE_LOCKING are disabled. The thunk contains a call, return-address
    store and return-thunk jump in this linked image. Runtime alternatives and
    ftrace patching are not captured here, so these static bytes do not prove
    an exact live mitigation cost or an active __fentry__ call.

    The map-operation dispatch is present regardless of the source warning.
    Stock verifier.c:23944–23949 already binds update/delete directly to the
    actual map's operations. Select those same operations; HASH, LRU_HASH,
    PERCPU_HASH and LRU_PERCPU_HASH do not share one update function
    (`kernel/bpf/hashtab.c:2351`, :2373, :2554 and :2576). Their deletion
    operations also differ for LRU versus ordinary hash maps. Hard-coding one
    generic hash function would lose the actual map semantics.

    Native-side identity machinery already exists: x86.rs:1154 calls
    `x86_known_maps.rs:7–72`, whose result maps each native CALL's local offset
    to the proven RDI map symbol (:38–42). It recognizes the actual map
    relocation and register moves, clearing lost facts at control-flow
    boundaries, clobbers and unknown memory loads. Lookup selection already
    consumes that identity in x86.rs:106–129. Update at :1562 instead selects
    by emission ordinal, and delete falls through to generic resolution.
    Reuse the existing per-native-call fact for both; a genuinely dynamic
    map can still require dynamic operation dispatch. No second ordinal
    metadata scheme or runtime map-identity check is needed.

12. **The register-mask field describes removed saves, not all registers used.**

    `x86.rs:2849` starts the strip set from compiler pushes. At :2987–3003
    the mask is built from that stripped/renamed set. A frame-pointer prologue
    exits early at :2801–2806 to preserve its frame and therefore yields no
    transferred saves. A request to preserve ABI similarly exits at :2836.
    Kernel-mode proof input also preserves the already-extracted ABI at :1140.
    This explains why mask zero can coexist with five compiler callee saves:
    it does not mean P uses or clobbers no callee-saved registers.

    The fixed kernel four-register push/pop pair itself is eight stack
    operations and 14 bytes (`bpf_jit_comp.c:357–392`), before the native-C
    frame. Reducing these duplicate outer saves is a static saving candidate,
    with no per-call measurement yet. Preserve the compiler's native frame
    and its R12/RBP needs unless the existing stripping transformation has
    actually transferred them; changing only the mask interpretation is not
    sufficient. The tail path's native cleanup, outer-frame pops and counter
    slots must follow the resulting frame together. Partial outer masks also
    change stack movement by eight-byte increments: preserve the compiler's
    existing stack alignment and offsets. The old comment at x86.rs:2982–2986
    assumes one save set replaces the other, whereas today's fixed-four
    wrapper ignores that metadata. This is a simplification opportunity, not
    evidence of the withdrawn current tail-pop bug.

    One more source fact belongs to this frame work: the sole kernel's
    `arch/x86/Makefile:38–46` defines an 8-byte stack convention for x86-64
    (clang -mstack-alignment=8, GCC -mpreferred-stack-boundary=3), applied at
    :162. The shared native producer flags in `vendor/bpf/Makefile:46–56`
    specify general-register-only/no-red-zone but do not set that stack
    convention. Linker wrappers such as x86.rs:1088–1095 and the nested-call
    ARRAY routine in x86_runtime_array.rs:34–40 assume a SysV alignment when
    adding eight-byte pads. Keeping the native compiler's saved registers
    does not by itself prove alignment at its kernel entry boundary.

    No live stack residue or alignment fault was captured in this review.
    Treat this as a convention to reconcile when consolidating the frame,
    using one producer setting across apps and the same convention in load-time
    code generation. Do not blindly remove/add one pad from a push count or
    introduce a runtime alignment check. Any reduction in compiler stack
    padding or installed bytes remains to be measured.

13. **Phase-1 CEL stock rejection loses the pointer carried in an index register.**

    This finding follows the actual terminal verifier log, not a new guest:
    `/workspaces/kprog-raw/perf/20261116-generator-indirect-spills/stock-map-binding/verifier.log`.
    B generated successfully; production private-map relocation succeeded.
    Instructions 3/5 load the arbitrary numeric entry-stack base from the private
    input map, then :23 subtracts 56. Instruction :35 dereferences that scalar,
    giving `R3 invalid mem access 'scalar'`. The log already proves the other
    offset zero at :16–19, so lack of a bound on that particular offset is not
    the first failure.

    The exact retained native proof is
    `/workspaces/kprog-raw/perf/20261116-code-pointer-check-retry1/cel.proof.o`.
    At +0x4f it forms RSI = RSP+0x10 after allocating 0x48 bytes: this is the
    stack array at entry-SP minus 56. Its actual upstream CEL body at +0x6a
    compares `QWORD PTR [rcx+rsi*1]` with 42. RCX is the scalar offset read from
    the separate offset array and masked with 2047 (+0x5f/+0x62).
    The archived generated B source in
    `20261116-generator-indirect-spills/stock/b-build.tar.gz` preserves this
    operand as CMP_MEM_IMM with base X86_RCX and index X86_RSI, scale zero.
    The defined-code spill target at +0x54 is now resolved; this rejection is
    downstream of that earlier generator fix.

    The source chain is explicit:

    - `x86_sim_local_bpf.h:1800–1805` gives the RSI LEA result STACK tag and
      an actual private-arena pointer.
    - `:670–683` computes memory displacement via X86_SIM_L_READ_REG(index).
      For STACK-tagged RSI, `:532–556` converts the pointer to numeric native
      entry-base bits. This is appropriate for observing numeric register
      bits, but discards the pointer needed for dereference.
    - `:1361–1409` forms the memory address and classifies it using only the
      encoded base register, RCX. `:1423–1435` also bases fault routing on
      that same scalar base. The resulting successful arm is a scalar memory
      load, exactly as the stock verifier log shows.
    - The generator's `parse_mem_terms` at
      `micro-prog/generate_micro_sim_proofs.py:416–449` retains the actual
      base/index arrangement; it does not establish a pointer-first operand.

    LEA already has the missing commutative, unscaled pointer handling at
    `x86_sim_local_bpf.h:1811–1817`: scalar base plus memory-tagged index with
    scale one preserves the index pointer and adds the scalar displacement.
    Memory read/write and recovery routing need the same effective-address
    provenance, using the existing operand/tag facts. Simply swapping all
    decoded operands would break scaled indices, mixed pointer arithmetic,
    address-width and segment cases. Do not make the native stack-base input
    constant, guess the pointer's bits, add a new runtime check or bypass the
    stock rejection.

    This is a concrete next phase-1 class, with no stock-acceptance or full
    application claim. Coordinator cleanup still owns all source edits.
    FORMAL owns shared-I proof coordination; the existing LEA and memory
    handlers must keep the same native address semantics when this is fixed.

14. **Correction: native CPU-ID/current-task inlining already exists.**

    The original item-6 table incorrectly stopped at generic helper resolution
    in x86.rs:1598. The earlier call at :1500 invokes
    `x86_probe_read.rs:178–193` before that path. For bpf_get_smp_processor_id
    it uses the plan's __native_x86_cpu_number; for bpf_get_current_task it
    resolves current_task relative to an available probe-read helper anchor
    and the actual same-kernel helper address. A representable GS disp32 emits
    a direct GS-relative load, with 64-bit width for the task pointer. These
    cases have existed since 3880cda8f2 (2026-11-14), not a cleanup addition.
    The loader supplies cpu_number and this_cpu_off from kallsyms at
    `native_loader_link_schema.hpp:95–103`.

    Missing layout/helper anchors or an unrepresentable offset keep the helper
    call; this review has not measured the frequency of those cases. Neither
    bpf_get_current_pid_tgid nor bpf_current_task_under_cgroup is one of those
    two rewrites. Their retained calls in BCC sys_enter/sys_exit therefore do
    not show that CPU-ID/current-task inlining is absent. The installed bytes
    and isolated gain of the existing rewrite remain unmeasured. Do not build
    another CPU/task inliner based on the withdrawn claim.

    A precise extension of that existing implementation is the BTF variant.
    The sole kernel's `kernel/trace/bpf_trace.c:755–758` returns current for
    bpf_get_current_task; :766–769 returns the same value for
    bpf_get_current_task_btf. Their verifier return types differ at :763
    and :774–775. Yet `x86_probe_read.rs:180` recognizes only the first name,
    so helper158 falls through to the ordinary call at `x86.rs:1598–1609`.
    The retained Tracee proof in replay409 contains a call relocation to
    bpf_get_current_task_btf at section offset +0x195, in
    trace_security_inode_symlink. This is proof-stage application evidence;
    that entry's inventory has a proof object, with kernel replay evidence
    still pending. Reuse the existing GS-load emission for the same native
    value while retaining helper158's identity and BTF pointer contract in
    proof/simulator handling. A global helper-ID substitution would lose
    that distinction.

    BCC's hot pid/tgid helper is a separate opportunity. Retained replay24
    sys_enter calls it first, at proof/blob +0x5; replay25 sys_exit calls it
    at proof +0x33 and blob +0x39 after the cgroup filter. Both blobs retain
    actual helper relocations. `kernel/bpf/helpers.c:225–232` loads current,
    handles the null case, then combines task->tgid and task->pid. This is
    more than a GS pointer load. Reusing sole-kernel BTF offsets in trusted
    IR lowering could expose those field loads to ordinary optimization.
    In particular, syscount.bpf.c:77–103 uses the upper half for filter_pid
    and count_by_process, so actual immutable configuration folding can make
    that half unused. Folding the caller alone still leaves an opaque helper
    computing both halves. Preserve the kernel helper's result/error behavior
    and actual configuration; isolated per-call and installed-byte effects
    remain to measure. This complements map-ops binding in the dominant
    pair, with its priority unchanged.

    The simulator's TC metadata constant is also already the translated +48:
    `x86_sim.h:150–153` uses X86_SKB_CB_OFF=0x30, unlike the producer's native
    struct cb at +40. Its data/data_end constants (+208/+80) agree with the
    sole kernel. This does not fix the native producer. The context bug in
    item 8 belongs to that producer boundary; simply changing the simulator
    constant to the raw sk_buff.cb offset would repeat it.

15. **Registered direct-native fallback does not preserve native tail reachability.**

    This is separate from the withdrawn callee-mask/pop claim in item 1.
    The timing path's `native_loader.cpp:1057–1150` takes tail_call_reachable
    and puts a verifier-visible tail-call site into the stub when needed.
    Source helper scan at :3085 records that fact in companion.has_tail_call;
    the ordinary direct loader passes it to load_stub_prog at :3486.

    In contrast, `load_trusted_worker` at :3995–3999 uses just MOV r0,0 and
    EXIT when trusted_direct_native is selected after a B failure. It submits
    those two instructions at :4086–4088 with the native image attached, but
    does not use companion.has_tail_call to describe P's tail frame. Reading
    the original program at :3973 can populate the companion fact, yet that
    does not transfer it into the newly loaded program's aux structure.

    Kernel `kernel/bpf/core.c:69–76` binds only the native image pointer.
    `kernel/bpf/verifier.c:3692–3696` marks tail sites found in the submitted
    B instructions, and :6864–6865 transfers that reachability to prog->aux.
    The two-instruction fallback has no such site. Native JIT
    `bpf_jit_comp.c:3806–3808` passes prog->aux->tail_call_reachable to
    emit_prologue; :557–558 allocates the two counter slots only when true.
    It neither derives that fact from native relocations nor overrides it for
    registered fallback. `x86.rs:3855–3877` still emits the native counter
    access at BPF RBP-16 and pops its two slots on a successful tail call.
    With that fallback stub, the frame does not contain the expected slots.

    Thus a native P with tail calls routed through registered fallback has a
    source-level frame-contract gap even though the ordinary timing stub
    correctly retains reachability. No new guest was run to trigger it, and
    it is not evidence that the recorded timing Cilium run used this route.
    The existing native tail-count relocation kind 10 already identifies
    these counter accesses; use actual P facts for the installed frame rather
    than inferring them solely from the different B/stub. Keep frame creation,
    tail cleanup and target entry consistent without an added per-call check
    or another optional compatibility path. This belongs with the pending
    frame/phase-1 correction after coordinator cleanup.

    Source fix after cleanup: 3821bf1dc makes the registered fallback and
    ordinary native entry share native_stub_program. Linked counter
    relocations supply tail reachability as well as the original source fact.
    The marker map remains live through program loading. Three host stream
    cases, including FD zero, and the loader rebuild pass; receipt is
    cilium-cb-frame-20261116. Kernel/image publication and guest tail-frame
    checks remain pending alongside item 1.

16. **Private-input pruning runs before later dead-store elimination exposes waste.**

    There is already a narrowly scoped removal pass; adding a second general
    volatile-load rule would be unnecessary. `packet_bounds_ir.cpp:250–266`
    removes unused, non-atomic, volatile i64 loads from the specific private
    kprog_unspecified_input extern. It preserves live choices and other memory.
    Main invokes it once at :323, before the later backend compilation in
    `trusted_specializer.py:94–100` and whole-word spill lowering.

    The shared I deliberately makes released stack bytes arbitrary:
    `x86_sim_local_bpf.h:776–790` draws private choices into each released
    word/byte. The stock input header :20 turns each draw into a volatile map
    load, which normal LLVM dead-store elimination cannot itself remove.
    In the retained CEL build, the return's ADD RSP,72 releases nine words.
    Later optimization removes those dead private stores, while nine now-dead
    volatile loads remain in the final B.

    The exact retained verifier listing shows instruction39/40 loading the
    private map-value address into R1, followed by nine consecutive i64 loads
    at41–49 from that same address. Their destination registers are overwritten
    without use; none affects the final result at50–54. In archived
    trusted_x86.bpf.before.mir, the corresponding nine volatile LLVM loads
    remain on the return edge even though their stores have disappeared.
    This is a static nine-load tail plus a two-slot address load, 11 of the
    55 B instruction slots (88 of440 executable bytes). It is not a measured
    post-fix object size or verifier-time reduction.

    Reuse the existing private-input pruner after the optimization that makes
    those reads dead. Do not strip volatile from arbitrary context/map reads,
    coalesce live independent choices, replace the entry stack base by zero,
    or remove released-stack semantics from I. This needs compiler ordering
    work after cleanup, not another runtime check or a new proof gate.
    It affects B generation/verification cost and byte size; the native P
    installed for timing does not execute these B instructions.

17. **Typed ARRAY update emitter truncates flags and changes error precedence.**

    `native_loader.cpp:3126–3150` selects the ARRAY/PERCPU_ARRAY update emitter
    based on map type and value size1/2/4/8, without restricting the actual
    flags argument. `x86.rs:4194–4200` loads the key, checks bounds, then uses
    CMP ECX,1 and CMP ECX,2. The helper's flags argument is u64 in RCX; those
    comparisons ignore its upper32 bits. The success body copies the value.

    The sole kernel operation in `kernel/bpf/arraymap.c:363–399` instead
    validates `(map_flags & ~BPF_F_LOCK) > BPF_EXIST` at :370 before key bounds
    at :374, then BPF_NOEXIST at :378 and lock-field semantics at :382.
    Two source-derived counterexamples require no new test or check:

    | Inputs | Kernel operation | Current native inline emitter |
    |---|---|---|
    | Valid key, flags=0x100000000 | -EINVAL, no write | ECX is zero; copies value and returns0 |
    | Out-of-range key, flags=3 | -EINVAL | Bounds exit first: -E2BIG |

    Even in-range flags=BPF_NOEXIST|BPF_F_LOCK (5) returns -EEXIST in the
    kernel before lock-field validation; the emitter returns -EINVAL.
    This is not just an extra branch or code-size concern: it changes return
    values, and the high-flags case changes map contents. The frozen benchmark
    may use constant zero flags; this review has not observed one of these
    inputs in its actual calls and does not attribute a measured ratio to it.

    The pending map-operation binding work can remove this custom update
    implementation and use the already-selected map's actual update operation.
    That preserves the existing kernel checks and removes duplicate userspace
    semantic logic without adding a new native runtime check. If retaining a
    specialized copy, restrict it by actual proven call facts and retain all
    relevant semantics; value size alone does not prove flags or map-record
    behavior. Per-call and installed-byte effects remain unmeasured.

18. **Retained Cilium baseline headers demonstrate an audit-policy difference.**

    The latest stats round's exact generated headers have not been compared,
    but historical baseline artifacts are available and should not be ignored.
    The capture manifest at
    `/workspaces/kprog-raw/perf/20261113-cilium-context-runtime-retry1/baseline-state/capture.json`
    identifies state/globals/node_config.h and the template ep_config.h
    archived beside its bpf_lxc.o. The template endpoint header defines
    ENABLE_ROUTING at line3 and POLICY_AUDIT_MODE at line9. The node header
    defines ENABLE_NODEPORT at line35 and contains no ENABLE_HOST_ROUTING,
    ENABLE_HOST_FIREWALL or ENABLE_DSR definitions.

    The current native maximum-feature recipe explicitly enables
    HOST_ROUTING, HOST_FIREWALL and DSR (`vendor/bpf/Makefile:81–90`), and
    neither it nor the checked-in dummy ep_config.h defines POLICY_AUDIT_MODE.
    The current frozen runner explicitly requests --policy-audit-mode=true
    (`runner/libs/app_runners/cilium.py:313`). This gives a concrete semantic
    reason the native producer must consume the agent's actual headers:
    `lib/policy.h:400–405` and :461–466 convert a negative policy verdict
    into CTX_ACT_OK with audited=1 only in audit mode. With that macro absent,
    the same denied-policy result stays negative. The actual benchmark packet
    may already be allowed; this does not prove its recorded route cause.

    The old capture also contradicts treating NODEPORT as universally absent:
    it is explicitly1 there. It is a November13 capture, not proof of the
    November16 round's generated flags. Do not remove NODEPORT merely from an
    inferred generic configuration or apply the old headers as current ones.
    Derive current flags from the actual agent build, retaining this historical
    evidence and the current runner intent. No source/benchmark change or
    guest was needed to locate these facts.

19. **Process-wide map discovery uses descriptor order as object identity.**

    The initial companion maps are scoped correctly to the original program:
    `native_loader.cpp:3022–3037` reads that program's map IDs and their
    metadata. But alias resolution at :2615 and :2658 can import process-wide
    maps when a symbol is not yet bound. `collect_open_process_maps:2000–2042`
    scans /proc/self/fd and queries every open map matching its predicate.

    Two explicit ambiguity paths choose the largest FD:
    `find_open_process_map_by_name:2075–2080` and
    `find_open_process_manifest_native_symbol_map:2470–2475`.
    Their object_scoped flag does not establish which ELF/program owns the
    matching map; it selects max(fd). For two same-shaped matching maps A/B,
    A at10 and B at11 choose B. Duplicating A to20 switches selection to A
    without changing either map's owner or the program being linked. This is
    a source-derived identity counterexample, not a new runtime experiment.

    Data-map lookup has a similar expansion of scope: find_array_data_map at
    :2528–2545 first searches companion maps, then imports a matching open
    process data map. No source/ELF identity is established by a section suffix
    and value size. Name/shape can narrow a known object binding; it cannot
    manufacture ownership from a shared loader process.

    The original-source binder already provides stronger facts:
    `native_loader_source_maps.hpp:9–11` and :119–127 relate original ELF
    symbol/slot correspondence to intercepted final BPF map-FD instructions.
    :154 onward binds those actual map capabilities, and native_loader.cpp:4205
    invokes it before data-symbol binding when source_bpf_object is present.
    Reuse those facts and the program's actual IDs; retire the process-wide
    highest-FD heuristic instead of adding another runtime ownership check.
    Maps needed only by a native optional branch also need the actual object
    binding/configuration, not an unrelated currently open map.

    The scans are load-time work, not per-invocation branches. Repeating them
    for unresolved symbols traverses process descriptors and re-queries matching
    maps; it can increase load cost and code complexity. No elapsed cost,
    current timed misbinding or packet-path cause has been measured here.

20. **Finite helper-ID dispatch bypasses helper-specific leaf lowering.**

    The compiler can prove a finite set of helper IDs at an indirect call.
    `x86.rs:1422–1434` handles that set before the singleton path, emits the
    dispatcher, and continues. Its leaves at :3738–3741 all resolve a normal
    runtime function target and emit E8/E9. That does not use the singleton
    bpf_tail_call lowering at :1460–1497 or CPU/task GS lowering at :1500.
    The dispatcher's tail parameter means a native sibling JMP, not a BPF
    program-array tail transition.

    This matters functionally for a finite set containing helper12:
    frame planning at :1125–1126 already recognizes bpf_tail_call in numeric
    alternatives, but emission still asks runtime_call_target for a C function.
    The sole kernel's bpf_tail_call_proto has func=BPF_PTR_POISON, explicitly
    unused (`kernel/bpf/core.c:3083–3092`); real tail calls are verifier/JIT
    control flow. A normal helper function target cannot implement its map
    lookup, counter and frame transition. With no such address in the plan,
    this path fails linking; a supplied ordinary address would still not be
    the existing BPF tail lowering. This is a source-level coverage gap, not
    a newly observed application failure or a fresh runtime test.

    CPU-ID/current-task alternatives also miss their existing GS leaf rewrite,
    whereas singleton calls can inline it. Some other optimizations still
    apply: runtime_call_target handles clocks, and the later shared helper
    passes can rewrite emitted lookup/probe relocations. Therefore this is
    not a claim that finite dispatch disables all LTO.

    Reuse the same proven helper-specific lowering for a dispatch leaf rather
    than a second generic-only implementation. Preserve the actual finite
    selector and each leaf's success/failure/return behavior; no speculative
    helper target or extra validation is needed. The number of such sites in
    the current apps and any per-call or installed-byte effect remain unknown.

21. **OTel context LTO reoptimizes and code-generates unrelated entry bodies per symbol.**

    `link_embedded_ir.cpp:23–30` preserves every function with a program section
    by making it externally linked before combining the OTel frontend modules.
    That is needed to retain selectable program entries in P. At load time,
    however, `native_loader_context_lto.hpp:18` includes the selected symbol
    in the cache key, and :39–40 invokes the compiler with that symbol.

    `perf_context_lto.cpp:72–79` keeps the selected entry external but does not
    internalize/drop other program entries. It runs the whole-module O3
    pipeline at :96, converts the selected PERF_EVENT entry, runs whole-module
    O3 again at :147, and emits the whole module at :152. Other external
    program bodies remain roots. Therefore distinct cold-cache symbol loads
    redo optimization and native object emission for unrelated entries from
    the same combined P. The later native-link selected-entry extraction
    does not undo that compilation work already spent.

    Use the selected entry's existing LLVM/global-reference closure before
    these expensive stages, retaining its real callees, address-taken code and
    reachable data. Standard LLVM internalization/global elimination can
    express this without another source-language parser, private source tree,
    per-application compiler or new runtime check. Merely deleting all other
    named functions would break referenced helpers/tables, and emitting a
    different context conversion for an unrelated program type is not valid.

    This is source-level repeated load-time work, not an explanation of native
    per-call0.946x/1.0x. Cold-cache compilation time/memory and eliminated output
    bytes have not been measured for this change. The installed P linker already
    selects a reachable entry, so a smaller temporary ELF does not itself
    establish the operator's installed half-size target or any per-call gain.

    The existing launcher already addresses process-boundary cost:
    `src/native_loader_subprocess.hpp:27–59` uses posix_spawn and synchronously
    reaps the child with waitpid, retrying interrupted waits. It removes the
    preload variable from the child environment at :14–23. This keeps the
    compiler/linker outside the intercepted application's shim and avoids
    ordinary fork-based duplication of its address space. The context-LTO
    caller at native_loader_context_lto.hpp:46 waits for this function before
    publishing the result at :55. Thus repeated module optimization and
    emission remain the concrete source cost in this item. A compiler from
    that invocation has completed when the launcher returns successfully;
    overlapping independent loads are a separate question. Retain this
    existing launch mechanism while trimming actual LLVM work, with load-time
    measurements distinct from native per-call timing.

22. **Local memory call redirection deletes observable function-address loads.**

    For an ordinary helper GOT load, `x86.rs:1267–1271` materializes the
    actual resolved helper address. For memcpy/memset, :1261–1275 instead
    marks the relocation handled and continues without emitting the load or
    any replacement for its destination register. There is no use restriction
    at that decision. This happens in proof mode as well as kernel mode.

    `x86_helper_provenance.rs:27–33` recognizes the original GOT value as a
    function symbol, and `x86.rs:1444–1453` can later redirect its indirect call
    to a linker-owned routine. Call-target provenance is not proof that the
    earlier pointer value is unobserved. A source-derived instruction sequence
    makes the difference explicit: initialize RAX to zero, load memcpy@GOT
    into RAX, test RAX and branch on zero, then call RAX on the nonzero path.
    Original linking supplies a nonzero function address; dropping the load
    leaves zero and takes the other branch, despite the call itself having a
    valid redirect. A store/comparison of the pointer has the same problem.
    No actual current app occurrence or fresh execution is claimed here.

    Preserve a consistent linker-bound address when the value is observed,
    using existing image-address relocation machinery and the canonical
    memory-function binding. Specialized call bodies can still be direct
    targets, but dropping a value definition requires its existing use facts,
    not merely recognizing the callee name. Do not add a runtime pointer check
    or another compatibility switch.

    Separately, the memory routines remain calls even for constant small
    sizes: :1447 emits an E8 slot, and x86_memory.rs:94–103 unrolls constant
    lengths up to512 before a RET. The key at :6–10 distinguishes function,
    constant length and zero-fill status; :1676–1686 deduplicates only that
    complete routine key within one program. This avoids a universal size
    dispatcher but retains CALL/RET for tiny copies and can grow code across
    many lengths/programs. Inline small fixed operations or share larger
    routines only with actual per-call/installed-byte evidence. This review
    supplies no isolated gain and does not assume byte-at-a-time copying:
    the dynamic implementation already uses32-byte then8-byte chunks.

23. **Shared hash lookup follows the JIT's kernel target and postprocessing.**

    Source crosswalk, 2026-11-16: the loader currently lives at
    `kprog/libnativeloader/src/native_loader.cpp` during coordinator cleanup.
    Its :1600–1607 resolves the existing kernel __htab_map_lookup_elem.
    The shape cases and caller-side operations correspond as follows:

    | Map shape | Native source | Sole kernel's JIT lookup generation |
    |---|---|---|
    | HASH | Loader :2757–2762; x86.rs:4047–4049 adds the value offset after a successful raw lookup | hashtab.c:774–786 calls __htab_map_lookup_elem and adds the same key-storage/rounded-key offset |
    | LRU_HASH | Loader :2764–2770; x86.rs:4055–4062 checks and sets the reference byte before adding the value offset | hashtab.c:812–836 emits the raw call, reference-byte read/conditional write and value adjustment |
    | PERCPU_HASH | Loader :2772–2783; x86.rs:4064–4071 loads the stored per-CPU pointer and adds this_cpu_off | hashtab.c:2409–2425 emits the raw call, pointer load and per-CPU conversion |
    | HASH_OF_MAPS | Loader :2790–2795; x86.rs:4051–4053 loads the inner-map pointer from the adjusted value address | hashtab.c:2698–2715 emits the raw call, value adjustment and inner-pointer load |
    | LRU_PERCPU_HASH | Loader :2785–2788 binds the complete htab_lru_percpu_map_lookup_elem | hashtab.c:2441–2450 marks the LRU reference and returns the current CPU's value |

    `x86.rs:4079–4083` guards raw-result postprocessing with the returned
    pointer's null test. Thus the source retains the LRU reference update
    that the earlier May-linker output skipped at Katran's dynamic sites.
    The raw kernel target itself performs hashing, bucket selection and
    collision comparison (`hashtab.c:732–749`) for both paths.

    This supports publishing the existing shared-kernel change f45bb2485:
    it removes the repeated 2444-B custom hash routine while retaining the
    kernel lookup algorithm and map-specific result operations. This is
    source correspondence; the actual timed site's selected map identity,
    installed-byte delta and per-call effect still require the existing
    load facts and post-cleanup measurement. The same-kernel hashing work
    remains in both arms, so the byte reduction alone establishes a size
    improvement candidate, with the speed target still open. Known-map
    update/delete binding and immutable configuration folding remain the
    separate opportunities identified above.

24. **Known complete lookup targets are discarded by the map selector.**

    This extends item 4 with a concrete retained Katran path. Loader
    `src/native_loader.cpp:2785–2788` binds known LRU_PERCPU_HASH to
    htab_lru_percpu_map_lookup_elem, and :2797–2800 binds ARRAY_OF_MAPS to
    array_of_map_lookup_elem. Both use kind=call because the kernel function
    returns the complete value. `x86.rs:114–120` accepts six inline/raw-result
    kinds for a proven map name, then :124–128 substitutes the generic
    bpf_map_lookup_elem target for kind=call. The existing test at :4507–4514
    explicitly encodes this substitution even with an exact map identity.

    Retained replay 114 is Katran balancer_ingress in
    `/workspaces/kprog-raw/perf/20261116-native-corpus-before-publication`.
    Its plan supplies lru_mapping with kind=call and target
    0xffffffff834cb580, the relocated array_of_map_lookup_elem. The original
    proof loads lru_mapping directly into RDI at +0x79a and +0xb1a, followed
    by argument setup and helper calls at +0x7ae/+0xb2e in the same blocks.
    There is a direct named-map fact at each call; these are the outer map
    accesses, separate from the dynamic inner-map sites in P-map-CFG.

    The emitted blob instead contains calls at +0x82c/+0xc81 to +0x2793.
    That routine tests map type ARRAY, then its fallback calls +0x3162 at
    +0x27cc. The second routine tests LPM, then calls the generic helper
    through relocation +0x32a2. The specialized array_of_map_lookup_elem
    target has zero relocation records in that blob. Thus each execution
    of either outer lookup takes two extra local CALL/RET boundaries and
    map-type tests before generic map-ops dispatch. The kernel's own
    ARRAY_OF_MAPS JIT generator already emits direct address arithmetic
    and the inner-pointer load (`arraymap.c:1413–1441`).

    `known-call-bindings.json` preserves the plan rows, blob/proof hashes,
    call offsets and targets. The retained corpus contains seven named
    kind=call rows with specialized targets: Katran's lru_mapping and two
    aliases of Cilium's policystats map in each of three program plans.
    These are seven map rows, with execution frequency still to measure;
    Cilium's exact native argument provenance needs its own site inspection.

    Reuse the complete bound target for an exact native map identity, or
    the existing direct shape emitter where appropriate. That bypasses
    redundant generic dispatch while keeping runtime dispatch for dynamic
    maps. This is a source and retained-machine-code finding. Current-image
    installed bytes and the per-call benefit remain measurement work after
    cleanup; the older replay's offsets identify evidence, not current code
    addresses or workload branch counts.

25. **Helper lowering retains immediately dead helper-ID moves.**

    Two exact instruction pairs in retained Katran replay114 illustrate a
    small emitted-code cost:

    | Blob offset | Retained definition | Immediate replacement instruction |
    |---|---|---|
    | +0x4b | b8 01 00 00 00: mov eax,1 | +0x50: mov eax,[rsi], beginning typed per-CPU ARRAY lookup |
    | +0x801 | b8 08 00 00 00: mov eax,8 | +0x806: mov eax,gs:[cpu_number], the existing CPU-ID lowering |

    Both replacement instructions write the whole RAX value through a
    32-bit destination. The earlier ID is overwritten before any intervening
    value use; MOV also preserves flags. The retained two definitions occupy
    ten bytes and one extra instruction whenever each site executes. They
    are static examples, with workload frequencies and measured timing still
    to establish.

    `x86.rs:1622–1628` keeps ordinary decoded instructions, while :1500–1505
    and :1517–1528 replace the helper call in isolation. Helper provenance
    knows its identity, but emitting the replacement leaves the earlier
    definition intact. Consume such dead definitions as part of the existing
    lowering using the decoder's register-use/write facts and branch targets.
    This is a local opportunity, sized against its implementation cost; the
    operator's half-size requirement still needs the larger changes above.
    Preserve observable address values from item22 and selector values that
    finite helper dispatch actually reads. The proof/simulator helper-ID
    representation has its own uses, so apply native emission cleanup at
    the appropriate stage. Installed-byte and per-call deltas remain to
    measure after cleanup.

26. **The retained OTel frame needs work beyond more u32 spill pairing.**

    The November15 main replay provides a concrete phase-1 storage inventory
    (`20261115-otel-main-spill-replay/result.json`). Its archived pre-PEI MIR
    declares a 408-byte default stack object plus forty eight-byte and twelve
    four-byte spill objects, each aligned to eight. The small objects are
    paired six ways. The report records 693 rewritten accesses: 396 stores
    and 297 loads. Nine save/restore events use one shared scratch slot.
    Compiled perf_event code is 991592 bytes with deepest frame access 784.
    `otel-spill-budget.json` preserves these counts and the input hashes.

    The 408-byte arena plus the forty full-word spill declarations already
    totals 728 bytes of storage in that inventory, before the packed small
    words. This identifies the limitation of working only on the twelve
    small slots. It is a declared-storage accounting observation, not a
    lower bound after arbitrary lifetime analysis, scalar replacement or
    slot reuse. The 784-byte figure is the actual retained compiled depth;
    newer P/context/frontend inputs still need their own generation result.

    Current `whole_word_spills.py:299–303` pairs eligible slots after register
    allocation. Each packed store becomes a full-word read/modify/write
    sequence using scratch registers (:125–158), with live-register saves
    when needed; loads extract a half (:166–172), and entry initialization
    makes the packed words readable (:180–185). This makes private scalar
    storage verifier-friendly, with real code and scratch cost. The current
    scalar-narrowing step (:293) already expands eligibility, so this is a
    request to examine the remaining live storage, preserving that work.

    Reuse the existing LLVM pipeline to shorten temporary lifetimes and
    eliminate dead native-stack/private-input state before register allocation
    (including item16's late pruning opportunity). Identify which remaining
    full-word spills carry pointers versus scalars before changing widths.
    This review establishes the retained storage bottleneck; stock acceptance,
    a smaller generated object and current whole-app completion remain open.

27. **PERF_EVENT context conversion covers direct entry loads, with callee uses still open.**

    `perf_context_lto.cpp:96` runs O3 to expose context reads, then :113–117
    collects LoadInst only from the selected entry F when its underlying
    pointer object equals F's argument zero. The lowering at :131–135 changes
    those loads to use the physical registers/data pointers. Helpers and tail
    calls intentionally keep the physical context (:137), and a second O3
    pipeline runs at :147.

    Inlining is therefore part of the current coverage assumption. Consider
    an external, defined noinline function read_period(p) whose body loads
    p->sample_period, called by the selected entry with its context argument.
    Its ABI/body can survive O3. The entry has the call while the public-field
    load remains in the callee. The collector above visits the entry alone,
    so that callee retains a public-structure offset on a physical kernel
    context. A context memcpy retained as a memory intrinsic also lies outside
    this LoadInst collector. These are source-derived coverage cases, with
    actual current OTel occurrence and execution still to establish. They
    leave the measured unwind counters as their own evidence.

    Extend the existing LLVM context-origin/reference traversal through real
    call arguments and memory operations. Shared callees need their actual
    argument origins distinguished before conversion; blindly rewriting every
    pointer argument would change ordinary-memory calls. Keep physical context
    operands for kernel helpers/tail calls while translating public field
    operations at their actual use. Reuse existing compiler infrastructure for
    this context class, preserving the operator's load-time placement. A new
    per-call context test, copied public context or app-specific compiler is
    unnecessary. Current installed bytes, stock-generation coverage and timing
    effects remain measurement work after cleanup.

28. **The kernel-symbol cache can publish partially initialized state to parallel loads.**

    Ordinary symbol lookups reuse a cache: loader
    `src/native_loader.cpp:1462–1467` holds a function-static unordered_map
    and returns it whenever it is nonempty. Population occurs afterward,
    inserting entries during the kallsyms scan at :1496–1524. C++ protects
    construction of that map object, while the following mutations and
    nonempty test have their own synchronization requirement.

    A source-level interleaving illustrates the gap: one loader inserts its
    first symbol and continues scanning; another sees a nonempty map and
    calls find while population is still running. That second lookup can
    see an incomplete symbol set, and the concurrent container read/write
    itself is a data race. Concurrent first callers can also both start
    populating an initially empty table.

    The shim's native-load scope uses a read lock
    (`libbpfrejit_shim.c:477–481`), which allows simultaneous load readers;
    its recursion flag is thread-local (:136). The call at :590 reaches the
    shared-library loader through shim_native_loader.h:306, and the exported
    entry at native_loader.cpp:4335–4354 calls load_from_fd directly. Thus the
    reviewed call chain supplies concurrent entry rather than an exclusive
    cache-initialization boundary. Current application race occurrence and
    failure frequency remain to establish.

    Build and publish the complete immutable table through C++'s existing
    function-static initialization, then reuse it for lookups. This keeps
    unrelated loads parallel and preserves existing resolution/error behavior.
    It needs neither a mutex around whole program loading nor another symbol
    cache or runtime admission test. This is load-time correctness work;
    ordinary cache hits already avoid rescanning, and per-call native timing
    and installed bytes are separate from this finding.

    Filesystem construction has a related same-key race. Context LTO checks
    its final object at native_loader_context_lto.hpp:33–36, then uses only
    the process PID to distinguish its temporary at :37. Native linking does
    the same at native_loader.cpp:3384–3392. Two cold loads of the same key
    within one process therefore share the temporary object or proof/blob/
    reloc/map/ABI file names and compiler logs. Existing parallel entry from
    the shim makes this a real interface precondition, with application
    interleaving still to establish.

    For example, both callers can miss the cache and open/truncate the same
    temporary. One publishes it through rename while the other's open file
    can still write that inode. The final path can then expose an object
    being written; the second publisher can also find its source path moved.
    `publish_cache_file` at :3241–3253 attempts rename then copy from that
    same source, so publication alone does not isolate the construction.
    Native-stub BTF metadata uses a PID-only temporary as well (:934–936).

    Give one in-flight construction ownership of a cache key, and let other
    consumers reuse its completed immutable product. Keep independent keys
    parallel and retain failed-build diagnostics. This matches the existing
    one-build/product rule and avoids duplicated cold work. The fix belongs
    to cache construction, separate from new artifact-admission checks or
    whole-program-load serialization. Runtime occurrence, load-time savings
    and current image behavior remain measurement work.
