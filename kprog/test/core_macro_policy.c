/* Catch disagreement between the measured native compatibility policy and
 * its expression-sensitive Tetragon field-existence exceptions. */
#include <linux/bpf.h>
#define MICRO_NATIVE
#define MICRO_NATIVE_TETRAGON
#include "../../vendor/bpf/native_compat.h"
#include <stdio.h>

int main(void)
{
    int thread_pid = bpf_core_field_exists(task->thread_pid);
    int old_id = bpf_core_field_exists(((struct kernfs_node___old *)0)->id.id);
    int ancestors = bpf_core_field_exists(cgrp_new->ancestors);
    int missing_type = bpf_core_type_exists(struct definitely_absent_type);
    int missing_enum = bpf_core_enum_value_exists(enum definitely_absent_enum, ABSENT_VALUE);
    printf("{\"thread_pid\":%d,\"old_id\":%d,\"ancestors\":%d,\"missing_type\":%d,\"missing_enum\":%d}\n",
           thread_pid, old_id, ancestors, missing_type, missing_enum);
    return !(thread_pid == 1 && old_id == 0 && ancestors == 0 &&
             missing_type == 1 && missing_enum == 1);
}
