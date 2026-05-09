// SPDX-License-Identifier: MIT
// Scan helpers for dynamic map inlining.

use std::collections::{BTreeMap, HashMap, HashSet};
use std::fmt::Write as _;
use std::fs;
use std::path::{Path, PathBuf};
use std::sync::OnceLock;

use anyhow::{bail, Context, Result};
use serde::Deserialize;

use super::utils::{emit_ldimm64, insn_width};
use crate::analysis::BranchTargetAnalysis;
use crate::insn::*;
use crate::pass::*;

mod map_info;
pub use map_info::{MapInfo, MapInfoAnalysis, MapInfoResult, MapReference};

const BPF_PSEUDO_MAP_FD: u8 = crate::insn::BPF_PSEUDO_MAP_FD;
const BPF_PSEUDO_MAP_VALUE: u8 = crate::insn::BPF_PSEUDO_MAP_VALUE;
const BPF_PSEUDO_MAP_IDX: u8 = crate::insn::BPF_PSEUDO_MAP_IDX;
const BPF_PSEUDO_MAP_IDX_VALUE: u8 = crate::insn::BPF_PSEUDO_MAP_IDX_VALUE;
const R2_SETUP_LOOKBACK_LIMIT: usize = 8;
const REG_RESOLUTION_LIMIT: usize = 64;
const CONST_STACK_VALUE_LOOKBACK_LIMIT: usize = 256;
const MAP_INLINE_FIXED_POINT_MAX_ITERS: usize = 8;
const VALUE_PREVIEW_BYTES: usize = 32;

// ── Hint-related types (pass-local; pass.rs re-exports for BpfProgram field).

#[derive(Clone, Debug, PartialEq, Eq, Hash)]
pub enum MapInlineHintAnchor {
    Pc(usize),
    MapName(String),
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum MapInlineHintMode {
    Soft,
    Hard,
}

#[derive(Clone, Debug, PartialEq, Eq)]
pub struct MapInlineHint {
    pub anchor: MapInlineHintAnchor,
    pub mode: MapInlineHintMode,
    pub key: Vec<u8>,
}

/// Dynamic map inlining optimization pass.
pub struct MapInlinePass;

#[derive(Clone)]
struct MapInlineCliPass {
    map_ids: Vec<u32>,
    snapshot: MapSnapshot,
    inline_hints: Vec<MapInlineHint>,
}

impl MapInlinePass {
    pub fn from_cli_args(args: &[String]) -> Result<Box<dyn BpfPass>> {
        let cli = MapInlineCliArgs::parse(args)?;
        let map_ids = parse_map_ids_arg(&cli.map_ids)?;
        let snapshot = read_map_values(&cli.map_values, &map_ids)?;
        Ok(Box::new(MapInlineCliPass {
            map_ids,
            snapshot,
            inline_hints: cli.inline_hints,
        }))
    }
}

impl BpfPass for MapInlineCliPass {
    fn name(&self) -> &str {
        "map_inline"
    }

    fn required_analyses(&self) -> Vec<&str> {
        vec!["branch_targets"]
    }

    fn run(
        &self,
        program: &mut BpfProgram,
        analyses: &mut AnalysisCache,
        ctx: &PassContext,
    ) -> anyhow::Result<PassResult> {
        program.set_map_ids(self.map_ids.clone());
        program.map_metadata = self.snapshot.metadata.clone();
        program.map_values = self.snapshot.values.clone();
        program.map_value_overlays = self.snapshot.compressed_values.clone();
        program.map_inner_map_ids = self.snapshot.inner_map_ids.clone();
        program.map_snapshots_skipped_by_size = self.snapshot.maps_skipped_by_size.clone();
        program.map_inline_hints = self.inline_hints.clone();
        MapInlinePass.run(program, analyses, ctx)
    }
}

struct MapInlineCliArgs {
    map_values: PathBuf,
    map_ids: String,
    /// Operator-supplied key hints. Each entry pre-fills
    /// `BpfProgram.map_inline_hints` so the pass can either hard-specialize a
    /// lookup or emit a guarded soft fold. Pass-local on purpose:
    /// `--inline-hint` is a map_inline tuning knob, NOT framework-global —
    /// adding it to `bpfopt::main::CommonArgs` would pollute every other
    /// pass's CLI surface.
    inline_hints: Vec<MapInlineHint>,
}

impl MapInlineCliArgs {
    fn parse(args: &[String]) -> Result<Self> {
        let mut map_values = None;
        let mut map_ids = None;
        let mut inline_hints = Vec::new();
        let mut iter = args.iter();
        while let Some(arg) = iter.next() {
            if let Some(value) = arg.strip_prefix("--inline-hint=") {
                inline_hints.push(parse_inline_hint(value)?);
                continue;
            }
            match arg.as_str() {
                "--map-values" => {
                    let value = iter
                        .next()
                        .ok_or_else(|| anyhow::anyhow!("--map-values requires DIR"))?;
                    map_values = Some(PathBuf::from(value));
                }
                "--map-ids" => {
                    let value = iter
                        .next()
                        .ok_or_else(|| anyhow::anyhow!("--map-ids requires LIST"))?;
                    map_ids = Some(value.clone());
                }
                "--inline-hint" => {
                    let value = iter.next().ok_or_else(|| {
                        anyhow::anyhow!("--inline-hint requires <anchor>:[!]<hex_key_bytes>")
                    })?;
                    inline_hints.push(parse_inline_hint(value)?);
                }
                other => bail!("map_inline unknown pass-local arg: {other}"),
            }
        }
        validate_inline_hint_anchor_modes(&inline_hints)?;
        Ok(Self {
            map_values: map_values
                .ok_or_else(|| anyhow::anyhow!("map_inline requires --map-values"))?,
            map_ids: map_ids.ok_or_else(|| anyhow::anyhow!("map_inline requires --map-ids"))?,
            inline_hints,
        })
    }
}

/// Parse one `--inline-hint <anchor>:[!]<hex_key_bytes>` value.
///
/// A decimal anchor selects one call PC. A name anchor selects every lookup
/// site that uses the named map. Bare hex is a soft fold; `!` requests a hard
/// fold.
fn parse_inline_hint(input: &str) -> Result<MapInlineHint> {
    let (anchor_str, key_str) = input.split_once(':').ok_or_else(|| {
        anyhow::anyhow!("invalid --inline-hint '{input}': expected <anchor>:[!]<hex_key_bytes>")
    })?;
    let anchor = parse_inline_hint_anchor(anchor_str)
        .with_context(|| format!("invalid --inline-hint anchor in '{input}'"))?;
    let (mode, hex_str) = if let Some(hex) = key_str.strip_prefix('!') {
        (MapInlineHintMode::Hard, hex)
    } else {
        (MapInlineHintMode::Soft, key_str)
    };
    let key_bytes = parse_inline_hint_hex(hex_str)
        .with_context(|| format!("invalid --inline-hint key bytes in '{input}'"))?;
    Ok(MapInlineHint {
        anchor,
        mode,
        key: key_bytes,
    })
}

fn parse_inline_hint_anchor(input: &str) -> Result<MapInlineHintAnchor> {
    if input.is_empty() {
        bail!("anchor is empty");
    }
    if input.bytes().all(|byte| byte.is_ascii_digit()) {
        let pc = input
            .parse::<usize>()
            .with_context(|| format!("invalid call_pc anchor {input:?}"))?;
        return Ok(MapInlineHintAnchor::Pc(pc));
    }

    let mut bytes = input.bytes();
    let first = bytes.next().expect("non-empty anchor checked above");
    if !(first.is_ascii_alphabetic() || first == b'_') {
        bail!("map-name anchor must start with a letter or underscore");
    }
    if !bytes.all(|byte| byte.is_ascii_alphanumeric() || byte == b'_') {
        bail!("map-name anchor must contain only ASCII letters, digits, and underscores");
    }
    Ok(MapInlineHintAnchor::MapName(input.to_string()))
}

fn parse_inline_hint_hex(input: &str) -> Result<Vec<u8>> {
    if !input.len().is_multiple_of(2) {
        bail!("hex string must have an even number of digits");
    }
    input
        .as_bytes()
        .chunks_exact(2)
        .map(|pair| {
            let hi = hex_nibble(pair[0])
                .ok_or_else(|| anyhow::anyhow!("invalid hex digit '{}'", char::from(pair[0])))?;
            let lo = hex_nibble(pair[1])
                .ok_or_else(|| anyhow::anyhow!("invalid hex digit '{}'", char::from(pair[1])))?;
            Ok((hi << 4) | lo)
        })
        .collect()
}

fn hex_nibble(byte: u8) -> Option<u8> {
    match byte {
        b'0'..=b'9' => Some(byte - b'0'),
        b'a'..=b'f' => Some(byte - b'a' + 10),
        b'A'..=b'F' => Some(byte - b'A' + 10),
        _ => None,
    }
}

fn validate_inline_hint_anchor_modes(hints: &[MapInlineHint]) -> Result<()> {
    let mut anchors: HashMap<MapInlineHintAnchor, (MapInlineHintMode, usize)> = HashMap::new();
    for hint in hints {
        match anchors.get_mut(&hint.anchor) {
            Some((mode, count)) => {
                if *mode != hint.mode {
                    bail!(
                        "inline hint anchor {} mixes soft and hard folds",
                        format_hint_anchor(&hint.anchor)
                    );
                }
                if hint.mode == MapInlineHintMode::Hard {
                    bail!(
                        "inline hint anchor {} has multiple hard folds",
                        format_hint_anchor(&hint.anchor)
                    );
                }
                *count += 1;
            }
            None => {
                anchors.insert(hint.anchor.clone(), (hint.mode, 1));
            }
        }
    }
    Ok(())
}

fn format_hint_anchor(anchor: &MapInlineHintAnchor) -> String {
    match anchor {
        MapInlineHintAnchor::Pc(pc) => pc.to_string(),
        MapInlineHintAnchor::MapName(name) => name.clone(),
    }
}

#[derive(Clone)]
struct MapSnapshot {
    metadata: HashMap<u32, MapMetadata>,
    values: HashMap<(u32, Vec<u8>), Vec<u8>>,
    compressed_values: HashMap<u32, CompressedMapValues>,
    inner_map_ids: HashMap<(u32, Vec<u8>), u32>,
    maps_skipped_by_size: HashSet<u32>,
}

#[derive(Debug, Deserialize)]
struct ProgInfoMapIdsJson {
    #[serde(default)]
    map_ids: Vec<u32>,
}

#[derive(Debug, Deserialize)]
struct BpftoolMapShowJson {
    id: u32,
    #[serde(default)]
    name: String,
    #[serde(rename = "type")]
    map_type: MapTypeJson,
    bytes_key: u32,
    bytes_value: u32,
    max_entries: u32,
}

#[derive(Debug, Deserialize)]
struct BpftoolMapEntryJson {
    key: Vec<String>,
    #[serde(default)]
    value: Option<BpftoolMapValueJson>,
    #[serde(default)]
    values: Vec<BpftoolPerCpuValueJson>,
    #[serde(default)]
    inner_map_id: Option<u32>,
}

#[derive(Debug, Deserialize)]
#[serde(untagged)]
enum InnerMapIdJson {
    Number(u32),
    String(String),
}

#[derive(Debug, Deserialize)]
#[serde(deny_unknown_fields)]
struct BpftoolMapDumpSkipMarker {
    skipped: bool,
    reason: String,
    size_bytes: u64,
    limit_bytes: u64,
}

enum BpftoolMapDumpSnapshot {
    Entries(Vec<BpftoolMapEntryJson>),
    Compressed(CompressedMapValues),
    SkippedBySize,
}

#[derive(Debug, Deserialize)]
struct BpftoolPerCpuValueJson {
    value: Vec<String>,
}

#[derive(Debug, Deserialize)]
#[serde(untagged)]
enum BpftoolMapValueJson {
    Bytes(Vec<String>),
    Error { error: String },
}

#[derive(Debug, Deserialize)]
#[serde(deny_unknown_fields)]
struct CompressedMapValuesJson {
    compression: String,
    value_size: usize,
    #[serde(default)]
    value_hex: Option<String>,
    #[serde(default)]
    default_hex: Option<String>,
    #[serde(default)]
    entries: Option<serde_json::Value>,
}

#[derive(Debug, Deserialize)]
#[serde(untagged)]
enum MapTypeJson {
    Number(u32),
    Name(String),
}

fn read_map_values(path: &Path, map_ids: &[u32]) -> Result<MapSnapshot> {
    if !path.is_dir() {
        bail!(
            "--map-values must point to a bpftool snapshot directory, got {}",
            path.display()
        );
    }
    let mut metadata = HashMap::new();
    let mut values = HashMap::new();
    let mut compressed_values = HashMap::new();
    let mut inner_map_ids = HashMap::new();
    let mut maps_skipped_by_size = HashSet::new();
    let mut empty_lpm_trie_maps = HashSet::new();

    for &map_id in map_ids.iter().filter(|&&map_id| map_id != 0) {
        let show = read_bpftool_map_show(path, map_id)?;
        let map_type = parse_map_type(&show.map_type)?;
        let map_metadata = MapMetadata {
            map_type,
            key_size: show.bytes_key,
            value_size: show.bytes_value,
            max_entries: show.max_entries,
            map_id: show.id,
            name: show.name,
        };
        if needs_bpftool_map_dump(map_type) {
            match read_bpftool_map_dump(path, show.id, &map_metadata)? {
                BpftoolMapDumpSnapshot::Entries(entries) => {
                    if entries.is_empty()
                        && map_metadata.map_type == libbpf_sys::BPF_MAP_TYPE_LPM_TRIE
                    {
                        empty_lpm_trie_maps.insert(show.id);
                    }
                    for entry in entries {
                        let key = decode_bpftool_hex_bytes(&entry.key)
                            .with_context(|| format!("invalid key bytes for map {}", show.id))?;
                        let value = decode_bpftool_entry_value(&entry, &map_metadata)
                            .with_context(|| format!("invalid value bytes for map {}", show.id))?;
                        values.insert((show.id, key.clone()), value);
                        if let Some(inner_map_id) = entry.inner_map_id {
                            inner_map_ids.insert((show.id, key), inner_map_id);
                        }
                    }
                }
                BpftoolMapDumpSnapshot::Compressed(compressed) => {
                    if values.keys().any(|(map_id, _)| *map_id == show.id) {
                        bail!(
                            "map {} has both raw entries and compression overlay",
                            show.id
                        );
                    }
                    compressed_values.insert(show.id, compressed);
                }
                BpftoolMapDumpSnapshot::SkippedBySize => {
                    maps_skipped_by_size.insert(show.id);
                }
            }
            read_inner_map_ids_supplement(
                path,
                show.id,
                map_metadata.key_size as usize,
                &mut inner_map_ids,
            )?;
        }
        metadata.insert(show.id, map_metadata);
    }
    read_optional_compressed_overlay_file(path, &metadata, &values, &mut compressed_values)?;
    synthesize_empty_lpm_trie_overlays(&empty_lpm_trie_maps, &metadata, &mut compressed_values)?;

    Ok(MapSnapshot {
        metadata,
        values,
        compressed_values,
        inner_map_ids,
        maps_skipped_by_size,
    })
}

fn read_bpftool_map_show(path: &Path, map_id: u32) -> Result<BpftoolMapShowJson> {
    let show_path = bpftool_map_show_path(path, map_id);
    let show: BpftoolMapShowJson = read_json_file(&show_path, "bpftool map show JSON")?;
    if show.id != map_id {
        bail!(
            "{} contains map id {}, expected {}",
            show_path.display(),
            show.id,
            map_id
        );
    }
    Ok(show)
}

fn read_bpftool_map_dump(
    path: &Path,
    map_id: u32,
    metadata: &MapMetadata,
) -> Result<BpftoolMapDumpSnapshot> {
    let dump_path = bpftool_map_dump_path(path, map_id);
    let data =
        fs::read(&dump_path).with_context(|| format!("failed to read {}", dump_path.display()))?;
    let Some(first) = data
        .iter()
        .copied()
        .find(|byte| !byte.is_ascii_whitespace())
    else {
        bail!("{} is empty", dump_path.display());
    };

    match first {
        b'[' => {
            let entries = serde_json::from_slice(&data).with_context(|| {
                format!(
                    "failed to parse bpftool map dump JSON from {}",
                    dump_path.display()
                )
            })?;
            Ok(BpftoolMapDumpSnapshot::Entries(entries))
        }
        b'{' => {
            let value: serde_json::Value = serde_json::from_slice(&data).with_context(|| {
                format!(
                    "failed to parse bpftool map dump object from {}",
                    dump_path.display()
                )
            })?;
            if value.get("compression").is_some() {
                let compressed = parse_compressed_map_values_json(map_id, metadata, value)
                    .with_context(|| {
                        format!(
                            "failed to parse compressed map overlay {}",
                            dump_path.display()
                        )
                    })?;
                return Ok(BpftoolMapDumpSnapshot::Compressed(compressed));
            }
            let marker: BpftoolMapDumpSkipMarker =
                serde_json::from_value(value).with_context(|| {
                    format!(
                        "failed to parse bpftool map dump skip marker from {}",
                        dump_path.display()
                    )
                })?;
            if !marker.skipped
                || marker.reason != "size_limit"
                || marker.size_bytes <= marker.limit_bytes
            {
                bail!(
                    "unexpected bpftool map dump skip marker in {}",
                    dump_path.display()
                );
            }
            Ok(BpftoolMapDumpSnapshot::SkippedBySize)
        }
        _ => bail!(
            "{} is neither a bpftool map dump array nor a skip marker object",
            dump_path.display()
        ),
    }
}

fn read_inner_map_ids_supplement(
    path: &Path,
    map_id: u32,
    key_size: usize,
    inner_map_ids: &mut HashMap<(u32, Vec<u8>), u32>,
) -> Result<()> {
    let supplement_path = bpftool_map_inner_map_ids_path(path, map_id);
    let data = match fs::read(&supplement_path) {
        Ok(data) => data,
        Err(err) if err.kind() == std::io::ErrorKind::NotFound => return Ok(()),
        Err(err) => {
            return Err(err)
                .with_context(|| format!("failed to read {}", supplement_path.display()))
        }
    };
    let supplement: HashMap<String, HashMap<String, InnerMapIdJson>> =
        serde_json::from_slice(&data).with_context(|| {
            format!(
                "failed to parse inner_map_id supplement from {}",
                supplement_path.display()
            )
        })?;
    let expected_map_id = map_id.to_string();
    for present_map_id in supplement.keys() {
        if present_map_id != &expected_map_id {
            bail!(
                "{} contains inner_map_id table for map {}, expected only {}",
                supplement_path.display(),
                present_map_id,
                expected_map_id
            );
        }
    }
    let entries = supplement.get(&expected_map_id).ok_or_else(|| {
        anyhow::anyhow!(
            "{} does not contain inner_map_id table for map {}",
            supplement_path.display(),
            map_id
        )
    })?;
    for (key_hex, inner_map_id_json) in entries {
        let key = decode_inner_map_id_key_hex(map_id, key_hex, key_size)?;
        let inner_map_id = decode_inner_map_id_json(map_id, key_hex, inner_map_id_json)?;
        inner_map_ids.insert((map_id, key), inner_map_id);
    }
    Ok(())
}

fn decode_inner_map_id_key_hex(map_id: u32, hex: &str, key_size: usize) -> Result<Vec<u8>> {
    let expected = expected_hex_digits(key_size, "key_size")?;
    if hex.len() != expected {
        bail!(
            "map {map_id} inner_map_id supplement key has {} hex digit(s), expected {}",
            hex.len(),
            expected
        );
    }
    parse_inline_hint_hex(hex)
        .with_context(|| format!("map {map_id} inner_map_id supplement key has invalid hex"))
}

fn decode_inner_map_id_json(map_id: u32, key_hex: &str, value: &InnerMapIdJson) -> Result<u32> {
    let inner_map_id = match value {
        InnerMapIdJson::Number(number) => *number,
        InnerMapIdJson::String(text) => text.parse::<u32>().with_context(|| {
            format!("map {map_id} inner_map_id supplement entry {key_hex:?} is not a u32 id")
        })?,
    };
    if inner_map_id == 0 {
        bail!("map {map_id} inner_map_id supplement entry {key_hex:?} has id 0; omit NULL entries");
    }
    Ok(inner_map_id)
}

fn read_optional_compressed_overlay_file(
    path: &Path,
    metadata: &HashMap<u32, MapMetadata>,
    raw_values: &HashMap<(u32, Vec<u8>), Vec<u8>>,
    compressed_values: &mut HashMap<u32, CompressedMapValues>,
) -> Result<()> {
    let overlay_path = path.join("overlays.json");
    let data = match fs::read(&overlay_path) {
        Ok(data) => data,
        Err(err) if err.kind() == std::io::ErrorKind::NotFound => return Ok(()),
        Err(err) => {
            return Err(err).with_context(|| format!("failed to read {}", overlay_path.display()))
        }
    };
    let overlays: HashMap<String, serde_json::Value> =
        serde_json::from_slice(&data).with_context(|| {
            format!(
                "failed to parse compressed map overlays from {}",
                overlay_path.display()
            )
        })?;

    for (map_id_text, overlay) in overlays {
        let map_id = map_id_text
            .parse::<u32>()
            .with_context(|| format!("invalid compressed overlay map id {map_id_text:?}"))?;
        let map_metadata = metadata.get(&map_id).ok_or_else(|| {
            anyhow::anyhow!(
                "compressed overlay references map {} not present in --map-ids metadata",
                map_id
            )
        })?;
        if raw_values
            .keys()
            .any(|(raw_map_id, _)| *raw_map_id == map_id)
        {
            bail!("map {map_id} has both raw entries and compression overlay");
        }
        let compressed = parse_compressed_map_values_json(map_id, map_metadata, overlay)
            .with_context(|| format!("invalid compressed overlay for map {map_id}"))?;
        if compressed_values.insert(map_id, compressed).is_some() {
            bail!("map {map_id} has duplicate compression overlays");
        }
    }

    Ok(())
}

fn synthesize_empty_lpm_trie_overlays(
    empty_lpm_trie_maps: &HashSet<u32>,
    metadata: &HashMap<u32, MapMetadata>,
    compressed_values: &mut HashMap<u32, CompressedMapValues>,
) -> Result<()> {
    for map_id in empty_lpm_trie_maps {
        if compressed_values.contains_key(map_id) {
            continue;
        }
        let map_metadata = metadata.get(map_id).ok_or_else(|| {
            anyhow::anyhow!("empty LPM_TRIE map {} missing map_values metadata", map_id)
        })?;
        compressed_values.insert(
            *map_id,
            CompressedMapValues {
                value_size: map_metadata.value_size as usize,
                kind: CompressedMapValuesKind::Enumerated {
                    entries: HashMap::new(),
                },
            },
        );
    }
    Ok(())
}

fn parse_compressed_map_values_json(
    map_id: u32,
    metadata: &MapMetadata,
    value: serde_json::Value,
) -> Result<CompressedMapValues> {
    let overlay: CompressedMapValuesJson = serde_json::from_value(value)
        .with_context(|| format!("invalid compressed map overlay schema for map {map_id}"))?;
    if overlay.value_size != metadata.value_size as usize {
        bail!(
            "map {map_id} compressed overlay value_size {} does not match map bytes_value {}",
            overlay.value_size,
            metadata.value_size
        );
    }

    let kind = match overlay.compression.as_str() {
        "uniform" => {
            if let Some(entries) = overlay.entries {
                if entries.is_array() {
                    bail!("map {map_id} has both raw entries and compression overlay");
                }
                bail!("map {map_id} uniform compression must not include entries");
            }
            if overlay.default_hex.is_some() {
                bail!("map {map_id} uniform compression must not include default_hex");
            }
            let value_hex = overlay.value_hex.ok_or_else(|| {
                anyhow::anyhow!("map {map_id} uniform compression requires value_hex")
            })?;
            let value =
                decode_compressed_value_hex(map_id, "value_hex", &value_hex, overlay.value_size)?;
            CompressedMapValuesKind::Uniform(value)
        }
        "sparse" => {
            if overlay.value_hex.is_some() {
                bail!("map {map_id} sparse compression must not include value_hex");
            }
            let default_hex = overlay.default_hex.ok_or_else(|| {
                anyhow::anyhow!("map {map_id} sparse compression requires default_hex")
            })?;
            let default = decode_compressed_value_hex(
                map_id,
                "default_hex",
                &default_hex,
                overlay.value_size,
            )?;
            let entries = overlay.entries.ok_or_else(|| {
                anyhow::anyhow!("map {map_id} sparse compression requires entries")
            })?;
            let entries = decode_compressed_entries(
                map_id,
                metadata.key_size as usize,
                overlay.value_size,
                entries,
            )?;
            CompressedMapValuesKind::Sparse { default, entries }
        }
        "enumerated" => {
            if overlay.value_hex.is_some() {
                bail!("map {map_id} enumerated compression must not include value_hex");
            }
            if overlay.default_hex.is_some() {
                bail!("map {map_id} enumerated compression must not include default_hex");
            }
            let entries = overlay.entries.ok_or_else(|| {
                anyhow::anyhow!("map {map_id} enumerated compression requires entries")
            })?;
            let entries = decode_compressed_entries(
                map_id,
                metadata.key_size as usize,
                overlay.value_size,
                entries,
            )?;
            CompressedMapValuesKind::Enumerated { entries }
        }
        other => bail!("map {map_id} unsupported compression {other:?}"),
    };

    Ok(CompressedMapValues {
        value_size: overlay.value_size,
        kind,
    })
}

fn decode_compressed_entries(
    map_id: u32,
    key_size: usize,
    value_size: usize,
    entries: serde_json::Value,
) -> Result<HashMap<Vec<u8>, Vec<u8>>> {
    let object = entries
        .as_object()
        .ok_or_else(|| anyhow::anyhow!("map {map_id} compressed entries must be a JSON object"))?;
    let mut decoded = HashMap::new();
    for (key_hex, value_json) in object {
        let value_hex = value_json.as_str().ok_or_else(|| {
            anyhow::anyhow!("map {map_id} compressed entry {key_hex:?} value must be a hex string")
        })?;
        let key = decode_compressed_key_hex(map_id, key_hex, key_size)?;
        let value = decode_compressed_value_hex(map_id, "entries value", value_hex, value_size)?;
        decoded.insert(key, value);
    }
    Ok(decoded)
}

fn decode_compressed_key_hex(map_id: u32, hex: &str, key_size: usize) -> Result<Vec<u8>> {
    let expected = expected_hex_digits(key_size, "key_size")?;
    if hex.len() != expected {
        bail!(
            "map {map_id} compressed entry key has {} hex digit(s), expected {}",
            hex.len(),
            expected
        );
    }
    parse_inline_hint_hex(hex)
        .with_context(|| format!("map {map_id} compressed entry key has invalid hex"))
}

fn decode_compressed_value_hex(
    map_id: u32,
    field: &str,
    hex: &str,
    value_size: usize,
) -> Result<Vec<u8>> {
    let expected = expected_hex_digits(value_size, "value_size")?;
    if hex.len() != expected {
        bail!(
            "map {map_id} compressed {field} has {} hex digit(s), expected {}",
            hex.len(),
            expected
        );
    }
    parse_inline_hint_hex(hex)
        .with_context(|| format!("map {map_id} compressed {field} has invalid hex"))
}

fn expected_hex_digits(byte_len: usize, label: &str) -> Result<usize> {
    byte_len
        .checked_mul(2)
        .ok_or_else(|| anyhow::anyhow!("{label} {byte_len} overflows hex length"))
}

fn bpftool_map_show_path(path: &Path, map_id: u32) -> PathBuf {
    path.join(format!("map-{map_id}.show.json"))
}

fn bpftool_map_dump_path(path: &Path, map_id: u32) -> PathBuf {
    path.join(format!("map-{map_id}.dump.json"))
}

fn bpftool_map_inner_map_ids_path(path: &Path, map_id: u32) -> PathBuf {
    path.join(format!("map-{map_id}.inner_map_ids.json"))
}

fn decode_bpftool_entry_value(
    entry: &BpftoolMapEntryJson,
    metadata: &MapMetadata,
) -> Result<Vec<u8>> {
    if !entry.values.is_empty() {
        return decode_bpftool_percpu_values(&entry.values, metadata.value_size as usize);
    }
    let Some(value) = &entry.value else {
        bail!("bpftool entry has neither value nor per-CPU values");
    };
    match value {
        BpftoolMapValueJson::Bytes(bytes) => decode_bpftool_hex_bytes(bytes),
        BpftoolMapValueJson::Error { error } => {
            bail!("bpftool map dump returned lookup error: {error}")
        }
    }
}

fn decode_bpftool_percpu_values(
    values: &[BpftoolPerCpuValueJson],
    value_size: usize,
) -> Result<Vec<u8>> {
    let stride = round_up_8(value_size);
    let mut out = Vec::with_capacity(values.len().saturating_mul(stride));
    for value in values {
        let bytes = decode_bpftool_hex_bytes(&value.value)?;
        if bytes.len() != value_size {
            bail!(
                "per-CPU value has {} byte(s), expected {}",
                bytes.len(),
                value_size
            );
        }
        out.extend_from_slice(&bytes);
        out.resize(out.len() + (stride - value_size), 0);
    }
    Ok(out)
}

fn decode_bpftool_hex_bytes(input: &[String]) -> Result<Vec<u8>> {
    input
        .iter()
        .map(|byte| {
            let byte = byte.trim();
            let hex = byte.strip_prefix("0x").unwrap_or(byte);
            u8::from_str_radix(hex, 16).with_context(|| format!("invalid bpftool byte {byte:?}"))
        })
        .collect()
}

fn needs_bpftool_map_dump(map_type: u32) -> bool {
    matches!(
        map_type,
        libbpf_sys::BPF_MAP_TYPE_HASH
            | libbpf_sys::BPF_MAP_TYPE_ARRAY
            | libbpf_sys::BPF_MAP_TYPE_PERCPU_ARRAY
            | libbpf_sys::BPF_MAP_TYPE_LRU_HASH
            | libbpf_sys::BPF_MAP_TYPE_LPM_TRIE
            | libbpf_sys::BPF_MAP_TYPE_ARRAY_OF_MAPS
            | libbpf_sys::BPF_MAP_TYPE_HASH_OF_MAPS
    )
}

fn parse_map_type(map_type: &MapTypeJson) -> Result<u32> {
    match map_type {
        MapTypeJson::Number(number) => Ok(*number),
        MapTypeJson::Name(name) => {
            let normalized = name
                .trim()
                .trim_start_matches("BPF_MAP_TYPE_")
                .trim_start_matches("bpf_map_type_")
                .replace(['-', ' '], "_")
                .to_ascii_lowercase();
            match normalized.as_str() {
                "hash" => Ok(libbpf_sys::BPF_MAP_TYPE_HASH),
                "array" => Ok(libbpf_sys::BPF_MAP_TYPE_ARRAY),
                "prog_array" => Ok(libbpf_sys::BPF_MAP_TYPE_PROG_ARRAY),
                "perf_event_array" => Ok(libbpf_sys::BPF_MAP_TYPE_PERF_EVENT_ARRAY),
                "percpu_hash" | "per_cpu_hash" => Ok(libbpf_sys::BPF_MAP_TYPE_PERCPU_HASH),
                "percpu_array" | "per_cpu_array" => Ok(libbpf_sys::BPF_MAP_TYPE_PERCPU_ARRAY),
                "stack_trace" => Ok(libbpf_sys::BPF_MAP_TYPE_STACK_TRACE),
                "cgroup_array" => Ok(libbpf_sys::BPF_MAP_TYPE_CGROUP_ARRAY),
                "lru_hash" => Ok(libbpf_sys::BPF_MAP_TYPE_LRU_HASH),
                "lru_percpu_hash" | "lru_per_cpu_hash" => {
                    Ok(libbpf_sys::BPF_MAP_TYPE_LRU_PERCPU_HASH)
                }
                "lpm_trie" => Ok(libbpf_sys::BPF_MAP_TYPE_LPM_TRIE),
                "array_of_maps" => Ok(libbpf_sys::BPF_MAP_TYPE_ARRAY_OF_MAPS),
                "hash_of_maps" => Ok(libbpf_sys::BPF_MAP_TYPE_HASH_OF_MAPS),
                "devmap" => Ok(libbpf_sys::BPF_MAP_TYPE_DEVMAP),
                "devmap_hash" => Ok(libbpf_sys::BPF_MAP_TYPE_DEVMAP_HASH),
                "sockmap" => Ok(libbpf_sys::BPF_MAP_TYPE_SOCKMAP),
                "cpumap" => Ok(libbpf_sys::BPF_MAP_TYPE_CPUMAP),
                "xskmap" => Ok(libbpf_sys::BPF_MAP_TYPE_XSKMAP),
                "sockhash" => Ok(libbpf_sys::BPF_MAP_TYPE_SOCKHASH),
                "cgroup_storage" => Ok(libbpf_sys::BPF_MAP_TYPE_CGROUP_STORAGE),
                "reuseport_sockarray" => Ok(libbpf_sys::BPF_MAP_TYPE_REUSEPORT_SOCKARRAY),
                "percpu_cgroup_storage" | "per_cpu_cgroup_storage" => {
                    Ok(libbpf_sys::BPF_MAP_TYPE_PERCPU_CGROUP_STORAGE)
                }
                "queue" => Ok(libbpf_sys::BPF_MAP_TYPE_QUEUE),
                "stack" => Ok(libbpf_sys::BPF_MAP_TYPE_STACK),
                "sk_storage" => Ok(libbpf_sys::BPF_MAP_TYPE_SK_STORAGE),
                "struct_ops" => Ok(libbpf_sys::BPF_MAP_TYPE_STRUCT_OPS),
                "ringbuf" => Ok(libbpf_sys::BPF_MAP_TYPE_RINGBUF),
                "inode_storage" => Ok(libbpf_sys::BPF_MAP_TYPE_INODE_STORAGE),
                "task_storage" => Ok(libbpf_sys::BPF_MAP_TYPE_TASK_STORAGE),
                "bloom_filter" => Ok(libbpf_sys::BPF_MAP_TYPE_BLOOM_FILTER),
                "user_ringbuf" => Ok(libbpf_sys::BPF_MAP_TYPE_USER_RINGBUF),
                "cgrp_storage" => Ok(libbpf_sys::BPF_MAP_TYPE_CGRP_STORAGE),
                "arena" => Ok(libbpf_sys::BPF_MAP_TYPE_ARENA),
                "insn_array" => Ok(libbpf_sys::BPF_MAP_TYPE_INSN_ARRAY),
                _ => bail!("unsupported map_type: {name}"),
            }
        }
    }
}

fn parse_map_ids_arg(value: &str) -> Result<Vec<u32>> {
    if value.contains('/') || value.ends_with(".json") {
        let prog_info: ProgInfoMapIdsJson = read_json_file(Path::new(value), "prog_info JSON")?;
        return Ok(prog_info.map_ids);
    }
    parse_u32_csv(value, "--map-ids")
}

fn parse_u32_csv(value: &str, flag: &str) -> Result<Vec<u32>> {
    value
        .split(',')
        .map(|entry| {
            entry
                .trim()
                .parse::<u32>()
                .with_context(|| format!("invalid {flag} value: {entry}"))
        })
        .collect()
}

fn read_json_file<T: for<'de> Deserialize<'de>>(path: &Path, label: &str) -> Result<T> {
    let data = fs::read(path).with_context(|| format!("failed to read {}", path.display()))?;
    serde_json::from_slice(&data)
        .with_context(|| format!("failed to parse {label} from {}", path.display()))
}

/// A `bpf_map_lookup_elem()` helper call and its map argument load.
#[derive(Clone, Debug, PartialEq, Eq)]
struct MapLookupSite {
    call_pc: usize,
    map_load_pc: usize,
}

/// A two-level map-in-map lookup chain: outer lookup result flows into the
/// inner lookup's map argument.
#[derive(Clone, Debug, PartialEq, Eq)]
struct MapInMapChain {
    outer_site: MapLookupSite,
    inner_call_pc: usize,
    outer_alias_copy_pcs: Vec<usize>,
    outer_null_check_pc: Option<usize>,
}

/// Constant key materialized on the stack for a map lookup.
#[derive(Clone, Debug, PartialEq, Eq)]
struct ConstantKey {
    stack_off: i16,
    width: usize,
    value: u64,
    bytes: Vec<u8>,
    store_pc: usize,
    source_imm_pc: Option<usize>,
    materialization_pcs: Vec<usize>,
    r2_mov_pc: Option<usize>,
    r2_add_pc: Option<usize>,
}

#[derive(Clone, Debug, PartialEq, Eq)]
struct ExtractedConstantKey {
    key: ConstantKey,
    used_inline_hint: Option<MapInlineHintAnchor>,
}

#[derive(Clone, Debug, PartialEq, Eq)]
enum KeyExtractionError {
    Unavailable(String),
}

/// A fixed-offset scalar load from the map value pointer returned in `r0`.
#[derive(Clone, Debug, PartialEq, Eq)]
struct FixedLoadUse {
    pc: usize,
    dst_reg: u8,
    size: u8,
    offset: i16,
}

/// Classification of all uses that consume the lookup result in `r0`.
#[derive(Clone, Debug, Default, PartialEq, Eq)]
struct R0UseClassification {
    fixed_loads: Vec<FixedLoadUse>,
    other_uses: Vec<usize>,
    alias_copy_pcs: Vec<usize>,
    null_check_pc: Option<usize>,
}

impl R0UseClassification {
    /// Returns whether every `r0` use is a fixed-offset scalar load.
    #[cfg(test)]
    pub fn all_fixed_loads(&self) -> bool {
        self.other_uses.is_empty()
    }
}

#[derive(Clone, Debug, PartialEq, Eq)]
struct ConstantRegValue {
    value: u64,
    source_pc: Option<usize>,
}

#[derive(Clone, Debug, PartialEq, Eq)]
struct ConstantStackBytes {
    bytes: Vec<u8>,
    latest_store_pc: usize,
    latest_source_imm_pc: Option<usize>,
    materialization_pcs: Vec<usize>,
}

#[derive(Clone, Debug)]
struct SnapshotMapValue {
    map_id: u32,
    key: Vec<u8>,
    value: Vec<u8>,
}

type DirectMapValueLoadRewrites = (
    BTreeMap<usize, Vec<BpfInsn>>,
    usize,
    Vec<String>,
    Vec<MapInlineRecord>,
);

#[derive(Clone, Debug, PartialEq, Eq)]
enum KeyPointerOrigin {
    Stack(i16),
    MapValue {
        map_ref: MapRefKey,
        value_off: i32,
        ldimm_pc: usize,
    },
}

#[derive(Clone, Copy, Debug, PartialEq, Eq, Hash)]
struct MapRefKey {
    src_reg: u8,
    imm: i32,
}

/// Find all `bpf_map_lookup_elem()` call sites in the instruction stream.
fn find_map_lookup_sites(insns: &[BpfInsn]) -> Vec<MapLookupSite> {
    let mut sites = Vec::new();
    let mut pc = 0usize;

    while pc < insns.len() {
        let insn = &insns[pc];
        if insn.is_call()
            && insn.src_reg() == 0
            && insn.imm == libbpf_sys::BPF_FUNC_map_lookup_elem as i32
        {
            if let Some(map_load_pc) = find_map_load_for_call(insns, pc) {
                sites.push(MapLookupSite {
                    call_pc: pc,
                    map_load_pc,
                });
            }
        }

        pc += insn_width(insn);
    }

    sites
}

/// Find outer-to-inner map-in-map lookup chains among direct outer lookup sites.
fn find_map_in_map_chains(insns: &[BpfInsn], outer_sites: &[MapLookupSite]) -> Vec<MapInMapChain> {
    outer_sites
        .iter()
        .filter_map(|outer_site| find_map_in_map_chain_for_outer(insns, outer_site))
        .collect()
}

fn find_map_in_map_chain_for_outer(
    insns: &[BpfInsn],
    outer_site: &MapLookupSite,
) -> Option<MapInMapChain> {
    let mut alias_regs = HashMap::from([(0u8, 0i16)]);
    let mut alias_stack_slots = HashMap::new();
    let mut alias_copy_pcs = Vec::new();
    let mut null_check_pc = None;
    let bounds = subprog_bounds(insns, outer_site.call_pc);
    let mut pc = outer_site.call_pc + 1;

    while pc < insns.len() && (!alias_regs.is_empty() || !alias_stack_slots.is_empty()) {
        let insn = &insns[pc];
        let allow_null_check = null_check_pc.is_none();

        if allow_null_check && is_null_check_on_alias(insn, &alias_regs) {
            null_check_pc = Some(pc);
            let Some(next_pc) = advance_to_non_null_path(pc, insn, insns.len()) else {
                break;
            };
            pc = next_pc;
            continue;
        }

        if insn.is_call()
            && insn.src_reg() == 0
            && insn.imm == libbpf_sys::BPF_FUNC_map_lookup_elem as i32
        {
            if alias_regs.get(&1).copied() == Some(0) {
                return Some(MapInMapChain {
                    outer_site: outer_site.clone(),
                    inner_call_pc: pc,
                    outer_alias_copy_pcs: alias_copy_pcs,
                    outer_null_check_pc: null_check_pc,
                });
            }
            break;
        }

        if let Some((dst_reg, alias_off)) = alias_copy(insn, &alias_regs) {
            if alias_off != 0 {
                break;
            }
            alias_copy_pcs.push(pc);
            kill_defined_alias_regs(&mut alias_regs, insn);
            alias_regs.insert(dst_reg, alias_off);
            pc += insn_width(insn);
            continue;
        }

        if let Some((stack_off, width)) = resolve_stack_store_slot(insns, pc, insn, bounds) {
            kill_overlapping_alias_stack_slots(&mut alias_stack_slots, stack_off, width);
            if insn.class() == BPF_STX
                && bpf_mode(insn.code) == BPF_MEM
                && width == 8
                && alias_regs.contains_key(&insn.src_reg())
            {
                alias_copy_pcs.push(pc);
                alias_stack_slots.insert(stack_off, alias_regs[&insn.src_reg()]);
                pc += insn_width(insn);
                continue;
            }
        }

        if let Some(stack_off) = resolve_stack_load_slot(insns, pc, insn, bounds) {
            if let Some(&alias_off) = alias_stack_slots.get(&stack_off) {
                alias_copy_pcs.push(pc);
                alias_stack_slots.remove(&stack_off);
                kill_defined_alias_regs(&mut alias_regs, insn);
                alias_regs.insert(insn.dst_reg(), alias_off);
                pc += insn_width(insn);
                continue;
            }
        }

        if insn_uses_any_alias(insn, &alias_regs) {
            break;
        }
        kill_defined_alias_regs(&mut alias_regs, insn);

        pc += insn_width(insn);
    }

    None
}

/// Recover a stack-materialized constant key for a lookup helper call.
#[cfg(test)]
fn extract_constant_key(insns: &[BpfInsn], call_pc: usize) -> Option<ConstantKey> {
    let Ok(key) = try_extract_constant_key(insns, call_pc) else {
        return None;
    };
    Some(key)
}

#[cfg(test)]
fn try_extract_constant_key(insns: &[BpfInsn], call_pc: usize) -> Result<ConstantKey, String> {
    let bounds = subprog_bounds(insns, call_pc);
    let stack_off = resolve_stack_pointer_to_stack(insns, call_pc, 2, bounds)?;
    let mut last_err = None;
    let mut extracted = None;
    for width in [8u8, 4, 2, 1] {
        match find_constant_stack_bytes(insns, call_pc, bounds, stack_off, width) {
            Ok(stack_bytes) => {
                extracted = Some((width, stack_bytes));
                break;
            }
            Err(err) => last_err = Some(err),
        }
    }
    let (width, stack_bytes) = extracted.ok_or_else(|| {
        last_err.unwrap_or_else(|| format!("no stack store found for fp{}", stack_off))
    })?;
    let removable_setup = find_r2_stack_pointer_setup_simple(insns, call_pc, bounds)
        .filter(|(_, _, off)| *off == stack_off);

    Ok(ConstantKey {
        stack_off,
        width: usize::from(width),
        value: constant_key_value(&stack_bytes.bytes),
        bytes: stack_bytes.bytes,
        store_pc: stack_bytes.latest_store_pc,
        source_imm_pc: stack_bytes.latest_source_imm_pc,
        materialization_pcs: stack_bytes.materialization_pcs,
        r2_mov_pc: removable_setup.map(|(mov_pc, _, _)| mov_pc),
        r2_add_pc: removable_setup.map(|(_, add_pc, _)| add_pc),
    })
}

#[cfg(test)]
fn try_extract_constant_key_sized(
    insns: &[BpfInsn],
    call_pc: usize,
    key_size: u32,
) -> Result<ConstantKey, String> {
    if key_size == 0 {
        return Err("map key size is zero".to_string());
    }

    let bounds = subprog_bounds(insns, call_pc);
    let stack_off = resolve_stack_pointer_to_stack(insns, call_pc, 2, bounds)?;
    let key_width = u8::try_from(key_size)
        .map_err(|_| format!("map key size {} does not fit in u8", key_size))?;
    let stack_bytes = find_constant_stack_bytes(insns, call_pc, bounds, stack_off, key_width)?;

    let removable_setup = find_r2_stack_pointer_setup_simple(insns, call_pc, bounds)
        .filter(|(_, _, off)| *off == stack_off);

    Ok(ConstantKey {
        stack_off,
        width: usize::from(key_width),
        value: constant_key_value(&stack_bytes.bytes),
        bytes: stack_bytes.bytes,
        store_pc: stack_bytes.latest_store_pc,
        source_imm_pc: stack_bytes.latest_source_imm_pc,
        materialization_pcs: stack_bytes.materialization_pcs,
        r2_mov_pc: removable_setup.map(|(mov_pc, _, _)| mov_pc),
        r2_add_pc: removable_setup.map(|(_, add_pc, _)| add_pc),
    })
}

fn try_extract_constant_key_verifier_guided(
    insns: &[BpfInsn],
    verifier_states: &[VerifierInsn],
    call_pc: usize,
    key_size: u32,
) -> Result<ConstantKey, String> {
    if verifier_states.is_empty() {
        return Err("no verifier states available".to_string());
    }
    if key_size == 0 {
        return Err("map key size is zero".to_string());
    }
    let key_width: usize = key_size
        .try_into()
        .map_err(|_| format!("map key size {} does not fit in usize", key_size))?;

    let occurrences = verifier_states
        .iter()
        .enumerate()
        .filter(|(_, state)| state.pc == call_pc)
        .collect::<Vec<_>>();
    if occurrences.is_empty() {
        return Err(format!(
            "verifier log has no state snapshot at call pc {}",
            call_pc
        ));
    }

    let mut extracted = Vec::new();
    for (occ_idx, state) in occurrences {
        extracted.push(try_extract_constant_key_for_occurrence(
            insns,
            verifier_states,
            call_pc,
            key_width,
            occ_idx,
            state.frame,
        )?);
    }

    let first = extracted
        .first()
        .cloned()
        .ok_or_else(|| format!("no verifier-guided key candidates at pc {}", call_pc))?;
    let all_same = extracted.iter().all(|key| {
        key.stack_off == first.stack_off
            && key.width == first.width
            && key.bytes == first.bytes
            && key.store_pc == first.store_pc
            && key.materialization_pcs == first.materialization_pcs
    });
    if !all_same {
        return Err(format!(
            "verifier-derived key candidates disagree across {} state(s)",
            extracted.len()
        ));
    }

    Ok(first)
}

fn try_extract_constant_key_for_occurrence(
    insns: &[BpfInsn],
    verifier_states: &[VerifierInsn],
    call_pc: usize,
    key_width: usize,
    occurrence_idx: usize,
    frame: usize,
) -> Result<ConstantKey, String> {
    let state = verifier_states.get(occurrence_idx).ok_or_else(|| {
        format!(
            "verifier state occurrence {} is out of range",
            occurrence_idx
        )
    })?;
    if state.frame != frame {
        return Err(format!(
            "verifier state occurrence frame {} does not match expected frame {} at pc {}",
            state.frame, frame, call_pc
        ));
    }
    let key_off = r2_stack_range_at_call(state, call_pc)?;
    let bounds = subprog_bounds(insns, call_pc);
    let bytes = constant_stack_bytes_for_range(&state.stack, key_off, key_width).ok_or_else(
        || {
            format!(
                "verifier log did not expose constant stack bytes covering fp{key_off} width {key_width} at call pc {call_pc}"
            )
        },
    )?;
    let materialization =
        materialization_for_snapshot_key(insns, call_pc, bounds, key_off, key_width, &bytes);

    let removable_setup = find_r2_stack_pointer_setup_simple(insns, call_pc, bounds)
        .filter(|(_, _, off)| *off == key_off);
    let (store_pc, source_imm_pc, materialization_pcs) = match materialization {
        Some(stack_bytes) => (
            stack_bytes.latest_store_pc,
            stack_bytes.latest_source_imm_pc,
            stack_bytes.materialization_pcs,
        ),
        None => (call_pc, None, Vec::new()),
    };

    Ok(ConstantKey {
        stack_off: key_off,
        width: key_width,
        value: constant_key_value(&bytes),
        bytes,
        store_pc,
        source_imm_pc,
        materialization_pcs,
        r2_mov_pc: removable_setup.map(|(mov_pc, _, _)| mov_pc),
        r2_add_pc: removable_setup.map(|(_, add_pc, _)| add_pc),
    })
}

fn r2_stack_range_at_call(state: &VerifierInsn, call_pc: usize) -> Result<i16, String> {
    let reg = state.regs.get(&2).ok_or_else(|| {
        format!(
            "verifier log did not expose r2 stack pointer at call pc {}",
            call_pc
        )
    })?;
    if reg.reg_type != "fp" {
        return Err(format!(
            "verifier log r2 at call pc {} has type {}, expected fp",
            call_pc, reg.reg_type
        ));
    }
    let offset = reg.offset.ok_or_else(|| {
        format!(
            "verifier log r2 stack pointer at call pc {} has no fixed offset",
            call_pc
        )
    })?;
    i16::try_from(offset).map_err(|_| {
        format!(
            "verifier log r2 stack pointer offset {} at call pc {} does not fit in i16",
            offset, call_pc
        )
    })
}

fn constant_stack_bytes_for_range(
    stack: &HashMap<i16, StackState>,
    stack_off: i16,
    key_width: usize,
) -> Option<Vec<u8>> {
    let start = i32::from(stack_off);
    let width = match i32::try_from(key_width) {
        Ok(width) => width,
        Err(_) => return None,
    };
    let end = start.checked_add(width)?;
    if start >= 0 || end > 0 {
        return None;
    }

    let mut bytes = Vec::with_capacity(key_width);
    for absolute_off in start..end {
        bytes.push(constant_stack_byte(stack, absolute_off)?);
    }
    Some(bytes)
}

fn constant_stack_byte(stack: &HashMap<i16, StackState>, absolute_off: i32) -> Option<u8> {
    if absolute_off >= 0 {
        return None;
    }
    let slot_index = ((-absolute_off - 1) / 8) + 1;
    let slot_start_i32 = -slot_index * 8;
    let slot_start = match i16::try_from(slot_start_i32) {
        Ok(slot_start) => slot_start,
        Err(_) => return None,
    };
    let byte_index = match usize::try_from(absolute_off - slot_start_i32) {
        Ok(byte_index) => byte_index,
        Err(_) => return None,
    };
    if byte_index >= 8 {
        return None;
    }

    let state = stack.get(&slot_start)?;
    let type_index = 7usize.checked_sub(byte_index)?;
    if let Some(slot_types) = state.slot_types.as_deref() {
        let slot_type = slot_types
            .as_bytes()
            .get(type_index)
            .copied()
            .or(Some(b'r'));
        if slot_type == Some(b'0') {
            return Some(0);
        }
        if slot_type != Some(b'r') {
            return None;
        }
    }

    let value = verifier_known_scalar_value(state.value.as_ref()?)?;
    Some(value.to_le_bytes()[byte_index])
}

fn materialization_for_snapshot_key(
    insns: &[BpfInsn],
    call_pc: usize,
    bounds: (usize, usize),
    stack_off: i16,
    key_width: usize,
    snapshot_bytes: &[u8],
) -> Option<ConstantStackBytes> {
    let key_width = match u8::try_from(key_width) {
        Ok(key_width) => key_width,
        Err(_) => return None,
    };
    let stack_bytes = match find_constant_stack_bytes_with_limit(
        insns,
        call_pc,
        bounds,
        stack_off,
        key_width,
        Some(CONST_STACK_VALUE_LOOKBACK_LIMIT),
    ) {
        Ok(stack_bytes) => stack_bytes,
        Err(_) => return None,
    };
    (stack_bytes.bytes == snapshot_bytes).then_some(stack_bytes)
}

fn constant_key_value(bytes: &[u8]) -> u64 {
    let mut buf = [0u8; 8];
    let copy_len = bytes.len().min(buf.len());
    buf[..copy_len].copy_from_slice(&bytes[..copy_len]);
    u64::from_le_bytes(buf)
}

fn format_constant_key(key: &ConstantKey) -> String {
    if key.bytes.len() <= 8 {
        format!("0x{:x}", key.value)
    } else {
        format_bytes_preview(&key.bytes)
    }
}

#[cfg(test)]
fn find_constant_stack_bytes(
    insns: &[BpfInsn],
    before_pc: usize,
    bounds: (usize, usize),
    stack_off: i16,
    key_width: u8,
) -> Result<ConstantStackBytes, String> {
    find_constant_stack_bytes_with_limit(insns, before_pc, bounds, stack_off, key_width, None)
}

fn find_constant_stack_bytes_with_limit(
    insns: &[BpfInsn],
    before_pc: usize,
    bounds: (usize, usize),
    stack_off: i16,
    key_width: u8,
    mut lookback_limit: Option<usize>,
) -> Result<ConstantStackBytes, String> {
    let key_width_usize = usize::from(key_width);
    let target_start = i32::from(stack_off);
    let target_end = target_start + i32::from(key_width);
    let mut raw = vec![None; key_width_usize];
    let mut latest_store_pc = None;
    let mut latest_source_imm_pc = None;
    let mut materialization_pcs = HashSet::new();
    let mut cursor = before_pc;

    while let Some(pc) = prev_real_pc_bounded(insns, cursor, bounds.0) {
        if let Some(remaining) = lookback_limit.as_mut() {
            if *remaining == 0 {
                break;
            }
            *remaining -= 1;
        }

        let insn = &insns[pc];
        let Some((store_off, width)) = resolve_stack_store_slot(insns, pc, insn, bounds) else {
            cursor = pc;
            continue;
        };
        let store_start = i32::from(store_off);
        let store_end = store_start + i32::from(width);
        let overlap_start = target_start.max(store_start);
        let overlap_end = target_end.min(store_end);
        if overlap_start >= overlap_end {
            cursor = pc;
            continue;
        }

        let bytes = constant_stack_store_bytes(insns, pc, bounds)?;
        let source_imm_pc = constant_stack_store_source_pc(insns, pc, bounds)?;
        let mut covered_new_byte = false;
        for absolute_off in overlap_start..overlap_end {
            let key_idx = usize::try_from(absolute_off - target_start).unwrap_or(usize::MAX);
            if key_idx >= key_width_usize || raw[key_idx].is_some() {
                continue;
            }
            let store_idx = usize::try_from(absolute_off - store_start).unwrap_or(usize::MAX);
            if store_idx >= bytes.len() {
                return Err(format!(
                    "stack store at pc {} does not cover expected byte offset {}",
                    pc, absolute_off
                ));
            }
            raw[key_idx] = Some(bytes[store_idx]);
            covered_new_byte = true;
        }

        if covered_new_byte {
            latest_store_pc.get_or_insert(pc);
            if latest_source_imm_pc.is_none() {
                latest_source_imm_pc = source_imm_pc;
            }
            insert_materialization_pc(&mut materialization_pcs, insns, pc);
            if let Some(source_imm_pc) = source_imm_pc {
                insert_materialization_pc(&mut materialization_pcs, insns, source_imm_pc);
            }
        }

        if raw.iter().all(Option::is_some) {
            let bytes = raw
                .into_iter()
                .map(|byte| byte.unwrap_or(0))
                .collect::<Vec<_>>();
            let mut materialization_pcs = materialization_pcs.into_iter().collect::<Vec<_>>();
            materialization_pcs.sort_unstable();
            return Ok(ConstantStackBytes {
                bytes,
                latest_store_pc: latest_store_pc.unwrap_or(pc),
                latest_source_imm_pc,
                materialization_pcs,
            });
        }

        cursor = pc;
    }

    Err(format!(
        "no constant stack store sequence found for fp{} width {}",
        stack_off, key_width
    ))
}

fn constant_stack_store_bytes(
    insns: &[BpfInsn],
    store_pc: usize,
    bounds: (usize, usize),
) -> Result<Vec<u8>, String> {
    let insn = &insns[store_pc];
    let width = size_in_bytes(bpf_size(insn.code)).ok_or_else(|| {
        format!(
            "stack store at pc {} uses unsupported width opcode {:#x}",
            store_pc, insn.code
        )
    })?;

    let value = if bpf_class(insn.code) == BPF_ST {
        truncate_imm(insn.imm, width)
    } else if bpf_class(insn.code) == BPF_STX {
        let resolved = resolve_constant_reg_value(insns, store_pc, insn.src_reg(), bounds)?;
        truncate_value(resolved.value, width)
    } else {
        return Err(format!(
            "instruction at pc {} is not a stack store",
            store_pc
        ));
    };

    Ok(value.to_le_bytes()[..usize::from(width)].to_vec())
}

fn constant_stack_store_source_pc(
    insns: &[BpfInsn],
    store_pc: usize,
    bounds: (usize, usize),
) -> Result<Option<usize>, String> {
    let insn = &insns[store_pc];
    if bpf_class(insn.code) == BPF_ST {
        return Ok(None);
    }
    if bpf_class(insn.code) != BPF_STX {
        return Err(format!(
            "instruction at pc {} is not a stack store",
            store_pc
        ));
    }
    Ok(resolve_constant_reg_value(insns, store_pc, insn.src_reg(), bounds)?.source_pc)
}

fn verifier_known_scalar_value(reg: &crate::pass::RegState) -> Option<u64> {
    if reg.reg_type != "scalar" || !reg.precise {
        return None;
    }

    reg.exact_u64().or_else(|| reg.exact_u32().map(u64::from))
}

/// Classify all uses of the lookup result until its value-pointer aliases die out.
#[cfg(test)]
fn classify_r0_uses(insns: &[BpfInsn], call_pc: usize) -> R0UseClassification {
    classify_r0_uses_with_options(insns, call_pc, false, false)
}

#[derive(Clone, Debug)]
struct SiteRewrite {
    call_pc: usize,
    diagnostic_value: String,
    removed_null_check: bool,
    map_inline_records: Vec<MapInlineRecord>,
    skipped_pcs: HashSet<usize>,
    replacements: BTreeMap<usize, Vec<BpfInsn>>,
    branch_patches: Vec<ReplacementBranchPatch>,
}

#[derive(Clone, Debug, PartialEq, Eq)]
struct ReplacementBranchPatch {
    replacement_pc: usize,
    replacement_insn_idx: usize,
    target_old_pc: usize,
}

#[derive(Debug)]
enum SiteRewriteError {
    Veto(String),
    MissingSnapshot(anyhow::Error),
    Error(anyhow::Error),
}

type SiteRewriteResult<T> = std::result::Result<T, SiteRewriteError>;

impl From<anyhow::Error> for SiteRewriteError {
    fn from(err: anyhow::Error) -> Self {
        SiteRewriteError::Error(err)
    }
}

#[derive(Clone, Debug)]
struct KernelMutableMaps {
    ids: HashSet<u32>,
    reasons: HashMap<u32, String>,
}

#[derive(Clone, Debug, Default)]
struct ResolvedInlineHints {
    by_call_pc: HashMap<usize, Vec<ResolvedInlineHint>>,
}

#[derive(Clone, Debug)]
struct HintedMapInMapRoute {
    inner_call_pc: usize,
    inner_info: MapInfo,
}

#[derive(Clone, Debug, PartialEq, Eq)]
enum ResolvedInlineValue {
    Value(Vec<u8>),
    Null,
}

#[derive(Clone, Debug)]
struct ResolvedInlineHint {
    anchor: MapInlineHintAnchor,
    mode: MapInlineHintMode,
    key: Vec<u8>,
    inline_value: ResolvedInlineValue,
    map_id: u32,
}

impl ResolvedInlineHints {
    fn for_call(&self, call_pc: usize) -> &[ResolvedInlineHint] {
        self.by_call_pc
            .get(&call_pc)
            .map(Vec::as_slice)
            .unwrap_or(&[])
    }
}

fn is_map_lookup_elem_call(insn: &BpfInsn) -> bool {
    insn.is_call() && insn.src_reg() == 0 && insn.imm == libbpf_sys::BPF_FUNC_map_lookup_elem as i32
}

fn collect_kernel_mutable_maps(
    program: &BpfProgram,
    map_info: &MapInfoResult,
) -> anyhow::Result<KernelMutableMaps> {
    let mut ids = HashSet::new();
    let mut reasons = HashMap::new();

    for metadata in program.map_metadata.values() {
        if lru_lookup_mutates_map(metadata.map_type) {
            ids.insert(metadata.map_id);
            reasons.insert(
                metadata.map_id,
                format!(
                    "map kernel-mutable: LRU map lookup mutates access order on map_id={}",
                    metadata.map_id
                ),
            );
        }
    }
    for info in &map_info.unique_maps {
        if ids.contains(&info.map_id) || !lru_lookup_mutates_map(info.map_type) {
            continue;
        }
        ids.insert(info.map_id);
        reasons.insert(
            info.map_id,
            format!(
                "map kernel-mutable: LRU map lookup mutates access order on map_id={}",
                info.map_id
            ),
        );
    }

    let mut pc = 0usize;
    while pc < program.insns.len() {
        let insn = &program.insns[pc];
        if is_map_writer_helper_call(insn) {
            let Some(map_load_pc) = find_direct_map_load_for_reg_before_pc(&program.insns, pc, 1)
            else {
                // A writer can target a runtime inner-map pointer produced by
                // map-in-map lookup. That does not identify a direct outer map
                // as kernel-mutable.
                pc += insn_width(insn);
                continue;
            };
            let helper_name = map_writer_helper_name(insn.imm);
            let map_ref = map_info.reference_at_pc(map_load_pc).ok_or_else(|| {
                anyhow::anyhow!(
                    "map_inline cannot resolve map reference at pc {map_load_pc} for {helper_name} helper at pc {pc}"
                )
            })?;
            let map_id = map_ref.map_id.ok_or_else(|| {
                anyhow::anyhow!(
                    "map_inline cannot resolve map_id at pc {map_load_pc} for {helper_name} helper at pc {pc}"
                )
            })?;
            ids.insert(map_id);
            reasons.insert(
                map_id,
                format!(
                    "map kernel-mutable: bytecode contains BPF_FUNC_map_update_elem/delete_elem/push_elem/pop_elem on map_id={map_id}"
                ),
            );
        }
        pc += insn_width(insn);
    }

    Ok(KernelMutableMaps { ids, reasons })
}

fn is_map_writer_helper_call(insn: &BpfInsn) -> bool {
    insn.is_call()
        && insn.src_reg() == 0
        && (insn.imm == libbpf_sys::BPF_FUNC_map_update_elem as i32
            || insn.imm == libbpf_sys::BPF_FUNC_map_delete_elem as i32
            || insn.imm == libbpf_sys::BPF_FUNC_map_push_elem as i32
            || insn.imm == libbpf_sys::BPF_FUNC_map_pop_elem as i32)
}

fn map_writer_helper_name(helper_id: i32) -> &'static str {
    if helper_id == libbpf_sys::BPF_FUNC_map_update_elem as i32 {
        "BPF_FUNC_map_update_elem"
    } else if helper_id == libbpf_sys::BPF_FUNC_map_delete_elem as i32 {
        "BPF_FUNC_map_delete_elem"
    } else if helper_id == libbpf_sys::BPF_FUNC_map_push_elem as i32 {
        "BPF_FUNC_map_push_elem"
    } else if helper_id == libbpf_sys::BPF_FUNC_map_pop_elem as i32 {
        "BPF_FUNC_map_pop_elem"
    } else {
        "BPF_FUNC_<non-writer>"
    }
}

fn lru_lookup_mutates_map(map_type: u32) -> bool {
    matches!(
        map_type,
        libbpf_sys::BPF_MAP_TYPE_LRU_HASH | libbpf_sys::BPF_MAP_TYPE_LRU_PERCPU_HASH
    )
}

fn kernel_mutable_reason_for_map(
    kernel_mutable_maps: &KernelMutableMaps,
    info: &MapInfo,
) -> Option<String> {
    if let Some(reason) = kernel_mutable_maps.reasons.get(&info.map_id) {
        return Some(reason.clone());
    }
    if kernel_mutable_maps.ids.contains(&info.map_id) {
        return Some(format!(
            "map kernel-mutable: bytecode contains BPF_FUNC_map_update_elem/delete_elem/push_elem/pop_elem on map_id={}",
            info.map_id
        ));
    }
    lru_lookup_mutates_map(info.map_type).then(|| {
        format!(
            "map kernel-mutable: LRU map lookup mutates access order on map_id={}",
            info.map_id
        )
    })
}

fn resolve_inline_hints(
    program: &BpfProgram,
    map_info: &MapInfoResult,
    kernel_mutable_maps: &KernelMutableMaps,
) -> anyhow::Result<ResolvedInlineHints> {
    if program.map_inline_hints.is_empty() {
        return Ok(ResolvedInlineHints::default());
    }

    let sites = find_map_lookup_sites(&program.insns);
    let mut sites_by_pc = HashMap::new();
    for site in &sites {
        sites_by_pc.insert(site.call_pc, site);
    }

    let mut resolved = ResolvedInlineHints::default();
    let mut deferred_inner_hints = Vec::new();
    for hint in &program.map_inline_hints {
        let resolved_direct = match &hint.anchor {
            MapInlineHintAnchor::Pc(call_pc) => resolve_pc_inline_hint(
                program,
                map_info,
                kernel_mutable_maps,
                &sites_by_pc,
                hint,
                *call_pc,
                &mut resolved,
            )?,
            MapInlineHintAnchor::MapName(name) => resolve_map_name_inline_hint(
                program,
                map_info,
                kernel_mutable_maps,
                &sites,
                hint,
                name,
                &mut resolved,
            )?,
        };
        if !resolved_direct {
            deferred_inner_hints.push(hint.clone());
        }
    }

    resolve_map_in_map_route_a_hints(
        program,
        map_info,
        kernel_mutable_maps,
        &sites,
        &deferred_inner_hints,
        &mut resolved,
    )?;

    validate_resolved_site_hint_modes(&resolved)?;
    Ok(resolved)
}

fn resolve_map_in_map_route_a_hints(
    program: &BpfProgram,
    map_info: &MapInfoResult,
    kernel_mutable_maps: &KernelMutableMaps,
    sites: &[MapLookupSite],
    deferred_inner_hints: &[MapInlineHint],
    resolved: &mut ResolvedInlineHints,
) -> anyhow::Result<()> {
    if deferred_inner_hints.is_empty() {
        return Ok(());
    }

    let routes = resolve_hinted_map_in_map_routes(program, map_info, sites, resolved)?;
    if routes.is_empty() {
        let has_map_in_map_outer_hint =
            has_resolved_map_in_map_outer_hint(map_info, sites, resolved)?;
        let has_known_inner_hint = deferred_inner_hints.iter().try_fold(false, |found, hint| {
            deferred_hint_targets_known_map_in_map_inner(program, sites, hint)
                .map(|matches| found || matches)
        })?;
        if has_map_in_map_outer_hint || has_known_inner_hint {
            bail!(
                "inner inline hint anchor {} has no matching map-in-map outer hint",
                format_hint_anchor(&deferred_inner_hints[0].anchor)
            );
        }
        return Ok(());
    }

    let mut matched = vec![false; deferred_inner_hints.len()];
    for route in &routes {
        for (idx, hint) in deferred_inner_hints.iter().enumerate() {
            if !inner_hint_matches_route(program, hint, route)? {
                continue;
            }
            validate_and_insert_site_hint(
                program,
                kernel_mutable_maps,
                hint,
                route.inner_call_pc,
                &route.inner_info,
                resolved,
            )?;
            matched[idx] = true;
        }
    }

    for (idx, hint) in deferred_inner_hints.iter().enumerate() {
        if !matched[idx] && deferred_hint_targets_known_map_in_map_inner(program, sites, hint)? {
            bail!(
                "inner inline hint anchor {} has no matching map-in-map outer hint",
                format_hint_anchor(&hint.anchor)
            );
        }
    }

    Ok(())
}

fn resolve_hinted_map_in_map_routes(
    program: &BpfProgram,
    map_info: &MapInfoResult,
    sites: &[MapLookupSite],
    resolved: &ResolvedInlineHints,
) -> anyhow::Result<Vec<HintedMapInMapRoute>> {
    let mut routes = Vec::new();
    for outer_site in sites {
        let outer_info = lookup_site_map_info(map_info, outer_site)?;
        if !outer_info.is_map_in_map() || resolved.for_call(outer_site.call_pc).is_empty() {
            continue;
        }
        for outer_hint in resolved.for_call(outer_site.call_pc) {
            let encoded_outer_key = encode_key_bytes(&outer_hint.key, outer_info.key_size as usize);
            let inner_map_id =
                resolve_inner_map_id_for_outer_key(program, outer_info, &encoded_outer_key)
                    .map_err(|err| map_route_a_error(outer_hint, outer_info, err))?;
            let inner_info = program
                .map_provider
                .map_info(program, inner_map_id)
                .map_err(anyhow::Error::msg)?
                .ok_or_else(|| {
                    anyhow::anyhow!(
                        "map_values snapshot has no metadata for inner map {} from outer map {} key {}",
                        inner_map_id,
                        outer_info.map_id,
                        format_bytes_preview(&encoded_outer_key)
                    )
                })?;
            let Some(chain) =
                find_map_in_map_chains(&program.insns, std::slice::from_ref(outer_site))
                    .into_iter()
                    .next()
            else {
                continue;
            };
            routes.push(HintedMapInMapRoute {
                inner_call_pc: chain.inner_call_pc,
                inner_info,
            });
        }
    }
    Ok(routes)
}

fn has_resolved_map_in_map_outer_hint(
    map_info: &MapInfoResult,
    sites: &[MapLookupSite],
    resolved: &ResolvedInlineHints,
) -> anyhow::Result<bool> {
    for site in sites {
        if resolved.for_call(site.call_pc).is_empty() {
            continue;
        }
        if lookup_site_map_info(map_info, site)?.is_map_in_map() {
            return Ok(true);
        }
    }
    Ok(false)
}

fn deferred_hint_targets_known_map_in_map_inner(
    program: &BpfProgram,
    sites: &[MapLookupSite],
    hint: &MapInlineHint,
) -> anyhow::Result<bool> {
    match &hint.anchor {
        MapInlineHintAnchor::Pc(call_pc) => Ok(find_map_in_map_chains(&program.insns, sites)
            .iter()
            .any(|chain| chain.inner_call_pc == *call_pc)),
        MapInlineHintAnchor::MapName(name) => {
            let map_ids = metadata_map_ids_for_name(program, name)?;
            Ok(map_ids
                .iter()
                .any(|map_id| map_id_is_known_inner_map(program, *map_id)))
        }
    }
}

fn map_id_is_known_inner_map(program: &BpfProgram, map_id: u32) -> bool {
    program
        .map_inner_map_ids
        .values()
        .any(|inner_map_id| *inner_map_id == map_id)
}

fn map_route_a_error(
    hint: &ResolvedInlineHint,
    outer_info: &MapInfo,
    err: SiteRewriteError,
) -> anyhow::Error {
    match err {
        SiteRewriteError::Veto(reason) => anyhow::anyhow!(
            "inline hint anchor {} key {} for map-in-map outer map_id={}: {}",
            format_hint_anchor(&hint.anchor),
            format_bytes_preview(&hint.key),
            outer_info.map_id,
            reason
        ),
        SiteRewriteError::MissingSnapshot(err) | SiteRewriteError::Error(err) => err,
    }
}

fn inner_hint_matches_route(
    program: &BpfProgram,
    hint: &MapInlineHint,
    route: &HintedMapInMapRoute,
) -> anyhow::Result<bool> {
    match &hint.anchor {
        MapInlineHintAnchor::Pc(call_pc) => Ok(*call_pc == route.inner_call_pc),
        MapInlineHintAnchor::MapName(name) => {
            let map_ids = metadata_map_ids_for_name(program, name)?;
            Ok(map_ids.contains(&route.inner_info.map_id))
        }
    }
}

fn metadata_map_ids_for_name(program: &BpfProgram, name: &str) -> anyhow::Result<HashSet<u32>> {
    let matched = program
        .map_metadata
        .values()
        .filter(|metadata| metadata.name == name)
        .map(|metadata| metadata.map_id)
        .collect::<HashSet<_>>();
    if matched.is_empty() {
        bail!("inline hint map_name anchor {name:?} is not present in map_values metadata");
    }
    Ok(matched)
}

fn resolve_pc_inline_hint(
    program: &BpfProgram,
    map_info: &MapInfoResult,
    kernel_mutable_maps: &KernelMutableMaps,
    sites_by_pc: &HashMap<usize, &MapLookupSite>,
    hint: &MapInlineHint,
    call_pc: usize,
    resolved: &mut ResolvedInlineHints,
) -> anyhow::Result<bool> {
    let Some(insn) = program.insns.get(call_pc) else {
        bail!("inline hint at pc {call_pc} does not point to a map_lookup_elem helper call");
    };
    if !is_map_lookup_elem_call(insn) {
        bail!("inline hint at pc {call_pc} does not point to a map_lookup_elem helper call");
    }
    let Some(site) = sites_by_pc.get(&call_pc) else {
        return Ok(false);
    };
    let info = lookup_site_map_info(map_info, site)?;
    validate_and_insert_site_hint(program, kernel_mutable_maps, hint, call_pc, info, resolved)?;
    Ok(true)
}

fn resolve_map_name_inline_hint(
    program: &BpfProgram,
    map_info: &MapInfoResult,
    kernel_mutable_maps: &KernelMutableMaps,
    sites: &[MapLookupSite],
    hint: &MapInlineHint,
    name: &str,
    resolved: &mut ResolvedInlineHints,
) -> anyhow::Result<bool> {
    let map_ids = direct_map_ids_for_name(program, map_info, name)?;
    if map_ids.is_empty() {
        return Ok(false);
    }
    let mut matched_sites = 0usize;
    for site in sites {
        let info = lookup_site_map_info(map_info, site)?;
        if !map_ids.contains(&info.map_id) {
            continue;
        }
        matched_sites += 1;
        validate_and_insert_site_hint(
            program,
            kernel_mutable_maps,
            hint,
            site.call_pc,
            info,
            resolved,
        )?;
    }
    if matched_sites == 0 {
        bail!(
            "inline hint map_name anchor {name:?} is present in used_maps but matches no map_lookup_elem site"
        );
    }
    Ok(true)
}

fn lookup_site_map_info<'a>(
    map_info: &'a MapInfoResult,
    site: &MapLookupSite,
) -> anyhow::Result<&'a MapInfo> {
    let map_ref = map_info.reference_at_pc(site.map_load_pc).ok_or_else(|| {
        anyhow::anyhow!(
            "map reference metadata unavailable for lookup pc {}",
            site.call_pc
        )
    })?;
    map_ref
        .info
        .as_ref()
        .ok_or_else(|| anyhow::anyhow!("map info unavailable for lookup pc {}", site.call_pc))
}

fn direct_map_ids_for_name(
    program: &BpfProgram,
    map_info: &MapInfoResult,
    name: &str,
) -> anyhow::Result<HashSet<u32>> {
    let mut matched = HashSet::new();
    for info in &map_info.unique_maps {
        let metadata = program.map_metadata.get(&info.map_id).ok_or_else(|| {
            anyhow::anyhow!(
                "map_values snapshot has no metadata for used map {} while resolving inline hint map_name anchor {name:?}",
                info.map_id
            )
        })?;
        if metadata.name == name {
            matched.insert(info.map_id);
        }
    }
    Ok(matched)
}

fn validate_and_insert_site_hint(
    program: &BpfProgram,
    kernel_mutable_maps: &KernelMutableMaps,
    hint: &MapInlineHint,
    call_pc: usize,
    info: &MapInfo,
    resolved: &mut ResolvedInlineHints,
) -> anyhow::Result<()> {
    if let Some(reason) = kernel_mutable_reason_for_map(kernel_mutable_maps, info) {
        bail!(
            "inline hint anchor {} targets kernel-mutable map_id={}: {}",
            format_hint_anchor(&hint.anchor),
            info.map_id,
            reason
        );
    }
    if hint.key.len() != info.key_size as usize {
        bail!(
            "inline hint anchor {} has {} key byte(s) for map_id={}, expected {}",
            format_hint_anchor(&hint.anchor),
            hint.key.len(),
            info.map_id,
            info.key_size
        );
    }
    if info.is_map_in_map() {
        if hint.mode != MapInlineHintMode::Hard {
            bail!(
                "map-in-map outer inline hint anchor {} must use hard fold",
                format_hint_anchor(&hint.anchor)
            );
        }
        resolved
            .by_call_pc
            .entry(call_pc)
            .or_default()
            .push(ResolvedInlineHint {
                anchor: hint.anchor.clone(),
                mode: hint.mode,
                key: hint.key.clone(),
                inline_value: ResolvedInlineValue::Value(Vec::new()),
                map_id: info.map_id,
            });
        return Ok(());
    }
    let inline_value =
        read_hint_inline_value(program, info, hint.mode, &hint.key).with_context(|| {
            format!(
                "inline hint anchor {} key {} for map_id={}",
                format_hint_anchor(&hint.anchor),
                format_bytes_preview(&hint.key),
                info.map_id
            )
        })?;

    resolved
        .by_call_pc
        .entry(call_pc)
        .or_default()
        .push(ResolvedInlineHint {
            anchor: hint.anchor.clone(),
            mode: hint.mode,
            key: hint.key.clone(),
            inline_value,
            map_id: info.map_id,
        });
    Ok(())
}

fn read_hint_inline_value(
    program: &BpfProgram,
    info: &MapInfo,
    mode: MapInlineHintMode,
    key: &[u8],
) -> anyhow::Result<ResolvedInlineValue> {
    let value_size = program
        .map_provider
        .lookup_value_size(program, info)
        .map_err(anyhow::Error::msg)?;
    let value = match program
        .map_provider
        .lookup_elem(program, info.map_id, key, value_size)
    {
        Ok(value) => value,
        Err(MapLookupError::MissingKey { .. })
            if mode == MapInlineHintMode::Hard
                && enumerated_overlay_missing_key(program, info.map_id, key) =>
        {
            return Ok(ResolvedInlineValue::Null);
        }
        Err(err) => {
            return Err(anyhow::anyhow!(
                "hint key is not present in map dump: {err}"
            ))
        }
    };
    prepare_inline_value(info, &value)
        .map(ResolvedInlineValue::Value)
        .map_err(anyhow::Error::msg)
}

fn enumerated_overlay_missing_key(program: &BpfProgram, map_id: u32, key: &[u8]) -> bool {
    matches!(
        program.map_value_overlays.get(&map_id).map(|overlay| &overlay.kind),
        Some(CompressedMapValuesKind::Enumerated { entries }) if !entries.contains_key(key)
    )
}

fn validate_resolved_site_hint_modes(resolved: &ResolvedInlineHints) -> anyhow::Result<()> {
    for (call_pc, hints) in &resolved.by_call_pc {
        let hard_count = hints
            .iter()
            .filter(|hint| hint.mode == MapInlineHintMode::Hard)
            .count();
        let soft_count = hints
            .iter()
            .filter(|hint| hint.mode == MapInlineHintMode::Soft)
            .count();
        if hard_count > 1 {
            bail!("lookup pc {call_pc} has multiple hard inline hints");
        }
        if hard_count > 0 && soft_count > 0 {
            bail!("lookup pc {call_pc} mixes soft and hard inline hints");
        }
    }
    Ok(())
}

impl BpfPass for MapInlinePass {
    fn name(&self) -> &str {
        "map_inline"
    }

    fn required_analyses(&self) -> Vec<&str> {
        vec!["branch_targets", "map_info"]
    }

    fn run(
        &self,
        program: &mut BpfProgram,
        analyses: &mut AnalysisCache,
        _ctx: &PassContext,
    ) -> anyhow::Result<PassResult> {
        let initial_map_info = analyses
            .get(&MapInfoAnalysis, program)
            .map_err(anyhow::Error::msg)?;
        let initial_kernel_mutable_maps = collect_kernel_mutable_maps(program, &initial_map_info)?;
        let initial_inline_hints =
            resolve_inline_hints(program, &initial_map_info, &initial_kernel_mutable_maps)?;
        let mut total_applied = 0usize;
        let mut final_skipped = Vec::new();
        let mut diagnostics = Vec::new();
        let mut map_inline_records = Vec::new();
        let mut hit_iteration_cap = false;
        let mut inline_hints_consumed = HashSet::<MapInlineHintAnchor>::new();

        for iter in 0..MAP_INLINE_FIXED_POINT_MAX_ITERS {
            let before_round = program.insns.clone();
            let empty_hints = ResolvedInlineHints::default();
            let round_inline_hints = if iter == 0 {
                &initial_inline_hints
            } else {
                &empty_hints
            };
            let round = run_map_inline_round(
                program,
                analyses,
                iter == 0,
                round_inline_hints,
                &mut inline_hints_consumed,
            )?;
            let round_modified = program.insns != before_round;

            final_skipped = round.sites_skipped;
            total_applied += round.sites_applied;
            map_inline_records.extend(round.map_inline_records);
            if iter == 0 {
                diagnostics.extend(round.diagnostics);
            } else {
                diagnostics.extend(
                    round
                        .diagnostics
                        .into_iter()
                        .map(|diag| format!("round {}: {}", iter + 1, diag)),
                );
            }

            if !round_modified {
                break;
            }

            analyses.invalidate_all();
            hit_iteration_cap = iter + 1 == MAP_INLINE_FIXED_POINT_MAX_ITERS;
        }

        if hit_iteration_cap {
            record_diagnostic(
                &mut diagnostics,
                format!(
                    "stopped after {} map_inline fixpoint rounds",
                    MAP_INLINE_FIXED_POINT_MAX_ITERS
                ),
            );
        }

        if !program.map_inline_hints.is_empty() {
            record_diagnostic(
                &mut diagnostics,
                format!("inline_hints_consumed={}", inline_hints_consumed.len()),
            );
        }

        Ok(PassResult {
            pass_name: self.name().into(),
            sites_applied: total_applied,
            sites_skipped: final_skipped,
            diagnostics,
            map_inline_records,
            ..Default::default()
        })
    }
}

fn run_map_inline_round(
    program: &mut BpfProgram,
    analyses: &mut AnalysisCache,
    use_verifier_guided_keys: bool,
    inline_hints: &ResolvedInlineHints,
    inline_hints_consumed: &mut HashSet<MapInlineHintAnchor>,
) -> anyhow::Result<PassResult> {
    let bt = analyses.get(&BranchTargetAnalysis, program);
    let map_info = analyses
        .get(&MapInfoAnalysis, program)
        .map_err(anyhow::Error::msg)?;
    let kernel_mutable_maps = collect_kernel_mutable_maps(program, &map_info)?;
    let mut skipped = Vec::new();
    let mut rewrites = Vec::new();
    let mut diagnostics = Vec::new();
    if use_verifier_guided_keys {
        record_maps_skipped_by_size_counter(program, &mut diagnostics);
    }
    let (direct_replacements, direct_sites_applied, direct_diagnostics, direct_records) =
        build_direct_map_value_load_rewrites(program, &kernel_mutable_maps)?;
    diagnostics.extend(direct_diagnostics);
    let sites = find_map_lookup_sites(&program.insns);

    log_map_inline_debug(&format!(
        "found {} lookup sites (verifier_guided_keys={})",
        sites.len(),
        use_verifier_guided_keys
    ));

    for site in sites {
        log_map_inline_debug(&format!(
            "evaluating site at PC={} (map_load_pc={})",
            site.call_pc, site.map_load_pc
        ));
        let Some(map_ref) = map_info.reference_at_pc(site.map_load_pc) else {
            log_map_inline_debug(&format!(
                "site pc={} skip: map reference unavailable",
                site.call_pc
            ));
            let reason = "map reference metadata unavailable".to_string();
            record_skip(&mut skipped, &mut diagnostics, site.call_pc, reason, None);
            continue;
        };
        log_map_inline_debug(&format!(
            "site at PC={}: map_ref imm={} map_index={} map_id={:?}",
            site.call_pc, map_ref.imm, map_ref.map_index, map_ref.map_id
        ));
        let Some(info) = map_ref.info.as_ref() else {
            let reason = "map info unavailable".to_string();
            record_skip(&mut skipped, &mut diagnostics, site.call_pc, reason, None);
            continue;
        };
        log_map_inline_debug(&format!(
            "site at PC={}: resolved map_id={} map_type={} key_size={} value_size={} max_entries={}",
            site.call_pc,
            info.map_id,
            info.map_type,
            info.key_size,
            info.value_size,
            info.max_entries,
        ));
        if let Some(reason) = kernel_mutable_reason_for_map(&kernel_mutable_maps, info) {
            record_skip(&mut skipped, &mut diagnostics, site.call_pc, reason, None);
            continue;
        }
        if map_snapshot_skipped_by_size(program, info.map_id) {
            log_map_inline_debug(&format!(
                "site pc={} skip: map {} snapshot skipped by size",
                site.call_pc, info.map_id
            ));
            let reason = map_snapshot_skipped_by_size_site_reason(program, info.map_id);
            record_skip(&mut skipped, &mut diagnostics, site.call_pc, reason, None);
            continue;
        }
        if info.is_map_in_map() {
            match build_map_in_map_chain_rewrite(
                program,
                &site,
                info,
                use_verifier_guided_keys,
                inline_hints,
                &kernel_mutable_maps,
                inline_hints_consumed,
            ) {
                Ok(Some(mut rewrite)) => {
                    if rewrite
                        .skipped_pcs
                        .iter()
                        .any(|&pc| pc < bt.is_target.len() && bt.is_target[pc])
                    {
                        record_diagnostic(
                            &mut diagnostics,
                            format!(
                                "site at PC={}: keeping map-in-map lookup chain because removal would cross a branch target",
                                site.call_pc
                            ),
                        );
                        rewrite.skipped_pcs.clear();
                        rewrite.removed_null_check = false;
                    }
                    if rewrite
                        .replacements
                        .keys()
                        .any(|pc| rewrite.skipped_pcs.contains(pc))
                    {
                        let reason = "internal rewrite overlap".to_string();
                        record_skip(&mut skipped, &mut diagnostics, site.call_pc, reason, None);
                        continue;
                    }
                    log_map_inline_debug(&format!(
                        "site at PC={}: map-in-map rewrite prepared with {} replacement load(s), removed_null_check={}",
                        site.call_pc,
                        rewrite.replacements.len(),
                        rewrite.removed_null_check
                    ));
                    rewrites.push(rewrite);
                }
                Ok(None) => {
                    let reason = "map-in-map chain is not inlineable".to_string();
                    record_skip(&mut skipped, &mut diagnostics, site.call_pc, reason, None);
                }
                Err(err) => match err {
                    SiteRewriteError::Veto(reason) => {
                        record_skip(&mut skipped, &mut diagnostics, site.call_pc, reason, None);
                        continue;
                    }
                    SiteRewriteError::MissingSnapshot(err) => {
                        return Err(err.context(format!(
                            "map_inline requires a concrete map-in-map snapshot at outer lookup pc {}",
                            site.call_pc
                        )));
                    }
                    SiteRewriteError::Error(err) => return Err(err),
                },
            }
            continue;
        }
        let site_inline_hints = inline_hints.for_call(site.call_pc);
        if hard_null_hint(site_inline_hints).is_some() {
            let extracted_key = match extract_site_constant_key(
                program,
                site.call_pc,
                info,
                use_verifier_guided_keys,
                site_inline_hints,
            ) {
                Ok(extracted_key) => extracted_key,
                Err(KeyExtractionError::Unavailable(detail)) => {
                    record_skip(
                        &mut skipped,
                        &mut diagnostics,
                        site.call_pc,
                        "lookup key is not available from inline hint".into(),
                        Some(format!("site at PC={}: {}", site.call_pc, detail)),
                    );
                    continue;
                }
            };
            if let Some(anchor) = extracted_key.used_inline_hint {
                inline_hints_consumed.insert(anchor);
            }
            let key = extracted_key.key;
            if key.width < info.key_size as usize {
                let reason = format!(
                    "key width {} is smaller than map key size {}",
                    key.width, info.key_size
                );
                record_skip(&mut skipped, &mut diagnostics, site.call_pc, reason, None);
                continue;
            }
            let mut rewrite = build_hard_null_site_rewrite(program, &site, &key, info);
            if rewrite
                .skipped_pcs
                .iter()
                .any(|&pc| pc < bt.is_target.len() && bt.is_target[pc])
            {
                record_diagnostic(
                    &mut diagnostics,
                    format!(
                        "site at PC={}: keeping lookup setup because removal would cross a branch target",
                        site.call_pc
                    ),
                );
                rewrite.skipped_pcs.clear();
            }
            rewrites.push(rewrite);
            continue;
        }
        if !info.supports_direct_value_inline() {
            log_map_inline_debug(&format!(
                "site pc={} skip: map type {} not inlineable",
                site.call_pc, info.map_type
            ));
            let reason = format!("map type {} not inlineable", info.map_type);
            record_skip(
                &mut skipped,
                &mut diagnostics,
                site.call_pc,
                reason,
                Some(format!(
                    "site at PC={}: map_type={}, skip reason: unsupported map type",
                    site.call_pc, info.map_type
                )),
            );
            continue;
        }

        if site_inline_hints
            .iter()
            .any(|hint| hint.mode == MapInlineHintMode::Soft)
        {
            match build_soft_hint_site_rewrite(program, &site, info, site_inline_hints) {
                Ok(Some(rewrite)) => {
                    for hint in site_inline_hints {
                        inline_hints_consumed.insert(hint.anchor.clone());
                    }
                    if rewrite
                        .skipped_pcs
                        .iter()
                        .any(|&pc| pc < bt.is_target.len() && bt.is_target[pc])
                    {
                        let reason = "soft fold removal would cross a branch target".to_string();
                        record_skip(&mut skipped, &mut diagnostics, site.call_pc, reason, None);
                        continue;
                    }
                    if rewrite
                        .replacements
                        .keys()
                        .any(|pc| rewrite.skipped_pcs.contains(pc))
                    {
                        let reason = "internal rewrite overlap".to_string();
                        record_skip(&mut skipped, &mut diagnostics, site.call_pc, reason, None);
                        continue;
                    }
                    rewrites.push(rewrite);
                }
                Ok(None) => {
                    let reason = "soft inline hint emitted no replacement bytecode".to_string();
                    record_skip(&mut skipped, &mut diagnostics, site.call_pc, reason, None);
                }
                Err(SiteRewriteError::Veto(reason)) => {
                    record_skip(&mut skipped, &mut diagnostics, site.call_pc, reason, None);
                }
                Err(SiteRewriteError::MissingSnapshot(err) | SiteRewriteError::Error(err)) => {
                    return Err(err);
                }
            }
            continue;
        }

        let extracted_key = match extract_site_constant_key(
            program,
            site.call_pc,
            info,
            use_verifier_guided_keys,
            site_inline_hints,
        ) {
            Ok(extracted_key) => extracted_key,
            Err(KeyExtractionError::Unavailable(detail)) => {
                record_skip(
                    &mut skipped,
                    &mut diagnostics,
                    site.call_pc,
                    "lookup key is not available from verifier-guided state".into(),
                    Some(format!("site at PC={}: {}", site.call_pc, detail)),
                );
                continue;
            }
        };
        if let Some(anchor) = extracted_key.used_inline_hint {
            inline_hints_consumed.insert(anchor);
        }
        let key = extracted_key.key;
        if key.width < info.key_size as usize {
            let reason = format!(
                "key width {} is smaller than map key size {}",
                key.width, info.key_size
            );
            record_skip(&mut skipped, &mut diagnostics, site.call_pc, reason, None);
            continue;
        }
        if info.has_removable_lookup_pattern()
            && key.bytes.len() <= 8
            && key.value >= info.max_entries as u64
        {
            let reason = format!(
                "constant key {} out of range for max_entries {}",
                key.value, info.max_entries
            );
            record_skip(&mut skipped, &mut diagnostics, site.call_pc, reason, None);
            continue;
        }

        let uses = classify_r0_uses_with_options(
            &program.insns,
            site.call_pc,
            info.has_removable_lookup_pattern(),
            info.has_removable_lookup_pattern(),
        );
        let null_check_pc = uses.null_check_pc;
        if info.requires_entry_presence_check() && null_check_pc.is_none() {
            let reason = "hash map inline requires an immediate null check".to_string();
            record_skip(&mut skipped, &mut diagnostics, site.call_pc, reason, None);
            continue;
        }
        log_map_inline_debug(&format!(
            "site at PC={}: null_check_pc={:?} alias_copies={} fixed_loads={} other_uses={}",
            site.call_pc,
            null_check_pc,
            uses.alias_copy_pcs.len(),
            uses.fixed_loads.len(),
            uses.other_uses.len()
        ));
        if uses.fixed_loads.is_empty() {
            let reason = "lookup result is not consumed by fixed-offset scalar loads".to_string();
            record_skip(&mut skipped, &mut diagnostics, site.call_pc, reason, None);
            continue;
        }
        let mut rewrite = match build_site_rewrite(program, &site, &key, &uses, info, null_check_pc)
        {
            Ok(Some(rewrite)) => rewrite,
            Ok(None) => {
                let reason = "failed to materialize replacement constants".to_string();
                record_skip(&mut skipped, &mut diagnostics, site.call_pc, reason, None);
                continue;
            }
            Err(err) => match err {
                SiteRewriteError::Veto(reason) => {
                    record_skip(&mut skipped, &mut diagnostics, site.call_pc, reason, None);
                    continue;
                }
                SiteRewriteError::MissingSnapshot(err) => {
                    return Err(err.context(format!(
                        "map_inline requires a concrete snapshot value for map {} key {} at lookup pc {}",
                        info.map_id,
                        format_bytes_preview(&key.bytes),
                        site.call_pc
                    )));
                }
                SiteRewriteError::Error(err) => return Err(err),
            },
        };

        if rewrite
            .skipped_pcs
            .iter()
            .any(|&pc| pc < bt.is_target.len() && bt.is_target[pc])
        {
            record_diagnostic(
                &mut diagnostics,
                format!(
                    "site at PC={}: keeping lookup pattern because removal would cross a branch target",
                    site.call_pc
                ),
            );
            rewrite.skipped_pcs.clear();
            rewrite.removed_null_check = false;
        }

        if rewrite
            .replacements
            .keys()
            .any(|pc| rewrite.skipped_pcs.contains(pc))
        {
            let reason = "internal rewrite overlap".to_string();
            record_skip(&mut skipped, &mut diagnostics, site.call_pc, reason, None);
            continue;
        }

        log_map_inline_debug(&format!(
            "site at PC={}: rewrite prepared with {} replacement load(s), removed_null_check={}",
            site.call_pc,
            rewrite.replacements.len(),
            rewrite.removed_null_check
        ));
        rewrites.push(rewrite);
    }

    if rewrites.is_empty() && direct_replacements.is_empty() {
        log_map_inline_debug("no map_inline rewrites prepared");
        return Ok(PassResult {
            sites_skipped: skipped,
            diagnostics,
            ..PassResult::unchanged("map_inline")
        });
    }

    let mut skip_pcs = HashSet::new();
    let mut replacements: BTreeMap<usize, Vec<BpfInsn>> = direct_replacements;
    let mut map_inline_records = direct_records;
    let mut applied = direct_sites_applied;
    let mut removed_any_null_check = false;
    let mut replacement_branch_patches = Vec::new();

    for rewrite in rewrites {
        let conflict = rewrite
            .skipped_pcs
            .iter()
            .any(|pc| replacements.contains_key(pc))
            || rewrite.replacements.keys().any(|pc| skip_pcs.contains(pc))
            || rewrite
                .replacements
                .keys()
                .any(|pc| replacements.contains_key(pc))
            || rewrite.skipped_pcs.iter().any(|pc| skip_pcs.contains(pc));
        if conflict {
            let reason = "overlapping map inline rewrite".to_string();
            record_skip(
                &mut skipped,
                &mut diagnostics,
                rewrite.call_pc,
                reason,
                None,
            );
            continue;
        }

        removed_any_null_check |= rewrite.removed_null_check;
        record_diagnostic(
            &mut diagnostics,
            format!(
                "site at PC={}: inlined successfully, value={}",
                rewrite.call_pc, rewrite.diagnostic_value
            ),
        );
        map_inline_records.extend(rewrite.map_inline_records);
        skip_pcs.extend(rewrite.skipped_pcs);
        replacements.extend(rewrite.replacements);
        replacement_branch_patches.extend(rewrite.branch_patches);
        applied += 1;
    }

    if applied == 0 {
        log_map_inline_debug("all prepared rewrites were discarded");
        return Ok(PassResult {
            sites_skipped: skipped,
            diagnostics,
            map_inline_records,
            ..PassResult::unchanged("map_inline")
        });
    }

    let orig_len = program.insns.len();
    let mut new_insns = Vec::with_capacity(orig_len);
    let mut addr_map = vec![0usize; orig_len + 1];
    let mut replacement_new_pcs = HashMap::new();
    let mut pc = 0usize;

    while pc < orig_len {
        addr_map[pc] = new_insns.len();

        if let Some(replacement) = replacements.get(&pc) {
            replacement_new_pcs.insert(pc, new_insns.len());
            new_insns.extend_from_slice(replacement);
            pc += 1;
            continue;
        }

        if skip_pcs.contains(&pc) {
            pc += 1;
            continue;
        }

        let insn = program.insns[pc];
        new_insns.push(insn);
        if insn.is_ldimm64() && pc + 1 < orig_len {
            pc += 1;
            addr_map[pc] = new_insns.len();
            new_insns.push(program.insns[pc]);
        }
        pc += 1;
    }
    addr_map[orig_len] = new_insns.len();

    super::utils::fixup_all_branches(&mut new_insns, &program.insns, &addr_map);

    let mut final_insns = new_insns;
    let mut final_addr_map = addr_map;
    let mut intermediate_to_final = (0..=final_insns.len()).collect::<Vec<_>>();
    if removed_any_null_check {
        if let Some((cleaned_insns, cleanup_map)) =
            super::utils::eliminate_unreachable_blocks(&final_insns)
        {
            final_addr_map = super::utils::compose_addr_maps(&final_addr_map, &cleanup_map);
            intermediate_to_final =
                super::utils::compose_addr_maps(&intermediate_to_final, &cleanup_map);
            final_insns = cleaned_insns;
        }
        if let Some((cleaned_insns, cleanup_map)) = super::utils::eliminate_nops(&final_insns) {
            final_addr_map = super::utils::compose_addr_maps(&final_addr_map, &cleanup_map);
            intermediate_to_final =
                super::utils::compose_addr_maps(&intermediate_to_final, &cleanup_map);
            final_insns = cleaned_insns;
        }
    }
    patch_replacement_branch_targets(
        &mut final_insns,
        &replacement_branch_patches,
        &replacement_new_pcs,
        &intermediate_to_final,
        &final_addr_map,
    )?;

    program.insns = final_insns;
    super::utils::remap_btf_metadata(program, &final_addr_map)?;
    program.remap_annotations(&final_addr_map);

    log_map_inline_debug(&format!(
        "applied {} map_inline rewrite(s), skipped {} site(s)",
        applied,
        skipped.len()
    ));

    Ok(PassResult {
        pass_name: "map_inline".into(),
        sites_applied: applied,
        sites_skipped: skipped,
        diagnostics,
        map_inline_records,
        ..Default::default()
    })
}

fn extract_site_constant_key(
    program: &BpfProgram,
    call_pc: usize,
    info: &MapInfo,
    use_verifier_guided_keys: bool,
    site_inline_hints: &[ResolvedInlineHint],
) -> std::result::Result<ExtractedConstantKey, KeyExtractionError> {
    if let Some(hint) = site_inline_hints
        .iter()
        .find(|hint| hint.mode == MapInlineHintMode::Hard)
    {
        let bounds = subprog_bounds(&program.insns, call_pc);
        let r2_setup = find_r2_stack_pointer_setup_simple(&program.insns, call_pc, bounds);
        let materialization = r2_setup.and_then(|(_, _, stack_off)| {
            materialization_for_snapshot_key(
                &program.insns,
                call_pc,
                bounds,
                stack_off,
                hint.key.len(),
                &hint.key,
            )
        });
        let (store_pc, source_imm_pc, materialization_pcs) = match materialization {
            Some(stack_bytes) => (
                stack_bytes.latest_store_pc,
                stack_bytes.latest_source_imm_pc,
                stack_bytes.materialization_pcs,
            ),
            None => (call_pc, None, Vec::new()),
        };
        let key = ConstantKey {
            stack_off: r2_setup.map(|(_, _, off)| off).unwrap_or(0),
            width: hint.key.len(),
            value: constant_key_value(&hint.key),
            bytes: hint.key.clone(),
            store_pc,
            source_imm_pc,
            materialization_pcs,
            r2_mov_pc: r2_setup.map(|(mov_pc, _, _)| mov_pc),
            r2_add_pc: r2_setup.map(|(_, add_pc, _)| add_pc),
        };
        log_map_inline_debug(&format!(
            "site at PC={}: inline-hint key={} width={} stack_off={} r2_mov_pc={:?} r2_add_pc={:?}",
            call_pc,
            format_constant_key(&key),
            key.width,
            key.stack_off,
            key.r2_mov_pc,
            key.r2_add_pc
        ));
        return Ok(ExtractedConstantKey {
            key,
            used_inline_hint: Some(hint.anchor.clone()),
        });
    }

    if use_verifier_guided_keys {
        return match try_extract_constant_key_verifier_guided(
            &program.insns,
            program.verifier_states.as_ref(),
            call_pc,
            info.key_size,
        ) {
            Ok(key) => {
                log_map_inline_debug(&format!(
                    "site at PC={}: verifier-guided key={} width={} stack_off={} store_pc={} source_imm_pc={:?} r2_mov_pc={:?} r2_add_pc={:?}",
                    call_pc,
                    format_constant_key(&key),
                    key.width,
                    key.stack_off,
                    key.store_pc,
                    key.source_imm_pc,
                    key.r2_mov_pc,
                    key.r2_add_pc
                ));
                Ok(ExtractedConstantKey {
                    key,
                    used_inline_hint: None,
                })
            }
            Err(verifier_err) => {
                log_map_inline_debug(&format!(
                    "site pc={} skip: verifier-guided key extraction failed: {}",
                    call_pc, verifier_err
                ));
                Err(KeyExtractionError::Unavailable(format!(
                    "verifier-guided key extraction failed: {}",
                    verifier_err
                )))
            }
        };
    }

    let detail = "verifier-guided key extraction is unavailable after a prior map_inline rewrite"
        .to_string();
    log_map_inline_debug(&format!("site pc={} skip: {}", call_pc, detail));
    Err(KeyExtractionError::Unavailable(detail))
}

fn build_site_rewrite(
    program: &BpfProgram,
    site: &MapLookupSite,
    key: &ConstantKey,
    uses: &R0UseClassification,
    info: &MapInfo,
    null_check_pc: Option<usize>,
) -> SiteRewriteResult<Option<SiteRewrite>> {
    let remove_lookup_pattern =
        site_can_attempt_lookup_pattern_removal(program, uses, info, null_check_pc);
    let encoded_key = encode_key_bytes(&key.bytes, info.key_size as usize);
    let lookup_value_size = program
        .map_provider
        .lookup_value_size(program, info)
        .map_err(anyhow::Error::msg)?;
    log_map_inline_debug(&format!(
        "site pc={} reading map_id={} key={:?} lookup_value_size={}",
        site.call_pc, info.map_id, encoded_key, lookup_value_size
    ));
    let value = match program.map_provider.lookup_elem(
        program,
        info.map_id,
        &encoded_key,
        lookup_value_size,
    ) {
        Ok(value) => {
            log_map_inline_debug(&format!(
                "site pc={} INLINE value={:?}",
                site.call_pc, value
            ));
            value
        }
        Err(MapLookupError::MissingKey { .. }) if is_hash_like_map_type(info.map_type) => {
            return Err(site_level_inline_veto(format!(
                "hash-like map {} has no live entry for key {}",
                info.map_id,
                format_bytes_preview(&encoded_key)
            )));
        }
        Err(MapLookupError::SkippedBySize { map_id }) => {
            return Err(site_level_inline_veto(map_snapshot_skipped_by_size_reason(
                map_id,
            )));
        }
        Err(err) => {
            log_map_inline_debug(&format!(
                "site at PC={}: map lookup(map_id={}, key={}) failed: {}",
                site.call_pc,
                info.map_id,
                format_bytes_preview(&encoded_key),
                err
            ));
            return Err(missing_snapshot_error(err));
        }
    };
    let inline_value = prepare_inline_value(info, &value).map_err(site_level_inline_veto)?;

    let removable_null_check_pc =
        null_check_pc.filter(|&pc| null_check_is_fallthrough_non_null(&program.insns[pc]));
    let replacement_pcs = uses
        .fixed_loads
        .iter()
        .map(|load| load.pc)
        .collect::<HashSet<_>>();
    let mut lookup_pattern_pcs = HashSet::new();
    if remove_lookup_pattern {
        lookup_pattern_pcs.insert(site.call_pc);
        lookup_pattern_pcs.insert(site.map_load_pc);
        lookup_pattern_pcs.insert(site.map_load_pc + 1);
        lookup_pattern_pcs.extend(key.materialization_pcs.iter().copied());
        if let Some(r2_mov_pc) = key.r2_mov_pc {
            lookup_pattern_pcs.insert(r2_mov_pc);
        }
        if let Some(r2_add_pc) = key.r2_add_pc {
            lookup_pattern_pcs.insert(r2_add_pc);
        }
        if let Some(null_check_pc) = removable_null_check_pc {
            lookup_pattern_pcs.insert(null_check_pc);
        }
    }
    if remove_lookup_pattern {
        lookup_pattern_pcs.extend(uses.alias_copy_pcs.iter().copied());
    }
    let null_check_blocks_lookup_removal = if let Some(null_check_pc) = removable_null_check_pc {
        !null_check_removal_window_is_trivial(
            program,
            uses,
            null_check_pc,
            &lookup_pattern_pcs,
            &replacement_pcs,
        )
    } else {
        null_check_pc.is_some()
    };
    let can_remove_lookup_pattern = remove_lookup_pattern
        && uses.other_uses.is_empty()
        && !null_check_blocks_lookup_removal
        && lookup_pattern_removal_is_safe(program, site.call_pc, &lookup_pattern_pcs);
    let skipped_pcs = if can_remove_lookup_pattern {
        lookup_pattern_pcs
    } else {
        HashSet::new()
    };

    let mut replacements = BTreeMap::new();
    for load in &uses.fixed_loads {
        let scalar =
            read_scalar_from_value(&inline_value, load.offset, load.size).ok_or_else(|| {
                anyhow::anyhow!(
                    "map value read out of bounds for load pc {} (offset {}, size {})",
                    load.pc,
                    load.offset,
                    load.size
                )
            })?;
        replacements.insert(load.pc, emit_constant_load(load.dst_reg, scalar, load.size));
    }

    if replacements.is_empty() {
        return Ok(None);
    }

    Ok(Some(SiteRewrite {
        call_pc: site.call_pc,
        diagnostic_value: format_inlined_value_diagnostic(&inline_value, &uses.fixed_loads),
        removed_null_check: can_remove_lookup_pattern && removable_null_check_pc.is_some(),
        map_inline_records: vec![MapInlineRecord {
            map_id: info.map_id,
            key: encoded_key,
            value: inline_value,
        }],
        skipped_pcs,
        replacements,
        branch_patches: Vec::new(),
    }))
}

fn hard_null_hint(hints: &[ResolvedInlineHint]) -> Option<&ResolvedInlineHint> {
    hints.iter().find(|hint| {
        hint.mode == MapInlineHintMode::Hard
            && matches!(hint.inline_value, ResolvedInlineValue::Null)
    })
}

fn build_hard_null_site_rewrite(
    program: &BpfProgram,
    site: &MapLookupSite,
    key: &ConstantKey,
    info: &MapInfo,
) -> SiteRewrite {
    let encoded_key = encode_key_bytes(&key.bytes, info.key_size as usize);
    let mut skipped_pcs = HashSet::new();
    skipped_pcs.insert(site.map_load_pc);
    if program
        .insns
        .get(site.map_load_pc)
        .is_some_and(BpfInsn::is_ldimm64)
        && site.map_load_pc + 1 < program.insns.len()
    {
        skipped_pcs.insert(site.map_load_pc + 1);
    }
    skipped_pcs.extend(key.materialization_pcs.iter().copied());
    if let Some(r2_mov_pc) = key.r2_mov_pc {
        skipped_pcs.insert(r2_mov_pc);
    }
    if let Some(r2_add_pc) = key.r2_add_pc {
        skipped_pcs.insert(r2_add_pc);
    }

    let mut replacements = BTreeMap::new();
    replacements.insert(site.call_pc, vec![BpfInsn::mov64_imm(0, 0)]);
    let removed_null_check =
        if let Some(null_handler) = find_soft_fold_null_handler(&program.insns, site.call_pc) {
            replacements.insert(
                null_handler.null_check_pc,
                vec![BpfInsn::ja(program.insns[null_handler.null_check_pc].off)],
            );
            true
        } else {
            false
        };

    SiteRewrite {
        call_pc: site.call_pc,
        diagnostic_value: format!(
            "NULL map_id={} key={}",
            info.map_id,
            format_bytes_preview(&encoded_key)
        ),
        removed_null_check,
        map_inline_records: Vec::new(),
        skipped_pcs,
        replacements,
        branch_patches: Vec::new(),
    }
}

fn build_soft_hint_site_rewrite(
    program: &BpfProgram,
    site: &MapLookupSite,
    info: &MapInfo,
    hints: &[ResolvedInlineHint],
) -> SiteRewriteResult<Option<SiteRewrite>> {
    if hints.is_empty() {
        return Ok(None);
    }
    if hints
        .iter()
        .any(|hint| hint.mode != MapInlineHintMode::Soft)
    {
        return Err(site_level_inline_veto(
            "soft hint rewrite received a non-soft hint",
        ));
    }
    if info.is_map_in_map() {
        return Err(site_level_inline_veto(
            "soft inline hints are not supported for map-in-map outer lookups",
        ));
    }

    let null_handler = find_soft_fold_null_handler(&program.insns, site.call_pc)
        .ok_or_else(|| site_level_inline_veto("soft fold not applicable: missing null handler"))?;

    let uses = classify_r0_uses_with_options(
        &program.insns,
        site.call_pc,
        info.has_removable_lookup_pattern(),
        info.has_removable_lookup_pattern(),
    );
    if uses.null_check_pc != Some(null_handler.null_check_pc) {
        return Err(site_level_inline_veto(
            "soft fold not applicable: nearest null check is not the lookup null handler",
        ));
    }
    if uses.fixed_loads.is_empty() {
        return Err(site_level_inline_veto(
            "soft fold not applicable: lookup result has no scalar load use",
        ));
    }
    if !uses.other_uses.is_empty() {
        return Err(site_level_inline_veto(
            "soft fold not applicable: lookup result has non-scalar use",
        ));
    }

    let mut replacement = Vec::new();
    let mut branch_patches = Vec::new();
    let mut records = Vec::new();

    for hint in hints {
        let ResolvedInlineValue::Value(inline_value) = &hint.inline_value else {
            return Err(site_level_inline_veto(
                "soft hint rewrite received a NULL hard-fold hint",
            ));
        };
        let compare_start = replacement.len();
        let mismatch_jumps = emit_key_compare_to_hint(&hint.key, &mut replacement)?;

        for load in &uses.fixed_loads {
            let scalar =
                read_scalar_from_value(inline_value, load.offset, load.size).ok_or_else(
                    || {
                        site_level_inline_veto(format!(
                            "soft fold map value read out of bounds for load pc {} (offset {}, size {})",
                            load.pc, load.offset, load.size
                        ))
                    },
                )?;
            replacement.extend(emit_constant_load(load.dst_reg, scalar, load.size));
        }

        branch_patches.push(ReplacementBranchPatch {
            replacement_pc: site.call_pc,
            replacement_insn_idx: replacement.len(),
            target_old_pc: null_handler.non_null_pc,
        });
        replacement.push(BpfInsn::ja(0));

        let next_hint_or_miss = replacement.len();
        for jump_pc in mismatch_jumps {
            patch_relative_jump(&mut replacement, jump_pc, next_hint_or_miss)?;
        }
        if compare_start == next_hint_or_miss {
            return Err(site_level_inline_veto(
                "soft inline hint emitted an empty key comparison",
            ));
        }
        records.push(MapInlineRecord {
            map_id: hint.map_id,
            key: hint.key.clone(),
            value: inline_value.clone(),
        });
    }

    replacement.push(BpfInsn::mov64_imm(0, 0));
    branch_patches.push(ReplacementBranchPatch {
        replacement_pc: site.call_pc,
        replacement_insn_idx: replacement.len(),
        target_old_pc: null_handler.null_handler_pc,
    });
    replacement.push(BpfInsn::ja(0));

    if replacement.is_empty() {
        return Ok(None);
    }

    let mut skipped_pcs = HashSet::new();
    skipped_pcs.insert(site.map_load_pc);
    if program
        .insns
        .get(site.map_load_pc)
        .is_some_and(BpfInsn::is_ldimm64)
        && site.map_load_pc + 1 < program.insns.len()
    {
        skipped_pcs.insert(site.map_load_pc + 1);
    }
    skipped_pcs.insert(null_handler.null_check_pc);
    skipped_pcs.extend(uses.alias_copy_pcs.iter().copied());
    skipped_pcs.extend(uses.fixed_loads.iter().map(|load| load.pc));

    let mut replacements = BTreeMap::new();
    replacements.insert(site.call_pc, replacement);
    Ok(Some(SiteRewrite {
        call_pc: site.call_pc,
        diagnostic_value: format!(
            "soft-fold hints={} keys={}",
            hints.len(),
            hints
                .iter()
                .map(|hint| format_bytes_preview(&hint.key))
                .collect::<Vec<_>>()
                .join(",")
        ),
        removed_null_check: false,
        map_inline_records: records,
        skipped_pcs,
        replacements,
        branch_patches,
    }))
}

#[derive(Clone, Copy, Debug)]
struct SoftNullHandler {
    null_check_pc: usize,
    non_null_pc: usize,
    null_handler_pc: usize,
}

fn find_soft_fold_null_handler(insns: &[BpfInsn], call_pc: usize) -> Option<SoftNullHandler> {
    let (_, end_pc) = subprog_bounds(insns, call_pc);
    let null_check_pc = call_pc + insn_width(insns.get(call_pc)?);
    if null_check_pc >= end_pc {
        return None;
    }

    let insn = insns.get(null_check_pc)?;
    if !is_direct_r0_null_jeq(insn) {
        return None;
    }
    let null_handler_pc = jump_target_pc(null_check_pc, insn, insns.len())?;
    Some(SoftNullHandler {
        null_check_pc,
        non_null_pc: null_check_pc + insn_width(insn),
        null_handler_pc,
    })
}

fn is_direct_r0_null_jeq(insn: &BpfInsn) -> bool {
    insn.class() == BPF_JMP
        && bpf_op(insn.code) == BPF_JEQ
        && bpf_src(insn.code) == BPF_K
        && insn.dst_reg() == 0
        && insn.src_reg() == 0
        && insn.imm == 0
        && insn.off >= 0
}

fn emit_key_compare_to_hint(key: &[u8], insns: &mut Vec<BpfInsn>) -> SiteRewriteResult<Vec<usize>> {
    let key_reg = 2;
    let scratch_reg = 3;
    let const_reg = 4;
    let mut mismatch_jumps = Vec::new();
    let mut offset = 0usize;
    while offset < key.len() {
        let remaining = key.len() - offset;
        let width = if remaining >= 8 {
            8usize
        } else if remaining >= 4 {
            4usize
        } else if remaining >= 2 {
            2usize
        } else {
            1usize
        };
        let off = i16::try_from(offset).map_err(|_| {
            site_level_inline_veto(format!("soft inline hint key offset {offset} exceeds i16"))
        })?;
        let bpf_width = match width {
            8 => BPF_DW,
            4 => BPF_W,
            2 => BPF_H,
            1 => BPF_B,
            _ => unreachable!("width is selected from 8/4/2/1"),
        };
        insns.push(BpfInsn::ldx_mem(bpf_width, scratch_reg, key_reg, off));
        let value = constant_key_value(&key[offset..offset + width]);
        if width == 8 {
            insns.extend(emit_ldimm64(const_reg, value));
        } else {
            insns.push(BpfInsn::mov32_imm(const_reg, value as u32 as i32));
        }
        mismatch_jumps.push(insns.len());
        insns.push(BpfInsn::new(
            BPF_JMP | BPF_JNE | BPF_X,
            BpfInsn::make_regs(scratch_reg, const_reg),
            0,
            0,
        ));
        offset += width;
    }
    Ok(mismatch_jumps)
}

fn patch_relative_jump(
    insns: &mut [BpfInsn],
    jump_pc: usize,
    target_pc: usize,
) -> SiteRewriteResult<()> {
    let offset = target_pc as isize - jump_pc as isize - 1;
    let offset = i16::try_from(offset).map_err(|_| {
        site_level_inline_veto(format!("map_inline_branch_offset_overflow offset={offset}"))
    })?;
    insns[jump_pc].off = offset;
    Ok(())
}

fn patch_replacement_branch_targets(
    insns: &mut [BpfInsn],
    patches: &[ReplacementBranchPatch],
    replacement_new_pcs: &HashMap<usize, usize>,
    intermediate_to_final: &[usize],
    final_addr_map: &[usize],
) -> anyhow::Result<()> {
    for patch in patches {
        let replacement_base = replacement_new_pcs
            .get(&patch.replacement_pc)
            .copied()
            .ok_or_else(|| {
                anyhow::anyhow!(
                    "missing replacement base for branch patch at old pc {}",
                    patch.replacement_pc
                )
            })?;
        let intermediate_branch_pc = replacement_base + patch.replacement_insn_idx;
        let branch_pc = *intermediate_to_final
            .get(intermediate_branch_pc)
            .ok_or_else(|| {
                anyhow::anyhow!(
                    "replacement branch pc {} is out of final address map range",
                    intermediate_branch_pc
                )
            })?;
        let target_pc = *final_addr_map.get(patch.target_old_pc).ok_or_else(|| {
            anyhow::anyhow!(
                "replacement branch target old pc {} is out of address map range",
                patch.target_old_pc
            )
        })?;
        let Some(insn) = insns.get_mut(branch_pc) else {
            bail!("replacement branch pc {branch_pc} is out of bounds");
        };
        if !insn.is_ja() {
            bail!("replacement branch pc {branch_pc} is not a JA instruction");
        }
        let offset = target_pc as isize - branch_pc as isize - 1;
        insn.off = i16::try_from(offset)
            .with_context(|| format!("replacement branch offset {offset} does not fit in i16"))?;
    }
    Ok(())
}

fn resolve_inner_map_id_for_outer_key(
    program: &BpfProgram,
    outer_info: &MapInfo,
    encoded_outer_key: &[u8],
) -> SiteRewriteResult<u32> {
    if let Some(inner_map_id) = program
        .map_inner_map_ids
        .get(&(outer_info.map_id, encoded_outer_key.to_vec()))
        .copied()
    {
        return Ok(inner_map_id);
    }

    let value_size = program
        .map_provider
        .lookup_value_size(program, outer_info)
        .map_err(anyhow::Error::msg)?;
    let value = match program.map_provider.lookup_elem(
        program,
        outer_info.map_id,
        encoded_outer_key,
        value_size,
    ) {
        Ok(value) => value,
        Err(MapLookupError::MissingKey { .. }) => {
            return Err(site_level_inline_veto(format!(
                "map-in-map outer map {} has no live inner map for key {}",
                outer_info.map_id,
                format_bytes_preview(encoded_outer_key)
            )));
        }
        Err(MapLookupError::SkippedBySize { map_id }) => {
            return Err(site_level_inline_veto(map_snapshot_skipped_by_size_reason(
                map_id,
            )));
        }
        Err(err) => return Err(missing_snapshot_error(err)),
    };
    let bytes = value.get(..4).ok_or_else(|| {
        site_level_inline_veto(format!(
            "map-in-map outer map {} value for key {} is too small to hold inner map id",
            outer_info.map_id,
            format_bytes_preview(encoded_outer_key)
        ))
    })?;
    let inner_map_id = u32::from_le_bytes(bytes.try_into().expect("slice length checked"));
    if inner_map_id == 0 {
        return Err(site_level_inline_veto(format!(
            "map-in-map outer map {} has no live inner map for key {}",
            outer_info.map_id,
            format_bytes_preview(encoded_outer_key)
        )));
    }
    Ok(inner_map_id)
}

fn build_map_in_map_chain_rewrite(
    program: &BpfProgram,
    outer_site: &MapLookupSite,
    outer_info: &MapInfo,
    use_verifier_guided_keys: bool,
    inline_hints: &ResolvedInlineHints,
    kernel_mutable_maps: &KernelMutableMaps,
    inline_hints_consumed: &mut HashSet<MapInlineHintAnchor>,
) -> SiteRewriteResult<Option<SiteRewrite>> {
    let Some(chain) = find_map_in_map_chains(&program.insns, std::slice::from_ref(outer_site))
        .into_iter()
        .next()
    else {
        return Ok(None);
    };
    let extracted_outer_key = extract_site_constant_key(
        program,
        outer_site.call_pc,
        outer_info,
        use_verifier_guided_keys,
        inline_hints.for_call(outer_site.call_pc),
    )
    .map_err(|err| match err {
        KeyExtractionError::Unavailable(err) => {
            site_level_inline_veto(format!("map-in-map outer key unavailable: {err}"))
        }
    })?;
    if let Some(anchor) = extracted_outer_key.used_inline_hint {
        inline_hints_consumed.insert(anchor);
    }
    let outer_key = extracted_outer_key.key;
    if outer_key.width < outer_info.key_size as usize {
        return Err(site_level_inline_veto(format!(
            "map-in-map outer key width {} is smaller than map key size {}",
            outer_key.width, outer_info.key_size
        )));
    }
    let encoded_outer_key = encode_key_bytes(&outer_key.bytes, outer_info.key_size as usize);
    let inner_map_id = resolve_inner_map_id_for_outer_key(program, outer_info, &encoded_outer_key)?;
    if map_in_map_outer_only_fold_requested(
        inline_hints.for_call(outer_site.call_pc),
        inline_hints.for_call(chain.inner_call_pc),
    ) {
        return Ok(Some(build_map_in_map_outer_only_rewrite(
            program,
            outer_site,
            outer_info,
            &outer_key,
            &encoded_outer_key,
            inner_map_id,
        )));
    }
    let inner_info = program
        .map_provider
        .map_info(program, inner_map_id)
        .map_err(anyhow::Error::msg)?
        .ok_or_else(|| {
            missing_snapshot_anyhow(anyhow::anyhow!(
                "map_values snapshot has no metadata for inner map {} from outer map {} key {}",
                inner_map_id,
                outer_info.map_id,
                format_bytes_preview(&encoded_outer_key)
            ))
        })?;
    if map_snapshot_skipped_by_size(program, inner_info.map_id) {
        return Ok(None);
    }
    if inner_info.is_map_in_map() {
        return Err(site_level_inline_veto(format!(
            "nested map-in-map inner map type {} not inlineable",
            inner_info.map_type
        )));
    }
    if let Some(reason) = kernel_mutable_reason_for_map(kernel_mutable_maps, &inner_info) {
        return Err(site_level_inline_veto(reason));
    }
    if !inner_info.supports_direct_value_inline() {
        return Err(site_level_inline_veto(format!(
            "inner map type {} not inlineable",
            inner_info.map_type
        )));
    }

    let extracted_inner_key = extract_site_constant_key(
        program,
        chain.inner_call_pc,
        &inner_info,
        use_verifier_guided_keys,
        inline_hints.for_call(chain.inner_call_pc),
    )
    .map_err(|err| match err {
        KeyExtractionError::Unavailable(err) => {
            site_level_inline_veto(format!("map-in-map inner key unavailable: {err}"))
        }
    })?;
    if let Some(anchor) = extracted_inner_key.used_inline_hint {
        inline_hints_consumed.insert(anchor);
    }
    let inner_key = extracted_inner_key.key;
    if inner_key.width < inner_info.key_size as usize {
        return Err(site_level_inline_veto(format!(
            "map-in-map inner key width {} is smaller than map key size {}",
            inner_key.width, inner_info.key_size
        )));
    }
    let encoded_inner_key = encode_key_bytes(&inner_key.bytes, inner_info.key_size as usize);

    let uses = classify_r0_uses_with_options(
        &program.insns,
        chain.inner_call_pc,
        inner_info.has_removable_lookup_pattern(),
        inner_info.has_removable_lookup_pattern(),
    );
    if inner_info.requires_entry_presence_check() && uses.null_check_pc.is_none() {
        return Err(site_level_inline_veto(
            "map-in-map inner hash map inline requires an immediate null check",
        ));
    }
    if uses.fixed_loads.is_empty() {
        return Err(site_level_inline_veto(
            "map-in-map inner lookup result is not consumed by fixed-offset scalar loads",
        ));
    }

    let lookup_value_size = program
        .map_provider
        .lookup_value_size(program, &inner_info)
        .map_err(anyhow::Error::msg)?;
    let value = match program.map_provider.lookup_elem(
        program,
        inner_info.map_id,
        &encoded_inner_key,
        lookup_value_size,
    ) {
        Ok(value) => value,
        Err(MapLookupError::MissingKey { .. }) if is_hash_like_map_type(inner_info.map_type) => {
            return Err(site_level_inline_veto(format!(
                "inner hash-like map {} has no live entry for key {}",
                inner_info.map_id,
                format_bytes_preview(&encoded_inner_key)
            )));
        }
        Err(MapLookupError::SkippedBySize { map_id }) => {
            return Err(site_level_inline_veto(map_snapshot_skipped_by_size_reason(
                map_id,
            )));
        }
        Err(err) => return Err(missing_snapshot_error(err)),
    };
    let inline_value = prepare_inline_value(&inner_info, &value).map_err(site_level_inline_veto)?;

    let mut replacements = BTreeMap::new();
    for load in &uses.fixed_loads {
        let scalar =
            read_scalar_from_value(&inline_value, load.offset, load.size).ok_or_else(|| {
                anyhow::anyhow!(
                    "inner map value read out of bounds for load pc {} (offset {}, size {})",
                    load.pc,
                    load.offset,
                    load.size
                )
            })?;
        replacements.insert(load.pc, emit_constant_load(load.dst_reg, scalar, load.size));
    }
    if replacements.is_empty() {
        return Ok(None);
    }

    let replacement_pcs = uses
        .fixed_loads
        .iter()
        .map(|load| load.pc)
        .collect::<HashSet<_>>();
    let mut outer_lookup_pcs = HashSet::new();
    outer_lookup_pcs.insert(outer_site.call_pc);
    outer_lookup_pcs.insert(outer_site.map_load_pc);
    outer_lookup_pcs.insert(outer_site.map_load_pc + 1);
    outer_lookup_pcs.extend(outer_key.materialization_pcs.iter().copied());
    if let Some(r2_mov_pc) = outer_key.r2_mov_pc {
        outer_lookup_pcs.insert(r2_mov_pc);
    }
    if let Some(r2_add_pc) = outer_key.r2_add_pc {
        outer_lookup_pcs.insert(r2_add_pc);
    }

    let mut inner_lookup_pcs = HashSet::new();
    if let Some(outer_null_check_pc) = chain.outer_null_check_pc {
        inner_lookup_pcs.insert(outer_null_check_pc);
    }
    inner_lookup_pcs.extend(chain.outer_alias_copy_pcs.iter().copied());
    inner_lookup_pcs.insert(chain.inner_call_pc);
    inner_lookup_pcs.extend(inner_key.materialization_pcs.iter().copied());
    if let Some(r2_mov_pc) = inner_key.r2_mov_pc {
        inner_lookup_pcs.insert(r2_mov_pc);
    }
    if let Some(r2_add_pc) = inner_key.r2_add_pc {
        inner_lookup_pcs.insert(r2_add_pc);
    }
    if let Some(inner_null_check_pc) = uses.null_check_pc {
        inner_lookup_pcs.insert(inner_null_check_pc);
    }
    inner_lookup_pcs.extend(uses.alias_copy_pcs.iter().copied());

    let mut lookup_pattern_pcs = outer_lookup_pcs.clone();
    lookup_pattern_pcs.extend(inner_lookup_pcs.iter().copied());
    let outer_null_check_blocks_removal =
        if let Some(outer_null_check_pc) = chain.outer_null_check_pc {
            !null_check_removal_window_is_trivial(
                program,
                &uses,
                outer_null_check_pc,
                &lookup_pattern_pcs,
                &replacement_pcs,
            )
        } else {
            false
        };
    let inner_null_check_blocks_removal = if let Some(inner_null_check_pc) = uses.null_check_pc {
        !null_check_removal_window_is_trivial(
            program,
            &uses,
            inner_null_check_pc,
            &lookup_pattern_pcs,
            &replacement_pcs,
        )
    } else {
        false
    };
    let can_remove_lookup_pattern = uses.other_uses.is_empty()
        && !outer_null_check_blocks_removal
        && !inner_null_check_blocks_removal
        && lookup_pattern_removal_is_safe(program, outer_site.call_pc, &outer_lookup_pcs)
        && lookup_pattern_removal_is_safe(program, chain.inner_call_pc, &inner_lookup_pcs);
    let skipped_pcs = if can_remove_lookup_pattern {
        lookup_pattern_pcs
    } else {
        HashSet::new()
    };

    Ok(Some(SiteRewrite {
        call_pc: outer_site.call_pc,
        diagnostic_value: format!(
            "outer_map_id={} outer_key={} inner_map_id={} inner_key={} {}",
            outer_info.map_id,
            format_bytes_preview(&encoded_outer_key),
            inner_info.map_id,
            format_bytes_preview(&encoded_inner_key),
            format_inlined_value_diagnostic(&inline_value, &uses.fixed_loads)
        ),
        removed_null_check: can_remove_lookup_pattern
            && (chain.outer_null_check_pc.is_some() || uses.null_check_pc.is_some()),
        map_inline_records: vec![MapInlineRecord {
            map_id: inner_info.map_id,
            key: encoded_inner_key,
            value: inline_value,
        }],
        skipped_pcs,
        replacements,
        branch_patches: Vec::new(),
    }))
}

fn map_in_map_outer_only_fold_requested(
    outer_hints: &[ResolvedInlineHint],
    inner_hints: &[ResolvedInlineHint],
) -> bool {
    outer_hints
        .iter()
        .any(|hint| hint.mode == MapInlineHintMode::Hard)
        && inner_hints.is_empty()
}

fn build_map_in_map_outer_only_rewrite(
    program: &BpfProgram,
    outer_site: &MapLookupSite,
    outer_info: &MapInfo,
    outer_key: &ConstantKey,
    encoded_outer_key: &[u8],
    inner_map_id: u32,
) -> SiteRewrite {
    let mut skipped_pcs = HashSet::new();
    skipped_pcs.insert(outer_site.map_load_pc);
    if program
        .insns
        .get(outer_site.map_load_pc)
        .is_some_and(BpfInsn::is_ldimm64)
        && outer_site.map_load_pc + 1 < program.insns.len()
    {
        skipped_pcs.insert(outer_site.map_load_pc + 1);
    }
    skipped_pcs.extend(outer_key.materialization_pcs.iter().copied());
    if let Some(r2_mov_pc) = outer_key.r2_mov_pc {
        skipped_pcs.insert(r2_mov_pc);
    }
    if let Some(r2_add_pc) = outer_key.r2_add_pc {
        skipped_pcs.insert(r2_add_pc);
    }

    let mut replacements = BTreeMap::new();
    replacements.insert(outer_site.call_pc, emit_map_ptr_load(0, inner_map_id));

    SiteRewrite {
        call_pc: outer_site.call_pc,
        diagnostic_value: format!(
            "outer-only outer_map_id={} outer_key={} inner_map_id={}",
            outer_info.map_id,
            format_bytes_preview(encoded_outer_key),
            inner_map_id
        ),
        removed_null_check: false,
        map_inline_records: Vec::new(),
        skipped_pcs,
        replacements,
        branch_patches: Vec::new(),
    }
}

fn emit_map_ptr_load(dst_reg: u8, map_id: u32) -> Vec<BpfInsn> {
    vec![
        BpfInsn::new(
            BPF_LD | BPF_DW | BPF_IMM,
            BpfInsn::make_regs(dst_reg, BPF_PSEUDO_MAP_FD),
            0,
            0,
        ),
        BpfInsn::new(0, 0, 0, map_id as i32),
    ]
}

fn site_can_attempt_lookup_pattern_removal(
    program: &BpfProgram,
    uses: &R0UseClassification,
    info: &MapInfo,
    null_check_pc: Option<usize>,
) -> bool {
    if info.has_removable_lookup_pattern() {
        return true;
    }

    info.requires_entry_presence_check()
        && uses.other_uses.is_empty()
        && null_check_pc.is_some_and(|pc| null_check_is_fallthrough_non_null(&program.insns[pc]))
}

fn build_direct_map_value_load_rewrites(
    program: &BpfProgram,
    kernel_mutable_maps: &KernelMutableMaps,
) -> anyhow::Result<DirectMapValueLoadRewrites> {
    let mut replacements = BTreeMap::new();
    let mut sites_applied = 0usize;
    let mut diagnostics = Vec::new();
    let mut map_inline_records = Vec::new();
    let mut map_cache: HashMap<MapRefKey, Option<SnapshotMapValue>> = HashMap::new();
    let mut pc = 0usize;

    while pc < program.insns.len() {
        let insn = &program.insns[pc];
        if !insn.is_ldx_mem() {
            pc += insn_width(insn);
            continue;
        }

        let bounds = subprog_bounds(&program.insns, pc);
        let origin = match resolve_key_pointer_origin(&program.insns, pc, insn.src_reg(), bounds) {
            Ok(KeyPointerOrigin::MapValue {
                map_ref, value_off, ..
            }) => Some((map_ref, value_off)),
            _ => None,
        };
        let Some((map_ref, value_off)) = origin else {
            pc += insn_width(insn);
            continue;
        };

        let Some(total_off) = value_off.checked_add(insn.off as i32) else {
            record_diagnostic(
                &mut diagnostics,
                format!(
                    "site at PC={}: pseudo-map-value offset overflow (base {} + load off {})",
                    pc, value_off, insn.off
                ),
            );
            pc += insn_width(insn);
            continue;
        };
        if total_off < 0 {
            record_diagnostic(
                &mut diagnostics,
                format!(
                    "site at PC={}: pseudo-map-value load offset {} is negative",
                    pc, total_off
                ),
            );
            pc += insn_width(insn);
            continue;
        }

        let map_value = match resolve_snapshot_map_value(
            program,
            map_ref,
            kernel_mutable_maps,
            &mut map_cache,
        )? {
            Some(map_value) => map_value,
            None => {
                pc += insn_width(insn);
                continue;
            }
        };

        let offset = total_off as usize;
        let Some(scalar) = read_scalar_from_value_at(&map_value.value, offset, bpf_size(insn.code))
        else {
            let size = match size_in_bytes(bpf_size(insn.code)) {
                Some(size) => size.to_string(),
                None => "invalid".to_string(),
            };
            record_diagnostic(
                &mut diagnostics,
                format!(
                    "site at PC={}: pseudo-map-value load out of bounds (map_id={}, off={}, size={})",
                    pc,
                    map_value.map_id,
                    offset,
                    size
                ),
            );
            pc += insn_width(insn);
            continue;
        };

        replacements.insert(
            pc,
            emit_constant_load(insn.dst_reg(), scalar, bpf_size(insn.code)),
        );
        sites_applied += 1;
        map_inline_records.push(MapInlineRecord {
            map_id: map_value.map_id,
            key: map_value.key.clone(),
            value: map_value.value.clone(),
        });
        record_diagnostic(
            &mut diagnostics,
            format!(
                "site at PC={}: constantized pseudo-map-value load from map_id={} off={} value=0x{:x}",
                pc, map_value.map_id, offset, scalar
            ),
        );

        pc += insn_width(insn);
    }

    Ok((replacements, sites_applied, diagnostics, map_inline_records))
}

fn resolve_snapshot_map_value(
    program: &BpfProgram,
    map_ref: MapRefKey,
    kernel_mutable_maps: &KernelMutableMaps,
    cache: &mut HashMap<MapRefKey, Option<SnapshotMapValue>>,
) -> anyhow::Result<Option<SnapshotMapValue>> {
    if let Some(cached) = cache.get(&map_ref) {
        return Ok(cached.clone());
    }

    let resolved = (|| -> anyhow::Result<Option<SnapshotMapValue>> {
        let Some(map_id) = map_id_for_ref(program, map_ref)? else {
            return Ok(None);
        };
        if map_snapshot_skipped_by_size(program, map_id) {
            return Ok(None);
        }
        let Some(info) = program
            .map_provider
            .map_info(program, map_id)
            .map_err(anyhow::Error::msg)?
        else {
            return Ok(None);
        };
        if kernel_mutable_reason_for_map(kernel_mutable_maps, &info).is_some() {
            return Ok(None);
        }

        let key = vec![0u8; info.key_size as usize];
        let value_size = program
            .map_provider
            .lookup_value_size(program, &info)
            .map_err(anyhow::Error::msg)?;
        let value = match program
            .map_provider
            .lookup_elem(program, map_id, &key, value_size)
        {
            Ok(value) => value,
            Err(MapLookupError::MissingKey { .. }) if is_hash_like_map_type(info.map_type) => {
                return Ok(None);
            }
            Err(MapLookupError::SkippedBySize { .. }) => return Ok(None),
            Err(err) => return Err(anyhow::Error::msg(err.to_string())),
        };
        Ok(Some(SnapshotMapValue { map_id, key, value }))
    })();

    let cached = resolved?;
    cache.insert(map_ref, cached.clone());
    Ok(cached)
}

fn map_id_for_ref(program: &BpfProgram, map_ref: MapRefKey) -> anyhow::Result<Option<u32>> {
    if map_ref.src_reg == BPF_PSEUDO_MAP_VALUE || map_ref.src_reg == BPF_PSEUDO_MAP_FD {
        return Ok(program.map_fd_bindings.get(&map_ref.imm).copied());
    }
    if map_ref.src_reg == BPF_PSEUDO_MAP_IDX_VALUE || map_ref.src_reg == BPF_PSEUDO_MAP_IDX {
        let index = usize::try_from(map_ref.imm)
            .map_err(|_| anyhow::anyhow!("negative canonical pseudo-map index {}", map_ref.imm))?;
        let Some(&map_id) = program.map_ids.get(index) else {
            anyhow::bail!(
                "canonical pseudo-map index {} out of range for {} map ids",
                index,
                program.map_ids.len()
            );
        };
        return Ok(Some(map_id));
    }
    Ok(None)
}

fn encode_key_bytes(bytes: &[u8], key_size: usize) -> Vec<u8> {
    bytes[..key_size].to_vec()
}

fn prepare_inline_value(info: &MapInfo, raw_value: &[u8]) -> Result<Vec<u8>, String> {
    if info.map_type != libbpf_sys::BPF_MAP_TYPE_PERCPU_ARRAY {
        return Ok(raw_value.to_vec());
    }

    collapse_uniform_percpu_array_value(info.value_size as usize, raw_value)
}

fn collapse_uniform_percpu_array_value(
    value_size: usize,
    raw_value: &[u8],
) -> Result<Vec<u8>, String> {
    if value_size == 0 {
        return Err("PERCPU_ARRAY has zero value_size".to_string());
    }

    let stride = round_up_8(value_size);
    if raw_value.len() < stride || !raw_value.len().is_multiple_of(stride) {
        return Err(format!(
            "PERCPU_ARRAY lookup blob length {} is inconsistent with slot stride {}",
            raw_value.len(),
            stride
        ));
    }

    let slot_count = raw_value.len() / stride;
    let first_value = raw_value[..value_size].to_vec();
    for slot in 1..slot_count {
        let offset = slot * stride;
        if raw_value[offset..offset + value_size] != first_value[..] {
            return Err(format!(
                "PERCPU_ARRAY value differs across CPUs for {} slot(s)",
                slot_count
            ));
        }
    }

    Ok(first_value)
}

fn read_scalar_from_value(value: &[u8], offset: i16, size: u8) -> Option<u64> {
    if offset < 0 {
        return None;
    }
    read_scalar_from_value_at(value, offset as usize, size)
}

fn read_scalar_from_value_at(value: &[u8], offset: usize, size: u8) -> Option<u64> {
    let width = size_in_bytes(size)? as usize;
    if offset + width > value.len() {
        return None;
    }

    let mut buf = [0u8; 8];
    buf[..width].copy_from_slice(&value[offset..offset + width]);
    Some(u64::from_le_bytes(buf))
}

fn round_up_8(value: usize) -> usize {
    (value + 7) & !7
}

fn emit_constant_load(dst_reg: u8, value: u64, size: u8) -> Vec<BpfInsn> {
    if size == BPF_DW {
        let signed_value = value as i64;
        if signed_value >= i32::MIN as i64 && signed_value <= i32::MAX as i64 {
            return vec![BpfInsn::mov64_imm(dst_reg, signed_value as i32)];
        }

        return emit_ldimm64(dst_reg, value);
    }

    debug_assert!(value <= u32::MAX as u64);
    vec![BpfInsn::mov32_imm(dst_reg, value as u32 as i32)]
}

fn find_map_load_for_call(insns: &[BpfInsn], call_pc: usize) -> Option<usize> {
    find_direct_map_load_for_reg_before_pc(insns, call_pc, 1)
}

fn find_direct_map_load_for_reg_before_pc(insns: &[BpfInsn], pc: usize, reg: u8) -> Option<usize> {
    let (subprog_start, _) = subprog_bounds(insns, pc);
    find_direct_map_load_for_reg_before_pc_inner(
        insns,
        pc,
        reg,
        subprog_start,
        REG_RESOLUTION_LIMIT,
    )
}

fn find_direct_map_load_for_reg_before_pc_inner(
    insns: &[BpfInsn],
    pc: usize,
    reg: u8,
    subprog_start: usize,
    budget: usize,
) -> Option<usize> {
    if budget == 0 {
        return None;
    }
    let mut cursor = pc;
    while let Some(prev_pc) = prev_real_pc_bounded(insns, cursor, subprog_start) {
        let insn = &insns[prev_pc];
        if insn_defines_reg(insn, reg) {
            if insn.is_ldimm64() && insn.dst_reg() == reg && is_pseudo_map_fd_src(insn.src_reg()) {
                return Some(prev_pc);
            }
            if is_mov64_reg(insn) && insn.dst_reg() == reg {
                return find_direct_map_load_for_reg_before_pc_inner(
                    insns,
                    prev_pc,
                    insn.src_reg(),
                    subprog_start,
                    budget - 1,
                );
            }
            if is_stack_dw_load_to_reg(insn, reg) {
                return find_direct_map_load_for_stack_slot_before_pc(
                    insns,
                    prev_pc,
                    insn.off,
                    subprog_start,
                    budget - 1,
                );
            }
            return None;
        }
        cursor = prev_pc;
    }
    None
}

fn find_direct_map_load_for_stack_slot_before_pc(
    insns: &[BpfInsn],
    pc: usize,
    stack_off: i16,
    subprog_start: usize,
    budget: usize,
) -> Option<usize> {
    if budget == 0 {
        return None;
    }
    let mut cursor = pc;
    while let Some(prev_pc) = prev_real_pc_bounded(insns, cursor, subprog_start) {
        let insn = &insns[prev_pc];
        if is_stack_dw_store(insn, stack_off) {
            if insn.class() != BPF_STX {
                return None;
            }
            return find_direct_map_load_for_reg_before_pc_inner(
                insns,
                prev_pc,
                insn.src_reg(),
                subprog_start,
                budget - 1,
            );
        }
        cursor = prev_pc;
    }
    None
}

fn is_mov64_reg(insn: &BpfInsn) -> bool {
    insn.code == (BPF_ALU64 | BPF_MOV | BPF_X)
}

fn is_stack_dw_load_to_reg(insn: &BpfInsn, reg: u8) -> bool {
    insn.class() == BPF_LDX
        && bpf_mode(insn.code) == BPF_MEM
        && bpf_size(insn.code) == BPF_DW
        && insn.dst_reg() == reg
        && insn.src_reg() == 10
}

fn is_stack_dw_store(insn: &BpfInsn, stack_off: i16) -> bool {
    bpf_mode(insn.code) == BPF_MEM
        && bpf_size(insn.code) == BPF_DW
        && matches!(insn.class(), BPF_ST | BPF_STX)
        && insn.dst_reg() == 10
        && insn.off == stack_off
}

fn site_level_inline_veto(reason: impl Into<String>) -> SiteRewriteError {
    SiteRewriteError::Veto(reason.into())
}

fn missing_snapshot_error(err: MapLookupError) -> SiteRewriteError {
    match err {
        MapLookupError::SkippedBySize { map_id } => {
            site_level_inline_veto(map_snapshot_skipped_by_size_reason(map_id))
        }
        err => missing_snapshot_anyhow(anyhow::Error::msg(err.to_string())),
    }
}

fn missing_snapshot_anyhow(err: anyhow::Error) -> SiteRewriteError {
    SiteRewriteError::MissingSnapshot(err)
}

fn is_hash_like_map_type(map_type: u32) -> bool {
    matches!(
        map_type,
        libbpf_sys::BPF_MAP_TYPE_HASH
            | libbpf_sys::BPF_MAP_TYPE_PERCPU_HASH
            | libbpf_sys::BPF_MAP_TYPE_LRU_HASH
            | libbpf_sys::BPF_MAP_TYPE_LRU_PERCPU_HASH
    )
}

fn lookup_pattern_removal_is_safe(
    program: &BpfProgram,
    lookup_call_pc: usize,
    skipped_pcs: &HashSet<usize>,
) -> bool {
    if skipped_pcs.is_empty() || skipped_pcs.iter().any(|&pc| pc >= program.insns.len()) {
        return false;
    }

    let min_removed_pc = *skipped_pcs
        .iter()
        .min()
        .expect("skipped_pcs non-empty (checked above)");
    let end_pc = lookup_call_pc + insn_width(&program.insns[lookup_call_pc]);
    let mut pc = min_removed_pc;
    while pc < end_pc {
        let insn = &program.insns[pc];
        let width = insn_width(insn);
        let insn_pcs = pc..pc + width;

        let fully_skipped = insn_pcs.clone().all(|slot| skipped_pcs.contains(&slot));
        if fully_skipped {
            pc += width;
            continue;
        }
        if insn_pcs.clone().any(|slot| skipped_pcs.contains(&slot)) {
            return false;
        }
        if !lookup_pattern_gap_insn_is_safe(insn) {
            return false;
        }
        if [1u8, 2]
            .into_iter()
            .any(|reg| insn_uses_reg(insn, reg) || insn_defines_reg(insn, reg))
        {
            return false;
        }

        pc += width;
    }

    true
}

fn insert_materialization_pc(
    materialization_pcs: &mut HashSet<usize>,
    insns: &[BpfInsn],
    pc: usize,
) {
    materialization_pcs.insert(pc);
    if insns.get(pc).is_some_and(BpfInsn::is_ldimm64) && pc + 1 < insns.len() {
        materialization_pcs.insert(pc + 1);
    }
}

fn lookup_pattern_gap_insn_is_safe(insn: &BpfInsn) -> bool {
    !insn.is_jmp_class() && !matches!(insn.class(), BPF_ST | BPF_STX)
}

fn find_r2_stack_pointer_setup_simple(
    insns: &[BpfInsn],
    call_pc: usize,
    bounds: (usize, usize),
) -> Option<(usize, usize, i16)> {
    let (r2_add_pc, scanned) =
        find_prev_reg_def_within(insns, call_pc, 2, R2_SETUP_LOOKBACK_LIMIT, bounds.0)?;
    let add = &insns[r2_add_pc];

    if add.code != (BPF_ALU64 | BPF_ADD | BPF_K) || add.dst_reg() != 2 || add.imm >= 0 {
        return None;
    }

    let remaining = R2_SETUP_LOOKBACK_LIMIT.saturating_sub(scanned);
    let (r2_mov_pc, _) = find_prev_reg_def_within(insns, r2_add_pc, 2, remaining, bounds.0)?;
    let mov = &insns[r2_mov_pc];
    if mov.code != (BPF_ALU64 | BPF_MOV | BPF_X) || mov.dst_reg() != 2 || mov.src_reg() != 10 {
        return None;
    }

    Some((r2_mov_pc, r2_add_pc, add.imm as i16))
}

fn find_prev_reg_def_within(
    insns: &[BpfInsn],
    start_pc: usize,
    reg: u8,
    limit: usize,
    lower_bound: usize,
) -> Option<(usize, usize)> {
    let mut cursor = start_pc;
    let mut scanned = 0usize;

    while scanned < limit {
        let pc = prev_real_pc_bounded(insns, cursor, lower_bound)?;
        scanned += 1;
        if insn_defines_reg(&insns[pc], reg) {
            return Some((pc, scanned));
        }
        cursor = pc;
    }

    None
}

fn resolve_constant_reg_value(
    insns: &[BpfInsn],
    before_pc: usize,
    reg: u8,
    bounds: (usize, usize),
) -> Result<ConstantRegValue, String> {
    resolve_constant_reg_value_inner(insns, before_pc, reg, bounds, REG_RESOLUTION_LIMIT)
}

fn resolve_constant_reg_value_inner(
    insns: &[BpfInsn],
    before_pc: usize,
    reg: u8,
    bounds: (usize, usize),
    budget: usize,
) -> Result<ConstantRegValue, String> {
    if budget == 0 {
        return Err(format!(
            "constant register resolution for r{} exceeded {} steps",
            reg, REG_RESOLUTION_LIMIT
        ));
    }

    let Some(pc) = find_prev_reg_def(insns, before_pc, reg, bounds.0) else {
        if reg <= 5 {
            return Err(format!("source register r{} is a function argument", reg));
        }
        return Err(format!("no definition for source register r{}", reg));
    };
    let insn = &insns[pc];

    if insn.is_ldimm64() && insn.dst_reg() == reg {
        if insn.src_reg() != 0 {
            return Err(format!(
                "register r{} at pc {} is loaded from pseudo source {}",
                reg,
                pc,
                insn.src_reg()
            ));
        }
        return Ok(ConstantRegValue {
            value: decode_ldimm64(insns, pc)?,
            source_pc: Some(pc),
        });
    }

    if insn.class() == BPF_LDX
        && bpf_mode(insn.code) == BPF_MEM
        && insn.dst_reg() == reg
        && budget > 1
    {
        if let Some(width) = size_in_bytes(bpf_size(insn.code)) {
            if let Ok(base_stack_off) =
                resolve_stack_pointer_to_stack_inner(insns, pc, insn.src_reg(), bounds, budget - 1)
            {
                let stack_off = i32::from(base_stack_off) + i32::from(insn.off);
                let stack_off = i16::try_from(stack_off).map_err(|_| {
                    format!(
                        "resolved stack load offset {} from r{} does not fit in i16",
                        stack_off, reg
                    )
                })?;
                let stack_bytes = find_constant_stack_bytes_with_limit(
                    insns,
                    pc,
                    bounds,
                    stack_off,
                    width,
                    Some(CONST_STACK_VALUE_LOOKBACK_LIMIT),
                )?;
                return Ok(ConstantRegValue {
                    value: constant_key_value(&stack_bytes.bytes),
                    source_pc: None,
                });
            }
        }
    }

    if (insn.class() == BPF_ALU64 || insn.class() == BPF_ALU) && insn.dst_reg() == reg {
        let is_32bit = insn.class() == BPF_ALU;
        let op = bpf_op(insn.code);
        let src_mode = bpf_src(insn.code);

        if op == BPF_MOV && src_mode == BPF_K {
            return Ok(ConstantRegValue {
                value: apply_alu_width(insn.imm as i64 as u64, is_32bit),
                source_pc: Some(pc),
            });
        }

        if op == BPF_MOV && src_mode == BPF_X {
            let resolved =
                resolve_constant_reg_value_inner(insns, pc, insn.src_reg(), bounds, budget - 1)?;
            return Ok(ConstantRegValue {
                value: apply_alu_width(resolved.value, is_32bit),
                source_pc: resolved.source_pc,
            });
        }

        let lhs = resolve_constant_reg_value_inner(insns, pc, reg, bounds, budget - 1)?;
        let rhs = if src_mode == BPF_K {
            insn.imm as i64 as u64
        } else {
            resolve_constant_reg_value_inner(insns, pc, insn.src_reg(), bounds, budget - 1)?.value
        };
        let value = apply_constant_alu(op, lhs.value, rhs, is_32bit).ok_or_else(|| {
            format!(
                "register r{} definition at pc {} uses unsupported constant op {:#x}",
                reg, pc, insn.code
            )
        })?;
        return Ok(ConstantRegValue {
            value,
            source_pc: None,
        });
    }

    Err(format!(
        "register r{} definition at pc {} is not a supported constant materialization",
        reg, pc
    ))
}

fn size_in_bytes(size: u8) -> Option<u8> {
    match size {
        BPF_B => Some(1),
        BPF_H => Some(2),
        BPF_W => Some(4),
        BPF_DW => Some(8),
        _ => None,
    }
}

fn truncate_imm(imm: i32, width: u8) -> u64 {
    truncate_value(imm as i64 as u64, width)
}

fn truncate_value(value: u64, width: u8) -> u64 {
    match width {
        1 => value & 0xff,
        2 => value & 0xffff,
        4 => value & 0xffff_ffff,
        8 => value,
        _ => value,
    }
}

fn prev_real_pc_bounded(insns: &[BpfInsn], pc: usize, lower_bound: usize) -> Option<usize> {
    if pc <= lower_bound {
        return None;
    }

    let mut cursor = lower_bound;
    let mut prev = None;
    while cursor < pc {
        prev = Some(cursor);
        cursor += insn_width(&insns[cursor]);
    }
    (cursor == pc)
        .then_some(prev?)
        .filter(|prev_pc| *prev_pc >= lower_bound)
}

fn find_prev_reg_def(
    insns: &[BpfInsn],
    start_pc: usize,
    reg: u8,
    lower_bound: usize,
) -> Option<usize> {
    let mut cursor = start_pc;
    while let Some(pc) = prev_real_pc_bounded(insns, cursor, lower_bound) {
        if insn_defines_reg(&insns[pc], reg) {
            return Some(pc);
        }
        cursor = pc;
    }
    None
}

#[cfg(test)]
fn resolve_stack_pointer_to_stack(
    insns: &[BpfInsn],
    before_pc: usize,
    reg: u8,
    bounds: (usize, usize),
) -> Result<i16, String> {
    resolve_stack_pointer_to_stack_inner(insns, before_pc, reg, bounds, REG_RESOLUTION_LIMIT)
}

fn resolve_key_pointer_origin(
    insns: &[BpfInsn],
    before_pc: usize,
    reg: u8,
    bounds: (usize, usize),
) -> Result<KeyPointerOrigin, String> {
    resolve_key_pointer_origin_inner(insns, before_pc, reg, bounds, REG_RESOLUTION_LIMIT)
}

fn resolve_key_pointer_origin_inner(
    insns: &[BpfInsn],
    before_pc: usize,
    reg: u8,
    bounds: (usize, usize),
    budget: usize,
) -> Result<KeyPointerOrigin, String> {
    if budget == 0 {
        return Err(format!(
            "key pointer resolution for r{} exceeded {} steps",
            reg, REG_RESOLUTION_LIMIT
        ));
    }
    if reg == 10 {
        return Ok(KeyPointerOrigin::Stack(0));
    }

    let Some(pc) = find_prev_reg_def(insns, before_pc, reg, bounds.0) else {
        if reg <= 5 {
            return Err(format!("key pointer flows from function argument r{}", reg));
        }
        return Err(format!("no definition for key pointer register r{}", reg));
    };
    let insn = &insns[pc];

    if insn.is_ldimm64() && insn.dst_reg() == reg {
        if is_pseudo_map_value_src(insn.src_reg()) {
            let value_off = insns
                .get(pc + 1)
                .ok_or_else(|| format!("pseudo-map-value load at pc {} is truncated", pc))?
                .imm;
            return Ok(KeyPointerOrigin::MapValue {
                map_ref: MapRefKey {
                    src_reg: insn.src_reg(),
                    imm: insn.imm,
                },
                value_off,
                ldimm_pc: pc,
            });
        }
        return Err(format!(
            "register r{} definition at pc {} is not a pseudo-map-value pointer",
            reg, pc
        ));
    }

    if (insn.class() == BPF_ALU64 || insn.class() == BPF_ALU) && insn.dst_reg() == reg {
        let op = bpf_op(insn.code);
        let src_mode = bpf_src(insn.code);

        if op == BPF_MOV && src_mode == BPF_X {
            return resolve_key_pointer_origin_inner(insns, pc, insn.src_reg(), bounds, budget - 1);
        }

        if op == BPF_ADD || op == BPF_SUB {
            let base = resolve_key_pointer_origin_inner(insns, pc, reg, bounds, budget - 1)?;
            let delta = if src_mode == BPF_K {
                insn.imm as i64
            } else {
                resolve_constant_reg_value_inner(insns, pc, insn.src_reg(), bounds, budget - 1)?
                    .value as i64
            };
            let signed_delta = if op == BPF_SUB { -delta } else { delta };
            return match base {
                KeyPointerOrigin::Stack(stack_off) => {
                    let stack_off = stack_off as i64 + signed_delta;
                    let stack_off = i16::try_from(stack_off).map_err(|_| {
                        format!(
                            "resolved stack offset {} from r{} does not fit in i16",
                            stack_off, reg
                        )
                    })?;
                    Ok(KeyPointerOrigin::Stack(stack_off))
                }
                KeyPointerOrigin::MapValue {
                    map_ref,
                    value_off,
                    ldimm_pc,
                } => {
                    let value_off = value_off as i64 + signed_delta;
                    let value_off = i32::try_from(value_off).map_err(|_| {
                        format!(
                            "resolved pseudo-map-value offset {} from r{} does not fit in i32",
                            value_off, reg
                        )
                    })?;
                    Ok(KeyPointerOrigin::MapValue {
                        map_ref,
                        value_off,
                        ldimm_pc,
                    })
                }
            };
        }
    }

    Err(format!(
        "register r{} definition at pc {} does not resolve to constant stack or pseudo-map-value memory",
        reg, pc
    ))
}

fn resolve_stack_pointer_to_stack_inner(
    insns: &[BpfInsn],
    before_pc: usize,
    reg: u8,
    bounds: (usize, usize),
    budget: usize,
) -> Result<i16, String> {
    if budget == 0 {
        return Err(format!(
            "stack pointer resolution for r{} exceeded {} steps",
            reg, REG_RESOLUTION_LIMIT
        ));
    }
    if reg == 10 {
        return Ok(0);
    }

    let Some(pc) = find_prev_reg_def(insns, before_pc, reg, bounds.0) else {
        if reg <= 5 {
            return Err(format!("key pointer flows from function argument r{}", reg));
        }
        return Err(format!("no definition for key pointer register r{}", reg));
    };
    let insn = &insns[pc];

    if (insn.class() == BPF_ALU64 || insn.class() == BPF_ALU) && insn.dst_reg() == reg {
        let op = bpf_op(insn.code);
        let src_mode = bpf_src(insn.code);

        if op == BPF_MOV && src_mode == BPF_X {
            return resolve_stack_pointer_to_stack_inner(
                insns,
                pc,
                insn.src_reg(),
                bounds,
                budget - 1,
            );
        }

        if op == BPF_ADD || op == BPF_SUB {
            let base = resolve_stack_pointer_to_stack_inner(insns, pc, reg, bounds, budget - 1)?;
            let delta = if src_mode == BPF_K {
                insn.imm as i64
            } else {
                resolve_constant_reg_value_inner(insns, pc, insn.src_reg(), bounds, budget - 1)?
                    .value as i64
            };
            let signed_delta = if op == BPF_SUB { -delta } else { delta };
            let stack_off = base as i64 + signed_delta;
            return i16::try_from(stack_off).map_err(|_| {
                format!(
                    "resolved stack offset {} from r{} does not fit in i16",
                    stack_off, reg
                )
            });
        }
    }

    Err(format!(
        "register r{} definition at pc {} does not resolve to fp-relative stack memory",
        reg, pc
    ))
}

fn decode_ldimm64(insns: &[BpfInsn], pc: usize) -> Result<u64, String> {
    let lo = insns
        .get(pc)
        .ok_or_else(|| format!("ldimm64 at pc {} is out of bounds", pc))?;
    let hi = insns
        .get(pc + 1)
        .ok_or_else(|| format!("ldimm64 at pc {} is missing high half", pc))?;
    Ok((lo.imm as u32 as u64) | ((hi.imm as u32 as u64) << 32))
}

fn apply_alu_width(value: u64, is_32bit: bool) -> u64 {
    if is_32bit {
        value as u32 as u64
    } else {
        value
    }
}

fn apply_constant_alu(op: u8, lhs: u64, rhs: u64, is_32bit: bool) -> Option<u64> {
    let value = if is_32bit {
        let lhs = lhs as u32;
        let rhs = rhs as u32;
        match op {
            BPF_ADD => lhs.wrapping_add(rhs) as u64,
            BPF_SUB => lhs.wrapping_sub(rhs) as u64,
            BPF_MUL => lhs.wrapping_mul(rhs) as u64,
            BPF_AND => (lhs & rhs) as u64,
            BPF_OR => (lhs | rhs) as u64,
            BPF_LSH => {
                if rhs >= 32 {
                    return None;
                }
                lhs.wrapping_shl(rhs) as u64
            }
            BPF_RSH => {
                if rhs >= 32 {
                    return None;
                }
                lhs.wrapping_shr(rhs) as u64
            }
            _ => return None,
        }
    } else {
        match op {
            BPF_ADD => lhs.wrapping_add(rhs),
            BPF_SUB => lhs.wrapping_sub(rhs),
            BPF_MUL => lhs.wrapping_mul(rhs),
            BPF_AND => lhs & rhs,
            BPF_OR => lhs | rhs,
            BPF_LSH => {
                if rhs >= 64 {
                    return None;
                }
                lhs.wrapping_shl(rhs as u32)
            }
            BPF_RSH => {
                if rhs >= 64 {
                    return None;
                }
                lhs.wrapping_shr(rhs as u32)
            }
            _ => return None,
        }
    };
    Some(apply_alu_width(value, is_32bit))
}

fn subprog_bounds(insns: &[BpfInsn], pc: usize) -> (usize, usize) {
    let mut starts = vec![0usize];
    let mut cursor = 0usize;
    while cursor < insns.len() {
        let insn = &insns[cursor];
        if insn.is_call() && insn.src_reg() == BPF_PSEUDO_CALL {
            let target = (cursor as i64 + 1 + insn.imm as i64) as usize;
            if target < insns.len() {
                starts.push(target);
            }
        }
        cursor += insn_width(insn);
    }

    starts.sort_unstable();
    starts.dedup();

    let mut start = 0usize;
    let mut end = insns.len();
    for (idx, subprog_start) in starts.iter().copied().enumerate() {
        if subprog_start > pc {
            break;
        }
        start = subprog_start;
        end = starts.get(idx + 1).copied().unwrap_or(insns.len());
    }
    (start, end)
}

fn site_skip_diagnostic(pc: usize, reason: &str) -> String {
    format!("site at PC={}: skip reason: {}", pc, reason)
}

fn log_map_inline_debug(message: &str) {
    static ENABLED: OnceLock<bool> = OnceLock::new();
    if *ENABLED.get_or_init(|| std::env::var_os("BPFREJIT_MAP_INLINE_DEBUG").is_some()) {
        eprintln!("map_inline: {}", message);
    }
}

fn record_diagnostic(diagnostics: &mut Vec<String>, message: String) {
    log_map_inline_debug(&message);
    diagnostics.push(message);
}

fn record_maps_skipped_by_size_counter(program: &BpfProgram, diagnostics: &mut Vec<String>) {
    let count = program
        .map_snapshots_skipped_by_size
        .iter()
        .filter(|map_id| !program.map_value_overlays.contains_key(map_id))
        .count();
    if count > 0 {
        record_diagnostic(diagnostics, format!("maps_skipped_by_size={count}"));
    }
}

fn map_snapshot_skipped_by_size(program: &BpfProgram, map_id: u32) -> bool {
    program.map_snapshots_skipped_by_size.contains(&map_id)
        && !program.map_value_overlays.contains_key(&map_id)
}

fn map_snapshot_skipped_by_size_reason(map_id: u32) -> String {
    format!("map {map_id} snapshot skipped by size and no overlay provided")
}

fn map_snapshot_skipped_by_size_site_reason(program: &BpfProgram, map_id: u32) -> String {
    format!(
        "map snapshot skipped by size and no overlay provided (map_name={}, map_id={})",
        map_name_for_id(program, map_id),
        map_id
    )
}

fn map_name_for_id(program: &BpfProgram, map_id: u32) -> String {
    match program.map_metadata.get(&map_id) {
        Some(metadata) if !metadata.name.is_empty() => metadata.name.clone(),
        Some(_) => "<unnamed>".to_string(),
        None => "<unknown>".to_string(),
    }
}

fn record_skip(
    skipped: &mut Vec<SkipReason>,
    diagnostics: &mut Vec<String>,
    pc: usize,
    reason: String,
    detail: Option<String>,
) {
    skipped.push(SkipReason {
        pc,
        reason: reason.clone(),
    });
    record_diagnostic(diagnostics, site_skip_diagnostic(pc, &reason));
    if let Some(detail) = detail {
        record_diagnostic(diagnostics, detail);
    }
}

fn format_bytes_preview(bytes: &[u8]) -> String {
    let preview_len = bytes.len().min(VALUE_PREVIEW_BYTES);
    let mut out = String::with_capacity(preview_len.saturating_mul(2) + 6);
    out.push_str("0x");
    for byte in &bytes[..preview_len] {
        write!(out, "{:02x}", byte).expect("writing to String cannot fail");
    }
    if bytes.len() > preview_len {
        out.push_str("...");
    }
    out
}

fn format_inlined_value_diagnostic(value: &[u8], loads: &[FixedLoadUse]) -> String {
    if loads.len() == 1 {
        let load = &loads[0];
        if let Some(scalar) = read_scalar_from_value(value, load.offset, load.size) {
            return format!("0x{scalar:x}");
        }
    }
    format_bytes_preview(value)
}

fn classify_r0_uses_with_options(
    insns: &[BpfInsn],
    start_pc: usize,
    allow_unrelated_helper_calls: bool,
    allow_readonly_helper_calls: bool,
) -> R0UseClassification {
    let mut classification = R0UseClassification::default();
    let mut alias_regs = HashMap::from([(0u8, 0i16)]);
    let mut alias_stack_slots = HashMap::new();
    let bounds = subprog_bounds(insns, start_pc);
    let mut pc = start_pc + 1;

    while pc < insns.len() && (!alias_regs.is_empty() || !alias_stack_slots.is_empty()) {
        let insn = &insns[pc];
        let alias_copy = alias_copy(insn, &alias_regs);
        let allow_null_check =
            classification.fixed_loads.is_empty() && classification.other_uses.is_empty();

        if let Some((dst_reg, alias_off)) = alias_copy {
            classification.alias_copy_pcs.push(pc);
            kill_defined_alias_regs(&mut alias_regs, insn);
            alias_regs.insert(dst_reg, alias_off);
            pc += insn_width(insn);
            continue;
        }

        if let Some(alias_off) = alias_adjustment(insns, pc, insn, &alias_regs, bounds) {
            classification.alias_copy_pcs.push(pc);
            kill_defined_alias_regs(&mut alias_regs, insn);
            alias_regs.insert(insn.dst_reg(), alias_off);
            pc += insn_width(insn);
            continue;
        }

        if allow_null_check
            && classification.null_check_pc.is_none()
            && is_null_check_on_alias(insn, &alias_regs)
        {
            classification.null_check_pc = Some(pc);
            let Some(next_pc) = advance_to_non_null_path(pc, insn, insns.len()) else {
                break;
            };
            pc = next_pc;
            continue;
        }

        if !classification.fixed_loads.is_empty()
            && alias_stack_slots.is_empty()
            && ends_current_use_region(insn, &alias_regs)
        {
            break;
        }

        if let Some((stack_off, width)) = resolve_stack_store_slot(insns, pc, insn, bounds) {
            kill_overlapping_alias_stack_slots(&mut alias_stack_slots, stack_off, width);
            if insn.class() == BPF_STX
                && bpf_mode(insn.code) == BPF_MEM
                && width == 8
                && alias_regs.contains_key(&insn.src_reg())
            {
                classification.alias_copy_pcs.push(pc);
                alias_stack_slots.insert(stack_off, alias_regs[&insn.src_reg()]);
                pc += insn_width(insn);
                continue;
            }
        }

        if let Some(stack_off) = resolve_stack_load_slot(insns, pc, insn, bounds) {
            if let Some(&alias_off) = alias_stack_slots.get(&stack_off) {
                classification.alias_copy_pcs.push(pc);
                alias_stack_slots.remove(&stack_off);
                kill_defined_alias_regs(&mut alias_regs, insn);
                alias_regs.insert(insn.dst_reg(), alias_off);
                pc += insn_width(insn);
                continue;
            }
        }

        if insn.is_call() {
            if insn_uses_any_alias(insn, &alias_regs) {
                classification.other_uses.push(pc);
                break;
            }

            let surviving_aliases = surviving_alias_regs_after_helper_call(&alias_regs);
            let can_follow_helper = allow_unrelated_helper_calls
                || (allow_readonly_helper_calls && helper_call_is_readonly_for_lookup_value(insn));
            if can_follow_helper && (!surviving_aliases.is_empty() || !alias_stack_slots.is_empty())
            {
                alias_regs = surviving_aliases;
                pc += insn_width(insn);
                continue;
            }

            let has_unfollowed_aliases = !surviving_aliases.is_empty();
            alias_regs.clear();
            if !alias_stack_slots.is_empty() {
                pc += insn_width(insn);
                continue;
            }
            if has_unfollowed_aliases {
                classification.other_uses.push(pc);
                break;
            }
            break;
        }

        if insn.is_ldx_mem() && alias_regs.contains_key(&insn.src_reg()) {
            let total_off = i32::from(alias_regs[&insn.src_reg()]) + i32::from(insn.off);
            let Ok(total_off) = i16::try_from(total_off) else {
                classification.other_uses.push(pc);
                kill_defined_alias_regs(&mut alias_regs, insn);
                pc += insn_width(insn);
                continue;
            };
            classification.fixed_loads.push(FixedLoadUse {
                pc,
                dst_reg: insn.dst_reg(),
                size: bpf_size(insn.code),
                offset: total_off,
            });
        } else if insn_uses_any_alias(insn, &alias_regs) {
            classification.other_uses.push(pc);
        }

        kill_defined_alias_regs(&mut alias_regs, insn);

        pc += insn_width(insn);
    }

    classification
}

fn resolve_stack_store_slot(
    insns: &[BpfInsn],
    pc: usize,
    insn: &BpfInsn,
    bounds: (usize, usize),
) -> Option<(i16, u8)> {
    if bpf_mode(insn.code) != BPF_MEM {
        return None;
    }
    let width = size_in_bytes(bpf_size(insn.code))?;
    if !(insn.class() == BPF_ST || insn.class() == BPF_STX) {
        return None;
    }
    let base_stack_off = match resolve_stack_pointer_to_stack_inner(
        insns,
        pc,
        insn.dst_reg(),
        bounds,
        REG_RESOLUTION_LIMIT,
    ) {
        Ok(base_stack_off) => base_stack_off,
        Err(_) => return None,
    };
    let stack_off = i32::from(base_stack_off) + i32::from(insn.off);
    let stack_off = match i16::try_from(stack_off) {
        Ok(stack_off) => stack_off,
        Err(_) => return None,
    };
    Some((stack_off, width))
}

fn resolve_stack_load_slot(
    insns: &[BpfInsn],
    pc: usize,
    insn: &BpfInsn,
    bounds: (usize, usize),
) -> Option<i16> {
    if insn.class() != BPF_LDX || bpf_mode(insn.code) != BPF_MEM || bpf_size(insn.code) != BPF_DW {
        return None;
    }
    let base_stack_off = match resolve_stack_pointer_to_stack_inner(
        insns,
        pc,
        insn.src_reg(),
        bounds,
        REG_RESOLUTION_LIMIT,
    ) {
        Ok(base_stack_off) => base_stack_off,
        Err(_) => return None,
    };
    let stack_off = i32::from(base_stack_off) + i32::from(insn.off);
    let Ok(stack_off) = i16::try_from(stack_off) else {
        return None;
    };
    Some(stack_off)
}

fn kill_overlapping_alias_stack_slots(
    alias_stack_slots: &mut HashMap<i16, i16>,
    stack_off: i16,
    width: u8,
) {
    let store_start = i32::from(stack_off);
    let store_end = store_start + i32::from(width);
    alias_stack_slots.retain(|slot, _| {
        let alias_start = i32::from(*slot);
        let alias_end = alias_start + 8;
        store_end <= alias_start || store_start >= alias_end
    });
}

fn surviving_alias_regs_after_helper_call(alias_regs: &HashMap<u8, i16>) -> HashMap<u8, i16> {
    alias_regs
        .iter()
        .filter(|(reg, _)| (6u8..=9u8).contains(reg))
        .map(|(&reg, &off)| (reg, off))
        .collect()
}

fn helper_call_is_readonly_for_lookup_value(insn: &BpfInsn) -> bool {
    insn.is_call() && insn.src_reg() == 0 && insn.imm == libbpf_sys::BPF_FUNC_ktime_get_ns as i32
}

fn advance_to_non_null_path(pc: usize, insn: &BpfInsn, insn_count: usize) -> Option<usize> {
    let fallthrough_pc = pc + insn_width(insn);
    match bpf_op(insn.code) {
        BPF_JEQ => (fallthrough_pc < insn_count).then_some(fallthrough_pc),
        BPF_JNE => jump_target_pc(pc, insn, insn_count),
        _ => None,
    }
}

fn jump_target_pc(pc: usize, insn: &BpfInsn, insn_count: usize) -> Option<usize> {
    let target = pc as isize + 1 + insn.off as isize;
    (0..insn_count as isize)
        .contains(&target)
        .then_some(target as usize)
}

fn ends_current_use_region(insn: &BpfInsn, alias_regs: &HashMap<u8, i16>) -> bool {
    (insn.is_jmp_class()
        && !insn.is_call()
        && !insn.is_exit()
        && !insn_uses_any_alias(insn, alias_regs))
        || starts_next_lookup_setup(insn)
}

fn starts_next_lookup_setup(insn: &BpfInsn) -> bool {
    insn.is_ldimm64() && is_pseudo_map_fd_src(insn.src_reg())
}

fn is_pseudo_map_fd_src(src_reg: u8) -> bool {
    src_reg == BPF_PSEUDO_MAP_FD || src_reg == BPF_PSEUDO_MAP_IDX
}

fn is_pseudo_map_value_src(src_reg: u8) -> bool {
    src_reg == BPF_PSEUDO_MAP_VALUE || src_reg == BPF_PSEUDO_MAP_IDX_VALUE
}

fn alias_copy(insn: &BpfInsn, alias_regs: &HashMap<u8, i16>) -> Option<(u8, i16)> {
    (insn.code == (BPF_ALU64 | BPF_MOV | BPF_X))
        .then(|| {
            alias_regs
                .get(&insn.src_reg())
                .copied()
                .map(|off| (insn.dst_reg(), off))
        })
        .flatten()
}

fn alias_adjustment(
    insns: &[BpfInsn],
    pc: usize,
    insn: &BpfInsn,
    alias_regs: &HashMap<u8, i16>,
    bounds: (usize, usize),
) -> Option<i16> {
    if insn.class() != BPF_ALU64 {
        return None;
    }

    let base_off = i32::from(*alias_regs.get(&insn.dst_reg())?);
    let delta = match (bpf_op(insn.code), bpf_src(insn.code)) {
        (BPF_ADD, BPF_K) => insn.imm as i64,
        (BPF_SUB, BPF_K) => -(insn.imm as i64),
        (BPF_ADD, BPF_X) => match resolve_constant_reg_value_inner(
            insns,
            pc,
            insn.src_reg(),
            bounds,
            REG_RESOLUTION_LIMIT,
        ) {
            Ok(value) => value.value as i64,
            Err(_) => return None,
        },
        (BPF_SUB, BPF_X) => match resolve_constant_reg_value_inner(
            insns,
            pc,
            insn.src_reg(),
            bounds,
            REG_RESOLUTION_LIMIT,
        ) {
            Ok(value) => -(value.value as i64),
            Err(_) => return None,
        },
        _ => return None,
    };
    let Ok(adjusted) = i16::try_from(base_off as i64 + delta) else {
        return None;
    };
    Some(adjusted)
}

fn is_null_check_on_alias(insn: &BpfInsn, alias_regs: &HashMap<u8, i16>) -> bool {
    let op = bpf_op(insn.code);
    insn.class() == BPF_JMP
        && matches!(op, BPF_JEQ | BPF_JNE)
        && bpf_src(insn.code) == BPF_K
        && insn.src_reg() == 0
        && insn.imm == 0
        && (op == BPF_JEQ || insn.off >= 0)
        && alias_regs.get(&insn.dst_reg()).copied() == Some(0)
}

fn null_check_is_fallthrough_non_null(insn: &BpfInsn) -> bool {
    insn.class() == BPF_JMP
        && bpf_op(insn.code) == BPF_JEQ
        && bpf_src(insn.code) == BPF_K
        && insn.src_reg() == 0
        && insn.imm == 0
        && insn.off >= 0
}

fn null_check_removal_window_is_trivial(
    program: &BpfProgram,
    uses: &R0UseClassification,
    null_check_pc: usize,
    skipped_pcs: &HashSet<usize>,
    replacement_pcs: &HashSet<usize>,
) -> bool {
    let Some(null_target_pc) = jump_target_pc(
        null_check_pc,
        &program.insns[null_check_pc],
        program.insns.len(),
    ) else {
        return false;
    };
    let Some(mut pc) = advance_to_non_null_path(
        null_check_pc,
        &program.insns[null_check_pc],
        program.insns.len(),
    ) else {
        return false;
    };
    let load_dst_regs = uses
        .fixed_loads
        .iter()
        .map(|load| (load.pc, load.dst_reg))
        .collect::<HashMap<_, _>>();
    let mut safe_scalar_regs = HashSet::new();
    let mut killed_arg_regs = HashSet::new();

    while pc < null_target_pc {
        let insn = &program.insns[pc];
        let width = insn_width(insn);
        let insn_pcs = pc..pc + width;

        if insn_pcs.clone().all(|slot| skipped_pcs.contains(&slot)) {
            for reg in 1..=5 {
                if insn_defines_reg(insn, reg) {
                    killed_arg_regs.insert(reg);
                    safe_scalar_regs.remove(&reg);
                }
            }
            pc += width;
            continue;
        }
        if insn_pcs.clone().any(|slot| skipped_pcs.contains(&slot)) {
            return false;
        }
        if replacement_pcs.contains(&pc) {
            let Some(&dst_reg) = load_dst_regs.get(&pc) else {
                return false;
            };
            mark_safe_scalar_reg(&mut safe_scalar_regs, &mut killed_arg_regs, dst_reg);
            pc += width;
            continue;
        }

        if !is_trivially_safe_null_check_guarded_insn(
            insn,
            &mut safe_scalar_regs,
            &mut killed_arg_regs,
        ) {
            return false;
        }
        pc += width;
    }

    true
}

fn is_trivially_safe_null_check_guarded_insn(
    insn: &BpfInsn,
    safe_scalar_regs: &mut HashSet<u8>,
    killed_arg_regs: &mut HashSet<u8>,
) -> bool {
    if insn.is_exit() || insn.is_ja() {
        return true;
    }

    if insn.is_ldimm64() {
        if insn.src_reg() != 0 {
            return false;
        }
        mark_safe_scalar_reg(safe_scalar_regs, killed_arg_regs, insn.dst_reg());
        return true;
    }

    match insn.class() {
        BPF_ALU64 | BPF_ALU => match (bpf_op(insn.code), bpf_src(insn.code)) {
            (BPF_MOV, BPF_K) => {
                mark_safe_scalar_reg(safe_scalar_regs, killed_arg_regs, insn.dst_reg());
                true
            }
            (BPF_MOV, BPF_X) if safe_scalar_regs.contains(&insn.src_reg()) => {
                mark_safe_scalar_reg(safe_scalar_regs, killed_arg_regs, insn.dst_reg());
                true
            }
            (BPF_ADD | BPF_SUB | BPF_MUL | BPF_AND | BPF_OR | BPF_LSH | BPF_RSH, BPF_K)
                if safe_scalar_regs.contains(&insn.dst_reg()) =>
            {
                mark_safe_scalar_reg(safe_scalar_regs, killed_arg_regs, insn.dst_reg());
                true
            }
            (BPF_ADD | BPF_SUB | BPF_MUL | BPF_AND | BPF_OR | BPF_LSH | BPF_RSH, BPF_X)
                if safe_scalar_regs.contains(&insn.dst_reg())
                    && safe_scalar_regs.contains(&insn.src_reg()) =>
            {
                mark_safe_scalar_reg(safe_scalar_regs, killed_arg_regs, insn.dst_reg());
                true
            }
            _ => false,
        },
        BPF_JMP | BPF_JMP32 if insn.is_call() => {
            if (1..=5).any(|reg| killed_arg_regs.contains(&reg)) {
                return false;
            }
            for reg in 0..=5 {
                safe_scalar_regs.remove(&reg);
            }
            killed_arg_regs.extend(1..=5);
            true
        }
        _ => false,
    }
}

fn mark_safe_scalar_reg(
    safe_scalar_regs: &mut HashSet<u8>,
    killed_arg_regs: &mut HashSet<u8>,
    reg: u8,
) {
    safe_scalar_regs.insert(reg);
    killed_arg_regs.remove(&reg);
}

fn insn_uses_any_alias(insn: &BpfInsn, alias_regs: &HashMap<u8, i16>) -> bool {
    alias_regs
        .keys()
        .copied()
        .any(|reg| insn_uses_reg(insn, reg))
}

fn kill_defined_alias_regs(alias_regs: &mut HashMap<u8, i16>, insn: &BpfInsn) {
    alias_regs.retain(|&reg, _| !insn_defines_reg(insn, reg));
}

fn insn_uses_reg(insn: &BpfInsn, reg: u8) -> bool {
    match insn.class() {
        BPF_ALU64 | BPF_ALU => {
            if bpf_op(insn.code) == BPF_MOV {
                bpf_src(insn.code) == BPF_X && insn.src_reg() == reg
            } else {
                insn.dst_reg() == reg || (bpf_src(insn.code) == BPF_X && insn.src_reg() == reg)
            }
        }
        BPF_LDX => insn.src_reg() == reg,
        BPF_ST => insn.dst_reg() == reg,
        BPF_STX => insn.dst_reg() == reg || insn.src_reg() == reg,
        BPF_JMP | BPF_JMP32 => {
            if insn.is_call() {
                (1..=5).contains(&reg)
            } else if insn.is_exit() {
                reg == 0
            } else if insn.is_ja() {
                false
            } else {
                insn.dst_reg() == reg || (bpf_src(insn.code) == BPF_X && insn.src_reg() == reg)
            }
        }
        _ => false,
    }
}

fn insn_defines_reg(insn: &BpfInsn, reg: u8) -> bool {
    match insn.class() {
        BPF_ALU64 | BPF_ALU | BPF_LDX | BPF_LD => insn.dst_reg() == reg,
        BPF_JMP | BPF_JMP32 => insn.is_call() && reg <= 5,
        _ => false,
    }
}

#[cfg(test)]
#[path = "map_inline_tests.rs"]
mod tests;
