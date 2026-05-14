// SPDX-License-Identifier: MIT
//! BTF metadata remapping for ProgramCFG lowering/reporting.

use std::collections::BTreeMap;

use crate::analysis::bbprogram::ProgramCFG;
use crate::analysis::InsnSite;
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

#[cfg(test)]
pub(crate) fn remap_btf_records_view(
    prog: &ProgramCFG,
    records: Option<&BtfInfoRecords>,
    kind: BtfRecordKind,
) -> anyhow::Result<Vec<BtfRecordView>> {
    let Some(records) = records else {
        return Ok(Vec::new());
    };
    if records.bytes.is_empty() {
        return Ok(Vec::new());
    }

    let rec_size = records.rec_size as usize;
    let mut out = Vec::new();
    remap_btf_records(prog, records, kind, |record, new_pc| {
        let type_id = (rec_size >= 8)
            .then(|| read_u32_field(record, 4, "type_id"))
            .transpose()?;
        out.push(BtfRecordView {
            offset: new_pc,
            type_id,
        });
        Ok(())
    })?;
    Ok(out)
}

pub(crate) fn remap_btf_records<F>(
    prog: &ProgramCFG,
    records: &BtfInfoRecords,
    kind: BtfRecordKind,
    mut emit: F,
) -> anyhow::Result<()>
where
    F: FnMut(&[u8], u32) -> anyhow::Result<()>,
{
    validate_btf_records(records)?;

    let rec_size = records.rec_size as usize;
    let old_to_new = old_pc_to_current_pc(prog)?;
    let mut previous = None;
    for record in records.bytes.chunks(rec_size) {
        let old_pc = read_u32_field(record, 0, "insn_off")? as usize;
        let Some(new_pc) = old_to_new.get(&old_pc).copied() else {
            continue;
        };
        if previous.is_some_and(|prev| new_pc <= prev) {
            if kind == BtfRecordKind::Line && previous == Some(new_pc) {
                continue;
            }
            anyhow::bail!("BTF remap produced non-increasing insn_off");
        }
        emit(
            record,
            new_pc
                .try_into()
                .map_err(|_| anyhow::anyhow!("BTF remapped insn_off does not fit u32"))?,
        )?;
        previous = Some(new_pc);
    }
    Ok(())
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

pub(crate) fn old_pc_to_current_pc(prog: &ProgramCFG) -> anyhow::Result<BTreeMap<usize, usize>> {
    let site_pcs = prog.current_site_pcs()?;
    let mut old_to_new = BTreeMap::new();
    for block in prog.blocks() {
        for (idx, node) in block.insns.iter().enumerate() {
            let Some(old_pc) = node.btf_pc else { continue };
            let site = InsnSite {
                block: block.id,
                idx,
            };
            if let Some(&new_pc) = site_pcs.get(&site) {
                old_to_new.insert(old_pc, new_pc);
            }
        }
        let term_site = InsnSite {
            block: block.id,
            idx: block.insns.len(),
        };
        if let Some(old_pc) = block.terminator_btf_pc {
            if let Some(&new_pc) = site_pcs.get(&term_site) {
                old_to_new.insert(old_pc, new_pc);
            }
        }
    }
    Ok(old_to_new)
}
