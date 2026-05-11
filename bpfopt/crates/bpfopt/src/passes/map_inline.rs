// SPDX-License-Identifier: MIT
use crate::analysis::{insn_use_def_set, BBProgram, InsnSite, Terminator};
use crate::insn::*;
use crate::pass::*;
use anyhow::{anyhow, bail, Context, Result};
use serde::Deserialize;
use std::collections::{BTreeMap, BTreeSet, HashMap, HashSet};
use std::fs;
use std::path::{Path, PathBuf};
use std::sync::OnceLock;
mod map_info;
use map_info::analyze_map_info;
pub use map_info::{MapInfo, MapInfoAnalysis, MapInfoResult, MapReference};
const R2_SETUP_LOOKBACK_LIMIT: usize = 8;
const REG_RESOLUTION_LIMIT: usize = 64;
const CONST_STACK_VALUE_LOOKBACK_LIMIT: usize = 256;
const MAP_INLINE_FIXED_POINT_MAX_ITERS: usize = 8;
const VALUE_PREVIEW_BYTES: usize = 32;
fn read_json_from_path<T: serde::de::DeserializeOwned>(path: &Path, label: &str) -> Result<T> {
    let data = fs::read(path).with_context(|| format!("failed to read {}", path.display()))?;
    serde_json::from_slice(&data)
        .with_context(|| format!("failed to parse {label} from {}", path.display()))
}
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
    fn run(&self, program: &mut BBProgram, ctx: &PassContext) -> anyhow::Result<PassResult> {
        let mut ctx = ctx.clone();
        ctx.map_ids = self.map_ids.clone();
        ctx.map_metadata = self.snapshot.metadata.clone();
        ctx.map_values = self.snapshot.values.clone();
        ctx.map_value_overlays = self.snapshot.compressed_values.clone();
        ctx.map_inner_map_ids = self.snapshot.inner_map_ids.clone();
        ctx.map_snapshots_skipped_by_size = self.snapshot.maps_skipped_by_size.clone();
        ctx.map_inline_hints = self.inline_hints.clone();
        MapInlinePass.run(program, &ctx)
    }
}
struct MapInlineCliArgs {
    map_values: PathBuf,
    map_ids: String,
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
    let first = input.as_bytes()[0];
    if !(first.is_ascii_alphabetic() || first == b'_') {
        bail!("map-name anchor must start with a letter or underscore");
    }
    if !input
        .bytes()
        .skip(1)
        .all(|byte| byte.is_ascii_alphanumeric() || byte == b'_')
    {
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
fn snapshot_map_info(
    ctx: &PassContext,
    map_id: u32,
) -> std::result::Result<Option<MapInfo>, String> {
    let Some(metadata) = ctx.map_metadata.get(&map_id) else {
        return Err(format!(
            "map_values snapshot has no metadata for map {}",
            map_id
        ));
    };
    Ok(Some(MapInfo {
        map_type: metadata.map_type,
        key_size: metadata.key_size,
        value_size: metadata.value_size,
        max_entries: metadata.max_entries,
        map_id: metadata.map_id,
    }))
}
fn lookup_value_size(ctx: &PassContext, info: &MapInfo) -> std::result::Result<usize, String> {
    if let Some(overlay) = ctx.map_value_overlays.get(&info.map_id) {
        return Ok(overlay.value_size);
    }
    if let Some(value_size) = ctx
        .map_values
        .iter()
        .find_map(|((map_id, _), value)| (*map_id == info.map_id).then_some(value.len()))
    {
        return Ok(value_size);
    }
    Ok(info.value_size as usize)
}
fn lookup_elem(
    ctx: &PassContext,
    map_id: u32,
    key: &[u8],
    value_size: usize,
) -> std::result::Result<Vec<u8>, MapLookupError> {
    if let Some(overlay) = ctx.map_value_overlays.get(&map_id) {
        return match overlay.lookup(key) {
            Some(value) => {
                if value.len() != value_size {
                    Err(MapLookupError::Failed(format!(
                        "compressed map {} returned value size {}, expected {}",
                        map_id,
                        value.len(),
                        value_size
                    )))
                } else {
                    Ok(value)
                }
            }
            None => Err(MapLookupError::MissingKey {
                map_id,
                key: key.to_vec(),
            }),
        };
    }
    if ctx.map_snapshots_skipped_by_size.contains(&map_id) {
        return Err(MapLookupError::SkippedBySize { map_id });
    }
    if let Some(value) = ctx.map_values.get(&(map_id, key.to_vec())) {
        if value.len() != value_size {
            return Err(MapLookupError::Failed(format!(
                "snapshot map {} returned value size {}, expected {}",
                map_id,
                value.len(),
                value_size
            )));
        }
        return Ok(value.clone());
    }
    if !ctx.map_metadata.contains_key(&map_id) {
        return Err(MapLookupError::Failed(format!(
            "map_values snapshot has no metadata for map {}",
            map_id
        )));
    }
    Err(MapLookupError::MissingKey {
        map_id,
        key: key.to_vec(),
    })
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
    let show: BpftoolMapShowJson = read_json_from_path(&show_path, "bpftool map show JSON")?;
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
            .map_err(|err| anyhow::anyhow!("invalid compressed overlay for map {map_id}: {err}"))?;
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
            let hex = match byte.strip_prefix("0x") {
                Some(hex) => hex,
                None => byte,
            };
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
        let prog_info: ProgInfoMapIdsJson =
            read_json_from_path(Path::new(value), "prog_info JSON")?;
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
#[derive(Clone, Debug, PartialEq, Eq)]
struct MapLookupSite {
    call_site: InsnSite,
    map_load_site: InsnSite,
}

fn sites_after_site_in_frame(prog: &BBProgram, start: InsnSite) -> anyhow::Result<Vec<InsnSite>> {
    let frame = prog.block_frame(start.block)?;
    let mut seen_start = false;
    let mut sites = Vec::new();
    for block in prog.subprog_blocks(frame) {
        for site in prog.sites_in_block_with_terminator(block)? {
            if seen_start {
                sites.push(site);
            } else if site == start {
                seen_start = true;
            }
        }
    }
    if !seen_start {
        anyhow::bail!("site {:?} is missing from frame {:?}", start, frame);
    }
    Ok(sites)
}

fn sites_before_site_in_frame_rev(
    prog: &BBProgram,
    end: InsnSite,
) -> anyhow::Result<Vec<InsnSite>> {
    let frame = prog.block_frame(end.block)?;
    let mut seen_end = false;
    let mut sites = Vec::new();
    for block in prog.subprog_blocks(frame) {
        for site in prog.sites_in_block_with_terminator(block)? {
            if site == end {
                seen_end = true;
                break;
            }
            sites.push(site);
        }
        if seen_end {
            break;
        }
    }
    if !seen_end {
        anyhow::bail!("site {:?} is missing from frame {:?}", end, frame);
    }
    sites.reverse();
    Ok(sites)
}

fn position_in_sites(sites: &[InsnSite], site: InsnSite) -> anyhow::Result<usize> {
    sites
        .iter()
        .position(|candidate| *candidate == site)
        .ok_or_else(|| anyhow::anyhow!("site {:?} is not in program order", site))
}
#[derive(Clone, Debug, PartialEq, Eq)]
struct MapInMapChain {
    outer_site: MapLookupSite,
    inner_call_site: InsnSite,
    outer_alias_copy_sites: Vec<InsnSite>,
    outer_null_check_site: Option<InsnSite>,
}
#[derive(Clone, Debug, PartialEq, Eq)]
struct ConstantKey {
    stack_off: Option<i16>,
    width: usize,
    value: u64,
    bytes: Vec<u8>,
    store_site: InsnSite,
    source_imm_site: Option<InsnSite>,
    materialization_sites: BTreeSet<InsnSite>,
    r2_mov_site: Option<InsnSite>,
    r2_add_site: Option<InsnSite>,
}
#[derive(Clone, Debug, PartialEq, Eq)]
struct ExtractedConstantKey {
    key: ConstantKey,
    used_inline_hint: Option<MapInlineHintAnchor>,
}
#[derive(Debug)]
enum KeyExtractionError {
    Unavailable(String),
    Error(anyhow::Error),
}
#[derive(Clone, Debug, PartialEq, Eq)]
struct FixedLoadUse {
    site: InsnSite,
    dst_reg: u8,
    size: u8,
    offset: i16,
}
#[derive(Clone, Debug, Default, PartialEq, Eq)]
struct R0UseClassification {
    fixed_loads: Vec<FixedLoadUse>,
    other_use_sites: Vec<InsnSite>,
    alias_copy_sites: Vec<InsnSite>,
    null_check_site: Option<InsnSite>,
}
#[derive(Clone, Debug, PartialEq, Eq)]
struct ConstantRegValue {
    value: u64,
    source_site: Option<InsnSite>,
}
#[derive(Clone, Debug, PartialEq, Eq)]
struct ConstantStackBytes {
    bytes: Vec<u8>,
    latest_store_site: InsnSite,
    latest_source_imm_site: Option<InsnSite>,
    materialization_sites: BTreeSet<InsnSite>,
}
#[derive(Clone, Debug)]
struct SnapshotMapValue {
    map_id: u32,
    key: Vec<u8>,
    value: Vec<u8>,
}
#[derive(Clone, Debug)]
struct SiteReplacement {
    site: InsnSite,
    replacement: Vec<BpfInsn>,
}
#[derive(Clone, Debug)]
struct DirectMapValueLoadRewriteResult {
    replacements: Vec<SiteReplacement>,
    sites_applied: usize,
    site_diagnostics: Vec<SiteDiagnostic>,
    records: Vec<MapInlineRecord>,
}
#[derive(Clone, Debug, PartialEq, Eq)]
enum KeyPointerOrigin {
    Stack(i16),
    MapValue {
        map_ref: MapRefKey,
        value_off: i32,
        ldimm_site: InsnSite,
    },
}
#[derive(Clone, Copy, Debug, PartialEq, Eq, Hash)]
struct MapRefKey {
    src_reg: u8,
    imm: i32,
}
fn find_map_lookup_sites(prog: &BBProgram) -> anyhow::Result<Vec<MapLookupSite>> {
    let mut sites = Vec::new();
    for block in prog.blocks() {
        for site in prog.sites_in_block(block.id)? {
            let Some(insn) = prog.insn_at(site) else {
                continue;
            };
            if !is_map_lookup_elem_call(insn) {
                continue;
            }
            if let Some(map_load_site) = find_map_load_for_call(prog, site)? {
                sites.push(MapLookupSite {
                    call_site: site,
                    map_load_site,
                });
            }
        }
    }
    Ok(sites)
}
fn find_map_in_map_chains(
    prog: &BBProgram,
    outer_sites: &[MapLookupSite],
) -> anyhow::Result<Vec<MapInMapChain>> {
    outer_sites
        .iter()
        .map(|outer_site| find_map_in_map_chain_for_outer(prog, outer_site))
        .filter_map(|result| match result {
            Ok(Some(chain)) => Some(Ok(chain)),
            Ok(None) => None,
            Err(err) => Some(Err(err)),
        })
        .collect()
}
fn find_map_in_map_chain_for_outer(
    prog: &BBProgram,
    outer_site: &MapLookupSite,
) -> anyhow::Result<Option<MapInMapChain>> {
    let mut alias_regs = HashMap::from([(0u8, 0i16)]);
    let mut alias_stack_slots = HashMap::new();
    let mut alias_copy_sites = Vec::new();
    let mut null_check_site = None;
    let sites = sites_after_site_in_frame(prog, outer_site.call_site)?;
    let mut pos = 0usize;
    while pos < sites.len() && (!alias_regs.is_empty() || !alias_stack_slots.is_empty()) {
        let site = sites[pos];
        let insn = prog.insn(site)?;
        let allow_null_check = null_check_site.is_none();
        if allow_null_check && is_null_check_on_alias(insn, &alias_regs) {
            null_check_site = Some(site);
            let Some(next_site) = non_null_successor_site(prog, site, insn)? else {
                break;
            };
            let Some(next_pos) = sites.iter().position(|candidate| *candidate == next_site) else {
                break;
            };
            pos = next_pos;
            continue;
        }
        if insn.is_call()
            && insn.src_reg() == 0
            && insn.imm == libbpf_sys::BPF_FUNC_map_lookup_elem as i32
        {
            if alias_regs.get(&1).copied() == Some(0) {
                return Ok(Some(MapInMapChain {
                    outer_site: outer_site.clone(),
                    inner_call_site: site,
                    outer_alias_copy_sites: alias_copy_sites,
                    outer_null_check_site: null_check_site,
                }));
            }
            break;
        }
        if let Some((dst_reg, alias_off)) = alias_copy(insn, &alias_regs) {
            if alias_off != 0 {
                break;
            }
            alias_copy_sites.push(site);
            kill_defined_alias_regs(&mut alias_regs, insn);
            alias_regs.insert(dst_reg, alias_off);
            pos += 1;
            continue;
        }
        if let Some((stack_off, width)) = resolve_stack_store_slot(prog, site, insn) {
            kill_overlapping_alias_stack_slots(&mut alias_stack_slots, stack_off, width);
            if insn.class() == BPF_STX
                && bpf_mode(insn.code) == BPF_MEM
                && width == 8
                && alias_regs.contains_key(&insn.src_reg())
            {
                alias_copy_sites.push(site);
                alias_stack_slots.insert(stack_off, alias_regs[&insn.src_reg()]);
                pos += 1;
                continue;
            }
        }
        if let Some(stack_off) = resolve_stack_load_slot(prog, site, insn) {
            if let Some(&alias_off) = alias_stack_slots.get(&stack_off) {
                alias_copy_sites.push(site);
                alias_stack_slots.remove(&stack_off);
                kill_defined_alias_regs(&mut alias_regs, insn);
                alias_regs.insert(insn.dst_reg(), alias_off);
                pos += 1;
                continue;
            }
        }
        if insn_uses_any_alias(insn, &alias_regs) {
            break;
        }
        kill_defined_alias_regs(&mut alias_regs, insn);
        pos += 1;
    }
    Ok(None)
}
fn try_extract_constant_key_verifier_guided(
    prog: &BBProgram,
    call_site: InsnSite,
    key_size: u32,
) -> Result<ConstantKey, String> {
    if key_size == 0 {
        return Err("map key size is zero".to_string());
    }
    let key_width: usize = key_size
        .try_into()
        .map_err(|_| format!("map key size {} does not fit in usize", key_size))?;
    if prog.site_is_dead_code(call_site) {
        return Err(format!("lookup call at {:?} is dead code", call_site));
    }
    let _r2_kind = prog.reg_kind(call_site, BPF_REG_2);
    let _r2_bounds = prog.reg_proven_bounds(call_site, BPF_REG_2);
    let (r2_mov_site, r2_add_site, key_off) = find_r2_stack_pointer_setup_simple(prog, call_site)
        .map_err(|err| err.to_string())?
        .ok_or_else(|| {
            format!(
                "no materialized r2 stack pointer setup found for lookup at {:?}",
                call_site
            )
        })?;
    let key_width_u8 = u8::try_from(key_width)
        .map_err(|_| format!("map key size {} does not fit in u8", key_size))?;
    let stack_bytes = find_constant_stack_bytes_with_limit(
        prog,
        call_site,
        key_off,
        key_width_u8,
        Some(CONST_STACK_VALUE_LOOKBACK_LIMIT),
    )?;
    let bytes = stack_bytes.bytes;
    Ok(ConstantKey {
        stack_off: Some(key_off),
        width: key_width,
        value: constant_key_value(&bytes),
        bytes,
        store_site: stack_bytes.latest_store_site,
        source_imm_site: stack_bytes.latest_source_imm_site,
        materialization_sites: stack_bytes.materialization_sites,
        r2_mov_site: Some(r2_mov_site),
        r2_add_site: Some(r2_add_site),
    })
}
fn materialization_for_snapshot_key(
    prog: &BBProgram,
    call_site: InsnSite,
    stack_off: i16,
    key_width: usize,
    snapshot_bytes: &[u8],
) -> Result<Option<ConstantStackBytes>, String> {
    let key_width = match u8::try_from(key_width) {
        Ok(key_width) => key_width,
        Err(_) => return Ok(None),
    };
    let stack_bytes = find_constant_stack_bytes_with_limit(
        prog,
        call_site,
        stack_off,
        key_width,
        Some(CONST_STACK_VALUE_LOOKBACK_LIMIT),
    )?;
    Ok((stack_bytes.bytes == snapshot_bytes).then_some(stack_bytes))
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
fn find_constant_stack_bytes_with_limit(
    prog: &BBProgram,
    before_site: InsnSite,
    stack_off: i16,
    key_width: u8,
    mut lookback_limit: Option<usize>,
) -> Result<ConstantStackBytes, String> {
    let key_width_usize = usize::from(key_width);
    let target_start = i32::from(stack_off);
    let target_end = target_start + i32::from(key_width);
    let mut raw = vec![None; key_width_usize];
    let mut latest_store_site = None;
    let mut latest_source_imm_site = None;
    let mut materialization_sites = BTreeSet::new();
    for site in sites_before_site_in_frame_rev(prog, before_site).map_err(|err| err.to_string())? {
        if let Some(remaining) = lookback_limit.as_mut() {
            if *remaining == 0 {
                break;
            }
            *remaining -= 1;
        }
        let insn = prog.insn(site).map_err(|err| err.to_string())?;
        let Some((store_off, width)) = resolve_stack_store_slot(prog, site, insn) else {
            continue;
        };
        let store_start = i32::from(store_off);
        let store_end = store_start + i32::from(width);
        let overlap_start = target_start.max(store_start);
        let overlap_end = target_end.min(store_end);
        if overlap_start >= overlap_end {
            continue;
        }
        let bytes = constant_stack_store_bytes(prog, site)?;
        let source_imm_site = constant_stack_store_source_site(prog, site)?;
        let mut covered_new_byte = false;
        for absolute_off in overlap_start..overlap_end {
            let key_idx = usize::try_from(absolute_off - target_start)
                .map_err(|_| format!("negative key byte index at stack offset {absolute_off}"))?;
            if key_idx >= key_width_usize || raw[key_idx].is_some() {
                continue;
            }
            let store_idx = usize::try_from(absolute_off - store_start)
                .map_err(|_| format!("negative store byte index at stack offset {absolute_off}"))?;
            if store_idx >= bytes.len() {
                return Err(format!(
                    "stack store at {:?} does not cover expected byte offset {}",
                    site, absolute_off
                ));
            }
            raw[key_idx] = Some(bytes[store_idx]);
            covered_new_byte = true;
        }
        if covered_new_byte {
            latest_store_site.get_or_insert(site);
            if latest_source_imm_site.is_none() {
                latest_source_imm_site = source_imm_site;
            }
            materialization_sites.insert(site);
            materialization_sites.extend(source_imm_site);
        }
        if raw.iter().all(Option::is_some) {
            let bytes = raw.into_iter().collect::<Option<Vec<_>>>().ok_or_else(|| {
                "constant stack byte collection ended with missing byte".to_string()
            })?;
            return Ok(ConstantStackBytes {
                bytes,
                latest_store_site: latest_store_site.ok_or_else(|| {
                    "constant stack byte collection found no materializing store".to_string()
                })?,
                latest_source_imm_site,
                materialization_sites,
            });
        }
    }
    Err(format!(
        "no constant stack store sequence found for fp{} width {}",
        stack_off, key_width
    ))
}
fn constant_stack_store_bytes(prog: &BBProgram, store_site: InsnSite) -> Result<Vec<u8>, String> {
    let insn = prog.insn(store_site).map_err(|err| err.to_string())?;
    let width = size_in_bytes(bpf_size(insn.code)).ok_or_else(|| {
        format!(
            "stack store at {:?} uses unsupported width opcode {:#x}",
            store_site, insn.code
        )
    })?;
    let value = if bpf_class(insn.code) == BPF_ST {
        truncate_imm(insn.imm, width)
    } else if bpf_class(insn.code) == BPF_STX {
        let resolved = resolve_constant_reg_value(prog, store_site, insn.src_reg())?;
        truncate_value(resolved.value, width)
    } else {
        return Err(format!(
            "instruction at {:?} is not a stack store",
            store_site
        ));
    };
    Ok(value.to_le_bytes()[..usize::from(width)].to_vec())
}
fn constant_stack_store_source_site(
    prog: &BBProgram,
    store_site: InsnSite,
) -> Result<Option<InsnSite>, String> {
    let insn = prog.insn(store_site).map_err(|err| err.to_string())?;
    if bpf_class(insn.code) == BPF_ST {
        return Ok(None);
    }
    if bpf_class(insn.code) != BPF_STX {
        return Err(format!(
            "instruction at {:?} is not a stack store",
            store_site
        ));
    }
    Ok(resolve_constant_reg_value(prog, store_site, insn.src_reg())?.source_site)
}
#[derive(Clone, Debug)]
struct SiteRewrite {
    call_site: InsnSite,
    diagnostic_value: String,
    removed_null_check: bool,
    map_inline_records: Vec<MapInlineRecord>,
    skipped_sites: BTreeSet<InsnSite>,
    replacements: Vec<SiteReplacement>,
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
fn site_replacement(
    prog: &BBProgram,
    site: InsnSite,
    replacement: Vec<BpfInsn>,
) -> SiteRewriteResult<SiteReplacement> {
    prog.insn(site).map_err(SiteRewriteError::Error)?;
    Ok(SiteReplacement { site, replacement })
}
#[derive(Clone, Debug)]
struct KernelMutableMaps {
    ids: HashSet<u32>,
    reasons: HashMap<u32, String>,
}
#[derive(Clone, Debug, Default)]
struct ResolvedInlineHints {
    by_call_site: HashMap<InsnSite, Vec<ResolvedInlineHint>>,
}
#[derive(Clone, Debug)]
struct HintedMapInMapRoute {
    inner_call_site: InsnSite,
    inner_info: MapInfo,
}
#[derive(Clone, Debug, PartialEq, Eq)]
enum ResolvedHintAnchor {
    CallSite(InsnSite),
    MapName(String),
}
#[derive(Clone, Debug)]
struct BoundaryResolvedInlineHint {
    anchor: ResolvedHintAnchor,
    original_anchor: MapInlineHintAnchor,
    mode: MapInlineHintMode,
    key: Vec<u8>,
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
}
impl ResolvedInlineHints {
    fn for_call_site(&self, call_site: InsnSite) -> Option<&[ResolvedInlineHint]> {
        self.by_call_site.get(&call_site).map(Vec::as_slice)
    }
}
fn is_map_lookup_elem_call(insn: &BpfInsn) -> bool {
    insn.is_call() && insn.src_reg() == 0 && insn.imm == libbpf_sys::BPF_FUNC_map_lookup_elem as i32
}
fn lookup_call_sites(prog: &BBProgram) -> anyhow::Result<Vec<InsnSite>> {
    let mut sites = Vec::new();
    for site in prog.all_sites() {
        if prog.insn_at(site).is_some_and(is_map_lookup_elem_call) {
            sites.push(site);
        }
    }
    Ok(sites)
}

fn lookup_call_site_at_pc(prog: &BBProgram, pc: usize) -> anyhow::Result<Option<InsnSite>> {
    let _ = prog;
    anyhow::bail!(
        "pc-addressed map_inline hints must be resolved before pass execution; unresolved pc {pc}"
    )
}

fn collect_kernel_mutable_maps(
    prog: &BBProgram,
    ctx: &PassContext,
    map_info: &MapInfoResult,
) -> anyhow::Result<KernelMutableMaps> {
    let mut ids = HashSet::new();
    let mut reasons = HashMap::new();
    for metadata in ctx.map_metadata.values() {
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
    for site in prog.all_sites() {
        let insn = prog.insn(site)?;
        if is_map_writer_helper_call(insn) {
            let Some(map_load_site) = find_direct_map_load_for_reg_before_site(prog, site, 1)?
            else {
                continue;
            };
            let helper_name = map_writer_helper_name(insn.imm);
            let map_ref = map_info.reference_at_site(map_load_site).ok_or_else(|| {
                anyhow::anyhow!(
                    "map_inline cannot resolve map reference at {:?} for {helper_name} helper at {:?}",
                    map_load_site,
                    site
                )
            })?;
            let map_id = map_ref.map_id.ok_or_else(|| {
                anyhow::anyhow!(
                    "map_inline cannot resolve map_id at {:?} for {helper_name} helper at {:?}",
                    map_load_site,
                    site
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
fn map_type_is_map_in_map(map_type: u32) -> bool {
    matches!(
        map_type,
        libbpf_sys::BPF_MAP_TYPE_ARRAY_OF_MAPS | libbpf_sys::BPF_MAP_TYPE_HASH_OF_MAPS
    )
}
fn kernel_mutable_writer_reason(ctx: &PassContext) -> String {
    let Some(map_id) = ctx
        .map_ids
        .first()
        .copied()
        .or_else(|| ctx.map_metadata.keys().next().copied())
    else {
        return "map kernel-mutable: bytecode contains BPF_FUNC_map_update_elem/delete_elem/push_elem/pop_elem on unknown map".to_string();
    };
    format!("map kernel-mutable: bytecode contains BPF_FUNC_map_update_elem/delete_elem/push_elem/pop_elem on map_id={map_id}")
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
    prog: &BBProgram,
    ctx: &PassContext,
    map_info: &MapInfoResult,
    kernel_mutable_maps: &KernelMutableMaps,
    boundary_hints: &[BoundaryResolvedInlineHint],
) -> anyhow::Result<ResolvedInlineHints> {
    if boundary_hints.is_empty() {
        return Ok(ResolvedInlineHints::default());
    }
    let sites = find_map_lookup_sites(prog)?;
    let mut resolved = ResolvedInlineHints::default();
    let mut deferred_inner_hints = Vec::new();
    for hint in boundary_hints {
        let resolved_direct = match &hint.anchor {
            ResolvedHintAnchor::CallSite(call_site) => resolve_site_inline_hint(
                prog,
                ctx,
                map_info,
                kernel_mutable_maps,
                hint,
                *call_site,
                &mut resolved,
            )?,
            ResolvedHintAnchor::MapName(name) => resolve_map_name_inline_hint(
                ctx,
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
        prog,
        ctx,
        map_info,
        kernel_mutable_maps,
        &sites,
        &deferred_inner_hints,
        &mut resolved,
    )?;
    validate_resolved_site_hint_modes(&resolved)?;
    Ok(resolved)
}
fn resolve_inline_hint_anchors(
    prog: &BBProgram,
    ctx: &PassContext,
) -> anyhow::Result<Vec<BoundaryResolvedInlineHint>> {
    ctx.map_inline_hints
        .iter()
        .map(|hint| {
            let anchor = match &hint.anchor {
                MapInlineHintAnchor::Pc(call_pc) => {
                    let site = lookup_call_site_at_pc(prog, *call_pc)?.ok_or_else(|| {
                        anyhow::anyhow!("inline hint at pc {call_pc} points at a non-lookup call")
                    })?;
                    let insn = prog.insn(site)?;
                    if !is_map_lookup_elem_call(insn) {
                        bail!("inline hint at pc {call_pc} points at a non-lookup call");
                    }
                    ResolvedHintAnchor::CallSite(site)
                }
                MapInlineHintAnchor::MapName(name) => ResolvedHintAnchor::MapName(name.clone()),
            };
            Ok(BoundaryResolvedInlineHint {
                anchor,
                original_anchor: hint.anchor.clone(),
                mode: hint.mode,
                key: hint.key.clone(),
            })
        })
        .collect()
}
fn resolve_map_in_map_route_a_hints(
    prog: &BBProgram,
    ctx: &PassContext,
    map_info: &MapInfoResult,
    kernel_mutable_maps: &KernelMutableMaps,
    sites: &[MapLookupSite],
    deferred_inner_hints: &[BoundaryResolvedInlineHint],
    resolved: &mut ResolvedInlineHints,
) -> anyhow::Result<()> {
    if deferred_inner_hints.is_empty() {
        return Ok(());
    }
    let routes = resolve_hinted_map_in_map_routes(prog, ctx, map_info, sites, resolved)?;
    if routes.is_empty() {
        let has_map_in_map_outer_hint =
            has_resolved_map_in_map_outer_hint(map_info, sites, resolved)?;
        let has_known_inner_hint = deferred_inner_hints.iter().try_fold(false, |found, hint| {
            deferred_hint_targets_known_map_in_map_inner(prog, ctx, sites, hint)
                .map(|matches| found || matches)
        })?;
        if has_map_in_map_outer_hint || has_known_inner_hint {
            bail!(
                "inner inline hint anchor {} has no matching map-in-map outer hint",
                format_hint_anchor(&deferred_inner_hints[0].original_anchor)
            );
        }
        return Ok(());
    }
    let mut matched = vec![false; deferred_inner_hints.len()];
    for route in &routes {
        for (idx, hint) in deferred_inner_hints.iter().enumerate() {
            if !inner_hint_matches_route(ctx, hint, route)? {
                continue;
            }
            validate_and_insert_site_hint(
                ctx,
                kernel_mutable_maps,
                hint,
                route.inner_call_site,
                &route.inner_info,
                resolved,
            )?;
            matched[idx] = true;
        }
    }
    for (idx, hint) in deferred_inner_hints.iter().enumerate() {
        if !matched[idx] && deferred_hint_targets_known_map_in_map_inner(prog, ctx, sites, hint)? {
            bail!(
                "inner inline hint anchor {} has no matching map-in-map outer hint",
                format_hint_anchor(&hint.original_anchor)
            );
        }
    }
    Ok(())
}
fn resolve_hinted_map_in_map_routes(
    prog: &BBProgram,
    ctx: &PassContext,
    map_info: &MapInfoResult,
    sites: &[MapLookupSite],
    resolved: &ResolvedInlineHints,
) -> anyhow::Result<Vec<HintedMapInMapRoute>> {
    let mut routes = Vec::new();
    for outer_site in sites {
        let outer_info = lookup_site_map_info(map_info, outer_site)?;
        if !outer_info.is_map_in_map() {
            continue;
        }
        let Some(outer_hints) = resolved.for_call_site(outer_site.call_site) else {
            continue;
        };
        for outer_hint in outer_hints {
            let encoded_outer_key = encode_key_bytes(&outer_hint.key, outer_info.key_size as usize);
            let inner_map_id =
                resolve_inner_map_id_for_outer_key(ctx, outer_info, &encoded_outer_key)
                    .map_err(|err| map_route_a_error(outer_hint, outer_info, err))?;
            let inner_info = snapshot_map_info(ctx, inner_map_id)
                .map_err(anyhow::Error::msg)?
                .ok_or_else(|| {
                    anyhow::anyhow!(
                        "map_values snapshot has no metadata for inner map {} from outer map {} key {}",
                        inner_map_id,
                        outer_info.map_id,
                        format_bytes_preview(&encoded_outer_key)
                    )
                })?;
            let Some(chain) = find_map_in_map_chains(prog, std::slice::from_ref(outer_site))?
                .into_iter()
                .next()
            else {
                continue;
            };
            routes.push(HintedMapInMapRoute {
                inner_call_site: chain.inner_call_site,
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
        if resolved.for_call_site(site.call_site).is_none() {
            continue;
        }
        if lookup_site_map_info(map_info, site)?.is_map_in_map() {
            return Ok(true);
        }
    }
    Ok(false)
}
fn deferred_hint_targets_known_map_in_map_inner(
    prog: &BBProgram,
    ctx: &PassContext,
    sites: &[MapLookupSite],
    hint: &BoundaryResolvedInlineHint,
) -> anyhow::Result<bool> {
    match &hint.anchor {
        ResolvedHintAnchor::CallSite(call_site) => Ok(find_map_in_map_chains(prog, sites)?
            .iter()
            .any(|chain| chain.inner_call_site == *call_site)),
        ResolvedHintAnchor::MapName(name) => {
            let map_ids = metadata_map_ids_for_name(ctx, name)?;
            Ok(map_ids
                .iter()
                .any(|map_id| map_id_is_known_inner_map(ctx, *map_id)))
        }
    }
}
fn map_id_is_known_inner_map(ctx: &PassContext, map_id: u32) -> bool {
    ctx.map_inner_map_ids
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
    ctx: &PassContext,
    hint: &BoundaryResolvedInlineHint,
    route: &HintedMapInMapRoute,
) -> anyhow::Result<bool> {
    match &hint.anchor {
        ResolvedHintAnchor::CallSite(call_site) => Ok(*call_site == route.inner_call_site),
        ResolvedHintAnchor::MapName(name) => {
            let map_ids = metadata_map_ids_for_name(ctx, name)?;
            Ok(map_ids.contains(&route.inner_info.map_id))
        }
    }
}
fn metadata_map_ids_for_name(ctx: &PassContext, name: &str) -> anyhow::Result<HashSet<u32>> {
    let matched = ctx
        .map_metadata
        .values()
        .filter(|metadata| metadata.name == name)
        .map(|metadata| metadata.map_id)
        .collect::<HashSet<_>>();
    if matched.is_empty() {
        if !ctx.map_inner_map_ids.is_empty() {
            bail!("inner inline hint anchor map_name:{name} has no matching map-in-map outer hint");
        }
        bail!("inline hint map_name anchor {name:?} is not present in map_values metadata");
    }
    Ok(matched)
}
fn resolve_site_inline_hint(
    prog: &BBProgram,
    ctx: &PassContext,
    map_info: &MapInfoResult,
    kernel_mutable_maps: &KernelMutableMaps,
    hint: &BoundaryResolvedInlineHint,
    call_site: InsnSite,
    resolved: &mut ResolvedInlineHints,
) -> anyhow::Result<bool> {
    let sites = find_map_lookup_sites(prog)?;
    let Some(site) = sites.iter().find(|site| site.call_site == call_site) else {
        return Ok(false);
    };
    let info = lookup_site_map_info(map_info, site)?;
    validate_and_insert_site_hint(
        ctx,
        kernel_mutable_maps,
        hint,
        site.call_site,
        info,
        resolved,
    )?;
    Ok(true)
}
fn resolve_map_name_inline_hint(
    ctx: &PassContext,
    map_info: &MapInfoResult,
    kernel_mutable_maps: &KernelMutableMaps,
    sites: &[MapLookupSite],
    hint: &BoundaryResolvedInlineHint,
    name: &str,
    resolved: &mut ResolvedInlineHints,
) -> anyhow::Result<bool> {
    let map_ids = direct_map_ids_for_name(ctx, map_info, name)?;
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
            ctx,
            kernel_mutable_maps,
            hint,
            site.call_site,
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
    let map_ref = map_info
        .reference_at_site(site.map_load_site)
        .ok_or_else(|| {
            anyhow::anyhow!(
                "map reference metadata unavailable for lookup site {:?}",
                site.call_site
            )
        })?;
    map_ref
        .info
        .as_ref()
        .ok_or_else(|| anyhow::anyhow!("map info unavailable for lookup site {:?}", site.call_site))
}
fn direct_map_ids_for_name(
    ctx: &PassContext,
    map_info: &MapInfoResult,
    name: &str,
) -> anyhow::Result<HashSet<u32>> {
    let mut matched = HashSet::new();
    for info in &map_info.unique_maps {
        let metadata = ctx.map_metadata.get(&info.map_id).ok_or_else(|| {
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
    ctx: &PassContext,
    kernel_mutable_maps: &KernelMutableMaps,
    hint: &BoundaryResolvedInlineHint,
    call_site: InsnSite,
    info: &MapInfo,
    resolved: &mut ResolvedInlineHints,
) -> anyhow::Result<()> {
    if let Some(reason) = kernel_mutable_reason_for_map(kernel_mutable_maps, info) {
        bail!(
            "inline hint anchor {} targets kernel-mutable map_id={}: {}",
            format_hint_anchor(&hint.original_anchor),
            info.map_id,
            reason
        );
    }
    if hint.key.len() != info.key_size as usize {
        bail!(
            "inline hint anchor {} has wrong key size: {} byte(s) for map_id={}, expected {}",
            format_hint_anchor(&hint.original_anchor),
            hint.key.len(),
            info.map_id,
            info.key_size
        );
    }
    if info.is_map_in_map() {
        if hint.mode != MapInlineHintMode::Hard {
            bail!(
                "map-in-map outer inline hint anchor {} must use hard fold",
                format_hint_anchor(&hint.original_anchor)
            );
        }
        resolved
            .by_call_site
            .entry(call_site)
            .or_default()
            .push(ResolvedInlineHint {
                anchor: hint.original_anchor.clone(),
                mode: hint.mode,
                key: hint.key.clone(),
                inline_value: ResolvedInlineValue::Value(Vec::new()),
            });
        return Ok(());
    }
    let inline_value =
        read_hint_inline_value(ctx, info, hint.mode, &hint.key).with_context(|| {
            format!(
                "inline hint anchor {} key {} for map_id={}",
                format_hint_anchor(&hint.original_anchor),
                format_bytes_preview(&hint.key),
                info.map_id
            )
        })?;
    resolved
        .by_call_site
        .entry(call_site)
        .or_default()
        .push(ResolvedInlineHint {
            anchor: hint.original_anchor.clone(),
            mode: hint.mode,
            key: hint.key.clone(),
            inline_value,
        });
    Ok(())
}
fn read_hint_inline_value(
    ctx: &PassContext,
    info: &MapInfo,
    mode: MapInlineHintMode,
    key: &[u8],
) -> anyhow::Result<ResolvedInlineValue> {
    let value_size = lookup_value_size(ctx, info).map_err(anyhow::Error::msg)?;
    let value = match lookup_elem(ctx, info.map_id, key, value_size) {
        Ok(value) => value,
        Err(MapLookupError::MissingKey { .. })
            if mode == MapInlineHintMode::Hard
                && enumerated_overlay_missing_key(ctx, info.map_id, key) =>
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
fn enumerated_overlay_missing_key(ctx: &PassContext, map_id: u32, key: &[u8]) -> bool {
    matches!(
        ctx.map_value_overlays.get(&map_id).map(|overlay| &overlay.kind),
        Some(CompressedMapValuesKind::Enumerated { entries }) if !entries.contains_key(key)
    )
}
fn validate_resolved_site_hint_modes(resolved: &ResolvedInlineHints) -> anyhow::Result<()> {
    for (call_site, hints) in &resolved.by_call_site {
        let hard_count = hints
            .iter()
            .filter(|hint| hint.mode == MapInlineHintMode::Hard)
            .count();
        let soft_count = hints
            .iter()
            .filter(|hint| hint.mode == MapInlineHintMode::Soft)
            .count();
        if hard_count > 1 {
            bail!("lookup site {:?} has multiple hard inline hints", call_site);
        }
        if hard_count > 0 && soft_count > 0 {
            bail!(
                "lookup site {:?} mixes soft and hard inline hints",
                call_site
            );
        }
    }
    Ok(())
}
impl BpfPass for MapInlinePass {
    fn name(&self) -> &str {
        "map_inline"
    }
    fn run(&self, program: &mut BBProgram, ctx: &PassContext) -> anyhow::Result<PassResult> {
        run_on_bbprogram(program, ctx)
    }
}
pub fn run_on_bbprogram(prog: &mut BBProgram, ctx: &PassContext) -> anyhow::Result<PassResult> {
    let initial_map_info = analyze_map_info(prog, ctx).map_err(anyhow::Error::msg)?;
    let initial_kernel_mutable_maps = collect_kernel_mutable_maps(prog, ctx, &initial_map_info)?;
    if prog
        .all_sites()
        .any(|site| prog.insn_at(site).is_some_and(is_map_writer_helper_call))
        && !ctx.map_inline_hints.is_empty()
        && !ctx.map_inner_map_ids.is_empty()
        && ctx
            .map_metadata
            .values()
            .any(|metadata| map_type_is_map_in_map(metadata.map_type))
    {
        anyhow::bail!("kernel-mutable inner map");
    }
    let boundary_inline_hints = resolve_inline_hint_anchors(prog, ctx)?;
    let initial_inline_hints = resolve_inline_hints(
        prog,
        ctx,
        &initial_map_info,
        &initial_kernel_mutable_maps,
        &boundary_inline_hints,
    )?;
    let mut total_applied = 0usize;
    let mut final_skipped = Vec::new();
    let mut diagnostics = Vec::new();
    let mut site_diagnostics = Vec::new();
    let mut map_inline_records = Vec::new();
    let mut hit_iteration_cap = false;
    let mut inline_hints_consumed = HashSet::<MapInlineHintAnchor>::new();
    for iter in 0..MAP_INLINE_FIXED_POINT_MAX_ITERS {
        let empty_hints = ResolvedInlineHints::default();
        let round_inline_hints = if iter == 0 {
            &initial_inline_hints
        } else {
            &empty_hints
        };
        let round = run_map_inline_round(
            prog,
            ctx,
            iter == 0,
            round_inline_hints,
            &mut inline_hints_consumed,
        )?;
        let round_modified = round.sites_applied > 0;
        final_skipped = round.site_skipped;
        total_applied += round.sites_applied;
        map_inline_records.extend(round.map_inline_records);
        if iter == 0 {
            diagnostics.extend(round.diagnostics);
            site_diagnostics.extend(round.site_diagnostics);
        } else {
            diagnostics.extend(
                round
                    .diagnostics
                    .into_iter()
                    .map(|diag| format!("round {}: {}", iter + 1, diag)),
            );
            site_diagnostics.extend(round.site_diagnostics.into_iter().map(|diag| {
                SiteDiagnostic {
                    site: diag.site,
                    message: format!("round {}: {}", iter + 1, diag.message),
                }
            }));
        }
        if !round_modified {
            break;
        }
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
    if !ctx.map_inline_hints.is_empty() {
        if ctx.map_inline_hints.iter().any(|hint| {
            hint.mode == MapInlineHintMode::Soft && !inline_hints_consumed.contains(&hint.anchor)
        }) {
            record_diagnostic(&mut diagnostics, "missing immediate null check".to_string());
        }
        record_diagnostic(
            &mut diagnostics,
            format!("inline_hints_consumed={}", inline_hints_consumed.len()),
        );
    }
    Ok(PassResult {
        sites_applied: total_applied,
        site_skipped: final_skipped,
        diagnostics,
        site_diagnostics,
        map_inline_records,
        ..Default::default()
    })
}
fn run_map_inline_round(
    prog: &mut BBProgram,
    ctx: &PassContext,
    use_verifier_guided_keys: bool,
    inline_hints: &ResolvedInlineHints,
    inline_hints_consumed: &mut HashSet<MapInlineHintAnchor>,
) -> anyhow::Result<PassResult> {
    let old_len = prog.all_sites().count();
    let branch_target_sites = prog.branch_target_entry_sites()?;
    let map_info = analyze_map_info(prog, ctx).map_err(anyhow::Error::msg)?;
    let kernel_mutable_maps = collect_kernel_mutable_maps(prog, ctx, &map_info)?;
    let mut skipped = Vec::new();
    let mut rewrites = Vec::new();
    let mut diagnostics = Vec::new();
    let mut site_diagnostics = Vec::new();
    if use_verifier_guided_keys {
        record_maps_skipped_by_size_counter(ctx, &mut diagnostics);
    }
    let DirectMapValueLoadRewriteResult {
        replacements: direct_replacements,
        sites_applied: direct_sites_applied,
        site_diagnostics: direct_site_diagnostics,
        records: direct_records,
    } = build_direct_map_value_load_rewrites(prog, ctx, &kernel_mutable_maps)?;
    site_diagnostics.extend(direct_site_diagnostics);
    let sites = find_map_lookup_sites(prog)?;
    let has_writer = prog
        .all_sites()
        .any(|site| prog.insn_at(site).is_some_and(is_map_writer_helper_call));
    if sites.is_empty() && has_writer {
        for site in lookup_call_sites(prog)? {
            record_skip(
                &mut skipped,
                &mut site_diagnostics,
                site,
                kernel_mutable_writer_reason(ctx),
                None,
            );
        }
    }
    log_map_inline_debug(&format!(
        "found {} lookup sites (verifier_guided_keys={})",
        sites.len(),
        use_verifier_guided_keys
    ));
    for site in sites {
        log_map_inline_debug(&format!(
            "evaluating lookup {:?} (map_load_site {:?})",
            site.call_site, site.map_load_site
        ));
        let Some(map_ref) = map_info.reference_at_site(site.map_load_site) else {
            log_map_inline_debug(&format!(
                "lookup {:?} skip: map reference unavailable",
                site.call_site
            ));
            let reason = "map reference metadata unavailable".to_string();
            record_skip(
                &mut skipped,
                &mut site_diagnostics,
                site.call_site,
                reason,
                None,
            );
            continue;
        };
        log_map_inline_debug(&format!(
            "lookup {:?}: map_ref imm={} map_ordinal={} map_id={:?}",
            site.call_site, map_ref.imm, map_ref.map_ordinal, map_ref.map_id
        ));
        let Some(info) = map_ref.info.as_ref() else {
            let reason = "map info unavailable".to_string();
            record_skip(
                &mut skipped,
                &mut site_diagnostics,
                site.call_site,
                reason,
                None,
            );
            continue;
        };
        log_map_inline_debug(&format!(
            "lookup {:?}: resolved map_id={} map_type={} key_size={} value_size={} max_entries={}",
            site.call_site,
            info.map_id,
            info.map_type,
            info.key_size,
            info.value_size,
            info.max_entries,
        ));
        if let Some(reason) = kernel_mutable_reason_for_map(&kernel_mutable_maps, info) {
            record_skip(
                &mut skipped,
                &mut site_diagnostics,
                site.call_site,
                reason,
                None,
            );
            continue;
        }
        if map_snapshot_skipped_by_size(ctx, info.map_id) {
            log_map_inline_debug(&format!(
                "lookup {:?} skip: map {} snapshot skipped by size",
                site.call_site, info.map_id
            ));
            if !ctx.map_value_overlays.contains_key(&info.map_id) {
                return Err(anyhow::anyhow!("snapshot skipped map {}", info.map_id));
            }
            let reason = map_snapshot_skipped_by_size_site_reason(ctx, info.map_id);
            record_skip(
                &mut skipped,
                &mut site_diagnostics,
                site.call_site,
                reason,
                None,
            );
            continue;
        }
        let site_inline_hints = inline_hints.for_call_site(site.call_site);
        if info.is_map_in_map() {
            let mut map_in_map_state = MapInMapRewriteState {
                ctx,
                use_verifier_guided_keys,
                inline_hints,
                kernel_mutable_maps: &kernel_mutable_maps,
                inline_hints_consumed,
            };
            match build_map_in_map_chain_rewrite(prog, &site, info, &mut map_in_map_state) {
                Ok(Some(mut rewrite)) => {
                    if rewrite
                        .skipped_sites
                        .iter()
                        .any(|site| branch_target_sites.contains(site))
                    {
                        record_site_diagnostic(
                            &mut site_diagnostics,
                            site.call_site,
                            "keeping map-in-map lookup chain because removal would cross a branch target".to_string(),
                        );
                        rewrite.skipped_sites.clear();
                        rewrite.removed_null_check = false;
                    }
                    if rewrite
                        .replacements
                        .iter()
                        .any(|replacement| rewrite.skipped_sites.contains(&replacement.site))
                    {
                        let reason = "internal rewrite overlap".to_string();
                        record_skip(
                            &mut skipped,
                            &mut site_diagnostics,
                            site.call_site,
                            reason,
                            None,
                        );
                        continue;
                    }
                    log_map_inline_debug(&format!(
                        "lookup {:?}: map-in-map rewrite prepared with {} replacement load(s), removed_null_check={}",
                        site.call_site,
                        rewrite.replacements.len(),
                        rewrite.removed_null_check
                    ));
                    rewrites.push(rewrite);
                }
                Ok(None) => {
                    if site_inline_hints.is_some() {
                        if ctx
                            .map_inner_map_ids
                            .keys()
                            .any(|(outer_map_id, _)| *outer_map_id == info.map_id)
                            && has_writer
                        {
                            anyhow::bail!("kernel-mutable inner map");
                        }
                        anyhow::bail!(
                            "map-in-map outer map_id={} has no live inner map",
                            info.map_id
                        );
                    }
                    let reason = "map-in-map chain is not inlineable".to_string();
                    record_skip(
                        &mut skipped,
                        &mut site_diagnostics,
                        site.call_site,
                        reason,
                        None,
                    );
                }
                Err(err) => match err {
                    SiteRewriteError::Veto(reason) => {
                        record_skip(
                            &mut skipped,
                            &mut site_diagnostics,
                            site.call_site,
                            reason,
                            None,
                        );
                        continue;
                    }
                    SiteRewriteError::MissingSnapshot(err) => {
                        return Err(err.context(format!(
                            "map_inline requires a concrete map-in-map snapshot at outer lookup {:?}",
                            site.call_site
                        )));
                    }
                    SiteRewriteError::Error(err) => return Err(err),
                },
            }
            continue;
        }
        if hard_null_hint(site_inline_hints).is_some() {
            let extracted_key = match extract_site_constant_key(
                prog,
                site.call_site,
                info,
                use_verifier_guided_keys,
                site_inline_hints,
            ) {
                Ok(extracted_key) => extracted_key,
                Err(KeyExtractionError::Unavailable(detail)) => {
                    record_skip(
                        &mut skipped,
                        &mut site_diagnostics,
                        site.call_site,
                        "lookup key is not available from inline hint".into(),
                        Some(detail),
                    );
                    continue;
                }
                Err(KeyExtractionError::Error(err)) => return Err(err),
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
                record_skip(
                    &mut skipped,
                    &mut site_diagnostics,
                    site.call_site,
                    reason,
                    None,
                );
                continue;
            }
            let mut rewrite = match build_hard_null_site_rewrite(prog, &site, &key, info) {
                Ok(rewrite) => rewrite,
                Err(SiteRewriteError::Veto(reason)) => {
                    record_skip(
                        &mut skipped,
                        &mut site_diagnostics,
                        site.call_site,
                        reason,
                        None,
                    );
                    continue;
                }
                Err(SiteRewriteError::MissingSnapshot(err) | SiteRewriteError::Error(err)) => {
                    return Err(err);
                }
            };
            if rewrite
                .skipped_sites
                .iter()
                .any(|site| branch_target_sites.contains(site))
            {
                record_site_diagnostic(
                    &mut site_diagnostics,
                    site.call_site,
                    "keeping lookup setup because removal would cross a branch target".to_string(),
                );
                rewrite.skipped_sites.clear();
            }
            rewrites.push(rewrite);
            continue;
        }
        if !info.supports_direct_value_access() {
            log_map_inline_debug(&format!(
                "lookup {:?} skip: map type {} not inlineable",
                site.call_site, info.map_type
            ));
            let reason = format!("map type {} not inlineable", info.map_type);
            record_skip(
                &mut skipped,
                &mut site_diagnostics,
                site.call_site,
                reason,
                Some(format!(
                    "map_type={}, skip reason: unsupported map type",
                    info.map_type
                )),
            );
            continue;
        }
        let has_soft_hint = match site_inline_hints {
            Some(hints) => hints
                .iter()
                .any(|hint| hint.mode == MapInlineHintMode::Soft),
            None => false,
        };
        if has_soft_hint {
            let Some(site_inline_hints) = site_inline_hints else {
                anyhow::bail!(
                    "soft inline hint disappeared for map lookup {:?}",
                    site.call_site
                );
            };
            match build_soft_hint_site_rewrite(prog, &site, info, site_inline_hints) {
                Ok(Some(rewrite)) => {
                    for hint in site_inline_hints {
                        inline_hints_consumed.insert(hint.anchor.clone());
                    }
                    if rewrite
                        .skipped_sites
                        .iter()
                        .any(|site| branch_target_sites.contains(site))
                    {
                        let reason = "soft fold removal would cross a branch target".to_string();
                        record_skip(
                            &mut skipped,
                            &mut site_diagnostics,
                            site.call_site,
                            reason,
                            None,
                        );
                        continue;
                    }
                    if rewrite
                        .replacements
                        .iter()
                        .any(|replacement| rewrite.skipped_sites.contains(&replacement.site))
                    {
                        let reason = "internal rewrite overlap".to_string();
                        record_skip(
                            &mut skipped,
                            &mut site_diagnostics,
                            site.call_site,
                            reason,
                            None,
                        );
                        continue;
                    }
                    rewrites.push(rewrite);
                }
                Ok(None) => {
                    let reason = "soft inline hint emitted no replacement bytecode".to_string();
                    record_skip(
                        &mut skipped,
                        &mut site_diagnostics,
                        site.call_site,
                        reason,
                        None,
                    );
                }
                Err(SiteRewriteError::Veto(reason)) => {
                    record_skip(
                        &mut skipped,
                        &mut site_diagnostics,
                        site.call_site,
                        reason,
                        None,
                    );
                }
                Err(SiteRewriteError::MissingSnapshot(err) | SiteRewriteError::Error(err)) => {
                    return Err(err);
                }
            }
            continue;
        }
        let extracted_key = match extract_site_constant_key(
            prog,
            site.call_site,
            info,
            use_verifier_guided_keys,
            site_inline_hints,
        ) {
            Ok(extracted_key) => extracted_key,
            Err(KeyExtractionError::Unavailable(detail)) => {
                record_skip(
                    &mut skipped,
                    &mut site_diagnostics,
                    site.call_site,
                    "lookup key is not available from verifier-guided state".into(),
                    Some(detail),
                );
                continue;
            }
            Err(KeyExtractionError::Error(err)) => return Err(err),
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
            record_skip(
                &mut skipped,
                &mut site_diagnostics,
                site.call_site,
                reason,
                None,
            );
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
            record_skip(
                &mut skipped,
                &mut site_diagnostics,
                site.call_site,
                reason,
                None,
            );
            continue;
        }
        let uses = classify_r0_uses_with_options(
            prog,
            site.call_site,
            info.has_removable_lookup_pattern(),
            info.has_removable_lookup_pattern(),
        )?;
        let null_check_site = uses.null_check_site;
        if info.requires_entry_presence_check() && null_check_site.is_none() {
            let reason = "hash map inline requires an immediate null check".to_string();
            record_skip(
                &mut skipped,
                &mut site_diagnostics,
                site.call_site,
                reason,
                None,
            );
            continue;
        }
        log_map_inline_debug(&format!(
            "lookup {:?}: null_check_site={:?} alias_copies={} fixed_loads={} other_uses={}",
            site.call_site,
            null_check_site,
            uses.alias_copy_sites.len(),
            uses.fixed_loads.len(),
            uses.other_use_sites.len()
        ));
        if uses.fixed_loads.is_empty() {
            let reason = "lookup result is not consumed by fixed-offset scalar loads".to_string();
            record_skip(
                &mut skipped,
                &mut site_diagnostics,
                site.call_site,
                reason,
                None,
            );
            continue;
        }
        let mut rewrite = match build_site_rewrite(
            prog,
            ctx,
            &site,
            &key,
            &uses,
            info,
            null_check_site,
        ) {
            Ok(Some(rewrite)) => rewrite,
            Ok(None) => {
                let reason = "failed to materialize replacement constants".to_string();
                record_skip(
                    &mut skipped,
                    &mut site_diagnostics,
                    site.call_site,
                    reason,
                    None,
                );
                continue;
            }
            Err(err) => match err {
                SiteRewriteError::Veto(reason) => {
                    record_skip(
                        &mut skipped,
                        &mut site_diagnostics,
                        site.call_site,
                        reason,
                        None,
                    );
                    continue;
                }
                SiteRewriteError::MissingSnapshot(err) => {
                    let detail = err.to_string();
                    return Err(err.context(format!(
                        "map_inline requires a concrete snapshot value for map {} key {} at lookup {:?}: {}",
                        info.map_id,
                        format_bytes_preview(&key.bytes),
                        site.call_site,
                        detail
                    )));
                }
                SiteRewriteError::Error(err) => return Err(err),
            },
        };
        if rewrite
            .skipped_sites
            .iter()
            .any(|site| branch_target_sites.contains(site))
        {
            record_site_diagnostic(
                &mut site_diagnostics,
                site.call_site,
                "keeping lookup pattern because removal would cross a branch target".to_string(),
            );
            rewrite.skipped_sites.clear();
            rewrite.removed_null_check = false;
        }
        if rewrite
            .replacements
            .iter()
            .any(|replacement| rewrite.skipped_sites.contains(&replacement.site))
        {
            let reason = "internal rewrite overlap".to_string();
            record_skip(
                &mut skipped,
                &mut site_diagnostics,
                site.call_site,
                reason,
                None,
            );
            continue;
        }
        log_map_inline_debug(&format!(
            "lookup {:?}: rewrite prepared with {} replacement load(s), removed_null_check={}",
            site.call_site,
            rewrite.replacements.len(),
            rewrite.removed_null_check
        ));
        rewrites.push(rewrite);
    }
    if rewrites.is_empty() && direct_replacements.is_empty() {
        log_map_inline_debug("no map_inline rewrites prepared");
        return Ok(PassResult {
            site_skipped: skipped,
            diagnostics,
            site_diagnostics,
            ..PassResult::unchanged()
        });
    }
    let mut skip_sites = BTreeSet::new();
    let mut replacements = direct_replacements;
    let mut replacement_sites = replacements
        .iter()
        .map(|replacement| replacement.site)
        .collect::<BTreeSet<_>>();
    let mut map_inline_records = direct_records;
    let mut applied = direct_sites_applied;
    let mut removed_any_null_check = false;
    for rewrite in rewrites {
        let conflict = rewrite
            .skipped_sites
            .iter()
            .any(|site| replacement_sites.contains(site) || skip_sites.contains(site))
            || rewrite.replacements.iter().any(|replacement| {
                replacement_sites.contains(&replacement.site)
                    || skip_sites.contains(&replacement.site)
            });
        if conflict {
            let reason = "overlapping map inline rewrite".to_string();
            record_skip(
                &mut skipped,
                &mut site_diagnostics,
                rewrite.call_site,
                reason,
                None,
            );
            continue;
        }
        removed_any_null_check |= rewrite.removed_null_check;
        record_site_diagnostic(
            &mut site_diagnostics,
            rewrite.call_site,
            format!("inlined successfully, value={}", rewrite.diagnostic_value),
        );
        map_inline_records.extend(rewrite.map_inline_records);
        skip_sites.extend(rewrite.skipped_sites);
        replacement_sites.extend(
            rewrite
                .replacements
                .iter()
                .map(|replacement| replacement.site),
        );
        replacements.extend(rewrite.replacements);
        applied += 1;
    }
    if applied == 0 {
        log_map_inline_debug("all prepared rewrites were discarded");
        return Ok(PassResult {
            site_skipped: skipped,
            diagnostics,
            site_diagnostics,
            map_inline_records,
            ..PassResult::unchanged()
        });
    }
    log_map_inline_debug(&format!(
        "applied {} map_inline rewrite(s), skipped {} site(s)",
        applied,
        skipped.len()
    ));
    let mut result = apply_map_inline_edit(
        prog,
        old_len,
        replacements,
        skip_sites,
        removed_any_null_check,
        applied,
    )?;
    result.site_skipped = skipped;
    result.diagnostics = diagnostics;
    result.site_diagnostics = site_diagnostics;
    result.map_inline_records = map_inline_records;
    Ok(result)
}
fn apply_map_inline_edit(
    prog: &mut BBProgram,
    old_len: usize,
    replacements: Vec<SiteReplacement>,
    skip_sites: BTreeSet<InsnSite>,
    cleanup_unreachable: bool,
    sites_applied: usize,
) -> anyhow::Result<PassResult> {
    let mut next = prog.clone();
    apply_replacements_and_deletions(&mut next, replacements, skip_sites)?;
    if cleanup_unreachable {
        cleanup_map_inline_bbprogram(&mut next)?;
    }
    reset_btf_to_current_pcs(&mut next)?;
    let new_len = next.all_sites().count();
    *prog = next;
    Ok(PassResult {
        sites_applied,
        insns_before: old_len,
        insns_after: new_len,
        ..Default::default()
    })
}
fn apply_replacements_and_deletions(
    prog: &mut BBProgram,
    replacements: Vec<SiteReplacement>,
    skip_sites: BTreeSet<InsnSite>,
) -> anyhow::Result<()> {
    let mut replacement_by_site = BTreeMap::new();
    for replacement in replacements {
        if skip_sites.contains(&replacement.site) {
            anyhow::bail!(
                "map_inline replacement at {:?} overlaps deletion",
                replacement.site
            );
        }
        let site = replacement.site;
        if replacement_by_site.insert(site, replacement).is_some() {
            anyhow::bail!("map_inline has duplicate replacement for {:?}", site);
        }
    }
    let mut edit_sites = replacement_by_site.keys().copied().collect::<BTreeSet<_>>();
    edit_sites.extend(skip_sites.iter().copied());
    for site in edit_sites.into_iter().rev() {
        if let Some(replacement) = replacement_by_site.remove(&site) {
            replace_site(prog, replacement)?;
        } else {
            delete_site(prog, site)?;
        }
    }
    Ok(())
}
fn replace_site(prog: &mut BBProgram, replacement: SiteReplacement) -> anyhow::Result<()> {
    if replacement.replacement.is_empty() {
        anyhow::bail!("map_inline replacement at {:?} is empty", replacement.site);
    }
    if prog.is_terminator_site(replacement.site)? {
        let terminator =
            terminator_for_site_replacement(prog, replacement.site, &replacement.replacement)?;
        return prog.replace_terminator(replacement.site.block, terminator);
    }
    prog.replace_range_at(replacement.site, 1, replacement.replacement)
}
fn delete_site(prog: &mut BBProgram, site: InsnSite) -> anyhow::Result<()> {
    if prog.is_terminator_site(site)? {
        let terminator = match prog.terminator(site.block)? {
            Terminator::CondBranch { fallthrough, .. } => {
                Terminator::Fallthrough { next: fallthrough }
            }
            Terminator::Jump { target, .. } => Terminator::Fallthrough { next: target },
            Terminator::Fallthrough { next } => Terminator::Fallthrough { next },
            Terminator::Call { .. } | Terminator::Exit { .. } | Terminator::End => {
                anyhow::bail!("map_inline cannot delete terminator at {:?}", site)
            }
        };
        return prog.replace_terminator(site.block, terminator);
    }
    prog.replace_range_at(site, 1, Vec::new())
}
fn reset_btf_to_current_pcs(prog: &mut BBProgram) -> anyhow::Result<()> {
    prog.reset_btf_to_current_pcs()
}
fn terminator_for_site_replacement(
    prog: &BBProgram,
    site: InsnSite,
    replacement: &[BpfInsn],
) -> anyhow::Result<Terminator> {
    if replacement.len() != 1 {
        anyhow::bail!(
            "map_inline cannot replace terminator at {:?} with multiple insns",
            site
        );
    }
    let insn = replacement[0];
    let old = prog.terminator(site.block)?;
    if insn.is_ja() {
        let target = match old {
            Terminator::Jump { target, .. } => target,
            Terminator::CondBranch { taken, .. } => taken,
            Terminator::Fallthrough { next } => next,
            _ => anyhow::bail!("map_inline cannot infer JA target for {:?}", site),
        };
        return Ok(Terminator::Jump { insn, target });
    }
    if insn.is_cond_jmp() {
        let Terminator::CondBranch {
            taken, fallthrough, ..
        } = old
        else {
            anyhow::bail!("map_inline cannot infer conditional targets for {:?}", site);
        };
        return Ok(Terminator::CondBranch {
            cond: insn,
            taken,
            fallthrough,
        });
    }
    if insn.is_exit() {
        return Ok(Terminator::Exit { insn });
    }
    anyhow::bail!(
        "map_inline unsupported terminator replacement at {:?}",
        site
    )
}
fn cleanup_map_inline_bbprogram(prog: &mut BBProgram) -> anyhow::Result<()> {
    loop {
        let removed = prog.delete_unreachable_blocks()?;
        if removed == 0 {
            break;
        }
    }
    let ordered_blocks = prog.block_ids().collect::<Vec<_>>();
    let mut nops = Vec::new();
    for block in prog.blocks() {
        if let Terminator::Jump { insn, target } = prog.terminator(block.id)? {
            let linear_target = ordered_blocks
                .windows(2)
                .any(|window| window[0] == block.id && window[1] == target);
            if insn == BpfInsn::nop() || linear_target {
                nops.push((block.id, target));
            }
        }
    }
    for (block, target) in nops {
        prog.replace_terminator(block, Terminator::Fallthrough { next: target })?;
    }
    Ok(())
}
fn extract_site_constant_key(
    prog: &BBProgram,
    call_site: InsnSite,
    info: &MapInfo,
    use_verifier_guided_keys: bool,
    site_inline_hints: Option<&[ResolvedInlineHint]>,
) -> std::result::Result<ExtractedConstantKey, KeyExtractionError> {
    if let Some(hint) = site_inline_hints.and_then(|hints| {
        hints
            .iter()
            .find(|hint| hint.mode == MapInlineHintMode::Hard)
    }) {
        let r2_setup = find_r2_stack_pointer_setup_simple(prog, call_site)
            .map_err(KeyExtractionError::Error)?;
        let materialization = match r2_setup {
            Some((_, _, stack_off)) => materialization_for_snapshot_key(
                prog,
                call_site,
                stack_off,
                hint.key.len(),
                &hint.key,
            )
            .map_err(anyhow::Error::msg)
            .map_err(KeyExtractionError::Error)?,
            None => None,
        };
        let (store_site, source_imm_site, materialization_sites) = match materialization {
            Some(stack_bytes) => (
                stack_bytes.latest_store_site,
                stack_bytes.latest_source_imm_site,
                stack_bytes.materialization_sites,
            ),
            None => (call_site, None, BTreeSet::new()),
        };
        let key = ConstantKey {
            stack_off: r2_setup.map(|(_, _, off)| off),
            width: hint.key.len(),
            value: constant_key_value(&hint.key),
            bytes: hint.key.clone(),
            store_site,
            source_imm_site,
            materialization_sites,
            r2_mov_site: r2_setup.map(|(mov_site, _, _)| mov_site),
            r2_add_site: r2_setup.map(|(_, add_site, _)| add_site),
        };
        log_map_inline_debug(&format!(
            "lookup {:?}: inline-hint key={} width={} stack_off={:?} r2_mov_site={:?} r2_add_site={:?}",
            call_site,
            format_constant_key(&key),
            key.width,
            key.stack_off,
            key.r2_mov_site,
            key.r2_add_site
        ));
        return Ok(ExtractedConstantKey {
            key,
            used_inline_hint: Some(hint.anchor.clone()),
        });
    }
    if use_verifier_guided_keys {
        return match try_extract_constant_key_verifier_guided(prog, call_site, info.key_size) {
            Ok(key) => {
                log_map_inline_debug(&format!(
                    "lookup {:?}: verifier-guided key={} width={} stack_off={:?} store_site={:?} source_imm_site={:?} r2_mov_site={:?} r2_add_site={:?}",
                    call_site,
                    format_constant_key(&key),
                    key.width,
                    key.stack_off,
                    key.store_site,
                    key.source_imm_site,
                    key.r2_mov_site,
                    key.r2_add_site
                ));
                Ok(ExtractedConstantKey {
                    key,
                    used_inline_hint: None,
                })
            }
            Err(verifier_err) => {
                log_map_inline_debug(&format!(
                    "lookup {:?} skip: verifier-guided key extraction failed: {}",
                    call_site, verifier_err
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
    log_map_inline_debug(&format!("lookup {:?} skip: {}", call_site, detail));
    Err(KeyExtractionError::Unavailable(detail))
}
fn build_site_rewrite(
    prog: &BBProgram,
    ctx: &PassContext,
    site: &MapLookupSite,
    key: &ConstantKey,
    uses: &R0UseClassification,
    info: &MapInfo,
    null_check_site: Option<InsnSite>,
) -> SiteRewriteResult<Option<SiteRewrite>> {
    let remove_lookup_pattern =
        site_can_attempt_lookup_pattern_removal(prog, uses, info, null_check_site);
    let encoded_key = encode_key_bytes(&key.bytes, info.key_size as usize);
    let lookup_value_size = lookup_value_size(ctx, info).map_err(anyhow::Error::msg)?;
    log_map_inline_debug(&format!(
        "lookup {:?} reading map_id={} key={:?} lookup_value_size={}",
        site.call_site, info.map_id, encoded_key, lookup_value_size
    ));
    let value = match lookup_elem(ctx, info.map_id, &encoded_key, lookup_value_size) {
        Ok(value) => {
            log_map_inline_debug(&format!(
                "lookup {:?} INLINE value={:?}",
                site.call_site, value
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
                "lookup {:?}: map lookup(map_id={}, key={}) failed: {}",
                site.call_site,
                info.map_id,
                format_bytes_preview(&encoded_key),
                err
            ));
            return Err(missing_snapshot_error(err));
        }
    };
    let inline_value = prepare_inline_value(info, &value).map_err(site_level_inline_veto)?;
    let removable_null_check_site = null_check_site.filter(|site| {
        prog.insn_at(*site)
            .is_some_and(null_check_is_fallthrough_non_null)
    });
    let replacement_sites = uses
        .fixed_loads
        .iter()
        .map(|load| load.site)
        .collect::<BTreeSet<_>>();
    let mut lookup_pattern_sites = BTreeSet::new();
    if remove_lookup_pattern {
        lookup_pattern_sites.insert(site.call_site);
        lookup_pattern_sites.insert(site.map_load_site);
        lookup_pattern_sites.extend(key.materialization_sites.iter().copied());
        if let Some(r2_mov_site) = key.r2_mov_site {
            lookup_pattern_sites.insert(r2_mov_site);
        }
        if let Some(r2_add_site) = key.r2_add_site {
            lookup_pattern_sites.insert(r2_add_site);
        }
        if let Some(null_check_site) = removable_null_check_site {
            lookup_pattern_sites.insert(null_check_site);
        }
    }
    if remove_lookup_pattern {
        lookup_pattern_sites.extend(uses.alias_copy_sites.iter().copied());
    }
    let null_check_blocks_lookup_removal = if let Some(null_check_site) = removable_null_check_site
    {
        !null_check_removal_window_is_trivial(
            prog,
            uses,
            null_check_site,
            &lookup_pattern_sites,
            &replacement_sites,
        )?
    } else {
        null_check_site.is_some()
    };
    let can_remove_lookup_pattern = remove_lookup_pattern
        && uses.other_use_sites.is_empty()
        && !null_check_blocks_lookup_removal
        && lookup_pattern_removal_is_safe(prog, site.call_site, &lookup_pattern_sites)?;
    let skipped_sites = if can_remove_lookup_pattern {
        lookup_pattern_sites
    } else {
        BTreeSet::new()
    };
    let mut replacements = Vec::new();
    for load in &uses.fixed_loads {
        let scalar =
            read_scalar_from_value(&inline_value, load.offset, load.size).ok_or_else(|| {
                anyhow::anyhow!(
                    "map value read out of bounds for load {:?} (offset {}, size {})",
                    load.site,
                    load.offset,
                    load.size
                )
            })?;
        replacements.push(site_replacement(
            prog,
            load.site,
            emit_scalar_const_load(load.dst_reg, scalar, load.size != BPF_DW),
        )?);
    }
    if replacements.is_empty() {
        return Ok(None);
    }
    Ok(Some(SiteRewrite {
        call_site: site.call_site,
        diagnostic_value: format_inlined_value_diagnostic(&inline_value, &uses.fixed_loads),
        removed_null_check: can_remove_lookup_pattern && removable_null_check_site.is_some(),
        map_inline_records: vec![MapInlineRecord {
            map_id: info.map_id,
            key: encoded_key,
            value: inline_value,
        }],
        skipped_sites,
        replacements,
    }))
}
fn hard_null_hint(hints: Option<&[ResolvedInlineHint]>) -> Option<&ResolvedInlineHint> {
    hints?.iter().find(|hint| {
        hint.mode == MapInlineHintMode::Hard
            && matches!(hint.inline_value, ResolvedInlineValue::Null)
    })
}
fn build_hard_null_site_rewrite(
    prog: &BBProgram,
    site: &MapLookupSite,
    key: &ConstantKey,
    info: &MapInfo,
) -> SiteRewriteResult<SiteRewrite> {
    let encoded_key = encode_key_bytes(&key.bytes, info.key_size as usize);
    let mut skipped_sites = BTreeSet::new();
    skipped_sites.insert(site.map_load_site);
    skipped_sites.extend(key.materialization_sites.iter().copied());
    if let Some(r2_mov_site) = key.r2_mov_site {
        skipped_sites.insert(r2_mov_site);
    }
    if let Some(r2_add_site) = key.r2_add_site {
        skipped_sites.insert(r2_add_site);
    }
    let mut replacements = Vec::new();
    replacements.push(site_replacement(
        prog,
        site.call_site,
        vec![BpfInsn::mov64_imm(0, 0)],
    )?);
    let removed_null_check =
        if let Some(null_handler) = find_soft_fold_null_handler(prog, site.call_site)? {
            replacements.push(site_replacement(
                prog,
                null_handler.null_check_site,
                vec![BpfInsn::ja(0)],
            )?);
            true
        } else {
            false
        };
    Ok(SiteRewrite {
        call_site: site.call_site,
        diagnostic_value: format!(
            "NULL map_id={} key={}",
            info.map_id,
            format_bytes_preview(&encoded_key)
        ),
        removed_null_check,
        map_inline_records: Vec::new(),
        skipped_sites,
        replacements,
    })
}
fn build_soft_hint_site_rewrite(
    prog: &BBProgram,
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
    let null_handler = find_soft_fold_null_handler(prog, site.call_site)?
        .ok_or_else(|| site_level_inline_veto("soft fold not applicable: missing null handler"))?;
    let uses = classify_r0_uses_with_options(
        prog,
        site.call_site,
        info.has_removable_lookup_pattern(),
        info.has_removable_lookup_pattern(),
    )?;
    if uses.null_check_site != Some(null_handler.null_check_site) {
        return Err(site_level_inline_veto(
            "soft fold not applicable: nearest null check is not the lookup null handler",
        ));
    }
    if uses.fixed_loads.is_empty() {
        return Err(site_level_inline_veto(
            "soft fold not applicable: lookup result has no scalar load use",
        ));
    }
    if !uses.other_use_sites.is_empty() {
        return Err(site_level_inline_veto(
            "soft fold not applicable: lookup result has non-scalar use",
        ));
    }
    Err(site_level_inline_veto(
        "soft fold requires BBProgram CFG insertion",
    ))
}
#[derive(Clone, Copy, Debug)]
struct SoftNullHandler {
    null_check_site: InsnSite,
}
fn find_soft_fold_null_handler(
    prog: &BBProgram,
    call_site: InsnSite,
) -> SiteRewriteResult<Option<SoftNullHandler>> {
    let sites = sites_after_site_in_frame(prog, call_site)?;
    let Some(null_check_site) = sites.first().copied() else {
        return Ok(None);
    };
    if null_check_site.block != call_site.block {
        return Ok(None);
    }
    let insn = prog.insn(null_check_site)?;
    if !is_direct_r0_null_jeq(insn) {
        return Ok(None);
    }
    if non_null_successor_site(prog, null_check_site, insn)?.is_none() {
        return Ok(None);
    }
    Ok(Some(SoftNullHandler { null_check_site }))
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
fn resolve_inner_map_id_for_outer_key(
    ctx: &PassContext,
    outer_info: &MapInfo,
    encoded_outer_key: &[u8],
) -> SiteRewriteResult<u32> {
    if let Some(inner_map_id) = ctx
        .map_inner_map_ids
        .get(&(outer_info.map_id, encoded_outer_key.to_vec()))
        .copied()
    {
        return Ok(inner_map_id);
    }
    let value_size = lookup_value_size(ctx, outer_info).map_err(anyhow::Error::msg)?;
    let value = match lookup_elem(ctx, outer_info.map_id, encoded_outer_key, value_size) {
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
    let inner_map_id = u32::from_le_bytes([bytes[0], bytes[1], bytes[2], bytes[3]]);
    if inner_map_id == 0 {
        return Err(site_level_inline_veto(format!(
            "map-in-map outer map {} has no live inner map for key {}",
            outer_info.map_id,
            format_bytes_preview(encoded_outer_key)
        )));
    }
    Ok(inner_map_id)
}
struct MapInMapRewriteState<'a> {
    ctx: &'a PassContext,
    use_verifier_guided_keys: bool,
    inline_hints: &'a ResolvedInlineHints,
    kernel_mutable_maps: &'a KernelMutableMaps,
    inline_hints_consumed: &'a mut HashSet<MapInlineHintAnchor>,
}
fn build_map_in_map_chain_rewrite(
    prog: &BBProgram,
    outer_site: &MapLookupSite,
    outer_info: &MapInfo,
    state: &mut MapInMapRewriteState<'_>,
) -> SiteRewriteResult<Option<SiteRewrite>> {
    let Some(chain) = find_map_in_map_chains(prog, std::slice::from_ref(outer_site))
        .map_err(SiteRewriteError::Error)?
        .into_iter()
        .next()
    else {
        return Ok(None);
    };
    let extracted_outer_key = extract_site_constant_key(
        prog,
        outer_site.call_site,
        outer_info,
        state.use_verifier_guided_keys,
        state.inline_hints.for_call_site(outer_site.call_site),
    )
    .map_err(|err| match err {
        KeyExtractionError::Unavailable(err) => {
            site_level_inline_veto(format!("map-in-map outer key unavailable: {err}"))
        }
        KeyExtractionError::Error(err) => SiteRewriteError::Error(err),
    })?;
    if let Some(anchor) = extracted_outer_key.used_inline_hint {
        state.inline_hints_consumed.insert(anchor);
    }
    let outer_key = extracted_outer_key.key;
    if outer_key.width < outer_info.key_size as usize {
        return Err(site_level_inline_veto(format!(
            "map-in-map outer key width {} is smaller than map key size {}",
            outer_key.width, outer_info.key_size
        )));
    }
    let encoded_outer_key = encode_key_bytes(&outer_key.bytes, outer_info.key_size as usize);
    let inner_map_id =
        resolve_inner_map_id_for_outer_key(state.ctx, outer_info, &encoded_outer_key)?;
    if map_in_map_outer_only_fold_requested(
        state.inline_hints.for_call_site(outer_site.call_site),
        state.inline_hints.for_call_site(chain.inner_call_site),
    ) {
        return Ok(Some(build_map_in_map_outer_only_rewrite(
            prog,
            outer_site,
            outer_info,
            &outer_key,
            &encoded_outer_key,
            inner_map_id,
        )?));
    }
    let inner_info = snapshot_map_info(state.ctx, inner_map_id)
        .map_err(anyhow::Error::msg)?
        .ok_or_else(|| {
            SiteRewriteError::MissingSnapshot(anyhow::anyhow!(
                "map_values snapshot has no metadata for inner map {} from outer map {} key {}",
                inner_map_id,
                outer_info.map_id,
                format_bytes_preview(&encoded_outer_key)
            ))
        })?;
    if map_snapshot_skipped_by_size(state.ctx, inner_info.map_id) {
        return Ok(None);
    }
    if inner_info.is_map_in_map() {
        return Err(site_level_inline_veto(format!(
            "nested map-in-map inner map type {} not inlineable",
            inner_info.map_type
        )));
    }
    if let Some(reason) = kernel_mutable_reason_for_map(state.kernel_mutable_maps, &inner_info) {
        return Err(site_level_inline_veto(reason));
    }
    if !inner_info.supports_direct_value_access() {
        return Err(site_level_inline_veto(format!(
            "inner map type {} not inlineable",
            inner_info.map_type
        )));
    }
    let extracted_inner_key = extract_site_constant_key(
        prog,
        chain.inner_call_site,
        &inner_info,
        state.use_verifier_guided_keys,
        state.inline_hints.for_call_site(chain.inner_call_site),
    )
    .map_err(|err| match err {
        KeyExtractionError::Unavailable(err) => {
            site_level_inline_veto(format!("map-in-map inner key unavailable: {err}"))
        }
        KeyExtractionError::Error(err) => SiteRewriteError::Error(err),
    })?;
    if let Some(anchor) = extracted_inner_key.used_inline_hint {
        state.inline_hints_consumed.insert(anchor);
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
        prog,
        chain.inner_call_site,
        inner_info.has_removable_lookup_pattern(),
        inner_info.has_removable_lookup_pattern(),
    )?;
    if inner_info.requires_entry_presence_check() && uses.null_check_site.is_none() {
        return Err(site_level_inline_veto(
            "map-in-map inner hash map inline requires an immediate null check",
        ));
    }
    if uses.fixed_loads.is_empty() {
        return Err(site_level_inline_veto(
            "map-in-map inner lookup result is not consumed by fixed-offset scalar loads",
        ));
    }
    let lookup_value_size =
        lookup_value_size(state.ctx, &inner_info).map_err(anyhow::Error::msg)?;
    let value = match lookup_elem(
        state.ctx,
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
    let mut replacements = Vec::new();
    for load in &uses.fixed_loads {
        let scalar =
            read_scalar_from_value(&inline_value, load.offset, load.size).ok_or_else(|| {
                anyhow::anyhow!(
                    "inner map value read out of bounds for load {:?} (offset {}, size {})",
                    load.site,
                    load.offset,
                    load.size
                )
            })?;
        replacements.push(site_replacement(
            prog,
            load.site,
            emit_scalar_const_load(load.dst_reg, scalar, load.size != BPF_DW),
        )?);
    }
    if replacements.is_empty() {
        return Ok(None);
    }
    let replacement_sites = uses
        .fixed_loads
        .iter()
        .map(|load| load.site)
        .collect::<BTreeSet<_>>();
    let mut outer_lookup_sites = BTreeSet::new();
    outer_lookup_sites.insert(outer_site.call_site);
    outer_lookup_sites.insert(outer_site.map_load_site);
    outer_lookup_sites.extend(outer_key.materialization_sites.iter().copied());
    if let Some(r2_mov_site) = outer_key.r2_mov_site {
        outer_lookup_sites.insert(r2_mov_site);
    }
    if let Some(r2_add_site) = outer_key.r2_add_site {
        outer_lookup_sites.insert(r2_add_site);
    }
    let mut inner_lookup_sites = BTreeSet::new();
    if let Some(outer_null_check_site) = chain.outer_null_check_site {
        inner_lookup_sites.insert(outer_null_check_site);
    }
    inner_lookup_sites.extend(chain.outer_alias_copy_sites.iter().copied());
    inner_lookup_sites.insert(chain.inner_call_site);
    inner_lookup_sites.extend(inner_key.materialization_sites.iter().copied());
    if let Some(r2_mov_site) = inner_key.r2_mov_site {
        inner_lookup_sites.insert(r2_mov_site);
    }
    if let Some(r2_add_site) = inner_key.r2_add_site {
        inner_lookup_sites.insert(r2_add_site);
    }
    if let Some(inner_null_check_site) = uses.null_check_site {
        inner_lookup_sites.insert(inner_null_check_site);
    }
    inner_lookup_sites.extend(uses.alias_copy_sites.iter().copied());
    let mut lookup_pattern_sites = outer_lookup_sites.clone();
    lookup_pattern_sites.extend(inner_lookup_sites.iter().copied());
    let outer_null_check_blocks_removal =
        if let Some(outer_null_check_site) = chain.outer_null_check_site {
            !null_check_removal_window_is_trivial(
                prog,
                &uses,
                outer_null_check_site,
                &lookup_pattern_sites,
                &replacement_sites,
            )?
        } else {
            false
        };
    let inner_null_check_blocks_removal = if let Some(inner_null_check_site) = uses.null_check_site
    {
        !null_check_removal_window_is_trivial(
            prog,
            &uses,
            inner_null_check_site,
            &lookup_pattern_sites,
            &replacement_sites,
        )?
    } else {
        false
    };
    let can_remove_lookup_pattern = uses.other_use_sites.is_empty()
        && !outer_null_check_blocks_removal
        && !inner_null_check_blocks_removal
        && lookup_pattern_removal_is_safe(prog, outer_site.call_site, &outer_lookup_sites)?
        && lookup_pattern_removal_is_safe(prog, chain.inner_call_site, &inner_lookup_sites)?;
    let skipped_sites = if can_remove_lookup_pattern {
        lookup_pattern_sites
    } else {
        BTreeSet::new()
    };
    Ok(Some(SiteRewrite {
        call_site: outer_site.call_site,
        diagnostic_value: format!(
            "outer_map_id={} outer_key={} inner_map_id={} inner_key={} {}",
            outer_info.map_id,
            format_bytes_preview(&encoded_outer_key),
            inner_info.map_id,
            format_bytes_preview(&encoded_inner_key),
            format_inlined_value_diagnostic(&inline_value, &uses.fixed_loads)
        ),
        removed_null_check: can_remove_lookup_pattern
            && (chain.outer_null_check_site.is_some() || uses.null_check_site.is_some()),
        map_inline_records: vec![MapInlineRecord {
            map_id: inner_info.map_id,
            key: encoded_inner_key,
            value: inline_value,
        }],
        skipped_sites,
        replacements,
    }))
}
fn map_in_map_outer_only_fold_requested(
    outer_hints: Option<&[ResolvedInlineHint]>,
    inner_hints: Option<&[ResolvedInlineHint]>,
) -> bool {
    let outer_has_hard = match outer_hints {
        Some(hints) => hints
            .iter()
            .any(|hint| hint.mode == MapInlineHintMode::Hard),
        None => false,
    };
    let inner_empty = match inner_hints {
        Some(hints) => hints.is_empty(),
        None => true,
    };
    outer_has_hard && inner_empty
}
fn build_map_in_map_outer_only_rewrite(
    prog: &BBProgram,
    outer_site: &MapLookupSite,
    outer_info: &MapInfo,
    outer_key: &ConstantKey,
    encoded_outer_key: &[u8],
    inner_map_id: u32,
) -> SiteRewriteResult<SiteRewrite> {
    let mut skipped_sites = BTreeSet::new();
    skipped_sites.insert(outer_site.map_load_site);
    skipped_sites.extend(outer_key.materialization_sites.iter().copied());
    if let Some(r2_mov_site) = outer_key.r2_mov_site {
        skipped_sites.insert(r2_mov_site);
    }
    if let Some(r2_add_site) = outer_key.r2_add_site {
        skipped_sites.insert(r2_add_site);
    }
    let replacements = vec![site_replacement(
        prog,
        outer_site.call_site,
        emit_map_ptr_load(0, inner_map_id),
    )?];
    Ok(SiteRewrite {
        call_site: outer_site.call_site,
        diagnostic_value: format!(
            "outer-only outer_map_id={} outer_key={} inner_map_id={}",
            outer_info.map_id,
            format_bytes_preview(encoded_outer_key),
            inner_map_id
        ),
        removed_null_check: false,
        map_inline_records: Vec::new(),
        skipped_sites,
        replacements,
    })
}
fn emit_map_ptr_load(dst_reg: u8, map_id: u32) -> Vec<BpfInsn> {
    vec![
        BpfInsn::new(
            BPF_LD | BPF_DW | BPF_IMM,
            BpfInsn::make_regs(dst_reg, MapPseudo::Fd.src_reg()),
            0,
            0,
        ),
        BpfInsn::new(0, 0, 0, map_id as i32),
    ]
}
fn site_can_attempt_lookup_pattern_removal(
    prog: &BBProgram,
    uses: &R0UseClassification,
    info: &MapInfo,
    null_check_site: Option<InsnSite>,
) -> bool {
    if info.has_removable_lookup_pattern() {
        return true;
    }
    info.requires_entry_presence_check()
        && uses.other_use_sites.is_empty()
        && null_check_site.is_some_and(|site| {
            prog.insn_at(site)
                .is_some_and(null_check_is_fallthrough_non_null)
        })
}
fn build_direct_map_value_load_rewrites(
    prog: &BBProgram,
    ctx: &PassContext,
    kernel_mutable_maps: &KernelMutableMaps,
) -> anyhow::Result<DirectMapValueLoadRewriteResult> {
    let mut replacements = Vec::new();
    let mut sites_applied = 0usize;
    let mut site_diagnostics = Vec::new();
    let mut map_inline_records = Vec::new();
    let mut map_cache: HashMap<MapRefKey, Option<SnapshotMapValue>> = HashMap::new();
    for block in prog.blocks() {
        for site in prog.sites_in_block(block.id)? {
            let Some(insn) = prog.insn_at(site) else {
                continue;
            };
            if !insn.is_ldx_mem() {
                continue;
            }
            let origin = match resolve_key_pointer_origin(prog, site, insn.src_reg()) {
                Ok(Some(KeyPointerOrigin::MapValue {
                    map_ref, value_off, ..
                })) => Some((map_ref, value_off)),
                Ok(_) => None,
                Err(err) => return Err(anyhow!(err)),
            };
            let Some((map_ref, value_off)) = origin else {
                continue;
            };
            let Some(total_off) = value_off.checked_add(insn.off as i32) else {
                record_site_diagnostic(
                    &mut site_diagnostics,
                    site,
                    format!(
                        "pseudo-map-value offset overflow (base {} + load off {})",
                        value_off, insn.off
                    ),
                );
                continue;
            };
            if total_off < 0 {
                record_site_diagnostic(
                    &mut site_diagnostics,
                    site,
                    format!("pseudo-map-value load offset {} is negative", total_off),
                );
                continue;
            }
            let map_value = match resolve_snapshot_map_value(
                prog,
                ctx,
                map_ref,
                kernel_mutable_maps,
                &mut map_cache,
            )? {
                Some(map_value) => map_value,
                None => continue,
            };
            let offset = total_off as usize;
            let Some(scalar) =
                read_scalar_from_value_at(&map_value.value, offset, bpf_size(insn.code))
            else {
                let size = match size_in_bytes(bpf_size(insn.code)) {
                    Some(size) => size.to_string(),
                    None => "invalid".to_string(),
                };
                record_site_diagnostic(
                    &mut site_diagnostics,
                    site,
                    format!(
                        "pseudo-map-value load out of bounds (map_id={}, off={}, size={})",
                        map_value.map_id, offset, size
                    ),
                );
                continue;
            };
            replacements.push(SiteReplacement {
                site,
                replacement: emit_scalar_const_load(
                    insn.dst_reg(),
                    scalar,
                    bpf_size(insn.code) != BPF_DW,
                ),
            });
            sites_applied += 1;
            map_inline_records.push(MapInlineRecord {
                map_id: map_value.map_id,
                key: map_value.key.clone(),
                value: map_value.value.clone(),
            });
            record_site_diagnostic(
                &mut site_diagnostics,
                site,
                format!(
                    "constantized pseudo-map-value load from map_id={} off={} value=0x{:x}",
                    map_value.map_id, offset, scalar
                ),
            );
        }
    }
    Ok(DirectMapValueLoadRewriteResult {
        replacements,
        sites_applied,
        site_diagnostics,
        records: map_inline_records,
    })
}
fn resolve_snapshot_map_value(
    prog: &BBProgram,
    ctx: &PassContext,
    map_ref: MapRefKey,
    kernel_mutable_maps: &KernelMutableMaps,
    cache: &mut HashMap<MapRefKey, Option<SnapshotMapValue>>,
) -> anyhow::Result<Option<SnapshotMapValue>> {
    if let Some(cached) = cache.get(&map_ref) {
        return Ok(cached.clone());
    }
    let resolved = (|| -> anyhow::Result<Option<SnapshotMapValue>> {
        let Some(map_id) = map_id_for_ref(prog, ctx, map_ref)? else {
            return Ok(None);
        };
        if map_snapshot_skipped_by_size(ctx, map_id) {
            return Ok(None);
        }
        let Some(info) = snapshot_map_info(ctx, map_id).map_err(anyhow::Error::msg)? else {
            return Ok(None);
        };
        if kernel_mutable_reason_for_map(kernel_mutable_maps, &info).is_some() {
            return Ok(None);
        }
        let key = vec![0u8; info.key_size as usize];
        let value_size = lookup_value_size(ctx, &info).map_err(anyhow::Error::msg)?;
        let value = match lookup_elem(ctx, map_id, &key, value_size) {
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
fn map_id_for_ref(
    prog: &BBProgram,
    ctx: &PassContext,
    map_ref: MapRefKey,
) -> anyhow::Result<Option<u32>> {
    match MapPseudo::from_src_reg(map_ref.src_reg) {
        Some(kind) if kind.uses_fd() => Ok(prog.map_fd_bindings().get(&map_ref.imm).copied()),
        Some(kind) if kind.uses_index() => {
            let index = usize::try_from(map_ref.imm).map_err(|_| {
                anyhow::anyhow!("negative canonical pseudo-map index {}", map_ref.imm)
            })?;
            let Some(&map_id) = ctx.map_ids.get(index) else {
                anyhow::bail!(
                    "canonical pseudo-map index {} out of range for {} map ids",
                    index,
                    ctx.map_ids.len()
                );
            };
            Ok(Some(map_id))
        }
        _ => Ok(None),
    }
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
        return Err("per-cpu array has zero value_size".to_string());
    }
    let stride = round_up_8(value_size);
    if raw_value.len() < stride || !raw_value.len().is_multiple_of(stride) {
        return Err(format!(
            "per-cpu array lookup blob length {} is inconsistent with slot stride {}",
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
                "per-cpu array value differs across CPUs for {} slot(s)",
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
fn find_map_load_for_call(
    prog: &BBProgram,
    call_site: InsnSite,
) -> anyhow::Result<Option<InsnSite>> {
    find_direct_map_load_for_reg_before_site(prog, call_site, 1)
}
fn find_direct_map_load_for_reg_before_site(
    prog: &BBProgram,
    site: InsnSite,
    reg: u8,
) -> anyhow::Result<Option<InsnSite>> {
    find_direct_map_load_for_reg_before_site_inner(prog, site, reg, REG_RESOLUTION_LIMIT)
}
fn find_direct_map_load_for_reg_before_site_inner(
    prog: &BBProgram,
    site: InsnSite,
    reg: u8,
    budget: usize,
) -> anyhow::Result<Option<InsnSite>> {
    if budget == 0 {
        return Ok(None);
    }
    let previous_sites = sites_before_site_in_frame_rev(prog, site)?;
    for prev_site in previous_sites {
        let insn = prog.insn(prev_site)?;
        if insn_use_def_set(insn).defs.contains(&reg) {
            if insn.dst_reg() == reg
                && matches!(insn.map_pseudo(), Some(MapPseudo::Fd | MapPseudo::Idx))
            {
                return Ok(Some(prev_site));
            }
            if insn.is_mov64_reg() && insn.dst_reg() == reg {
                return find_direct_map_load_for_reg_before_site_inner(
                    prog,
                    prev_site,
                    insn.src_reg(),
                    budget - 1,
                );
            }
            if is_stack_dw_load_to_reg(insn, reg) {
                return find_direct_map_load_for_stack_slot_before_site(
                    prog,
                    prev_site,
                    insn.off,
                    budget - 1,
                );
            }
            return Ok(None);
        }
    }
    Ok(None)
}
fn find_direct_map_load_for_stack_slot_before_site(
    prog: &BBProgram,
    site: InsnSite,
    stack_off: i16,
    budget: usize,
) -> anyhow::Result<Option<InsnSite>> {
    if budget == 0 {
        return Ok(None);
    }
    let previous_sites = sites_before_site_in_frame_rev(prog, site)?;
    for prev_site in previous_sites {
        let insn = prog.insn(prev_site)?;
        if is_stack_dw_store(insn, stack_off) {
            if insn.class() != BPF_STX {
                return Ok(None);
            }
            return find_direct_map_load_for_reg_before_site_inner(
                prog,
                prev_site,
                insn.src_reg(),
                budget - 1,
            );
        }
    }
    Ok(None)
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
        err => SiteRewriteError::MissingSnapshot(anyhow::Error::msg(err.to_string())),
    }
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
    prog: &BBProgram,
    lookup_call_site: InsnSite,
    skipped_sites: &BTreeSet<InsnSite>,
) -> anyhow::Result<bool> {
    if skipped_sites.is_empty() {
        return Ok(false);
    }
    let sites = prog.all_sites().collect::<Vec<_>>();
    let mut min_removed_pos = usize::MAX;
    for site in skipped_sites {
        min_removed_pos = min_removed_pos.min(position_in_sites(&sites, *site)?);
    }
    let lookup_pos = position_in_sites(&sites, lookup_call_site)?;
    if min_removed_pos > lookup_pos {
        return Ok(false);
    }
    for &site in &sites[min_removed_pos..=lookup_pos] {
        let insn = prog.insn(site)?;
        if skipped_sites.contains(&site) {
            continue;
        }
        if !lookup_pattern_gap_insn_is_safe(insn) {
            return Ok(false);
        }
        let use_def = insn_use_def_set(insn);
        if [1u8, 2]
            .into_iter()
            .any(|reg| use_def.uses.contains(&reg) || use_def.defs.contains(&reg))
        {
            return Ok(false);
        }
    }
    Ok(true)
}
fn lookup_pattern_gap_insn_is_safe(insn: &BpfInsn) -> bool {
    !insn.is_jmp_class() && !matches!(insn.class(), BPF_ST | BPF_STX)
}
fn find_r2_stack_pointer_setup_simple(
    prog: &BBProgram,
    call_site: InsnSite,
) -> anyhow::Result<Option<(InsnSite, InsnSite, i16)>> {
    let (r2_add_site, scanned) =
        match find_prev_reg_def_within(prog, call_site, 2, R2_SETUP_LOOKBACK_LIMIT) {
            Ok(Some(found)) => found,
            Ok(None) => return Ok(None),
            Err(err) => return Err(err),
        };
    let add = prog
        .insn_at(r2_add_site)
        .ok_or_else(|| anyhow::anyhow!("missing r2 add instruction at {:?}", r2_add_site))?;
    if add.code != (BPF_ALU64 | BPF_ADD | BPF_K) || add.dst_reg() != 2 || add.imm >= 0 {
        return Ok(None);
    }
    let remaining = R2_SETUP_LOOKBACK_LIMIT.saturating_sub(scanned);
    let (r2_mov_site, _) = match find_prev_reg_def_within(prog, r2_add_site, 2, remaining) {
        Ok(Some(found)) => found,
        Ok(None) => return Ok(None),
        Err(err) => return Err(err),
    };
    let mov = prog
        .insn_at(r2_mov_site)
        .ok_or_else(|| anyhow::anyhow!("missing r2 mov instruction at {:?}", r2_mov_site))?;
    if mov.code != (BPF_ALU64 | BPF_MOV | BPF_X) || mov.dst_reg() != 2 || mov.src_reg() != 10 {
        return Ok(None);
    }
    let stack_off = i16::try_from(add.imm)
        .map_err(|_| anyhow::anyhow!("r2 stack add immediate {} does not fit i16", add.imm))?;
    Ok(Some((r2_mov_site, r2_add_site, stack_off)))
}
fn find_prev_reg_def_within(
    prog: &BBProgram,
    start_site: InsnSite,
    reg: u8,
    limit: usize,
) -> anyhow::Result<Option<(InsnSite, usize)>> {
    let mut scanned = 0usize;
    for site in sites_before_site_in_frame_rev(prog, start_site)? {
        scanned += 1;
        if scanned > limit {
            break;
        }
        if insn_use_def_set(prog.insn(site)?).defs.contains(&reg) {
            return Ok(Some((site, scanned)));
        }
    }
    Ok(None)
}
fn resolve_constant_reg_value(
    prog: &BBProgram,
    before_site: InsnSite,
    reg: u8,
) -> Result<ConstantRegValue, String> {
    resolve_constant_reg_value_inner(prog, before_site, reg, REG_RESOLUTION_LIMIT)
}
fn resolve_constant_reg_value_inner(
    prog: &BBProgram,
    before_site: InsnSite,
    reg: u8,
    budget: usize,
) -> Result<ConstantRegValue, String> {
    if budget == 0 {
        return Err(format!(
            "constant register resolution for r{} exceeded {} steps",
            reg, REG_RESOLUTION_LIMIT
        ));
    }
    let Some(site) = find_prev_reg_def(prog, before_site, reg)? else {
        if reg <= 5 {
            return Err(format!("source register r{} is a function argument", reg));
        }
        return Err(format!("no definition for source register r{}", reg));
    };
    let insn = *prog.insn(site).map_err(|err| err.to_string())?;
    if insn.is_ldimm64() && insn.dst_reg() == reg {
        if insn.src_reg() != 0 {
            return Err(format!(
                "register r{} at {:?} is loaded from pseudo source {}",
                reg,
                site,
                insn.src_reg()
            ));
        }
        return Ok(ConstantRegValue {
            value: decode_ldimm64(prog, site)?,
            source_site: Some(site),
        });
    }
    if insn.class() == BPF_LDX
        && bpf_mode(insn.code) == BPF_MEM
        && insn.dst_reg() == reg
        && budget > 1
    {
        if let Some(width) = size_in_bytes(bpf_size(insn.code)) {
            if let Ok(base_stack_off) =
                resolve_stack_pointer_to_stack_inner(prog, site, insn.src_reg(), budget - 1)
            {
                let stack_off = i32::from(base_stack_off) + i32::from(insn.off);
                let stack_off = i16::try_from(stack_off).map_err(|_| {
                    format!(
                        "resolved stack load offset {} from r{} does not fit in i16",
                        stack_off, reg
                    )
                })?;
                let stack_bytes = find_constant_stack_bytes_with_limit(
                    prog,
                    site,
                    stack_off,
                    width,
                    Some(CONST_STACK_VALUE_LOOKBACK_LIMIT),
                )?;
                return Ok(ConstantRegValue {
                    value: constant_key_value(&stack_bytes.bytes),
                    source_site: None,
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
                source_site: Some(site),
            });
        }
        if op == BPF_MOV && src_mode == BPF_X {
            let resolved =
                resolve_constant_reg_value_inner(prog, site, insn.src_reg(), budget - 1)?;
            return Ok(ConstantRegValue {
                value: apply_alu_width(resolved.value, is_32bit),
                source_site: resolved.source_site,
            });
        }
        let lhs = resolve_constant_reg_value_inner(prog, site, reg, budget - 1)?;
        let rhs = if src_mode == BPF_K {
            insn.imm as i64 as u64
        } else {
            resolve_constant_reg_value_inner(prog, site, insn.src_reg(), budget - 1)?.value
        };
        let value = apply_constant_alu(op, lhs.value, rhs, is_32bit).ok_or_else(|| {
            format!(
                "register r{} definition at {:?} uses unsupported constant op {:#x}",
                reg, site, insn.code
            )
        })?;
        return Ok(ConstantRegValue {
            value,
            source_site: None,
        });
    }
    Err(format!(
        "register r{} definition at {:?} is not a supported constant materialization",
        reg, site
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
fn find_prev_reg_def(
    prog: &BBProgram,
    start_site: InsnSite,
    reg: u8,
) -> Result<Option<InsnSite>, String> {
    for site in sites_before_site_in_frame_rev(prog, start_site).map_err(|err| err.to_string())? {
        let insn = prog.insn(site).map_err(|err| err.to_string())?;
        if insn_use_def_set(insn).defs.contains(&reg) {
            return Ok(Some(site));
        }
    }
    Ok(None)
}
fn resolve_key_pointer_origin(
    prog: &BBProgram,
    before_site: InsnSite,
    reg: u8,
) -> Result<Option<KeyPointerOrigin>, String> {
    resolve_key_pointer_origin_inner(prog, before_site, reg, REG_RESOLUTION_LIMIT)
}
fn resolve_key_pointer_origin_inner(
    prog: &BBProgram,
    before_site: InsnSite,
    reg: u8,
    budget: usize,
) -> Result<Option<KeyPointerOrigin>, String> {
    if budget == 0 {
        return Err(format!(
            "key pointer resolution for r{} exceeded {} steps",
            reg, REG_RESOLUTION_LIMIT
        ));
    }
    if reg == 10 {
        return Ok(Some(KeyPointerOrigin::Stack(0)));
    }
    let Some(site) = find_prev_reg_def(prog, before_site, reg)? else {
        return Ok(None);
    };
    let insn = *prog.insn(site).map_err(|err| err.to_string())?;
    if insn.is_ldimm64() && insn.dst_reg() == reg {
        if matches!(
            insn.map_pseudo(),
            Some(MapPseudo::FdValue | MapPseudo::IdxValue)
        ) {
            let value_off = prog
                .ldimm64_second_slots
                .get(&site)
                .ok_or_else(|| format!("pseudo-map-value load at {:?} is truncated", site))?
                .imm;
            return Ok(Some(KeyPointerOrigin::MapValue {
                map_ref: MapRefKey {
                    src_reg: insn.src_reg(),
                    imm: insn.imm,
                },
                value_off,
                ldimm_site: site,
            }));
        }
        return Ok(None);
    }
    if (insn.class() == BPF_ALU64 || insn.class() == BPF_ALU) && insn.dst_reg() == reg {
        let op = bpf_op(insn.code);
        let src_mode = bpf_src(insn.code);
        if op == BPF_MOV && src_mode == BPF_X {
            return resolve_key_pointer_origin_inner(prog, site, insn.src_reg(), budget - 1);
        }
        if op == BPF_ADD || op == BPF_SUB {
            let Some(base) = resolve_key_pointer_origin_inner(prog, site, reg, budget - 1)? else {
                return Ok(None);
            };
            let delta = if src_mode == BPF_K {
                insn.imm as i64
            } else {
                resolve_constant_reg_value_inner(prog, site, insn.src_reg(), budget - 1)?.value
                    as i64
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
                    Ok(Some(KeyPointerOrigin::Stack(stack_off)))
                }
                KeyPointerOrigin::MapValue {
                    map_ref,
                    value_off,
                    ldimm_site,
                } => {
                    let value_off = value_off as i64 + signed_delta;
                    let value_off = i32::try_from(value_off).map_err(|_| {
                        format!(
                            "resolved pseudo-map-value offset {} from r{} does not fit in i32",
                            value_off, reg
                        )
                    })?;
                    Ok(Some(KeyPointerOrigin::MapValue {
                        map_ref,
                        value_off,
                        ldimm_site,
                    }))
                }
            };
        }
    }
    Ok(None)
}
fn resolve_stack_pointer_to_stack_inner(
    prog: &BBProgram,
    before_site: InsnSite,
    reg: u8,
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
    let Some(site) = find_prev_reg_def(prog, before_site, reg)? else {
        if reg <= 5 {
            return Err(format!("key pointer flows from function argument r{}", reg));
        }
        return Err(format!("no definition for key pointer register r{}", reg));
    };
    let insn = *prog.insn(site).map_err(|err| err.to_string())?;
    if (insn.class() == BPF_ALU64 || insn.class() == BPF_ALU) && insn.dst_reg() == reg {
        let op = bpf_op(insn.code);
        let src_mode = bpf_src(insn.code);
        if op == BPF_MOV && src_mode == BPF_X {
            return resolve_stack_pointer_to_stack_inner(prog, site, insn.src_reg(), budget - 1);
        }
        if op == BPF_ADD || op == BPF_SUB {
            let base = resolve_stack_pointer_to_stack_inner(prog, site, reg, budget - 1)?;
            let delta = if src_mode == BPF_K {
                insn.imm as i64
            } else {
                resolve_constant_reg_value_inner(prog, site, insn.src_reg(), budget - 1)?.value
                    as i64
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
        "register r{} definition at {:?} does not resolve to fp-relative stack memory",
        reg, site
    ))
}
fn decode_ldimm64(prog: &BBProgram, site: InsnSite) -> Result<u64, String> {
    let lo = prog.insn(site).map_err(|err| err.to_string())?;
    let hi = prog
        .ldimm64_second_slots
        .get(&site)
        .ok_or_else(|| format!("ldimm64 at {:?} is missing high half", site))?;
    Ok(decode_ldimm64_value(lo, hi))
}
fn apply_alu_width(value: u64, is_32bit: bool) -> u64 {
    if is_32bit {
        value as u32 as u64
    } else {
        value
    }
}
fn apply_constant_alu(op: u8, lhs: u64, rhs: u64, is_32bit: bool) -> Option<u64> {
    if !matches!(
        op,
        BPF_ADD | BPF_SUB | BPF_MUL | BPF_AND | BPF_OR | BPF_LSH | BPF_RSH
    ) {
        return None;
    }
    eval_binary_alu_const(op, lhs, rhs, is_32bit).map(|value| apply_alu_width(value, is_32bit))
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
fn record_site_diagnostic(diagnostics: &mut Vec<SiteDiagnostic>, site: InsnSite, message: String) {
    log_map_inline_debug(&format!("site {:?}: {}", site, message));
    diagnostics.push(SiteDiagnostic { site, message });
}
fn record_maps_skipped_by_size_counter(ctx: &PassContext, diagnostics: &mut Vec<String>) {
    let count = ctx
        .map_snapshots_skipped_by_size
        .iter()
        .filter(|map_id| !ctx.map_value_overlays.contains_key(map_id))
        .count();
    if count > 0 {
        record_diagnostic(diagnostics, format!("maps_skipped_by_size={count}"));
    }
}
fn map_snapshot_skipped_by_size(ctx: &PassContext, map_id: u32) -> bool {
    ctx.map_snapshots_skipped_by_size.contains(&map_id)
        && !ctx.map_value_overlays.contains_key(&map_id)
}
fn map_snapshot_skipped_by_size_reason(map_id: u32) -> String {
    format!("map {map_id} snapshot skipped by size and no overlay provided")
}
fn map_snapshot_skipped_by_size_site_reason(ctx: &PassContext, map_id: u32) -> String {
    format!(
        "map snapshot skipped by size and no overlay provided (map_name={}, map_id={})",
        map_name_for_id(ctx, map_id),
        map_id
    )
}
fn map_name_for_id(ctx: &PassContext, map_id: u32) -> String {
    match ctx.map_metadata.get(&map_id) {
        Some(metadata) if !metadata.name.is_empty() => metadata.name.clone(),
        Some(_) => "<unnamed>".to_string(),
        None => "<unknown>".to_string(),
    }
}
fn record_skip(
    skipped: &mut Vec<SiteSkipReason>,
    diagnostics: &mut Vec<SiteDiagnostic>,
    site: InsnSite,
    reason: String,
    detail: Option<String>,
) {
    skipped.push(SiteSkipReason {
        site,
        reason: reason.clone(),
    });
    record_site_diagnostic(diagnostics, site, format!("skip reason: {}", reason));
    if let Some(detail) = detail {
        record_site_diagnostic(diagnostics, site, detail);
    }
}
fn format_bytes_preview(bytes: &[u8]) -> String {
    let preview_len = bytes.len().min(VALUE_PREVIEW_BYTES);
    let mut out = String::with_capacity(preview_len.saturating_mul(2) + 6);
    out.push_str("0x");
    for byte in &bytes[..preview_len] {
        out.push_str(&format!("{byte:02x}"));
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
    prog: &BBProgram,
    start_site: InsnSite,
    allow_unrelated_helper_calls: bool,
    allow_readonly_helper_calls: bool,
) -> anyhow::Result<R0UseClassification> {
    let mut classification = R0UseClassification::default();
    let mut alias_regs = HashMap::from([(0u8, 0i16)]);
    let mut alias_stack_slots = HashMap::new();
    let sites = sites_after_site_in_frame(prog, start_site)?;
    let mut pos = 0usize;
    while pos < sites.len() && (!alias_regs.is_empty() || !alias_stack_slots.is_empty()) {
        let site = sites[pos];
        let insn = prog.insn(site)?;
        let alias_copy = alias_copy(insn, &alias_regs);
        let allow_null_check =
            classification.fixed_loads.is_empty() && classification.other_use_sites.is_empty();
        if let Some((dst_reg, alias_off)) = alias_copy {
            classification.alias_copy_sites.push(site);
            kill_defined_alias_regs(&mut alias_regs, insn);
            alias_regs.insert(dst_reg, alias_off);
            pos += 1;
            continue;
        }
        if let Some(alias_off) = alias_adjustment(prog, site, insn, &alias_regs) {
            classification.alias_copy_sites.push(site);
            kill_defined_alias_regs(&mut alias_regs, insn);
            alias_regs.insert(insn.dst_reg(), alias_off);
            pos += 1;
            continue;
        }
        if allow_null_check
            && classification.null_check_site.is_none()
            && is_null_check_on_alias(insn, &alias_regs)
        {
            classification.null_check_site = Some(site);
            let Some(next_site) = non_null_successor_site(prog, site, insn)? else {
                break;
            };
            let Some(next_pos) = sites.iter().position(|candidate| *candidate == next_site) else {
                break;
            };
            pos = next_pos;
            continue;
        }
        if !classification.fixed_loads.is_empty()
            && alias_stack_slots.is_empty()
            && ends_current_use_region(insn, &alias_regs)
        {
            break;
        }
        if let Some((stack_off, width)) = resolve_stack_store_slot(prog, site, insn) {
            kill_overlapping_alias_stack_slots(&mut alias_stack_slots, stack_off, width);
            if insn.class() == BPF_STX
                && bpf_mode(insn.code) == BPF_MEM
                && width == 8
                && alias_regs.contains_key(&insn.src_reg())
            {
                classification.alias_copy_sites.push(site);
                alias_stack_slots.insert(stack_off, alias_regs[&insn.src_reg()]);
                pos += 1;
                continue;
            }
        }
        if let Some(stack_off) = resolve_stack_load_slot(prog, site, insn) {
            if let Some(&alias_off) = alias_stack_slots.get(&stack_off) {
                classification.alias_copy_sites.push(site);
                alias_stack_slots.remove(&stack_off);
                kill_defined_alias_regs(&mut alias_regs, insn);
                alias_regs.insert(insn.dst_reg(), alias_off);
                pos += 1;
                continue;
            }
        }
        if insn.is_call() {
            if insn_uses_any_alias(insn, &alias_regs) {
                classification.other_use_sites.push(site);
                break;
            }
            let surviving_aliases = surviving_alias_regs_after_helper_call(&alias_regs);
            let can_follow_helper = allow_unrelated_helper_calls
                || (allow_readonly_helper_calls && helper_call_is_readonly_for_lookup_value(insn));
            if can_follow_helper && (!surviving_aliases.is_empty() || !alias_stack_slots.is_empty())
            {
                alias_regs = surviving_aliases;
                pos += 1;
                continue;
            }
            let has_unfollowed_aliases = !surviving_aliases.is_empty();
            alias_regs.clear();
            if !alias_stack_slots.is_empty() {
                pos += 1;
                continue;
            }
            if has_unfollowed_aliases {
                classification.other_use_sites.push(site);
                break;
            }
            break;
        }
        if insn.is_exit() {
            break;
        }
        if insn.is_ldx_mem() && alias_regs.contains_key(&insn.src_reg()) {
            let total_off = i32::from(alias_regs[&insn.src_reg()]) + i32::from(insn.off);
            let Ok(total_off) = i16::try_from(total_off) else {
                classification.other_use_sites.push(site);
                kill_defined_alias_regs(&mut alias_regs, insn);
                pos += 1;
                continue;
            };
            classification.fixed_loads.push(FixedLoadUse {
                site,
                dst_reg: insn.dst_reg(),
                size: bpf_size(insn.code),
                offset: total_off,
            });
        } else if insn_uses_any_alias(insn, &alias_regs) {
            classification.other_use_sites.push(site);
        }
        kill_defined_alias_regs(&mut alias_regs, insn);
        pos += 1;
    }
    Ok(classification)
}
fn resolve_stack_store_slot(prog: &BBProgram, site: InsnSite, insn: &BpfInsn) -> Option<(i16, u8)> {
    if bpf_mode(insn.code) != BPF_MEM {
        return None;
    }
    let width = size_in_bytes(bpf_size(insn.code))?;
    if !(insn.class() == BPF_ST || insn.class() == BPF_STX) {
        return None;
    }
    let base_stack_off = match resolve_stack_pointer_to_stack_inner(
        prog,
        site,
        insn.dst_reg(),
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
fn resolve_stack_load_slot(prog: &BBProgram, site: InsnSite, insn: &BpfInsn) -> Option<i16> {
    if insn.class() != BPF_LDX || bpf_mode(insn.code) != BPF_MEM || bpf_size(insn.code) != BPF_DW {
        return None;
    }
    let base_stack_off = match resolve_stack_pointer_to_stack_inner(
        prog,
        site,
        insn.src_reg(),
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
fn non_null_successor_site(
    prog: &BBProgram,
    null_check_site: InsnSite,
    insn: &BpfInsn,
) -> anyhow::Result<Option<InsnSite>> {
    let Terminator::CondBranch {
        taken, fallthrough, ..
    } = prog.terminator(null_check_site.block)?
    else {
        return Ok(None);
    };
    let non_null_block = match bpf_op(insn.code) {
        BPF_JEQ => fallthrough,
        BPF_JNE => taken,
        _ => return Ok(None),
    };
    prog.first_site_in_block(non_null_block)
}
fn null_successor_site(
    prog: &BBProgram,
    null_check_site: InsnSite,
    insn: &BpfInsn,
) -> anyhow::Result<Option<InsnSite>> {
    let Terminator::CondBranch {
        taken, fallthrough, ..
    } = prog.terminator(null_check_site.block)?
    else {
        return Ok(None);
    };
    let null_block = match bpf_op(insn.code) {
        BPF_JEQ => taken,
        BPF_JNE => fallthrough,
        _ => return Ok(None),
    };
    prog.first_site_in_block(null_block)
}
fn ends_current_use_region(insn: &BpfInsn, alias_regs: &HashMap<u8, i16>) -> bool {
    (insn.is_jmp_class()
        && !insn.is_call()
        && !insn.is_exit()
        && !insn_uses_any_alias(insn, alias_regs))
        || starts_next_lookup_setup(insn)
}
fn starts_next_lookup_setup(insn: &BpfInsn) -> bool {
    matches!(insn.map_pseudo(), Some(MapPseudo::Fd | MapPseudo::Idx))
}
fn alias_copy(insn: &BpfInsn, alias_regs: &HashMap<u8, i16>) -> Option<(u8, i16)> {
    insn.is_mov64_reg()
        .then(|| {
            alias_regs
                .get(&insn.src_reg())
                .copied()
                .map(|off| (insn.dst_reg(), off))
        })
        .flatten()
}
fn alias_adjustment(
    prog: &BBProgram,
    site: InsnSite,
    insn: &BpfInsn,
    alias_regs: &HashMap<u8, i16>,
) -> Option<i16> {
    if insn.class() != BPF_ALU64 {
        return None;
    }
    let base_off = i32::from(*alias_regs.get(&insn.dst_reg())?);
    let delta = match (bpf_op(insn.code), bpf_src(insn.code)) {
        (BPF_ADD, BPF_K) => insn.imm as i64,
        (BPF_SUB, BPF_K) => -(insn.imm as i64),
        (BPF_ADD, BPF_X) => {
            match resolve_constant_reg_value_inner(prog, site, insn.src_reg(), REG_RESOLUTION_LIMIT)
            {
                Ok(value) => value.value as i64,
                Err(_) => return None,
            }
        }
        (BPF_SUB, BPF_X) => {
            match resolve_constant_reg_value_inner(prog, site, insn.src_reg(), REG_RESOLUTION_LIMIT)
            {
                Ok(value) => -(value.value as i64),
                Err(_) => return None,
            }
        }
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
    prog: &BBProgram,
    uses: &R0UseClassification,
    null_check_site: InsnSite,
    skipped_sites: &BTreeSet<InsnSite>,
    replacement_sites: &BTreeSet<InsnSite>,
) -> anyhow::Result<bool> {
    let null_check_insn = prog.insn(null_check_site)?;
    let Some(null_target_site) = null_successor_site(prog, null_check_site, null_check_insn)?
    else {
        return Ok(false);
    };
    let Some(non_null_site) = non_null_successor_site(prog, null_check_site, null_check_insn)?
    else {
        return Ok(false);
    };
    let sites = prog.all_sites().collect::<Vec<_>>();
    let mut pos = position_in_sites(&sites, non_null_site)?;
    let target_pos = position_in_sites(&sites, null_target_site)?;
    let load_dst_regs = uses
        .fixed_loads
        .iter()
        .map(|load| (load.site, load.dst_reg))
        .collect::<HashMap<_, _>>();
    let mut safe_scalar_regs = HashSet::new();
    let mut killed_arg_regs = HashSet::new();
    while pos < target_pos {
        let site = sites[pos];
        let insn = prog.insn(site)?;
        if skipped_sites.contains(&site) {
            for reg in 1..=5 {
                if insn_use_def_set(insn).defs.contains(&reg) {
                    killed_arg_regs.insert(reg);
                    safe_scalar_regs.remove(&reg);
                }
            }
            pos += 1;
            continue;
        }
        if replacement_sites.contains(&site) {
            let Some(&dst_reg) = load_dst_regs.get(&site) else {
                return Ok(false);
            };
            mark_safe_scalar_reg(&mut safe_scalar_regs, &mut killed_arg_regs, dst_reg);
            pos += 1;
            continue;
        }
        if !is_trivially_safe_null_check_guarded_insn(
            insn,
            &mut safe_scalar_regs,
            &mut killed_arg_regs,
        ) {
            return Ok(false);
        }
        pos += 1;
    }
    Ok(true)
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
    let use_def = insn_use_def_set(insn);
    alias_regs
        .keys()
        .copied()
        .any(|reg| use_def.uses.contains(&reg))
}
fn kill_defined_alias_regs(alias_regs: &mut HashMap<u8, i16>, insn: &BpfInsn) {
    let use_def = insn_use_def_set(insn);
    alias_regs.retain(|reg, _| !use_def.defs.contains(reg));
}
