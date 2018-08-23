CXX = g++

CPPFLAGS = -std=c++11 -g -Wall
VGFLAGS = --tool=memcheck --leak-check=yes

all: twitter

twitter: twitter.cpp twiteng.o util.o user.o tweet.o cmdhandler.o handler.o datetime.o
	$(CXX) $(CPPFLAGS) $^ -o $@

twiteng.o: twiteng.cpp twiteng.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

util.o: util.cpp util.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

tweet.o: tweet.cpp tweet.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

cmdhandler.o: cmdhandler.cpp cmdhandler.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

handler.o: handler.cpp handler.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

datetime.o: datetime.cpp datetime.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

user.o: user.cpp user.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

.PHONY: clean test vtest

clean:
	rm -f twitter
	rm -f *.o
	rm -f *.feed

test: twitter
	./twitter twitterLarge.dat

vtest: twitter
	valgrind $(VGFLAGS) ./twitter twitterLarge.dat