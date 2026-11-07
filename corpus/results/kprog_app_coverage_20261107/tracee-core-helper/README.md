# Whole Tracee application with preserved CORE helper reads

Actual `x86_kvm_corpus_20261107_203243_822180`, original upstream application/BPF
objects and existing workload. The native object comes from the shared
CORE helper-preservation repair48ff82cfb, with identical173 function/87 map
symbol inventory and the original native compiler flags. Its actual ELF SHA is
7479850e23454e957f4c5880a18d92a91c27dd282af52f768e4422fe9366a722.

| Baseline app loads | Generated | Compiled | Accepted/bound | Specialization errors | Verifier rejections | Further app entries remaining |
| ---: | ---: | ---: | ---: | --- | ---: | ---: |
| 151 | 2 | 2 | 2 | 1: helper source stack relation | 0 | 148 |

The common registered service fresh-binds the raw syscall entry and
sys_enter_init. The previous scalar register-frame read error at sys_enter_init
is closed in this native-input epoch. The next whole-application request,
sys_enter_submit, reaches the generic helper source stack relation check at
native offset0x1ad7. All three kernel-owned original native identities match
7479850e2345, with two complete success archives and one complete failure
archive. The next generic affine stack-origin repair and whole-application
replay continue from this observed analysis failure class.

Image34ad6722ac3a contains the new whole native object over the coherent kernel
runtime; bootdf7a92936b41,12GiB/eight guest vCPUs on20–23, one sample and duration
two seconds. All source input hashes retain their launch values. Actual app and
metadata status is error, outer driver status is0. Baseline work completes;
native matching-work measurement remains on the application completion queue.

coverage.json preserves raw counters/work and request outcomes. service.tar.gz
preserves the original complete service/kernel/request archive; result.tar.gz
preserves the corpus tree; launch.tar.gz preserves compiler/native/image/source
inputs and the exact private-image command path. collection-evidence.tar.gz
preserves collector and image build/retirement history. Closed experiment image
tar, guest disk and temporary candidate image tag are retired. Universal
simulator, token, helper and native-link laws carry the safety argument.
