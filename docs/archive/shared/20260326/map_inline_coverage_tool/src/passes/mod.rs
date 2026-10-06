#[path = "../../../../../../daemon/src/passes/utils.rs"]
pub mod utils;
#[path = "../../../../../../daemon/src/passes/map_inline.rs"]
pub mod map_inline;
#[path = "../../../../../../daemon/src/passes/const_prop.rs"]
pub mod const_prop;
#[path = "../../../../../../daemon/src/passes/dce.rs"]
pub mod dce;

pub use const_prop::ConstPropPass;
pub use dce::DcePass;
pub use map_inline::{find_map_lookup_sites, MapInlinePass};
