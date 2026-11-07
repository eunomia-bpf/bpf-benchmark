"""Regression for manifest selectors over libbpf-linked BPF subprograms."""
from pathlib import Path
import os
import shutil
import subprocess
import tempfile
import unittest

from elftools.elf.elffile import ELFFile
from write_native_manifest import scan_bpf_source_programs

ROOT = Path(__file__).resolve().parents[2]
FIXTURE = r"""
#include <linux/bpf.h>
#include <bpf_helpers.h>
static __attribute__((noinline)) int common(void *ctx) {
    asm volatile("" : : "r"(ctx));
    return bpf_get_smp_processor_id();
}
static __attribute__((noinline)) long callback(__u32 index, void *ctx) {
    return common(ctx) + index;
}
__attribute__((noinline)) long global_callback(__u32 index, void *ctx) {
    return common(ctx) + index + 1;
}
static __attribute__((used,noinline)) int unrelated(void *ctx) {
    return bpf_get_prandom_u32();
}
SEC("xdp/direct") int direct_entry(struct xdp_md *ctx) { return common(ctx); }
SEC("xdp/callback") int callback_entry(struct xdp_md *ctx) {
    long a = bpf_loop(2, callback, ctx, 0);
    long b = bpf_loop(3, callback, ctx, 0);
    return a + b + bpf_loop(1, global_callback, ctx, 0);
}
SEC("xdp/constant") unsigned long constant_entry(struct xdp_md *ctx) {
    return bpf_ktime_get_ns() ^ 0x0000008500000001ULL;
}
char LICENSE[] SEC("license") = "GPL";
"""


class LinkedSourceMetadata(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.directory = tempfile.TemporaryDirectory(prefix="native-manifest-closure-")
        cls.addClassCleanup(cls.directory.cleanup)
        folder = Path(cls.directory.name)
        source, cls.object = folder / "source.c", folder / "source.o"
        source.write_text(FIXTURE)
        clang = os.environ.get("CLANG") or shutil.which("clang") or "/usr/lib/llvm-18/bin/clang"
        subprocess.run([clang, "-target", "bpf", "-O2", "-g",
            "-I", str(ROOT / "vendor/libbpf/include/uapi"),
            "-I", str(ROOT / "vendor/libbpf/src"),
            "-I", "/usr/include/x86_64-linux-gnu", "-c", str(source), "-o", str(cls.object)], check=True)
        with cls.object.open("rb") as stream:
            elf = ELFFile(stream)
            cls.sizes = {s.name: int(s["st_size"]) for s in elf.get_section_by_name(".symtab").iter_symbols()
                         if s["st_info"]["type"] == "STT_FUNC"}
        cls.metadata = scan_bpf_source_programs(cls.object)

    def test_direct_call_includes_local_function_and_its_helpers(self):
        item = self.metadata["direct_entry"]
        self.assertEqual(item.bytecode_len, self.sizes["direct_entry"] + self.sizes["common"])
        self.assertEqual(item.helpers, {8})
        self.assertNotIn("common", self.metadata)

    def test_function_address_closure_counts_shared_descendants_once(self):
        item = self.metadata["callback_entry"]
        self.assertEqual(item.bytecode_len, sum(self.sizes[n] for n in
            ["callback_entry", "callback", "global_callback", "common"]))
        self.assertEqual(item.helpers, {8, 181})
        self.assertIn("common", scan_bpf_source_programs(self.object, include_local=True))

    def test_ldimm64_data_words_keep_their_instruction_identity(self):
        item = self.metadata["constant_entry"]
        self.assertEqual(item.bytecode_len, self.sizes["constant_entry"])
        self.assertEqual(item.helpers, {5})


if __name__ == "__main__":
    unittest.main()
