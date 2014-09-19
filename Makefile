all: pvrtctest gen_bitscales


pvrtctest: main.cpp PvrTcPacket.cpp MortonTable.cpp PvrTcEncoder.cpp PvrTcDecoder.cpp BitScale.cpp PvrTcPacket.h MortonTable.h PvrTcEncoder.h PvrTcDecoder.h BitScale.h
	g++ -std=c++11 -o pvrtctest main.cpp PvrTcPacket.cpp MortonTable.cpp PvrTcEncoder.cpp PvrTcDecoder.cpp BitScale.cpp

gen_bitscales: gen_bitscales.cpp	
	g++ -std=c++11 -o gen_bitscales gen_bitscales.cpp
