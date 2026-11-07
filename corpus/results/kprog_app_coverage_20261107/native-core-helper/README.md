# Generic native CORE helper preservation

The shared native compatibility layer now expresses PT_REGS_*_CORE through the
common BPF_CORE_READ path, and single-field reads uniformly call their selected
probe helper. Kernel and legacy helper selection remains113/4 respectively;
BPF_CORE_READ_USER retains112. Plain PT_REGS_* context access keeps its existing
register-field representation. The direct pt_regs CORE specialization and its
private support macros are retired.

| Generic mechanism observation | Before | Current |
| --- | ---: | ---: |
| x86/ARM kernel/legacy valid read cases | 102,400 | 102,400 |
| CORE helper calls elided | 77,824 | 0 |
| Protected-page probe outcomes matching EFAULT and zero result | Recorded through current helper path | 84 |
| Valid read value/size/address/helper selection differences | 0 | 0 |

The independent helper fixture uses process_vm_readv to obtain real protected
memory errors, then applies the documented helper destination-zeroing contract.
It runs on the x86-64 host with x86 and ARM register-selector preprocessor
configurations and instrumented kernel/legacy helper contract models. It checks17
CORE register selectors, ordinary/const single-field reads, INTO and low-level
forms, four data widths and plain-context access, across1024 seeds in the four
selector/helper configurations under UBSan. The helper and caller
both observe the requested source address, width and helper identity. The full
command/output histories include the first candidate and its refined explicit
void destination cast.

The entire unchanged Tracee source compiles through the existing native-object
Make rule and flags, force-including the candidate header. Its173 defined
functions and87 map symbols match the earlier object inventory. This is a new
native-input epoch: original025fe5e116ed becomes7479850e2345. The current
private object was compiled against the byte-identical published header copy;
the exact include command and source hashes are archived. Upstream application
code, baseline BPF objects and workloads retain their captured sources.

An application replay through the common native-only generation/verifier/binding
service follows the current serial application/OTel queue. It will record all
reached programs, binding outcomes and work counters. These finite observations
support the generic compiler mechanism; universal helper/fault and native-link
laws carry the formal preservation responsibilities. Earlier native timing
cohorts retain their original native identities; future measurements record the
new native-input epoch.

raw.tar.gz contains exact before/current headers, patch, generic fixture,
build/terminal histories and whole native object. observations.json records
all counts and object/header identities.
