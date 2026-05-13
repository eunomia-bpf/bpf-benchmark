#pragma once

#include_next "lib/static_data.h"

#undef CONFIG
#define CONFIG(name) (__config_##name)
