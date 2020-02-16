Import('env')

env.Append(CPPPATH=['./h'])

env.VariantDir('build', 'c', duplicate=0)
libmap_sources = Glob('build/*.c')
env.SharedLibrary(target = "build/libmap", source = libmap_sources, PDB = "build/libmap.pdb")
