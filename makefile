cc = g++
obj = memory.o
obj2 = driver.o
bin = memory

$(bin):	$(obj) $(obj2)
	$(cc) $(obj) $(obj2) -o $(bin)

.cpp.o:
	$(cc) -c $<

clean:
	rm *.o $(bin)

