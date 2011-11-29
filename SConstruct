env = Environment()

env.AppendUnique(CFLAGS=['-O2', '-Wall', '-g'])

src_cc = ['interpreter', 'lexer', 'mathtree', 'parser', 'token']

sources_cc =  map(lambda x: 'src/' + x + '.cc', src_cc)

env.Program(target="theam",
            source=sources_cc + ['src/theam.cc'])
