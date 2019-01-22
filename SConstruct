#target='ymodem'
#src=Glob('src/*.c')
#src+='./port/ymodem_port_linux.c'
#CCFLAGS = ['-g']
#CPPPATH = ['src/','port/']
#Program(target,src,CCFLAGS=CCFLAGS,CPPPATH = CPPPATH)

Program('ymodem',['src/ymodem.c','port/ymodem_port_linux.c'],CPPPATH = ['src','port'])