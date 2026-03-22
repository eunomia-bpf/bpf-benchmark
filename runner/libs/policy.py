from __future__ import annotations

from collections import Counter, defaultdict
import re
from dataclasses import dataclass
from pathlib import Path
from typing import Any, Iterable, Mapping, Sequence

import yaml

ROOT_DIR = Path(__file__).resolve().parents[2]
CORPUS_DIR = ROOT_DIR / "corpus"
POLICY_DIR = CORPUS_DIR / "policies"
LIVE_POLICY_DIRNAME = "live"
OBJECT_ROOT_NAMES = ("build", "expanded_corpus", "objects")
PROGRAM_SAFE_CHARS = re.compile(r"[^A-Za-z0-9._-]+")
CANONICAL_POLICY_FAMILIES = (
    "cmov",
    "wide",
    "rotate",
    "lea",
    "extract",
    "endian",
    "branch-flip",
)
CANONICAL_POLICY_FAMILY_SET = set(CANONICAL_POLICY_FAMILIES)
POLICY_FAMILY_ALIASES = {
    "cmov": "cmov",
    "cond-select": "cmov",
    "cond_select": "cmov",
    "wide": "wide",
    "wide-mem": "wide",
    "wide_mem": "wide",
    "wide-load": "wide",
    "wide_load": "wide",
    "rotate": "rotate",
    "lea": "lea",
    "addr-calc": "lea",
    "addr_calc": "lea",
    "addrcalc": "lea",
    "extract": "extract",
    "bitfield": "extract",
    "bitfield-extract": "extract",
    "bitfield_extract": "extract",
    "bit-extract": "extract",
    "endian": "endian",
    "endian-fusion": "endian",
    "branch-flip": "branch-flip",
    "branch_flip": "branch-flip",
    "branchflip": "branch-flip",
    "bflip": "branch-flip",
}
POLICY_FAMILY_ORDER = {family: index for index, family in enumerate(CANONICAL_POLICY_FAMILIES)}


class _UniqueKeyLoader(yaml.SafeLoader):
    pass


def _construct_unique_mapping(
    loader: _UniqueKeyLoader,
    node: yaml.MappingNode,
    deep: bool = False,
) -> dict[Any, Any]:
    mapping: dict[Any, Any] = {}
    for key_node, value_node in node.value:
        key = loader.construct_object(key_node, deep=deep)
        if key in mapping:
            raise yaml.constructor.ConstructorError(
                "while constructing a mapping",
                node.start_mark,
                f"found duplicate key {key!r}",
                key_node.start_mark,
            )
        mapping[key] = loader.construct_object(value_node, deep=deep)
    return mapping


_UniqueKeyLoader.add_constructor(
    yaml.resolver.BaseResolver.DEFAULT_MAPPING_TAG,
    _construct_unique_mapping,
)


@dataclass(frozen=True, slots=True)
class PolicySiteV3:
    insn: int
    family: str
    pattern_kind: str


@dataclass(frozen=True, slots=True)
class PolicyDocumentV3:
    version: int
    program: str | None
    sites: tuple[PolicySiteV3, ...]


@dataclass(frozen=True, slots=True)
class PolicyRemapSummaryV3:
    explicit_sites: int
    remapped_sites: int
    dropped_sites: int
    live_total_sites: int
    policy_family_counts: dict[str, int]
    live_family_counts: dict[str, int]
    remapped_family_counts: dict[str, int]
    dropped_family_counts: dict[str, int]


def object_roots(corpus_dir: Path = CORPUS_DIR) -> tuple[Path, ...]:
    return tuple((corpus_dir / name).resolve() for name in OBJECT_ROOT_NAMES if (corpus_dir / name).exists())


def object_relative_path(object_path: Path, corpus_dir: Path = CORPUS_DIR) -> Path:
    resolved = object_path.resolve()
    for root in object_roots(corpus_dir):
        try:
            return resolved.relative_to(root)
        except ValueError:
            continue
    try:
        return resolved.relative_to(corpus_dir.resolve())
    except ValueError:
        return Path(resolved.name)


def object_policy_stem(object_path: Path) -> str:
    name = object_relative_path(object_path).name
    if name.endswith(".bpf.o"):
        return name[:-len(".bpf.o")]
    return Path(name).stem


def sanitize_program_name(program_name: str) -> str:
    sanitized = PROGRAM_SAFE_CHARS.sub("_", program_name.strip())
    sanitized = sanitized.strip(".")
    return sanitized or "unnamed-program"


def program_policy_dir(object_path: Path, policy_dir: Path = POLICY_DIR) -> Path:
    relative = object_relative_path(object_path)
    return policy_dir / relative.parent / object_policy_stem(object_path)


def live_policy_dir(policy_dir: Path = POLICY_DIR) -> Path:
    return policy_dir / LIVE_POLICY_DIRNAME


def policy_path_for_program(
    object_path: Path,
    program_name: str,
    policy_dir: Path = POLICY_DIR,
) -> Path:
    return program_policy_dir(object_path, policy_dir) / f"{sanitize_program_name(program_name)}.policy.yaml"


def live_policy_path_for_program(
    program_name: str,
    *,
    prog_id: int | None = None,
    policy_dir: Path = POLICY_DIR,
) -> Path:
    basename = sanitize_program_name(program_name)
    if prog_id is not None and int(prog_id) > 0:
        filename = f"{int(prog_id):05d}_{basename}.policy.yaml"
    else:
        filename = f"{basename}.policy.yaml"
    return live_policy_dir(policy_dir) / filename


def resolve_live_policy_path(
    *,
    program_name: str | None,
    prog_id: int | None = None,
    policy_dir: Path = POLICY_DIR,
) -> Path | None:
    if not program_name:
        return None
    if prog_id is not None and int(prog_id) > 0:
        per_id = live_policy_path_for_program(program_name, prog_id=int(prog_id), policy_dir=policy_dir)
        if per_id.exists():
            return per_id
    basename = sanitize_program_name(program_name)
    exact = live_policy_path_for_program(program_name, policy_dir=policy_dir)
    if exact.exists():
        return exact
    live_dir = live_policy_dir(policy_dir)
    if not live_dir.exists():
        return None
    matches = sorted(live_dir.glob(f"*_{basename}.policy.yaml"))
    if len(matches) == 1:
        return matches[0]
    return None


def resolve_policy_path(
    object_path: Path,
    policy_dir: Path = POLICY_DIR,
    program_name: str | None = None,
) -> Path | None:
    if not program_name:
        return None
    per_program = policy_path_for_program(object_path, program_name, policy_dir)
    if per_program.exists():
        return per_program
    return None


def canonical_policy_family_name(value: str) -> str:
    normalized = value.strip().lower().replace("_", "-")
    if normalized not in POLICY_FAMILY_ALIASES:
        raise ValueError(f"unknown policy family: {value}")
    return POLICY_FAMILY_ALIASES[normalized]


def strict_policy_family_name(value: str) -> str:
    normalized = value.strip().lower()
    if normalized not in CANONICAL_POLICY_FAMILY_SET:
        raise ValueError(f"unknown policy family: {value}")
    return normalized


def yaml_single_quoted(value: str) -> str:
    return "'" + value.replace("'", "''") + "'"


def _normalize_policy_site_v3(entry: Mapping[str, Any]) -> tuple[int, str, str]:
    for field_name in entry:
        if field_name not in {"insn", "family", "pattern_kind"}:
            raise ValueError(f"unknown policy site field: {field_name}")
    insn = int(entry.get("insn", -1))
    family = strict_policy_family_name(str(entry.get("family", "")))
    pattern_kind = str(entry.get("pattern_kind", "")).strip()
    if insn < 0:
        raise ValueError("policy site insn must be >= 0")
    if not pattern_kind:
        raise ValueError("policy site pattern_kind must be a non-empty string")
    return insn, family, pattern_kind


def policy_sites_from_manifest(
    manifest: Mapping[str, Any],
    *,
    skip_families: frozenset[str] = frozenset(),
) -> tuple[list[dict[str, Any]], dict[str, int], dict[str, int]]:
    site_counts: Counter[str] = Counter()
    skipped_site_counts: Counter[str] = Counter()
    rendered_sites: list[dict[str, Any]] = []
    raw_sites = manifest.get("sites")
    if not isinstance(raw_sites, Sequence) or isinstance(raw_sites, (str, bytes, bytearray)):
        return rendered_sites, dict(site_counts), dict(skipped_site_counts)
    for entry in raw_sites:
        if not isinstance(entry, Mapping):
            continue
        family_value = entry.get("family")
        if family_value is None:
            continue
        try:
            family = canonical_policy_family_name(str(family_value))
        except ValueError:
            continue
        site_counts[family] += 1
        if family in skip_families:
            skipped_site_counts[family] += 1
            continue
        pattern_kind = str(entry.get("pattern_kind", "")).strip()
        insn = int(entry.get("insn", entry.get("start_insn", -1)))
        if insn < 0 or not pattern_kind:
            continue
        rendered_sites.append(
            {
                "insn": insn,
                "family": family,
                "pattern_kind": pattern_kind,
            }
        )
    rendered_sites.sort(
        key=lambda item: (
            int(item["insn"]),
            POLICY_FAMILY_ORDER.get(str(item["family"]), len(POLICY_FAMILY_ORDER)),
            str(item["pattern_kind"]),
        )
    )
    return rendered_sites, dict(site_counts), dict(skipped_site_counts)


def render_manifest_policy_v3_text(
    *,
    program_name: str | None,
    manifest: Mapping[str, Any],
    comments: Iterable[str] = (),
    skip_families: frozenset[str] = frozenset(),
) -> tuple[str, dict[str, Any]]:
    sites, site_counts, skipped_site_counts = policy_sites_from_manifest(
        manifest,
        skip_families=skip_families,
    )
    explicit_family_counts: Counter[str] = Counter()
    for site in sites:
        explicit_family_counts[str(site["family"])] += 1
    rendered = render_policy_v3_text(
        program_name=program_name,
        sites=sites,
        comments=comments,
    )
    live_total_sites = int((manifest.get("summary") or {}).get("total_sites", 0) or 0)
    if live_total_sites <= 0:
        live_total_sites = sum(site_counts.values())
    return rendered, {
        "program_name": program_name,
        "live_total_sites": live_total_sites,
        "explicit_sites": len(sites),
        "family_counts": site_counts,
        "explicit_family_counts": dict(explicit_family_counts),
        "skipped_family_counts": skipped_site_counts,
    }


def render_policy_v3_text(
    *,
    program_name: str | None,
    sites: Sequence[Mapping[str, Any]] = (),
    comments: Iterable[str] = (),
) -> str:
    rendered_sites: list[tuple[int, str, str]] = []
    seen_sites: set[tuple[int, str, str]] = set()
    for raw_site in sites:
        if not isinstance(raw_site, Mapping):
            raise ValueError("policy sites entries must be mappings")
        site = _normalize_policy_site_v3(raw_site)
        if site in seen_sites:
            raise ValueError(
                "duplicate policy site entry: "
                f"{site[1]} insn {site[0]} pattern_kind {site[2]}"
            )
        seen_sites.add(site)
        rendered_sites.append(site)

    lines: list[str] = [f"# {line}" for line in comments]
    if lines:
        lines.append("")
    lines.append("version: 3")
    if program_name is not None:
        lines.append(f"program: {yaml_single_quoted(program_name)}")
    if not rendered_sites:
        lines.append("sites: []")
        lines.append("")
        return "\n".join(lines)

    lines.append("sites:")
    for insn, family, pattern_kind in rendered_sites:
        lines.append(f"  - insn: {insn}")
        lines.append(f"    family: {family}")
        lines.append(f"    pattern_kind: {yaml_single_quoted(pattern_kind)}")
    lines.append("")
    return "\n".join(lines)


def _load_policy_payload(policy: Path | str | Mapping[str, Any]) -> Mapping[str, Any]:
    try:
        if isinstance(policy, Mapping):
            return policy
        if isinstance(policy, Path):
            loaded = yaml.load(policy.read_text(), Loader=_UniqueKeyLoader)
        else:
            candidate = Path(policy)
            if "\n" not in policy and candidate.exists():
                loaded = yaml.load(candidate.read_text(), Loader=_UniqueKeyLoader)
            else:
                loaded = yaml.load(policy, Loader=_UniqueKeyLoader)
    except yaml.YAMLError as ex:
        raise ValueError(str(ex)) from ex
    if not isinstance(loaded, Mapping):
        raise ValueError("policy document must be a mapping")
    return loaded


def parse_policy_v3(policy: Path | str | Mapping[str, Any]) -> PolicyDocumentV3:
    payload = _load_policy_payload(policy)
    version = int(payload.get("version", 0) or 0)
    if version != 3:
        raise ValueError(f"expected version 3 policy, got {version}")
    for field_name in payload:
        if field_name not in {"version", "program", "sites"}:
            raise ValueError(f"unknown policy field: {field_name}")

    raw_sites = payload.get("sites")
    if raw_sites is None:
        raw_sites = []
    if not isinstance(raw_sites, list):
        raise ValueError("policy sites must be a list")

    sites: list[PolicySiteV3] = []
    seen_sites: set[tuple[int, str, str]] = set()
    for entry in raw_sites:
        if not isinstance(entry, Mapping):
            raise ValueError("policy sites entries must be mappings")
        insn, family, pattern_kind = _normalize_policy_site_v3(entry)
        site_key = (insn, family, pattern_kind)
        if site_key in seen_sites:
            raise ValueError(
                f"duplicate policy site entry: {family} insn {insn} pattern_kind {pattern_kind}"
            )
        seen_sites.add(site_key)
        sites.append(
            PolicySiteV3(
                insn=insn,
                family=family,
                pattern_kind=pattern_kind,
            )
        )

    program_value = payload.get("program")
    program = None if program_value is None else str(program_value)
    return PolicyDocumentV3(
        version=3,
        program=program,
        sites=tuple(sites),
    )


def remap_policy_v3_to_live(
    policy: Path | str | Mapping[str, Any] | PolicyDocumentV3,
    live_manifest: Mapping[str, Any],
    *,
    program_name: str | None = None,
    comments: Iterable[str] = (),
) -> tuple[str, PolicyRemapSummaryV3]:
    document = policy if isinstance(policy, PolicyDocumentV3) else parse_policy_v3(policy)
    raw_sites = live_manifest.get("sites")
    if raw_sites is None:
        raise ValueError("live manifest must contain a sites list")
    if not isinstance(raw_sites, Sequence) or isinstance(raw_sites, (str, bytes, bytearray)):
        raise ValueError("live manifest sites must be a sequence")

    live_sites_by_key: dict[tuple[str, str], list[int]] = defaultdict(list)
    live_family_counts: Counter[str] = Counter()
    live_total_sites = 0
    for entry in raw_sites:
        if not isinstance(entry, Mapping):
            continue
        family_value = entry.get("family")
        if family_value is None:
            continue
        try:
            family = canonical_policy_family_name(str(family_value))
        except ValueError:
            continue
        insn_value = entry.get("insn", entry.get("start_insn", -1))
        try:
            insn = int(insn_value)
        except (TypeError, ValueError):
            continue
        if insn < 0:
            continue
        pattern_kind = str(entry.get("pattern_kind", "")).strip()
        if not pattern_kind:
            continue
        live_sites_by_key[(family, pattern_kind)].append(insn)
        live_family_counts[family] += 1
        live_total_sites += 1

    next_live_index: dict[tuple[str, str], int] = defaultdict(int)
    remapped_sites: list[dict[str, Any]] = []
    policy_family_counts: Counter[str] = Counter()
    remapped_family_counts: Counter[str] = Counter()
    dropped_family_counts: Counter[str] = Counter()

    for site in document.sites:
        policy_family_counts[site.family] += 1
        site_key = (site.family, site.pattern_kind)
        family_sites = live_sites_by_key.get(site_key, [])
        position = next_live_index[site_key]
        if position >= len(family_sites):
            dropped_family_counts[site.family] += 1
            continue
        remapped_sites.append(
            {
                "insn": family_sites[position],
                "family": site.family,
                "pattern_kind": site.pattern_kind,
            }
        )
        next_live_index[site_key] = position + 1
        remapped_family_counts[site.family] += 1

    remap_comments = list(comments)
    remap_comments.append(
        "Remapped onto live daemon sites by family + pattern_kind order."
    )
    remap_comments.append(
        "Live site totals: "
        + ", ".join(
            f"{family}={live_family_counts.get(family, 0)}"
            for family in CANONICAL_POLICY_FAMILIES
            if family in live_family_counts
        )
        if live_family_counts
        else "Live site totals: none"
    )
    if dropped_family_counts:
        remap_comments.append(
            "Dropped explicit policy sites with no live family/pattern_kind match: "
            + ", ".join(
                f"{family}={count}" for family, count in sorted(dropped_family_counts.items())
            )
        )

    text = render_policy_v3_text(
        program_name=program_name if program_name is not None else document.program,
        sites=remapped_sites,
        comments=remap_comments,
    )
    summary = PolicyRemapSummaryV3(
        explicit_sites=len(document.sites),
        remapped_sites=len(remapped_sites),
        dropped_sites=max(0, len(document.sites) - len(remapped_sites)),
        live_total_sites=live_total_sites,
        policy_family_counts=dict(sorted(policy_family_counts.items())),
        live_family_counts=dict(sorted(live_family_counts.items())),
        remapped_family_counts=dict(sorted(remapped_family_counts.items())),
        dropped_family_counts=dict(sorted(dropped_family_counts.items())),
    )
    return text, summary


__all__ = [
    "CORPUS_DIR",
    "LIVE_POLICY_DIRNAME",
    "OBJECT_ROOT_NAMES",
    "POLICY_DIR",
    "PolicyDocumentV3",
    "PolicyRemapSummaryV3",
    "PolicySiteV3",
    "ROOT_DIR",
    "canonical_policy_family_name",
    "live_policy_dir",
    "live_policy_path_for_program",
    "object_policy_stem",
    "object_relative_path",
    "object_roots",
    "parse_policy_v3",
    "policy_sites_from_manifest",
    "policy_path_for_program",
    "program_policy_dir",
    "remap_policy_v3_to_live",
    "render_manifest_policy_v3_text",
    "render_policy_v3_text",
    "resolve_live_policy_path",
    "resolve_policy_path",
    "sanitize_program_name",
]
