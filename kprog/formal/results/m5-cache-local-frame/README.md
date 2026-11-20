# Canonical cache observations outside selected register cells

`Arm64CacheLocalFrame.Kept` records exact imported Mem observations of canonical
locals outside the selected word/tag cells. Actual allocation/free frames and
the existing writer certificate supply this property; trans composes them.
It preserves every typed header pointer and the borrowed header/pointee walks,
including undefined values, pointers and refused loads.

The existing WarmEntryCache predicate transports through these exact
observations. warm_iff moves the same cache between any frontier above its
canonical allocation and the actual memory frontier, using typed ownership
and real pointer readbacks. No read success, warmth, alias exclusion or post
resource is asserted by the transport lemmas. No runtime or ISA model changes.

Focused check passes 177 jobs and seven public type/axiom queries at original
200000-heartbeat/512-depth caps on CPU 17, nice 0, one worker and 32 GiB address
space. Whole `lake build KProgFormal` proof-library/root confirmation passes 285
jobs on CPUs 16–23, nice 19, one worker and 32 GiB address space.
Raw: `/workspaces/kprog-raw/formal/m5-cache-local-frame`.
M5/M6 remain open; completed ISA-family count is zero.
