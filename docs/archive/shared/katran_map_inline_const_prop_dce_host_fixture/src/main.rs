mod loader {
    include!("../loader_body.rs");

    const KATRAN_INLINE_HINTS_4: [&str; 4] = [
        "--inline-hint=ctl_array:!00000000",
        "--inline-hint=vip_map:!0a6401010000000000000000000000001f900600",
        "--inline-hint=ch_rings:!00000000",
        "--inline-hint=server_id_map:!00000000",
    ];

    pub fn run_tmp() -> Result<()> {
        let root = Path::new("/home/yunwei37/workspace/bpf-benchmark");
        std::env::set_current_dir(root).context("chdir repo")?;
        let bpfopt = root.join(BPFOPT_BIN);
        let workdir = WorkDir::open(Some(PathBuf::from(
            "/tmp/bpfopt-katran-mapinline-const-dce",
        )))?;
        let _ = fs::remove_dir_all(&workdir.path);
        fs::create_dir_all(&workdir.path)?;

        let obj = root.join("bpfopt/testobject/katran_balancer.bpf.o");
        let map_values_dir = workdir.path.join(MAP_VALUES_DIR);
        let (_obj, prepared) = prepare_workdir(&workdir.path, &obj, true, true)?;
        for prog in &prepared {
            let metadata = read_json::<ProgramMetadata>(&prog.dir.join(METADATA_JSON))?;
            if metadata.name != "balancer_ingress" {
                continue;
            }
            canonicalize_program(prog, &bpfopt)?;
            write_hardcoded_overlays(&map_values_dir)?;
            run_chain(prog, &map_values_dir, &bpfopt)?;
            let fd = verify_workdir(&prog.dir, &prog.map_fds)?;
            run_bpftestrun(fd.as_raw_fd(), &prog.dir, &katran_cli(1))?;
            fs::copy(
                prog.dir.join(TEST_OUTPUT_BIN),
                prog.dir.join("test_output.semantic.bin"),
            )?;
            fs::copy(
                prog.dir.join(TEST_RUN_JSON),
                prog.dir.join("test_run.semantic.json"),
            )?;
            for _ in 0..5 {
                run_bpftestrun(fd.as_raw_fd(), &prog.dir, &katran_cli(10_000))?;
            }
            println!("workdir={}", workdir.path.display());
            return Ok(());
        }
        bail!("balancer_ingress not found")
    }

    fn run_chain(prog: &PreparedProgram, map_values_dir: &Path, bpfopt: &Path) -> Result<()> {
        let metadata = read_json::<ProgramMetadata>(&prog.dir.join(METADATA_JSON))?;
        let map_inline = prog.dir.join("output.map_inline.bin");
        let const_prop = prog.dir.join("output.const_prop.bin");
        let map_inline_report = prog.dir.join("report.map_inline.json");
        let const_prop_report = prog.dir.join("report.const_prop.json");
        let dce_report = prog.dir.join("report.dce.json");
        let map_inline_verify = prog.dir.join("verify.map_inline.log");

        command_ok(
            Command::new(bpfopt)
                .arg("--pass")
                .arg("map_inline")
                .arg("--input")
                .arg(prog.dir.join(INPUT_BIN))
                .arg("--output")
                .arg(&map_inline)
                .arg("--report")
                .arg(&map_inline_report)
                .arg("--prog-type")
                .arg(metadata.prog_type.to_string())
                .arg("--verifier-states")
                .arg(prog.dir.join(VERIFIER_LOG))
                .arg("--")
                .arg("--map-values")
                .arg(map_values_dir)
                .arg("--map-ids")
                .arg(join_u32_csv(&prog.map_ids))
                .args(KATRAN_INLINE_HINTS_4),
            "map_inline",
        )?;

        fs::copy(&map_inline, prog.dir.join(OUTPUT_BIN))?;
        drop(verify_workdir_log2(prog, &map_inline_verify)?);

        command_ok(
            Command::new(bpfopt)
                .arg("--pass")
                .arg("const_prop")
                .arg("--input")
                .arg(&map_inline)
                .arg("--output")
                .arg(&const_prop)
                .arg("--report")
                .arg(&const_prop_report)
                .arg("--prog-type")
                .arg(metadata.prog_type.to_string())
                .arg("--verifier-states")
                .arg(&map_inline_verify),
            "const_prop",
        )?;

        command_ok(
            Command::new(bpfopt)
                .arg("--pass")
                .arg("dce")
                .arg("--input")
                .arg(&const_prop)
                .arg("--output")
                .arg(prog.dir.join(OUTPUT_BIN))
                .arg("--report")
                .arg(&dce_report)
                .arg("--prog-type")
                .arg(metadata.prog_type.to_string()),
            "dce",
        )?;

        let report = serde_json::json!({
            "map_inline": read_json::<serde_json::Value>(&map_inline_report)?,
            "const_prop": read_json::<serde_json::Value>(&const_prop_report)?,
            "dce": read_json::<serde_json::Value>(&dce_report)?,
        });
        write_json(&prog.dir.join(REPORT_JSON), &report)
    }

    fn verify_workdir_log2(prog: &PreparedProgram, log_path: &Path) -> Result<OwnedFd> {
        let metadata = read_json::<ProgramMetadata>(&prog.dir.join(METADATA_JSON))?;
        let input = prog.dir.join(OUTPUT_BIN);
        let raw = fs::read(&input)?;
        let stride = mem::size_of::<libbpf_sys::bpf_insn>();
        if !raw.len().is_multiple_of(stride) {
            bail!("{} length is not a multiple of 8 bytes", input.display());
        }
        let mut insns = vec![libbpf_sys::bpf_insn::default(); raw.len() / stride];
        unsafe { ptr::copy_nonoverlapping(raw.as_ptr(), insns.as_mut_ptr().cast(), raw.len()) };
        rewrite_map_indices_to_fds(&mut insns, &prog.map_fds)?;

        let name = CString::new(metadata.name.as_str())?;
        let license = CString::new("GPL").unwrap();
        let mut log_buf = vec![0 as c_char; LOG_BYTES];
        let mut opts = libbpf_sys::bpf_prog_load_opts {
            sz: mem::size_of::<libbpf_sys::bpf_prog_load_opts>() as libbpf_sys::size_t,
            log_level: 2,
            log_size: log_buf.len() as u32,
            log_buf: log_buf.as_mut_ptr(),
            expected_attach_type: metadata.expected_attach_type,
            attach_btf_id: metadata.attach_btf_id,
            ..Default::default()
        };
        let fd = unsafe {
            libbpf_sys::bpf_prog_load(
                metadata.prog_type,
                name.as_ptr(),
                license.as_ptr(),
                insns.as_ptr(),
                insns.len() as libbpf_sys::size_t,
                &mut opts,
            )
        };
        let log = log_buf_to_string(&log_buf);
        fs::write(log_path, &log)?;
        if fd < 0 {
            bail!(
                "BPF_PROG_LOAD rejected {}: {}; verifier log: {}",
                input.display(),
                io::Error::last_os_error(),
                log.trim()
            );
        }
        Ok(unsafe { OwnedFd::from_raw_fd(fd) })
    }

    fn write_hardcoded_overlays(map_values_dir: &Path) -> Result<()> {
        let overlay_dir =
            Path::new("/home/yunwei37/workspace/bpf-benchmark/runner/config/passes/map_inline/overlays/katran");
        let mut overlays = serde_json::Map::new();
        for (name, file) in [
            ("ch_rings", "ch_rings.json"),
            ("server_id_map", "server_id_map.json"),
        ] {
            let id = katran_map_id(map_values_dir, name)?;
            let overlay: serde_json::Value = read_json(&overlay_dir.join(file))?;
            overlays.insert(id.to_string(), overlay);
        }
        write_json(&map_values_dir.join("overlays.json"), &overlays)
    }

    fn katran_map_id(map_values_dir: &Path, expected_name: &str) -> Result<u32> {
        for entry in fs::read_dir(map_values_dir)? {
            let path = entry?.path();
            if !path
                .file_name()
                .and_then(|name| name.to_str())
                .is_some_and(|name| name.ends_with(".show.json"))
            {
                continue;
            }
            let show: serde_json::Value = read_json(&path)?;
            if show.get("name").and_then(|name| name.as_str()) == Some(expected_name) {
                return show
                    .get("id")
                    .and_then(|id| id.as_u64())
                    .and_then(|id| u32::try_from(id).ok())
                    .context("bad map id");
            }
        }
        bail!("missing map {expected_name}")
    }

    fn command_ok(command: &mut Command, label: &str) -> Result<()> {
        let status = command.status()?;
        if !status.success() {
            bail!("{label} failed with {status}");
        }
        Ok(())
    }

    fn katran_cli(repeat: u32) -> Cli {
        Cli {
            obj: PathBuf::from("bpfopt/testobject/katran_balancer.bpf.o"),
            pass: Some("map_inline_const_dce".into()),
            target: None,
            workdir: None,
            bpftestrun: true,
            katran_maps: true,
            repeat,
        }
    }
}

fn main() -> anyhow::Result<()> {
    loader::run_tmp()
}
