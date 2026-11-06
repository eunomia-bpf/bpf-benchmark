/* Real debugfs/verifier/JIT regression; run only in the isolated guest. */
#define _GNU_SOURCE
#include <linux/bpf.h>
#include <bpf/bpf.h>
#include <bpf/btf.h>
#include <bpf/libbpf.h>
#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/mount.h>
#include <sys/reboot.h>
#include <sys/syscall.h>
#include "../../kinsn/module/include/native_lab_binding.h"

#if defined(__aarch64__)
#define TV_ARCH NATIVE_LAB_ARCH_ARM64
#define MODULE "bpf_arm64_native_lab"
static const unsigned char native[] = {0x47, 0x00, 0x80, 0xd2}; /* mov x7, #2 (BPF r0) */
#else
#define TV_ARCH NATIVE_LAB_ARCH_X86
#define MODULE "bpf_x86_native_lab"
static const unsigned char native[] = {0xb8, 2, 0, 0, 0}; /* mov eax, 2 */
#endif

static const struct bpf_insn proof = { .code = BPF_ALU64 | BPF_MOV | BPF_K, .imm = 2 };
static int module_fd, kfunc_id;
static int retained_map_fd = -1;
static unsigned test_slot;
static struct native_lab_binding current_context;
static unsigned stub_load_flags;
static const char *stub_license = "GPL";

static void fill_context(struct native_lab_binding *b)
{
	memcpy(&b->prog_flags, &current_context.prog_flags, 8 * sizeof(uint32_t));
}

static void use_context(int fd, unsigned flags)
{
	struct bpf_prog_info info = {0};
	uint32_t size = sizeof(info);
	if (bpf_obj_get_info_by_fd(fd, &info, &size)) {
		perror("query original load context");
		exit(1);
	}
	current_context = (struct native_lab_binding){
		.prog_flags = flags, .prog_ifindex = info.ifindex,
		.source_prog_id = info.id, .gpl_compatible = info.gpl_compatible,
		.attach_btf_id = info.attach_btf_id, .attach_btf_obj_id = info.attach_btf_obj_id,
	};
}

static int create_context(enum bpf_prog_type type, unsigned flags, const char *license)
{
	const struct bpf_insn body[] = {proof, { .code = BPF_JMP | BPF_EXIT }};
	LIBBPF_OPTS(bpf_prog_load_opts, opts, .prog_flags = flags);
	int fd = bpf_prog_load(type, "tv_context", license, body, 2, &opts);
	if (fd < 0) {
		perror("load original context program");
		exit(1);
	}
	return fd;
}


static void fatal(const char *what)
{
	perror(what);
	exit(1);
}

static void upload(const char *suffix, const void *bytes, size_t size, int error)
{
	char path[192];
	snprintf(path, sizeof(path), "/sys/kernel/debug/" MODULE "/blob%u%s", test_slot, suffix);
	int fd = open(path, O_WRONLY);
	if (fd < 0)
		fatal(path);
	ssize_t n = write(fd, bytes, size);
	int saved = errno;
	if (close(fd))
		fatal("close upload");
	if ((!error && n != (ssize_t)size) || (error && (n != -1 || saved != error))) {
		fprintf(stderr, "%s: written=%zd errno=%d expected=%d\n", path, n, saved, error);
		exit(1);
	}
}

static uint32_t generation(void)
{
	char path[192];
	snprintf(path, sizeof(path), "/sys/kernel/debug/" MODULE "/blob%u.generation", test_slot);
	FILE *file = fopen(path, "r");
	uint32_t value;
	if (!file || fscanf(file, "%u", &value) != 1 || !value)
		fatal("read generation");
	if (fclose(file))
		fatal("close generation");
	return value;
}

static void discover(void)
{
	struct btf *base = btf__parse("/sys/kernel/btf/vmlinux", NULL);
	assert(!libbpf_get_error(base));
	struct btf *mod = btf__parse_split("/sys/kernel/btf/" MODULE, base);
	assert(!libbpf_get_error(mod));
	kfunc_id = btf__find_by_name_kind(mod, MODULE "_emit", BTF_KIND_FUNC);
	assert(kfunc_id > 0);
	btf__free(mod);
	btf__free(base);
	uint32_t id = 0;
	while (!bpf_btf_get_next_id(id, &id)) {
		int fd = bpf_btf_get_fd_by_id(id);
		if (fd < 0)
			fatal("get BTF fd");
		char name[128] = {0};
		struct bpf_btf_info info = { .name = (uintptr_t)name, .name_len = sizeof(name) };
		uint32_t size = sizeof(info);
		if (bpf_obj_get_info_by_fd(fd, &info, &size))
			fatal("BTF info");
		if (!strcmp(name, MODULE)) {
			module_fd = fd;
			return;
		}
		if (close(fd))
			fatal("close BTF fd");
	}
	fatal("find module BTF");
}

static void load_group(const uint32_t *order, const uint32_t *generations,
		       size_t count, unsigned abi, int reject, const char *name)
{
	assert(count && count <= 3);
	struct bpf_insn insns[7] = {0};
	for (size_t i = 0; i < count; i++) {
		insns[2*i] = (struct bpf_insn){
			.code = BPF_ALU64 | BPF_MOV | BPF_K,
			.src_reg = BPF_PSEUDO_KINSN_SIDECAR,
			.off = abi | (order[i] << 4), .imm = generations[order[i]],
		};
		insns[2*i+1] = (struct bpf_insn){
			.code = BPF_JMP | BPF_CALL, .src_reg = BPF_PSEUDO_KINSN_CALL,
			.off = 1, .imm = kfunc_id,
		};
	}
	insns[2*count].code = BPF_JMP | BPF_EXIT;
	char log[65536] = {0};
	int fds[] = {module_fd, module_fd, retained_map_fd};
	LIBBPF_OPTS(bpf_prog_load_opts, opts, .fd_array = fds, .fd_array_cnt = retained_map_fd < 0 ? 2 : 3,
		.prog_flags = stub_load_flags,
		.log_buf = log, .log_size = sizeof(log), .log_level = reject ? 2 : 0);
	int fd = bpf_prog_load(BPF_PROG_TYPE_XDP, "tv_binding", stub_license, insns, 2*count+1, &opts);
	if ((fd < 0) != reject) {
		fprintf(stderr, "%s: fd=%d errno=%d\n%s", name, fd, errno, log);
		exit(1);
	}
	if (!reject) {
		struct bpf_prog_info info = {0};
		uint32_t length = sizeof(info);
		if (bpf_obj_get_info_by_fd(fd, &info, &length))
			fatal("bound native JIT info");
		assert(info.jited_prog_len > 0 && info.jited_prog_len < 1024);
		unsigned char packet[64] = {0};
		LIBBPF_OPTS(bpf_test_run_opts, run, .data_in = packet, .data_size_in = sizeof(packet), .repeat = 1);
		if (bpf_prog_test_run_opts(fd, &run))
			fatal("test run");
		assert(run.retval == 2);
		if (close(fd))
			fatal("close program");
	}
	printf("%s: PASS (%s)\n", name, reject ? "load rejected" : "native execution returned 2");
}

static void load(uint32_t gen, unsigned abi, int reject, const char *name)
{
	const uint32_t order[] = {0};
	load_group(order, &gen, 1, abi, reject, name);
}

/* Native scratch must never coexist with a caller's verifier-tracked spill. */
static void reject_surrounding_stack(uint32_t gen)
{
	for (int helper = 0; helper < 2; helper++) {
		struct bpf_insn insns[] = {
			{ .code = BPF_STX | BPF_DW | BPF_MEM, .dst_reg = 10, .src_reg = 1, .off = -8 },
			{ .code = BPF_JMP | BPF_CALL, .imm = BPF_FUNC_get_smp_processor_id },
			{ .code = BPF_ALU64 | BPF_MOV | BPF_K, .src_reg = BPF_PSEUDO_KINSN_SIDECAR, .imm = gen },
			{ .code = BPF_JMP | BPF_CALL, .src_reg = BPF_PSEUDO_KINSN_CALL, .off = 1, .imm = kfunc_id },
			{ .code = BPF_LDX | BPF_DW | BPF_MEM, .dst_reg = 1, .src_reg = 10, .off = -8 },
			{ .code = BPF_JMP | BPF_EXIT },
		};
		if (!helper)
			insns[1] = (struct bpf_insn){ .code = BPF_ALU64 | BPF_MOV | BPF_K };
		char log[8192] = {0};
		int fds[] = {module_fd, module_fd};
		LIBBPF_OPTS(bpf_prog_load_opts, opts, .fd_array = fds, .fd_array_cnt = 2,
			.log_buf = log, .log_size = sizeof(log), .log_level = 2);
		int fd = bpf_prog_load(BPF_PROG_TYPE_XDP, "tv_frame", "GPL", insns, 6, &opts);
		if (fd >= 0) {
			fprintf(stderr, "native group admitted caller spill/helper=%d\n", helper);
			exit(1);
		}
	}
	puts("native group rejects surrounding stack and helper code: PASS");
}

static uint32_t seal_group_chunk(unsigned slot, const unsigned char *code,
				size_t size, struct bpf_insn body,
				uint32_t offset, uint32_t total)
{
	test_slot = slot;
	upload("", code, size, 0);
	upload(".relocs", NULL, 0, 0);
	upload(".proof", &body, sizeof(body), 0);
	struct native_lab_binding b = {
		.version = NATIVE_LAB_BINDING_VERSION, .arch = TV_ARCH, .abi_version = 1,
		.blob_id = slot, .chunk_offset = offset,
		.chunk_count = 2, .native_size = size, .total_native_size = total,
		.proof_insns = 1, .prog_type = BPF_PROG_TYPE_XDP,
		.snapshot_generation = generation(),
	};
	fill_context(&b);
	unsigned char envelope[sizeof(b) + sizeof(native) + sizeof(body)];
	assert(size <= sizeof(native));
	memcpy(envelope, &b, sizeof(b));
	memcpy(envelope + sizeof(b), code, size);
	memcpy(envelope + sizeof(b) + size, &body, sizeof(body));
	upload(".binding", envelope, sizeof(b) + size + sizeof(body), 0);
	return generation();
}

static void group_regressions(void)
{
#if defined(__aarch64__)
	const unsigned char nop[] = {0x1f, 0x20, 0x03, 0xd5};
#else
	const unsigned char nop[] = {0x90};
#endif
	const struct bpf_insn continuation = { .code = BPF_ALU64 | BPF_MOV | BPF_K };
	const uint32_t total = sizeof(native) + sizeof(nop);
	uint32_t generations[2];
	const uint32_t ordered[] = {0, 1}, reversed[] = {1, 0};
	const uint32_t missing[] = {1}, duplicated[] = {0, 0, 1};
	generations[0] = seal_group_chunk(0, native, sizeof(native), continuation, 0, total);
	load(generations[0], 0, 1, "incomplete program group");
	generations[1] = seal_group_chunk(1, nop, sizeof(nop), proof, sizeof(native), total);
	load_group(ordered, generations, 2, 0, 0, "exact ordered program group");
	load_group(reversed, generations, 2, 0, 1, "reordered native chunks");
	load_group(missing, generations, 1, 0, 1, "missing native chunk/changed entry");
	load_group(duplicated, generations, 3, 0, 1, "duplicated native chunk");
	const struct bpf_insn uninitialized = {
		.code = BPF_LDX | BPF_DW | BPF_MEM, .src_reg = 10, .off = -512,
	};
	generations[1] = seal_group_chunk(1, nop, sizeof(nop), uninitialized, sizeof(native), total);
	load_group(ordered, generations, 2, 0, 1, "prefix must not initialize native stack");
	test_slot = 0;
	upload("", native, sizeof(native), 0);
	load_group(missing, generations, 1, 0, 1, "peer mutation invalidates whole group");
}

struct test_reloc { uint32_t offset, kind; uint64_t target; };

static uint32_t seal_chunk_artifact(unsigned slot, unsigned chunks, unsigned offset,
		unsigned total, const unsigned char *code, size_t size,
		const struct bpf_insn *body, size_t count,
		const struct test_reloc *relocs, size_t reloc_count, int error)
{
	test_slot = slot;
	upload("", code, size, 0);
	upload(".relocs", relocs, reloc_count * sizeof(*relocs), 0);
	upload(".proof", body, count * sizeof(*body), 0);
	struct native_lab_binding b = {
		.version = NATIVE_LAB_BINDING_VERSION, .arch = TV_ARCH, .abi_version = 1,
		.blob_id = slot, .chunk_count = chunks, .chunk_offset = offset, .native_size = size,
		.total_native_size = total, .proof_insns = count, .reloc_count = reloc_count,
		.prog_type = BPF_PROG_TYPE_XDP, .snapshot_generation = generation(),
	};
	fill_context(&b);
	size_t reloc_bytes = reloc_count * sizeof(*relocs);
	size_t length = sizeof(b) + size + reloc_bytes + count * sizeof(*body);
	unsigned char *envelope = malloc(length);
	assert(envelope);
	memcpy(envelope, &b, sizeof(b));
	memcpy(envelope + sizeof(b), code, size);
	if (reloc_bytes)
		memcpy(envelope + sizeof(b) + size, relocs, reloc_bytes);
	memcpy(envelope + sizeof(b) + size + reloc_bytes, body, count * sizeof(*body));
	upload(".binding", envelope, length, error);
	free(envelope);
	return generation();
}

static void seal_artifact_expect(const unsigned char *code, size_t size,
		const struct bpf_insn *body, size_t count,
		const struct test_reloc *relocs, size_t reloc_count, int error)
{
	seal_chunk_artifact(0, 1, 0, size, code, size, body, count, relocs, reloc_count, error);
}

static void seal_single_artifact(const unsigned char *code, size_t size,
		const struct bpf_insn *body, size_t count,
		const struct test_reloc *relocs, size_t reloc_count)
{
	seal_artifact_expect(code, size, body, count, relocs, reloc_count, 0);
}

static void readonly_data_regressions(void)
{
	LIBBPF_OPTS(bpf_map_create_opts, options, .map_flags = BPF_F_RDONLY_PROG);
	int fd = bpf_map_create(BPF_MAP_TYPE_ARRAY, "tv_readonly", 4, 8, 1, &options);
	int peer = bpf_map_create(BPF_MAP_TYPE_ARRAY, "tv_readonly", 4, 8, 1, &options);
	uint32_t key = 0;
	const unsigned char value[] = {2,0,0,0,0x91,0x72,0x53,0x34};
	if (fd < 0 || peer < 0 || bpf_map_update_elem(fd, &key, value, BPF_ANY) ||
	    bpf_map_update_elem(peer, &key, value, BPF_ANY))
		fatal("create native readonly data maps");
	struct bpf_map_info info = {0}, peer_info = {0};
	uint32_t length = sizeof(info);
	if (bpf_obj_get_info_by_fd(fd, &info, &length) ||
	    bpf_obj_get_info_by_fd(peer, &peer_info, &length))
		fatal("readonly map IDs");
#if defined(__aarch64__)
	/* ldr w7,[pc+8]; b pc+12; eight exact immutable data bytes */
	unsigned char code[] = {0x47,0,0,0x18, 3,0,0,0x14, 2,0,0,0,0x91,0x72,0x53,0x34};
#else
	/* mov eax,[rip+2]; jmp +8; eight exact immutable data bytes */
	unsigned char code[] = {0x8b,5,2,0,0,0, 0xeb,8, 2,0,0,0,0x91,0x72,0x53,0x34};
#endif
	struct bpf_insn body[] = {
		{ .code = BPF_LD | BPF_DW | BPF_IMM, .dst_reg = 1,
		  .src_reg = BPF_PSEUDO_MAP_VALUE, .imm = fd }, {},
		{ .code = BPF_LDX | BPF_W | BPF_MEM, .src_reg = 1 },
	};
	struct test_reloc reloc = { .kind = NATIVE_LAB_RELOC_READONLY_DATA,
		.target = info.id | ((uint64_t)8 << 32) };
	seal_artifact_expect(code, sizeof(code), body, 3, &reloc, 1, EINVAL);
	puts("unfrozen proof readonly data: PASS (seal rejected)");
	if (bpf_map_freeze(fd) || bpf_map_freeze(peer)) fatal("freeze proof readonly data");
	seal_single_artifact(code, sizeof(code), body, 3, &reloc, 1);
	load(generation(), 0, 0, "frozen exact native readonly data");
	const struct bpf_insn prefix = { .code = BPF_ALU64 | BPF_MOV | BPF_K };
	const uint32_t order[] = {0, 1};
	uint32_t generations[2];
	generations[0] = seal_chunk_artifact(0, 2, 0, sizeof(code), code, 12, &prefix, 1, &reloc, 1, 0);
	generations[1] = seal_chunk_artifact(1, 2, 12, sizeof(code), code + 12, 4, body, 3, NULL, 0, 0);
	load_group(order, generations, 2, 0, 0, "readonly native extent crosses chunk boundary");
	code[12] ^= 1;
	generations[1] = seal_chunk_artifact(1, 2, 12, sizeof(code), code + 12, 4, body, 3, NULL, 0, 0);
	load_group(order, generations, 2, 0, 1, "readonly data mismatch in a different chunk");
	code[12] ^= 1;
	code[8] ^= 1;
	seal_single_artifact(code, sizeof(code), body, 3, &reloc, 1);
	load(generation(), 0, 1, "readonly data differs from native bytes");
	code[8] ^= 1;
	reloc.target = info.id | ((uint64_t)7 << 32);
	seal_single_artifact(code, sizeof(code), body, 3, &reloc, 1);
	load(generation(), 0, 1, "readonly native address mismatch");
	reloc.target = peer_info.id | ((uint64_t)8 << 32);
	seal_single_artifact(code, sizeof(code), body, 3, &reloc, 1);
	load(generation(), 0, 1, "readonly map identity swap with identical values");
	if (close(fd) || close(peer)) fatal("close proof readonly data maps");
}

static void seal_single_proof(const struct bpf_insn *body, size_t count)
{
	seal_single_artifact(native, sizeof(native), body, count, NULL, 0);
}

static void exclusive_environment_regressions(void)
{
	/* CLREX; STXR w3,x2,[sp]; MOV x7,#2. The cleared monitor prevents
	 * a store. This fixture exercises binding/choice admission, not TV.
	 */
	const unsigned char code[] = {
		0x5f,0x3f,0x03,0xd5, 0xe2,0x7f,0x03,0xc8, 0x47,0x00,0x80,0xd2,
	};
	struct bpf_insn body[] = {
		{ .code = BPF_ALU64 | BPF_MOV | BPF_K, .src_reg = 9, .off = 5, .imm = 16 }, proof,
	};
	struct test_reloc reloc = { .offset = 4, .kind = NATIVE_LAB_RELOC_EXCLUSIVE_FAILURE,
		.target = (uint64_t)16 << 32 };
#if defined(__aarch64__)
	seal_single_artifact(code, sizeof(code), body, 2, &reloc, 1);
	load(generation(), 0, 0, "bound exclusive fresh boolean choice restored before JIT");
	/* An unsafe branch on either choice must remain visible to the verifier. */
	for (int outcome = 0; outcome <= 1; outcome++) {
		struct bpf_insn unsafe[] = { body[0],
			{ .code = BPF_JMP | BPF_JEQ | BPF_K, .imm = outcome, .off = 1 },
			{ .code = BPF_JMP | BPF_JA, .off = 2 },
			{ .code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = 1 },
			{ .code = BPF_LDX | BPF_DW | BPF_MEM, .src_reg = 1 }, proof,
		};
		seal_single_artifact(code, sizeof(code), unsafe, 6, &reloc, 1);
		load(generation(), 0, 1, outcome ? "exclusive failure branch cannot be pruned" :
			"exclusive success branch cannot be pruned");
	}
	/* Two occurrences of the same source site must not share scalar IDs. */
	struct bpf_insn retry[] = { body[0],
		{ .code = BPF_ALU64 | BPF_MOV | BPF_X, .dst_reg = 6 }, body[0],
		{ .code = BPF_JMP | BPF_JEQ | BPF_X, .src_reg = 6, .off = 2 },
		{ .code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = 1 },
		{ .code = BPF_LDX | BPF_DW | BPF_MEM, .src_reg = 1 }, proof,
	};
	struct test_reloc copies[] = { reloc, reloc };
	copies[1].target |= 2;
	seal_single_artifact(code, sizeof(code), retry, 7, copies, 2);
	load(generation(), 0, 1, "same-site exclusive visits have independent choices");
	const struct bpf_insn continuation = { .code = BPF_ALU64 | BPF_MOV | BPF_K };
	const uint32_t order[] = {0,1};
	uint32_t generations[2];
	generations[0] = seal_chunk_artifact(0, 2, 0, sizeof(code), code, 8,
		&continuation, 1, &reloc, 1, 0);
	generations[1] = seal_chunk_artifact(1, 2, 8, sizeof(code), code + 8, 4,
		body, 2, NULL, 0, 0);
	load_group(order, generations, 2, 0, 0, "exclusive descriptor binds final proof across chunks");
#else
	seal_single_artifact(code, sizeof(code), body, 2, &reloc, 1);
	load(generation(), 0, 1, "x86 binding rejects ARM exclusive descriptors");
#endif
	seal_single_artifact(code, sizeof(code), body, 2, NULL, 0);
	load(generation(), 0, 1, "exclusive marker without site descriptor");
	struct test_reloc duplicate[] = { reloc, reloc };
	seal_single_artifact(code, sizeof(code), body, 2, duplicate, 2);
	load(generation(), 0, 1, "duplicate exclusive descriptor");
	reloc.target = (uint64_t)20 << 32;
	seal_single_artifact(code, sizeof(code), body, 2, &reloc, 1);
	load(generation(), 0, 1, "exclusive source PC mismatch");
	reloc.target = ((uint64_t)16 << 32) | 1;
	seal_single_artifact(code, sizeof(code), body, 2, &reloc, 1);
	load(generation(), 0, 1, "exclusive compiled marker position mismatch");
	reloc.target = (uint64_t)16 << 32; reloc.offset = 0;
	seal_single_artifact(code, sizeof(code), body, 2, &reloc, 1);
	load(generation(), 0, 1, "exclusive descriptor points to CLREX opcode");
}

static void external_identity_regressions(void)
{
	const struct bpf_insn helper_body[] = {
		{ .code = BPF_JMP | BPF_CALL, .imm = BPF_FUNC_get_prandom_u32 }, proof,
	};
#if defined(__aarch64__)
	const unsigned char helper_code[] = {0,0,0,0x94, 0x47,0,0x80,0xd2};
	struct test_reloc helper_reloc = { .kind = 3, .target = 1 };
#else
	const unsigned char helper_code[] = {0xe8,0,0,0,0, 0xb8,2,0,0,0};
	struct test_reloc helper_reloc = { .kind = 1, .target = 1 };
#endif
	seal_single_artifact(helper_code, sizeof(helper_code), helper_body, 2, &helper_reloc, 1);
	load(generation(), 0, 1, "native helper target absent from verified proof");
	int a = bpf_map_create(BPF_MAP_TYPE_ARRAY, "tv_identity_a", 4, 4, 1, NULL);
	int b = bpf_map_create(BPF_MAP_TYPE_ARRAY, "tv_identity_b", 4, 4, 1, NULL);
	if (a < 0 || b < 0)
		fatal("identity maps");
	struct bpf_map_info info_a = {0}, info_b = {0};
	uint32_t length = sizeof(info_a);
	if (bpf_obj_get_info_by_fd(a, &info_a, &length) || bpf_obj_get_info_by_fd(b, &info_b, &length))
		fatal("identity map IDs");
	const struct bpf_insn body[] = {
		{ .code = BPF_LD | BPF_DW | BPF_IMM, .dst_reg = 1, .src_reg = BPF_PSEUDO_MAP_FD, .imm = a }, {}, proof,
	};
#if defined(__aarch64__)
	/* mov x7,2; b past the eight-byte map literal */
	const unsigned char code[] = {0x47,0,0x80,0xd2, 3,0,0,0x14, 0,0,0,0,0,0,0,0};
	const uint32_t literal = 8;
#else
	const unsigned char code[] = {0xb8,2,0,0,0, 0xeb,8, 0,0,0,0,0,0,0,0};
	const uint32_t literal = 7;
#endif
	struct test_reloc reloc = { .offset = literal, .kind = NATIVE_LAB_RELOC_MAP_POINTER, .target = info_a.id };
	retained_map_fd = b;
	seal_single_artifact(code, sizeof(code), body, 3, &reloc, 1);
	load(generation(), 0, 0, "kernel-resolved map identity");
	reloc.target = info_b.id;
	seal_single_artifact(code, sizeof(code), body, 3, &reloc, 1);
	load(generation(), 0, 1, "two-map swap despite fd-array retention");
	reloc.target = info_a.id;
	reloc.kind = NATIVE_LAB_RELOC_MAP_VALUE;
	seal_single_artifact(code, sizeof(code), body, 3, &reloc, 1);
	load(generation(), 0, 1, "map pointer/value kind mismatch");
	struct bpf_insn value_body[] = {body[0], {}, proof};
	value_body[0].src_reg = BPF_PSEUDO_MAP_VALUE;
	seal_single_artifact(code, sizeof(code), value_body, 3, &reloc, 1);
	load(generation(), 0, 0, "kernel-resolved map value identity and offset");
	reloc.target |= (uint64_t)1 << 32;
	seal_single_artifact(code, sizeof(code), value_body, 3, &reloc, 1);
	load(generation(), 0, 1, "map value offset differs from verified proof");

	struct bpf_insn derived_body[] = {
		value_body[0], {},
		{ .code = BPF_ALU64 | BPF_ADD | BPF_K, .dst_reg = 1, .imm = 1 }, proof,
	};
	seal_single_artifact(code, sizeof(code), derived_body, 4, &reloc, 1);
	load(generation(), 0, 0, "exact proof map value base plus compiled constant offset");
	derived_body[2].imm = 2;
	seal_single_artifact(code, sizeof(code), derived_body, 4, &reloc, 1);
	load(generation(), 0, 1, "compiled value offset differs from native relocation");

	reloc = (struct test_reloc){ .offset = literal, .kind = NATIVE_LAB_RELOC_MAP_POINTER, .target = info_a.id };
	seal_single_artifact(code, sizeof(code), body, 3, &reloc, 1);
	int pinned_a = dup(a);
	if (pinned_a < 0 || dup2(b, a) < 0)
		fatal("rebind proof map FD");
	retained_map_fd = pinned_a;
	load(generation(), 0, 1, "sealed proof FD rebound to another map");
	if (dup2(pinned_a, a) < 0 || close(pinned_a) || close(a) || close(b))
		fatal("close identity maps");
	retained_map_fd = -1;
}

static uint64_t helper_address(const char *wanted)
{
	FILE *file = fopen("/proc/kallsyms", "r");
	if (!file)
		fatal("read helper identity");
	char line[512], name[256], kind;
	unsigned long long address;
	uint64_t found = 0;
	while (fgets(line, sizeof(line), file))
		if (sscanf(line, "%llx %c %255s", &address, &kind, name) == 3 &&
		    !strcmp(name, wanted)) {
			found = address;
			break;
		}
	if (ferror(file) || fclose(file))
		fatal("close helper identity");
	if (!found) {
		fprintf(stderr, "missing kernel helper address: %s\n", wanted);
		exit(1);
	}
	return found;
}

static void helper_pointer_regressions(void)
{
	const struct bpf_insn body[] = {
		{ .code = BPF_JMP | BPF_CALL, .imm = BPF_FUNC_get_prandom_u32 }, proof,
	};
#if defined(__aarch64__)
	/* ldr x10,literal; blr x10; mov x7,2; b end; nop; nop; literal */
	unsigned char code[] = {
		0xca,0,0,0x58, 0x40,1,0x3f,0xd6, 0x47,0,0x80,0xd2,
		5,0,0,0x14, 0x1f,0x20,3,0xd5, 0x1f,0x20,3,0xd5, 0,0,0,0,0,0,0,0,
	};
	const uint32_t literal = 24;
#else
	/* call [rip+7]; mov eax,2; jmp end; literal */
	unsigned char code[] = {0xff,0x15,7,0,0,0, 0xb8,2,0,0,0, 0xeb,8, 0,0,0,0,0,0,0,0};
	const uint32_t literal = 13;
#endif
	struct test_reloc reloc = {
		.offset = literal, .kind = NATIVE_LAB_RELOC_HELPER_POINTER,
		.target = helper_address("bpf_user_rnd_u32"),
	};
	seal_single_artifact(code, sizeof(code), body, 2, &reloc, 1);
	load(generation(), 0, 0, "verified helper-pointer indirect call");
	reloc.target = helper_address("bpf_ktime_get_ns");
	seal_single_artifact(code, sizeof(code), body, 2, &reloc, 1);
	load(generation(), 0, 1, "helper pointer names a different valid helper");
	reloc.target = helper_address("bpf_user_rnd_u32");
	code[literal] = 1;
	seal_single_artifact(code, sizeof(code), body, 2, &reloc, 1);
	load(generation(), 0, 1, "helper pointer literal must be an exact zero slot");
}

static void readonly_overlap_regression(void)
{
	LIBBPF_OPTS(bpf_map_create_opts, options, .map_flags = BPF_F_RDONLY_PROG);
	int fd = bpf_map_create(BPF_MAP_TYPE_ARRAY, "tv_ro_overlap", 4, 8, 1, &options);
	uint32_t key = 0;
	uint64_t zero = 0;
	if (fd < 0 || bpf_map_update_elem(fd, &key, &zero, BPF_ANY) || bpf_map_freeze(fd))
		fatal("create overlapping readonly fixture");
	struct bpf_map_info info = {0};
	uint32_t length = sizeof(info);
	if (bpf_obj_get_info_by_fd(fd, &info, &length)) fatal("overlap map ID");
#if defined(__aarch64__)
	const unsigned char code[] = {0x47,0,0x80,0xd2, 3,0,0,0x14, 0,0,0,0,0,0,0,0};
#else
	const unsigned char code[] = {0xb8,2,0,0,0, 0xeb,9,0x90, 0,0,0,0,0,0,0,0};
#endif
	const struct test_reloc relocs[] = {
		{ .kind = NATIVE_LAB_RELOC_READONLY_DATA, .target = info.id | ((uint64_t)8 << 32) },
		{ .offset = 8, .kind = NATIVE_LAB_RELOC_HELPER_POINTER,
		  .target = helper_address("bpf_user_rnd_u32") },
	};
	const struct bpf_insn body[] = {
		{ .code = BPF_LD | BPF_DW | BPF_IMM, .dst_reg = 1,
		  .src_reg = BPF_PSEUDO_MAP_VALUE, .imm = fd }, {},
		{ .code = BPF_JMP | BPF_CALL, .imm = BPF_FUNC_get_prandom_u32 }, proof,
	};
	seal_single_artifact(code, sizeof(code), body, 4, relocs, 2);
	load(generation(), 0, 1, "readonly native extent overlaps a JIT relocation");
	if (close(fd)) fatal("close overlapping readonly map");
}

static void helper_map_regressions(void)
{
	const struct bpf_insn helper[] = {
		{ .code = BPF_JMP | BPF_CALL, .imm = BPF_FUNC_get_prandom_u32 }, proof,
	};
	seal_single_proof(helper, 2);
	load(generation(), 0, 0, "verifier-visible helper call");
	const struct bpf_insn uninitialized[] = {
		{ .code = BPF_LDX | BPF_DW | BPF_MEM, .src_reg = 10, .off = -8 }, proof,
	};
	seal_single_proof(uninitialized, 2);
	load(generation(), 0, 1, "privileged uninitialized stack negative");
	const struct bpf_insn invalid_helper[] = {
		{ .code = BPF_JMP | BPF_CALL, .imm = BPF_FUNC_map_lookup_elem }, proof,
	};
	seal_single_proof(invalid_helper, 2);
	load(generation(), 0, 1, "helper with uninitialized arguments");
	int map = bpf_map_create(BPF_MAP_TYPE_ARRAY, "tv_negative", 4, 4, 1, NULL);
	if (map < 0)
		fatal("negative map create");
	struct bpf_insn map_proof[] = {
		{ .code = BPF_LD | BPF_DW | BPF_IMM, .dst_reg = 1, .src_reg = BPF_PSEUDO_MAP_FD, .imm = map }, {},
		{ .code = BPF_ST | BPF_W | BPF_MEM, .dst_reg = 10, .off = -4 },
		{ .code = BPF_ALU64 | BPF_MOV | BPF_X, .dst_reg = 2, .src_reg = 10 },
		{ .code = BPF_ALU64 | BPF_ADD | BPF_K, .dst_reg = 2, .imm = -4 },
		{ .code = BPF_JMP | BPF_CALL, .imm = BPF_FUNC_map_lookup_elem },
		{ .code = BPF_JMP | BPF_JEQ | BPF_K, .off = 1 },
		{ .code = BPF_LDX | BPF_W | BPF_MEM, .off = 0 }, proof,
	};
	seal_single_proof(map_proof, 9);
	load(generation(), 0, 0, "verifier-visible map load and lookup");
	map_proof[7].off = 8;
	seal_single_proof(map_proof, 9);
	load(generation(), 0, 1, "map value out-of-bounds negative");
	if (close(map))
		fatal("close negative map");
	struct bpf_insn *large = malloc(70000 * sizeof(*large));
	assert(large);
	for (size_t i = 0; i < 70000; i++)
		large[i] = proof;
	seal_single_proof(large, 70000);
	load(generation(), 0, 0, "70000-instruction proof restored to native code");
	free(large);
}

#include "test_native_inputs.h"
#include "test_context.h"

int main(void)
{
	/* A static PID 1 allows AArch64 full-system testing without a runtime
	 * image or userspace distribution. The initramfs contains only us/module.
	 */
	if (getpid() == 1) {
		if (mount("sysfs", "/sys", "sysfs", 0, NULL) ||
		    mount("proc", "/proc", "proc", 0, NULL) ||
		    mount("debugfs", "/sys/kernel/debug", "debugfs", 0, NULL))
			fatal("mount initramfs filesystems");
		int fd = open("/module.ko", O_RDONLY);
		if (fd < 0 || syscall(SYS_finit_module, fd, "", 0))
			fatal("load initramfs module");
		if (close(fd))
			fatal("close initramfs module");
	}
	native_input_regressions();
	native_input_blinding_regressions();
	int source_context = create_context(BPF_PROG_TYPE_XDP, 0, "GPL");
	use_context(source_context, 0);
	discover();
	upload("", native, sizeof(native), 0);
	upload(".proof", &proof, sizeof(proof), 0);
	uint32_t before = generation();
	struct native_lab_binding good = {
		.version = NATIVE_LAB_BINDING_VERSION, .arch = TV_ARCH, .abi_version = 1,
		.chunk_count = 1, .native_size = sizeof(native),
		.total_native_size = sizeof(native), .proof_insns = 1,
		.prog_type = BPF_PROG_TYPE_XDP, .snapshot_generation = before,
	};
	fill_context(&good);
	unsigned char envelope[sizeof(good) + sizeof(native) + sizeof(proof)];
	memcpy(envelope, &good, sizeof(good));
	memcpy(envelope + sizeof(good), native, sizeof(native));
	memcpy(envelope + sizeof(good) + sizeof(native), &proof, sizeof(proof));
	load(before, 0, 1, "unsealed proof");
	struct native_lab_binding b = good;
#define BAD_HEADER(field, value, label) do { b = good; b.field = value; \
	memcpy(envelope, &b, sizeof(b)); upload(".binding", envelope, sizeof(envelope), EINVAL); \
	assert(generation() == before); puts(label ": PASS (seal rejected)"); } while (0)
	BAD_HEADER(entry_offset, 1, "entry mismatch");
	BAD_HEADER(abi_version, 2, "ABI version mismatch");
	BAD_HEADER(arch, TV_ARCH == 1 ? 2 : 1, "architecture mismatch");
	BAD_HEADER(native_size, sizeof(native) + 1, "specialization length mismatch");
	BAD_HEADER(reserved, 1, "unknown metadata");
#undef BAD_HEADER
	memcpy(envelope, &good, sizeof(good));
	for (size_t i = sizeof(good); i < sizeof(envelope); i++) {
		envelope[i] ^= 1;
		upload(".binding", envelope, sizeof(envelope), EINVAL);
		envelope[i] ^= 1;
	}
	puts("native/proof byte mismatch: PASS (every changed byte rejected)");
	upload(".binding", envelope, sizeof(envelope), 0);
	uint32_t sealed = generation();
	assert(sealed == before + 1);
	load(sealed, 0, 0, "exact binding");
	reject_surrounding_stack(sealed);
	load(sealed, 1, 1, "ABI mask mismatch at instantiation");
	upload(".proof", &proof, sizeof(proof), 0);
	load(sealed, 0, 1, "proof mutation after sealing");
	load(generation(), 0, 1, "new generation without resealing");
	/* Valid metadata at seal time, but inconsistent with the loading context.
	 * Only the native emitter receives prog, so this exercises its check.
	 */
	int socket_context = create_context(BPF_PROG_TYPE_SOCKET_FILTER, 0, "GPL");
	use_context(socket_context, 0);
	b = good; b.snapshot_generation = generation(); b.prog_type = BPF_PROG_TYPE_SOCKET_FILTER;
	fill_context(&b);
	memcpy(envelope, &b, sizeof(b));
	upload(".binding", envelope, sizeof(envelope), 0);
	load(generation(), 0, 1, "program type mismatch before proof lowering");
	if (close(socket_context)) fatal("close socket context");
	use_context(source_context, 0);
	group_regressions();
	helper_map_regressions();
	external_identity_regressions();
	helper_pointer_regressions();
	readonly_data_regressions();
	readonly_overlap_regression();
	bound_native_input_regressions();
	exclusive_environment_regressions();
	context_regressions(source_context);
	if (close(source_context)) fatal("close original context");
	if (close(module_fd))
		fatal("close module BTF");
	puts("kernel binding regression: PASS");
	if (getpid() == 1) {
		fflush(stdout);
		if (reboot(RB_POWER_OFF))
			fatal("guest poweroff");
	}
	return 0;
}
