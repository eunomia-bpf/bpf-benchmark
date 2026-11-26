savedcmd_bpf_x86_native_lab.mod.o := gcc -Wp,-MMD,./.bpf_x86_native_lab.mod.o.d -nostdinc -I/workspaces/repository/vendor/linux-framework/arch/x86/include -I/workspaces/.agent-state/kprog-ck/build-x86/arch/x86/include/generated -I/workspaces/repository/vendor/linux-framework/include -I/workspaces/.agent-state/kprog-ck/build-x86/include -I/workspaces/repository/vendor/linux-framework/arch/x86/include/uapi -I/workspaces/.agent-state/kprog-ck/build-x86/arch/x86/include/generated/uapi -I/workspaces/repository/vendor/linux-framework/include/uapi -I/workspaces/.agent-state/kprog-ck/build-x86/include/generated/uapi -include /workspaces/repository/vendor/linux-framework/include/linux/compiler-version.h -include /workspaces/repository/vendor/linux-framework/include/linux/kconfig.h -include /workspaces/repository/vendor/linux-framework/include/linux/compiler_types.h -D__KERNEL__ -fmacro-prefix-map=/workspaces/repository/kprog/perf/direct-native/= -std=gnu11 -fshort-wchar -funsigned-char -fno-common -fno-PIE -fno-strict-aliasing -mno-sse -mno-mmx -mno-sse2 -mno-3dnow -mno-avx -mno-sse4a -fcf-protection=none -m64 -falign-jumps=1 -falign-loops=1 -mno-80387 -mno-fp-ret-in-387 -mpreferred-stack-boundary=3 -mskip-rax-setup -march=x86-64 -mtune=generic -mno-red-zone -mcmodel=kernel -mstack-protector-guard-reg=gs -mstack-protector-guard-symbol=__ref_stack_chk_guard -Wno-sign-compare -fno-asynchronous-unwind-tables -mindirect-branch=thunk-extern -mindirect-branch-register -mindirect-branch-cs-prefix -mfunction-return=thunk-extern -fno-jump-tables -fpatchable-function-entry=16,16 -fno-delete-null-pointer-checks -O2 -fno-allow-store-data-races -fstack-protector-strong -fno-stack-clash-protection -pg -mrecord-mcount -mfentry -DCC_USING_FENTRY -fno-inline-functions-called-once -falign-functions=16 -fstrict-flex-arrays=3 -fms-extensions -fno-strict-overflow -fno-stack-check -fconserve-stack -fno-builtin-wcslen -Wall -Wextra -Wundef -Werror=implicit-function-declaration -Werror=implicit-int -Werror=return-type -Werror=strict-prototypes -Wno-format-security -Wno-trigraphs -Wno-frame-address -Wno-address-of-packed-member -Wmissing-declarations -Wmissing-prototypes -Wframe-larger-than=2048 -Wno-main -Wno-type-limits -Wno-dangling-pointer -Wvla-larger-than=1 -Wno-pointer-sign -Wcast-function-type -Wno-array-bounds -Wno-stringop-overflow -Wno-alloc-size-larger-than -Wimplicit-fallthrough=5 -Werror=date-time -Werror=incompatible-pointer-types -Werror=designated-init -Wenum-conversion -Wunused -Wno-unused-but-set-variable -Wno-unused-const-variable -Wno-packed-not-aligned -Wno-format-overflow -Wno-format-truncation -Wno-stringop-truncation -Wno-override-init -Wno-missing-field-initializers -Wno-shift-negative-value -Wno-maybe-uninitialized -Wno-sign-compare -Wno-unused-parameter -g   -DMODULE  -DKBUILD_BASENAME='"bpf_x86_native_lab.mod"' -DKBUILD_MODNAME='"bpf_x86_native_lab"' -D__KBUILD_MODNAME=bpf_x86_native_lab -c -o bpf_x86_native_lab.mod.o bpf_x86_native_lab.mod.c   ; /workspaces/.agent-state/kprog-ck/build-x86/tools/objtool/objtool --hacks=jump_label --hacks=noinstr --hacks=skylake --orc --retpoline --rethunk --static-call --uaccess --prefix=16  --link  --module bpf_x86_native_lab.mod.o

source_bpf_x86_native_lab.mod.o := bpf_x86_native_lab.mod.c

deps_bpf_x86_native_lab.mod.o := \
    $(wildcard include/config/MODULE_UNLOAD) \
  /workspaces/repository/vendor/linux-framework/include/linux/compiler-version.h \
    $(wildcard include/config/CC_VERSION_TEXT) \
  /workspaces/repository/vendor/linux-framework/include/linux/kconfig.h \
    $(wildcard include/config/CPU_BIG_ENDIAN) \
    $(wildcard include/config/BOOGER) \
    $(wildcard include/config/FOO) \
  /workspaces/repository/vendor/linux-framework/include/linux/compiler_types.h \
    $(wildcard include/config/DEBUG_INFO_BTF) \
    $(wildcard include/config/PAHOLE_HAS_BTF_TAG) \
    $(wildcard include/config/FUNCTION_ALIGNMENT) \
    $(wildcard include/config/CC_HAS_SANE_FUNCTION_ALIGNMENT) \
    $(wildcard include/config/X86_64) \
    $(wildcard include/config/ARM64) \
    $(wildcard include/config/LD_DEAD_CODE_DATA_ELIMINATION) \
    $(wildcard include/config/LTO_CLANG) \
    $(wildcard include/config/HAVE_ARCH_COMPILER_H) \
    $(wildcard include/config/KCSAN) \
    $(wildcard include/config/CC_HAS_ASSUME) \
    $(wildcard include/config/CC_HAS_COUNTED_BY) \
    $(wildcard include/config/FORTIFY_SOURCE) \
    $(wildcard include/config/UBSAN_BOUNDS) \
    $(wildcard include/config/CC_HAS_COUNTED_BY_PTR) \
    $(wildcard include/config/CC_HAS_MULTIDIMENSIONAL_NONSTRING) \
    $(wildcard include/config/UBSAN_INTEGER_WRAP) \
    $(wildcard include/config/CFI) \
    $(wildcard include/config/ARCH_USES_CFI_GENERIC_LLVM_PASS) \
    $(wildcard include/config/CC_HAS_BROKEN_COUNTED_BY_REF) \
    $(wildcard include/config/CC_HAS_ASM_INLINE) \
  /workspaces/repository/vendor/linux-framework/include/linux/compiler-context-analysis.h \
  /workspaces/repository/vendor/linux-framework/include/linux/compiler_attributes.h \
  /workspaces/repository/vendor/linux-framework/include/linux/compiler-gcc.h \
    $(wildcard include/config/ARCH_USE_BUILTIN_BSWAP) \
    $(wildcard include/config/SHADOW_CALL_STACK) \
    $(wildcard include/config/KCOV) \
    $(wildcard include/config/CC_HAS_TYPEOF_UNQUAL) \
  /workspaces/repository/vendor/linux-framework/include/linux/module.h \
    $(wildcard include/config/MODULES) \
    $(wildcard include/config/SYSFS) \
    $(wildcard include/config/MODULES_TREE_LOOKUP) \
    $(wildcard include/config/LIVEPATCH) \
    $(wildcard include/config/STACKTRACE_BUILD_ID) \
    $(wildcard include/config/ARCH_USES_CFI_TRAPS) \
    $(wildcard include/config/MODULE_SIG) \
    $(wildcard include/config/GENERIC_BUG) \
    $(wildcard include/config/KALLSYMS) \
    $(wildcard include/config/SMP) \
    $(wildcard include/config/TRACEPOINTS) \
    $(wildcard include/config/TREE_SRCU) \
    $(wildcard include/config/BPF_EVENTS) \
    $(wildcard include/config/DEBUG_INFO_BTF_MODULES) \
    $(wildcard include/config/JUMP_LABEL) \
    $(wildcard include/config/TRACING) \
    $(wildcard include/config/EVENT_TRACING) \
    $(wildcard include/config/DYNAMIC_FTRACE) \
    $(wildcard include/config/KPROBES) \
    $(wildcard include/config/HAVE_STATIC_CALL_INLINE) \
    $(wildcard include/config/KUNIT) \
    $(wildcard include/config/PRINTK_INDEX) \
    $(wildcard include/config/CONSTRUCTORS) \
    $(wildcard include/config/FUNCTION_ERROR_INJECTION) \
    $(wildcard include/config/DYNAMIC_DEBUG_CORE) \
    $(wildcard include/config/MITIGATION_RETPOLINE) \
  /workspaces/repository/vendor/linux-framework/include/linux/list.h \
    $(wildcard include/config/LIST_HARDENED) \
    $(wildcard include/config/DEBUG_LIST) \
  /workspaces/repository/vendor/linux-framework/include/linux/container_of.h \
  /workspaces/repository/vendor/linux-framework/include/linux/build_bug.h \
  /workspaces/repository/vendor/linux-framework/include/linux/compiler.h \
    $(wildcard include/config/TRACE_BRANCH_PROFILING) \
    $(wildcard include/config/PROFILE_ALL_BRANCHES) \
    $(wildcard include/config/OBJTOOL) \
  /workspaces/.agent-state/kprog-ck/build-x86/arch/x86/include/generated/asm/rwonce.h \
  /workspaces/repository/vendor/linux-framework/include/asm-generic/rwonce.h \
  /workspaces/repository/vendor/linux-framework/include/linux/kasan-checks.h \
    $(wildcard include/config/KASAN_GENERIC) \
    $(wildcard include/config/KASAN_SW_TAGS) \
  /workspaces/repository/vendor/linux-framework/include/linux/types.h \
    $(wildcard include/config/HAVE_UID16) \
    $(wildcard include/config/UID16) \
    $(wildcard include/config/ARCH_DMA_ADDR_T_64BIT) \
    $(wildcard include/config/PHYS_ADDR_T_64BIT) \
    $(wildcard include/config/64BIT) \
    $(wildcard include/config/ARCH_32BIT_USTAT_F_TINODE) \
  /workspaces/repository/vendor/linux-framework/include/uapi/linux/types.h \
  /workspaces/.agent-state/kprog-ck/build-x86/arch/x86/include/generated/uapi/asm/types.h \
  /workspaces/repository/vendor/linux-framework/include/uapi/asm-generic/types.h \
  /workspaces/repository/vendor/linux-framework/include/asm-generic/int-ll64.h \
  /workspaces/repository/vendor/linux-framework/include/uapi/asm-generic/int-ll64.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/uapi/asm/bitsperlong.h \
  /workspaces/repository/vendor/linux-framework/include/asm-generic/bitsperlong.h \
  /workspaces/repository/vendor/linux-framework/include/uapi/asm-generic/bitsperlong.h \
  /workspaces/repository/vendor/linux-framework/include/uapi/linux/posix_types.h \
  /workspaces/repository/vendor/linux-framework/include/linux/stddef.h \
  /workspaces/repository/vendor/linux-framework/include/uapi/linux/stddef.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/posix_types.h \
    $(wildcard include/config/X86_32) \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/uapi/asm/posix_types_64.h \
  /workspaces/repository/vendor/linux-framework/include/uapi/asm-generic/posix_types.h \
  /workspaces/repository/vendor/linux-framework/include/linux/kcsan-checks.h \
    $(wildcard include/config/KCSAN_WEAK_MEMORY) \
    $(wildcard include/config/KCSAN_IGNORE_ATOMICS) \
  /workspaces/repository/vendor/linux-framework/include/linux/poison.h \
    $(wildcard include/config/ILLEGAL_POINTER_VALUE) \
  /workspaces/repository/vendor/linux-framework/include/linux/const.h \
  /workspaces/repository/vendor/linux-framework/include/vdso/const.h \
  /workspaces/repository/vendor/linux-framework/include/uapi/linux/const.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/barrier.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/alternative.h \
    $(wildcard include/config/CALL_THUNKS) \
    $(wildcard include/config/MITIGATION_ITS) \
    $(wildcard include/config/MITIGATION_RETHUNK) \
  /workspaces/repository/vendor/linux-framework/include/linux/stringify.h \
  /workspaces/repository/vendor/linux-framework/include/linux/objtool.h \
    $(wildcard include/config/FRAME_POINTER) \
    $(wildcard include/config/NOINSTR_VALIDATION) \
    $(wildcard include/config/MITIGATION_UNRET_ENTRY) \
    $(wildcard include/config/MITIGATION_SRSO) \
  /workspaces/repository/vendor/linux-framework/include/linux/objtool_types.h \
  /workspaces/repository/vendor/linux-framework/include/linux/annotate.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/asm.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/asm-offsets.h \
  /workspaces/.agent-state/kprog-ck/build-x86/include/generated/asm-offsets.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/extable_fixup_types.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/bug.h \
    $(wildcard include/config/DEBUG_BUGVERBOSE) \
    $(wildcard include/config/DEBUG_BUGVERBOSE_DETAILED) \
  /workspaces/repository/vendor/linux-framework/include/linux/instrumentation.h \
  /workspaces/repository/vendor/linux-framework/include/linux/static_call_types.h \
    $(wildcard include/config/HAVE_STATIC_CALL) \
  /workspaces/repository/vendor/linux-framework/include/asm-generic/bug.h \
    $(wildcard include/config/BUG) \
    $(wildcard include/config/GENERIC_BUG_RELATIVE_POINTERS) \
  /workspaces/repository/vendor/linux-framework/include/linux/once_lite.h \
  /workspaces/repository/vendor/linux-framework/include/linux/panic.h \
    $(wildcard include/config/PANIC_TIMEOUT) \
  /workspaces/repository/vendor/linux-framework/include/linux/stdarg.h \
  /workspaces/repository/vendor/linux-framework/include/linux/printk.h \
    $(wildcard include/config/MESSAGE_LOGLEVEL_DEFAULT) \
    $(wildcard include/config/CONSOLE_LOGLEVEL_DEFAULT) \
    $(wildcard include/config/CONSOLE_LOGLEVEL_QUIET) \
    $(wildcard include/config/EARLY_PRINTK) \
    $(wildcard include/config/PRINTK) \
    $(wildcard include/config/DYNAMIC_DEBUG) \
  /workspaces/repository/vendor/linux-framework/include/linux/init.h \
    $(wildcard include/config/MEMORY_HOTPLUG) \
    $(wildcard include/config/HAVE_ARCH_PREL32_RELOCATIONS) \
  /workspaces/repository/vendor/linux-framework/include/linux/kern_levels.h \
  /workspaces/repository/vendor/linux-framework/include/linux/linkage.h \
    $(wildcard include/config/ARCH_USE_SYM_ANNOTATIONS) \
  /workspaces/repository/vendor/linux-framework/include/linux/export.h \
    $(wildcard include/config/MODVERSIONS) \
    $(wildcard include/config/GENDWARFKSYMS) \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/linkage.h \
    $(wildcard include/config/CALL_PADDING) \
    $(wildcard include/config/MITIGATION_SLS) \
    $(wildcard include/config/FUNCTION_PADDING_BYTES) \
    $(wildcard include/config/UML) \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/ibt.h \
    $(wildcard include/config/X86_KERNEL_IBT) \
  /workspaces/repository/vendor/linux-framework/include/linux/ratelimit_types.h \
  /workspaces/repository/vendor/linux-framework/include/linux/bits.h \
  /workspaces/repository/vendor/linux-framework/include/vdso/bits.h \
  /workspaces/repository/vendor/linux-framework/include/uapi/linux/bits.h \
  /workspaces/repository/vendor/linux-framework/include/linux/overflow.h \
  /workspaces/repository/vendor/linux-framework/include/linux/limits.h \
  /workspaces/repository/vendor/linux-framework/include/uapi/linux/limits.h \
  /workspaces/repository/vendor/linux-framework/include/vdso/limits.h \
  /workspaces/repository/vendor/linux-framework/include/uapi/linux/param.h \
  /workspaces/.agent-state/kprog-ck/build-x86/arch/x86/include/generated/uapi/asm/param.h \
  /workspaces/repository/vendor/linux-framework/include/asm-generic/param.h \
    $(wildcard include/config/HZ) \
  /workspaces/repository/vendor/linux-framework/include/uapi/asm-generic/param.h \
  /workspaces/repository/vendor/linux-framework/include/linux/spinlock_types_raw.h \
    $(wildcard include/config/DEBUG_SPINLOCK) \
    $(wildcard include/config/DEBUG_LOCK_ALLOC) \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/spinlock_types.h \
  /workspaces/repository/vendor/linux-framework/include/asm-generic/qspinlock_types.h \
    $(wildcard include/config/NR_CPUS) \
  /workspaces/repository/vendor/linux-framework/include/asm-generic/qrwlock_types.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/uapi/asm/byteorder.h \
  /workspaces/repository/vendor/linux-framework/include/linux/byteorder/little_endian.h \
  /workspaces/repository/vendor/linux-framework/include/uapi/linux/byteorder/little_endian.h \
  /workspaces/repository/vendor/linux-framework/include/linux/swab.h \
  /workspaces/repository/vendor/linux-framework/include/uapi/linux/swab.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/uapi/asm/swab.h \
  /workspaces/repository/vendor/linux-framework/include/linux/byteorder/generic.h \
  /workspaces/repository/vendor/linux-framework/include/linux/lockdep_types.h \
    $(wildcard include/config/PROVE_RAW_LOCK_NESTING) \
    $(wildcard include/config/LOCKDEP) \
    $(wildcard include/config/LOCK_STAT) \
  /workspaces/repository/vendor/linux-framework/include/linux/dynamic_debug.h \
  /workspaces/repository/vendor/linux-framework/include/linux/jump_label.h \
    $(wildcard include/config/HAVE_ARCH_JUMP_LABEL_RELATIVE) \
  /workspaces/repository/vendor/linux-framework/include/linux/cleanup.h \
  /workspaces/repository/vendor/linux-framework/include/linux/err.h \
  /workspaces/.agent-state/kprog-ck/build-x86/arch/x86/include/generated/uapi/asm/errno.h \
  /workspaces/repository/vendor/linux-framework/include/uapi/asm-generic/errno.h \
  /workspaces/repository/vendor/linux-framework/include/uapi/asm-generic/errno-base.h \
  /workspaces/repository/vendor/linux-framework/include/linux/args.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/jump_label.h \
    $(wildcard include/config/HAVE_JUMP_LABEL_HACK) \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/nops.h \
  /workspaces/repository/vendor/linux-framework/include/asm-generic/barrier.h \
  /workspaces/repository/vendor/linux-framework/include/linux/stat.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/uapi/asm/stat.h \
  /workspaces/repository/vendor/linux-framework/include/uapi/linux/stat.h \
  /workspaces/repository/vendor/linux-framework/include/linux/time.h \
    $(wildcard include/config/POSIX_TIMERS) \
  /workspaces/repository/vendor/linux-framework/include/linux/cache.h \
    $(wildcard include/config/ARCH_HAS_CACHE_LINE_SIZE) \
  /workspaces/repository/vendor/linux-framework/include/uapi/linux/kernel.h \
  /workspaces/repository/vendor/linux-framework/include/uapi/linux/sysinfo.h \
  /workspaces/repository/vendor/linux-framework/include/vdso/cache.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/cache.h \
    $(wildcard include/config/X86_L1_CACHE_SHIFT) \
    $(wildcard include/config/X86_INTERNODE_CACHE_SHIFT) \
    $(wildcard include/config/X86_VSMP) \
  /workspaces/repository/vendor/linux-framework/include/linux/math64.h \
    $(wildcard include/config/ARCH_SUPPORTS_INT128) \
  /workspaces/repository/vendor/linux-framework/include/linux/math.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/div64.h \
  /workspaces/repository/vendor/linux-framework/include/asm-generic/div64.h \
    $(wildcard include/config/CC_OPTIMIZE_FOR_PERFORMANCE) \
  /workspaces/repository/vendor/linux-framework/include/vdso/math64.h \
  /workspaces/repository/vendor/linux-framework/include/linux/time64.h \
  /workspaces/repository/vendor/linux-framework/include/vdso/time64.h \
  /workspaces/repository/vendor/linux-framework/include/uapi/linux/time.h \
  /workspaces/repository/vendor/linux-framework/include/uapi/linux/time_types.h \
  /workspaces/repository/vendor/linux-framework/include/linux/time32.h \
  /workspaces/repository/vendor/linux-framework/include/linux/timex.h \
  /workspaces/repository/vendor/linux-framework/include/uapi/linux/timex.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/timex.h \
    $(wildcard include/config/X86_TSC) \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/processor.h \
    $(wildcard include/config/X86_VMX_FEATURE_NAMES) \
    $(wildcard include/config/X86_IOPL_IOPERM) \
    $(wildcard include/config/VM86) \
    $(wildcard include/config/X86_USER_SHADOW_STACK) \
    $(wildcard include/config/X86_DEBUG_FPU) \
    $(wildcard include/config/USE_X86_SEG_SUPPORT) \
    $(wildcard include/config/PARAVIRT_XXL) \
    $(wildcard include/config/CPU_SUP_AMD) \
    $(wildcard include/config/XEN) \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/processor-flags.h \
    $(wildcard include/config/MITIGATION_PAGE_TABLE_ISOLATION) \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/uapi/asm/processor-flags.h \
  /workspaces/repository/vendor/linux-framework/include/linux/mem_encrypt.h \
    $(wildcard include/config/ARCH_HAS_MEM_ENCRYPT) \
    $(wildcard include/config/AMD_MEM_ENCRYPT) \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/mem_encrypt.h \
    $(wildcard include/config/X86_MEM_ENCRYPT) \
  /workspaces/repository/vendor/linux-framework/include/linux/cc_platform.h \
    $(wildcard include/config/ARCH_HAS_CC_PLATFORM) \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/math_emu.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/ptrace.h \
    $(wildcard include/config/PARAVIRT) \
    $(wildcard include/config/IA32_EMULATION) \
    $(wildcard include/config/X86_DEBUGCTLMSR) \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/segment.h \
    $(wildcard include/config/XEN_PV) \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/page_types.h \
    $(wildcard include/config/PHYSICAL_START) \
    $(wildcard include/config/PHYSICAL_ALIGN) \
    $(wildcard include/config/DYNAMIC_PHYSICAL_MASK) \
  /workspaces/repository/vendor/linux-framework/include/vdso/page.h \
    $(wildcard include/config/PAGE_SHIFT) \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/page_64_types.h \
    $(wildcard include/config/KASAN) \
    $(wildcard include/config/RANDOMIZE_BASE) \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/kaslr.h \
    $(wildcard include/config/RANDOMIZE_MEMORY) \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/uapi/asm/ptrace.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/uapi/asm/ptrace-abi.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/paravirt-base.h \
    $(wildcard include/config/PARAVIRT_SPINLOCKS) \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/proto.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/uapi/asm/ldt.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/uapi/asm/sigcontext.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/current.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/percpu.h \
    $(wildcard include/config/CC_HAS_NAMED_AS) \
  /workspaces/repository/vendor/linux-framework/include/asm-generic/percpu.h \
    $(wildcard include/config/DEBUG_PREEMPT) \
    $(wildcard include/config/HAVE_SETUP_PER_CPU_AREA) \
  /workspaces/repository/vendor/linux-framework/include/linux/threads.h \
    $(wildcard include/config/BASE_SMALL) \
  /workspaces/repository/vendor/linux-framework/include/linux/percpu-defs.h \
    $(wildcard include/config/ARCH_MODULE_NEEDS_WEAK_PER_CPU) \
    $(wildcard include/config/DEBUG_FORCE_WEAK_PER_CPU) \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/cpufeatures.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/cpuid/api.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/cpuid/types.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/string.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/string_64.h \
    $(wildcard include/config/KMSAN) \
    $(wildcard include/config/ARCH_HAS_UACCESS_FLUSHCACHE) \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/page.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/page_64.h \
    $(wildcard include/config/DEBUG_VIRTUAL) \
    $(wildcard include/config/X86_VSYSCALL_EMULATION) \
  /workspaces/repository/vendor/linux-framework/include/linux/kmsan-checks.h \
  /workspaces/repository/vendor/linux-framework/include/linux/mmdebug.h \
    $(wildcard include/config/DEBUG_VM) \
    $(wildcard include/config/DEBUG_VM_IRQSOFF) \
    $(wildcard include/config/DEBUG_VM_PGFLAGS) \
  /workspaces/repository/vendor/linux-framework/include/linux/bug.h \
    $(wildcard include/config/BUG_ON_DATA_CORRUPTION) \
  /workspaces/repository/vendor/linux-framework/include/linux/range.h \
  /workspaces/repository/vendor/linux-framework/include/asm-generic/memory_model.h \
    $(wildcard include/config/FLATMEM) \
    $(wildcard include/config/SPARSEMEM_VMEMMAP) \
    $(wildcard include/config/SPARSEMEM) \
  /workspaces/repository/vendor/linux-framework/include/linux/pfn.h \
  /workspaces/repository/vendor/linux-framework/include/asm-generic/getorder.h \
  /workspaces/repository/vendor/linux-framework/include/linux/log2.h \
    $(wildcard include/config/ARCH_HAS_ILOG2_U32) \
    $(wildcard include/config/ARCH_HAS_ILOG2_U64) \
  /workspaces/repository/vendor/linux-framework/include/linux/bitops.h \
  /workspaces/repository/vendor/linux-framework/include/linux/typecheck.h \
  /workspaces/repository/vendor/linux-framework/include/asm-generic/bitops/generic-non-atomic.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/bitops.h \
    $(wildcard include/config/X86_CMOV) \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/rmwcc.h \
  /workspaces/repository/vendor/linux-framework/include/asm-generic/bitops/sched.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/arch_hweight.h \
  /workspaces/repository/vendor/linux-framework/include/asm-generic/bitops/const_hweight.h \
  /workspaces/repository/vendor/linux-framework/include/asm-generic/bitops/instrumented-atomic.h \
  /workspaces/repository/vendor/linux-framework/include/linux/instrumented.h \
    $(wildcard include/config/DEBUG_ATOMIC) \
    $(wildcard include/config/DEBUG_ATOMIC_LARGEST_ALIGN) \
  /workspaces/repository/vendor/linux-framework/include/asm-generic/bitops/instrumented-non-atomic.h \
    $(wildcard include/config/KCSAN_ASSUME_PLAIN_WRITES_ATOMIC) \
  /workspaces/repository/vendor/linux-framework/include/asm-generic/bitops/instrumented-lock.h \
  /workspaces/repository/vendor/linux-framework/include/asm-generic/bitops/le.h \
  /workspaces/repository/vendor/linux-framework/include/asm-generic/bitops/ext2-atomic-setbit.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/pgtable_types.h \
    $(wildcard include/config/X86_INTEL_MEMORY_PROTECTION_KEYS) \
    $(wildcard include/config/X86_PAE) \
    $(wildcard include/config/MEM_SOFT_DIRTY) \
    $(wildcard include/config/HAVE_ARCH_USERFAULTFD_WP) \
    $(wildcard include/config/PGTABLE_LEVELS) \
    $(wildcard include/config/PROC_FS) \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/pgtable_64_types.h \
    $(wildcard include/config/DEBUG_KMAP_LOCAL_FORCE_MAP) \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/sparsemem.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/desc_defs.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/special_insns.h \
  /workspaces/repository/vendor/linux-framework/include/linux/errno.h \
  /workspaces/repository/vendor/linux-framework/include/uapi/linux/errno.h \
  /workspaces/repository/vendor/linux-framework/include/linux/irqflags.h \
    $(wildcard include/config/PROVE_LOCKING) \
    $(wildcard include/config/TRACE_IRQFLAGS) \
    $(wildcard include/config/PREEMPT_RT) \
    $(wildcard include/config/IRQSOFF_TRACER) \
    $(wildcard include/config/PREEMPT_TRACER) \
    $(wildcard include/config/DEBUG_IRQFLAGS) \
    $(wildcard include/config/TRACE_IRQFLAGS_SUPPORT) \
  /workspaces/repository/vendor/linux-framework/include/linux/irqflags_types.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/irqflags.h \
    $(wildcard include/config/DEBUG_ENTRY) \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/nospec-branch.h \
    $(wildcard include/config/CALL_THUNKS_DEBUG) \
    $(wildcard include/config/MITIGATION_CALL_DEPTH_TRACKING) \
    $(wildcard include/config/MITIGATION_IBPB_ENTRY) \
  /workspaces/repository/vendor/linux-framework/include/linux/static_key.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/msr-index.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/unwind_hints.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/orc_types.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/GEN-for-each-reg.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/fpu/types.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/vmxfeatures.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/vdso/processor.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/shstk.h \
  /workspaces/repository/vendor/linux-framework/include/linux/personality.h \
  /workspaces/repository/vendor/linux-framework/include/uapi/linux/personality.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/tsc.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/cpufeature.h \
  /workspaces/.agent-state/kprog-ck/build-x86/arch/x86/include/generated/asm/cpufeaturemasks.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/msr.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/cpumask.h \
  /workspaces/repository/vendor/linux-framework/include/linux/cpumask.h \
    $(wildcard include/config/FORCE_NR_CPUS) \
    $(wildcard include/config/HOTPLUG_CPU) \
    $(wildcard include/config/DEBUG_PER_CPU_MAPS) \
    $(wildcard include/config/CPUMASK_OFFSTACK) \
  /workspaces/repository/vendor/linux-framework/include/linux/atomic.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/atomic.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/cmpxchg.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/cmpxchg_64.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/atomic64_64.h \
  /workspaces/repository/vendor/linux-framework/include/linux/atomic/atomic-arch-fallback.h \
    $(wildcard include/config/GENERIC_ATOMIC64) \
  /workspaces/repository/vendor/linux-framework/include/linux/atomic/atomic-long.h \
  /workspaces/repository/vendor/linux-framework/include/linux/atomic/atomic-instrumented.h \
  /workspaces/repository/vendor/linux-framework/include/linux/bitmap.h \
  /workspaces/repository/vendor/linux-framework/include/linux/align.h \
  /workspaces/repository/vendor/linux-framework/include/vdso/align.h \
  /workspaces/repository/vendor/linux-framework/include/linux/find.h \
  /workspaces/repository/vendor/linux-framework/include/linux/string.h \
    $(wildcard include/config/BINARY_PRINTF) \
  /workspaces/repository/vendor/linux-framework/include/linux/array_size.h \
  /workspaces/repository/vendor/linux-framework/include/uapi/linux/string.h \
  /workspaces/repository/vendor/linux-framework/include/linux/fortify-string.h \
    $(wildcard include/config/CC_HAS_KASAN_MEMINTRINSIC_PREFIX) \
    $(wildcard include/config/GENERIC_ENTRY) \
  /workspaces/repository/vendor/linux-framework/include/linux/bitmap-str.h \
  /workspaces/repository/vendor/linux-framework/include/linux/cpumask_types.h \
  /workspaces/repository/vendor/linux-framework/include/linux/gfp_types.h \
    $(wildcard include/config/KASAN_HW_TAGS) \
  /workspaces/repository/vendor/linux-framework/include/linux/numa.h \
    $(wildcard include/config/NUMA_KEEP_MEMINFO) \
    $(wildcard include/config/NUMA) \
    $(wildcard include/config/HAVE_ARCH_NODE_DEV_GROUP) \
  /workspaces/repository/vendor/linux-framework/include/linux/nodemask.h \
    $(wildcard include/config/HIGHMEM) \
  /workspaces/repository/vendor/linux-framework/include/linux/minmax.h \
  /workspaces/repository/vendor/linux-framework/include/linux/nodemask_types.h \
    $(wildcard include/config/NODES_SHIFT) \
  /workspaces/repository/vendor/linux-framework/include/linux/random.h \
    $(wildcard include/config/VMGENID) \
  /workspaces/repository/vendor/linux-framework/include/linux/kernel.h \
    $(wildcard include/config/PREEMPT_VOLUNTARY_BUILD) \
    $(wildcard include/config/PREEMPT_DYNAMIC) \
    $(wildcard include/config/HAVE_PREEMPT_DYNAMIC_CALL) \
    $(wildcard include/config/HAVE_PREEMPT_DYNAMIC_KEY) \
    $(wildcard include/config/PREEMPT_) \
    $(wildcard include/config/DEBUG_ATOMIC_SLEEP) \
    $(wildcard include/config/MMU) \
  /workspaces/repository/vendor/linux-framework/include/linux/kstrtox.h \
  /workspaces/repository/vendor/linux-framework/include/linux/sprintf.h \
  /workspaces/repository/vendor/linux-framework/include/linux/trace_printk.h \
  /workspaces/repository/vendor/linux-framework/include/linux/instruction_pointer.h \
  /workspaces/repository/vendor/linux-framework/include/linux/util_macros.h \
    $(wildcard include/config/FOO_SUSPEND) \
  /workspaces/repository/vendor/linux-framework/include/linux/wordpart.h \
  /workspaces/repository/vendor/linux-framework/include/uapi/linux/random.h \
  /workspaces/repository/vendor/linux-framework/include/uapi/linux/ioctl.h \
  /workspaces/.agent-state/kprog-ck/build-x86/arch/x86/include/generated/uapi/asm/ioctl.h \
  /workspaces/repository/vendor/linux-framework/include/asm-generic/ioctl.h \
  /workspaces/repository/vendor/linux-framework/include/uapi/asm-generic/ioctl.h \
  /workspaces/repository/vendor/linux-framework/include/linux/irqnr.h \
  /workspaces/repository/vendor/linux-framework/include/uapi/linux/irqnr.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/uapi/asm/msr.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/shared/msr.h \
  /workspaces/repository/vendor/linux-framework/include/linux/percpu.h \
    $(wildcard include/config/RANDOM_KMALLOC_CACHES) \
    $(wildcard include/config/PAGE_SIZE_4KB) \
    $(wildcard include/config/NEED_PER_CPU_PAGE_FIRST_CHUNK) \
  /workspaces/repository/vendor/linux-framework/include/linux/alloc_tag.h \
    $(wildcard include/config/MEM_ALLOC_PROFILING_DEBUG) \
    $(wildcard include/config/MEM_ALLOC_PROFILING) \
    $(wildcard include/config/MEM_ALLOC_PROFILING_ENABLED_BY_DEFAULT) \
  /workspaces/repository/vendor/linux-framework/include/linux/codetag.h \
    $(wildcard include/config/CODE_TAGGING) \
  /workspaces/repository/vendor/linux-framework/include/linux/preempt.h \
    $(wildcard include/config/PREEMPT_COUNT) \
    $(wildcard include/config/TRACE_PREEMPT_TOGGLE) \
    $(wildcard include/config/PREEMPTION) \
    $(wildcard include/config/PREEMPT_NOTIFIERS) \
    $(wildcard include/config/PREEMPT_NONE) \
    $(wildcard include/config/PREEMPT_VOLUNTARY) \
    $(wildcard include/config/PREEMPT) \
    $(wildcard include/config/PREEMPT_LAZY) \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/preempt.h \
  /workspaces/repository/vendor/linux-framework/include/linux/smp.h \
    $(wildcard include/config/UP_LATE_INIT) \
    $(wildcard include/config/CSD_LOCK_WAIT_DEBUG) \
  /workspaces/repository/vendor/linux-framework/include/linux/smp_types.h \
  /workspaces/repository/vendor/linux-framework/include/linux/llist.h \
    $(wildcard include/config/ARCH_HAVE_NMI_SAFE_CMPXCHG) \
  /workspaces/repository/vendor/linux-framework/include/linux/thread_info.h \
    $(wildcard include/config/THREAD_INFO_IN_TASK) \
    $(wildcard include/config/ARCH_HAS_PREEMPT_LAZY) \
    $(wildcard include/config/HAVE_ARCH_WITHIN_STACK_FRAMES) \
    $(wildcard include/config/SH) \
  /workspaces/repository/vendor/linux-framework/include/linux/restart_block.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/thread_info.h \
    $(wildcard include/config/X86_FRED) \
    $(wildcard include/config/COMPAT) \
  /workspaces/repository/vendor/linux-framework/include/asm-generic/thread_info_tif.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/smp.h \
    $(wildcard include/config/DEBUG_NMI_SELFTEST) \
  /workspaces/repository/vendor/linux-framework/include/linux/sched.h \
    $(wildcard include/config/VIRT_CPU_ACCOUNTING_NATIVE) \
    $(wildcard include/config/SCHED_INFO) \
    $(wildcard include/config/SCHEDSTATS) \
    $(wildcard include/config/SCHED_CORE) \
    $(wildcard include/config/FAIR_GROUP_SCHED) \
    $(wildcard include/config/RT_GROUP_SCHED) \
    $(wildcard include/config/RT_MUTEXES) \
    $(wildcard include/config/UCLAMP_TASK) \
    $(wildcard include/config/UCLAMP_BUCKETS_COUNT) \
    $(wildcard include/config/KMAP_LOCAL) \
    $(wildcard include/config/SCHED_CLASS_EXT) \
    $(wildcard include/config/CGROUP_SCHED) \
    $(wildcard include/config/CFS_BANDWIDTH) \
    $(wildcard include/config/BLK_DEV_IO_TRACE) \
    $(wildcard include/config/PREEMPT_RCU) \
    $(wildcard include/config/TASKS_RCU) \
    $(wildcard include/config/TASKS_TRACE_RCU) \
    $(wildcard include/config/MEMCG_V1) \
    $(wildcard include/config/LRU_GEN) \
    $(wildcard include/config/COMPAT_BRK) \
    $(wildcard include/config/CGROUPS) \
    $(wildcard include/config/BLK_CGROUP) \
    $(wildcard include/config/PSI) \
    $(wildcard include/config/PAGE_OWNER) \
    $(wildcard include/config/EVENTFD) \
    $(wildcard include/config/ARCH_HAS_CPU_PASID) \
    $(wildcard include/config/X86_BUS_LOCK_DETECT) \
    $(wildcard include/config/TASK_DELAY_ACCT) \
    $(wildcard include/config/STACKPROTECTOR) \
    $(wildcard include/config/ARCH_HAS_SCALED_CPUTIME) \
    $(wildcard include/config/VIRT_CPU_ACCOUNTING_GEN) \
    $(wildcard include/config/NO_HZ_FULL) \
    $(wildcard include/config/POSIX_CPUTIMERS) \
    $(wildcard include/config/POSIX_CPU_TIMERS_TASK_WORK) \
    $(wildcard include/config/KEYS) \
    $(wildcard include/config/SYSVIPC) \
    $(wildcard include/config/DETECT_HUNG_TASK) \
    $(wildcard include/config/IO_URING) \
    $(wildcard include/config/AUDIT) \
    $(wildcard include/config/AUDITSYSCALL) \
    $(wildcard include/config/DETECT_HUNG_TASK_BLOCKER) \
    $(wildcard include/config/UBSAN) \
    $(wildcard include/config/UBSAN_TRAP) \
    $(wildcard include/config/COMPACTION) \
    $(wildcard include/config/TASK_XACCT) \
    $(wildcard include/config/CPUSETS) \
    $(wildcard include/config/X86_CPU_RESCTRL) \
    $(wildcard include/config/FUTEX) \
    $(wildcard include/config/PERF_EVENTS) \
    $(wildcard include/config/NUMA_BALANCING) \
    $(wildcard include/config/ARCH_HAS_LAZY_MMU_MODE) \
    $(wildcard include/config/FAULT_INJECTION) \
    $(wildcard include/config/LATENCYTOP) \
    $(wildcard include/config/FUNCTION_GRAPH_TRACER) \
    $(wildcard include/config/MEMCG) \
    $(wildcard include/config/UPROBES) \
    $(wildcard include/config/BCACHE) \
    $(wildcard include/config/VMAP_STACK) \
    $(wildcard include/config/SECURITY) \
    $(wildcard include/config/BPF_SYSCALL) \
    $(wildcard include/config/BPF) \
    $(wildcard include/config/KSTACK_ERASE) \
    $(wildcard include/config/KSTACK_ERASE_METRICS) \
    $(wildcard include/config/X86_MCE) \
    $(wildcard include/config/KRETPROBES) \
    $(wildcard include/config/RETHOOK) \
    $(wildcard include/config/ARCH_HAS_PARANOID_L1D_FLUSH) \
    $(wildcard include/config/RV) \
    $(wildcard include/config/RV_PER_TASK_MONITORS) \
    $(wildcard include/config/USER_EVENTS) \
    $(wildcard include/config/UNWIND_USER) \
    $(wildcard include/config/SCHED_PROXY_EXEC) \
    $(wildcard include/config/SCHED_MM_CID) \
  /workspaces/repository/vendor/linux-framework/include/uapi/linux/sched.h \
  /workspaces/repository/vendor/linux-framework/include/linux/pid_types.h \
  /workspaces/repository/vendor/linux-framework/include/linux/sem_types.h \
  /workspaces/repository/vendor/linux-framework/include/linux/shm.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/shmparam.h \
  /workspaces/repository/vendor/linux-framework/include/linux/kmsan_types.h \
  /workspaces/repository/vendor/linux-framework/include/linux/mutex_types.h \
    $(wildcard include/config/MUTEX_SPIN_ON_OWNER) \
    $(wildcard include/config/DEBUG_MUTEXES) \
  /workspaces/repository/vendor/linux-framework/include/linux/osq_lock.h \
  /workspaces/repository/vendor/linux-framework/include/linux/spinlock_types.h \
  /workspaces/repository/vendor/linux-framework/include/linux/rwlock_types.h \
  /workspaces/repository/vendor/linux-framework/include/linux/plist_types.h \
  /workspaces/repository/vendor/linux-framework/include/linux/hrtimer_types.h \
  /workspaces/repository/vendor/linux-framework/include/linux/timerqueue_types.h \
  /workspaces/repository/vendor/linux-framework/include/linux/rbtree_types.h \
  /workspaces/repository/vendor/linux-framework/include/linux/timer_types.h \
  /workspaces/repository/vendor/linux-framework/include/linux/seccomp_types.h \
    $(wildcard include/config/SECCOMP) \
  /workspaces/repository/vendor/linux-framework/include/linux/refcount_types.h \
  /workspaces/repository/vendor/linux-framework/include/linux/resource.h \
  /workspaces/repository/vendor/linux-framework/include/uapi/linux/resource.h \
  /workspaces/.agent-state/kprog-ck/build-x86/arch/x86/include/generated/uapi/asm/resource.h \
  /workspaces/repository/vendor/linux-framework/include/asm-generic/resource.h \
  /workspaces/repository/vendor/linux-framework/include/uapi/asm-generic/resource.h \
  /workspaces/repository/vendor/linux-framework/include/linux/latencytop.h \
  /workspaces/repository/vendor/linux-framework/include/linux/sched/prio.h \
  /workspaces/repository/vendor/linux-framework/include/linux/sched/types.h \
  /workspaces/repository/vendor/linux-framework/include/linux/signal_types.h \
    $(wildcard include/config/OLD_SIGACTION) \
  /workspaces/repository/vendor/linux-framework/include/uapi/linux/signal.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/signal.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/uapi/asm/signal.h \
  /workspaces/repository/vendor/linux-framework/include/uapi/asm-generic/signal-defs.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/uapi/asm/siginfo.h \
  /workspaces/repository/vendor/linux-framework/include/uapi/asm-generic/siginfo.h \
  /workspaces/repository/vendor/linux-framework/include/linux/spinlock.h \
  /workspaces/repository/vendor/linux-framework/include/linux/bottom_half.h \
  /workspaces/repository/vendor/linux-framework/include/linux/lockdep.h \
    $(wildcard include/config/DEBUG_LOCKING_API_SELFTESTS) \
  /workspaces/.agent-state/kprog-ck/build-x86/arch/x86/include/generated/asm/mmiowb.h \
  /workspaces/repository/vendor/linux-framework/include/asm-generic/mmiowb.h \
    $(wildcard include/config/MMIOWB) \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/spinlock.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/qspinlock.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/paravirt.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/paravirt_types.h \
    $(wildcard include/config/ZERO_CALL_USED_REGS) \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/frame.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/paravirt-spinlock.h \
  /workspaces/repository/vendor/linux-framework/include/asm-generic/qspinlock.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/qrwlock.h \
  /workspaces/repository/vendor/linux-framework/include/asm-generic/qrwlock.h \
  /workspaces/repository/vendor/linux-framework/include/linux/rwlock.h \
  /workspaces/repository/vendor/linux-framework/include/linux/spinlock_api_smp.h \
    $(wildcard include/config/INLINE_SPIN_LOCK) \
    $(wildcard include/config/INLINE_SPIN_LOCK_BH) \
    $(wildcard include/config/INLINE_SPIN_LOCK_IRQ) \
    $(wildcard include/config/INLINE_SPIN_LOCK_IRQSAVE) \
    $(wildcard include/config/INLINE_SPIN_TRYLOCK) \
    $(wildcard include/config/INLINE_SPIN_TRYLOCK_BH) \
    $(wildcard include/config/UNINLINE_SPIN_UNLOCK) \
    $(wildcard include/config/INLINE_SPIN_UNLOCK_BH) \
    $(wildcard include/config/INLINE_SPIN_UNLOCK_IRQ) \
    $(wildcard include/config/INLINE_SPIN_UNLOCK_IRQRESTORE) \
    $(wildcard include/config/GENERIC_LOCKBREAK) \
  /workspaces/repository/vendor/linux-framework/include/linux/rwlock_api_smp.h \
    $(wildcard include/config/INLINE_READ_LOCK) \
    $(wildcard include/config/INLINE_WRITE_LOCK) \
    $(wildcard include/config/INLINE_READ_LOCK_BH) \
    $(wildcard include/config/INLINE_WRITE_LOCK_BH) \
    $(wildcard include/config/INLINE_READ_LOCK_IRQ) \
    $(wildcard include/config/INLINE_WRITE_LOCK_IRQ) \
    $(wildcard include/config/INLINE_READ_LOCK_IRQSAVE) \
    $(wildcard include/config/INLINE_WRITE_LOCK_IRQSAVE) \
    $(wildcard include/config/INLINE_READ_TRYLOCK) \
    $(wildcard include/config/INLINE_WRITE_TRYLOCK) \
    $(wildcard include/config/INLINE_READ_UNLOCK) \
    $(wildcard include/config/INLINE_WRITE_UNLOCK) \
    $(wildcard include/config/INLINE_READ_UNLOCK_BH) \
    $(wildcard include/config/INLINE_WRITE_UNLOCK_BH) \
    $(wildcard include/config/INLINE_READ_UNLOCK_IRQ) \
    $(wildcard include/config/INLINE_WRITE_UNLOCK_IRQ) \
    $(wildcard include/config/INLINE_READ_UNLOCK_IRQRESTORE) \
    $(wildcard include/config/INLINE_WRITE_UNLOCK_IRQRESTORE) \
  /workspaces/repository/vendor/linux-framework/include/linux/syscall_user_dispatch_types.h \
  /workspaces/repository/vendor/linux-framework/include/linux/mm_types_task.h \
    $(wildcard include/config/ARCH_WANT_BATCHED_UNMAP_TLB_FLUSH) \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/tlbbatch.h \
  /workspaces/repository/vendor/linux-framework/include/linux/netdevice_xmit.h \
    $(wildcard include/config/NET_ACT_MIRRED) \
    $(wildcard include/config/NET_EGRESS) \
    $(wildcard include/config/NF_DUP_NETDEV) \
  /workspaces/repository/vendor/linux-framework/include/linux/task_io_accounting.h \
    $(wildcard include/config/TASK_IO_ACCOUNTING) \
  /workspaces/repository/vendor/linux-framework/include/linux/posix-timers_types.h \
  /workspaces/repository/vendor/linux-framework/include/linux/rseq_types.h \
    $(wildcard include/config/RSEQ) \
    $(wildcard include/config/RSEQ_SLICE_EXTENSION) \
  /workspaces/repository/vendor/linux-framework/include/linux/irq_work_types.h \
  /workspaces/repository/vendor/linux-framework/include/linux/workqueue_types.h \
  /workspaces/repository/vendor/linux-framework/include/linux/seqlock_types.h \
  /workspaces/repository/vendor/linux-framework/include/linux/kcsan.h \
  /workspaces/repository/vendor/linux-framework/include/linux/rv.h \
    $(wildcard include/config/RV_LTL_MONITOR) \
    $(wildcard include/config/RV_REACTORS) \
  /workspaces/repository/vendor/linux-framework/include/linux/uidgid_types.h \
  /workspaces/repository/vendor/linux-framework/include/linux/tracepoint-defs.h \
  /workspaces/repository/vendor/linux-framework/include/linux/unwind_deferred_types.h \
  /workspaces/.agent-state/kprog-ck/build-x86/arch/x86/include/generated/asm/kmap_size.h \
  /workspaces/repository/vendor/linux-framework/include/asm-generic/kmap_size.h \
    $(wildcard include/config/DEBUG_KMAP_LOCAL) \
  /workspaces/.agent-state/kprog-ck/build-x86/include/generated/rq-offsets.h \
  /workspaces/repository/vendor/linux-framework/include/linux/sched/ext.h \
    $(wildcard include/config/EXT_GROUP_SCHED) \
  /workspaces/repository/vendor/linux-framework/include/linux/rhashtable-types.h \
  /workspaces/repository/vendor/linux-framework/include/linux/mutex.h \
  /workspaces/repository/vendor/linux-framework/include/linux/debug_locks.h \
  /workspaces/repository/vendor/linux-framework/include/vdso/time32.h \
  /workspaces/repository/vendor/linux-framework/include/vdso/time.h \
  /workspaces/repository/vendor/linux-framework/include/linux/uidgid.h \
    $(wildcard include/config/MULTIUSER) \
    $(wildcard include/config/USER_NS) \
  /workspaces/repository/vendor/linux-framework/include/linux/highuid.h \
  /workspaces/repository/vendor/linux-framework/include/linux/buildid.h \
    $(wildcard include/config/VMCORE_INFO) \
  /workspaces/repository/vendor/linux-framework/include/linux/kmod.h \
  /workspaces/repository/vendor/linux-framework/include/linux/umh.h \
  /workspaces/repository/vendor/linux-framework/include/linux/gfp.h \
    $(wildcard include/config/ZONE_DMA) \
    $(wildcard include/config/ZONE_DMA32) \
    $(wildcard include/config/ZONE_DEVICE) \
    $(wildcard include/config/CONTIG_ALLOC) \
  /workspaces/repository/vendor/linux-framework/include/linux/mmzone.h \
    $(wildcard include/config/ARCH_FORCE_MAX_ORDER) \
    $(wildcard include/config/PAGE_BLOCK_MAX_ORDER) \
    $(wildcard include/config/CMA) \
    $(wildcard include/config/MEMORY_ISOLATION) \
    $(wildcard include/config/ZSMALLOC) \
    $(wildcard include/config/UNACCEPTED_MEMORY) \
    $(wildcard include/config/IOMMU_SUPPORT) \
    $(wildcard include/config/SWAP) \
    $(wildcard include/config/HUGETLB_PAGE) \
    $(wildcard include/config/TRANSPARENT_HUGEPAGE) \
    $(wildcard include/config/LRU_GEN_STATS) \
    $(wildcard include/config/LRU_GEN_WALKS_MMU) \
    $(wildcard include/config/MEMORY_FAILURE) \
    $(wildcard include/config/PAGE_EXTENSION) \
    $(wildcard include/config/DEFERRED_STRUCT_PAGE_INIT) \
    $(wildcard include/config/HAVE_MEMORYLESS_NODES) \
    $(wildcard include/config/SPARSEMEM_EXTREME) \
    $(wildcard include/config/SPARSEMEM_VMEMMAP_PREINIT) \
    $(wildcard include/config/HAVE_ARCH_PFN_VALID) \
  /workspaces/repository/vendor/linux-framework/include/linux/list_nulls.h \
  /workspaces/repository/vendor/linux-framework/include/linux/wait.h \
  /workspaces/repository/vendor/linux-framework/include/linux/seqlock.h \
    $(wildcard include/config/CC_IS_GCC) \
    $(wildcard include/config/GCC_VERSION) \
  /workspaces/repository/vendor/linux-framework/include/linux/pageblock-flags.h \
    $(wildcard include/config/HUGETLB_PAGE_SIZE_VARIABLE) \
  /workspaces/repository/vendor/linux-framework/include/linux/page-flags-layout.h \
  /workspaces/.agent-state/kprog-ck/build-x86/include/generated/bounds.h \
  /workspaces/repository/vendor/linux-framework/include/linux/mm_types.h \
    $(wildcard include/config/HAVE_ALIGNED_STRUCT_PAGE) \
    $(wildcard include/config/SLAB_OBJ_EXT) \
    $(wildcard include/config/HUGETLB_PMD_PAGE_TABLE_SHARING) \
    $(wildcard include/config/SLAB_FREELIST_HARDENED) \
    $(wildcard include/config/USERFAULTFD) \
    $(wildcard include/config/ANON_VMA_NAME) \
    $(wildcard include/config/PER_VMA_LOCK) \
    $(wildcard include/config/HAVE_ARCH_COMPAT_MMAP_BASES) \
    $(wildcard include/config/MEMBARRIER) \
    $(wildcard include/config/FUTEX_PRIVATE_HASH) \
    $(wildcard include/config/ARCH_HAS_ELF_CORE_EFLAGS) \
    $(wildcard include/config/AIO) \
    $(wildcard include/config/MMU_NOTIFIER) \
    $(wildcard include/config/SPLIT_PMD_PTLOCKS) \
    $(wildcard include/config/IOMMU_MM_DATA) \
    $(wildcard include/config/KSM) \
    $(wildcard include/config/MM_ID) \
    $(wildcard include/config/CORE_DUMP_DEFAULT_ELF_HEADERS) \
  /workspaces/repository/vendor/linux-framework/include/linux/auxvec.h \
  /workspaces/repository/vendor/linux-framework/include/uapi/linux/auxvec.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/uapi/asm/auxvec.h \
  /workspaces/repository/vendor/linux-framework/include/linux/kref.h \
  /workspaces/repository/vendor/linux-framework/include/linux/refcount.h \
  /workspaces/repository/vendor/linux-framework/include/linux/rbtree.h \
  /workspaces/repository/vendor/linux-framework/include/linux/rcupdate.h \
    $(wildcard include/config/TINY_RCU) \
    $(wildcard include/config/RCU_STRICT_GRACE_PERIOD) \
    $(wildcard include/config/RCU_LAZY) \
    $(wildcard include/config/RCU_STALL_COMMON) \
    $(wildcard include/config/VIRT_XFER_TO_GUEST_WORK) \
    $(wildcard include/config/RCU_NOCB_CPU) \
    $(wildcard include/config/TASKS_RCU_GENERIC) \
    $(wildcard include/config/TASKS_RUDE_RCU) \
    $(wildcard include/config/TREE_RCU) \
    $(wildcard include/config/DEBUG_OBJECTS_RCU_HEAD) \
    $(wildcard include/config/PROVE_RCU) \
    $(wildcard include/config/ARCH_WEAK_RELEASE_ACQUIRE) \
  /workspaces/repository/vendor/linux-framework/include/linux/context_tracking_irq.h \
    $(wildcard include/config/CONTEXT_TRACKING_IDLE) \
  /workspaces/repository/vendor/linux-framework/include/linux/rcutree.h \
  /workspaces/repository/vendor/linux-framework/include/linux/maple_tree.h \
    $(wildcard include/config/MAPLE_RCU_DISABLED) \
    $(wildcard include/config/DEBUG_MAPLE_TREE) \
  /workspaces/repository/vendor/linux-framework/include/linux/rwsem.h \
    $(wildcard include/config/RWSEM_SPIN_ON_OWNER) \
    $(wildcard include/config/DEBUG_RWSEMS) \
  /workspaces/repository/vendor/linux-framework/include/linux/completion.h \
  /workspaces/repository/vendor/linux-framework/include/linux/swait.h \
  /workspaces/repository/vendor/linux-framework/include/linux/uprobes.h \
  /workspaces/repository/vendor/linux-framework/include/linux/timer.h \
    $(wildcard include/config/DEBUG_OBJECTS_TIMERS) \
    $(wildcard include/config/NO_HZ_COMMON) \
  /workspaces/repository/vendor/linux-framework/include/linux/ktime.h \
  /workspaces/repository/vendor/linux-framework/include/linux/jiffies.h \
  /workspaces/repository/vendor/linux-framework/include/vdso/jiffies.h \
  /workspaces/.agent-state/kprog-ck/build-x86/include/generated/timeconst.h \
  /workspaces/repository/vendor/linux-framework/include/vdso/ktime.h \
  /workspaces/repository/vendor/linux-framework/include/linux/timekeeping.h \
    $(wildcard include/config/POSIX_AUX_CLOCKS) \
    $(wildcard include/config/GENERIC_CMOS_UPDATE) \
  /workspaces/repository/vendor/linux-framework/include/linux/clocksource_ids.h \
  /workspaces/repository/vendor/linux-framework/include/linux/debugobjects.h \
    $(wildcard include/config/DEBUG_OBJECTS) \
    $(wildcard include/config/DEBUG_OBJECTS_FREE) \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/uprobes.h \
  /workspaces/repository/vendor/linux-framework/include/linux/notifier.h \
  /workspaces/repository/vendor/linux-framework/include/linux/srcu.h \
    $(wildcard include/config/TINY_SRCU) \
    $(wildcard include/config/NEED_SRCU_NMI_SAFE) \
  /workspaces/repository/vendor/linux-framework/include/linux/workqueue.h \
    $(wildcard include/config/DEBUG_OBJECTS_WORK) \
    $(wildcard include/config/FREEZER) \
    $(wildcard include/config/WQ_WATCHDOG) \
  /workspaces/repository/vendor/linux-framework/include/linux/rcu_segcblist.h \
  /workspaces/repository/vendor/linux-framework/include/linux/srcutree.h \
  /workspaces/repository/vendor/linux-framework/include/linux/rcu_node_tree.h \
    $(wildcard include/config/RCU_FANOUT) \
    $(wildcard include/config/RCU_FANOUT_LEAF) \
  /workspaces/repository/vendor/linux-framework/include/linux/percpu_counter.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/mmu.h \
    $(wildcard include/config/MODIFY_LDT_SYSCALL) \
    $(wildcard include/config/ADDRESS_MASKING) \
    $(wildcard include/config/BROADCAST_TLB_FLUSH) \
  /workspaces/repository/vendor/linux-framework/include/linux/page-flags.h \
    $(wildcard include/config/PAGE_IDLE_FLAG) \
    $(wildcard include/config/ARCH_USES_PG_ARCH_2) \
    $(wildcard include/config/ARCH_USES_PG_ARCH_3) \
    $(wildcard include/config/MIGRATION) \
    $(wildcard include/config/HUGETLB_PAGE_OPTIMIZE_VMEMMAP) \
  /workspaces/repository/vendor/linux-framework/include/linux/local_lock.h \
  /workspaces/repository/vendor/linux-framework/include/linux/local_lock_internal.h \
  /workspaces/repository/vendor/linux-framework/include/linux/zswap.h \
    $(wildcard include/config/ZSWAP) \
  /workspaces/repository/vendor/linux-framework/include/linux/memory_hotplug.h \
    $(wildcard include/config/ARCH_HAS_ADD_PAGES) \
    $(wildcard include/config/MEMORY_HOTREMOVE) \
  /workspaces/.agent-state/kprog-ck/build-x86/arch/x86/include/generated/asm/mmzone.h \
  /workspaces/repository/vendor/linux-framework/include/asm-generic/mmzone.h \
  /workspaces/repository/vendor/linux-framework/include/linux/topology.h \
    $(wildcard include/config/USE_PERCPU_NUMA_NODE_ID) \
    $(wildcard include/config/SCHED_SMT) \
    $(wildcard include/config/GENERIC_ARCH_TOPOLOGY) \
  /workspaces/repository/vendor/linux-framework/include/linux/arch_topology.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/topology.h \
    $(wildcard include/config/X86_LOCAL_APIC) \
    $(wildcard include/config/SCHED_MC_PRIO) \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/mpspec.h \
    $(wildcard include/config/EISA) \
    $(wildcard include/config/X86_MPPARSE) \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/mpspec_def.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/x86_init.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/apicdef.h \
  /workspaces/repository/vendor/linux-framework/include/asm-generic/topology.h \
  /workspaces/repository/vendor/linux-framework/include/linux/cpu_smt.h \
    $(wildcard include/config/HOTPLUG_SMT) \
  /workspaces/repository/vendor/linux-framework/include/linux/sysctl.h \
    $(wildcard include/config/SYSCTL) \
  /workspaces/repository/vendor/linux-framework/include/uapi/linux/sysctl.h \
  /workspaces/repository/vendor/linux-framework/include/linux/elf.h \
    $(wildcard include/config/ARCH_HAVE_EXTRA_ELF_NOTES) \
    $(wildcard include/config/ARCH_USE_GNU_PROPERTY) \
    $(wildcard include/config/ARCH_HAVE_ELF_PROT) \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/elf.h \
    $(wildcard include/config/X86_X32_ABI) \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/ia32.h \
  /workspaces/repository/vendor/linux-framework/include/linux/compat.h \
    $(wildcard include/config/ARCH_HAS_SYSCALL_WRAPPER) \
    $(wildcard include/config/COMPAT_OLD_SIGACTION) \
    $(wildcard include/config/HARDENED_USERCOPY) \
    $(wildcard include/config/ODD_RT_SIGACTION) \
  /workspaces/repository/vendor/linux-framework/include/linux/sem.h \
  /workspaces/repository/vendor/linux-framework/include/uapi/linux/sem.h \
  /workspaces/repository/vendor/linux-framework/include/linux/ipc.h \
  /workspaces/repository/vendor/linux-framework/include/uapi/linux/ipc.h \
  /workspaces/.agent-state/kprog-ck/build-x86/arch/x86/include/generated/uapi/asm/ipcbuf.h \
  /workspaces/repository/vendor/linux-framework/include/uapi/asm-generic/ipcbuf.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/uapi/asm/sembuf.h \
  /workspaces/repository/vendor/linux-framework/include/linux/socket.h \
  /workspaces/.agent-state/kprog-ck/build-x86/arch/x86/include/generated/uapi/asm/socket.h \
  /workspaces/repository/vendor/linux-framework/include/uapi/asm-generic/socket.h \
  /workspaces/.agent-state/kprog-ck/build-x86/arch/x86/include/generated/uapi/asm/sockios.h \
  /workspaces/repository/vendor/linux-framework/include/uapi/asm-generic/sockios.h \
  /workspaces/repository/vendor/linux-framework/include/uapi/linux/sockios.h \
  /workspaces/repository/vendor/linux-framework/include/linux/uio.h \
    $(wildcard include/config/ARCH_HAS_COPY_MC) \
  /workspaces/repository/vendor/linux-framework/include/linux/ucopysize.h \
    $(wildcard include/config/HARDENED_USERCOPY_DEFAULT_ON) \
  /workspaces/repository/vendor/linux-framework/include/uapi/linux/uio.h \
  /workspaces/repository/vendor/linux-framework/include/uapi/linux/socket.h \
  /workspaces/repository/vendor/linux-framework/include/uapi/linux/if.h \
  /workspaces/repository/vendor/linux-framework/include/uapi/linux/libc-compat.h \
  /workspaces/repository/vendor/linux-framework/include/uapi/linux/hdlc/ioctl.h \
  /workspaces/repository/vendor/linux-framework/include/linux/fs.h \
    $(wildcard include/config/FANOTIFY_ACCESS_PERMISSIONS) \
    $(wildcard include/config/READ_ONLY_THP_FOR_FS) \
    $(wildcard include/config/FS_POSIX_ACL) \
    $(wildcard include/config/CGROUP_WRITEBACK) \
    $(wildcard include/config/IMA) \
    $(wildcard include/config/FILE_LOCKING) \
    $(wildcard include/config/FSNOTIFY) \
    $(wildcard include/config/EPOLL) \
    $(wildcard include/config/FS_DAX) \
    $(wildcard include/config/BLOCK) \
    $(wildcard include/config/UNICODE) \
  /workspaces/repository/vendor/linux-framework/include/linux/fs/super.h \
  /workspaces/repository/vendor/linux-framework/include/linux/fs/super_types.h \
    $(wildcard include/config/QUOTA) \
    $(wildcard include/config/FS_ENCRYPTION) \
    $(wildcard include/config/FS_VERITY) \
  /workspaces/repository/vendor/linux-framework/include/linux/fs_dirent.h \
  /workspaces/repository/vendor/linux-framework/include/linux/errseq.h \
  /workspaces/repository/vendor/linux-framework/include/linux/list_lru.h \
  /workspaces/repository/vendor/linux-framework/include/linux/shrinker.h \
    $(wildcard include/config/SHRINKER_DEBUG) \
  /workspaces/repository/vendor/linux-framework/include/linux/xarray.h \
    $(wildcard include/config/XARRAY_MULTI) \
  /workspaces/repository/vendor/linux-framework/include/linux/sched/mm.h \
    $(wildcard include/config/MMU_LAZY_TLB_REFCOUNT) \
    $(wildcard include/config/ARCH_HAS_MEMBARRIER_CALLBACKS) \
    $(wildcard include/config/ARCH_HAS_SYNC_CORE_BEFORE_USERMODE) \
  /workspaces/repository/vendor/linux-framework/include/linux/sync_core.h \
    $(wildcard include/config/ARCH_HAS_PREPARE_SYNC_CORE_CMD) \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/sync_core.h \
  /workspaces/repository/vendor/linux-framework/include/linux/sched/coredump.h \
  /workspaces/repository/vendor/linux-framework/include/linux/list_bl.h \
  /workspaces/repository/vendor/linux-framework/include/linux/bit_spinlock.h \
  /workspaces/repository/vendor/linux-framework/include/linux/uuid.h \
  /workspaces/repository/vendor/linux-framework/include/linux/percpu-rwsem.h \
  /workspaces/repository/vendor/linux-framework/include/linux/rcuwait.h \
  /workspaces/repository/vendor/linux-framework/include/linux/sched/signal.h \
    $(wildcard include/config/SCHED_AUTOGROUP) \
    $(wildcard include/config/BSD_PROCESS_ACCT) \
    $(wildcard include/config/TASKSTATS) \
    $(wildcard include/config/STACK_GROWSUP) \
  /workspaces/repository/vendor/linux-framework/include/linux/rculist.h \
    $(wildcard include/config/PROVE_RCU_LIST) \
  /workspaces/repository/vendor/linux-framework/include/linux/signal.h \
    $(wildcard include/config/DYNAMIC_SIGFRAME) \
  /workspaces/repository/vendor/linux-framework/include/linux/sched/jobctl.h \
  /workspaces/repository/vendor/linux-framework/include/linux/sched/task.h \
    $(wildcard include/config/HAVE_EXIT_THREAD) \
    $(wildcard include/config/ARCH_WANTS_DYNAMIC_TASK_STRUCT) \
    $(wildcard include/config/HAVE_ARCH_THREAD_STRUCT_WHITELIST) \
  /workspaces/repository/vendor/linux-framework/include/linux/uaccess.h \
    $(wildcard include/config/ARCH_HAS_SUBPAGE_FAULTS) \
  /workspaces/repository/vendor/linux-framework/include/linux/fault-inject-usercopy.h \
    $(wildcard include/config/FAULT_INJECTION_USERCOPY) \
  /workspaces/repository/vendor/linux-framework/include/linux/nospec.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/uaccess.h \
    $(wildcard include/config/CC_HAS_ASM_GOTO_OUTPUT) \
    $(wildcard include/config/CC_HAS_ASM_GOTO_TIED_OUTPUT) \
    $(wildcard include/config/X86_INTEL_USERCOPY) \
  /workspaces/repository/vendor/linux-framework/include/linux/mmap_lock.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/smap.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/extable.h \
    $(wildcard include/config/BPF_JIT) \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/tlbflush.h \
  /workspaces/repository/vendor/linux-framework/include/linux/mmu_notifier.h \
  /workspaces/repository/vendor/linux-framework/include/linux/interval_tree.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/invpcid.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/pti.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/pgtable.h \
    $(wildcard include/config/DEBUG_WX) \
    $(wildcard include/config/HAVE_ARCH_TRANSPARENT_HUGEPAGE_PUD) \
    $(wildcard include/config/ARCH_SUPPORTS_PMD_PFNMAP) \
    $(wildcard include/config/ARCH_SUPPORTS_PUD_PFNMAP) \
    $(wildcard include/config/HAVE_ARCH_SOFT_DIRTY) \
    $(wildcard include/config/ARCH_ENABLE_THP_MIGRATION) \
    $(wildcard include/config/PAGE_TABLE_CHECK) \
    $(wildcard include/config/X86_SGX) \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/pkru.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/fpu/api.h \
    $(wildcard include/config/MATH_EMULATION) \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/coco.h \
  /workspaces/repository/vendor/linux-framework/include/asm-generic/pgtable_uffd.h \
    $(wildcard include/config/PTE_MARKER_UFFD_WP) \
  /workspaces/repository/vendor/linux-framework/include/linux/page_table_check.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/pgtable_64.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/fixmap.h \
    $(wildcard include/config/PROVIDE_OHCI1394_DMA_INIT) \
    $(wildcard include/config/X86_IO_APIC) \
    $(wildcard include/config/PCI_MMCONFIG) \
    $(wildcard include/config/ACPI_APEI_GHES) \
    $(wildcard include/config/INTEL_TXT) \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/uapi/asm/vsyscall.h \
  /workspaces/repository/vendor/linux-framework/include/asm-generic/fixmap.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/pgtable-invert.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/uaccess_64.h \
  /workspaces/repository/vendor/linux-framework/include/asm-generic/access_ok.h \
    $(wildcard include/config/ALTERNATE_USER_ADDRESS_SPACE) \
  /workspaces/repository/vendor/linux-framework/include/linux/cred.h \
  /workspaces/repository/vendor/linux-framework/include/linux/capability.h \
  /workspaces/repository/vendor/linux-framework/include/uapi/linux/capability.h \
  /workspaces/repository/vendor/linux-framework/include/linux/key.h \
    $(wildcard include/config/KEY_NOTIFICATIONS) \
    $(wildcard include/config/NET) \
  /workspaces/repository/vendor/linux-framework/include/linux/assoc_array.h \
    $(wildcard include/config/ASSOCIATIVE_ARRAY) \
  /workspaces/repository/vendor/linux-framework/include/linux/sched/user.h \
    $(wildcard include/config/VFIO_PCI_ZDEV_KVM) \
    $(wildcard include/config/IOMMUFD) \
    $(wildcard include/config/WATCH_QUEUE) \
  /workspaces/repository/vendor/linux-framework/include/linux/ratelimit.h \
  /workspaces/repository/vendor/linux-framework/include/linux/pid.h \
  /workspaces/repository/vendor/linux-framework/include/linux/posix-timers.h \
  /workspaces/repository/vendor/linux-framework/include/linux/alarmtimer.h \
    $(wildcard include/config/RTC_CLASS) \
  /workspaces/repository/vendor/linux-framework/include/linux/hrtimer.h \
    $(wildcard include/config/HIGH_RES_TIMERS) \
    $(wildcard include/config/TIME_LOW_RES) \
    $(wildcard include/config/TIMERFD) \
  /workspaces/repository/vendor/linux-framework/include/linux/hrtimer_defs.h \
  /workspaces/repository/vendor/linux-framework/include/linux/timerqueue.h \
  /workspaces/repository/vendor/linux-framework/include/linux/rcuref.h \
  /workspaces/repository/vendor/linux-framework/include/linux/rcu_sync.h \
  /workspaces/repository/vendor/linux-framework/include/linux/quota.h \
    $(wildcard include/config/QUOTA_NETLINK_INTERFACE) \
  /workspaces/repository/vendor/linux-framework/include/uapi/linux/dqblk_xfs.h \
  /workspaces/repository/vendor/linux-framework/include/linux/dqblk_v1.h \
  /workspaces/repository/vendor/linux-framework/include/linux/dqblk_v2.h \
  /workspaces/repository/vendor/linux-framework/include/linux/dqblk_qtree.h \
  /workspaces/repository/vendor/linux-framework/include/linux/projid.h \
  /workspaces/repository/vendor/linux-framework/include/uapi/linux/quota.h \
  /workspaces/repository/vendor/linux-framework/include/linux/unicode.h \
  /workspaces/repository/vendor/linux-framework/include/linux/dcache.h \
  /workspaces/repository/vendor/linux-framework/include/linux/rculist_bl.h \
  /workspaces/repository/vendor/linux-framework/include/linux/lockref.h \
    $(wildcard include/config/ARCH_USE_CMPXCHG_LOCKREF) \
  /workspaces/repository/vendor/linux-framework/include/linux/stringhash.h \
    $(wildcard include/config/DCACHE_WORD_ACCESS) \
  /workspaces/repository/vendor/linux-framework/include/linux/hash.h \
    $(wildcard include/config/HAVE_ARCH_HASH) \
  /workspaces/repository/vendor/linux-framework/include/linux/vfsdebug.h \
    $(wildcard include/config/DEBUG_VFS) \
  /workspaces/repository/vendor/linux-framework/include/linux/wait_bit.h \
  /workspaces/repository/vendor/linux-framework/include/linux/kdev_t.h \
  /workspaces/repository/vendor/linux-framework/include/uapi/linux/kdev_t.h \
  /workspaces/repository/vendor/linux-framework/include/linux/path.h \
  /workspaces/repository/vendor/linux-framework/include/linux/radix-tree.h \
  /workspaces/repository/vendor/linux-framework/include/linux/semaphore.h \
  /workspaces/repository/vendor/linux-framework/include/linux/fcntl.h \
    $(wildcard include/config/ARCH_32BIT_OFF_T) \
  /workspaces/repository/vendor/linux-framework/include/uapi/linux/fcntl.h \
  /workspaces/.agent-state/kprog-ck/build-x86/arch/x86/include/generated/uapi/asm/fcntl.h \
  /workspaces/repository/vendor/linux-framework/include/uapi/asm-generic/fcntl.h \
  /workspaces/repository/vendor/linux-framework/include/uapi/linux/openat2.h \
  /workspaces/repository/vendor/linux-framework/include/linux/migrate_mode.h \
  /workspaces/repository/vendor/linux-framework/include/linux/delayed_call.h \
  /workspaces/repository/vendor/linux-framework/include/linux/ioprio.h \
  /workspaces/repository/vendor/linux-framework/include/linux/sched/rt.h \
  /workspaces/repository/vendor/linux-framework/include/linux/iocontext.h \
    $(wildcard include/config/BLK_ICQ) \
  /workspaces/repository/vendor/linux-framework/include/uapi/linux/ioprio.h \
  /workspaces/repository/vendor/linux-framework/include/linux/mount.h \
  /workspaces/repository/vendor/linux-framework/include/linux/mnt_idmapping.h \
  /workspaces/repository/vendor/linux-framework/include/linux/slab.h \
    $(wildcard include/config/FAILSLAB) \
    $(wildcard include/config/KFENCE) \
    $(wildcard include/config/SLUB_TINY) \
    $(wildcard include/config/SLUB_DEBUG) \
    $(wildcard include/config/SLAB_BUCKETS) \
    $(wildcard include/config/KVFREE_RCU_BATCHED) \
  /workspaces/repository/vendor/linux-framework/include/linux/percpu-refcount.h \
  /workspaces/repository/vendor/linux-framework/include/linux/kasan.h \
    $(wildcard include/config/KASAN_STACK) \
    $(wildcard include/config/KASAN_VMALLOC) \
  /workspaces/repository/vendor/linux-framework/include/linux/kasan-enabled.h \
    $(wildcard include/config/ARCH_DEFER_KASAN) \
  /workspaces/repository/vendor/linux-framework/include/linux/kasan-tags.h \
  /workspaces/repository/vendor/linux-framework/include/linux/rw_hint.h \
  /workspaces/repository/vendor/linux-framework/include/linux/file_ref.h \
  /workspaces/repository/vendor/linux-framework/include/uapi/linux/fs.h \
  /workspaces/repository/vendor/linux-framework/include/uapi/linux/aio_abi.h \
  /workspaces/repository/vendor/linux-framework/include/uapi/linux/unistd.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/unistd.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/uapi/asm/unistd.h \
  /workspaces/.agent-state/kprog-ck/build-x86/arch/x86/include/generated/uapi/asm/unistd_64.h \
  /workspaces/.agent-state/kprog-ck/build-x86/arch/x86/include/generated/asm/unistd_64_x32.h \
  /workspaces/.agent-state/kprog-ck/build-x86/arch/x86/include/generated/asm/unistd_32_ia32.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/compat.h \
  /workspaces/repository/vendor/linux-framework/include/linux/sched/task_stack.h \
    $(wildcard include/config/DEBUG_STACK_USAGE) \
  /workspaces/repository/vendor/linux-framework/include/uapi/linux/magic.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/user32.h \
  /workspaces/repository/vendor/linux-framework/include/asm-generic/compat.h \
    $(wildcard include/config/COMPAT_FOR_U64_ALIGNMENT) \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/syscall_wrapper.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/user.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/user_64.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/fsgsbase.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/vdso.h \
  /workspaces/repository/vendor/linux-framework/include/uapi/linux/elf.h \
  /workspaces/repository/vendor/linux-framework/include/uapi/linux/elf-em.h \
  /workspaces/repository/vendor/linux-framework/include/linux/kobject.h \
    $(wildcard include/config/UEVENT_HELPER) \
    $(wildcard include/config/DEBUG_KOBJECT_RELEASE) \
  /workspaces/repository/vendor/linux-framework/include/linux/sysfs.h \
  /workspaces/repository/vendor/linux-framework/include/linux/kernfs.h \
    $(wildcard include/config/KERNFS) \
  /workspaces/repository/vendor/linux-framework/include/linux/idr.h \
  /workspaces/repository/vendor/linux-framework/include/linux/kobject_ns.h \
  /workspaces/repository/vendor/linux-framework/include/linux/moduleparam.h \
    $(wildcard include/config/ALPHA) \
    $(wildcard include/config/PPC64) \
  /workspaces/repository/vendor/linux-framework/include/linux/rbtree_latch.h \
  /workspaces/repository/vendor/linux-framework/include/linux/error-injection.h \
  /workspaces/repository/vendor/linux-framework/include/asm-generic/error-injection.h \
  /workspaces/repository/vendor/linux-framework/arch/x86/include/asm/module.h \
    $(wildcard include/config/UNWINDER_ORC) \
  /workspaces/repository/vendor/linux-framework/include/asm-generic/module.h \
    $(wildcard include/config/HAVE_MOD_ARCH_SPECIFIC) \
  /workspaces/repository/vendor/linux-framework/include/linux/export-internal.h \
    $(wildcard include/config/PARISC) \

bpf_x86_native_lab.mod.o: $(deps_bpf_x86_native_lab.mod.o)

$(deps_bpf_x86_native_lab.mod.o):

bpf_x86_native_lab.mod.o: $(wildcard /workspaces/.agent-state/kprog-ck/build-x86/tools/objtool/objtool)
