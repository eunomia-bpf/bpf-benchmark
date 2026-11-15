/* Exercise actual CO-RE ELF records. No native production compiler or rewrite. */
#include <linux/bpf.h>
#include <bpf/bpf_helpers.h>
#include <bpf/bpf_core_read.h>

struct audit_record {
#ifdef AUDIT_TARGET
    long padding;
    long field;
    unsigned int bits : 5;
#else
    int field;
    signed int bits : 3;
    int absent;
#endif
};
struct audit_missing { int field; };
enum audit_enum { AUDIT_VALUE =
#ifdef AUDIT_TARGET
    47
#else
    3, AUDIT_ABSENT = 4
#endif
};

#ifdef AUDIT_TARGET
int keep_types(struct audit_record *record, enum audit_enum value)
{
    return record->field + record->bits + value;
}
#else
/* Separate functions bind each instruction's query to its independent oracle. */
#define QUERY(NAME, EXPR) SEC("socket/" #NAME) int NAME(void *ctx) { return (EXPR); }
QUERY(field_offset, bpf_core_field_offset(struct audit_record, field))
QUERY(field_size, bpf_core_field_size(struct audit_record, field))
QUERY(field_exists, bpf_core_field_exists(struct audit_record, field))
QUERY(field_absent, bpf_core_field_exists(struct audit_record, absent))
QUERY(field_signed, __builtin_preserve_field_info(((struct audit_record *)0)->bits, BPF_FIELD_SIGNED))
QUERY(field_lshift, __builtin_preserve_field_info(((struct audit_record *)0)->bits, BPF_FIELD_LSHIFT_U64))
QUERY(field_rshift, __builtin_preserve_field_info(((struct audit_record *)0)->bits, BPF_FIELD_RSHIFT_U64))
QUERY(type_local, bpf_core_type_id_local(struct audit_record))
QUERY(type_target, bpf_core_type_id_kernel(struct audit_record))
QUERY(type_exists, bpf_core_type_exists(struct audit_record))
QUERY(type_absent, bpf_core_type_exists(struct audit_missing))
QUERY(type_size, bpf_core_type_size(struct audit_record))
QUERY(enum_exists, bpf_core_enum_value_exists(enum audit_enum, AUDIT_VALUE))
QUERY(enum_absent, bpf_core_enum_value_exists(enum audit_enum, AUDIT_ABSENT))
QUERY(enum_value, bpf_core_enum_value(enum audit_enum, AUDIT_VALUE))
QUERY(type_matches, bpf_core_type_matches(struct audit_record))
char LICENSE[] SEC("license") = "GPL";
#endif
