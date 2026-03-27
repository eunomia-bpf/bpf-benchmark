#[derive(Clone, Debug, Default)]
pub struct PgoAnalysis {
    pub delta_run_cnt: u64,
    pub delta_run_time_ns: u64,
    pub delta_avg_ns: Option<f64>,
    pub branch_miss_rate: Option<f64>,
}

impl PgoAnalysis {
    pub fn is_hot(&self) -> bool {
        false
    }
}
