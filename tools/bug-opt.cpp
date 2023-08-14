#include "include/IR/SecretDialect.h"
#include "include/Transforms/Passes.h"
#include "mlir/include/mlir/Dialect/Affine/IR/AffineOps.h"  // from @llvm-project
#include "mlir/include/mlir/Dialect/Arith/IR/Arith.h"  // from @llvm-project
#include "mlir/include/mlir/Dialect/Func/IR/FuncOps.h"   // from @llvm-project
#include "mlir/include/mlir/Dialect/MemRef/IR/MemRef.h"  // from @llvm-project
#include "mlir/include/mlir/Dialect/SCF/IR/SCF.h"  // from @llvm-project
#include "mlir/include/mlir/InitAllDialects.h"             // from @llvm-project
#include "mlir/include/mlir/InitAllPasses.h"               // from @llvm-project
#include "mlir/include/mlir/Pass/PassManager.h"            // from @llvm-project
#include "mlir/include/mlir/Pass/PassRegistry.h"           // from @llvm-project
#include "mlir/include/mlir/Tools/mlir-opt/MlirOptMain.h"  // from @llvm-project

int main(int argc, char **argv) {
  mlir::DialectRegistry registry;
  registry.insert<mlir::heir::secret::SecretDialect>();

  // Add expected MLIR dialects to the registry.
  registry.insert<mlir::affine::AffineDialect>();
  registry.insert<mlir::arith::ArithDialect>();
  registry.insert<mlir::func::FuncDialect>();
  registry.insert<mlir::memref::MemRefDialect>();
  registry.insert<mlir::scf::SCFDialect>();
  mlir::registerAllDialects(registry);

  // Register MLIR core passes to build pipeline.
  mlir::registerAllPasses();
  mlir::heir::secret::registerSecretPasses();

  return mlir::asMainReturnCode(
      mlir::MlirOptMain(argc, argv, "HEIR Pass Driver", registry));
}
