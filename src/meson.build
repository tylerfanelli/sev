cargo_build = find_program('cargo-build.sh')

v = meson.project_version().split('.')

staticlib_name = 'libsev.a'

staticlib_target = custom_target(staticlib_name,
  build_by_default : true,
  build_always_stale : true,
  command : [cargo_build, get_option('debug').to_string(),
             get_option('optimization'), meson.current_build_dir() / 'target',
             '@OUTPUT@'],
  console : true,
  output : [staticlib_name])

lib = library('sev',
  sources: files('TEST.c'),
  link_with: staticlib_target,
  install: true,
  soversion: meson.project_version())

# generate pkg-config file

import('pkgconfig').generate(libraries : ['-lsev'],
  name : 'sev',
  description : 'AMD SEV library')
