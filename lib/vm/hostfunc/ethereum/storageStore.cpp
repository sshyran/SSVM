// SPDX-License-Identifier: Apache-2.0
#include "vm/hostfunc/ethereum/storageStore.h"
#include "support/hexstr.h"

namespace SSVM {
namespace Executor {

ErrCode EEIStorageStore::body(VM::EnvironmentManager &EnvMgr,
                              Instance::MemoryInstance &MemInst,
                              uint32_t PathOffset, uint32_t ValueOffset) {
  /// Get Path data by path offset.
  std::vector<unsigned char> Data;
  std::string Path;
  std::string Value;
  if (ErrCode Status = MemInst.getBytes(Data, PathOffset, 32);
      Status != ErrCode::Success) {
    return Status;
  }
  Support::convertBytesToHexStr(Data, Path, 64);

  /// Get Value data by value offset.
  Data.clear();
  if (ErrCode Status = MemInst.getBytes(Data, ValueOffset, 32);
      Status != ErrCode::Success) {
    return Status;
  }
  Support::convertBytesToHexStr(Data, Value, 64);

  /// Set Value data to storage.
  // Env.getStorage()[Path] = Value;

  return ErrCode::Success;
}

} // namespace Executor
} // namespace SSVM