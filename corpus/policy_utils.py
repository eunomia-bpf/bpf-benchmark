from __future__ import annotations

from collections import Counter, defaultdict
import re
import subprocess
from dataclasses import dataclass
from pathlib import Path
from typing import Any, Iterable, Mapping, Sequence

import yaml

ROOT_DIR = Path(__file__).resolve().parent.parent
CORPUS_DIR = ROOT_DIR / "corpus"
POLICY_DIR = CORPUS_DIR / "policies"
OBJECT_ROOT_NAMES = ("build", "expanded_corpus", "objects")
PROGRAM_SAFE_CHARS = re.compile(r"[^A-Za-z0-9._-]+")
VALID_POLICY_ACTIONS = {"apply", "skip"}
VALID_POLICY_DEFAULTS = {"apply", "skip", "stock"}
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
    "zero-ext": "zero-ext",
    "zero_ext": "zero-ext",
    "zeroext": "zero-ext",
    "zero-ext-elide": "zero-ext",
    "endian": "endian",
    "endian-fusion": "endian",
    "branch-flip": "branch-flip",
    "branch_flip": "branch-flip",
    "branchflip": "branch-flip",
    "bflip": "branch-flip",
}
CANONICAL_POLICY_FAMILIES = tuple(dict.fromkeys(POLICY_FAMILY_ALIASES.values()))
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
class PolicySiteV2:
    insn: int
    family: str
    action: str


@dataclass(frozen=True, slots=True)
class PolicyFamilyActionV2:
    family: str
    action: str


@dataclass(frozen=True, slots=True)
class PolicyDocumentV2:
    version: int
    program: str | None
    default: str
    families: tuple[PolicyFamilyActionV2, ...]
    sites: tuple[PolicySiteV2, ...]


@dataclass(frozen=True, slots=True)
class PolicyRemapSummaryV2:
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


def policy_path_for_program(
    object_path: Path,
    program_name: str,
    policy_dir: Path = POLICY_DIR,
) -> Path:
    return program_policy_dir(object_path, policy_dir) / f"{sanitize_program_name(program_name)}.policy.yaml"


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


def yaml_single_quoted(value: str) -> str:
    return "'" + value.replace("'", "''") + "'"


def _normalize_policy_families(
    families: Mapping[str, Any] | Sequence[Mapping[str, Any]],
) -> list[tuple[str, str]]:
    if isinstance(families, Mapping):
        raw_items = [
            {"family": family, "action": action}
            for family, action in families.items()
        ]
    else:
        raw_items = list(families)

    normalized: list[tuple[str, str]] = []
    seen: set[str] = set()
    for entry in raw_items:
        if not isinstance(entry, Mapping):
            raise ValueError("policy families entries must be mappings")
        family = canonical_policy_family_name(str(entry.get("family", "")))
        action = str(entry.get("action", "")).strip().lower()
        if action not in VALID_POLICY_ACTIONS:
            raise ValueError("policy family action must be 'apply' or 'skip'")
        if family in seen:
            raise ValueError(f"duplicate policy family entry: {family}")
        seen.add(family)
        normalized.append((family, action))
    normalized.sort(key=lambda item: POLICY_FAMILY_ORDER.get(item[0], len(POLICY_FAMILY_ORDER)))
    return normalized


def render_policy_v2_text(
    *,
    program_name: str | None,
    default_action: str,
    families: Mapping[str, Any] | Sequence[Mapping[str, Any]] = (),
    sites: Sequence[Mapping[str, Any]] = (),
    comments: Iterable[str] = (),
) -> str:
    normalized_default = default_action.strip().lower()
    if normalized_default not in VALID_POLICY_DEFAULTS:
        raise ValueError("policy default must be 'apply', 'skip', or 'stock'")

    rendered_families = _normalize_policy_families(families)
    rendered_sites: list[tuple[int, str, str]] = []
    for raw_site in sites:
        insn = int(raw_site.get("insn", -1))
        family = canonical_policy_family_name(str(raw_site.get("family", "")))
        action = str(raw_site.get("action", "")).strip().lower()
        if insn < 0:
            raise ValueError("policy site insn must be >= 0")
        if action not in VALID_POLICY_ACTIONS:
            raise ValueError("policy site action must be 'apply' or 'skip'")
        rendered_sites.append((insn, family, action))

    lines: list[str] = [f"# {line}" for line in comments]
    if lines:
        lines.append("")
    lines.append("version: 2")
    if program_name is not None:
        lines.append(f"program: {yaml_single_quoted(program_name)}")
    lines.append(f"default: {normalized_default}")
    if rendered_families:
        lines.append("families:")
        for family, action in rendered_families:
            lines.append(f"  {family}: {action}")
    if not rendered_sites:
        lines.append("sites: []")
        lines.append("")
        return "\n".join(lines)

    lines.append("sites:")
    for insn, family, action in rendered_sites:
        lines.append(f"  - insn: {insn}")
        lines.append(f"    family: {family}")
        lines.append(f"    action: {action}")
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


def parse_policy_v2(policy: Path | str | Mapping[str, Any]) -> PolicyDocumentV2:
    payload = _load_policy_payload(policy)
    version = int(payload.get("version", 0) or 0)
    if version != 2:
        raise ValueError(f"expected version 2 policy, got {version}")

    default = str(payload.get("default", "")).strip().lower()
    if default not in VALID_POLICY_DEFAULTS:
        raise ValueError("policy default must be 'apply', 'skip', or 'stock'")
    if default == "stock":
        default = "skip"

    raw_families = payload.get("families") or {}
    if not isinstance(raw_families, Mapping):
        raise ValueError("policy families must be a mapping")
    families = tuple(
        PolicyFamilyActionV2(family=family, action=action)
        for family, action in _normalize_policy_families(raw_families)
    )

    raw_sites = payload.get("sites")
    if raw_sites is None:
        raw_sites = []
    if not isinstance(raw_sites, list):
        raise ValueError("policy sites must be a list")

    sites: list[PolicySiteV2] = []
    seen_sites: set[tuple[int, str]] = set()
    for entry in raw_sites:
        if not isinstance(entry, Mapping):
            raise ValueError("policy sites entries must be mappings")
        insn = int(entry.get("insn", -1))
        family = canonical_policy_family_name(str(entry.get("family", "")))
        if "action" not in entry:
            raise ValueError("policy site action must be 'apply' or 'skip'")
        action = str(entry.get("action", "")).strip().lower()
        if insn < 0:
            raise ValueError("policy site insn must be >= 0")
        if action not in VALID_POLICY_ACTIONS:
            raise ValueError("policy site action must be 'apply' or 'skip'")
        site_key = (insn, family)
        if site_key in seen_sites:
            raise ValueError(f"duplicate policy site entry: {family} insn {insn}")
        seen_sites.add(site_key)
        sites.append(PolicySiteV2(insn=insn, family=family, action=action))

    program_value = payload.get("program")
    program = None if program_value is None else str(program_value)
    return PolicyDocumentV2(
        version=2,
        program=program,
        default=default,
        families=families,
        sites=tuple(sites),
    )


def remap_policy_v2_to_live(
    policy: Path | str | Mapping[str, Any] | PolicyDocumentV2,
    live_manifest: Mapping[str, Any],
    *,
    program_name: str | None = None,
    comments: Iterable[str] = (),
) -> tuple[str, PolicyRemapSummaryV2]:
    document = policy if isinstance(policy, PolicyDocumentV2) else parse_policy_v2(policy)
    raw_sites = live_manifest.get("sites")
    if raw_sites is None:
        raise ValueError("live manifest must contain a sites list")
    if not isinstance(raw_sites, Sequence) or isinstance(raw_sites, (str, bytes, bytearray)):
        raise ValueError("live manifest sites must be a sequence")

    live_sites_by_family: dict[str, list[int]] = defaultdict(list)
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
        live_sites_by_family[family].append(insn)
        live_family_counts[family] += 1
        live_total_sites += 1

    for insns in live_sites_by_family.values():
        insns.sort()

    next_live_index: dict[str, int] = defaultdict(int)
    remapped_sites: list[dict[str, Any]] = []
    policy_family_counts: Counter[str] = Counter()
    remapped_family_counts: Counter[str] = Counter()
    dropped_family_counts: Counter[str] = Counter()

    for site in document.sites:
        policy_family_counts[site.family] += 1
        family_sites = live_sites_by_family.get(site.family, [])
        position = next_live_index[site.family]
        if position >= len(family_sites):
            dropped_family_counts[site.family] += 1
            continue
        remapped_sites.append(
            {
                "insn": family_sites[position],
                "family": site.family,
                "action": site.action,
            }
        )
        next_live_index[site.family] = position + 1
        remapped_family_counts[site.family] += 1

    remap_comments = list(comments)
    remap_comments.append("Remapped onto live scanner sites by family order.")
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
            "Dropped explicit policy sites with no live family match: "
            + ", ".join(
                f"{family}={count}" for family, count in sorted(dropped_family_counts.items())
            )
        )

    text = render_policy_v2_text(
        program_name=program_name if program_name is not None else document.program,
        default_action=document.default,
        families=[
            {"family": family_action.family, "action": family_action.action}
            for family_action in document.families
        ],
        sites=remapped_sites,
        comments=remap_comments,
    )
    summary = PolicyRemapSummaryV2(
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


def generate_default_policy_v2(
    scanner_binary: Path | str,
    object_path: Path | str,
    *,
    program_name: str | None = None,
    default: str = "skip",
    output_path: Path | str | None = None,
    timeout_seconds: int = 60,
) -> str:
    normalized_default = default.strip().lower()
    if normalized_default not in VALID_POLICY_ACTIONS:
        raise ValueError("default must be 'apply' or 'skip'")

    command = [
        str(Path(scanner_binary).resolve()),
        "generate-policy",
        str(Path(object_path).resolve()),
        "--default",
        normalized_default,
    ]
    if program_name:
        command.extend(["--program-name", program_name])
    if output_path is not None:
        resolved_output = Path(output_path).resolve()
        resolved_output.parent.mkdir(parents=True, exist_ok=True)
        command.extend(["--output", str(resolved_output)])

    completed = subprocess.run(
        command,
        cwd=ROOT_DIR,
        capture_output=True,
        text=True,
        check=False,
        timeout=timeout_seconds,
    )
    if completed.returncode != 0:
        message = (completed.stderr or completed.stdout).strip()
        raise RuntimeError(message or "scanner generate-policy failed")

    if output_path is not None:
        return Path(output_path).resolve().read_text()
    return completed.stdout


__all__ = [
    "CORPUS_DIR",
    "OBJECT_ROOT_NAMES",
    "POLICY_DIR",
    "PolicyDocumentV2",
    "PolicyFamilyActionV2",
    "PolicyRemapSummaryV2",
    "PolicySiteV2",
    "ROOT_DIR",
    "canonical_policy_family_name",
    "generate_default_policy_v2",
    "object_policy_stem",
    "object_relative_path",
    "object_roots",
    "parse_policy_v2",
    "policy_path_for_program",
    "program_policy_dir",
    "remap_policy_v2_to_live",
    "render_policy_v2_text",
    "resolve_policy_path",
    "sanitize_program_name",
]
