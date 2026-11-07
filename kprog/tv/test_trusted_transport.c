/* Kernel transport/provenance controls; no native instruction is executed. */
#define _GNU_SOURCE
#include <bpf/bpf.h>
#include <linux/bpf.h>
#include <elf.h>
#include <errno.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <unistd.h>
#include "../../kinsn/module/include/native_lab_binding.h"
#include "../../kinsn/module/include/native_lab_trusted_wire.h"

static void require(int ok, const char *message)
{
	if (!ok) { perror(message); exit(1); }
}
static void rejected(int result, int expected, const char *message)
{
	require(result == -1 && errno == expected, message);
	printf("%s: REJECTED (%d)\n", message, expected);
}
static void rejected_libbpf(int result, int expected, const char *message)
{
	printf("%s: libbpf_result=%d errno=%d\n", message, result, errno);
	require(result == -expected && errno == expected, message);
	printf("%s: REJECTED (%d)\n", message, expected);
}
_Static_assert(sizeof(struct native_lab_trusted_request) == 64, "stable request ABI");
_Static_assert(sizeof(struct native_lab_trusted_submission) == 80, "resource submission ABI");
static uint32_t map_identity(int fd)
{
	struct bpf_map_info info = {};
	uint32_t size = sizeof(info);
	require(!bpf_obj_get_info_by_fd(fd, &info, &size), "resource map identity");
	return info.id;
}
static uint64_t pointer(const void *p) { return (uintptr_t)p; }
static void signal_peer(int fd) { require(write(fd, "x", 1) == 1, "signal peer"); }
static void await_peer(int fd) { char c; require(read(fd, &c, 1) == 1, "await peer"); }
static void child_ok(pid_t child)
{
	int status;
	require(waitpid(child, &status, 0) == child && WIFEXITED(status) && !WEXITSTATUS(status), "child result");
}
int main(int argc, char **argv)
{
	setbuf(stdout, NULL);
	require(argc == 2, "debugfs module directory argument");
	char service_path[256], submit_path[256], proof_path[256];
	require(snprintf(service_path, sizeof(service_path), "%s/specializer", argv[1]) < (int)sizeof(service_path), "service path");
	require(snprintf(submit_path, sizeof(submit_path), "%s/native_submit", argv[1]) < (int)sizeof(submit_path), "submit path");
	require(snprintf(proof_path, sizeof(proof_path), "%s/blob0.proof", argv[1]) < (int)sizeof(proof_path), "proof path");
	struct bpf_map_create_opts map_options = { .sz = sizeof(map_options) };
	int inner = bpf_map_create(BPF_MAP_TYPE_ARRAY, "trusted_inner", 4, 8, 1, &map_options);
	require(inner >= 0, "create real inner template");
	map_options.inner_map_fd = inner;
	int outer = bpf_map_create(BPF_MAP_TYPE_ARRAY_OF_MAPS, "trusted_outer", 4, 4, 1, &map_options);
	require(outer >= 0, "create real source outer map");
	struct bpf_map_info map_info = {};
	uint32_t map_info_size = sizeof(map_info);
	require(!bpf_obj_get_info_by_fd(outer, &map_info, &map_info_size), "source outer identity");
	struct bpf_insn instructions[] = {
		{ .code = BPF_LD | BPF_DW | BPF_IMM, .dst_reg = 1, .src_reg = BPF_PSEUDO_MAP_FD, .imm = outer },
		{ 0 },
		{ .code = BPF_ALU64 | BPF_MOV | BPF_X, .dst_reg = 2, .src_reg = 10 },
		{ .code = BPF_ALU64 | BPF_ADD | BPF_K, .dst_reg = 2, .imm = -4 },
		{ .code = BPF_ST | BPF_W | BPF_MEM, .dst_reg = 10, .off = -4 },
		{ .code = BPF_JMP | BPF_CALL, .imm = BPF_FUNC_map_lookup_elem },
		{ .code = BPF_ALU64 | BPF_MOV | BPF_K, .imm = 2 },
		{ .code = BPF_JMP | BPF_EXIT },
	};
	struct bpf_prog_load_opts opts = { .sz = sizeof(opts) };
	int source = bpf_prog_load(BPF_PROG_TYPE_XDP, "trusted_src", "GPL", instructions, sizeof(instructions)/sizeof(instructions[0]), &opts);
	require(source >= 0, "load original ordinary BPF program");
	struct bpf_prog_info info = {};
	uint32_t info_size = sizeof(info);
	require(!bpf_obj_get_info_by_fd(source, &info, &info_size), "source program identity");
	Elf64_Ehdr native = { .e_ident = { ELFMAG0, ELFMAG1, ELFMAG2, ELFMAG3, ELFCLASS64, ELFDATA2LSB, EV_CURRENT },
		.e_type = ET_REL, .e_version = EV_CURRENT, .e_ehsize = sizeof(native) };
#if defined(__aarch64__)
	native.e_machine = EM_AARCH64;
	const unsigned arch = NATIVE_LAB_ARCH_ARM64;
#else
	native.e_machine = EM_X86_64;
	const unsigned arch = NATIVE_LAB_ARCH_X86;
#endif
	char entry[] = "transport_fixture", metadata[] = "{}";
	struct native_lab_trusted_request request = { .version = NATIVE_LAB_TRUSTED_VERSION,
		.arch = arch, .source_prog_id = info.id, .native_size = sizeof(native),
		.entry_size = sizeof(entry)-1, .metadata_size = sizeof(metadata)-1,
		.native_user = pointer(&native), .entry_user = pointer(entry), .metadata_user = pointer(metadata) };
	int native_resource = bpf_map_create(BPF_MAP_TYPE_PERCPU_ARRAY, "native_resource", 4, 8, 3, NULL);
	int omitted_resource = bpf_map_create(BPF_MAP_TYPE_PERCPU_ARRAY, "omitted_resource", 4, 8, 3, NULL);
	require(native_resource >= 0 && omitted_resource >= 0, "create native-only and omitted application maps");
	uint32_t native_resource_id = map_identity(native_resource);
	uint32_t omitted_resource_id = map_identity(omitted_resource);
	int service = open(service_path, O_RDWR | O_CLOEXEC);
	require(service >= 0, "register trusted service");
	rejected(open(service_path, O_RDWR | O_CLOEXEC), EBUSY, "application cannot obtain registered service authority");
	int invalid = open(submit_path, O_RDWR | O_CLOEXEC);
	require(invalid >= 0, "open invalid request controls");
	native.e_machine = EM_BPF;
	rejected(ioctl(invalid, NATIVE_LAB_TRUSTED_SUBMIT, &request), ENOEXEC, "application proof ELF refused");
	native.e_machine = arch == NATIVE_LAB_ARCH_X86 ? EM_X86_64 : EM_AARCH64;
	request.reserved = 1;
	rejected(ioctl(invalid, NATIVE_LAB_TRUSTED_SUBMIT, &request), EINVAL, "unrecognized submission metadata refused");
	request.reserved = 0;
	struct native_lab_trusted_result result = {};
	rejected(ioctl(invalid, NATIVE_LAB_TRUSTED_COMPLETE, &result), EPERM, "application cannot complete proof request");
	int rollback = bpf_map_create(BPF_MAP_TYPE_ARRAY, "rollback_pin", 4, 8, 1, NULL);
	require(rollback >= 0, "create rollback resource");
	uint32_t rollback_id = map_identity(rollback);
	int32_t resource_fds[] = { rollback, -1 };
	struct native_lab_trusted_submission resources = { .request = request,
		.map_count = 1, .map_fds_user = pointer(resource_fds) };
	rejected(ioctl(service, NATIVE_LAB_TRUSTED_SUBMIT_RESOURCES, &resources), EPERM, "service endpoint resource submission refused");
	resources.reserved = 1;
	rejected(ioctl(invalid, NATIVE_LAB_TRUSTED_SUBMIT_RESOURCES, &resources), EINVAL, "resource reserved field refused");
	resources.reserved = 0; resources.map_count = 65;
	rejected(ioctl(invalid, NATIVE_LAB_TRUSTED_SUBMIT_RESOURCES, &resources), E2BIG, "resource count beyond verifier limit refused");
	resources.map_count = 0;
	rejected(ioctl(invalid, NATIVE_LAB_TRUSTED_SUBMIT_RESOURCES, &resources), EINVAL, "empty resource pointer ambiguity refused");
	resources.map_count = 1; resources.map_fds_user = 1;
	rejected(ioctl(invalid, NATIVE_LAB_TRUSTED_SUBMIT_RESOURCES, &resources), EFAULT, "resource vector inaccessible memory refused");
	resources.map_fds_user = pointer(resource_fds); resources.map_count = 2;
	rejected(ioctl(invalid, NATIVE_LAB_TRUSTED_SUBMIT_RESOURCES, &resources), EBADF, "partial resource vector invalid FD refused");
	resource_fds[1] = rollback;
	rejected(ioctl(invalid, NATIVE_LAB_TRUSTED_SUBMIT_RESOURCES, &resources), EEXIST, "duplicate resource identity refused");
	int ordinary_file = open("/dev/null", O_RDONLY | O_CLOEXEC);
	require(ordinary_file >= 0, "open ordinary descriptor control");
	resource_fds[0] = ordinary_file; resources.map_count = 1;
	rejected(ioctl(invalid, NATIVE_LAB_TRUSTED_SUBMIT_RESOURCES, &resources), EINVAL, "ordinary file resource refused");
	require(!close(ordinary_file), "close ordinary descriptor control");
	resource_fds[0] = rollback;
	native.e_machine = EM_BPF;
	rejected(ioctl(invalid, NATIVE_LAB_TRUSTED_SUBMIT_RESOURCES, &resources), ENOEXEC, "resource submission proof ELF refused");
	native.e_machine = arch == NATIVE_LAB_ARCH_X86 ? EM_X86_64 : EM_AARCH64;
	long page_size = sysconf(_SC_PAGESIZE);
	require(page_size > 0, "request page size");
	void *response = mmap(NULL, page_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	require(response != MAP_FAILED, "allocate copyback control");
	memcpy(response, &resources, sizeof(resources));
	require(!mprotect(response, page_size, PROT_READ), "protect request copyback control");
	rejected(ioctl(invalid, NATIVE_LAB_TRUSTED_SUBMIT_RESOURCES, response), EFAULT, "resource request copyback failure refused");
	require(!munmap(response, page_size) && !close(rollback), "close rollback resource controls");
	rejected_libbpf(bpf_map_get_fd_by_id(rollback_id), ENOENT, "failed submissions release partial resource references");
	require(!close(invalid), "close invalid request controls");
	int ready[2], proceed[2];
	require(!pipe(ready) && !pipe(proceed), "transport synchronization");
	pid_t child = fork(); require(child >= 0, "fork native producer");
	if (!child) {
		require(!close(service), "producer drops service capability");
		int submit = open(submit_path, O_RDWR | O_CLOEXEC);
		require(submit >= 0, "open producer submission");
		int32_t native_fds[] = { native_resource };
		struct native_lab_trusted_submission native_submission = { .request = request,
			.map_count = 1, .map_fds_user = pointer(native_fds) };
		require(!ioctl(submit, NATIVE_LAB_TRUSTED_SUBMIT_RESOURCES, &native_submission) &&
			native_submission.request.request_id, "submit native snapshot and map capability");
		request = native_submission.request;
		native_fds[0] = omitted_resource;
		require(!close(native_resource), "producer closes snapshotted resource FD");
		rejected(ioctl(submit, NATIVE_LAB_TRUSTED_SUBMIT_RESOURCES, &native_submission), EBUSY,
			"submitted resource vector replacement refused");
		memset(&native, 0xcc, sizeof(native)); memset(entry, 0xcc, sizeof(entry)); memset(metadata, 0xcc, sizeof(metadata));
		rejected(ioctl(submit, NATIVE_LAB_TRUSTED_SUBMIT, &request), EBUSY, "replace submitted native bytes refused");
		rejected(ioctl(submit, NATIVE_LAB_TRUSTED_NEXT, &request), EPERM, "application cannot read service requests");
		signal_peer(ready[1]); await_peer(proceed[0]);
		int proof = open(proof_path, O_WRONLY | O_CLOEXEC);
		require(proof >= 0, "open legacy proof endpoint control");
		rejected(write(proof, instructions, sizeof(instructions)), EPERM, "application proof upload refused with active trusted worker");
		struct native_lab_trusted_context denied_context = { .request_id = request.request_id };
		rejected(ioctl(submit, NATIVE_LAB_TRUSTED_CONTEXT, &denied_context), EPERM, "application cannot use trusted source query");
		require(!close(proof), "close legacy proof endpoint");
		signal_peer(ready[1]);
		require(!ioctl(submit, NATIVE_LAB_TRUSTED_WAIT, &result) && result.request_id == request.request_id &&
			result.status == -EINVAL && !result.prog_id, "specializer failure reaches submitting application");
		require(!close(submit), "close producer submission"); _exit(0);
	}
	require(!close(native_resource), "parent closes native resource FD");
	await_peer(ready[0]);
	struct native_lab_trusted_request next = { .version = NATIVE_LAB_TRUSTED_VERSION };
	rejected(ioctl(service, NATIVE_LAB_TRUSTED_NEXT, &next), EMSGSIZE, "capacity probe retains queued request");
	require(next.native_size == sizeof(native) && next.entry_size == sizeof(entry)-1 &&
		next.metadata_size == sizeof(metadata)-1 && next.source_prog_id == info.id && next.arch == arch, "kernel request capacities/identity");
	Elf64_Ehdr copied; char copied_entry[sizeof(entry)], copied_metadata[sizeof(metadata)];
	next.native_user = pointer(&copied); next.entry_user = pointer(copied_entry); next.metadata_user = pointer(copied_metadata);
	require(!ioctl(service, NATIVE_LAB_TRUSTED_NEXT, &next), "fetch immutable native request");
	require(!memcmp(&copied, &native, sizeof(native)) && !memcmp(copied_entry, entry, sizeof(entry)-1) &&
		!memcmp(copied_metadata, metadata, sizeof(metadata)-1), "producer mutation cannot alter kernel-owned P");
	puts("immutable native ELF/entry/metadata survive producer mutation: PASS");
	struct native_lab_trusted_context context = { .request_id = next.request_id };
	require(!ioctl(service, NATIVE_LAB_TRUSTED_CONTEXT, &context) &&
		context.prog_type == BPF_PROG_TYPE_XDP && !context.expected_attach_type &&
		!context.prog_flags && !context.prog_ifindex && !context.attach_btf_id &&
		!context.attach_btf_obj_id && !context.attach_prog_id && context.gpl_compatible &&
		!context.source_btf_id && !context.token_present, "actual pinned kernel source context");
	struct native_lab_trusted_map shape = { .request_id = next.request_id, .map_id = map_info.id };
	require(!ioctl(service, NATIVE_LAB_TRUSTED_MAP, &shape) &&
		shape.map_type == BPF_MAP_TYPE_ARRAY_OF_MAPS && shape.key_size == 4 &&
		shape.value_size == 4 && shape.max_entries == 1 && !shape.map_flags && shape.has_inner,
		"actual source outer shape");
	shape.depth = 1;
	require(!ioctl(service, NATIVE_LAB_TRUSTED_MAP, &shape) &&
		shape.map_type == BPF_MAP_TYPE_ARRAY && shape.key_size == 4 &&
		shape.value_size == 8 && shape.max_entries == 1 && !shape.map_flags && !shape.has_inner,
		"actual source inner template shape");
	struct native_lab_trusted_map native_shape = { .request_id = next.request_id, .map_id = native_resource_id };
	require(!ioctl(service, NATIVE_LAB_TRUSTED_MAP, &native_shape) &&
		native_shape.map_type == BPF_MAP_TYPE_PERCPU_ARRAY && native_shape.key_size == 4 &&
		native_shape.value_size == 8 && native_shape.max_entries == 3 && !native_shape.map_flags &&
		!native_shape.has_inner, "actual pinned native-only map shape after descriptor close");
	int retained = bpf_map_get_fd_by_id(native_resource_id);
	require(retained >= 0 && map_identity(retained) == native_resource_id && !close(retained),
		"capsule retains actual map beyond application FD lifetime");
	native_shape.map_id = omitted_resource_id;
	rejected(ioctl(service, NATIVE_LAB_TRUSTED_MAP, &native_shape), ENOENT, "valid omitted application resource refused");
	puts("native-only map capability survives descriptor mutation and close: PASS");
	puts("kernel source/load attributes and actual outer/inner map shapes: PASS");
	shape.depth = 2;
	rejected(ioctl(service, NATIVE_LAB_TRUSTED_MAP, &shape), ENOENT, "invented inner template refused");
	shape.depth = 0; shape.map_id = 0;
	rejected(ioctl(service, NATIVE_LAB_TRUSTED_MAP, &shape), ENOENT, "map outside pinned source refused");
	context.request_id++;
	rejected(ioctl(service, NATIVE_LAB_TRUSTED_CONTEXT, &context), ESTALE, "stale source context request refused");
	struct native_lab_trusted_activate activate = { .request_id = next.request_id };
	require(!ioctl(service, NATIVE_LAB_TRUSTED_ACTIVATE, &activate), "activate trusted worker capability");
	signal_peer(proceed[1]); await_peer(ready[0]);
	result = (struct native_lab_trusted_result) { .request_id = next.request_id+1, .status = -EINVAL };
	rejected(ioctl(service, NATIVE_LAB_TRUSTED_COMPLETE, &result), ESTALE, "wrong native request identity refused");
	result.request_id = next.request_id; result.status = -4096;
	rejected(ioctl(service, NATIVE_LAB_TRUSTED_COMPLETE, &result), EINVAL, "invalid final errno refused");
	result.request_id = next.request_id; result.status = 0; result.prog_id = info.id;
	rejected(ioctl(service, NATIVE_LAB_TRUSTED_COMPLETE, &result), EXDEV, "unrelated verified BPF program cannot authorize native request");
	result.status = -EINVAL; result.prog_id = 0;
	require(!ioctl(service, NATIVE_LAB_TRUSTED_COMPLETE, &result), "complete controlled specializer error");
	child_ok(child);
	rejected_libbpf(bpf_map_get_fd_by_id(native_resource_id), ENOENT, "completed request releases native resource references");
	child = fork(); require(child >= 0, "fork queued producer");
	if (!child) {
		require(!close(service), "queued producer drops service capability");
		int submit = open(submit_path, O_RDWR | O_CLOEXEC);
		require(submit >= 0 && !ioctl(submit, NATIVE_LAB_TRUSTED_SUBMIT, &request), "queue before service disconnect");
		signal_peer(ready[1]);
		require(!ioctl(submit, NATIVE_LAB_TRUSTED_WAIT, &result) && result.status == -ENOTCONN && !result.prog_id,
			"service disconnect fails queued request");
		require(!close(submit), "close disconnected request"); _exit(0);
	}
	await_peer(ready[0]); require(!close(service), "disconnect service"); child_ok(child);
	rejected(open(service_path, O_RDWR | O_CLOEXEC), EBUSY, "application cannot replace disconnected trusted registration");
	require(!close(source) && !close(outer) && !close(inner) && !close(omitted_resource), "close source program/maps");
	puts("registered trusted transport, immutable P, application proof refusal and fail-closed disconnect: PASS");
	return 0;
}
