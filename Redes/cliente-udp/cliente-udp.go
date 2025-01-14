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

func main() {

	if len(os.Args) != 2 {
		fmt.Fprintf(os.Stderr, "Uso: %s host:porta.\n", os.Args[0])
		os.Exit(1)
	}

	service := os.Args[1]
	udpAddr, err := net.ResolveUDPAddr("udp", service)
	checkError(err)

	conn, err := net.DialUDP("udp", nil, udpAddr)
	checkError(err)

	_, err = conn.Write([]byte("qualquer coisa"))
	checkError(err)

	var buf [512]byte

	n, err := conn.Read(buf[0:])
	checkError(err)

	fmt.Println(string(buf[0:n]))
	os.Exit(0)
}
