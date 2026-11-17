#!/usr/bin/env python3
"""Make the existing CLI link body callable from its Cargo unit executable."""
from pathlib import Path
p=Path('kprog/x86/native_lab/native_link/src/main.rs');s=p.read_text()
old='''fn main() -> Result<()> {
    let args = Args::parse();'''
new='''fn main() -> Result<()> {
    link(Args::parse())
}

fn link(args: Args) -> Result<()> {'''
assert s.count(old)==1;s=s.replace(old,new)
old='''mod tests {
    use super::*;
'''
new='''mod tests {
    use super::*;

    #[test]
    #[ignore = "requires a captured CLI argument file"]
    fn replay_captured_link_request() -> Result<()> {
        let path=std::env::var("NATIVE_LINK_CAPTURE_ARGV")?;
        let argv:Vec<String>=serde_json::from_slice(&fs::read(path)?)?;
        link(Args::try_parse_from(argv)?)
    }
'''
assert s.count(old)==1;s=s.replace(old,new);p.write_text(s)
