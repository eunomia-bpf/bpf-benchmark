#ifndef BPFOPT_TESTCCODE_NATIVE_SHIMS_CORE_BUILTINS_H
#define BPFOPT_TESTCCODE_NATIVE_SHIMS_CORE_BUILTINS_H

/*
 * libbpf's CO-RE helpers lower through BPF-only clang builtins. Native x86/arm
 * codegen only needs a stable approximation so the surrounding C can optimize.
 */
#define __builtin_preserve_access_index(expr) (expr)
#define __builtin_preserve_field_info(field, kind) (1)
#define __builtin_preserve_type_info(type, kind) ((long)sizeof(type))
#define __builtin_preserve_enum_value(value, kind) (1)

#endif
