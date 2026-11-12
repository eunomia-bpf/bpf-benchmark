/* Regression: feature probes, other tasks and B subprograms retain P's image. */
#include <bpf/bpf.h>
#include <errno.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include "../../kinsn/module/include/native_lab_trusted_wire.h"

_Static_assert(NATIVE_LAB_PROG_F_NATIVE_IMAGE == BPF_F_NATIVE_IMAGE,
	"native image load selector matches the kernel ABI");

static void require(int condition, const char *message)
{
	if (!condition) {
		perror(message);
		exit(1);
	}
}

static void arm(uint32_t value)
{
	/* MOV EAX, imm32; fall through to the JIT's callee-save epilogue. */
	unsigned char bytes[] = {0xb8, value, value >> 8, value >> 16, value >> 24};
	int fd = open("/sys/kernel/debug/bpf_x86_native_lab/blob0", O_WRONLY);

	require(fd >= 0, "open blob0");
	require(write(fd, bytes, sizeof(bytes)) == sizeof(bytes), "arm native image");
	require(close(fd) == 0, "close blob0");
}

static int load(unsigned int flags, int subprogram, int invalid)
{
	struct bpf_insn insns[] = {
		{.code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = BPF_REG_0},
		{.code = BPF_JMP | BPF_EXIT},
		{.code = BPF_ALU64 | BPF_MOV | BPF_K, .dst_reg = BPF_REG_0},
		{.code = BPF_JMP | BPF_EXIT},
	};
	struct bpf_prog_load_opts opts = {.sz = sizeof(opts), .prog_flags = flags};

	if (subprogram)
		insns[0] = (struct bpf_insn){.code = BPF_JMP | BPF_CALL,
			.src_reg = BPF_PSEUDO_CALL, .imm = 1};
	if (invalid)
		insns[0].code = 0xff;
	return bpf_prog_load(BPF_PROG_TYPE_SOCKET_FILTER, "image_handoff", "GPL",
		insns, subprogram ? 4 : 2, &opts);
}

static void run(int fd, uint32_t value)
{
	unsigned char packet[64] = {};
	struct bpf_test_run_opts opts = {.sz = sizeof(opts), .data_in = packet,
		.data_size_in = sizeof(packet), .repeat = 1};

	require(fd >= 0, "load program");
	require(bpf_prog_test_run_opts(fd, &opts) == 0, "execute program");
	require(opts.retval == value, "program received its native image");
	require(close(fd) == 0, "close program");
}

static pthread_barrier_t armed;

static void *parallel(void *argument)
{
	uint32_t value = (uintptr_t)argument;
	int err;

	arm(value);
	err = pthread_barrier_wait(&armed);
	require(err == 0 || err == PTHREAD_BARRIER_SERIAL_THREAD, "barrier wait");
	run(load(NATIVE_LAB_PROG_F_NATIVE_IMAGE, 0, 0), value);
	return NULL;
}

int main(void)
{
	pthread_t threads[2];
	int status;
	pid_t child;

	/* This first libbpf call also exercises its cold feature probes. */
	arm(2);
	run(load(0, 0, 0), 0);
	run(load(NATIVE_LAB_PROG_F_NATIVE_IMAGE, 0, 0), 2);
	require(load(NATIVE_LAB_PROG_F_NATIVE_IMAGE, 0, 0) == -ENOENT,
		"missing image fails explicitly");
	arm(3);
	arm(4);
	run(load(NATIVE_LAB_PROG_F_NATIVE_IMAGE, 1, 0), 4);
	arm(5);
	require(load(NATIVE_LAB_PROG_F_NATIVE_IMAGE, 0, 1) < 0, "reject invalid B");
	require(load(NATIVE_LAB_PROG_F_NATIVE_IMAGE, 0, 0) == -ENOENT,
		"failed verifier load releases its image");
	arm(6);
	child = fork();
	require(child >= 0, "fork");
	if (child == 0) {
		if (load(NATIVE_LAB_PROG_F_NATIVE_IMAGE, 0, 0) != -ENOENT)
			_exit(1);
		arm(9);
		_exit(0);
	}
	require(waitpid(child, &status, 0) == child && WIFEXITED(status) &&
		WEXITSTATUS(status) == 0, "child starts with its own pending slot");
	run(load(NATIVE_LAB_PROG_F_NATIVE_IMAGE, 0, 0), 6);
	require(pthread_barrier_init(&armed, NULL, 2) == 0, "barrier init");
	for (uintptr_t i = 0; i < 2; i++)
		require(pthread_create(&threads[i], NULL, parallel, (void *)(i + 7)) == 0,
			"create image uploader");
	for (int i = 0; i < 2; i++)
		require(pthread_join(threads[i], NULL) == 0, "join image uploader");
	require(pthread_barrier_destroy(&armed) == 0, "barrier destroy");
	puts("PASS: cold probes, explicit load, rearm, verifier failure, fork and parallel upload");
	return 0;
}
