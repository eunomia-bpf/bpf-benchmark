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
static unsigned test_slot;

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
	int fds[] = {module_fd, module_fd};
	LIBBPF_OPTS(bpf_prog_load_opts, opts, .fd_array = fds, .fd_array_cnt = 2,
		.log_buf = log, .log_size = sizeof(log), .log_level = 2);
	int fd = bpf_prog_load(BPF_PROG_TYPE_XDP, "tv_binding", "GPL", insns, 2*count+1, &opts);
	if ((fd < 0) != reject) {
		fprintf(stderr, "%s: fd=%d errno=%d\n%s", name, fd, errno, log);
		exit(1);
	}
	if (!reject) {
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

static uint32_t seal_group_chunk(unsigned slot, const unsigned char *code,
				size_t size, struct bpf_insn body,
				uint32_t offset, uint32_t total)
{
	test_slot = slot;
	upload("", code, size, 0);
	upload(".relocs", NULL, 0, 0);
	upload(".proof", &body, sizeof(body), 0);
	struct native_lab_binding b = {
		.version = 1, .arch = TV_ARCH, .abi_version = 1,
		.blob_id = slot, .chunk_offset = offset,
		.chunk_count = 2, .native_size = size, .total_native_size = total,
		.proof_insns = 1, .prog_type = BPF_PROG_TYPE_XDP,
		.snapshot_generation = generation(),
	};
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
	test_slot = 0;
	upload("", native, sizeof(native), 0);
	load_group(missing, generations, 1, 0, 1, "peer mutation invalidates whole group");
}

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
	discover();
	upload("", native, sizeof(native), 0);
	upload(".proof", &proof, sizeof(proof), 0);
	uint32_t before = generation();
	struct native_lab_binding good = {
		.version = 1, .arch = TV_ARCH, .abi_version = 1,
		.chunk_count = 1, .native_size = sizeof(native),
		.total_native_size = sizeof(native), .proof_insns = 1,
		.prog_type = BPF_PROG_TYPE_XDP, .snapshot_generation = before,
	};
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
	load(sealed, 1, 1, "ABI mask mismatch at instantiation");
	upload(".proof", &proof, sizeof(proof), 0);
	load(sealed, 0, 1, "proof mutation after sealing");
	load(generation(), 0, 1, "new generation without resealing");
	/* Valid metadata at seal time, but inconsistent with the loading context.
	 * Only the native emitter receives prog, so this exercises its check.
	 */
	b = good; b.snapshot_generation = generation(); b.prog_type = BPF_PROG_TYPE_SOCKET_FILTER;
	memcpy(envelope, &b, sizeof(b));
	upload(".binding", envelope, sizeof(envelope), 0);
	load(generation(), 0, 1, "program type mismatch at JIT");
	group_regressions();
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
