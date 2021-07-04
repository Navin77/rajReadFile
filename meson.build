project(
  'rajReadFile',
  'c',
  version : '1.0.0',
  default_options : ['warning_level=3']
)
project_description = 'it ease the management of dynamic arrays for c types'

project_headers = [
  'rajReadFile.h'
]

project_source_files = [
  'rajReadFile.c'
]

public_headers = include_directories('.')

project_target = shared_library(
  meson.project_name(),
  project_source_files,
  install : true,
  gnu_symbol_visibility : 'hidden',
  include_directories : public_headers,
)

# =======
# Project
# =======

# Make this library usable from the system's package manager.
install_headers(project_headers)

pkg_mod = import('pkgconfig')
pkg_mod.generate(
  name : meson.project_name(),
  filebase : meson.project_name(),
  description : project_description,
  libraries : project_target,
)

# Make this library usable as a Meson subproject.
project_dep = declare_dependency(
  include_directories: public_headers,
  link_with : project_target
)
set_variable(meson.project_name() + '_dep', project_dep)
