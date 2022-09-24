workspace(name = "istio_ecosystem_wasm_extensions")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

# Need to push Wasm OCI images
#http_archive(
#    name = "io_bazel_rules_docker",
#    sha256 = "92779d3445e7bdc79b961030b996cb0c91820ade7ffa7edca69273f404b085d5",
#    strip_prefix = "rules_docker-0.20.0",
#    urls = ["https://github.com/bazelbuild/rules_docker/releases/download/v0.20.0/rules_docker-v0.20.0.tar.gz"],
#)

#load(
#    "@io_bazel_rules_docker//repositories:repositories.bzl",
#    container_repositories = "repositories",
#)

#container_repositories()

#load("@io_bazel_rules_docker//repositories:deps.bzl", container_deps = "deps")

#container_deps()

# TODO fix update-deps.sh (points to playground proxy)
### Proxy SDK. 2022-03-15, as in envoy v1.23.1
#PROXY_WASM_CPP_SDK_SHA = "e30535b7c0cd3126e6401bc3769063a74bbb37be"

#PROXY_WASM_CPP_SDK_SHA256 = "94e474ebea782225821224734ed5992fa749301e12e06b6520b8b4d4e1c05ffc"

#http_archive(
#    name = "proxy_wasm_cpp_sdk",
#    sha256 = PROXY_WASM_CPP_SDK_SHA256,
#    strip_prefix = "proxy-wasm-cpp-sdk-" + PROXY_WASM_CPP_SDK_SHA,
#    url = "https://github.com/proxy-wasm/proxy-wasm-cpp-sdk/archive/" + PROXY_WASM_CPP_SDK_SHA + ".tar.gz",
#)

#load("@proxy_wasm_cpp_sdk//bazel/dep:deps.bzl", "wasm_dependencies")

#wasm_dependencies()

#load("@proxy_wasm_cpp_sdk//bazel/dep:deps_extra.bzl", "wasm_dependencies_extra")

#wasm_dependencies_extra()

### optional imports ###
# To import commonly used libraries from istio proxy, such as base64, json, and flatbuffer.
# Istio proxy. 2022-08-26, v1.15.0
#IO_ISTIO_PROXY_SHA = "c5837eae93559dfa0279db04b3d565b9ec01c833"

#IO_ISTIO_PROXY_SHA256 = "a3211281031694a59e9a12fcb54f95dbfebb71a0f18ef528f50249d73c160461"

#http_archive(
#    name = "io_istio_proxy",
#    sha256 = IO_ISTIO_PROXY_SHA256,
#    strip_prefix = "proxy-" + IO_ISTIO_PROXY_SHA,
#    url = "https://github.com/istio/proxy/archive/" + IO_ISTIO_PROXY_SHA + ".tar.gz",
#)

#load("@istio_ecosystem_wasm_extensions//bazel:wasm.bzl", "wasm_libraries")

#wasm_libraries()

# To import proxy wasm cpp host, which will be used in unit testing.
#load("@proxy_wasm_cpp_host//bazel:repositories.bzl", "proxy_wasm_cpp_host_repositories")

#proxy_wasm_cpp_host_repositories()

#load("@proxy_wasm_cpp_host//bazel:dependencies.bzl", "proxy_wasm_cpp_host_dependencies")

#proxy_wasm_cpp_host_dependencies()

### Envoy v1.23.1, as in Istio proxy 1.15.0.
# 1. Determine SHA256 `wget https://github.com/envoyproxy/envoy/archive/$COMMIT.tar.gz && sha256sum $COMMIT.tar.gz`
# 2. Update .bazelversion, envoy.bazelrc and .bazelrc if needed.
#
# Note: this is needed by release builder to resolve envoy dep sha to tag.
# Commit date: 2022-08-25
ENVOY_SHA = "edd69583372955fdfa0b8ca3820dd7312c094e46"

ENVOY_SHA256 = "40b557d0cb88188b58de74444e909f8c4f4bd52e0a11bcee0fcedea6bd399008"

ENVOY_ORG = "envoyproxy"

ENVOY_REPO = "envoy"

# To override with local envoy, just pass `--override_repository=envoy=/PATH/TO/ENVOY` to Bazel or
# persist the option in `user.bazelrc`.
http_archive(
    name = "envoy",
    sha256 = ENVOY_SHA256,
    strip_prefix = ENVOY_REPO + "-" + ENVOY_SHA,
    url = "https://github.com/" + ENVOY_ORG + "/" + ENVOY_REPO + "/archive/" + ENVOY_SHA + ".tar.gz",
)

load("@envoy//bazel:api_binding.bzl", "envoy_api_binding")

# TODO maybe add back w/ extension_config
#local_repository(
#    name = "envoy_build_config",
    # Relative paths are also supported.
#    path = "bazel/extension_config",
#)

envoy_api_binding()

load("@envoy//bazel:api_repositories.bzl", "envoy_api_dependencies")

envoy_api_dependencies()

load("@envoy//bazel:repositories.bzl", "envoy_dependencies")

envoy_dependencies()

load("@envoy//bazel:repositories_extra.bzl", "envoy_dependencies_extra")

envoy_dependencies_extra()

load("@envoy//bazel:python_dependencies.bzl", "envoy_python_dependencies")

envoy_python_dependencies()

#load("@base_pip3//:requirements.bzl", "install_deps")

#install_deps()

load("@envoy//bazel:dependency_imports.bzl", "envoy_dependency_imports")

envoy_dependency_imports()
