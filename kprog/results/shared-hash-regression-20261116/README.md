Shared-hash regression investigation, 2026-11-16

Coordinator20:20 requests before/after-f45bb2485 diagnostics on image6641a7e1,
CPUs16-23, for OTel and Katran. Actual body/helper/map per-call comparison is
still open; no diagnostic guest has been started by this result yet.

Static audit (audit.json): build_x86_lookup_call_postprocess is text-identical
before and after f45bb2485. The kernel raw __htab_map_lookup_elem returns an
htab_elem and leaves LRU marking to its caller. The kernel LRU JIT generator
and native typed LRU postprocessing test/store ref at byte35; generic LRU
map operations mark it too (hashtab.c:788-809,812-838,2441-2452).

The retained pre-f45 Katran blob has no explicit typed LRU ref compare/store;
its dynamic LRU lookups retain generic map-ops dispatch. The retained OTel
sampling-entry blob has one such compare/store sequence. Thus the source
change did not delete the caller's LRU update. This rules out deletion of
that sequence, not every possible runtime map-binding, hash-cost or eviction
mechanism. The older May-linker missing-lookup case remains distinct.

The copied raw hash is exactly identical in the two retained app blobs:
Katran [10198,12642), OTel [7685,10129), 2444 B each. Its sole external raw
fallback is at relative2434, and each region has123 retained ABI instruction
sites. audit.py extracts the retained body and ABI sites as raw inputs for
the requested current-image comparison; it builds no old tool or source copy.

A diagnostic can use the existing BPFREJIT_NATIVE_LINK_BINARY override through
the results bind mount and the current image's own linker. A retained-body
comparison must preserve map patches, helper/image-pointer relocations,
entry/end control flow and ABI sites. Keep the image, workload and frozen
entry intact. Hardware guest-only sampling is needed for OTel; software
CPU-clock missed its perf-event BPF execution in the earlier profile.
