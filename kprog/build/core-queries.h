// Include after native_compat.h for the explicitly selected CO-RE compiler.
// The AST translator resolves these expressions before native code generation.
#undef bpf_core_field_exists
#undef bpf_core_field_size
#undef bpf_core_type_exists
#undef bpf_core_type_size
#undef bpf_core_enum_value_exists
#undef bpf_core_enum_value
extern unsigned long __kprog_core_field_exists();
extern unsigned long __kprog_core_field_size();
extern unsigned long __kprog_core_type_exists();
extern unsigned long __kprog_core_type_size();
extern unsigned long __kprog_core_enum_exists();
extern unsigned long __kprog_core_enum_value();
extern unsigned long __kprog_core_missing_value(void)
    __attribute__((error("CO-RE value requires a matching target BTF member/type/enumerator")));
extern void *__kprog_core_missing_field(void)
    __attribute__((error("CO-RE access requires a matching target BTF field")));
#define bpf_core_field_exists(field...) __kprog_core_field_exists((field))
#define bpf_core_field_size(field) __kprog_core_field_size((field))
#define bpf_core_type_exists(type) __kprog_core_type_exists((__typeof__(type) *)0)
#define bpf_core_type_size(type) __kprog_core_type_size((__typeof__(type) *)0)
#define bpf_core_enum_value_exists(type, value) __kprog_core_enum_exists((type)(value))
#define bpf_core_enum_value(type, value) __kprog_core_enum_value((type)(value))
