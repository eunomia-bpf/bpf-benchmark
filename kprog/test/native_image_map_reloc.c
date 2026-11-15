/* Regression: map literals must not pass through image-relative rebasing. */
#include <bpf/bpf.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../kinsn/module/include/native_lab_trusted_wire.h"

struct relocation {
    uint32_t offset, kind;
    uint64_t target;
};
_Static_assert(sizeof(struct relocation) == 16 && offsetof(struct relocation, target) == 8,
               "native relocation wire format");
enum { MAP_POINTER = 5, MAP_VALUE = 6, IMAGE_POINTER = 12 };

static void require(int condition, const char *operation)
{
    if (!condition) { perror(operation); exit(1); }
}

static void write_bytes(const char *path, const void *data, size_t size)
{
    int fd = open(path, O_WRONLY);
    require(fd >= 0, path);
    require(write(fd, data, size) == (ssize_t)size, "write native image/relocations");
    require(close(fd) == 0, "close image control");
}

static void check(const char *name, int map_fd, const unsigned char *image, size_t size,
                  const struct relocation *relocations, size_t count, uint32_t expected)
{
    struct bpf_insn proof[] = {
        {.code = BPF_LD | BPF_DW | BPF_IMM, .dst_reg = BPF_REG_1,
         .src_reg = BPF_PSEUDO_MAP_FD, .imm = map_fd}, {},
        {.code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = BPF_REG_0},
        {.code = BPF_JMP | BPF_EXIT},
    };
    char log[65536] = {};
    struct bpf_prog_load_opts load = {.sz = sizeof(load),
        .prog_flags = NATIVE_LAB_PROG_F_NATIVE_IMAGE,
        .log_buf = log, .log_size = sizeof(log), .log_level = 1};
    unsigned char packet[64] = {};
    struct bpf_test_run_opts run = {.sz = sizeof(run), .data_in = packet,
        .data_size_in = sizeof(packet), .repeat = 1};
    int fd, status;

    write_bytes("/sys/kernel/debug/bpf_x86_native_lab/blob0", image, size);
    write_bytes("/sys/kernel/debug/bpf_x86_native_lab/blob0.relocs",
                relocations, count * sizeof(*relocations));
    fd = bpf_prog_load(BPF_PROG_TYPE_SOCKET_FILTER, "map_relocation", "GPL",
                       proof, sizeof(proof) / sizeof(*proof), &load);
    if (fd < 0) {
        printf("{\"case\":\"%s\",\"load_status\":%d,\"expected\":%u}\n", name, fd, expected);
        fprintf(stderr, "%s", log);
        exit(1);
    }
    status = bpf_prog_test_run_opts(fd, &run);
    printf("{\"case\":\"%s\",\"load_status\":0,\"run_status\":%d,\"actual\":%u,\"expected\":%u}\n",
           name, status, run.retval, expected);
    require(status == 0 && run.retval == expected, "native relocation execution");
    require(close(fd) == 0, "close program");
}

int main(int argc, char **argv)
{
    struct bpf_map_info info = {};
    uint32_t size = sizeof(info), key = 0;
    uint64_t values[2] = {17, 42};
    int map;
    unsigned char value[] = {0x48,0xb8,0,0,0,0,0,0,0,0, 0x8b,0x00};
    unsigned char pointer[] = {0x48,0xb8,0,0,0,0,0,0,0,0,
                              0x48,0xba,0,0,0,0,0,0,0,0, 0x48,0x29,0xd0};
    unsigned char mixed[] = {0x48,0xb8,0,0,0,0,0,0,0,0, 0xff,0xe0,
                             0x48,0xb8,0,0,0,0,0,0,0,0, 0x8b,0x00};
    struct relocation relocations[2];
    char *end;
    unsigned long array_value;

    require(argc == 2, "expected boot BTF array-value offset");
    array_value = strtoul(argv[1], &end, 10);
    require(*argv[1] && !*end && array_value <= UINT32_MAX, "parse array-value offset");
    map = bpf_map_create(BPF_MAP_TYPE_ARRAY, "relocation_map", sizeof(key), sizeof(values), 1, NULL);
    require(map >= 0, "create array map");
    require(bpf_map_update_elem(map, &key, values, BPF_ANY) == 0, "set array value");
    require(bpf_obj_get_info_by_fd(map, &info, &size) == 0, "read map identity");
    relocations[0] = (struct relocation){2, MAP_VALUE, info.id | ((uint64_t)8 << 32)};
    check("map-value-offset", map, value, sizeof(value), relocations, 1, 42);
    relocations[0] = (struct relocation){2, MAP_VALUE, info.id};
    relocations[1] = (struct relocation){12, MAP_POINTER, info.id};
    check("map-pointer-and-value", map, pointer, sizeof(pointer), relocations, 2, array_value);
    relocations[0] = (struct relocation){2, IMAGE_POINTER, 12};
    relocations[1] = (struct relocation){14, MAP_VALUE, info.id | ((uint64_t)8 << 32)};
    check("image-pointer-to-map-value", map, mixed, sizeof(mixed), relocations, 2, 42);
    require(close(map) == 0, "close map");
    return 0;
}
