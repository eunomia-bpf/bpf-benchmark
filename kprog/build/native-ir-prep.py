"""Prepare resolved CO-RE IR for x86 codegen.

Three edits, each of which the shipped native objects already have and a raw frontend IR
does not:

  1. **Name the helper calls.** The BPF frontend leaves helpers as
     `inttoptr (i64 <id> to ptr)(...)`. The native linker resolves a helper by NAME, and
     clang is free to hoist such a constant into a register far from the call (and clobber
     it), so the call arrives unresolvable. The shipped objects carry
     `R_X86_64_PLT32 bpf_<name>` instead. This rewrites each `inttoptr` call into a call to
     a declaration of the uapi helper name.

  2. **Drop the frontend's target attributes.** The module and functions carry
     `"target-features"="+sse,+sse2"`, which overrides `-mgeneral-regs-only` at codegen and
     expands `llvm.memset`/`memcpy` into `movdqa`/`pxor`. Native code stays SIMD-free, so the
     attributes are removed.

  3. **Clear `dso_local` on the `.maps` globals.** With it, clang references the section
     symbol (`R_X86_64_PC32 .maps`, the *address* of a copy); without it, it emits the
     `GOTPCRELX` load whose slot the loader fills with the map pointer — the shipped form.

  4. **Fold `__kconfig` variables to the one kernel's values** (only with `--kconfig`).
     Upstream declares e.g. `extern __u32 LINUX_KERNEL_VERSION __kconfig;` and libbpf
     fills it at load time. The native linker has no `.kconfig` section to resolve, so the
     object keeps an undefined `LINUX_KERNEL_VERSION` and the link fails with
     `PC32 proof reloc target LINUX_KERNEL_VERSION has no section`. On a single known
     kernel the value is a compile-time constant, so it is substituted here and the
     global is dropped.

Usage: native-ir-prep.py <in.ll> <out.ll> [--name-helpers] [--kconfig <kernel build dir>]
"""
import re
import pathlib
import sys

ROOT = pathlib.Path('/workspaces/repository')
UAPI = ROOT / 'vendor/linux-framework/include/uapi/linux/bpf.h'


def helper_names() -> dict[int, str]:
    return {int(m.group(2)): 'bpf_' + m.group(1)
            for m in re.finditer(r'FN\((\w+),\s*(\d+),', UAPI.read_text())}


CALL = re.compile(r'inttoptr \(i64 (\d+) to ptr\)\(')

KCONFIG_GLOBAL = re.compile(
    r'^@(\w+) = external dso_local (?:local_unnamed_addr )?global (\w+), section "\.kconfig".*$',
    re.M)


def kconfig_values(build_dir) -> dict[str, int]:
    """The one kernel's build configuration, as BPF `__kconfig` variables see it.

    libbpf resolves a `__kconfig` extern from the kernel's own kconfig at load time.  The
    native linker has no such section, so the same values are read from the build the
    native object targets and folded into the IR as constants.  `build_dir` is that
    kernel's build tree (`.../build-x86`), which holds both `.config` and the release.
    """
    build_dir = pathlib.Path(build_dir)
    values = {}
    for line in (build_dir / '.config').read_text().splitlines():
        line = line.strip()
        if not line.startswith('CONFIG_') or '=' not in line:
            continue
        key, raw = line.split('=', 1)
        raw = raw.strip().strip('"')
        if raw == 'y':
            values[key] = 1
        elif raw == 'n':
            values[key] = 0
        elif raw.isdigit():
            values[key] = int(raw)
    release = (build_dir / 'include/config/kernel.release').read_text().strip()
    a, b, c = release.split('.', 2)
    values['LINUX_KERNEL_VERSION'] = (
        (int(a) << 16) + (int(b) << 8) + int(re.match(r'\d+', c).group(0)))
    return values


def fold_kconfig(text: str, values: dict[str, int]) -> tuple[str, list[str]]:
    """Replace each `.kconfig` global with its constant and drop the declaration.

    Only the single known target kernel can do this: the substitute is what that kernel
    reports, which is exactly what libbpf would have written into `.kconfig` at load.
    """
    folded, unresolved = [], []
    for m in KCONFIG_GLOBAL.finditer(text):
        name = m.group(1)
        if name in values:
            folded.append(name)
        else:
            unresolved.append(name)
    for name in folded:
        # Every use is a load of the global, which is folded to its constant; the
        # value's own metadata goes with it (nothing reads it to generate code).
        text = re.sub(
            r'^\s*(%[A-Za-z0-9_.]+) = load \w+, ptr @' + re.escape(name) + r'\b.*$',
            lambda m: f'{m.group(1)} = add i32 0, {values[name]}', text, flags=re.M)
        text = re.sub(r'^@%s = external dso_local .*$' % re.escape(name), '', text, flags=re.M)
        # A leftover `@NAME` in the debug metadata (a DIGlobalVariable) is harmless:
        # it is not a use, so it cannot produce a relocation.
        if re.search(r'@%s\b' % re.escape(name), re.sub(r'^!.*$', '', text, flags=re.M)):
            raise SystemExit(f'kconfig global {name} still referenced after folding')
    return text, unresolved


def main(argv):
    src, dst = pathlib.Path(argv[1]), pathlib.Path(argv[2])
    flags = argv[3:]
    name_helpers = '--name-helpers' in flags
    build_dir = None
    if '--kconfig' in flags:
        build_dir = flags[flags.index('--kconfig') + 1]
    names = helper_names()
    text = src.read_text()

    missing = set()

    def repl(m):
        name = names.get(int(m.group(1)))
        if name is None:
            missing.add(int(m.group(1)))
            return m.group(0)
        return f'@{name}('

    # Naming is only right when the frontend leaves helpers as address-taken constants
    # that clang can hoist away from the call (Tracee, BCC).  Where the frontend already
    # produces the adjacent `mov $imm; call *reg` — Katran — naming converts a call the
    # linker inlines into a PLT32 relocation it cannot, and the objects grow.  So: name
    # only if the caller asked, by passing a third argument.
    if name_helpers:
        text = CALL.sub(repl, text)
        if missing:
            raise SystemExit(f'helper ids with no uapi name: {sorted(missing)}')

    # Declare each named helper once, typed by the first call site that uses it.
    for name in sorted(set(re.findall(r'@(bpf_\w+)\(', text))):
        if re.search(rf'^declare .*@{name}\(', text, re.M):
            continue
        m = re.search(rf'(%\S+) = (?:tail )?call ([\w*]+) @{name}\(', text)
        retty = m.group(2) if m else 'void'
        text = text.replace('\n\n', f'\ndeclare {retty} @{name}(...) ; bpf helper\n\n', 1)

    # 2 and 3.
    text = re.sub(r'"target-features"="[^"]*"\s*', '', text)
    # The frontend records "frame-pointer"="all" on every function, which overrides
    # -fomit-frame-pointer at codegen; the shipped objects are built without one.
    text = re.sub(r'"frame-pointer"="[^"]*"\s*', '', text)
    text = re.sub(r'"target-cpu"="[^"]*"\s*', '', text)
    # Every data global the native object references by address, not just .maps: a
    # dso_local global makes clang emit an R_X86_64_PC32 against the SECTION symbol (the
    # address of a copy), where the shipped objects carry a GOTPCRELX load of the slot the
    # loader fills from the symbol's name.  Only definitions are touched; declarations are
    # already non-dso_local.
    text = re.sub(r'^(@\S+ = )dso_local (global .*)$', r'\1\2', text, flags=re.M)
    text = re.sub(r'^(@\S+ = )dso_local (constant .*)$', r'\1\2', text, flags=re.M)

    # 4.  The one kernel's kconfig values, so no `.kconfig` global reaches the linker.
    unresolved = []
    if build_dir is not None:
        text, unresolved = fold_kconfig(text, kconfig_values(build_dir))

    dst.write_text(text)
    named = len(set(re.findall(r'@(bpf_\w+)\(', text)))
    print('helpers named', named, '| passthrough left',
          text.count('llvm.bpf.passthrough'),
          '| kconfig folded', 'no' if build_dir is None else 'yes',
          '| kconfig unresolved', unresolved)


if __name__ == '__main__':
    main(sys.argv)