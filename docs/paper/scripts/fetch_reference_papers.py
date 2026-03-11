#!/usr/bin/env python3
from __future__ import annotations

import csv
import json
import pathlib
import re
import time
from dataclasses import dataclass
from difflib import SequenceMatcher
from typing import Iterable
from urllib.parse import quote_plus, urljoin, urlparse

import requests
import urllib3
from bs4 import BeautifulSoup


REPO_ROOT = pathlib.Path(__file__).resolve().parents[3]
PLAN_PATH = REPO_ROOT / "docs" / "ebpf-bench-research-plan.md"
OUT_DIR = REPO_ROOT / "reference" / "papers"
PCHAIGNO_URL = "https://pchaigno.github.io/bpf/2025/01/07/research-papers-bpf.html"
USER_AGENT = (
    "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 "
    "(KHTML, like Gecko) Chrome/123.0.0.0 Safari/537.36"
)
TIMEOUT = 30
REQUEST_SLEEP = 0.2

urllib3.disable_warnings(urllib3.exceptions.InsecureRequestWarning)

# The plan uses many shorthand names. These map to the exact paper titles used
# by pchaigno's index page so we can reuse its direct PDF links when available.
PCHAIGNO_TITLE_OVERRIDES = {
    "Jitterbug": (
        "Specification and Verification in the Field: Applying Formal Methods "
        "to BPF Just-in-Time Compilers in the Linux Kernel"
    ),
    "End-to-End Mechanized Proof of eBPF VM for IoT": (
        "End-to-End Mechanized Proof of a JIT-Accelerated eBPF Virtual Machine for IoT"
    ),
    "eBPF Program Warping on FPGA": (
        "Faster Software Packet Processing on FPGA NICs with eBPF Program Warping"
    ),
    "K2": "Synthesizing Safe and Efficient Kernel Extensions for Packet Processing",
    "DSRO: Domain-Specific Run Time Optimization": (
        "Domain Specific Run Time Optimization for Software Data Planes"
    ),
    "SoK: Memory Safety for eBPF": (
        "SoK: Challenges and Paths Toward Memory Safety for eBPF"
    ),
    "VEP": "VEP: A Two-stage Verification Toolchain for Full eBPF Programmability",
    "BeeBox": "BeeBox: Hardening BPF Against Transient Execution Attacks",
    "Toss a Fault to BpfChecker": (
        "Toss a Fault to BpfChecker: Revealing Implementation Flaws for eBPF runtimes "
        "with Differential Fuzzing"
    ),
    "NetEdit": "NetEdit: An Orchestration Platform for eBPF Network Functions at Scale",
    "Electrode": "Electrode: Accelerating Distributed Protocols with eBPF",
    "DINT": "DINT: Fast In-Kernel Distributed Transactions with eBPF",
    "SPRIGHT": (
        "SPRIGHT: Extracting the Server from Serverless Computing! High-Performance "
        "eBPF-Based Event-Driven, Shared-Memory Processing"
    ),
    "Hermes": (
        "Hermes: Enhancing Layer-7 Cloud Load Balancers with "
        "Userspace-Directed I/O Event Notification"
    ),
    "Tigger": "Tigger: A Database Proxy That Bounces with User-Bypass",
    "bpftime (EIM)": "Extending Applications Safely and Efficiently",
    "cache_ext": "cache_ext: Customizing the Page Cache with eBPF",
    "PageFlex": (
        "PageFlex: Flexible and Efficient User-space Delegation of Linux Paging Policies "
        "with eBPF"
    ),
    "FetchBPF": "FetchBPF: Customizable Prefetching Policies in Linux with eBPF",
    "XRP": "XRP: In-Kernel Storage Functions with eBPF",
    "Syrup": "Syrup: User-Defined Scheduling Across the Stack",
    "MOAT": "MOAT: Towards Safe BPF Kernel Extension",
    "Hive": "Hive: A Hardware-assisted Isolated Execution Environment for eBPF on AArch64",
    "PREVAIL": "Simple and Precise Static Analysis of Untrusted Linux Kernel Extensions",
    "Agni": "Verifying the Verifier: eBPF Range Analysis Verification",
    "Validating eBPF Verifier via State Embedding": (
        "Validating the eBPF Verifier via State Embedding"
    ),
    "Fast, Flexible, and Practical Kernel Extensions": (
        "Fast, Flexible, and Practical Kernel Extensions"
    ),
    "Rex": "Rex: Closing the language-verifier gap with safe and usable kernel extensions",
    "eTran": "eTran: Extensible Kernel Transport with eBPF",
    "State-Compute Replication": (
        "State-Compute Replication: Parallelizing High-Speed Stateful Packet Processing"
    ),
    "eHDL: Turning eBPF/XDP Programs into Hardware Designs": (
        "eHDL: Turning eBPF/XDP Programs into Hardware Designs for the NIC"
    ),
}

# Extra search queries for items not covered well by exact-title search.
QUERY_OVERRIDES = {
    "KFuse": ["KFuse eBPF EuroSys 2022"],
    "EPSO": ["EPSO eBPF ASE 2025 superoptimizer"],
    "BCF (Prove It to the Kernel)": ["Prove It to the Kernel eBPF SOSP 2025"],
    "VeriFence": ["VeriFence eBPF RAID 2024"],
    "Flow Hijacking in eBPF": ["Flow Hijacking in eBPF IJIS 2025"],
    "BPFGuard": ["BPFGuard eBPF IEEE TCC 2025"],
    "Enabling eBPF on Embedded Systems Through Decoupled Verification": [
        "Enabling eBPF on Embedded Systems Through Decoupled Verification"
    ],
    "Demystifying Performance of eBPF Network Applications": [
        "Demystifying Performance of eBPF Network Applications CoNEXT 2025"
    ],
    "eNetSTL": ["eNetSTL EuroSys 2025 eBPF"],
    "uXDP": ["uXDP: Frictionless XDP Deployments in Userspace"],
    "X2DP": ["X2DP eBPF SIGCOMM 2025 poster"],
    "InXpect": ["InXpect Lightweight XDP Profiling"],
    "AF_XDP + Programmable NICs": ["AF_XDP and Programmable NICs eBPF Workshop 2025"],
    "BPF-DB": ["BPF-DB SIGMOD 2025 kernel embedded transactional database"],
    "DepSurf": ["DepSurf EuroSys 2025 eBPF"],
    "gpu_ext": ["gpu_ext eBPF arXiv 2025"],
    "Pairwise BPF Programs Should Be Optimized Together": [
        "Pairwise BPF Programs Should Be Optimized Together"
    ],
    "Kernel Extension DSLs Should Be Verifier-Safe": [
        "Kernel Extension DSLs Should Be Verifier-Safe"
    ],
    "Automatic Synthesis of Abstract Operators for eBPF": [
        "Automatic Synthesis of Abstract Operators for eBPF"
    ],
    "No Two Snowflakes Are Alike": [
        "No Two Snowflakes Are Alike Studying eBPF Libraries Performance Fidelity Resource Usage"
    ],
    "SchedBPF: Scheduling BPF programs": ["SchedBPF Scheduling BPF programs"],
    "A Memory Pool Allocator for eBPF Applications": [
        "A Memory Pool Allocator for eBPF Applications"
    ],
    "eBPFML": ["eBPFML workshop 2025"],
    "ChainIO": ["ChainIO eBPF workshop 2025"],
    "Evaluation of tail call costs": ["Evaluation of tail call costs Cloudflare LPC 2020"],
    "Understanding performance of eBPF-based applications": [
        "Understanding performance of eBPF-based applications ETH Zurich"
    ],
    "Towards eBPF Overhead Quantification": ["Towards eBPF Overhead Quantification ICPE 2025"],
    "FOSDEM 2025: Performance evaluation of eBPF verifier": [
        "Performance evaluation of eBPF verifier FOSDEM 2025"
    ],
    "Benchmarking DTrace vs eBPF": ["Benchmarking DTrace vs eBPF AsiaBSDCon 2024"],
    "eBPF-Based Instrumentation for Degradation Diagnosis": [
        "eBPF-Based Instrumentation for Degradation Diagnosis"
    ],
}

DIRECT_URL_OVERRIDES = {
    "DSRO: Domain-Specific Run Time Optimization": (
        "https://sebymiano.github.io/publication/2022-morpheus/2022-morpheus_final.pdf"
    ),
    "SoK: Memory Safety for eBPF": "https://www.cs.ucr.edu/~trentj/papers/huang25oakland.pdf",
    "eBPF Misbehavior Detection": (
        "https://cs.uwaterloo.ca/~m285xu/assets/publication/ebpf_smt_fuzz-paper.pdf"
    ),
    "BCF (Prove It to the Kernel)": "https://haosun.info/assets/pdf/BCF.pdf",
    "Toss a Fault to BpfChecker": "https://www.yajin.org/papers/CCS2024_BpfChecker.pdf",
    "SafeBPF": "https://tfjmp.org/publications/2024-ccsw.pdf",
    "Demystifying Performance of eBPF Network Applications": (
        "https://cs.nyu.edu/~apanda/assets/papers/conext25.pdf"
    ),
    "eNetSTL": "https://snowzjx.me/assets/enetstl-eurosys25.pdf",
    "uXDP": "https://marioskogias.github.io/docs/uxdp.pdf",
    "AF_XDP + Programmable NICs": "https://cs.nyu.edu/~apanda/assets/papers/ebpf25.pdf",
    "BPF-DB": "https://db.cs.cmu.edu/papers/2025/butrovich-sigmod2025.pdf",
    "DepSurf": "https://depsurf.github.io/assets/paper.pdf",
    "Kernel Extension DSLs Should Be Verifier-Safe": (
        "https://cs.brown.edu/people/acrotty/pubs/3748355.3748368.pdf"
    ),
    "Automatic Synthesis of Abstract Operators for eBPF": (
        "https://people.cs.rutgers.edu/~sn349/papers/vayu-ebpf-2025.pdf"
    ),
    "No Two Snowflakes Are Alike": (
        "https://dsr-haslab.github.io/assets/files/2025/snowflakes-ebpf25-cmachado.pdf"
    ),
    "A Memory Pool Allocator for eBPF Applications": (
        "https://gyuyeongkim.github.io/papers/kerby_ebpf25.pdf"
    ),
    "Evaluation of tail call costs": (
        "https://lpc.events/event/7/contributions/676/attachments/512/1000/paper.pdf"
    ),
    "Understanding performance of eBPF-based applications": (
        "https://nsg.ee.ethz.ch/files/public/theses/2024-benchmarking_ebpf_programs/thesis-1.pdf"
    ),
    "FOSDEM 2025: Performance evaluation of eBPF verifier": (
        "https://archive.fosdem.org/2025/events/attachments/"
        "fosdem-2025-6453-performance-evaluation-of-the-linux-kernel-ebpf-verifier/"
        "slides/238217/eBPF_fosd_bqqGJyz.pdf"
    ),
}


@dataclass
class Paper:
    title: str
    venue: str
    year: int | None


def session() -> requests.Session:
    sess = requests.Session()
    sess.headers.update({"User-Agent": USER_AGENT})
    sess.verify = False
    return sess


def normalize_title(title: str) -> str:
    return re.sub(r"[^a-z0-9]+", "", title.lower())


def clean_url(url: str) -> str:
    return url.replace("\\", "")


def title_score(a: str, b: str) -> float:
    a_norm = normalize_title(a)
    b_norm = normalize_title(b)
    if not a_norm or not b_norm:
        return 0.0
    if a_norm == b_norm:
        return 1.0
    if a_norm in b_norm or b_norm in a_norm:
        return 0.94
    return SequenceMatcher(None, a.lower(), b.lower()).ratio()


def slugify(title: str) -> str:
    slug = re.sub(r"[^a-z0-9]+", "-", title.lower()).strip("-")
    return slug or "paper"


def parse_year(venue: str) -> int | None:
    match = re.search(r"'(\d{2})", venue)
    if not match:
        return None
    year = int(match.group(1))
    return 2000 + year if year < 70 else 1900 + year


def parse_plan_papers(plan_path: pathlib.Path) -> list[Paper]:
    text = plan_path.read_text()
    section_match = re.search(
        r"## 二、学术界已经做了什么（按主题分类）\n(.*?)\n---\n\n## 三、",
        text,
        re.S,
    )
    if not section_match:
        raise RuntimeError("failed to locate paper table section in research plan")

    seen: set[str] = set()
    papers: list[Paper] = []
    for line in section_match.group(1).splitlines():
        match = re.match(r"\|\s*\*\*(.+?)\*\*\s*\|\s*([^|]+?)\s*\|", line)
        if not match:
            continue
        title = match.group(1).strip()
        if title in seen:
            continue
        seen.add(title)
        papers.append(Paper(title=title, venue=match.group(2).strip(), year=parse_year(match.group(2))))
    return papers


def build_pchaigno_index(sess: requests.Session) -> dict[str, dict[str, str]]:
    response = sess.get(PCHAIGNO_URL, timeout=TIMEOUT)
    response.raise_for_status()
    soup = BeautifulSoup(response.text, "html.parser")

    index: dict[str, dict[str, str]] = {}
    for heading in soup.find_all("h4"):
        title = heading.get_text(" ", strip=True)
        paper_link = None
        venue = None
        for sibling in heading.next_siblings:
            name = getattr(sibling, "name", None)
            if name == "span" and venue is None:
                venue = sibling.get_text(" ", strip=True)
            if name == "a" and sibling.get_text(" ", strip=True) == "Paper":
                paper_link = sibling.get("href")
            if name == "br":
                break
        if paper_link:
            index[title] = {"url": paper_link, "venue": venue or ""}
    return index


def preferred_urls_from_openalex(result: dict) -> list[str]:
    urls: list[str] = []
    for location in result.get("locations", []):
        for key in ("pdf_url", "landing_page_url"):
            value = location.get(key)
            if value and value not in urls:
                urls.append(value)
    for key in ("best_oa_location", "primary_location"):
        location = result.get(key) or {}
        for inner_key in ("pdf_url", "landing_page_url"):
            value = location.get(inner_key)
            if value and value not in urls:
                urls.append(value)
    oa_url = (result.get("open_access") or {}).get("oa_url")
    if oa_url and oa_url not in urls:
        urls.append(oa_url)

    def rank(url: str) -> tuple[int, str]:
        host = urlparse(url).netloc.lower()
        if "arxiv.org" in host:
            return (0, url)
        if any(token in host for token in ("usenix.org", "springer.com", "sigcomm.org", "vtechworks.lib.vt.edu", "nebelwelt.net", "seahorn.github.io")):
            return (1, url)
        if host.endswith(".edu") or host.endswith(".org"):
            return (2, url)
        if "hdl.handle.net" in host:
            return (3, url)
        if "dl.acm.org" in host:
            return (9, url)
        return (5, url)

    return sorted(urls, key=rank)


def search_openalex(sess: requests.Session, paper: Paper, queries: Iterable[str]) -> list[dict]:
    candidates: list[dict] = []
    seen_titles: set[str] = set()
    for query in queries:
        response = sess.get(
            "https://api.openalex.org/works",
            params={"search": query, "per-page": 8},
            timeout=TIMEOUT,
        )
        response.raise_for_status()
        for result in response.json().get("results", []):
            display_name = result.get("display_name") or ""
            if not display_name or display_name in seen_titles:
                continue
            score = max(title_score(paper.title, display_name), title_score(query, display_name))
            if paper.year and result.get("publication_year") == paper.year:
                score += 0.04
            if score < 0.62:
                continue
            seen_titles.add(display_name)
            candidates.append(
                {
                    "score": score,
                    "display_name": display_name,
                    "publication_year": result.get("publication_year"),
                    "urls": preferred_urls_from_openalex(result),
                }
            )
        time.sleep(REQUEST_SLEEP)
    return sorted(candidates, key=lambda item: item["score"], reverse=True)


def extract_pdf_url_from_html(page_url: str, html: str) -> str | None:
    soup = BeautifulSoup(html, "html.parser")

    for meta_name in ("citation_pdf_url", "dc.identifier", "dc.identifier.uri"):
        meta = soup.find("meta", attrs={"name": meta_name})
        if meta and meta.get("content"):
            candidate = meta["content"].strip()
            if candidate.lower().endswith(".pdf") or "pdf" in candidate.lower():
                return urljoin(page_url, candidate)

    for meta_prop in ("og:pdf", "og:pdf_url"):
        meta = soup.find("meta", attrs={"property": meta_prop})
        if meta and meta.get("content"):
            return urljoin(page_url, meta["content"].strip())

    for link in soup.find_all("a", href=True):
        href = urljoin(page_url, link["href"])
        text = link.get_text(" ", strip=True).lower()
        href_lower = href.lower()
        if href_lower.endswith(".pdf"):
            return href
        if "download" in text and "pdf" in text:
            return href
        if "bitstreams" in href_lower and "download" in href_lower:
            return href
        if "pdf" in href_lower and "doi.org" not in href_lower:
            return href

    iframe = soup.find("iframe", src=True)
    if iframe and iframe["src"].lower().endswith(".pdf"):
        return urljoin(page_url, iframe["src"])

    return None


def resolve_pdf_url(sess: requests.Session, url: str) -> str | None:
    url = clean_url(url)
    parsed = urlparse(url)
    if "arxiv.org" in parsed.netloc and "/abs/" in parsed.path:
        paper_id = parsed.path.split("/abs/", 1)[1]
        return f"https://arxiv.org/pdf/{paper_id}.pdf"
    if url.lower().endswith(".pdf"):
        return url

    try:
        response = sess.get(url, timeout=TIMEOUT, allow_redirects=True)
    except requests.RequestException:
        return None

    content_type = response.headers.get("content-type", "").lower()
    if "application/pdf" in content_type:
        return response.url
    if response.status_code >= 400:
        return None

    return extract_pdf_url_from_html(response.url, response.text)


def download_pdf(sess: requests.Session, url: str, destination: pathlib.Path) -> tuple[bool, str]:
    url = clean_url(url)
    try:
        response = sess.get(url, timeout=TIMEOUT, allow_redirects=True)
        response.raise_for_status()
    except requests.RequestException as exc:
        return False, f"request failed: {exc}"

    content_type = response.headers.get("content-type", "").lower()
    body = response.content
    if "application/pdf" not in content_type and not body.startswith(b"%PDF"):
        return False, f"not a PDF ({content_type or 'unknown content-type'})"

    destination.write_bytes(body)
    return True, response.url


def build_query_list(paper: Paper) -> list[str]:
    queries: list[str] = []
    override_title = PCHAIGNO_TITLE_OVERRIDES.get(paper.title)
    if override_title:
        queries.append(override_title)
    queries.append(paper.title)
    queries.extend(QUERY_OVERRIDES.get(paper.title, []))
    deduped: list[str] = []
    seen: set[str] = set()
    for query in queries:
        if query not in seen:
            deduped.append(query)
            seen.add(query)
    return deduped


def main() -> int:
    OUT_DIR.mkdir(parents=True, exist_ok=True)
    sess = session()
    papers = parse_plan_papers(PLAN_PATH)
    pchaigno_index = build_pchaigno_index(sess)

    manifest: list[dict[str, object]] = []
    for index, paper in enumerate(papers, start=1):
        queries = build_query_list(paper)
        filename = f"{index:02d}-{slugify(paper.title)}.pdf"
        destination = OUT_DIR / filename

        attempts: list[dict[str, str]] = []
        resolved_url = None
        matched_title = None
        source = None
        note = ""

        pchaigno_title = PCHAIGNO_TITLE_OVERRIDES.get(paper.title, paper.title)
        pchaigno_entry = pchaigno_index.get(pchaigno_title)
        source_urls: list[tuple[str, str, str | None]] = []
        direct_url = DIRECT_URL_OVERRIDES.get(paper.title)
        if direct_url:
            source_urls.append(("manual", direct_url, paper.title))
        if pchaigno_entry:
            source_urls.append(("pchaigno", pchaigno_entry["url"], pchaigno_title))

        for candidate in search_openalex(sess, paper, queries):
            for candidate_url in candidate["urls"]:
                source_urls.append(("openalex", candidate_url, candidate["display_name"]))

        seen_source_urls: set[str] = set()
        for candidate_source, candidate_url, candidate_title in source_urls:
            if candidate_url in seen_source_urls:
                continue
            seen_source_urls.add(candidate_url)
            pdf_url = resolve_pdf_url(sess, candidate_url)
            attempts.append(
                {
                    "source": candidate_source,
                    "candidate_url": candidate_url,
                    "resolved_pdf_url": pdf_url or "",
                }
            )
            if not pdf_url:
                continue
            ok, info = download_pdf(sess, pdf_url, destination)
            if ok:
                resolved_url = info
                matched_title = candidate_title or paper.title
                source = candidate_source
                note = ""
                break
            note = info
            time.sleep(REQUEST_SLEEP)

        status = "downloaded" if resolved_url else "missing"
        manifest.append(
            {
                "title": paper.title,
                "matched_title": matched_title or "",
                "venue": paper.venue,
                "year": paper.year or "",
                "status": status,
                "file": str(destination.relative_to(REPO_ROOT)) if resolved_url else "",
                "source": source or "",
                "resolved_url": resolved_url or "",
                "queries": queries,
                "attempts": attempts,
                "note": note,
            }
        )
        print(f"[{index:02d}/{len(papers)}] {paper.title}: {status}")

    manifest_json = OUT_DIR / "manifest.json"
    manifest_csv = OUT_DIR / "manifest.csv"
    missing_txt = OUT_DIR / "missing.txt"

    manifest_json.write_text(json.dumps(manifest, indent=2, ensure_ascii=False) + "\n")
    with manifest_csv.open("w", newline="") as handle:
        writer = csv.DictWriter(
            handle,
            fieldnames=[
                "title",
                "matched_title",
                "venue",
                "year",
                "status",
                "file",
                "source",
                "resolved_url",
                "note",
            ],
        )
        writer.writeheader()
        for row in manifest:
            writer.writerow({key: row[key] for key in writer.fieldnames})

    missing_titles = [row["title"] for row in manifest if row["status"] != "downloaded"]
    missing_txt.write_text("".join(f"{title}\n" for title in missing_titles))

    downloaded = sum(1 for row in manifest if row["status"] == "downloaded")
    print(f"\nDownloaded {downloaded}/{len(manifest)} papers into {OUT_DIR.relative_to(REPO_ROOT)}")
    if missing_titles:
        print("Missing:")
        for title in missing_titles:
            print(f"  - {title}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
