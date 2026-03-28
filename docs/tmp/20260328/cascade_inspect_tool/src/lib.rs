use std::fs;
use std::path::{Path, PathBuf};

use anyhow::{Context, Result};
use serde::Serialize;

#[path = "/home/yunwei37/workspace/bpf-benchmark/daemon/src/analysis/mod.rs"]
mod analysis;
#[path = "/home/yunwei37/workspace/bpf-benchmark/daemon/src/bpf.rs"]
mod bpf;
#[path = "/home/yunwei37/workspace/bpf-benchmark/daemon/src/elf_parser.rs"]
mod elf_parser;
#[path = "/home/yunwei37/workspace/bpf-benchmark/daemon/src/insn.rs"]
mod insn;
#[path = "/home/yunwei37/workspace/bpf-benchmark/daemon/src/pass.rs"]
mod pass;
#[path = "/home/yunwei37/workspace/bpf-benchmark/daemon/src/passes/mod.rs"]
mod passes;
#[path = "/home/yunwei37/workspace/bpf-benchmark/daemon/src/test_utils.rs"]
mod test_utils;
#[path = "/home/yunwei37/workspace/bpf-benchmark/daemon/src/verifier_log.rs"]
mod verifier_log;

#[derive(Clone, Debug)]
enum MapMode {
    Synthetic,
    Captured(PathBuf),
}

#[derive(Clone, Debug)]
struct Case {
    label: &'static str,
    object_relpath: &'static str,
    section_name: &'static str,
    map_mode: MapMode,
}

#[derive(Clone, Debug, Serialize)]
struct UsedMapSummary {
    name: String,
    map_type: Option<u32>,
    key_size: Option<u32>,
    value_size: Option<u32>,
    max_entries: Option<u32>,
    map_flags: Option<u32>,
}

#[derive(Clone, Debug, Serialize)]
struct StageSummary {
    stage: String,
    insn_count: usize,
}

#[derive(Clone, Debug, Serialize)]
struct CaseSummary {
    label: String,
    object_path: String,
    section_name: String,
    used_maps: Vec<UsedMapSummary>,
    stages: Vec<StageSummary>,
    map_inline_records: Vec<MapInlineRecordSummary>,
    pass_results_map_inline: Vec<PassResultSummary>,
    pass_results_map_inline_const_prop: Vec<PassResultSummary>,
    pass_results_full: Vec<PassResultSummary>,
}

#[derive(Clone, Debug, Serialize)]
struct MapInlineRecordSummary {
    map_id: u32,
    key_hex: String,
    expected_value_hex: String,
}

#[derive(Clone, Debug, Serialize)]
struct SkippedSiteSummary {
    pc: usize,
    reason: String,
}

#[derive(Clone, Debug, Serialize)]
struct PassResultSummary {
    pass_name: String,
    changed: bool,
    sites_applied: usize,
    insns_before: usize,
    insns_after: usize,
    diagnostics: Vec<String>,
    skipped_sites: Vec<SkippedSiteSummary>,
}

fn repo_root() -> PathBuf {
    PathBuf::from(env!("CARGO_MANIFEST_DIR"))
        .join("../../../..")
        .canonicalize()
        .expect("repo root should resolve")
}

fn output_root() -> PathBuf {
    repo_root().join("docs/tmp/20260328/cascade_inspect_output")
}

fn format_program_dump(program: &pass::BpfProgram) -> String {
    let dump = insn::dump_bytecode(&program.insns);
    let mut out = String::new();
    out.push_str(&format!("insn_count={}\n", dump.insn_count));
    for insn in dump.insns {
        out.push_str(&format!(
            "{:04}: code=0x{:02x} dst=r{} src=r{} off={} imm={} raw={}\n",
            insn.pc, insn.code, insn.dst_reg, insn.src_reg, insn.off, insn.imm, insn.raw_hex
        ));
    }
    out
}

fn hex_bytes(bytes: &[u8]) -> String {
    bytes.iter().map(|byte| format!("{byte:02x}")).collect()
}

fn write_text(path: &Path, content: &str) -> Result<()> {
    if let Some(parent) = path.parent() {
        fs::create_dir_all(parent)
            .with_context(|| format!("create output dir {}", parent.display()))?;
    }
    fs::write(path, content).with_context(|| format!("write {}", path.display()))
}

fn write_json<T: Serialize>(path: &Path, value: &T) -> Result<()> {
    let content = serde_json::to_string_pretty(value)?;
    write_text(path, &content)
}

fn used_maps_summary(loaded: &test_utils::LoadedFixtureProgram) -> Vec<UsedMapSummary> {
    loaded
        .used_maps
        .iter()
        .map(|map| UsedMapSummary {
            name: map.name.clone(),
            map_type: map.map_type,
            key_size: map.key_size,
            value_size: map.value_size,
            max_entries: map.max_entries,
            map_flags: map.map_flags,
        })
        .collect()
}

fn summarize_map_inline_records(records: &[pass::MapInlineRecord]) -> Vec<MapInlineRecordSummary> {
    records
        .iter()
        .map(|record| MapInlineRecordSummary {
            map_id: record.map_id,
            key_hex: hex_bytes(&record.key),
            expected_value_hex: hex_bytes(&record.expected_value),
        })
        .collect()
}

fn summarize_pass_results(results: &[pass::PassResult]) -> Vec<PassResultSummary> {
    results
        .iter()
        .map(|result| PassResultSummary {
            pass_name: result.pass_name.clone(),
            changed: result.changed,
            sites_applied: result.sites_applied,
            insns_before: result.insns_before,
            insns_after: result.insns_after,
            diagnostics: result.diagnostics.clone(),
            skipped_sites: result
                .sites_skipped
                .iter()
                .map(|skip| SkippedSiteSummary {
                    pc: skip.pc,
                    reason: skip.reason.clone(),
                })
                .collect(),
        })
        .collect()
}

fn load_program_for_case(
    loaded: &test_utils::LoadedFixtureProgram,
    case: &Case,
) -> Result<pass::BpfProgram> {
    match &case.map_mode {
        MapMode::Synthetic => Ok(loaded.into_program_with_synthetic_maps()),
        MapMode::Captured(path) => loaded.into_program_with_captured_maps(path),
    }
}

fn analyze_case(case: &Case) -> Result<()> {
    let repo = repo_root();
    let object_path = repo.join(case.object_relpath);
    let loaded = test_utils::load_program_from_path(&object_path, case.section_name)
        .with_context(|| format!("load {}:{}", object_path.display(), case.section_name))?;
    let ctx = test_utils::permissive_pass_ctx(loaded.prog_type);

    let original = load_program_for_case(&loaded, case)?;
    let mut map_inline_only = load_program_for_case(&loaded, case)?;
    let mut map_inline_const_prop = load_program_for_case(&loaded, case)?;
    let mut full = load_program_for_case(&loaded, case)?;

    let result_map_inline = test_utils::run_named_pipeline(&mut map_inline_only, &ctx, &["map_inline"])?;
    let result_map_inline_const_prop = test_utils::run_named_pipeline(
        &mut map_inline_const_prop,
        &ctx,
        &["map_inline", "const_prop"],
    )?;
    let result_full = test_utils::run_named_pipeline(
        &mut full,
        &ctx,
        &["map_inline", "const_prop", "dce"],
    )?;

    let map_inline_pass = result_map_inline
        .pass_results
        .iter()
        .find(|result| result.pass_name == "map_inline")
        .cloned()
        .context("missing map_inline pass result")?;

    let case_root = output_root().join(case.label);
    fs::create_dir_all(&case_root)?;
    write_text(&case_root.join("00_original.txt"), &format_program_dump(&original))?;
    write_text(
        &case_root.join("01_after_map_inline.txt"),
        &format_program_dump(&map_inline_only),
    )?;
    write_text(
        &case_root.join("02_after_map_inline_const_prop.txt"),
        &format_program_dump(&map_inline_const_prop),
    )?;
    write_text(
        &case_root.join("03_after_full_pipeline.txt"),
        &format_program_dump(&full),
    )?;
    write_json(
        &case_root.join("summary.json"),
        &CaseSummary {
            label: case.label.to_string(),
            object_path: object_path.display().to_string(),
            section_name: case.section_name.to_string(),
            used_maps: used_maps_summary(&loaded),
            stages: vec![
                StageSummary {
                    stage: "original".to_string(),
                    insn_count: original.insns.len(),
                },
                StageSummary {
                    stage: "after_map_inline".to_string(),
                    insn_count: map_inline_only.insns.len(),
                },
                StageSummary {
                    stage: "after_map_inline_const_prop".to_string(),
                    insn_count: map_inline_const_prop.insns.len(),
                },
                StageSummary {
                    stage: "after_full_pipeline".to_string(),
                    insn_count: full.insns.len(),
                },
            ],
            map_inline_records: summarize_map_inline_records(&map_inline_pass.map_inline_records),
            pass_results_map_inline: summarize_pass_results(&result_map_inline.pass_results),
            pass_results_map_inline_const_prop: summarize_pass_results(
                &result_map_inline_const_prop.pass_results,
            ),
            pass_results_full: summarize_pass_results(&result_full.pass_results),
        },
    )?;

    Ok(())
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn generate_cascade_case_outputs() -> Result<()> {
        let repo = repo_root();
        let tracee_capture = repo.join(
            "corpus/fixtures/tracee/tracee.bpf.o/sys_enter_submit.json",
        );

        let cases = vec![
            Case {
                label: "katran_xdp_pktcntr_xdp",
                object_relpath: "corpus/build/katran/xdp_pktcntr.bpf.o",
                section_name: "xdp",
                map_mode: MapMode::Synthetic,
            },
            Case {
                label: "katran_balancer_xdp",
                object_relpath: "corpus/build/katran/balancer.bpf.o",
                section_name: "xdp",
                map_mode: MapMode::Synthetic,
            },
            Case {
                label: "bindsnoop_kprobe_inet_bind",
                object_relpath: "corpus/build/bcc/libbpf-tools/bindsnoop.bpf.o",
                section_name: "kprobe/inet_bind",
                map_mode: MapMode::Synthetic,
            },
            Case {
                label: "tracee_sys_enter_submit_captured",
                object_relpath: "corpus/build/tracee/tracee.bpf.o",
                section_name: "sys_enter_submit",
                map_mode: MapMode::Captured(tracee_capture),
            },
        ];

        for case in &cases {
            analyze_case(case).with_context(|| format!("analyze {}", case.label))?;
        }

        Ok(())
    }
}
