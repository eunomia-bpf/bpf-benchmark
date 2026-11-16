# Actual x86 XDP and SKB producer entries

The real parser and renderer consume `oracles/x86_context_profile.S` in XDP and
SKB forms, each 30 native instructions, a 48-byte frame and six named fact cells.
Both programs read three context fields, call their typed context helper, then
read the fields again and fold the full result into the return value. The
existing export driver now accepts the producer's entry kind; RAW remains its
default. No shared simulator C, helper body or production flag changes.

The exports contain 123 internal bodies each. XDP is 20,863,158 bytes and SKB
20,948,882 bytes, with exact regeneration. All previous 20 AST files remain
unchanged. `make clight`, all 22 Clight modules/59 jobs, the actual entry/layout
checks and six standard-axiom queries pass at existing limits. Mature layout
calculation checks the typed entry/helper signatures, 48-byte arena, six named
fact cells and actual 40/216-byte ABI storage declarations.

Four UBSan host combinations exercise XDP/SKB with native UAPI fields or the
CompCert full-pointer platform adapter. Each checks 16 complete returns and 16
nonreturning helper prefixes, with independent expected results, exact input
counts 46/24, helper context/argument identity and the complete context buffer.
The helper environment deliberately changes fields before returning or refusing;
these controlled effects test live binding, not actual kernel-helper behavior.
The adapter checks the context/kind/UAPI offset and physical low-field updates
before supplying the full pointer value. Field/phase values differ so two stale
reads do not cancel. Native host UAPI pointer fields are 32-bit; the adapter
also checks their high bits. No across-mode full-state capture equality is
claimed, and private entry state is not exposed by these tests.

Four negatives fail with the intended diagnostic: pointer truncation and wrong
helper context, each on XDP and SKB. They alter the included C in memory only;
normal products are rebuilt afterward. Reproduce after `make clight` with:

```
python3 results/m4-x86-context-program/compare.py --output <new-raw-directory>
```

The default RAW fixture's 3,804-byte C matches both the historical export driver
at `d934e015d` and the original product exactly. This step leaves shared C
unchanged. Ordinary BPF compilation of the new profiles produces XDP 736 bytes
and TC 1,072 bytes, each with two allocated relocations. These are compile
results, not stock-verifier or kernel execution results. Extraction preprocessing
is 2,605,362/2,605,333 bytes for 4,642/4,660-byte producer C; these describe the
extraction units, not application compiler performance.

Full commands, intermediate host data patterns, negatives, restored outputs and
measurements remain in `/workspaces/kprog-raw/formal/m4-x86-context-program`.
M4 remains open: the producer's readonly-data hook is the next concrete C-subset
probe. Actual memory/context/helper correspondence and all 2,065 Clight
refinements belong to M5, followed by O1/O2/O4 recount, M6 retirement and final
whole `lake build`/`make check`.
