// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once

#include "bigint.h"
#include "ds/json.h"
namespace eevm
{
  enum VarType {
    kMapping = 1,
    kArray = 2,
    kStatic = 3
  };
  DECLARE_JSON_ENUM(VarType,
   {{VarType::kMapping, "kMapping"},
   {VarType::kArray, "kArray"},
   {VarType::kStatic, "kStatic"}})

  struct HashState {
    uint256_t mem_low_32;
    uint256_t mem_high_32;
    uint256_t stack_0;
    uint256_t stack_1;
    uint256_t stack_2;
    uint256_t stack_3;
    uint256_t addr;
    VarType var_type;
  };
  struct VarInfo{
    VarType var_type;
    uint256_t addr;
    uint256_t key;
    uint256_t value;
    uint256_t slot;
  };
  DECLARE_JSON_TYPE(VarInfo)
  DECLARE_JSON_REQUIRED_FIELDS(VarInfo, var_type, addr, key, value)


  // recorder of state before executing command sha3()
  inline std::map<uint256_t, HashState> hash_states{};

  /**
   * Abstract interface for accessing EVM's permanent, per-address key-value
   * storage
   */
  struct Storage
  {
    virtual void store(const uint256_t& key, const uint256_t& value,
     const std::string& mpt_id) = 0;
    virtual uint256_t load(const uint256_t& key, const std::string& mpt_id) = 0;
    virtual bool remove(const uint256_t& key) = 0;
    virtual ~Storage() {}
  };
} // namespace eevm
