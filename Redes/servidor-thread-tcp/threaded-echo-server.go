package main

import (
	"fmt"
	"net"
	"os"
)

func checkError(err error)  {
	if err != nil {
		fmt.Fprintf(os.Stderr, "Erro: %s.\n", err.Error())
		os.Exit(1)
	}
}

func handleClient(conn net.Conn)  {
	defer conn.Close()

	var buf [512]byte

	for {
		num, err := conn.Read(buf[0:])

		if err != nil {
			return
		}

		fmt.Println(string(buf[0:]))

		num, err = conn.Write(buf[0:num])

		if err != nil {
			return
		}
	}
}

func main() {
	service := ":1201"
	tcpAddr, err := net.ResolveTCPAddr("tcp", service)
	checkError(err)

	listener, err := net.ListenTCP("tcp", tcpAddr)
	checkError(err)

	for {
		conn, err := listener.Accept()

		if err != nil {
			continue
		}

		go handleClient(conn)
	}
}