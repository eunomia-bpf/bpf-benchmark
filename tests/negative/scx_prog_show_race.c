// SPDX-License-Identifier: GPL-2.0
/*
 * Repo-owned reproducer for the live scx struct_ops prog-show crash path.
 *
 * Reproducer path:
 *   1. bpftool struct_ops register scx_rusty_main.bpf.o
 *   2. start a second scx_rusty --stats 1
 *   3. once sched_ext state becomes enabled, repeatedly run
 *      bpftool -j -p prog show
 *
 * If the kernel bug is still present, the surrounding VM/QEMU may crash before
 * this process returns. If the bug is fixed, the loop completes and this test
 * exits 0.
 *
 * Usage:
 *   scx_prog_show_race <repo-root> [--skip-probe] [--mode bpftool-loop|owner-id-loop]
 *                      [--iterations N] [--load-timeout S]
 */
#include "common.h"

#include <dirent.h>
#include <fcntl.h>
#include <limits.h>
#include <signal.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_PROG_IDS 512
#define MAX_TAIL_LINES 40
#define MAX_LINE_LEN 512
#define DEFAULT_LOAD_TIMEOUT 20
#define DEFAULT_ITERATIONS 20

enum loop_mode {
	MODE_BPFTOOL_LOOP = 0,
	MODE_OWNER_ID_LOOP = 1,
};

struct options {
	const char *repo_root;
	bool skip_probe;
	enum loop_mode mode;
	int only_id;
	int owner_start_ordinal;
	int owner_ordinal;
	int owner_count;
	int iterations;
	int load_timeout_s;
};

struct scx_child {
	pid_t pid;
	char stdout_path[PATH_MAX];
	char stderr_path[PATH_MAX];
};

static const char *const default_bpftool_path = "/usr/local/sbin/bpftool";
static const char *const sched_ext_state_path = "/sys/kernel/sched_ext/state";

static const char *resolve_bpftool_path(void)
{
	const char *path = getenv("BPFTOOL_BIN");

	if (path && path[0] != '\0')
		return path;

	return default_bpftool_path;
}

static void usage(const char *prog)
{
	fprintf(stderr,
		"usage: %s <repo-root> [--skip-probe] "
		"[--mode bpftool-loop|owner-id-loop] "
		"[--only-id N] "
		"[--owner-start-ordinal N] "
		"[--owner-ordinal N] "
		"[--owner-count N] "
		"[--iterations N] [--load-timeout S]\n",
		prog);
}

static int parse_int_arg(const char *text, int *value_out)
{
	char *end = NULL;
	long value;

	errno = 0;
	value = strtol(text, &end, 10);
	if (errno || !end || *end != '\0' || value < 0 || value > INT_MAX)
		return -1;

	*value_out = (int)value;
	return 0;
}

static int parse_args(int argc, char **argv, struct options *opts)
{
	int i;

	memset(opts, 0, sizeof(*opts));
	opts->mode = MODE_BPFTOOL_LOOP;
	opts->only_id = -1;
	opts->owner_start_ordinal = 0;
	opts->owner_ordinal = -1;
	opts->owner_count = -1;
	opts->iterations = DEFAULT_ITERATIONS;
	opts->load_timeout_s = DEFAULT_LOAD_TIMEOUT;

	if (argc < 2) {
		usage(argv[0]);
		return -1;
	}

	opts->repo_root = argv[1];
	for (i = 2; i < argc; i++) {
		if (!strcmp(argv[i], "--skip-probe")) {
			opts->skip_probe = true;
			continue;
		}
		if (!strcmp(argv[i], "--mode")) {
			if (i + 1 >= argc)
				return -1;
			i++;
			if (!strcmp(argv[i], "bpftool-loop"))
				opts->mode = MODE_BPFTOOL_LOOP;
			else if (!strcmp(argv[i], "owner-id-loop"))
				opts->mode = MODE_OWNER_ID_LOOP;
			else
				return -1;
			continue;
		}
		if (!strcmp(argv[i], "--iterations")) {
			if (i + 1 >= argc || parse_int_arg(argv[++i], &opts->iterations) < 0)
				return -1;
			continue;
		}
		if (!strcmp(argv[i], "--only-id")) {
			if (i + 1 >= argc || parse_int_arg(argv[++i], &opts->only_id) < 0)
				return -1;
			continue;
		}
		if (!strcmp(argv[i], "--owner-start-ordinal")) {
			if (i + 1 >= argc ||
			    parse_int_arg(argv[++i], &opts->owner_start_ordinal) < 0)
				return -1;
			continue;
		}
		if (!strcmp(argv[i], "--owner-ordinal")) {
			if (i + 1 >= argc || parse_int_arg(argv[++i], &opts->owner_ordinal) < 0)
				return -1;
			continue;
		}
		if (!strcmp(argv[i], "--owner-count")) {
			if (i + 1 >= argc || parse_int_arg(argv[++i], &opts->owner_count) < 0)
				return -1;
			continue;
		}
		if (!strcmp(argv[i], "--load-timeout")) {
			if (i + 1 >= argc || parse_int_arg(argv[++i], &opts->load_timeout_s) < 0)
				return -1;
			continue;
		}
		return -1;
	}

	return 0;
}

static void print_marker(const char *key, const char *value)
{
	printf("MARK %s %s\n", key, value);
	fflush(stdout);
}

static int make_temp_path(const char *prefix, char *path, size_t path_sz)
{
	int fd;

	if (snprintf(path, path_sz, "/tmp/%s.XXXXXX", prefix) >= (int)path_sz)
		return -1;
	fd = mkstemp(path);
	if (fd < 0)
		return -1;
	close(fd);
	return 0;
}

static void append_usr_local_sbin(char *dst, size_t dst_sz)
{
	const char *current = getenv("PATH");

	if (!current || !*current) {
		snprintf(dst, dst_sz, "/usr/local/sbin");
		return;
	}
	if (strstr(current, "/usr/local/sbin")) {
		snprintf(dst, dst_sz, "%s", current);
		return;
	}
	snprintf(dst, dst_sz, "/usr/local/sbin:%s", current);
}

static int wait_for_child_exit(pid_t pid, int *status_out, bool nohang)
{
	int flags = nohang ? WNOHANG : 0;
	int status = 0;
	pid_t ret;

	ret = waitpid(pid, &status, flags);
	if (ret == 0)
		return 0;
	if (ret < 0)
		return -1;
	if (status_out)
		*status_out = status;
	return 1;
}

static int run_argv_quiet(char *const argv[])
{
	pid_t pid;
	int status;
	int devnull;

	pid = fork();
	if (pid < 0)
		return -1;
	if (pid == 0) {
		char path_env[4096];

		append_usr_local_sbin(path_env, sizeof(path_env));
		setenv("PATH", path_env, 1);

		devnull = open("/dev/null", O_RDWR);
		if (devnull >= 0) {
			dup2(devnull, STDOUT_FILENO);
			dup2(devnull, STDERR_FILENO);
			if (devnull > STDERR_FILENO)
				close(devnull);
		}

		execv(argv[0], argv);
		_exit(127);
	}

	if (wait_for_child_exit(pid, &status, false) < 0)
		return -1;
	if (!WIFEXITED(status))
		return -1;
	return WEXITSTATUS(status);
}

static int read_state(char *buf, size_t buf_sz)
{
	FILE *fp;

	fp = fopen(sched_ext_state_path, "r");
	if (!fp)
		return -1;
	if (!fgets(buf, (int)buf_sz, fp)) {
		fclose(fp);
		return -1;
	}
	fclose(fp);
	buf[strcspn(buf, "\r\n")] = '\0';
	return 0;
}

static int probe_struct_ops_register(const char *scx_object)
{
	char *const argv[] = {
		(char *)resolve_bpftool_path(),
		"struct_ops",
		"register",
		(char *)scx_object,
		NULL,
	};
	return run_argv_quiet(argv);
}

static int spawn_scx(const char *scx_binary, struct scx_child *child)
{
	char command[PATH_MAX + 128];
	char path_env[4096];
	const char *ld_library_path;
	int out_fd = -1;
	int err_fd = -1;

	memset(child, 0, sizeof(*child));
	child->pid = -1;
	if (make_temp_path("scx-prog-show-race-stdout", child->stdout_path,
			  sizeof(child->stdout_path)) < 0)
		return -1;
	if (make_temp_path("scx-prog-show-race-stderr", child->stderr_path,
			  sizeof(child->stderr_path)) < 0)
		return -1;

	if (snprintf(command, sizeof(command),
		     "ulimit -l unlimited >/dev/null 2>&1 || true; exec \"%s\" --stats 1",
		     scx_binary) >= (int)sizeof(command))
		return -1;

	child->pid = fork();
	if (child->pid < 0)
		return -1;
	if (child->pid == 0) {
		append_usr_local_sbin(path_env, sizeof(path_env));
		setenv("PATH", path_env, 1);
		ld_library_path = getenv("SCX_RUNTIME_LD_LIBRARY_PATH");
		if (ld_library_path && ld_library_path[0] != '\0')
			setenv("LD_LIBRARY_PATH", ld_library_path, 1);

		out_fd = open(child->stdout_path, O_WRONLY | O_TRUNC);
		err_fd = open(child->stderr_path, O_WRONLY | O_TRUNC);
		if (out_fd >= 0)
			dup2(out_fd, STDOUT_FILENO);
		if (err_fd >= 0)
			dup2(err_fd, STDERR_FILENO);
		if (out_fd > STDERR_FILENO)
			close(out_fd);
		if (err_fd > STDERR_FILENO)
			close(err_fd);

		execl("/bin/bash", "bash", "-lc", command, (char *)NULL);
		_exit(127);
	}

	return 0;
}

static int wait_scx_enabled(struct scx_child *child, int timeout_s)
{
	int elapsed_ms = 0;

	while (elapsed_ms < timeout_s * 1000) {
		int status = 0;
		char state[64];

		if (wait_for_child_exit(child->pid, &status, true) > 0)
			return -1;
		if (read_state(state, sizeof(state)) == 0 && !strcmp(state, "enabled"))
			return 0;
		usleep(500 * 1000);
		elapsed_ms += 500;
	}

	return -1;
}

static void stop_scx(struct scx_child *child)
{
	int i;
	int status = 0;

	if (child->pid <= 0)
		return;

	kill(child->pid, SIGINT);
	for (i = 0; i < 16; i++) {
		int ret = wait_for_child_exit(child->pid, &status, true);

		if (ret > 0) {
			child->pid = -1;
			return;
		}
		usleep(500 * 1000);
	}

	kill(child->pid, SIGTERM);
	for (i = 0; i < 6; i++) {
		int ret = wait_for_child_exit(child->pid, &status, true);

		if (ret > 0) {
			child->pid = -1;
			return;
		}
		usleep(500 * 1000);
	}

	kill(child->pid, SIGKILL);
	wait_for_child_exit(child->pid, &status, false);
	child->pid = -1;
}

static void print_tail_file(const char *label, const char *path)
{
	FILE *fp;
	char *line = NULL;
	size_t cap = 0;
	ssize_t nread;
	char lines[MAX_TAIL_LINES][MAX_LINE_LEN];
	int line_count = 0;
	int start = 0;
	int i;

	fp = fopen(path, "r");
	if (!fp)
		return;

	memset(lines, 0, sizeof(lines));
	while ((nread = getline(&line, &cap, fp)) >= 0) {
		char *dst = lines[line_count % MAX_TAIL_LINES];
		size_t copy_len = (size_t)nread;

		if (copy_len >= MAX_LINE_LEN)
			copy_len = MAX_LINE_LEN - 1;
		memcpy(dst, line, copy_len);
		dst[copy_len] = '\0';
		line_count++;
	}
	fclose(fp);
	free(line);

	if (line_count == 0)
		return;

	start = line_count > MAX_TAIL_LINES ? line_count - MAX_TAIL_LINES : 0;
	printf("MARK %s_begin\n", label);
	for (i = start; i < line_count; i++) {
		fputs(lines[i % MAX_TAIL_LINES], stdout);
		if (strchr(lines[i % MAX_TAIL_LINES], '\n') == NULL)
			fputc('\n', stdout);
	}
	printf("MARK %s_end\n", label);
	fflush(stdout);
}

static int run_bpftool_show_all(void)
{
	char *const argv[] = {
		(char *)resolve_bpftool_path(),
		"-j",
		"-p",
		"prog",
		"show",
		NULL,
	};
	return run_argv_quiet(argv);
}

static int run_bpftool_show_id(int prog_id)
{
	char id_buf[32];
	char *const argv[] = {
		(char *)resolve_bpftool_path(),
		"-j",
		"-p",
		"prog",
		"show",
		"id",
		id_buf,
		NULL,
	};

	snprintf(id_buf, sizeof(id_buf), "%d", prog_id);
	return run_argv_quiet(argv);
}

static int id_cmp(const void *a, const void *b)
{
	const int *ia = a;
	const int *ib = b;
	return (*ia > *ib) - (*ia < *ib);
}

static bool id_seen(const int *ids, int count, int id)
{
	int i;

	for (i = 0; i < count; i++) {
		if (ids[i] == id)
			return true;
	}
	return false;
}

static int collect_prog_ids_from_fdinfo(pid_t pid, int *ids, int max_ids)
{
	char dir_path[PATH_MAX];
	DIR *dir;
	struct dirent *ent;
	int count = 0;

	snprintf(dir_path, sizeof(dir_path), "/proc/%d/fdinfo", (int)pid);
	dir = opendir(dir_path);
	if (!dir)
		return -1;

	while ((ent = readdir(dir)) != NULL) {
		char file_path[PATH_MAX];
		FILE *fp;
		char *line = NULL;
		size_t cap = 0;

		if (ent->d_name[0] == '.')
			continue;
		if (snprintf(file_path, sizeof(file_path), "%s/%s", dir_path,
			     ent->d_name) >= (int)sizeof(file_path))
			continue;
		fp = fopen(file_path, "r");
		if (!fp)
			continue;
		while (getline(&line, &cap, fp) >= 0) {
			int prog_id = -1;

			if (sscanf(line, "prog_id: %d", &prog_id) != 1)
				continue;
			if (prog_id < 0 || id_seen(ids, count, prog_id))
				continue;
			if (count < max_ids)
				ids[count++] = prog_id;
		}
		free(line);
		fclose(fp);
	}

	closedir(dir);
	qsort(ids, count, sizeof(ids[0]), id_cmp);
	return count;
}

static int run_bpftool_loop(const struct options *opts)
{
	int i;

	for (i = 0; i < opts->iterations; i++) {
		int rc = run_bpftool_show_all();

		printf("MARK bpftool %d rc %d\n", i, rc);
		fflush(stdout);
		if (rc != 0)
			return -1;
	}
	return 0;
}

static int run_owner_id_loop(const struct options *opts, pid_t scx_pid)
{
	int ids[MAX_PROG_IDS];
	int count;
	int i;
	int iter;
	int filtered_ordinal = 0;

	count = collect_prog_ids_from_fdinfo(scx_pid, ids, ARRAY_SIZE(ids));
	if (count <= 0)
		return -1;

	printf("MARK owner_ids");
	for (i = 0; i < count; i++) {
		if (opts->only_id >= 0 && ids[i] != opts->only_id)
			continue;
		if (filtered_ordinal < opts->owner_start_ordinal) {
			filtered_ordinal++;
			continue;
		}
		if (opts->owner_count >= 0 &&
		    filtered_ordinal >= opts->owner_start_ordinal + opts->owner_count)
			continue;
		if (opts->owner_ordinal >= 0 && filtered_ordinal != opts->owner_ordinal) {
			filtered_ordinal++;
			continue;
		}
		printf(" %d", ids[i]);
		filtered_ordinal++;
	}
	printf("\n");
	fflush(stdout);

	filtered_ordinal = 0;
	for (i = 0; i < count; i++) {
		if (opts->only_id >= 0 && ids[i] != opts->only_id)
			continue;
		if (filtered_ordinal < opts->owner_start_ordinal) {
			filtered_ordinal++;
			continue;
		}
		if (opts->owner_count >= 0 &&
		    filtered_ordinal >= opts->owner_start_ordinal + opts->owner_count)
			continue;
		if (opts->owner_ordinal >= 0 && filtered_ordinal != opts->owner_ordinal) {
			filtered_ordinal++;
			continue;
		}
		for (iter = 0; iter < opts->iterations; iter++) {
			int rc = run_bpftool_show_id(ids[i]);

			printf("MARK owner_bpftool %d %d rc %d\n", ids[i], iter, rc);
			fflush(stdout);
			if (rc != 0)
				return -1;
		}
		filtered_ordinal++;
	}

	return 0;
}

int main(int argc, char **argv)
{
	struct options opts;
	struct scx_child child;
	char scx_binary[PATH_MAX];
	char scx_object[PATH_MAX];
	const char *arch_dir =
#if defined(__aarch64__) || defined(__arm64__)
		"arm64";
#else
		"x86_64";
#endif
	char state[64];
	int rc = 1;

	if (parse_args(argc, argv, &opts) < 0) {
		usage(argv[0]);
		return 2;
	}

	if (snprintf(scx_binary, sizeof(scx_binary),
		     "%s/corpus/build/%s/scx/bin/scx_rusty",
		     opts.repo_root, arch_dir) >= (int)sizeof(scx_binary))
		return 2;
	if (snprintf(scx_object, sizeof(scx_object),
		     "%s/corpus/build/%s/scx/scx_rusty_main.bpf.o",
		     opts.repo_root, arch_dir) >= (int)sizeof(scx_object))
		return 2;

	if (access(scx_binary, X_OK) != 0) {
		fprintf(stderr, "missing scx binary: %s\n", scx_binary);
		return 2;
	}
	if (access(scx_object, R_OK) != 0) {
		fprintf(stderr, "missing scx object: %s\n", scx_object);
		return 2;
	}

	printf("MARK mode %s iterations %d\n",
	       opts.mode == MODE_BPFTOOL_LOOP ? "bpftool-loop" : "owner-id-loop",
	       opts.iterations);
	if (opts.only_id >= 0)
		printf("MARK only_id %d\n", opts.only_id);
	if (opts.owner_start_ordinal > 0)
		printf("MARK owner_start_ordinal %d\n", opts.owner_start_ordinal);
	if (opts.owner_ordinal >= 0)
		printf("MARK owner_ordinal %d\n", opts.owner_ordinal);
	if (opts.owner_count >= 0)
		printf("MARK owner_count %d\n", opts.owner_count);
	printf("MARK paths %s %s %s\n", scx_binary, scx_object,
	       resolve_bpftool_path());
	fflush(stdout);

	if (!opts.skip_probe) {
		int probe_rc;

		print_marker("before_probe", "1");
		probe_rc = probe_struct_ops_register(scx_object);
		printf("MARK after_probe %d\n", probe_rc);
		fflush(stdout);
		if (probe_rc != 0)
			return 1;
	} else {
		print_marker("skip_probe", "1");
	}

	if (spawn_scx(scx_binary, &child) < 0) {
		perror("spawn_scx");
		return 1;
	}

	if (wait_scx_enabled(&child, opts.load_timeout_s) < 0) {
		fprintf(stderr, "scx_rusty did not become healthy\n");
		goto out;
	}

	if (read_state(state, sizeof(state)) < 0)
		snprintf(state, sizeof(state), "missing");
	printf("MARK after_wait healthy 1 state %s pid %d\n", state, (int)child.pid);
	fflush(stdout);

	if (opts.mode == MODE_BPFTOOL_LOOP)
		rc = run_bpftool_loop(&opts);
	else
		rc = run_owner_id_loop(&opts, child.pid);

	if (rc == 0)
		printf("MARK completed %s\n",
		       opts.mode == MODE_BPFTOOL_LOOP ? "bpftool-loop" : "owner-id-loop");
	fflush(stdout);

out:
	stop_scx(&child);
	print_tail_file("stdout_tail", child.stdout_path);
	print_tail_file("stderr_tail", child.stderr_path);
	unlink(child.stdout_path);
	unlink(child.stderr_path);
	return rc == 0 ? 0 : 1;
}
