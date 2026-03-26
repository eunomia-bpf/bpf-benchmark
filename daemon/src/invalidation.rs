// SPDX-License-Identifier: MIT
//! Dynamic map invalidation tracking for specialized map-inline sites.
#![cfg_attr(not(test), allow(dead_code))]

use anyhow::Result;
use std::collections::{BTreeMap, BTreeSet, HashMap, HashSet};
use std::os::unix::io::{AsRawFd, OwnedFd};

use crate::bpf;

/// A single map-inline dependency recorded for one specialized program.
#[derive(Clone, Debug, PartialEq, Eq)]
pub struct TrackedInlineSite {
    pub prog_id: u32,
    pub map_fd: u32,
    pub key: Vec<u8>,
    pub expected_value: Vec<u8>,
}

/// One key/value result returned by a batched map lookup.
#[derive(Clone, Debug, PartialEq, Eq)]
pub struct BatchLookupValue {
    pub key: Vec<u8>,
    pub value: Option<Vec<u8>>,
}

/// Abstract map access used by the invalidation tracker.
///
/// Tests inject a fake implementation; production wiring can provide a real
/// BPF-backed adapter later.
pub trait MapValueReader {
    fn lookup_values_batch(&self, map_fd: u32, keys: &[Vec<u8>]) -> Result<Vec<BatchLookupValue>>;
}

/// Production map reader backed by live BPF map file descriptors.
#[derive(Clone, Copy, Debug, Default)]
pub struct BpfMapValueReader;

impl MapValueReader for BpfMapValueReader {
    fn lookup_values_batch(&self, map_fd: u32, keys: &[Vec<u8>]) -> Result<Vec<BatchLookupValue>> {
        let info = bpf::bpf_map_get_info(map_fd as i32)?;
        let value_size = info.value_size as usize;

        keys.iter()
            .cloned()
            .map(|key| {
                let value = bpf::bpf_map_lookup_elem_optional(map_fd as i32, &key, value_size)?;
                Ok(BatchLookupValue { key, value })
            })
            .collect()
    }
}

/// Tracks inline dependencies and polls their backing maps for changes.
pub struct MapInvalidationTracker<A> {
    map_reader: A,
    entries: Vec<TrackedInlineSite>,
    owned_map_fds: HashMap<u32, OwnedFd>,
}

impl<A> MapInvalidationTracker<A> {
    pub fn new(map_reader: A) -> Self {
        Self {
            map_reader,
            entries: Vec::new(),
            owned_map_fds: HashMap::new(),
        }
    }

    pub fn is_empty(&self) -> bool {
        self.entries.is_empty()
    }

    pub fn entry_count(&self) -> usize {
        self.entries.len()
    }

    pub fn tracks_prog(&self, prog_id: u32) -> bool {
        self.entries.iter().any(|entry| entry.prog_id == prog_id)
    }

    pub fn remember_map_fd(&mut self, fd: OwnedFd) -> u32 {
        let raw_fd = fd.as_raw_fd() as u32;
        self.owned_map_fds.insert(raw_fd, fd);
        raw_fd
    }

    fn prune_owned_map_fds(&mut self) {
        let live_fds: HashSet<u32> = self.entries.iter().map(|entry| entry.map_fd).collect();
        self.owned_map_fds
            .retain(|map_fd, _| live_fds.contains(map_fd));
    }

    pub fn record_inline_site(
        &mut self,
        prog_id: u32,
        map_fd: u32,
        key: Vec<u8>,
        expected_value: Vec<u8>,
    ) {
        if let Some(entry) = self
            .entries
            .iter_mut()
            .find(|entry| entry.prog_id == prog_id && entry.map_fd == map_fd && entry.key == key)
        {
            entry.expected_value = expected_value;
            return;
        }

        self.entries.push(TrackedInlineSite {
            prog_id,
            map_fd,
            key,
            expected_value,
        });
    }

    pub fn remove_prog(&mut self, prog_id: u32) {
        self.entries.retain(|entry| entry.prog_id != prog_id);
        self.prune_owned_map_fds();
    }
}

impl<A: MapValueReader> MapInvalidationTracker<A> {
    pub fn check_all<R: MapValueReader + ?Sized>(&self, reader: &R) -> Result<Vec<u32>> {
        if self.entries.is_empty() {
            return Ok(Vec::new());
        }

        let mut keys_by_map: BTreeMap<u32, BTreeSet<Vec<u8>>> = BTreeMap::new();
        for entry in &self.entries {
            keys_by_map
                .entry(entry.map_fd)
                .or_default()
                .insert(entry.key.clone());
        }

        let mut values_by_map: BTreeMap<u32, BTreeMap<Vec<u8>, Option<Vec<u8>>>> = BTreeMap::new();
        for (map_fd, key_set) in keys_by_map {
            let keys: Vec<Vec<u8>> = key_set.into_iter().collect();
            let batch = reader.lookup_values_batch(map_fd, &keys)?;
            let mut lookup_values = BTreeMap::new();
            for lookup in batch {
                lookup_values.insert(lookup.key, lookup.value);
            }
            values_by_map.insert(map_fd, lookup_values);
        }

        let mut invalidated = BTreeSet::new();
        for entry in &self.entries {
            let current_value = values_by_map
                .get(&entry.map_fd)
                .and_then(|map_values| map_values.get(&entry.key))
                .and_then(|value| value.as_ref());
            if current_value != Some(&entry.expected_value) {
                invalidated.insert(entry.prog_id);
            }
        }

        Ok(invalidated.into_iter().collect())
    }

    pub fn check_for_invalidations(&self) -> Result<Vec<u32>> {
        self.check_all(&self.map_reader)
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::cell::RefCell;
    use std::collections::{HashMap, HashSet};
    use std::rc::Rc;

    #[derive(Clone, Debug, Default)]
    struct MockMapValueReader {
        state: Rc<RefCell<MockMapValueReaderState>>,
    }

    #[derive(Debug, Default)]
    struct MockMapValueReaderState {
        values: HashMap<u32, HashMap<Vec<u8>, Vec<u8>>>,
        batch_calls: Vec<(u32, usize)>,
    }

    type FakeMapAccessor = MockMapValueReader;

    impl MockMapValueReader {
        fn set_value(&self, map_fd: u32, key: Vec<u8>, value: Vec<u8>) {
            let mut state = self.state.borrow_mut();
            state.values.entry(map_fd).or_default().insert(key, value);
        }

        fn batch_call_count(&self) -> usize {
            self.state.borrow().batch_calls.len()
        }

        fn batch_calls(&self) -> Vec<(u32, usize)> {
            self.state.borrow().batch_calls.clone()
        }
    }

    impl MapValueReader for MockMapValueReader {
        fn lookup_values_batch(
            &self,
            map_fd: u32,
            keys: &[Vec<u8>],
        ) -> Result<Vec<BatchLookupValue>> {
            let mut state = self.state.borrow_mut();
            state.batch_calls.push((map_fd, keys.len()));

            let map_values = state.values.get(&map_fd).cloned().unwrap_or_default();
            Ok(keys
                .iter()
                .cloned()
                .map(|key| BatchLookupValue {
                    value: map_values.get(&key).cloned(),
                    key,
                })
                .collect())
        }
    }

    fn key(n: u32) -> Vec<u8> {
        n.to_le_bytes().to_vec()
    }

    fn value(n: u32) -> Vec<u8> {
        n.to_le_bytes().to_vec()
    }

    fn invalidated_set(prog_ids: Vec<u32>) -> HashSet<u32> {
        prog_ids.into_iter().collect()
    }

    #[test]
    fn test_tracker_empty() {
        let tracker = MapInvalidationTracker::new(FakeMapAccessor::default());

        assert!(tracker.is_empty());
        assert_eq!(tracker.entry_count(), 0);
    }

    #[test]
    fn test_record_inline_site() {
        let mut tracker = MapInvalidationTracker::new(FakeMapAccessor::default());

        tracker.record_inline_site(101, 7, key(1), value(11));

        assert_eq!(tracker.entry_count(), 1);
        assert_eq!(
            tracker.entries[0],
            TrackedInlineSite {
                prog_id: 101,
                map_fd: 7,
                key: key(1),
                expected_value: value(11),
            }
        );
    }

    #[test]
    fn test_record_multiple_sites() {
        let mut tracker = MapInvalidationTracker::new(FakeMapAccessor::default());

        tracker.record_inline_site(101, 7, key(1), value(11));
        tracker.record_inline_site(101, 7, key(2), value(12));
        tracker.record_inline_site(202, 8, key(1), value(21));

        assert_eq!(tracker.entry_count(), 3);
    }

    #[test]
    fn test_check_unchanged_returns_empty() {
        let accessor = FakeMapAccessor::default();
        accessor.set_value(7, key(1), value(11));

        let mut tracker = MapInvalidationTracker::new(accessor.clone());
        tracker.record_inline_site(101, 7, key(1), value(11));
        let tracker = tracker;

        let invalidated = tracker
            .check_for_invalidations()
            .expect("check_for_invalidations should not error");

        assert!(invalidated.is_empty());
        assert_eq!(accessor.batch_call_count(), 1);
        assert_eq!(accessor.batch_calls(), vec![(7, 1)]);
    }

    #[test]
    fn test_check_changed_returns_affected_progs() {
        let accessor = FakeMapAccessor::default();
        accessor.set_value(7, key(1), value(99));

        let mut tracker = MapInvalidationTracker::new(accessor.clone());
        tracker.record_inline_site(101, 7, key(1), value(11));
        tracker.record_inline_site(202, 7, key(1), value(11));

        let invalidated = tracker
            .check_for_invalidations()
            .expect("check_for_invalidations should not error");

        assert_eq!(invalidated_set(invalidated), HashSet::from([101, 202]));
        assert_eq!(accessor.batch_call_count(), 1);
        assert_eq!(accessor.batch_calls(), vec![(7, 1)]);
    }

    #[test]
    fn test_check_multiple_maps_independent() {
        let accessor = FakeMapAccessor::default();
        accessor.set_value(7, key(1), value(99));
        accessor.set_value(8, key(1), value(22));

        let mut tracker = MapInvalidationTracker::new(accessor.clone());
        tracker.record_inline_site(101, 7, key(1), value(11));
        tracker.record_inline_site(202, 8, key(1), value(22));

        let invalidated = tracker
            .check_for_invalidations()
            .expect("check_for_invalidations should not error");

        assert_eq!(invalidated_set(invalidated), HashSet::from([101]));
        assert_eq!(accessor.batch_call_count(), 2);
        assert_eq!(accessor.batch_calls(), vec![(7, 1), (8, 1)]);
    }

    #[test]
    fn test_remove_prog_clears_entries() {
        let mut tracker = MapInvalidationTracker::new(FakeMapAccessor::default());
        tracker.record_inline_site(101, 7, key(1), value(11));
        tracker.record_inline_site(101, 7, key(2), value(12));
        tracker.record_inline_site(202, 8, key(1), value(21));

        tracker.remove_prog(101);

        assert_eq!(tracker.entry_count(), 1);
        assert_eq!(tracker.entries[0].prog_id, 202);
    }

    #[test]
    fn test_duplicate_key_updates_value() {
        let mut tracker = MapInvalidationTracker::new(FakeMapAccessor::default());
        tracker.record_inline_site(101, 7, key(1), value(11));
        tracker.record_inline_site(101, 7, key(1), value(99));

        assert_eq!(tracker.entry_count(), 1);
        assert_eq!(
            tracker.entries[0],
            TrackedInlineSite {
                prog_id: 101,
                map_fd: 7,
                key: key(1),
                expected_value: value(99),
            }
        );
    }

    #[test]
    fn test_batch_check_efficiency() {
        let accessor = FakeMapAccessor::default();
        let mut tracker = MapInvalidationTracker::new(accessor.clone());

        for i in 0..100u32 {
            accessor.set_value(7, key(i), value(i));
            tracker.record_inline_site(1000 + i, 7, key(i), value(i));
        }

        let invalidated = tracker
            .check_for_invalidations()
            .expect("check_for_invalidations should not error");

        assert!(invalidated.is_empty());
        assert_eq!(tracker.entry_count(), 100);
        assert_eq!(accessor.batch_call_count(), 1);
        assert_eq!(accessor.batch_calls(), vec![(7, 100)]);
    }
}
