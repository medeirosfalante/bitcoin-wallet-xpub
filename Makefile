build:
	 g++ main.cpp src/bitcoin-wallet-xpub/cli.cpp  -o app  -lncurses -ltinfo
run:
	./app