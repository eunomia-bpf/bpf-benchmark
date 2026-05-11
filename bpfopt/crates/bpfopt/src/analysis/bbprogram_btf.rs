// SPDX-License-Identifier: MIT
//! BTF metadata remapping for BBProgram lowering/reporting.

use std::collections::BTreeMap;

use crate::analysis::bbprogram::BBProgram;
use crate::pass::BtfInfoRecords;

#[cfg(test)]
#[derive(Clone, Debug, Default)]
pub struct BtfRemapView {
    pub(crate) func: Vec<BtfRecordView>,
    pub(crate) line: Vec<BtfRecordView>,
}

#[cfg(test)]
#[derive(Clone, Debug)]
pub(crate) struct BtfRecordView {
    offset: u32,
    type_id: Option<u32>,
}

#[cfg(test)]
impl BtfRemapView {
    pub fn func_offsets(&self) -> Vec<u32> {
        self.func.iter().map(|record| record.offset).collect()
    }

    pub fn line_offsets(&self) -> Vec<u32> {
        self.line.iter().map(|record| record.offset).collect()
    }

    pub fn line_type_ids(&self) -> Vec<u32> {
        self.line
            .iter()
            .filter_map(|record| record.type_id)
            .collect()
    }
}

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub(crate) enum BtfRecordKind {
    Func,
    Line,
}

pub(crate) enum BtfRecordRemap {
    Keep { new_pc: usize },
    DeletedOriginalInstruction,
}

pub(crate) fn remap_btf_record_pc(
    old_to_new: &BTreeMap<usize, usize>,
    old_pc: usize,
) -> BtfRecordRemap {
    match old_to_new.get(&old_pc).copied() {
        Some(new_pc) => BtfRecordRemap::Keep { new_pc },
        None => BtfRecordRemap::DeletedOriginalInstruction,
    }
}

#[cfg(test)]
pub(crate) fn remap_btf_records_view(
    prog: &BBProgram,
    records: Option<&BtfInfoRecords>,
    kind: BtfRecordKind,
) -> anyhow::Result<Vec<BtfRecordView>> {
    let Some(records) = records else {
        return Ok(Vec::new());
    };
    if records.bytes.is_empty() {
        return Ok(Vec::new());
    }
    validate_btf_records(records)?;

    let rec_size = records.rec_size as usize;
    let old_to_new = old_pc_to_current_pc(prog)?;
    let mut out = Vec::new();
    let mut previous = None;
    for record in records.bytes.chunks(rec_size) {
        let old_pc = read_u32_field(record, 0, "insn_off")?;
        let new_pc = match remap_btf_record_pc(&old_to_new, old_pc as usize) {
            BtfRecordRemap::Keep { new_pc } => new_pc,
            BtfRecordRemap::DeletedOriginalInstruction => continue,
        };
        if previous.is_some_and(|prev| new_pc <= prev) {
            if kind == BtfRecordKind::Line && previous == Some(new_pc) {
                continue;
            }
            anyhow::bail!("BTF remap produced non-increasing insn_off");
        }
        let type_id = (rec_size >= 8)
            .then(|| read_u32_field(record, 4, "type_id"))
            .transpose()?;
        out.push(BtfRecordView {
            offset: new_pc
                .try_into()
                .map_err(|_| anyhow::anyhow!("BTF remapped insn_off does not fit u32"))?,
            type_id,
        });
        previous = Some(new_pc);
    }
    Ok(out)
}

pub(crate) fn validate_btf_records(records: &BtfInfoRecords) -> anyhow::Result<()> {
    if records.rec_size < std::mem::size_of::<u32>() as u32 {
        anyhow::bail!("BTF record size {} is too small", records.rec_size);
    }
    let rec_size = records.rec_size as usize;
    if !records.bytes.len().is_multiple_of(rec_size) {
        anyhow::bail!(
            "BTF byte length {} is not a multiple of record size {}",
            records.bytes.len(),
            records.rec_size
        );
    }
    Ok(())
}

pub(crate) fn read_u32_field(record: &[u8], offset: usize, label: &str) -> anyhow::Result<u32> {
    let bytes = record
        .get(offset..offset + 4)
        .ok_or_else(|| anyhow::anyhow!("BTF record is missing {label} field"))?;
    Ok(u32::from_le_bytes(bytes.try_into().map_err(|_| {
        anyhow::anyhow!("BTF record {label} field has invalid length")
    })?))
}

pub(crate) fn old_pc_to_current_pc(prog: &BBProgram) -> anyhow::Result<BTreeMap<usize, usize>> {
    let site_pcs = prog.current_site_pcs()?;
    let mut old_to_new = BTreeMap::new();
    for &site in prog.btf.keys() {
        let old_pc = prog.original_pc(site)?;
        if let Some(&new_pc) = site_pcs.get(&site) {
            old_to_new.insert(old_pc, new_pc);
        }
    }
    Ok(old_to_new)
}
