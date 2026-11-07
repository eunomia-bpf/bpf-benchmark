# Matching boot image and module BTF

The incremental bzImage build completes the kernel module update. The compressed
boot payload and the module build base contain the same5,670,459-byte BTF stream,
SHA `75fe34c0e2e1da4cee5a0989934299c4d078460b31b4c611fcaf359101c74dc2`. The boot image SHA is
`df7a92936b4180044271d87854fee6783d05a72a62eee72c70b28cf811cb5278` and the refreshed image is `sha256:1ead525666cc9da03d9740230bb9f1ac4cb567e36eb255172a7bd63ffa5a2b16`.
The package manifest records842 kernel modules against vmlinux
`76c6adc50151a4a7f8ab5591b353c27bcb1d404609fb7d56c00c861efc58bc02`.

The previous live Katran insertion and Tetragon CO-RE attempts exposed the
remaining boot/module epoch difference: image a5b0 contained the refreshed
modules while its guests booted2f12. Their full logs and errors are published in
native-modules-katran and native-modules-tetragon__observer. Kernel BTF type/name
errors identify the insertion/relocation cause; both services received zero
native requests during those baseline startup attempts.

The common modules recipe now requests bzImage and modules in the same
incremental Make invocation. Existing kernel objects and configuration remain
in use. Queuer3653317 paused at its parent scheduling point while its current
Tetragon guest retained its captured epoch; the detached build completion trap
resumed scheduling. Tracee and Cilium subsequently capture the coherent boot
image. Whole-OTel private stack replay3653318 follows the application queue.

observations.json records both epochs and the BTF equality. raw.tar.gz retains
the actual extracted boot BTF stream, extraction script/log, incremental build
and image logs, scheduling record and complete package manifest. Runtime
application startup supplies the subsequent live module/CO-RE observations.
