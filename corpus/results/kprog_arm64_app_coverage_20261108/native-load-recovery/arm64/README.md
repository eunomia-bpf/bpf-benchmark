AArch64 same-copy native load exception integration

Shared source5598b9321 supplies the service load-site span and descriptor callbacks. ARM decodes final code before its literal pool, copies sites into request chunks, allocates the program exception table and fills RX-relative EX_TYPE_BPF entries while emitting the same native bytes. Native fixups clear X0-X30, discard XZR, handle X5 through a native marker, clear paired GPR destinations and resume at PC+4. The upstream file__nullable hook metadata is included.

build.json records actual incremental host/kernel/module outcomes against the retained ARM cache. Runtime and configured module archives carry exact binary inputs. Vector resume-only effects and protected-read/B fault-prefix correspondence continue through the shared model/reference work. The authorized full-word NULL guest is the following functional control. Runtime admission additions:0.
