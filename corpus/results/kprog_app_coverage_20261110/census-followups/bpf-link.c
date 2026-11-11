/* usage: bpf-link <output.o> <input.o>...: libbpf static linker, as the
 * application loaders link Tetragon's default CEL bodies into its objects. */
#include <stdio.h>
#include <bpf/libbpf.h>

int main(int argc, char **argv)
{
	struct bpf_linker *linker;
	int i, err;

	if (argc < 3) {
		fprintf(stderr, "usage: %s <output.o> <input.o>...\n", argv[0]);
		return 1;
	}
	linker = bpf_linker__new(argv[1], NULL);
	if (!linker) {
		perror("bpf_linker__new");
		return 1;
	}
	for (i = 2; i < argc; i++) {
		err = bpf_linker__add_file(linker, argv[i], NULL);
		if (err) {
			fprintf(stderr, "bpf_linker__add_file %s: %d\n", argv[i], err);
			bpf_linker__free(linker);
			return 1;
		}
	}
	err = bpf_linker__finalize(linker);
	bpf_linker__free(linker);
	if (err) {
		fprintf(stderr, "bpf_linker__finalize: %d\n", err);
		return 1;
	}
	return 0;
}
