use anyhow::{anyhow, Context};
use wasmtime::{Engine, Linker, Module, Store};
use wasmtime_wasi::{sync::WasiCtxBuilder, WasiCtx};
const PAGE_SIZE: u64 = 64 * 1024;
fn main() -> anyhow::Result<()> {
    let args = std::env::args().collect::<Vec<_>>();
    if args.len() < 2 || args.len() > 3 {
        eprintln!(
            "Usage: {} <path to wasm program> [path to memory file]",
            args[0]
        );
        return Ok(());
    }
    let prog_bytes =
        std::fs::read(&args[1]).with_context(|| anyhow!("Failed to read program file"))?;
    let mem_bytes = if args.len() >= 3 {
        std::fs::read(&args[2]).with_context(|| anyhow!("Failed to read memory file"))?
    } else {
        vec![]
    };
    let config = wasmtime::Config::new()
        .cranelift_opt_level(wasmtime::OptLevel::Speed)
        .to_owned();
    let engine = Engine::new(&config).with_context(|| anyhow!("Failed to create engine"))?;
    let mut linker = Linker::new(&engine);
    wasmtime_wasi::add_to_linker(&mut linker, |s: &mut WasiCtx| s)
        .with_context(|| anyhow!("Failed to link wasi"))?;
    let wasi = WasiCtxBuilder::new()
        .inherit_stdio()
        .inherit_args()?
        .build();
    let mut store = Store::new(&engine, wasi);
    let compile_start = std::time::Instant::now();
    let module = Module::from_binary(&engine, &prog_bytes)
        .with_context(|| anyhow!("Failed to parse module"))?;
    let compile_usage = compile_start.elapsed().as_nanos();
    linker.module(&mut store, "", &module)?;

    let memory = linker
        .get(&mut store, "", "memory")
        .unwrap()
        .into_memory()
        .with_context(|| anyhow!("Failed to find memory export"))?;
    let base_addr = (memory.size(&mut store) * PAGE_SIZE) as usize;
    memory
        .grow(&mut store, (4u64 << 20) / PAGE_SIZE as u64 + 1)
        .with_context(|| anyhow!("Failed to grow memory"))?;
    memory.data_mut(&mut store)[base_addr..base_addr + mem_bytes.len()].copy_from_slice(&mem_bytes);
    let bpf_main = linker
        .get(&mut store, "", "bpf_main")
        .with_context(|| anyhow!("Failed to lookup bpf_main"))?
        .into_func()
        .unwrap()
        .typed::<(i32,), i64>(&mut store)
        .with_context(|| anyhow!("Failed to find bpf_main"))?;
    // bpf_main.call(&mut store, (0x100));
    let exec_start = std::time::Instant::now();
    let ret = bpf_main.call(&mut store, (base_addr as i32,))?;
    let exec_time_usage = exec_start.elapsed().as_nanos();
    println!("{} {} {}", compile_usage, exec_time_usage, ret);

    Ok(())
}
