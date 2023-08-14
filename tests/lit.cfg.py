import os
from pathlib import Path

from lit.formats import ShTest

config.name = "bug"
config.test_format = ShTest()
config.suffixes = [".mlir"]

# lit executes relative to the directory
#
#   bazel-bin/tests/<test_target_name>.runfiles/bug/
#
# which contains tools/ and tests/ directories and the binary targets built
# within them, brought in via the `data` attribute in the BUILD file. To
# manually inspect the filesystem in situ, add the following to this script and
# run `bazel test //tests:<target>`
#
#   import subprocess
#
#   print(subprocess.run(["pwd",]).stdout)
#   print(subprocess.run(["ls", "-l", os.environ["RUNFILES_DIR"]]).stdout)
#   print(subprocess.run([ "env", ]).stdout)
#
# Hence, to get lit to see tools like `bug-opt`, we need to add the tools/
# subdirectory to the PATH environment variable.
#
# Bazel defines RUNFILES_DIR which includes bug/ and third party dependencies
# as tbug own directory. Generally, it seems that $PWD == $RUNFILES_DIR/bug/

runfiles_dir = Path(os.environ["RUNFILES_DIR"])

mlir_tools_relpath = "llvm-project/mlir"
mlir_tools_path = runfiles_dir.joinpath(Path(mlir_tools_relpath))
tool_relpaths = [
    mlir_tools_relpath,
    "bug/tools",
    "llvm-project/llvm",
]

config.environment["PATH"] = (
    ":".join(str(runfiles_dir.joinpath(Path(path))) for path in tool_relpaths)
    + ":"
    + os.environ["PATH"]
)
