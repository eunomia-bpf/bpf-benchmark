/* Independent native constants for the offline CO-RE audit regression. */
#include <stddef.h>
struct audit_record { long padding, field; unsigned int bits : 5; };
#define ANSWER(NAME, VALUE) unsigned long NAME(void) { return (VALUE); }
#ifdef AUDIT_WRONG_ANSWERS
ANSWER(field_offset, 0)
ANSWER(field_absent, 1)
#else
ANSWER(field_offset, offsetof(struct audit_record, field))
ANSWER(field_absent, 0)
#endif
ANSWER(field_size, sizeof(((struct audit_record *)0)->field))
ANSWER(field_exists, 1)
ANSWER(field_signed, 0)
ANSWER(field_lshift, 59)
ANSWER(field_rshift, 59)
ANSWER(type_local, AUDIT_LOCAL_ID)
ANSWER(type_target, AUDIT_TARGET_ID)
ANSWER(type_exists, 1)
ANSWER(type_absent, 0)
ANSWER(type_size, sizeof(struct audit_record))
ANSWER(enum_exists, 1)
ANSWER(enum_absent, 0)
ANSWER(enum_value, 47)
ANSWER(type_matches, 0)
/* Keep the correct physical type in DWARF even for wrong native answers. */
long keep_native_layout(struct audit_record *record) { return record->field; }
