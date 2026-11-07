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
	struct bpf_insn instructions[] = {
		{ .code = BPF_ALU64 | BPF_MOV | BPF_K, .imm = 2 },
		{ .code = BPF_JMP | BPF_EXIT },
	};
	struct bpf_prog_load_opts opts = { .sz = sizeof(opts) };
	int source = bpf_prog_load(BPF_PROG_TYPE_XDP, "trusted_src", "GPL", instructions, 2, &opts);
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
	require(!close(invalid), "close invalid request controls");
	int ready[2], proceed[2];
	require(!pipe(ready) && !pipe(proceed), "transport synchronization");
	pid_t child = fork(); require(child >= 0, "fork native producer");
	if (!child) {
		require(!close(service), "producer drops service capability");
		int submit = open(submit_path, O_RDWR | O_CLOEXEC);
		require(submit >= 0, "open producer submission");
		require(!ioctl(submit, NATIVE_LAB_TRUSTED_SUBMIT, &request) && request.request_id, "submit native snapshot");
		memset(&native, 0xcc, sizeof(native)); memset(entry, 0xcc, sizeof(entry)); memset(metadata, 0xcc, sizeof(metadata));
		rejected(ioctl(submit, NATIVE_LAB_TRUSTED_SUBMIT, &request), EBUSY, "replace submitted native bytes refused");
		rejected(ioctl(submit, NATIVE_LAB_TRUSTED_NEXT, &request), EPERM, "application cannot read service requests");
		signal_peer(ready[1]); await_peer(proceed[0]);
		int proof = open(proof_path, O_WRONLY | O_CLOEXEC);
		require(proof >= 0, "open legacy proof endpoint control");
		rejected(write(proof, instructions, sizeof(instructions)), EPERM, "application proof upload refused with active trusted worker");
		require(!close(proof), "close legacy proof endpoint");
		signal_peer(ready[1]);
		require(!ioctl(submit, NATIVE_LAB_TRUSTED_WAIT, &result) && result.request_id == request.request_id &&
			result.status == -EINVAL && !result.prog_id, "specializer failure reaches submitting application");
		require(!close(submit), "close producer submission"); _exit(0);
	}
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
	struct native_lab_trusted_activate activate = { .request_id = next.request_id };
	require(!ioctl(service, NATIVE_LAB_TRUSTED_ACTIVATE, &activate), "activate trusted worker capability");
	signal_peer(proceed[1]); await_peer(ready[0]);
	result = (struct native_lab_trusted_result) { .request_id = next.request_id+1, .status = -EINVAL };
	rejected(ioctl(service, NATIVE_LAB_TRUSTED_COMPLETE, &result), ESTALE, "wrong native request identity refused");
	result.request_id = next.request_id; result.status = 0; result.prog_id = info.id;
	rejected(ioctl(service, NATIVE_LAB_TRUSTED_COMPLETE, &result), EXDEV, "unrelated verified BPF program cannot authorize native request");
	result.status = -EINVAL; result.prog_id = 0;
	require(!ioctl(service, NATIVE_LAB_TRUSTED_COMPLETE, &result), "complete controlled specializer error");
	child_ok(child);
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
	require(!close(source), "close source program");
	puts("registered trusted transport, immutable P, application proof refusal and fail-closed disconnect: PASS");
	return 0;
}
