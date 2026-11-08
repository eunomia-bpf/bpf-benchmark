# x86 exact native JIT emission extent

Private native-kinsn transport uses the callback emit=false extent to allocate native emission storage, followed by the existing JIT image/offset path. Ordinary kinsn scratch rules retain their current route. Native descriptor max_emit_bytes128 retires in the paired candidate module. Callback/allocation errors retain their ordinary handling; runtime admission predicates and new limits added0. Canonical source/runtime adoption0.

The existing warm kernel cache supplies the candidate Image/module build, exit0. Existing patch application/idempotence/conflict checks pass. The actual source-extracted host helper covers24 native/ordinary length/emit scenes and2 allocation/callback error paths under ASan/UBSan, and retains the baseline declared129-byte refusal. Private loader changes only its transport chunk width to64KiB to exercise a complete wide chunk; actual native input bytes retain their identity.

| Native input | Generated/compiled | Service status | Producer/TEST_RUN exit |
| --- | ---: | ---: | ---: |
| small | 1 | 0 | 0 |
| wide | 0 | -5 | 1 |

The original wide native object has32780text bytes (8193ordinary LEA instructions between scalar initialization and retval2); normal link canonicalization supplies the final image. Both positive producers use the existing XDP TEST_RUN and compare retval2/output0. Actual results above retain their own stages. The initial2GiB guest compiles/executes the small control and records a wide-compiler SIGKILL; the serial retry uses the existing host compiler broker and the identical native input. A short earlier host retry was withdrawn to preserve the active Tracee guest; the resource correction record and original files remain archived.

Commands in the owning Workspace:

```sh
sh /workspaces/.agent-state/kprog-lanes/C/design-only/native-extent/build.sh
make -f /workspaces/.agent-state/kprog-lanes/C/design-only/native-extent/Makefile host loader native-inputs
python3 /workspaces/.agent-state/kprog-lanes/C/design-only/native-extent/retry.serial.py
```

[summary.json](summary.json) retains real stages and hashes; [raw.tar.gz](raw.tar.gz) retains exact source/patch/private transport edits, original positive native objects, source-extracted host cases, kernel/module/compiler logs, complete initial/retry service/native/BPF/verifier receipts, actual candidate Image/module, and reproduction scripts. The private warm kernel build remains available for a coherent shared-kernel/module adoption and original BCC/Katran replay. Universal native-link/copy/ABI laws retain V ownership.
