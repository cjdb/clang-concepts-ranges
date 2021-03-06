// Copyright (c) Christopher Di Bella.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
#include "cjdb/concepts/core/common_reference_with.hpp"

static_assert(cjdb::common_reference_with<int, float>);
static_assert(cjdb::common_reference_with<void, void>);

int main() {}
