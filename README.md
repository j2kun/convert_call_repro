# Issue with dialect conversion framework

Passing test

```
bazel test -c dbg //tests:convert_call_passing.mlir.test
```

Failing test

```
bazel test -c dbg //tests:convert_call_failing.mlir.test
```

Or to run it manually:

```
bazel build -c dbg tools:bug-opt
bazel-bin/tools/bug-opt --secret-forget-secrets tests/convert_call_failing.mlir
```
