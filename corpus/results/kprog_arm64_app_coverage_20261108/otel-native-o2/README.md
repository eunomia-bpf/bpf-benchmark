Complete OTel native compiler O2 frame input

The complete upstream OTel native recipe uses one O2 profile with the retained AArch64 ABI/reserved registers and guest sysroot plus Armv8.1 LSE. The compiler applies O2 to every translation unit. Native objects and compiler-generated stack-usage records accompany the exact commands and full build output. The captured O3 perf_unwind_native source has a496byte native private arena plus64byte tags and8byte payload, reaching stock-verifier offset-576. This native-input change measures ordinary compiler frame geometry; the stock verifier evaluates fresh B in the complete application successor. QEMU timing provides functional evidence.

Make exit 0; native objects 16.
