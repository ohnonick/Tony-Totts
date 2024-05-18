investigate: driver.o tonyTotts.o
	g++ -o investigate driver.o tonyTotts.o -g
driver.o: driver.cpp tonyTotts.h arrayDictionary.h linkedlist.h entry.h node.h dictionary.h list.h
	g++ -c driver.cpp -g
tonyTotts.o: tonyTotts.cpp arrayDictionary.h linkedlist.h entry.h node.h dictionary.h list.h
	g++ -c tonyTotts.cpp -g
clean:
	rm *.o investigate