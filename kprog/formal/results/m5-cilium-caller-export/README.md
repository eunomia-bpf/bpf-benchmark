# Complete retained Cilium caller with original LINK statements

The checked-in C is the literal37573-byte original request1 trusted_arm64.bpf.c in Cilium20261127T090610Z. Its native input and archive/member/source hashes are bound by inspect_export.py. The recorded local macro header exactly matches the captured hash. A small translation unit repeats the original profile before the existing formal extraction bindings,then restores the original pointer-writer statement body inline only for LINK. The entire captured caller is included unchanged. This retains actual LR assignment,eager SP read,table walks,word/tag stores and loops at all8 sites,without the old four-argument writer call. Other operations retain the existing extraction interfaces;whole-function extraction fidelity and prefix/native refinement are NOT asserted here. These are BPF-helper sites,not memcpy sites.

The existing CompCert frontend emits37519 top-level declarations/480440 lines/26564297 bytes. A single Lean source check exhausted the ORIGINAL32GiB address-space cap. No cap was raised. Pure import/namespace packaging divides complete declarations into37 modules;reconstruction exactly reproduces the original full export bytes and order,including all types,globals,functions,metadata and the complete original caller. The package build passes76 jobs. Makefile regeneration produces byte-identical declarations. No source statement is pruned or replaced by a new interpreter.

Query.lean checks the actual program/function types and two original source-file/context ABI facts. The complete actual caller's label/resource/execution proofs are a separate following step. Source/linker/loaded-text/global/provider/fault/whole-source/universal/refinement obligations remain;this is no app acceptance or memcpy evidence. Native P,runtime,headers,oracle,framework,benchmark settings and paper remain unchanged.

Reproduce with make KProgFormal/Clight/Arm64CiliumCaller.lean,then lake build +KProgFormal.Clight.Arm64CiliumCaller. Existing proof resources remain CPU17,nice0,j1,32GiB,shared timing,default200000 heartbeats/512 recursion. V owns unified makecheck.

The Clight modules remain ignored build products,matching the existing source-first workflow;they are not force-added. Their complete hashes/reconstruction evidence are retained in packaging.json and generated afresh by the Makefile.

Default root Lake1481 jobs passes with the complete exported caller imported. This confirms source/build integration;the real LR/word/tag execution proof is still unadopted and is not counted as a result.
