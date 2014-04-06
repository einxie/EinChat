bin = EinServer
obj = EinServer.o ServerSock.o
$(bin) : $(obj)
	g++ -o $(bin) $(obj)
$(obj) : ServerSock.h

.PHONY : clean
clean :
	rm -rf $(obj)
