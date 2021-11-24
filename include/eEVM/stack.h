// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once
#include "bigint.h"

#include <deque>
#define FMT_HEADER_ONLY
#include <fmt/format.h>
#include <fmt/ostream.h>
#include <ostream>

namespace eevm
{
  /**
   * Stack used by Processor
   */
  class Stack
  {
  private:
    std::deque<uint256_t> st;

  public:
    static constexpr std::size_t MAX_SIZE = 1024;
    Stack() = default;
    uint256_t pop();
    uint64_t pop64();
    void push(const uint256_t& val);
    uint64_t size() const;
    void swap(uint64_t i);
    void dup(uint64_t a);
    uint256_t at(uint64_t i);

    friend std::ostream& operator<<(std::ostream& os, const Stack& s);
  };
} // namespace eevm
