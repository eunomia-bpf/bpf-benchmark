# Functional fixes since 2026-05-29: is their code still in HEAD?

Operator 2026-11-16: "功能正常吗? 我们的功能修复也都在?" and "还有新的 verify 修复也在? verify 也要继续做".

`survive.py` takes every commit since 2026-05-29 whose subject reads like a fix and that touches the loader, linker, trusted module, direct-native module, specializer/B compiler, stock path, shim or app compat headers, and counts how many of its added code lines still appear in the HEAD version of the same file. `result.txt` lists the commits under 60%.

Measured 2026-11-16T02:08:03Z: 343 fix-like commits; 159 under 60%; 65 of them because whole files were removed (the build-time specialization scripts, native_compat.h and native_division.cpp removed on 2026-11-15 as old routes, and the verified-track checked headers rewritten in early November). A line count cannot tell a lost fix from a rewrite, so the decisive test is each application running end to end on the native side: the breadth round of 2026-11-16 does that, and each load failure is traced to its cause.
