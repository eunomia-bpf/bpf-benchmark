Complete OTel native compiler Os frame input

The complete upstream OTel native recipe uses one Os profile with the retained AArch64 ABI/reserved registers and guest sysroot plus Armv8.1 LSE. The compiler applies Os to every translation unit. Native objects and compiler-generated stack-usage records accompany the exact commands and full build output. The captured O3 perf_unwind_native source has a496byte native private arena plus64byte tags and8byte payload, reaching stock-verifier offset-576. This native-input change measures ordinary compiler frame geometry; the stock verifier evaluates fresh B in the complete application successor. QEMU timing provides functional evidence.

Make exit 0; native objects 16.

The compiler stack-usage record for both perf_unwind_native and kprobe_unwind_native is496bytes under this Os profile. The earlier O2 profile also records496bytes. The generic simulator storage and BPF frame representation remain the concrete continuation for this frontier.
