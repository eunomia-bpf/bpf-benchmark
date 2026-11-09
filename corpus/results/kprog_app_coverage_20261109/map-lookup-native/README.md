# Pre-submission array map lookup body in native P

The compiler plugin uses BTF C static map metadata to select array lookups. It emits the original unsigned key/max-entry branch, live array index mask and live element-size multiplication before native submission. The map symbol retains its existing relocation; an empty compiler barrier preserves its runtime address identity through LLVM. Every other map operation retains its existing helper call. Layout offsets come from pahole on the matched7rc2 vmlinux and are recorded with exact build flags. The final kernel emitter retains its submitted-copy behavior.

The complete4object Katran payload uses identical original C and native inline flags to32dad control. summary.json records actual lowered sites, executable sizes, symbols and hashes. payload.tar.gz includes full manifest/objects/plugin/commands/diagnostics and BTF layout. R owns unbound timing and actual work; generation-bound acceptance stays a separate observation.
