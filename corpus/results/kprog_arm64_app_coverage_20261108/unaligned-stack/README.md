Generic ARM stack byte-arm lowering

Whole OTel8GiB cohort1d63beebe reaches verifier stack-alignment checks after two fresh compilations and one binding. Native LDUR reads offsets29/21/45; the old byte arm emits wide BPF stack accesses. The candidate assembles each selected volatile stack byte into the established little-endian value. The aligned whole-word/pointer spill arm and provenance selector retain their contracts.

Four existing UBSan stack routing/tag/arena/write hosts pass. A single generic native control spans four widths and eight byte alignments: the prior source reaches the verifier alignment refusal, and the candidate freshly generates, compiles, verifies, binds and executes with retval2. Both raw cohorts retain exact source/native/compiler/request identities. The source patch and complete80-source private profile accompany this result. Generic34 safety and complete OTel consumption continue through the captured successor.
