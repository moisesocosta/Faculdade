package main

import (
	"fmt"
	"net"
	"os"
	"time"
)

func checkError(err error)  {
	if err != nil {
		fmt.Fprintf(os.Stderr, "Erro: %s.\n", err.Error())
		os.Exit(1)
	}
}

func main() {
	tcpAddr, err := net.ResolveTCPAddr("tcp", ":1200")
	checkError(err)

	listener, err := net.ListenTCP("tcp", tcpAddr)
	checkError(err)

	for {
		conn, err := listener.Accept()

		if err != nil {
			continue
		}

		daytime := time.Now().String()
		conn.Write([]byte(daytime))
		conn.Close()
	}
}
