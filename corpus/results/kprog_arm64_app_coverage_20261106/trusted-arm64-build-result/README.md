# ARM trusted kernel/module incremental build

`taskset -c 8-23 make host-kinsn-arm64 IMAGE_BUILD_JOBS=8` completed with
exit 0 using the existing canonical ARM kernel cache. Image, EFI image, kernel
symbols/configuration and all 11 modules are pinned in build.json. Recorded
critical patch/module/wire hashes match before and after compilation.

No clean build, private source copy, Docker image replacement or active guest
replacement occurred. The retained v35 runtime remains separate. This result
establishes compilation only; ARM QEMU transport checks and the generated
Katran service path remain pending. Completed raw build logs are retired under
the cleanup order; the canonical incremental outputs stay available.
