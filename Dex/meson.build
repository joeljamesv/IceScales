dex_lib = static_library(
    'dex',
    'logger.cpp',
    install : true
)

dex_dep = declare_dependency(
    include_directories : include_directories('.'),
    link_with : dex_lib
)
