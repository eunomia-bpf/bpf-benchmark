# Compiled trie body diagnostic

Scope: measure the retained native ARRAY/LPM range against the sole kernel's
compiled trie body on stable host nodes with the captured kernel layout.
The smallest experiment extracts these existing bodies, records host-only
patches, checks expected value pointers and times three query shapes. The
production source, canonical CLI, checked guest, image and corpus entry retain
their current state.

The kernel's external return-thunk jump becomes an ordinary RET in its host
slice. The native range's generic helper relocation targets a local UD2;
the fixture supplies the captured LPM type and twelve-byte data shape. Both
original byte slices and each explicit patch remain in raw output. A normal
SysV call executes both bodies. The fixture checks empty/full/short/over-max
and first/last-bit cases, then a balanced fourteen-level trie with 4,096
queries and a retained ancestor value. Timing alternates arm order across
three samples for full hit, first-bit miss and deep hit.

Run the committed wrapper with setsid nohup. It holds timing SH and image SH,
uses CPU19 and limits address space to4GiB. Raw output stays in
/workspaces/kprog-raw/perf/lpm-body-20261118. This is helper-body diagnostic
evidence. Kernel return mitigations, concurrent update/RCU behavior, actual
application frequency, per-call BPF time and installed app bytes belong to
omp's frozen image/check/affected-app batch with all LTO enabled.

2026-11-18T01:16:29Z — Host2846223 ended0. The eight functional groups pass,
including all4,096 deep queries. Kernel/native median body ratios are1.158
for full hit,1.292 for first-bit miss and0.812 for deep hit. The three raw
kernel deep samples are118.421/104.393/104.664ns; native is128.984/128.919/
128.039ns. See baseline.json for every raw sample, input path and patch.
The first deep kernel sample includes the initial large-tree cache state.
All measurements stay in the report. Function-text sizes are497B kernel and
293B native fused dispatch; each has a different place in installed app code,
so these sizes describe the slices. Production emits an IMUL by8 per trie
level where the kernel uses an indexed address. A local SIB specialization
and the equivalent NOT/AND bit selector are the next measured source step.
