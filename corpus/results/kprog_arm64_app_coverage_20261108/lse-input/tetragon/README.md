Complete Tetragon Armv8.1 LSE native compiler input

The existing native-tetragon recipe uses the current AArch64 ABI/reserved registers, captured guest sysroot and installed libbpf headers, with -march=armv8.1-a+lse. The original247 application manifest rows retain their identities and point to the rebuilt native files. Complete compiler output and native instruction census accompany the exact build recipe and native inputs. Runtime submission uses the paired five-step QEMU path after the active application cohorts close.

Make exit 0; native objects 62; atomic census {"ldaddal": 227, "ldclral": 2, "ldsetal": 44}.
