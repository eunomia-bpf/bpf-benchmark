use anyhow::{anyhow, bail, Context};

fn main() -> anyhow::Result<()> {
    let args = std::env::args().collect::<Vec<_>>();
    if args.len() < 2 || args.len() > 3 {
        eprintln!(
            "Usage: {} <path to ebpf program> [path to memory file]",
            args[0]
        );
        return Ok(());
    }
    let prog_bytes =
        std::fs::read(&args[1]).with_context(|| anyhow!("Failed to read program file"))?;
    if prog_bytes.len() % 8 != 0 {
        bail!("Length of ebpf program must be a multiple of 8");
    }
    let mut mem_bytes = if args.len() >= 3 {
        std::fs::read(&args[2]).with_context(|| anyhow!("Failed to read memory file"))?
    } else {
        vec![]
    };
    let mut vm =
        rbpf::EbpfVmRaw::new(Some(&prog_bytes)).with_context(|| anyhow!("Failed to create vm"))?;
    let compile_start = std::time::Instant::now();

    vm.jit_compile()
        .with_context(|| anyhow!("Failed to run jit"))?;
    let compile_usage = compile_start.elapsed().as_nanos();

    let execute_start = std::time::Instant::now();
    let ret = unsafe { vm.execute_program_jit(&mut mem_bytes) }
        .with_context(|| anyhow!("Failed to run ebpf program"))?;
    let execute_usage = execute_start.elapsed().as_nanos();
    println!("{} {} {}", compile_usage, execute_usage, ret);
    Ok(())
}
